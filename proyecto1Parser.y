%{
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>

#define MAXCHILD 10
void yyerror (char *s);
int yylex();
extern int yyparse();
extern FILE* yyin;
extern int yylineno;

int symbols[52];
int symbolVal(char symbol);
void updateSymbolVal(char symbol, int val);


char* tab="  ";
char indent[100]="";

char* integer="INT";
char* floating="float";
char* none = "none";
char* assign = "=";

void incIndent(){
    strcat(indent, tab);
}
void decIndent(){
    int len = strlen(indent);
    indent[len-2]='\0';
}

struct treeNode{
    struct treeNode *child[MAXCHILD];
    char* nodeType;
    char* string;
    char* value;
    char* dataType;
    int lineNo;
    int Nchildren;
};
void printNode(struct treeNode* node){
    printf("%s<Tree lineNo=\"%d\" nodeType=\"%s\" string=\"%s\" value=\"%s\" dataType=\"%s\">\n", 
        indent,
        node->lineNo,
        node->nodeType,
        node->string,
        node->value, 
        node->dataType);
    int i;
    if (node->Nchildren > 0){
        printf("%s<Child>\n", indent);
        incIndent();
        for (i=0;i<node->Nchildren;i++){
            printNode(node->child[i]);
        }
        decIndent();
        printf("%s</Child>\n", indent);
    }
    printf("%s</Tree>\n", indent);
}

struct treeNode * newnode(int lineNo, char* nodeType, 
							char* string, char* value, 
								char* dataType, int Nchildren, ...){

    struct treeNode * node = (struct treeNode*) malloc(sizeof(struct treeNode));
    node->nodeType = nodeType;
    node->string = string;
    node->value = value;
    node->dataType = dataType;
    node->lineNo = lineNo;
    node->Nchildren = Nchildren;
    va_list ap;
    int i;
    va_start(ap, Nchildren);
    for (i=0;i<Nchildren;i++){
        node->child[i]=va_arg(ap, struct treeNode *);
    }
    va_end(ap);
    return node;
}


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

Program: Decls { printf("f"); printNode($1);}
;

Decls: Decl | Decls Decl
;
Decl:   VariableDecl {printf("d");$$=$1;}
        | FunctionDecl
        | ClassDecl
        | InterfaceDecl 
;

VariableDecl: Variable SEMICLN {printf("c");$$=$1;}
;

Variable: Type ID  {
            printf("d");
			$$=newnode(yylineno, "variable", none, none, $1, 0); 
			}
;
Type: 	INTEGER 	{printf("integer");$$="INTEGER";}
		| DOUBLE 	{printf("double");}
		| BOOL 		{printf("boolean");} 
		| STRING 	{printf("string");}
		| ID 		{printf("Identificador");}
        | Type LFTBRCKT RGHBRCKT {printf("Identificador");}
;

FunctionDecl: Type ID LFTPARTH Formals RGHPARTH StmtBlock {$$=newnode(yylineno, "function", none, none, $1, 0);}
                |VOID ID LFTPARTH Formals RGHPARTH StmtBlock
;
Formals:  ManyFormals| /* empty */
;
ManyFormals: Variable | ManyFormals COMMA Variable
;
Identis: ID | Identis COMMA ID
;

Fields:   /* empty */ | Fields Field 
;
ClassDecl:    CLASS ID  extend implementsList LFTGATE Fields RGHGATE
            | CLASS ID LFTGATE Fields RGHGATE
;
extend: EXTENDS ID | /* empty */
;
implementsList: IMPLEMENTS Identis | /* empty */
;
Field: VariableDecl | FunctionDecl
;
InterfaceDecl: INTERFACE ID LFTGATE Prototypes RGHGATE
;
Prototypes: /* empty*/ | Prototypes Prototype
;
Prototype:  Type ID LFTPARTH Formals RGHPARTH SEMICLN | 
            VOID ID LFTPARTH Formals RGHPARTH SEMICLN
;
StmtBlock: LFTGATE  ManyVariables ManyStmt RGHGATE
;
ManyVariables:  /* empty */| ManyVariables VariableDecl
;
ManyStmt: /* empty */
    | ManyStmt Stmt
;
Stmt:  Exprs | IfStmt | WhileStmt | ForStmt | BreakStmt |
       ReturnStmt | PrintStmt | StmtBlock
;
Exprs: Expr SEMICLN | /* empty */
;
IfStmt: IF LFTPARTH Expr RGHPARTH Stmt ElseStmt
;
ElseStmt: /* empty */ | ELSE Stmt 
;
WhileStmt: WHILE LFTPARTH Expr RGHPARTH Stmt
;
ExprOneOrZero: Expr | /* emptye */
;
ForStmt: FOR  LFTPARTH ExprOneOrZero SEMICLN ExprOneOrZero SEMICLN ExprOneOrZero RGHPARTH Stmt
;
ReturnStmt:  RETURN ExprOneOrZero 
;
BreakStmt: BREAK SEMICLN
;
ManyExpr:  Expr | ManyExpr COMMA Expr
;
PrintStmt: PRINT LFTPARTH ManyExpr RGHPARTH;
;
Expr:   LValue EQUAL Expr | 
        Constant | 
        LValue | 
        THIS | Call | 
        LFTPARTH Expr RGHPARTH| 
        Expr SUM Expr | 
        Expr SUB Expr | 
        Expr MULT Expr | 
        Expr DIV Expr | 
        Expr  MOD Expr | 
        SUB Expr | 
        Expr LESSTHN Expr | 
        Expr LESSEQL Expr |
        Expr GREATERTHN Expr | 
        Expr GREATEREQL Expr | 
        Expr SAME Expr | 
        Expr DIFF Expr |
        Expr AND Expr | 
        Expr OR Expr | 
        NOT Expr | 
        READINTEGER| 
        READLINE | 
        NEW LFTPARTH ID RGHPARTH | 
        LFTPARTH Expr COMMA Type RGHPARTH
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

int computeSymbolIndex(char token)
{
	int idx = -1;
	if(islower(token)) {
		idx = token - 'a' + 26;
	} else if(isupper(token)) {
		idx = token - 'A';
	}
	return idx;
} 

/* returns the value of a given symbol */
int symbolVal(char symbol)
{
	int bucket = computeSymbolIndex(symbol);
	return symbols[bucket];
}

/* updates the value of a given symbol */
void updateSymbolVal(char symbol, int val)
{
	int bucket = computeSymbolIndex(symbol);
	symbols[bucket] = val;
}

int main() {
	yyin = stdin;

	do {
		yyparse();
	} while(!feof(yyin));

	return 0;
}

void yyerror (char *s) {
	fprintf (stderr, "%s\n", s);} 
