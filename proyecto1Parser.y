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
<<<<<<< HEAD
=======
    struct ListNode * listNode;
>>>>>>> 8a92694c8f70e11535de40c3a6ad5ea61c8d0a9c
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
<<<<<<< HEAD

%type<str> SUM SUB MULT DIV LESSTHN LESSEQL GREATERTHN MOD
%type<treeNode> Expr ActualsLists Constant Program Variable VariableDecl FunctionDecl ClassDecl InterfaceDecl Decl Decls Type
=======
 
%type<treeNode> Type Program Variable VariableDecl FunctionDecl ClassDecl InterfaceDecl Decl Decls
>>>>>>> 8a92694c8f70e11535de40c3a6ad5ea61c8d0a9c

%%

Program:    Decls { $$ = createTreeNode(yylineno, 0, "NULL", "Program", 1, $1); printTree($$); freeTree($$);}
;

Decls:      Decl {$$ = createTreeNode(yylineno, 0, "NULL", "Decls", 1, $1);}
        |   Decls Decl {$$ = createTreeNode(yylineno, 0, "NULL", "Decls", 2, $1, $2);}
;

<<<<<<< HEAD
Decl:     VariableDecl
        | FunctionDecl
        |  ClassDecl {printf(" class ");}
        | InterfaceDecl {printf(" interface ");}
;

VariableDecl: Variable SEMICLN {printf(" varDecl ");$$=$1;}

;

Variable: Type ID  {printf(" var ");}
;

Type: 	INTEGER 	{printf("integer");}
		| DOUBLE 	{printf("double");}
		| BOOL 		{printf("boolean");}
		| STRING 	{printf("string");}
		| ID 		{printf(" Identificador");}
        | Type LFTBRCKT RGHBRCKT {printf(" Identificador Type");}
;

FunctionDecl:   Type ID LFTPARTH Formals RGHPARTH StmtBlock {
                    printf(" functionDecl\n");
                    }
                | VOID ID LFTPARTH Formals RGHPARTH StmtBlock {
                    printf(" functionDecl void\n");
                }
=======
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
>>>>>>> 8a92694c8f70e11535de40c3a6ad5ea61c8d0a9c
;

Formals:        ManyFormals {$$ = createTreeNode(yylineno, 0, "NULL", "Formals", 1, $1);}
            |   /* empty */ {$$ = createTreeNode(yylineno, 0, "NULL", "Formals", 0);}
;

ManyFormals:   Variable {$$ = createTreeNode(yylineno, 0, "NULL", "ManyFormals", 1, $1);}
             | ManyFormals COMMA Variable {struct TreeNode * node = createTreeNode(yylineno, 0, ",", "COMMA", 0); $$ = createTreeNode(yylineno, 0, "NULL", "ManyFormals", 3, $1, node, $3);}
;

<<<<<<< HEAD
Identis:      ID {printf(" identis");}
            | Identis COMMA ID {printf(" identisList");}
=======
Identis:      ID {struct TreeNode * node = createTreeNode(yylineno, 0, yylval.str, "ID", 0); $$ = createTreeNode(yylineno, 0, "NULL", "Identis", 1, node);} 
            | Identis COMMA ID {struct TreeNode * comma = createTreeNode(yylineno, 0, ",", "COMMA", 0); struct TreeNode * id = createTreeNode(yylineno, 0, yylval.str, "ID", 0); $$ = createTreeNode(yylineno, 0, "NULL", "Identis", 3, $1, comma, id);}
>>>>>>> 8a92694c8f70e11535de40c3a6ad5ea61c8d0a9c
;

ClassDecl:     CLASS ID LFTGATE Fields RGHGATE {printf(" classDecl ");}
            |  CLASS ID  extend implementsList LFTGATE Fields RGHGATE {printf(" classDecl ");}
;

<<<<<<< HEAD
Fields:  /* empty */ {printf(" vacio");}
        |Fields Field {printf(" field de fields");};
=======
Fields:     /* empty */ {printf(" vacio");}
        |   Fields Field {printf(" field de fields");};
>>>>>>> 8a92694c8f70e11535de40c3a6ad5ea61c8d0a9c
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

<<<<<<< HEAD
Prototype:  Type ID LFTPARTH Formals RGHPARTH SEMICLN |
            VOID ID LFTPARTH Formals RGHPARTH SEMICLN
=======
Prototype:      Type ID LFTPARTH Formals RGHPARTH SEMICLN 
            |   VOID ID LFTPARTH Formals RGHPARTH SEMICLN
>>>>>>> 8a92694c8f70e11535de40c3a6ad5ea61c8d0a9c
;

StmtBlock: LFTGATE  ManyVariables ManyStmt RGHGATE {printf(" stmBlock ");}
;

ManyVariables:      /* empty */
                |   ManyVariables VariableDecl
;

ManyStmt:       /* empty */
            |   ManyStmt Stmt
;

<<<<<<< HEAD
Stmt:  Exprs SEMICLN | IfStmt | WhileStmt | ForStmt | BreakStmt
        | ReturnStmt | PrintStmt | StmtBlock
;

Exprs: /* empty */ | Expr
=======
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
>>>>>>> 8a92694c8f70e11535de40c3a6ad5ea61c8d0a9c
;

IfStmt: IF LFTPARTH Expr RGHPARTH Stmt ElseStmt
;

<<<<<<< HEAD
ElseStmt:   /* empty */
            | ELSE Stmt {printf(" else Carepu");}
=======
ElseStmt:       /* empty */ 
            |   ELSE Stmt {printf(" else Carepu");}
>>>>>>> 8a92694c8f70e11535de40c3a6ad5ea61c8d0a9c
;

WhileStmt: WHILE LFTPARTH Expr RGHPARTH Stmt
;
<<<<<<< HEAD
ExprOneOrZero: /* emptye */ | Expr
;
ForStmt: FOR  LFTPARTH ExprOneOrZero SEMICLN ExprOneOrZero SEMICLN ExprOneOrZero RGHPARTH Stmt {printf(" for ");}
;
=======

ExprOneOrZero:      /* emptye */ 
                |   Expr
;

ForStmt: FOR  LFTPARTH ExprOneOrZero SEMICLN ExprOneOrZero SEMICLN ExprOneOrZero RGHPARTH Stmt {printf(" for ");}
;

>>>>>>> 8a92694c8f70e11535de40c3a6ad5ea61c8d0a9c
ReturnStmt:  RETURN ExprOneOrZero SEMICLN
;

BreakStmt: BREAK SEMICLN
;

ManyExpr:       Expr 
            |   ManyExpr COMMA Expr
;
<<<<<<< HEAD
PrintStmt: PRINT LFTPARTH ManyExpr RGHPARTH SEMICLN {printf(" printea ");}
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
=======

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
>>>>>>> 8a92694c8f70e11535de40c3a6ad5ea61c8d0a9c
        | NEWARRAY LFTPARTH Expr COMMA Type RGHPARTH
;

LValue:     ID 
        |   Expr POINT ID 
        |   Expr LFTBRCKT Expr RGHBRCKT
;

Call:       ID LFTPARTH Actuals RGHPARTH 
        |   Expr POINT ID LFTPARTH Actuals RGHPARTH
;
<<<<<<< HEAD
Actuals:  /* empty */ | ActualsLists
;
ActualsLists:       Expr {$$ = createTreeNode(yylineno, 0,"NULL", ActualsLists, 1,$1);}
                |   ActualsLists COMMA Expr {
                            struct TreeNode * node = createTreeNode(yylineno, 0, ",", "COMMA", 0);
                            $$ = createTreeNode(yylineno, 0,"NULL", ActualsLists, 3,$1,node,$3);
                            }
=======

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
>>>>>>> 8a92694c8f70e11535de40c3a6ad5ea61c8d0a9c
;
Constant:   INTVAL {$$ = createTreeNode(yylineno, 0, "NULL", "INTVAL", 0);}
            | DOUBLEVAL {$$ = createTreeNode(yylineno, 0, "NULL", "INTVAL", 0);}
            | TRUE {$$ = createTreeNode(yylineno, 0, "NULL", "INTVAL", 0);}
            | FALSE {$$ = createTreeNode(yylineno, 0, "NULL", "INTVAL", 0);}
            | STRINGVAL {$$ = createTreeNode(yylineno, 0, "NULL", "INTVAL", 0);}
            | NULLVAL {$$ = createTreeNode(yylineno, 0, "NULL", "INTVAL", 0);}

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
