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
%token<str> ID
%token COMMA POINT LFTBRCKT RGHBRCKT LFTPARTH RGHPARTH SEMICLN
%token LFTGATE RGHGATE STRINGERROR INVCHAR INVESCP
%token LINEJMP TAB SPACE INTVAL DOUBLEVAL STRINGVAL NULLVAL

%left SUM SUB MULT DIV LESSTHN LESSEQL GREATERTHN MOD
%left GREATEREQL EQUAL SAME DIFF AND OR NOT

%type<str> SUM SUB MULT DIV LESSTHN LESSEQL GREATERTHN MOD
%type<treeNode> Field Prototype Prototypes
%type<treeNode> LValue Call Actuals Expr ActualsLists Constant Program
%type<treeNode> Variable VariableDecl FunctionDecl ClassDecl InterfaceDecl
%type<treeNode> Decl Decls Type PrintStmt ManyExpr BreakStmt ReturnStmt ForStmt
%type<treeNode> WhileStmt ElseStmt IfStmt Exprs Stmt ManyStmt ManyVariables StmtBlock
%type<treeNode> Fields ManyFormals ExprOneOrZero Formals implementsList Identis extend
%%

Program: Decls { $$ = createTreeNode(yylineno, 0, "NULL", "Program", 1, $1); printTree($$); freeTree($$);}
;

Decls:    Decl {$$ = createTreeNode(yylineno, 0, "NULL", "Decls", 1, $1);}
        | Decls Decl {$$ = createTreeNode(yylineno, 0, "NULL", "Decls", 2, $1, $2);}
;

Decl:     VariableDecl {$$ = createTreeNode(yylineno, 0, "NULL", "Decl", 1, $1);}
        | FunctionDecl {$$ = createTreeNode(yylineno, 0, "NULL", "Decl", 1, $1);}
        |  ClassDecl {$$ = createTreeNode(yylineno, 0, "NULL", "Decl", 1, $1);}
        | InterfaceDecl {$$ = createTreeNode(yylineno, 0, "NULL", "Decl", 1, $1);}
;

VariableDecl: Variable SEMICLN {
                struct TreeNode * node = createTreeNode(yylineno, 0, ";", "SEMICLN", 0);
                $$ = createTreeNode(yylineno, 0, "NULL", "VariableDecl", 2, $1, node);
                }

;

Variable: Type ID  {struct TreeNode * node = createTreeNode(yylineno, 0, yylval.str, "ID", 0); $$ = createTreeNode(yylineno, 0, "NULL", "Variable", 2, $1, node);}
;

Type: 	INTEGER 	{$$ = createTreeNode(yylineno, 0, "int", "Type", 0);}
		| DOUBLE 	{$$ = createTreeNode(yylineno, 0, "double", "Type", 0);}
		| BOOL 		{$$ = createTreeNode(yylineno, 0, "bool", "Type", 0);}
		| STRING 	{$$ = createTreeNode(yylineno, 0, "string", "Type", 0);}
		| ID 		{$$ = createTreeNode(yylineno, 0, yylval.str, "Type", 0);}
        | Type LFTBRCKT RGHBRCKT {
            struct TreeNode * lft = createTreeNode(yylineno, 0, "{", "LFTBRCKT", 0);
            struct TreeNode * rgh = createTreeNode(yylineno, 0, "}", "RGHBRCKT", 0);
            $$ = createTreeNode(yylineno, 0, "NULL", "Type", 3, $1, lft, rgh);
            }
;
//$$ = createTreeNode(yylineno, 0, "Function", "FunctionDecl", 6, $1, tT(yylval.str, "ID"), tN("("), $4, tN(")"), $6)
//$$ = eN()
FunctionDecl:   Type ID LFTPARTH Formals RGHPARTH StmtBlock {
                    struct TreeNode * node = createTreeNode(yylineno, 0, yylval.str, "ID", 0);
                    struct TreeNode * lft = createTreeNode(yylineno, 0, "(", "LFTPARTH", 0);
                    struct TreeNode * rgh = createTreeNode(yylineno, 0, ")", "RGHPARTH", 0);
                    $$ = createTreeNode(yylineno, 0, "NULL", "FunctionDecl", 6, $1, node, lft, $4, rgh, $6);
                    }
                | VOID ID LFTPARTH Formals RGHPARTH StmtBlock {

                struct TreeNode * Nvoid = createTreeNode(yylineno, 0, "void", "VOID", 0);
                struct TreeNode * node = createTreeNode(yylineno, 0, yylval.str, "ID", 0);
                struct TreeNode * lft = createTreeNode(yylineno, 0, "(", "LFTPARTH", 0);
                struct TreeNode * rgh = createTreeNode(yylineno, 0, ")", "RGHPARTH", 0);
                $$ = createTreeNode(yylineno, 0, "NULL", "FunctionDecl", 6, Nvoid, node, lft, $4, rgh, $6);}
;

Formals:        ManyFormals {$$ = createTreeNode(yylineno, 0, "NULL", "Formals", 1, $1);}
            |   /* empty */ {$$ = createTreeNode(yylineno, 0, "NULL", "Formals", 0);}
;
ManyFormals:   Variable {$$ = createTreeNode(yylineno, 0, "NULL", "ManyFormals", 1, $1);}
             | ManyFormals COMMA Variable {struct TreeNode * node = createTreeNode(yylineno, 0, ",", "COMMA", 0); $$ = createTreeNode(yylineno, 0, "NULL", "ManyFormals", 3, $1, node, $3);}
;

Identis:      ID {struct TreeNode * node = createTreeNode(yylineno, 0, yylval.str, "ID", 0); $$ = createTreeNode(yylineno, 0, "NULL", "Identis", 1, node);}
            | Identis COMMA ID {
                {
                struct TreeNode * nodeID = createTreeNode(yylineno, 0, yylval.str, "ID", 0);
                struct TreeNode * nodeCOMMA = createTreeNode(yylineno, 0, ",", "COMMA", 0);
                $$ = createTreeNode(yylineno, 0, "NULL", "Identis", 3,$1,nodeCOMMA,nodeID);}
            }
;

ClassDecl:  CLASS ID LFTGATE Fields RGHGATE  {
                struct TreeNode * class = createTreeNode(yylineno, 0, "Class", "CLASS", 0);
                struct TreeNode * nodeID = createTreeNode(yylineno, 0, yylval.str, "ID", 0);
                struct TreeNode * commaL = createTreeNode(yylineno, 0, "{", "LFTGATE", 0);
                struct TreeNode * commaR = createTreeNode(yylineno, 0, "}", "RGHGATE", 0);
                struct TreeNode * id = createTreeNode(yylineno, 0, yylval.str, "ID", 0);
                $$ = createTreeNode(yylineno, 0, "NULL", "Identis", 5,class,nodeID,commaL,$4,commaR);}
            | CLASS ID  extend implementsList LFTGATE Fields RGHGATE  {
                struct TreeNode * class = createTreeNode(yylineno, 0, "Class", "CLASS", 0);
                struct TreeNode * nodeID = createTreeNode(yylineno, 0, yylval.str, "ID", 0);
                struct TreeNode * commaL = createTreeNode(yylineno, 0, "{", "LFTGATE", 0);
                struct TreeNode * commaR = createTreeNode(yylineno, 0, "}", "RGHGATE", 0);
                struct TreeNode * id = createTreeNode(yylineno, 0, yylval.str, "ID", 0);
                $$ = createTreeNode(yylineno, 0, "NULL", "ClassDecl", 7, class,nodeID, $3, $4,commaL,$6,commaR);}
;
Fields:   /* empty */ {$$ = createTreeNode(yylineno, 0, "NULL", "Fields", 0);}
        |   Fields Field {$$ = createTreeNode(yylineno, 0, "NULL", "Fields", 2, $1, $2);};
;

extend:   EXTENDS ID {struct TreeNode * node = createTreeNode(yylineno, 0, yylval.str, "ID", 0); struct TreeNode * extend = createTreeNode(yylineno, 0, "extends", "extend", 0); $$ = createTreeNode(yylineno, 0, "NULL", "extend", 2, extend, node);}
        |   /* empty */ {$$ = createTreeNode(yylineno, 0, "NULL", "extend", 0);}
;

implementsList:    IMPLEMENTS Identis {struct TreeNode * implement = createTreeNode(yylineno, 0, "implement", "IMPLEMENTS", 0); $$ = createTreeNode(yylineno, 0, "NULL", "implementList", 2, implement, $2);}
                |   /* empty */ {$$ = createTreeNode(yylineno, 0, "NULL", "implementsList", 0);}
;

Field:    VariableDecl {$$ = createTreeNode(yylineno, 0, "NULL", "Field", 1, $1);}
        |   FunctionDecl {$$ = createTreeNode(yylineno, 0, "NULL", "Field", 1, $1);}
;

InterfaceDecl: INTERFACE ID LFTGATE Prototypes RGHGATE {
    struct TreeNode * interface = createTreeNode(yylineno, 0, "interface", "INTERFACE", 0);
    struct TreeNode * id = createTreeNode(yylineno, 0, yylval.str, "ID", 0);
    struct TreeNode * rgh = createTreeNode(yylineno, 0, "}", "RGHGATE", 0);
    struct TreeNode * lft = createTreeNode(yylineno, 0, "{", "LFTGATE", 0);
    $$ = createTreeNode(yylineno, 0, "NULL", "InterfaceDecl", 5, interface, id, lft, $4, rgh);}
;

Prototypes:   /* empty*/ {$$ = createTreeNode(yylineno, 0, "NULL", "Prototypes", 0);}
            |   Prototypes Prototype {$$ = createTreeNode(yylineno, 0, "NULL", "Prototypes", 2, $1, $2);}
;

Prototype:      Type ID LFTPARTH Formals RGHPARTH SEMICLN {
    struct TreeNode * id = createTreeNode(yylineno, 0, yylval.str, "ID", 0);
    struct TreeNode * rgh = createTreeNode(yylineno, 0, ")", "RGHPARTH", 0);
    struct TreeNode * lft = createTreeNode(yylineno, 0, "(", "LFTPARTH", 0);
    struct TreeNode * cln = createTreeNode(yylineno, 0, ";", "SEMICLN", 0);
    $$ = createTreeNode(yylineno, 0, "NULL", "Prototype", 6, $1, id, lft, $4, rgh, cln);}
            |   VOID ID LFTPARTH Formals RGHPARTH SEMICLN {
    struct TreeNode * Nvoid = createTreeNode(yylineno, 0, "void", "VOID", 0);
    struct TreeNode * id = createTreeNode(yylineno, 0, yylval.str, "ID", 0);
    struct TreeNode * rgh = createTreeNode(yylineno, 0, ")", "RGHPARTH", 0);
    struct TreeNode * lft = createTreeNode(yylineno, 0, "(", "LFTPARTH", 0);
    struct TreeNode * cln = createTreeNode(yylineno, 0, ";", "SEMICLN", 0);
    $$ = createTreeNode(yylineno, 0, "NULL", "Prototype", 6, Nvoid, id, lft, $4, rgh, cln);}
;

StmtBlock: LFTGATE  ManyVariables ManyStmt RGHGATE {
    struct TreeNode * rgh = createTreeNode(yylineno, 0, "}", "RGHGATE", 0);
    struct TreeNode * lft = createTreeNode(yylineno, 0, "{", "LFTGATE", 0);
    $$ = createTreeNode(yylineno, 0, "NULL", "StmtBlock", 4, lft, $2, $3, rgh);}
;
ManyVariables:      /* empty */ {$$ = createTreeNode(yylineno, 0, "NULL", "ManyVariables", 0);}
                |   ManyVariables VariableDecl {$$ = createTreeNode(yylineno, 0, "NULL", "ManyVariables", 2, $1, $2);}
;

ManyStmt:       /* empty */ {$$ = createTreeNode(yylineno, 0, "NULL", "ManyStmt", 0);}
            |   ManyStmt Stmt {$$ = createTreeNode(yylineno, 0, "NULL", "ManyStmt", 2, $1, $2);}
;

Stmt:       Exprs SEMICLN {
            struct TreeNode * cln = createTreeNode(yylineno, 0, ";", "SEMICLN", 0);
            $$ = createTreeNode(yylineno, 0, "NULL", "Stmt",2, $1, cln);}
        |   IfStmt {$$ = createTreeNode(yylineno, 0, "NULL", "Stmt", 1, $1);}
        |   WhileStmt {$$ = createTreeNode(yylineno, 0, "NULL", "Stmt", 1, $1);}
        |   ForStmt {$$ = createTreeNode(yylineno, 0, "NULL", "Stmt", 1, $1);}
        |   BreakStmt {$$ = createTreeNode(yylineno, 0, "NULL", "Stmt", 1, $1);}
        |   ReturnStmt {$$ = createTreeNode(yylineno, 0, "NULL", "Stmt", 1, $1);}
        |   PrintStmt {$$ = createTreeNode(yylineno, 0, "NULL", "Stmt", 1, $1);}
        |   StmtBlock {$$ = createTreeNode(yylineno, 0, "NULL", "Stmt", 1, $1);}
;

Exprs:      /* empty */ {$$ = createTreeNode(yylineno, 0, "NULL", "Exprs", 0);}
        |   Expr {$$ = createTreeNode(yylineno, 0, "NULL", "Exprs", 1, $1);}
;

IfStmt: IF LFTPARTH Expr RGHPARTH Stmt ElseStmt {
        struct TreeNode * rgh = createTreeNode(yylineno, 0, ")", "RGHPARTH", 0);
        struct TreeNode * lft = createTreeNode(yylineno, 0, "(", "LFTPARTH", 0);
        struct TreeNode * nodoIf = createTreeNode(yylineno, 0, "if", "IF", 0);
        $$ = createTreeNode(yylineno, 0, "NULL", "IfStmt", 6, nodoIf, lft, $3, rgh, $5, $6);}
;

ElseStmt:       /* empty */ {$$ = createTreeNode(yylineno, 0, "NULL", "ElseStmt", 0);}
            |   ELSE Stmt {
                struct TreeNode * Nelse = createTreeNode(yylineno, 0, "else", "ELSE", 0);
                $$ = createTreeNode(yylineno, 0, "NULL", "ElseStmt", 2, Nelse, $2);
            }
;

WhileStmt: WHILE LFTPARTH Expr RGHPARTH Stmt {
    struct TreeNode * rgh = createTreeNode(yylineno, 0, ")", "RGHPARTH", 0);
    struct TreeNode * lft = createTreeNode(yylineno, 0, "(", "LFTPARTH", 0);
    struct TreeNode * Nwhile = createTreeNode(yylineno, 0, "while", "WHILE", 0);
    $$ = createTreeNode(yylineno, 0, "NULL", "WhileStmt", 5, Nwhile, lft, $3, rgh, $5);}
;

ExprOneOrZero:      /* emptye */ {$$ = createTreeNode(yylineno, 0, "NULL", "ExprOneOrZero", 0);}
                |   Expr {$$ = createTreeNode(yylineno, 0, "NULL", "WhileStmt", 1, $1);}
;

ForStmt: FOR  LFTPARTH ExprOneOrZero SEMICLN ExprOneOrZero SEMICLN ExprOneOrZero RGHPARTH Stmt {
    struct TreeNode * rgh = createTreeNode(yylineno, 0, ")", "RGHPARTH", 0);
    struct TreeNode * lft = createTreeNode(yylineno, 0, "(", "LFTPARTH", 0);
    struct TreeNode * Nfor = createTreeNode(yylineno, 0, "for", "FOR", 0);
    struct TreeNode * cln = createTreeNode(yylineno, 0, ";", "cln", 0);
    struct TreeNode * cln2 = createTreeNode(yylineno, 0, ";", "cln", 0);
    $$ = createTreeNode(yylineno, 0, "NULL", "ForStmt", 9, Nfor, lft, $3, cln, $5, cln2, $7, rgh, $9);
}
;

ReturnStmt:  RETURN ExprOneOrZero SEMICLN {
    struct TreeNode * cln = createTreeNode(yylineno, 0, ";", "cln", 0);
    struct TreeNode * Nreturn = createTreeNode(yylineno, 0, "return", "RETURN", 0);
    $$ = createTreeNode(yylineno, 0, "NULL", "ReturnStmt", 3, Nreturn, $2, cln);
}
;

BreakStmt: BREAK SEMICLN {
    struct TreeNode * cln = createTreeNode(yylineno, 0, ";", "cln", 0);
    struct TreeNode * Nbreak = createTreeNode(yylineno, 0, "break", "BREAK", 0);
    $$ = createTreeNode(yylineno, 0, "NULL", "BreakStmt", 2, Nbreak, cln);
}
;

ManyExpr:       Expr {$$ = createTreeNode(yylineno, 0, "NULL", "ManyExpr", 1, $1);}
            |   ManyExpr COMMA Expr {
                struct TreeNode * comma = createTreeNode(yylineno, 0, ",", "COMMA", 0);
                $$ = createTreeNode(yylineno, 0, "NULL", "ManyExpr", 3, $1, comma, $3);
            }
;

PrintStmt: PRINT LFTPARTH ManyExpr RGHPARTH SEMICLN {
    struct TreeNode * cln = createTreeNode(yylineno, 0, ";", "cln", 0);
    struct TreeNode * rgh = createTreeNode(yylineno, 0, ")", "RGHPARTH", 0);
    struct TreeNode * lft = createTreeNode(yylineno, 0, "(", "LFTPARTH", 0);
    struct TreeNode * print = createTreeNode(yylineno, 0, "print", "PRINT", 0);
    $$ = createTreeNode(yylineno, 0, "NULL", "PrintStmt", 5, print, lft, $3, rgh, cln);
}
;

Expr:     LValue EQUAL Expr {
            struct TreeNode * nodeL = createTreeNode(yylineno, 0, "=", "EQUAL", 0);

            $$ = createTreeNode(yylineno, 0,"NULL", "Expr", 3,$1,nodeL,$3);
            }
        | LValue { $$ = createTreeNode(yylineno, 0,"NULL", "Expr",1,$1);}
        | Constant { $$ = createTreeNode(yylineno, 0,"NULL", "Expr",1,$1);}
        | THIS  { $$ = createTreeNode(yylineno, 0,"THIS", "Expr",0);}
        | Call { $$ = createTreeNode(yylineno, 0,"Call", "Expr",0);}
        | LFTPARTH Expr RGHPARTH {
            struct TreeNode * nodeR = createTreeNode(yylineno, 0, "(", "LFTPARTH", 0);
            struct TreeNode * nodeL = createTreeNode(yylineno, 0, ")", "RGHPARTH", 0);
            $$ = createTreeNode(yylineno, 0,"NULL", "Expr", 3,nodeR, $2, nodeL);
        }
        | Expr SUM Expr {
            struct TreeNode * nodeL = createTreeNode(yylineno, 0, "+", "DIV", 0);

            $$ = createTreeNode(yylineno, 0,"NULL", "Expr", 3,$1,nodeL,$3);
        }
        | Expr SUB Expr {
            struct TreeNode * nodeL = createTreeNode(yylineno, 0, "-", "DIV", 0);

            $$ = createTreeNode(yylineno, 0,"NULL", "Expr", 3,$1,nodeL,$3);
        }
        | Expr MULT Expr {
            struct TreeNode * nodeL = createTreeNode(yylineno, 0, "*", "DIV", 0);

            $$ = createTreeNode(yylineno, 0,"NULL", "Expr", 3,$1,nodeL,$3);
        }
        | Expr DIV Expr {
            struct TreeNode * nodeL = createTreeNode(yylineno, 0, "/", "DIV", 0);

            $$ = createTreeNode(yylineno, 0,"NULL", "Expr", 3,$1,nodeL,$3);
        }
        | Expr  MOD Expr {
            struct TreeNode * nodeL = createTreeNode(yylineno, 0, "%", "MOD", 0);

            $$ = createTreeNode(yylineno, 0,"NULL", "Expr", 3,$1,nodeL,$3);
        }
        | SUB Expr {
            struct TreeNode * nodeL = createTreeNode(yylineno, 0, "-", "SUB", 0);

            $$ = createTreeNode(yylineno, 0,"NULL", "Expr", 2,nodeL,$1);
        }
        | Expr LESSTHN Expr {
             struct TreeNode * nodeL = createTreeNode(yylineno, 0, "<", "LESSTHN", 0);

             $$ = createTreeNode(yylineno, 0,"NULL", "Expr",3,$1,nodeL,$3);
        }
        | Expr LESSEQL Expr {
               struct TreeNode * nodeL = createTreeNode(yylineno, 0, "<=", "LESSEQL", 0);

             $$ = createTreeNode(yylineno, 0,"NULL", "Expr", 3,$1,nodeL,$3);
        }
        | Expr GREATERTHN Expr {
             struct TreeNode * nodeL = createTreeNode(yylineno, 0, ">", "GREATERTHN", 0);

             $$ = createTreeNode(yylineno, 0,"NULL", "Expr", 3,$1,nodeL,$3);
        }
        | Expr GREATEREQL Expr {
             struct TreeNode * nodeL = createTreeNode(yylineno, 0, ">=", "GREATEREQL", 0);

             $$ = createTreeNode(yylineno, 0,"NULL", "Expr", 3,$1,nodeL,$3);
        }
        | Expr SAME Expr {
             struct TreeNode * nodeL = createTreeNode(yylineno, 0, "==", "SAME", 0);

             $$ = createTreeNode(yylineno, 0,"NULL", "Expr", 3,$1,nodeL,$3);
        }
        | Expr DIFF Expr {
            struct TreeNode * nodeL = createTreeNode(yylineno, 0, "!=", "DIFF", 0);

             $$ = createTreeNode(yylineno, 0,"NULL", "Expr", 3,$1,nodeL,$3);
        }
        | Expr AND Expr {
             struct TreeNode * nodeL = createTreeNode(yylineno, 0, "&&", "AND", 0);

             $$ = createTreeNode(yylineno, 0,"NULL", "Expr", 3,$1,nodeL,$3);
        }
        | Expr OR Expr {
             struct TreeNode * nodeL = createTreeNode(yylineno, 0, "||", "OR", 0);

             $$ = createTreeNode(yylineno, 0,"NULL", "Expr", 3,$1,nodeL,$3);
        }
        | NOT Expr {
            struct TreeNode * nodeID = createTreeNode(yylineno, 0, "!","NOT", 0);
            $$ = createTreeNode(yylineno, 0,"NULL", "Expr",2,nodeID,$2);
        }
        | READINTEGER {
            $$ = createTreeNode(yylineno, 0,"ReadInteger","Expr",0);
        }
        | READLINE {
            $$ = createTreeNode(yylineno, 0,"ReadLine","Expr",0);
        }
        | NEW LFTPARTH ID RGHPARTH {
            struct TreeNode * nodeN = createTreeNode(yylineno, 0, "new", "Expr", 0);
            struct TreeNode * nodeR = createTreeNode(yylineno, 0, "(", "Expr", 0);
            struct TreeNode * nodeL = createTreeNode(yylineno, 0, ")", "Expr", 0);
            struct TreeNode * nodeID = createTreeNode(yylineno, 0, yyval.str, "Expr", 0);
            $$ = createTreeNode(yylineno, 0,"NULL", "Expr",4,nodeN,nodeR,nodeID,nodeL);
        }
        | NEWARRAY LFTPARTH Expr COMMA Type RGHPARTH {
            struct TreeNode * nodeR = createTreeNode(yylineno, 0, "(", "Expr", 0);
            struct TreeNode * nodeL = createTreeNode(yylineno, 0, ")", "Expr", 0);
            struct TreeNode * nodeN = createTreeNode(yylineno, 0, "NEWARRAY", "Expr", 0);
            struct TreeNode * nodeComma = createTreeNode(yylineno, 0, ",", "Expr", 0);

            $$ = createTreeNode(yylineno, 0,"NULL", "Expr",6,nodeN,nodeR,$3,nodeComma,$5,nodeL);
            }
;
LValue:     ID {$$ = createTreeNode(yylineno, 0,yylval.str, "LValue",0);}
            | Expr POINT ID {
                struct TreeNode * nodeL = createTreeNode(yylineno, 0, "", "LValue", 0);
                struct TreeNode * nodeR = createTreeNode(yylineno, 0, "]", "LValue", 0);
                $$ = createTreeNode(yylineno, 0,"NULL", "LValue", 3,$1,nodeL,nodeR);
                }
            | Expr LFTBRCKT Expr RGHBRCKT {
                struct TreeNode * nodeL = createTreeNode(yylineno, 0, "[", "LValue", 0);
                struct TreeNode * nodeR = createTreeNode(yylineno, 0, "]", "LValue", 0);
                $$ = createTreeNode(yylineno, 0,"NULL", "LValue", 4,$1,nodeL,$3,nodeR);}
;
Call:       ID LFTPARTH Actuals RGHPARTH {
                        struct TreeNode * nodeL = createTreeNode(yylineno, 0, "(", "Call", 0);
                        struct TreeNode * nodeR = createTreeNode(yylineno, 0, ")", "Call", 0);
                        struct TreeNode * nodeID = createTreeNode(yylineno, 0, yyval.str, "Call", 0);
                        $$ = createTreeNode(yylineno, 0,"NULL", "Call", 4,nodeID,nodeL,$3,nodeR);}
            | Expr POINT ID LFTPARTH Actuals RGHPARTH {
                struct TreeNode * nodeL = createTreeNode(yylineno, 0, "(", "Call", 0);
                struct TreeNode * nodeR = createTreeNode(yylineno, 0, ")", "Call", 0);
                struct TreeNode * nodeID = createTreeNode(yylineno, 0, yyval.str, "Call", 0);
                 struct TreeNode * nodePoint = createTreeNode(yylineno, 0, ".", "Call", 0);
                $$ = createTreeNode(yylineno, 0,"NULL", "Call", 6,$1,nodePoint,nodeID,nodeL,$5,nodeR);
            }
;
Actuals:  /* empty */  {$$ = createTreeNode(yylineno, 0,"NULL", "Actuals", 0);}
         | ActualsLists {$$ = createTreeNode(yylineno, 0,"NULL", "Actuals", 1,$1);}
;
ActualsLists:       Expr {$$ = createTreeNode(yylineno, 0,"NULL", "ActualsLists", 1,$1);}
                |   ActualsLists COMMA Expr {
                            struct TreeNode * node = createTreeNode(yylineno, 0, ",", "COMMA", 0);
                            $$ = createTreeNode(yylineno, 0,"NULL", "ActualsLists", 3,$1,node,$3);
                            }
;
Constant:   INTVAL {$$ = createTreeNode(yylineno, 0, yylval.str, "INT", 0);}
            | DOUBLEVAL {$$ = createTreeNode(yylineno, 0, yylval.str, "DOUBLE", 0);}
            | TRUE {$$ = createTreeNode(yylineno, 0, "TRUE", "BOOL", 0);}
            | FALSE {$$ = createTreeNode(yylineno, 0, "FALSE", "BOOL", 0);}
            | STRINGVAL {$$ = createTreeNode(yylineno, 0, yylval.str, "STRINGVAL", 0);}
            | NULLVAL {$$ = createTreeNode(yylineno, 0, "NULL", "NULL", 0);}

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

void yyerror(char *s)
{
    fprintf(stderr,"Error | Line: %d\n%s\n",yylineno,s);
}
