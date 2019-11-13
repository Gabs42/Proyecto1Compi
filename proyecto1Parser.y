%{

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include "tree.c"

extern FILE* yyin;
extern int yylineno;
extern int yyparse();
void yyerror (char *s);
int yylex();

%}

%locations

%union {
  char* str;
	struct TreeNode * treeNode;
  int intval;
}

%start Program

%token VOID INTEGER DOUBLE BOOL STRING
%token CLASS INTERFACE NULLN THIS EXTENDS IMPLEMENTS
%token FOR WHILE IF ELSE RETURN BREAK NEW NEWARRAY
%token PRINT READINTEGER READLINE TRUE FALSE
%token COMMA POINT LFTBRCKT RGHBRCKT LFTPARTH RGHPARTH SEMICLN
%token LFTGATE RGHGATE STRINGERROR INVCHAR INVESCP
%token LINEJMP TAB SPACE INTVAL DOUBLEVAL STRINGVAL NULLVAL
%token OR LESSEQL
%token<str> ID

%left SUM SUB MULT DIV LESSTHN LESSEQL GREATERTHN MOD GREATEREQL
%left EQUAL SAME DIFF AND OR NOT

%type<str> SUM SUB MULT DIV LESSTHN LESSEQL GREATERTHN MOD

%type<treeNode> Program Declarations Declaration VariableDecl Variable Type
%type<treeNode> FunctionDecl Formals Variables ClassDecl Extend Implement
%type<treeNode> ListIdents Fields Field InterfaceDecl Prototypes Prototype
%type<treeNode> StmtBlock Stmts Stmt PossibleExpr IfStmt
%type<treeNode> PossibleElse WhileStmt ForStmt ReturnStmt BreakStmt PrintStmt
%type<treeNode> ListExpr Expr LValue Call Actuals Constant

%%

Program:        Declarations { $$ = createTreeNode(yylineno, "Program", 1, $1); printTree($$); freeTree($$); }
;

Declarations:   Declaration               { $$ = createTreeNode(yylineno, "Declarations", 1, $1); }
              | Declarations Declaration  { $$ = createTreeNode(yylineno, "Declarations", 2, $1, $2); }
;

Declaration:    VariableDecl  { $$ = createTreeNode(yylineno, "Declaration", 1, $1); }
              | FunctionDecl  { $$ = createTreeNode(yylineno, "Declaration", 1, $1); }
              | ClassDecl     { $$ = createTreeNode(yylineno, "Declaration", 1, $1); }
              | InterfaceDecl { $$ = createTreeNode(yylineno, "Declaration", 1, $1); }
;

VariableDecl:   Variable SEMICLN { $$ = createTreeNode(yylineno, "VariableDecl", 2, $1, tN(";")); }
;

Variable:       Type ID { $$ = createTreeNode(yylineno, "Variable", 2, $1, tT(yylval.str, "ID")); }
;

Type:           INTEGER                 { $$ = createTreeNode(yylineno, "Type", 1, tN("integer")); }
		          | DOUBLE                  { $$ = createTreeNode(yylineno, "Type", 1, tN("double")); }
              | BOOL                    { $$ = createTreeNode(yylineno, "Type", 1, tN("boolean")); }
              | STRING                  { $$ = createTreeNode(yylineno, "Type", 1, tN("string")); }
              | ID                      { $$ = createTreeNode(yylineno, "Type", 1, tN(yylval.str)); }
              | Type LFTBRCKT RGHBRCKT  { $$ = createTreeNode(yylineno, "Type", 3, $1, tN("["), tN("]")); }
;

FunctionDecl:   Type ID LFTPARTH Formals RGHPARTH StmtBlock { $$ = createTreeNode(yylineno, "FunctionDecl", 6, $1, tT(yylval.str, "ID"), tN("("), $4, tN(")"), $6); }
              | VOID ID LFTPARTH Formals RGHPARTH StmtBlock { $$ = createTreeNode(yylineno, "FunctionDecl", 6, tN("void"), tT(yylval.str, "ID"), tN("("), $4, tN(")"), $6); }
;

Formals:        Variables   { $$ = createTreeNode(yylineno, "Formals", 1, $1); }
              | /* empty */ { $$ = eN(); }
;

Variables:      Variable                  { $$ = createTreeNode(yylineno, "Variables", 1, $1); }
              | Variables COMMA Variable  { $$ = createTreeNode(yylineno, "Variables", 3, $1, tN(","), $3); }
;

ClassDecl:      CLASS ID Extend Implement LFTGATE Fields RGHGATE { $$ = createTreeNode(yylineno, "ClassDecl", 7, tN("class"), tT(yylval.str, "ID"), $3, $4, tN("{"), $6, tN("}")); }
;

Extend:         EXTENDS ID  { $$ = createTreeNode(yylineno, "Extend", 2, tN("extends"), tT(yylval.str, "ID")); }
              | /* empty */ { $$ = eN(); }
;

Implement:      IMPLEMENTS ListIdents { $$ = createTreeNode(yylineno, "Implement", 2, tN("implements"), $2); }
              | /* empty */           { $$ = eN(); }
;

ListIdents:     ID                  { $$ = createTreeNode(yylineno, "ListIdents", 1, tT(yylval.str, "ID")); }
              | ListIdents COMMA ID { $$ = createTreeNode(yylineno, "ListIdents", 3, $1, tN(","), tT(yylval.str, "ID")); }
;

Fields:         Fields Field  { $$ = createTreeNode(yylineno, "Fields", 2, $1, $2); }
              | /* empty */   { $$ = eN(); }
;

Field:          VariableDecl  { $$ = createTreeNode(yylineno, "Field", 1, $1); }
              | FunctionDecl  { $$ = createTreeNode(yylineno, "Field", 1, $1); }
;

InterfaceDecl:  INTERFACE ID LFTGATE Prototypes RGHGATE { $$ = createTreeNode(yylineno, "InterfaceDecl", 5, tN("interface"), tT(yylval.str, "ID"), tN("{"), $4, tN("}")); }
;

Prototypes:     Prototypes Prototype  { $$ = createTreeNode(yylineno, "Prototypes", 2, $1, $2); }
              | /* empty */           { $$ = eN(); }
;

Prototype:      Type ID LFTPARTH Formals RGHPARTH SEMICLN { $$ = createTreeNode(yylineno, "Prototype", 6, $1, tT(yylval.str, "ID"), tN("("), $4, tN(")"), tN(";")); }
              | VOID ID LFTPARTH Formals RGHPARTH SEMICLN { $$ = createTreeNode(yylineno, "Prototype", 6, tN("void"), tT(yylval.str, "ID"), tN("("), $4, tN(")"), tN(";")); }
;

StmtBlock:      LFTGATE Stmts RGHGATE { $$ = createTreeNode(yylineno, "StmtBlock", 3, tN("{"), $2, tN("}")); } //No olvidar
;

Stmts:          Stmts Stmt  { $$ = createTreeNode(yylineno, "Stmts", 2, $1, $2); }
              | /* empty */ { $$ = eN(); }
;

Stmt:           IfStmt        { $$ = createTreeNode(yylineno, "Stmt", 1, $1); }
              | WhileStmt     { $$ = createTreeNode(yylineno, "Stmt", 1, $1); }
              | ForStmt       { $$ = createTreeNode(yylineno, "Stmt", 1, $1); }
              | BreakStmt     { $$ = createTreeNode(yylineno, "Stmt", 1, $1); }
              | ReturnStmt    { $$ = createTreeNode(yylineno, "Stmt", 1, $1); }
              | PrintStmt     { $$ = createTreeNode(yylineno, "Stmt", 1, $1); }
              | StmtBlock     { $$ = createTreeNode(yylineno, "Stmt", 1, $1); }
              | Expr          { $$ = createTreeNode(yylineno, "Stmt", 1, $1); } //No olvidar
              | VariableDecl  { $$ = createTreeNode(yylineno, "Stmt", 1, $1); } //No olvidar
;

PossibleExpr:   Expr        { $$ = createTreeNode(yylineno, "Expr", 1, $1); }
              | /* empty */ { $$ = eN(); }
;

IfStmt:         IF LFTPARTH Expr RGHPARTH Stmt PossibleElse { $$ = createTreeNode(yylineno, "IfStmt", 6, tN("if"), tN("("), $3, tN(")"), $5, $6); }
;

PossibleElse:   ELSE Stmt   { $$ = createTreeNode(yylineno, "Else", 2, tN("else"), $2); }
              //| /* empty */ { $$ = eN(); } // No olvidar
;

WhileStmt:      WHILE LFTPARTH Expr RGHPARTH Stmt { $$ = createTreeNode(yylineno, "WhileStmt", 5, tN("while"), tN("("), $3, tN(")"), $5); }
;

ForStmt:        FOR LFTPARTH PossibleExpr SEMICLN PossibleExpr SEMICLN PossibleExpr RGHPARTH Stmt { $$ = createTreeNode(yylineno, "ForStmt", 9, tN("for"), tN("("), $3, tN(";"), $5, tN(";"), $7, tN(")"), $9); }
;

ReturnStmt:     RETURN PossibleExpr SEMICLN { $$ = createTreeNode(yylineno, "ReturnStmt", 3, tN("return"), $2, tN(";")); }
;

BreakStmt:      BREAK SEMICLN { $$ = createTreeNode(yylineno, "BreakStmt", 2, tN("break"), tN(";")); }
;

PrintStmt:      PRINT LFTPARTH ListExpr RGHPARTH SEMICLN { $$ = createTreeNode(yylineno, "PrintStmt", 5, tN("print"), tN("("), $3, tN(")"), tN(";")); }
;

ListExpr:       Expr                { $$ = createTreeNode(yylineno, "ListExpr", 1, $1); }
              | ListExpr COMMA Expr { $$ = createTreeNode(yylineno, "ListExpr", 3, $1, tN(","), $3); }
;

Expr:           LValue EQUAL Expr                           { $$ = createTreeNode(yylineno, "Expr", 3, $1, tN("="), $3); }
              | Constant                                    { $$ = createTreeNode(yylineno, "Expr", 1, $1); }
              | LValue                                      { $$ = createTreeNode(yylineno, "Expr", 1, $1); }
              | THIS                                        { $$ = createTreeNode(yylineno, "Expr", 1, tN("this")); }
              | Call                                        { $$ = createTreeNode(yylineno, "Expr", 1, $1); }
              | LFTPARTH Expr RGHPARTH                      { $$ = createTreeNode(yylineno, "Expr", 3, tN("("), $2, tN(")")); }
              | Expr SUM Expr                               { $$ = createTreeNode(yylineno, "Expr", 3, $1, tN("+"), $3); }
              | Expr SUB Expr                               { $$ = createTreeNode(yylineno, "Expr", 3, $1, tN("-"), $3); }
              | Expr MULT Expr                              { $$ = createTreeNode(yylineno, "Expr", 3, $1, tN("*"), $3); }
              | Expr DIV Expr                               { $$ = createTreeNode(yylineno, "Expr", 3, $1, tN("/"), $3); }
              | Expr  MOD Expr                              { $$ = createTreeNode(yylineno, "Expr", 3, $1, tN("mod"), $3); }
              | SUB Expr                                    { $$ = createTreeNode(yylineno, "Expr", 2, tN("-"), $2); }
              | Expr LESSTHN Expr                           { $$ = createTreeNode(yylineno, "Expr", 3, $1, tN("<"), $3); }
              | Expr LESSEQL Expr                           { $$ = createTreeNode(yylineno, "Expr", 3, $1, tN("<="), $3); }
              | Expr GREATERTHN Expr                        { $$ = createTreeNode(yylineno, "Expr", 3, $1, tN(">"), $3); }
              | Expr GREATEREQL Expr                        { $$ = createTreeNode(yylineno, "Expr", 3, $1, tN(">="), $3); }
              | Expr SAME Expr                              { $$ = createTreeNode(yylineno, "Expr", 3, $1, tN("=="), $3); }
              | Expr DIFF Expr                              { $$ = createTreeNode(yylineno, "Expr", 3, $1, tN("!="), $3); }
              | Expr AND Expr                               { $$ = createTreeNode(yylineno, "Expr", 3, $1, tN("&&"), $3); }
              | Expr OR Expr                                { $$ = createTreeNode(yylineno, "Expr", 3, $1, tN("||"), $3); }
              | NOT Expr                                    { $$ = createTreeNode(yylineno, "Expr", 2, tN("!"), $2); }
              | READINTEGER LFTPARTH RGHPARTH               { $$ = createTreeNode(yylineno, "Expr", 3, tN("readInteger"), tN("("), tN(")")); }
              | READLINE LFTPARTH RGHPARTH                  { $$ = createTreeNode(yylineno, "Expr", 3, tN("readLine"), tN("("), tN(")")); }
              | NEW LFTPARTH ID RGHPARTH                    { $$ = createTreeNode(yylineno, "Expr", 4, tN("new"), tN("("), tT(yylval.str, "ID"), tN(")")); }
              | NEWARRAY LFTPARTH Expr COMMA Type RGHPARTH  { $$ = createTreeNode(yylineno, "Expr", 6, tN("newArray"), tN("("), $3, tN(","), $5, tN(")")); }
;

LValue:         ID                          { $$ = createTreeNode(yylineno, "LValue", 1, tT(yylval.str, "ID")); }
              | Expr POINT ID               { $$ = createTreeNode(yylineno, "LValue", 3, $1, tN("."), tT(yylval.str, "ID")); }
              | Expr LFTBRCKT Expr RGHBRCKT { $$ = createTreeNode(yylineno, "LValue", 4, $1, tN("["), $3, tN("]")); }
;

Call:           ID LFTPARTH Actuals RGHPARTH            { $$ = createTreeNode(yylineno, "Call", 4, tT(yylval.str, "ID"), tN("("), $3, tN(")")); }
              | Expr POINT ID LFTPARTH Actuals RGHPARTH { $$ = createTreeNode(yylineno, "Call", 6, $1, tN("."), tT(yylval.str, "ID"), tN("("), $5, tN(")")); }
;

Actuals:        ListExpr    { $$ = createTreeNode(yylineno, "Actuals", 1, $1); }
              | /* empty */ { $$ = eN(); }
;

Constant:       INTVAL    { $$ = createTreeNode(yylineno, "Constant", 1, tT(yylval.str, "integer")); }
              | DOUBLEVAL { $$ = createTreeNode(yylineno, "Constant", 1, tT(yylval.str, "double")); }
              | TRUE      { $$ = createTreeNode(yylineno, "Constant", 1, tT("true", "boolean")); }
              | FALSE     { $$ = createTreeNode(yylineno, "Constant", 1, tT("false", "boolean")); }
              | STRINGVAL { $$ = createTreeNode(yylineno, "Constant", 1, tT(yylval.str, "string")); }
              | NULLVAL   { $$ = createTreeNode(yylineno, "Constant", 1, tT("null", "null")); }
;

%%

int main() {
  yyin = stdin;
  do {
    yyparse();
	} while(!feof(yyin));
	return 0;
}

void yyerror(char *s) {
  fprintf(stderr,"Error | Line: %d\n%s\n",yylineno,s);
}
