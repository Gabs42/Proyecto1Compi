%{

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include "tree.c"

extern FILE* yyin;
extern int yylineno;
void yyerror (char *s);
int yylex();
extern int yyparse();

%}

%union {
	char* str;
	struct TreeNode * treeNode;
    struct ListNode * listNode;
    int intval;
}

%start Program
%token VOID INTEGER DOUBLE BOOL STRING 
%token CLASS INTERFACE NULLN THIS EXTENDS IMPLEMENTS 
%token FOR WHILE IF ELSE RETURN BREAK NEW NEWARRAY 
%token PRINT READINTEGER READLINE TRUE FALSE 
%token<str> ID
%token COMMA POINT LFTBRCKT RGHBRCKT LFTPARTH RGHPARTH SEMICLN 
%token LFTGATE RGHGATE STRINGERROR INVCHAR INVESCP 
%token LINEJMP TAB SPACE INTVAL DOUBLEVAL STRINGVAL NULLVAL

%left SUM SUB MULT DIV LESSTHN LESSEQL GREATERTHN MOD
%left GREATEREQL EQUAL SAME DIFF AND OR NOT
 
%type<treeNode> Type Program Variable VariableDecl FunctionDecl ClassDecl InterfaceDecl Decl Decls

%%

Program:    Decls { $$ = createTreeNode(yylineno, 0, "NULL", "Program", 1, $1); printTree($$); freeTree($$);}
;

Decls:      Decl {$$ = createTreeNode(yylineno, 0, "NULL", "Decls", 1, $1);}
        |   Decls Decl {$$ = createTreeNode(yylineno, 0, "NULL", "Decls", 2, $1, $2);}
;

Decl:       VariableDecl {$$ = createTreeNode(yylineno, 0, "NULL", "Decl", 1, $1);}
        |   FunctionDecl {$$ = createTreeNode(yylineno, 0, "NULL", "Decl", 1, $1);}
        |   ClassDecl {$$ = createTreeNode(yylineno, 0, "NULL", "Decl", 1, $1);}
        |   InterfaceDecl {$$ = createTreeNode(yylineno, 0, "NULL", "Decl", 1, $1);}
;

VariableDecl: Variable SEMICLN {struct TreeNode * node = createTreeNode(yylineno, 0, ";", "SEMICLN", 0); $$ = createTreeNode(yylineno, 0, "NULL", "VariableDecl", 2, $1, node);}               
;

Variable: Type ID  {struct TreeNode * node = createTreeNode(yylineno, 0, yylval.str, "ID", 0); $$ = createTreeNode(yylineno, 0, "NULL", "Variable", 2, $1, node);}
;

Type: 	    INTEGER {$$ = createTreeNode(yylineno, 0, "int", "Type", 0);}
		|   DOUBLE 	{$$ = createTreeNode(yylineno, 0, "double", "Type", 0);}
		|   BOOL 	{$$ = createTreeNode(yylineno, 0, "bool", "Type", 0);} 
		|   STRING 	{$$ = createTreeNode(yylineno, 0, "string", "Type", 0);}
		|   ID 		{$$ = createTreeNode(yylineno, 0, yylval.str, "Type", 0);}
        |   Type LFTBRCKT RGHBRCKT {struct TreeNode * lft = createTreeNode(yylineno, 0, "{", "LFTBRCKT", 0); struct TreeNode * rgh = createTreeNode(yylineno, 0, "}", "RGHBRCKT", 0); $$ = createTreeNode(yylineno, 0, "NULL", "Type", 3, $1, lft, rgh);}
;

FunctionDecl:       Type ID LFTPARTH Formals RGHPARTH StmtBlock {struct TreeNode * node = createTreeNode(yylineno, 0, yylval.str, "ID", 0); struct TreeNode * lft = createTreeNode(yylineno, 0, "(", "LFTPARTH", 0); struct TreeNode * rgh = createTreeNode(yylineno, 0, ")", "RGHPARTH", 0); $$ = createTreeNode(yylineno, 0, "NULL", "Type", 6, $1, node, lft, $4, rgh, $6);}
                |   VOID ID LFTPARTH Formals RGHPARTH StmtBlock {struct TreeNode * void = createTreeNode(yylineno, 0, "void", "VOID", 0); struct TreeNode * node = createTreeNode(yylineno, 0, yylval.str, "ID", 0); struct TreeNode * lft = createTreeNode(yylineno, 0, "(", "LFTPARTH", 0); struct TreeNode * rgh = createTreeNode(yylineno, 0, ")", "RGHPARTH", 0); $$ = createTreeNode(yylineno, 0, "NULL", "FunctionDecl", 6, void, node, lft, $4, rgh, $6);}
;

Formals:        ManyFormals {$$ = createTreeNode(yylineno, 0, "NULL", "Formals", 1, $1);}
            |   /* empty */ {$$ = createTreeNode(yylineno, 0, "NULL", "Formals", 0);}
;

ManyFormals:   Variable {$$ = createTreeNode(yylineno, 0, "NULL", "ManyFormals", 1, $1);}
             | ManyFormals COMMA Variable {struct TreeNode * node = createTreeNode(yylineno, 0, ",", "COMMA", 0); $$ = createTreeNode(yylineno, 0, "NULL", "ManyFormals", 3, $1, node, $3);}
;

Identis:      ID {struct TreeNode * node = createTreeNode(yylineno, 0, yylval.str, "ID", 0); $$ = createTreeNode(yylineno, 0, "NULL", "Identis", 1, node);} 
            | Identis COMMA ID {struct TreeNode * comma = createTreeNode(yylineno, 0, ",", "COMMA", 0); struct TreeNode * id = createTreeNode(yylineno, 0, yylval.str, "ID", 0); $$ = createTreeNode(yylineno, 0, "NULL", "Identis", 3, $1, comma, id);}
;

ClassDecl:     CLASS ID LFTGATE Fields RGHGATE {printf(" classDecl ");}
            |  CLASS ID  extend implementsList LFTGATE Fields RGHGATE {printf(" classDecl ");}
;

Fields:     /* empty */ {printf(" vacio");}
        |   Fields Field {printf(" field de fields");};
;

extend:     EXTENDS ID 
        |   /* empty */
;

implementsList:     IMPLEMENTS Identis 
                |   /* empty */
;

Field:      VariableDecl 
        |   FunctionDecl
;

InterfaceDecl: INTERFACE ID LFTGATE Prototypes RGHGATE {printf("interface");}
;

Prototypes:     /* empty*/ 
            |   Prototypes Prototype
;

Prototype:      Type ID LFTPARTH Formals RGHPARTH SEMICLN 
            |   VOID ID LFTPARTH Formals RGHPARTH SEMICLN
;

StmtBlock: LFTGATE  ManyVariables ManyStmt RGHGATE {printf(" stmBlock ");}
;

ManyVariables:      /* empty */
                |   ManyVariables VariableDecl
;

ManyStmt:       /* empty */
            |   ManyStmt Stmt
;

Stmt:       Exprs SEMICLN 
        |   IfStmt 
        |   WhileStmt 
        |   ForStmt 
        |   BreakStmt 
        |   ReturnStmt 
        |   PrintStmt 
        |   StmtBlock
;

Exprs:      /* empty */ 
        |   Expr
;

IfStmt: IF LFTPARTH Expr RGHPARTH Stmt ElseStmt
;

ElseStmt:       /* empty */ 
            |   ELSE Stmt {printf(" else Carepu");}
;

WhileStmt: WHILE LFTPARTH Expr RGHPARTH Stmt
;

ExprOneOrZero:      /* emptye */ 
                |   Expr
;

ForStmt: FOR  LFTPARTH ExprOneOrZero SEMICLN ExprOneOrZero SEMICLN ExprOneOrZero RGHPARTH Stmt {printf(" for ");}
;

ReturnStmt:  RETURN ExprOneOrZero SEMICLN
;

BreakStmt: BREAK SEMICLN
;

ManyExpr:       Expr 
            |   ManyExpr COMMA Expr
;

PrintStmt: PRINT LFTPARTH ManyExpr RGHPARTH SEMICLN
;

Expr:     LValue EQUAL Expr {printf(" asignacion");} 
        | LValue 
        | Constant
        | THIS  
        | Call 
        | LFTPARTH Expr RGHPARTH
        | Expr SUM Expr {printf(" suma");}
        | Expr SUB Expr 
        | Expr MULT Expr 
        | Expr DIV Expr 
        | Expr  MOD Expr 
        | SUB Expr 
        | Expr LESSTHN Expr 
        | Expr LESSEQL Expr 
        | Expr GREATERTHN Expr 
        | Expr GREATEREQL Expr 
        | Expr SAME Expr 
        | Expr DIFF Expr 
        | Expr AND Expr 
        | Expr OR Expr 
        | NOT Expr 
        | READINTEGER
        | READLINE 
        | NEW LFTPARTH ID RGHPARTH 
        | NEWARRAY LFTPARTH Expr COMMA Type RGHPARTH
;

LValue:     ID 
        |   Expr POINT ID 
        |   Expr LFTBRCKT Expr RGHBRCKT
;

Call:       ID LFTPARTH Actuals RGHPARTH 
        |   Expr POINT ID LFTPARTH Actuals RGHPARTH
;

Actuals:        ActualsLists 
            |   /* empty */
;

ActualsLists:       Expr 
                |   ActualsLists COMMA Expr
;

Constant:       INTVAL 
            |   DOUBLEVAL 
            |   TRUE 
            |   FALSE 
            |   STRINGVAL 
            |   NULLVAL
;

%%        
             /* C code */


int main() {
    // #ifdef YYDEBUG
    //     yydebug = 1;
    // #endif

	yyin = stdin;

	do {
		yyparse();
	} while(!feof(yyin));
//ya
	return 0;
}

void yyerror (char *s) {
	fprintf (stderr, "%s\n", s);
} 
