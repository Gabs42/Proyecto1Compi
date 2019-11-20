%{

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include "scopeList.c"

extern FILE* yyin;
extern int yylineno;
extern int yyparse();
void yyerror (char *s);
struct SymbolNode * createSymbol(struct TreeNode * variable);
struct SymbolNode * createSymbolAux(struct TreeNode * type, char * id, int dimension);
int yylex();
char* symbols[50][3];
int fila = 0;

struct TreeNode * tree;

struct Scope * globalScope;

struct ScopeNode * classList;

struct ScopeNode * scopeList;
struct SymbolNode * symbolList;

struct SymbolNode * symbolClass;

struct SymbolNode * symbolGlobal;
struct ScopeNode * functionsGlobal;

struct SymbolNode * symbolExtends;
struct ScopeNode * scopeExtends;

//Validations functions

void adjustFScope();

struct Scope * getScope(struct TreeNode * node);
struct Scope * getScopeAux(struct TreeNode * node, struct Scope * scope);

struct Scope * getFunctionScope(struct Scope * classScope, char * id, int global);

struct Scope * checkClass(char * id);

struct Scope * getScopeInterface(char * id);

struct Scope * getScopeClass(char * id);

int compareSymbolNodes(struct SymbolNode * params,struct SymbolNode * funct);

struct SymbolNode * dupSymbol(struct SymbolNode * symbol);

struct SymbolNode * getParams(struct Scope * function);

struct SymbolNode * getTypeActuals(struct TreeNode * actuals, struct Scope * scope);
struct SymbolNode * getTypeActualsAux(struct TreeNode * list, struct Scope * scope);

int checkAtributtes(struct Scope * class);

struct Scope * methodInterface(struct Scope * class, char * id);

int methodsInInterface(struct Scope * implements, struct Scope * class);

int implementMethods(struct Scope * class);
int implementMethodsAux(struct Scope * class, struct Scope * fScope);

int scopeInList(struct Scope * scope, struct ScopeNode * list);

int scopesInList(struct ScopeNode * list, struct ScopeNode * scope);

int checkImplementation(struct Scope * method1, struct Scope * method2);

int checkMethods(struct Scope * class);

int checkSubClass(char * class, char * subClass);

int checkSymbolScope(struct Scope * scope);

int checkFunctionReturn(struct TreeNode * returnNode, struct Scope * function);

struct SymbolNode * getTypeId(char * id, struct Scope * scope);

struct SymbolNode * getTypeFunction(char * id, struct Scope * scope);

char * getTypeConstant(struct TreeNode * node);
char * getValueConstant(struct TreeNode * node);

int compareReturnFunctions(struct Scope * scope1, struct Scope * scope2);

struct SymbolNode * getTypeReturn(struct TreeNode * node, struct Scope * actualScope);

struct SymbolNode * getTypeExpr(struct TreeNode * node, struct Scope * actualScope);

struct SymbolNode * getTypeLValue(struct TreeNode * node, struct Scope * actualScope);

struct SymbolNode * getTypeCall(struct TreeNode * node, struct Scope * actualScope);

void probarMetodo(struct TreeNode * node, struct Scope * actualScope);

%}

%locations

%union {
  char* str;
	struct TreeNode * treeNode;
  int intval;
  struct SymbolNode * symbolNode;
  struct Scope * scope;
}

%start Program

%token VOID INTEGER DOUBLE BOOL STRING
%token CLASS INTERFACE NULLN THIS EXTENDS IMPLEMENTS
%token FOR WHILE IF ELSE RETURN BREAK NEW NEWARRAY
%token PRINT READINTEGER READLINE TRUE FALSE
%token COMMA POINT LFTBRCKT RGHBRCKT LFTPARTH RGHPARTH SEMICLN
%token LFTGATE RGHGATE STRINGERROR INVCHAR INVESCP
%token LINEJMP TAB SPACE INTVAL DOUBLEVAL STRINGVAL
%token OR LESSEQL
%token<str> ID

%left SUM SUB MULT DIV LESSTHN LESSEQL GREATERTHN MOD GREATEREQL
%left EQUAL SAME DIFF AND OR NOT

%type<str> SUM SUB MULT DIV LESSTHN LESSEQL GREATERTHN MOD

%type<treeNode> Program Declarations Declaration VariableDecl Variable Type
%type<treeNode> FunctionDecl Formals Variables ClassDecl Extend Implement FixCall
%type<treeNode> ListIdents Fields Field InterfaceDecl Prototypes Prototype FixLValue
%type<treeNode> StmtBlock Stmts Stmt PossibleExpr IfStmt InterfaceName PrototypeName
%type<treeNode> PossibleElse WhileStmt ForStmt ReturnStmt BreakStmt PrintStmt
%type<treeNode> ListExpr Expr LValue Call Actuals Constant FunctionName ClassName

%%

Program:        Declarations  { $$ = createTreeNode(yylineno, "Program", 1, $1);
                                tree = $$;
                                globalScope = createScope("global", "Global");
                                globalScope = setFScope(globalScope, classList);
                                globalScope = setPScope(globalScope, classList);
                                globalScope = setPScope(globalScope, functionsGlobal);
                                globalScope = setFScope(globalScope, functionsGlobal);
                                globalScope = insertSymbol(globalScope, symbolGlobal);
                                globalScope = setTree(globalScope, $$);
                                symbolGlobal = 0;
                                functionsGlobal = 0;
                              }
;

Declarations:   Declaration               { $$ = createTreeNode(yylineno, "Declarations", 1, $1); }
              | Declarations Declaration  { $$ = createTreeNode(yylineno, "Declarations", 2, $1, $2); }
;

Declaration:    VariableDecl  { $$ = createTreeNode(yylineno, "Declaration", 1, $1);
                                struct TreeNode * variable = $1->root->node;
                                struct SymbolNode * newSymbol = createSymbol(variable);
                                symbolGlobal = insertSymbolNode(symbolGlobal, newSymbol);
                              }
              | FunctionDecl  { $$ = createTreeNode(yylineno, "Declaration", 1, $1);
                                struct Scope * newScope = createScope($1->root->node->root->next->node->value, "Function");
                                newScope = insertSymbol(newScope, symbolList);
                                newScope = setTree(newScope, $1);
                                struct ScopeNode * newNode = createScopeNode(newScope);
                                functionsGlobal = insertScopeNode(functionsGlobal, newNode);
                                symbolList = 0;
                              }
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

FunctionDecl:   FunctionName LFTPARTH Formals RGHPARTH StmtBlock  { $$ = createTreeNode(yylineno, "FunctionDecl", 5, $1, tN("("), $3, tN(")"), $5); }
;

FunctionName:   Type ID { $$ = createTreeNode(yylineno, "FunctionName", 2, $1, tT(yylval.str, "ID")); }
              | VOID ID { $$ = createTreeNode(yylineno, "FunctionName", 2, tN("void"), tT(yylval.str, "ID")); }
;

Formals:        Variables   { $$ = createTreeNode(yylineno, "Formals", 1, $1); }
              | /* empty */ { $$ = eN(); }
;

Variables:      Variable                  { $$ = createTreeNode(yylineno, "Variables", 1, $1);
                                            struct TreeNode * variable = $1;
                                            struct SymbolNode * newSymbol = createSymbol(variable);
                                            newSymbol->parameter = 1;
                                            symbolList = insertSymbolNode(symbolList, newSymbol);
                                          }
              | Variables COMMA Variable  { $$ = createTreeNode(yylineno, "Variables", 3, $1, tN(","), $3); 
                                            struct TreeNode * variable = $3;
                                            struct SymbolNode * newSymbol = createSymbol(variable);
                                            newSymbol->parameter = 1;
                                            symbolList = insertSymbolNode(symbolList, newSymbol);
                                          }
;

ClassDecl:      ClassName Extend Implement LFTGATE Fields RGHGATE { $$ = createTreeNode(yylineno, "ClassDecl", 6, $1, $2, $3, tN("{"), $5, tN("}"));
                                                                    struct Scope * newScope = createScope($1->root->next->node->value, "Class");
                                                                    newScope = insertSymbol(newScope, symbolClass);
                                                                    newScope = setFScope(newScope, scopeList);
                                                                    newScope = setPScope(newScope, scopeList);
                                                                    newScope = setTree(newScope, $$);
                                                                    struct ScopeNode * newNode = createScopeNode(newScope);
                                                                    classList = insertScopeNode(classList, newNode);
                                                                    scopeList = 0;
                                                                    symbolClass = 0;
                                                                    struct Scope * newScopeExtend = createScope($1->root->next->node->value, "Class");
                                                                    newScopeExtend = insertSymbol(newScopeExtend, symbolExtends);
                                                                    struct ScopeNode * newNodeExtend = createScopeNode(newScopeExtend);
                                                                    scopeExtends = insertScopeNode(scopeExtends, newNodeExtend);
                                                                    symbolExtends = 0;
                                                                  }
;

ClassName:      CLASS ID {$$ = createTreeNode(yylineno, "ClassName", 2, tN("Class"), tT(yylval.str, "ID"));}
;

Extend:         EXTENDS ID  { $$ = createTreeNode(yylineno, "Extend", 2, tN("extends"), tT(yylval.str, "ID"));
                              struct SymbolNode * newSymbol = createSymbolNode("extend", yylval.str);
                              symbolExtends = insertSymbolNode(symbolExtends, newSymbol);
                            }
              | /* empty */ { $$ = eN(); }
;

Implement:      IMPLEMENTS ListIdents { $$ = createTreeNode(yylineno, "Implement", 2, tN("implements"), $2); }
              | /* empty */           { $$ = eN(); }
;

ListIdents:     ID                  { $$ = createTreeNode(yylineno, "ListIdents", 1, tT(yylval.str, "ID")); 
                                      struct SymbolNode * newSymbol = createSymbolNode("implement", yylval.str);
                                      symbolExtends = insertSymbolNode(symbolExtends, newSymbol);
                                    }
              | ListIdents COMMA ID { $$ = createTreeNode(yylineno, "ListIdents", 3, $1, tN(","), tT(yylval.str, "ID")); 
                                      struct SymbolNode * newSymbol = createSymbolNode("implement", yylval.str);
                                      symbolExtends = insertSymbolNode(symbolExtends, newSymbol);
                                    }
;

Fields:         Fields Field  { $$ = createTreeNode(yylineno, "Fields", 2, $1, $2); }
              | /* empty */   { $$ = eN(); }
;

Field:          VariableDecl  { $$ = createTreeNode(yylineno, "Field", 1, $1);
                                struct TreeNode * variable = $1->root->node;
                                struct SymbolNode * newSymbol = createSymbol(variable);
                                symbolClass = insertSymbolNode(symbolClass, newSymbol);
                              }
              | FunctionDecl  { $$ = createTreeNode(yylineno, "Field", 1, $1); 
                                struct Scope * newScope = createScope($1->root->node->root->next->node->value, "Function");
                                newScope = insertSymbol(newScope, symbolList);
                                newScope = setTree(newScope, $1);
                                struct ScopeNode * newNode = createScopeNode(newScope);
                                scopeList = insertScopeNode(scopeList, newNode);
                                symbolList = 0;
                              }
;

InterfaceDecl:  InterfaceName LFTGATE Prototypes RGHGATE  { $$ = createTreeNode(yylineno, "InterfaceDecl", 4, $1, tN("{"), $3, tN("}"));
                                                            struct Scope * newScope = createScope($1->root->next->node->value, "Interface");
                                                            newScope = setFScope(newScope, scopeList);
                                                            newScope = setPScope(newScope, scopeList);
                                                            newScope = setTree(newScope, $$);
                                                            struct ScopeNode * newNode = createScopeNode(newScope);
                                                            classList = insertScopeNode(classList, newNode);
                                                            scopeList = 0;
                                                            struct Scope * newScopeExtend = createScope($1->root->next->node->value, "Interface");
                                                            newScopeExtend = insertSymbol(newScopeExtend, symbolExtends);
                                                            struct ScopeNode * newNodeExtend = createScopeNode(newScopeExtend);
                                                            scopeExtends = insertScopeNode(scopeExtends, newNodeExtend);
                                                            symbolExtends = 0;
                                                          }
;

InterfaceName:  INTERFACE ID { $$ = createTreeNode(yylineno, "InterfaceName", 2, tN("interface"), tT(yylval.str, "ID")); }
;

Prototypes:     Prototypes Prototype  { $$ = createTreeNode(yylineno, "Prototypes", 2, $1, $2); }
              | /* empty */           { $$ = eN(); }
;

Prototype:      PrototypeName LFTPARTH Formals RGHPARTH SEMICLN { $$ = createTreeNode(yylineno, "Prototype", 5, $1, tN("("), $3, tN(")"), tN(";"));
                                                                  struct Scope * newScope = createScope($1->root->next->node->value, "Function");
                                                                  newScope = insertSymbol(newScope, symbolList);
                                                                  newScope = setTree(newScope, $$);
                                                                  struct ScopeNode * newNode = createScopeNode(newScope);
                                                                  scopeList = insertScopeNode(scopeList, newNode);
                                                                  symbolList = 0;
                                                                }
;

PrototypeName:  Type ID { $$ = createTreeNode(yylineno, "PrototypeName", 2, $1, tT(yylval.str, "ID")); }
              | VOID ID { $$ = createTreeNode(yylineno, "PrototypeName", 2, tN("void"), tT(yylval.str, "ID")); }
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
              | Expr          { $$ = createTreeNode(yylineno, "Stmt", 1, $1); }
              | VariableDecl  { $$ = createTreeNode(yylineno, "Stmt", 1, $1);
                                struct TreeNode * variable = $1->root->node;
                                struct SymbolNode * newSymbol = createSymbol(variable);
                                symbolList = insertSymbolNode(symbolList, newSymbol);
                              }
;

PossibleExpr:   Expr        { $$ = createTreeNode(yylineno, "PossibleExpr", 1, $1); }
              | /* empty */ { $$ = eN(); }
;

IfStmt:         IF LFTPARTH Expr RGHPARTH Stmt PossibleElse { $$ = createTreeNode(yylineno, "IfStmt", 6, tN("if"), tN("("), $3, tN(")"), $5, $6); }
;

PossibleElse:   ELSE Stmt   { $$ = createTreeNode(yylineno, "Else", 2, tN("else"), $2); }
              | /* empty */ { $$ = eN(); }
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
              | Expr MOD Expr                               { $$ = createTreeNode(yylineno, "Expr", 3, $1, tN("mod"), $3); }
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
              | FixLValue Expr RGHBRCKT     { $$ = createTreeNode(yylineno, "LValue", 4, $1->root->node, $1->root->next->node, $2, tN("]")); }
;

FixLValue:      ID LFTBRCKT { $$ = createTreeNode(yylineno, "FixLValue", 2, tT(yylval.str, "ID"), tN("[")); }
;

Call:           ID LFTPARTH Actuals RGHPARTH            { $$ = createTreeNode(yylineno, "Call", 4, tT(yylval.str, "ID"), tN("("), $3, tN(")")); }
              | Expr FixCall Actuals RGHPARTH  { $$ = createTreeNode(yylineno, "Call", 6, $1, $2->root->node, $2->root->next->node, $2->root->next->next->node, $3, tN(")")); }
;

FixCall:        POINT ID LFTPARTH { $$ = createTreeNode(yylineno, "FixCall", 3, tN("."), tT(yylval.str, "ID"), tN("(")); }
;

Actuals:        ListExpr    { $$ = createTreeNode(yylineno, "Actuals", 1, $1); }
              | /* empty */ { $$ = createTreeNode(yylineno, "Actuals", 0); }
;

Constant:       INTVAL    { $$ = createTreeNode(yylineno, "Constant", 1, tT(yylval.str, "integer")); }
              | DOUBLEVAL { $$ = createTreeNode(yylineno, "Constant", 1, tT(yylval.str, "double")); }
              | TRUE      { $$ = createTreeNode(yylineno, "Constant", 1, tT("true", "boolean")); }
              | FALSE     { $$ = createTreeNode(yylineno, "Constant", 1, tT("false", "boolean")); }
              | STRINGVAL { $$ = createTreeNode(yylineno, "Constant", 1, tT(yylval.str, "string")); }
              | NULLN   { $$ = createTreeNode(yylineno, "Constant", 1, tT("null", "null")); }
;

%%

int main() {
  //Variables
  globalScope = 0;
  classList = 0;
  scopeList = 0;
  symbolList = 0;
  symbolClass = 0;
  symbolGlobal = 0;
  symbolExtends = 0;
  scopeExtends = 0;
  functionsGlobal = 0;
  tree = 0;
  //Parser
  yyin = stdin;
  do {
    yyparse();
	} while(!feof(yyin));
  adjustFScope();
  struct Scope * scope = getScopeClass("Clase2");
  printf("%i\n", checkAtributtes(scope));
  //probarMetodo(tree, 0);
	return 0;
}

void yyerror(char *s) {
  fprintf(stderr,"Error | Line: %d\n%s\n",yylineno,s);
}

struct SymbolNode * createSymbol(struct TreeNode * variable) {
  struct ListNode * root = variable->root;
  char * id = root->next->node->value;
  return createSymbolAux(root->node, id, 0);
}

struct SymbolNode * createSymbolAux(struct TreeNode * type, char * id, int dimension) {
  struct ListNode * root = type->root;
  int size = listSize(root);
  if(size > 1) {
    return createSymbolAux(root->node, id, dimension + 1);
  }
  else {
    struct SymbolNode * node = createSymbolNode(root->node->value, id);
    node = setArray(node, dimension);
    return node;
  }
}

//Validation Functions

void adjustFScope() {
  struct ScopeNode * list = scopeExtends;
  int size = sizeScopeList(list);
  for(int i = 0; i < size; i++) {
    struct Scope * scope = list->value;
    struct SymbolNode * root = scope->root;
    int length = sizeSymbol(root);
    for(int j = 0; j < length; j++) {
      if(strcmp("extend", root->type) == 0) {
        if(checkClass(scope->id) && checkClass(root->id)) {
          struct Scope * fScope = getScopeClass(root->id);
          struct Scope * pScope = getScopeClass(scope->id);
          pScope->fScope = fScope;
        }
      }
      root = root->next;
    }
    list = list->next;
  }
}

struct Scope * getScope(struct TreeNode * node) {
  return getScopeAux(node, globalScope);
};

struct Scope * getScopeAux(struct TreeNode * node, struct Scope * scope) {
  struct TreeNode * treeScope = scope->tree;
  if(treeScope == node) {
    return scope;
  }
  else {
    struct ScopeNode * scopes = scope->pScope;
    int size = sizeScopeList(scopes);
    for(int i = 0; i < size; i++) {
      struct Scope * value = scopes->value;
      struct Scope * res = getScopeAux(node, value);
      if(res) {
        return res;
      }
      scopes = scopes->next;
    }
    return 0;
  }
};

struct Scope * checkClass(char * id) {
  int size = sizeScopeList(scopeExtends);
  struct ScopeNode * temp = scopeExtends;
  for(int i = 0; i < size; i++) {
    struct Scope * scope = temp->value;
    if(strcmp(id, scope->id) == 0) {
      return scope;
    }
    temp = temp->next;
  }
  return 0;
};

struct Scope * getScopeInterface(char * id) {
  struct ScopeNode * list = globalScope->pScope;
  int size = sizeScopeList(list);
  for(int i = 0; i < size; i++) {
    struct Scope * scope = list->value;
    if(strcmp(id, scope->id) == 0 && (strcmp(scope->type, "Interface") == 0 || strcmp(scope->type, "Interface") == 0) ) {
      return scope;
    }
    list = list->next;
  }
  return 0;
};

struct Scope * getScopeClass(char * id) {
  struct ScopeNode * list = globalScope->pScope;
  int size = sizeScopeList(list);
  for(int i = 0; i < size; i++) {
    struct Scope * scope = list->value;
    if(strcmp(id, scope->id) == 0 && (strcmp(scope->type, "Class") == 0 || strcmp(scope->type, "Interface") == 0) ) {
      return scope;
    }
    list = list->next;
  }
  return 0;
};

int checkSubClass(char * class, char * subClass) {
  struct Scope * scopeClass = checkClass(subClass);
  if(checkClass(class) && scopeClass) {
    struct SymbolNode * temp = scopeClass->root;
    int size = sizeSymbol(temp);
    for(int i = 0; i < size; i++) {
      if(strcmp(class, temp->id) == 0) {
        return 1;
      }
      if(strcmp("Class", temp->type) == 0) {
        int check = checkSubClass(temp->id, subClass);
        if(check) {
          return 1;
        }
      }
      temp = temp->next;
    }
  }
  return 0;
};

struct SymbolNode * getTypeId(char * id, struct Scope * scope) {
  struct SymbolNode * root = scope->root;
  int size = sizeSymbol(root);
  for(int i = 0; i < size; i++) {
    if(strcmp(root->id, id) == 0) {
      return root;
    }
    root = root->next;
  }
  if(strcmp("global", scope->id) == 0) {
    return 0;
  }
  else {
    return getTypeId(id, scope->fScope);
  }
};

struct SymbolNode * getTypeFunction(char * id, struct Scope * scope) {
  struct ScopeNode * list = scope->pScope;
  int size = sizeScopeList(list);
  for(int i = 0; i < size; i++) {
    struct Scope * value = list->value;
    if(strcmp(id, value->id) == 0 && strcmp("Function", value->type) == 0) {
      struct TreeNode * node = value->tree;
      struct TreeNode * functionName = node->root->node;
      char * name = functionName->root->next->node->value;
      if(strcmp("Terminal", functionName->root->node->type) == 0) {
        if(strcmp("void", functionName->root->node->value) == 0) {
          //Tipo void
          return 0;
        }
        else {
          struct SymbolNode * res = createSymbolNode(functionName->root->node->value, name);
          return res;
        }    
      }
      else {
        struct SymbolNode * res = createSymbolAux(functionName->root->node, name, 0);
        return res;
      }
    }
    list = list->next;
  }
  if(strcmp("global", scope->id) == 0) {
    //Funcion no existe
    return 0;
  }
  else {
    return getTypeFunction(id, scope->fScope);
  }
};

char * getTypeConstant(struct TreeNode * node) {
  struct TreeNode * terminal = node->root->node;
  return terminal->type;
};

char * getValueConstant(struct TreeNode * node) {
  struct TreeNode * terminal = node->root->node;
  return terminal->value;
};

struct SymbolNode * getTypeReturn(struct TreeNode * node, struct Scope * actualScope) {
  struct ListNode * list = node->root;
  int size = listSize(list);
  if(size == 2) {
    return 0;
  }
  else {
    struct TreeNode * possibleExpr = list->next->node;
    struct TreeNode * expr = possibleExpr->root->node;
    return getTypeExpr(expr, actualScope);
  } 
};

struct SymbolNode * getTypeExpr(struct TreeNode * node, struct Scope * actualScope) {
  struct ListNode * list = node->root;
  int size = listSize(list);
  if(size == 1) {
    struct TreeNode * value = list->node;
    if(strcmp("Terminal", value->type) == 0) {
      if(actualScope->fScope) {
        struct SymbolNode * res = createSymbolNode(actualScope->fScope->id, actualScope->fScope->id);
        return res;
      }
      else {
        //This fuera de scope;
        return 0;
      }
    }
    else if(strcmp("Constant", value->type) == 0) {
      char * type = getTypeConstant(value);
      char * val = getValueConstant(value);
      struct SymbolNode * res = createSymbolNode(type, val);
      return res;
    }
    else if(strcmp("LValue", value->type) == 0) {
      return getTypeLValue(value, actualScope);
    }
    else {
      return getTypeCall(value, actualScope);
    }
  }
  else if(size == 2) {
    struct SymbolNode * typeReturn = getTypeExpr(list->next->node, actualScope);
    if(typeReturn) {
      if(strcmp("!", list->node->value) == 0) {
        if(strcmp(typeReturn->type, "boolean") == 0) {
          return typeReturn;
        }
        else {
          //Tipo invalido, debe ser boolean
          return 0;
        }
      }
      else {
        if(strcmp(typeReturn->type, "integer") == 0 || strcmp(typeReturn->type, "double") == 0) {
          return typeReturn;
        }
        else {
          //Tipo invalido, debe ser int o double;
          return 0;
        }
      }
    }
    else {
      //Error en la expresion
      return 0;
    } 
  }
  else if(size == 3) {
    struct TreeNode * terminal = list->next->node;
    if(strcmp("+", terminal->value) == 0 || strcmp("-", terminal->value) == 0 || strcmp("*", terminal->value) == 0 || strcmp("/", terminal->value) == 0 || strcmp("mod", terminal->value) == 0) {
      struct SymbolNode * typeExpr1 = getTypeExpr(list->node, actualScope);
      struct SymbolNode * typeExpr2 = getTypeExpr(list->next->next->node, actualScope);
      if(typeExpr1 && typeExpr2) {
        if(strcmp("integer", typeExpr1->type) == 0 || strcmp("double", typeExpr1->type) == 0) {
          if(strcmp("integer", typeExpr2->type) == 0 || strcmp("double", typeExpr2->type) == 0) {
            return typeExpr1;
          }
          else {
            //Segundo tipo invalido en operacion aritmetica
            return 0;
          }
        }
        else {
          //Primer tipo invalido en operacion arimetica
          return 0;
        }
      }
      else {
        //La expresion arimetica no es valida
        return 0;
      }
    }
    else if(strcmp("<", terminal->value) == 0 || strcmp("<=", terminal->value) == 0 || strcmp(">", terminal->value) == 0 || strcmp(">=", terminal->value) == 0) {
      struct SymbolNode * typeExpr1 = getTypeExpr(list->node, actualScope);
      struct SymbolNode * typeExpr2 = getTypeExpr(list->next->next->node, actualScope);
      if(typeExpr2 && typeExpr1) {
        if(strcmp("integer", typeExpr1->type) == 0 || strcmp("double", typeExpr1->type) == 0) {
          if(strcmp("integer", typeExpr2->type) == 0 || strcmp("double", typeExpr2->type) == 0) {
            struct SymbolNode * res = createSymbolNode("boolean", "boolean");
            return res;
          }
          else {
            //Segundo tipo invalido en comparacion de tamano
            return 0;
          }
        }
        else {
          //Primer tipo invalido en comparacion de tamano
          return 0;
        }
      }
      else {
        //Las expresiones no pueden ser void
        return 0;
      }
    }
    else if(strcmp("==", terminal->value) == 0 || strcmp("!=", terminal->value) == 0) {
      struct SymbolNode * typeExpr1 = getTypeExpr(list->node, actualScope);
      struct SymbolNode * typeExpr2 = getTypeExpr(list->next->next->node, actualScope);
      if(typeExpr2 && typeExpr1) {
        if(strcmp(typeExpr2->type, typeExpr1->type) == 0) {
          struct SymbolNode * res = createSymbolNode("boolean", "boolean");
          return res;
        }
        else {
          //Solo se pueden comparar expresiones del mismo tipo
          return 0;
        }
      }
      else {
        //Las comparaciones no se pueden hacer con tipo void
        return 0;
      }
    }
    else if(strcmp("||", terminal->value) == 0 || strcmp("&&", terminal->value) == 0) {
      struct SymbolNode * typeExpr1 = getTypeExpr(list->node, actualScope);
      struct SymbolNode * typeExpr2 = getTypeExpr(list->next->next->node, actualScope);
      if(typeExpr2 && typeExpr1) {
        if(strcmp(typeExpr2->type, typeExpr1->type) == 0) {
          if(strcmp("boolean", typeExpr2->type) == 0) {
            struct SymbolNode * res = createSymbolNode("boolean", "boolean");
            return res;
          }
          else {
            //Expresion debe ser bool
            return 0;
          }
        }
        else {
          //Ambas expresiones deben ser tipo bool
          return 0;
        }
      }
      else {
        //Operaciones booleanas no se pueden hacer con tipo void
        return 0;
      }   
    }
    else if(strcmp("(", list->node->value) == 0 ) {
      return getTypeExpr(list->next->node, actualScope);
    }
    else {
      struct SymbolNode * typeLValue = getTypeLValue(list->node, actualScope);
      struct SymbolNode * typeExpr = getTypeExpr(list->next->next->node, actualScope);
      if(typeLValue && typeExpr) {
        if(strcmp("integer", typeLValue->type) == 0 || strcmp("boolean", typeLValue->type) == 0 || strcmp("double", typeLValue->type) == 0 || strcmp("string", typeLValue->type) == 0 || checkClass(typeLValue->type)) {
          if(strcmp(typeExpr->type, "null") == 0 || strcmp(typeExpr->type, typeLValue->type) == 0 || checkSubClass(typeExpr->type, typeLValue->type)) {
            //Asignacion siempre retorna void aunque sea correcta
            return 0;
          }
          else {
            //La asignacion debe ser del mismo tipo o de una clase padre
            return 0;
          }
        }
        else {
          //La variable debe ser de una clase existente o un tipo primitivo
          return 0;
        }
      }
      else {
        //Las expresiones no pueden ser tipo void en igualdad
        return 0;
      }
    }
  }
  else {
    if(strcmp("readInteger", list->node->value) == 0 || strcmp("readLine", list->node->value) == 0) {
      //Ambas funciones retornan void
      return 0;
    }
    else if(strcmp("new", list->node->value) == 0) {
      struct Scope * checkScope = checkClass(list->next->next->node->value);
      if(checkScope) {
        struct SymbolNode * res = createSymbolNode(checkScope->id, checkScope->id);
        return res;
      }
      else {
        //Clase o interfaz no existe
        return 0;
      }
    }
    else {
      struct TreeNode * expr = list->next->next->node;
      struct SymbolNode * typeExpr = getTypeExpr(expr, actualScope);
      if(typeExpr) {
        if(strcmp("integer", typeExpr->type) == 0) {
          struct TreeNode * type = list->next->next->next->next->node;
          struct SymbolNode * symbol = createSymbolAux(type, "TypeArray", 0);
          return symbol;
        }
        else {
          //El largo debe ser un tipo entero
          return 0;
        } 
      }
      else {
        //Expresion no puede ser void o funcion no existe
        return 0;
      }
    }
  }
};

struct SymbolNode * getTypeLValue(struct TreeNode * node, struct Scope * actualScope) {
  struct ListNode * list = node->root;
  int size = listSize(list);
  if(size == 1) { 
    struct SymbolNode * symbol = getTypeId(list->node->value, actualScope);
    if(symbol) {
      return symbol;
    }
    else {
      //No existe el id
      return 0;
    }
  }
  else if(size == 3) {
    struct TreeNode * expr = list->node;
    struct SymbolNode * typeReturn = getTypeExpr(expr, actualScope);
    struct Scope * objectScope = getScopeClass(typeReturn->type);
    if(objectScope) {
      char * id = list->next->next->node->value;
      struct SymbolNode * symbol = getTypeId(id, objectScope);
      if(symbol) {
        return symbol;
      }
      else {
        //No existe el atributo
        return 0;
      }
    }
    else {
      //No existe el objeto
      return 0;
    }
  }
  else {
    char * nodeId = list->node->value;
    struct SymbolNode * typeId = getTypeId(nodeId, actualScope);
    struct SymbolNode * verifyReturn = getTypeExpr(list->next->next->node, actualScope);
    if(verifyReturn) {
      if(strcmp(verifyReturn->type, "integer") == 0) {
        if(typeId) {
          return typeId;
        }
        else {
          //Variable no existe
          return 0;
        }
      }
      else {
        //Indice debe ser un integer
        return 0;
      }
    }
    else {
      //Expresion no puede ser void
      return 0;
    }  
  }
};

struct SymbolNode * getTypeCall(struct TreeNode * node, struct Scope * actualScope) {
  struct ListNode * list = node->root;
  int size = listSize(list);
  if(size == 4) {
    char * id = list->node->value;
    struct SymbolNode * res = getTypeFunction(id, actualScope);
    struct SymbolNode * params = getTypeActuals(list->next->next->node,actualScope);
    struct Scope * functionScope = getFunctionScope(actualScope->fScope, actualScope->id, 1);
    if(functionScope) {
      struct SymbolNode * funct = getParams(functionScope);
      if(compareSymbolNodes(params, funct)) {
        return res;
      }
      else {
        //Error en los parametros
        return 0;
      }
    }
    else {
      return 0;
    }
  }
  else {
    struct TreeNode * expr = list->node;
    struct SymbolNode * typeReturn = getTypeExpr(expr, actualScope);
    struct SymbolNode * actuals = getTypeActuals(list->next->next->next->next->node, actualScope);
    if(typeReturn) {
      struct Scope * functionScope = getScopeClass(typeReturn->type);
      if(functionScope) {
        char * id = list->next->next->node->value;
        struct Scope * checkFunction = getFunctionScope(functionScope, id, 0);
        if(checkFunction) {
          struct SymbolNode * params = getParams(checkFunction);
          if(compareSymbolNodes(actuals, params)) {
            struct SymbolNode * symbol = getTypeFunction(id, functionScope);
            return symbol; //Puede no existir o ser void
          }
          else {
            //Parametros no coinciden
            return 0;
          }
        }
        else {
          //Funcion no existe
          return 0;
        }
      }
      else {
        //Clase no existe
        return 0;
      }
    }
    else {
      //Tipo void no puede invocar una funcion
      return 0;
    }
  }
};

void probarMetodo(struct TreeNode * node, struct Scope * actualScope) {
  struct Scope * newScope = getScope(node);
  if(newScope) {
    actualScope = newScope;
  }
  if(strcmp(node->type, "Expr") == 0) {
    struct SymbolNode * res = getTypeExpr(node, actualScope);
    if(res) {
      //printf("%s\n", res->type);
    }
    else {
      printf("%s\n", "Error o void");
    }
  }
  if(strcmp(node->type, "ReturnStmt") == 0) {
    //printf("%i\n", checkFunctionReturn(node, actualScope));
  }
  if(strcmp(node->type, "Actuals") == 0) {
    struct SymbolNode * list = getTypeActuals(node, actualScope);
    int size = sizeSymbol(list);
    for(int i = 0; i < size; i++) {
      //printf("%s\n", list->id);
      list = list->next;
    }
  }
  struct ListNode * temp = node->root;
  int size = listSize(temp);
  for(int i = 0; i < size; i++) {
    struct TreeNode * value = temp->node;
    probarMetodo(value, actualScope);
    temp = temp->next;
  }
};

int checkSymbolScope(struct Scope * scope) {
  struct SymbolNode * root = scope->root;
  int size = sizeSymbol(root);
  for(int i = 0; i < size; i++) {
    char * id = root->id;
    if(i < size - 2) {
      struct SymbolNode * temp = root->next;
      for(int j = i + 1; j < size; i++) {
        if(strcmp(id, temp->id) == 0) {
          return 0;
        }
        temp = temp->next;
      }
      root = root->next;
    }
  }
  return 1;
};

int checkFunctionReturn(struct TreeNode * returnNode, struct Scope * function) {
  struct SymbolNode * symbol = getTypeFunction(function->id, function->fScope);
  struct SymbolNode * typeReturn = getTypeReturn(returnNode, function);
  if(symbol && typeReturn) {
    if(strcmp(typeReturn->type, symbol->type) == 0 && typeReturn->array == symbol->array) {
      return 1;
    }
  }
  else if(symbol || typeReturn) {
    return 0;
  }
  else {
    return 1;
  }
};

struct SymbolNode * getParams(struct Scope * function) {
  struct SymbolNode * params = 0;
  struct SymbolNode * temp = function->root;
  int size = sizeSymbol(function->root);
  for(int i = 0; i < size; i++) {
    if(temp->parameter) {
      struct SymbolNode * newNode = createSymbolNode(temp->type, temp->id);
      newNode->array = temp->array;
      newNode->parameter = temp->parameter;
      params = insertSymbolNode(params, newNode);
    }
    temp = temp->next;
  }
  return params;
};

struct SymbolNode * getTypeActuals(struct TreeNode * actuals, struct Scope * scope) {
  int size = listSize(actuals->root);
  if(size) {
    return getTypeActualsAux(actuals->root->node, scope);
  }
  else {
    return 0;
  }
};

struct SymbolNode * getTypeActualsAux(struct TreeNode * list, struct Scope * scope) {
  struct ListNode * root = list->root;
  int size = listSize(root);
  if(size == 1) {
    struct SymbolNode * res = getTypeExpr(root->node, scope);
    return dupSymbol(res);
  }
  else {
    struct SymbolNode * newNode = getTypeExpr(root->next->next->node, scope);
    return insertSymbolNode(getTypeActualsAux(root->node, scope), dupSymbol(newNode));
  }
};

struct SymbolNode * dupSymbol(struct SymbolNode * symbol) {
  struct SymbolNode * newNode = createSymbolNode(symbol->type, symbol->id);
  newNode->array = symbol->array;
  newNode->parameter = symbol->parameter;
  newNode->next = 0;
  return newNode;
}

int compareSymbolNodes(struct SymbolNode * params,struct SymbolNode * funct) {
  if(params && funct) {
    int sizeParam = sizeSymbol(params);
    int sizeFun = sizeSymbol(funct);
    if(sizeParam == sizeFun) {
      struct SymbolNode * temp = funct;
      for(int i = 0; i < sizeFun; i++) {
        if(strcmp(temp->type,params->type) == 0) {
          temp = temp->next;
          params = params->next;
        }
        else {
          //Parametros de diferente tipo
          return 0;
        }
      }
      return 1;
    } 
    else {
      //Diferente cantidad de parametros
      return 0;
    }

  }
  else if(params || funct) {
    //Diferente cantidad de parametros
    return 0;
  }
  else {
    return 1;
  }
};

struct Scope * getFunctionScope(struct Scope * classScope, char * id, int global) {
  if(!classScope) {
    return 0;
  }
  struct ScopeNode * list = classScope->pScope;
  int size = sizeScopeList(list);
  for(int i = 0; i < size; i++) {
    struct Scope * scope = list->value;
    if(strcmp(id, scope->id) == 0) {
      return scope;
    }  
    list = list->next;
  }
  struct Scope * fScope = classScope->fScope;
  if(fScope) {
    if(strcmp("global", fScope->id) == 0 && global == 0) {
      return 0;
    }
    else {
      return getFunctionScope(fScope, id, global);
    }
  }
  return 0;
};

int implementMethods(struct Scope * class) {
  return implementMethodsAux(class, class);
};

int implementMethodsAux(struct Scope * class, struct Scope * fScope) {
  if(strcmp("global", fScope->id) == 0) {
    return 1;
  }
  else {
    struct Scope * implements = checkClass(fScope->id);
    if(methodsInInterface(implements, class)) {
      return implementMethodsAux(class, fScope->fScope);
    }
    else {
      return 0;
    }
  } 
};

int methodsInInterface(struct Scope * implements, struct Scope * class) {
  struct SymbolNode * list = implements->root;
  int size = sizeSymbol(list);
  for(int i = 0; i < size; i++) {
    if(strcmp("implement", list->type) == 0) {
      struct Scope * interface = getScopeInterface(list->id);
      if(!scopesInList(class->pScope, interface->pScope)) {
        return 0;
      }
    }
    list = list->next;
  }
  return 1;
};

int scopesInList(struct ScopeNode * list, struct ScopeNode * scope) {
  int size = sizeScopeList(scope);
  struct ScopeNode * temp = scope;
  for(int i = 0; i < size; i++) {
    if(!scopeInList(temp->value, list)) {
      return 0;
    }
    temp = temp->next;
  }
  return 1;
}

int scopeInList(struct Scope * scope, struct ScopeNode * list) {
  int size = sizeScopeList(list);
  struct ScopeNode * temp = list;
  for(int i = 0; i < size; i++) {
    if(strcmp(scope->id, temp->value->id) == 0) {
      return 1;
    }
    temp = temp->next;
  }
  //El metodo de la interfaz no se encuentra en la clase
  return 0;
}

int checkMethods(struct Scope * class) {
  struct ScopeNode * functions = class->pScope;
  int size = sizeScopeList(functions);
  for(int i = 0; i < size; i++) {
    struct Scope * function = functions->value;
    struct Scope * interface = methodInterface(class, function->id);
    if(interface) {
      if(!checkImplementation(function, interface)) {
        return 0;
      }
    }
    functions = functions->next;
  }
  return 1;
};

int checkAtributtes(struct Scope * class) {
  struct Scope * fScope = class->fScope;
  struct SymbolNode * list = class->root;
  int size = sizeSymbol(list);
  while(fScope || strcmp("global", fScope->id) != 0) {
    struct SymbolNode * listFScope = fScope->root;
    int sizeFScope = sizeSymbol(listFScope);
    for(int i = 0; i < size; i++) {
      char * id = list->id;
      for(int j = 0; j < sizeFScope; i++) {
        char * idFScope = listFScope->id;
        if(strcmp(idFScope, id) == 0) {
          return 0;
        }
        listFScope = listFScope->next;
      }
      list = list->next;
    }
    fScope = fScope->fScope;
  }
  return 1;
};

struct Scope * methodInterface(struct Scope * class, char * id) {
  struct ScopeNode * list = scopeExtends;
  int size = sizeScopeList(list);
  for(int i = 0; i < size; i++) {
    struct Scope * scope = list->value;
    if(strcmp(class->id, scope->id) == 0) {
      struct SymbolNode * extends = scope->root;
      int sizeExtends = sizeSymbol(extends);
      for(int j = 0; j < sizeExtends; j++) {
        if(strcmp("implement", extends->type) == 0) {
          struct Scope * interface = getScopeInterface(extends->id);
          
          if(interface) {
            struct ScopeNode * functionsInterface = interface->pScope;
            int sizeFunctions = sizeScopeList(functionsInterface);
            for(int k = 0; k < sizeFunctions; k++) {
              struct Scope * function = functionsInterface->value;
              if(strcmp(id, function->id) == 0) {
                return interface;
              }
              functionsInterface = functionsInterface->next;
            }
          }
          else {
            return 0;
          }
        }
        extends = extends->next;
      };
    }
    list = list->next;
  }
  class = class->fScope;
  if(class) {
    if(strcmp("global", class->id) != 0) {
      return methodInterface(class, id);
    }
  }
  return 0;
};

int checkImplementation(struct Scope * method1, struct Scope * method2) {
  struct Scope * functionInterface = getFunctionScope(method2, method1->id, 0);
  struct SymbolNode * params1 = getParams(method1);
  struct SymbolNode * params2 = getParams(functionInterface);
  if(compareSymbolNodes(params1, params2)) {
    return compareReturnFunctions(functionInterface, method1);
  }
  else {
    //Parametros no coinciden con la interfaz
    return 0;
  }
};

int compareReturnFunctions(struct Scope * scope1, struct Scope * scope2) {
  struct SymbolNode * return2 = getTypeFunction(scope2->id, scope2->fScope);
  struct SymbolNode * return1 = getTypeFunction(scope1->id, scope1->fScope);
  if(return1 && return2) {
    if(strcmp(return1->type, return2->type) == 0) {
      return 1;
    }
    else {
      //Tipos diferentes
      return 0;
    }
  }
  else if(return1 || return2) {
    //Una de las funciones es void
    return 0;
  }
  else {
    //Ambas son void
    return 1;
  }
}
