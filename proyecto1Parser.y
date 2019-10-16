%{
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>

extern FILE* yyin;
extern int yylineno;
void yyerror (char *s);
int yylex();
extern int yyparse();

struct treeNode{
    struct treeNode *child[10];
    char* nodeType;
    char* string;
    char* value;
    char* dataType;
    int lineNo;
    int Nchildren;
};

%}

%union {
	char* str;
	struct treeNode * ast;
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

%type<str> Type
%type<ast> Program Variable VariableDecl FunctionDecl ClassDecl InterfaceDecl Decl Decls

%%

Program: Decls { printf("f");}
;

Decls: Decl | Decls Decl {printf("ff");}
;

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
                |VOID ID LFTPARTH Formals RGHPARTH StmtBlock {
                    printf(" functionDecl void\n");
                }
;

Formals:    ManyFormals {printf(" Formals\n");}
            | /* empty */ {printf(" Formals Vacio\n");}
;

ManyFormals:   Variable {printf(" manyFormals");}
             | ManyFormals COMMA Variable {printf(" manyFormals comma");}
;

Identis:      ID {printf(" identis");} 
            | Identis COMMA ID {printf(" identisList");}
;

ClassDecl:     CLASS ID LFTGATE Fields RGHGATE {printf(" classDecl ");}
            |  CLASS ID  extend implementsList LFTGATE Fields RGHGATE {printf(" classDecl ");}
;

Fields:   /* empty */ {printf(" vacio");}
        |Fields Field {printf(" field de fields");};
;

extend: EXTENDS ID | /* empty */
;

implementsList: IMPLEMENTS Identis | /* empty */
;

Field: VariableDecl | FunctionDecl
;

InterfaceDecl: INTERFACE ID LFTGATE Prototypes RGHGATE {printf("interface");}
;

Prototypes: /* empty*/ | Prototypes Prototype
;

Prototype:  Type ID LFTPARTH Formals RGHPARTH SEMICLN | 
            VOID ID LFTPARTH Formals RGHPARTH SEMICLN
;

StmtBlock: LFTGATE  ManyVariables ManyStmt RGHGATE {printf(" stmBlock ");}
;

ManyVariables:  /* empty */| ManyVariables VariableDecl
;

ManyStmt: /* empty */
    | ManyStmt Stmt
;

Stmt:  Exprs SEMICLN | IfStmt | WhileStmt | ForStmt | BreakStmt |
       ReturnStmt | PrintStmt | StmtBlock
;

Exprs: /* empty */ | Expr
;

IfStmt: IF LFTPARTH Expr RGHPARTH Stmt ElseStmt
;

ElseStmt:   /* empty */ 
            | ELSE Stmt {printf(" else Carepu");}
;

WhileStmt: WHILE LFTPARTH Expr RGHPARTH Stmt
;
ExprOneOrZero: /* emptye */ | Expr
;
ForStmt: FOR  LFTPARTH ExprOneOrZero SEMICLN ExprOneOrZero SEMICLN ExprOneOrZero RGHPARTH Stmt {printf(" for ");}
;
ReturnStmt:  RETURN ExprOneOrZero SEMICLN
;
BreakStmt: BREAK SEMICLN
;
ManyExpr:  Expr | ManyExpr COMMA Expr
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
LValue: ID | Expr POINT ID | Expr LFTBRCKT Expr RGHBRCKT
;
Call: ID LFTPARTH Actuals RGHPARTH | Expr POINT ID LFTPARTH Actuals RGHPARTH
;
Actuals: ActualsLists | /* empty */
;
ActualsLists: Expr | ActualsLists COMMA Expr
;
Constant:   INTVAL | DOUBLEVAL | TRUE | FALSE 
            STRINGVAL | NULLVAL
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
