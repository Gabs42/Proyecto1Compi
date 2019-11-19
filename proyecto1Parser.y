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

struct Scope * checkClass(char * id);

struct Scope * getScopeClass(char * id);

int checkSubClass(char * class, char * subClass);

int checkSymbolScope(struct Scope * scope);

int checkFunctionReturn(struct TreeNode * returnNode, struct Scope * function);

struct SymbolNode * getTypeId(char * id, struct Scope * scope);

struct SymbolNode * getTypeFunction(char * id, struct Scope * scope);

char * getTypeConstant(struct TreeNode * node);
char * getValueConstant(struct TreeNode * node);

char * getTypeReturn(struct TreeNode * node, struct Scope * actualScope);

char * getTypeExpr(struct TreeNode * node, struct Scope * actualScope);

char * getTypeLValue(struct TreeNode * node, struct Scope * actualScope);

char * getTypeCall(struct TreeNode * node, struct Scope * actualScope);

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
%type<treeNode> FunctionDecl Formals Variables ClassDecl Extend Implement
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
              | Variables COMMA Variable  { $$ = createTreeNode(yylineno, "Variables", 3, $1, tN(","), $3); }
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

Implement:      IMPLEMENTS ListIdents { $$ = createTreeNode(yylineno, "Implement", 2, tN("implements"), $2);
                                        struct SymbolNode * newSymbol = createSymbolNode("implement", yylval.str);
                                        symbolExtends = insertSymbolNode(symbolExtends, newSymbol);
                                      }
              | /* empty */           { $$ = eN(); }
;

ListIdents:     ID                  { $$ = createTreeNode(yylineno, "ListIdents", 1, tT(yylval.str, "ID")); }
              | ListIdents COMMA ID { $$ = createTreeNode(yylineno, "ListIdents", 3, $1, tN(","), tT(yylval.str, "ID")); }
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
                                                                  struct ScopeNode * newNode = createScopeNode(newScope);
                                                                  scopeList = insertScopeNode(scopeList, newNode);
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
  probarMetodo(tree, 0);
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
        struct SymbolNode * res = createSymbolNode(functionName->root->node->value, name);
        return res;
      }
      else {
        struct SymbolNode * res = createSymbolAux(functionName->root->node, name, 0);
        return res;
      }
    }
    list = list->next;
  }
  if(strcmp("global", scope->id) == 0) {
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

char * getTypeReturn(struct TreeNode * node, struct Scope * actualScope) {
  struct ListNode * list = node->root;
  int size = listSize(list);
  if(size == 2) {
    return "void";
  }
  else {
    struct TreeNode * possibleExpr = list->next->node;
    struct TreeNode * expr = possibleExpr->root->node;
    return getTypeExpr(expr, actualScope);
  } 
};

char * getTypeExpr(struct TreeNode * node, struct Scope * actualScope) {
  struct ListNode * list = node->root;
  int size = listSize(list);
  if(size == 1) {
    struct TreeNode * value = list->node;
    if(strcmp("Terminal", value->type) == 0) {
      if(actualScope->fScope) {
        return actualScope->fScope->id;
      }
      else {
        return "This fuera de scope";
      }
    }
    else if(strcmp("Constant", value->type) == 0) {
      return getTypeConstant(value);
    }
    else if(strcmp("LValue", value->type) == 0) {
      return getTypeLValue(value, actualScope);
    }
    else {
      return getTypeCall(value, actualScope);
    }
  }
  else if(size == 2) {
    char * typeReturn = getTypeExpr(list->next->node, actualScope);
    if(strcmp("!", list->node->value) == 0) {
      if(strcmp(typeReturn, "boolean") == 0) {
        return "boolean";
      }
      else {
        return "Tipo invalido, debe ser boolean";
      }
    }
    else {
      if(strcmp(typeReturn, "integer") == 0) {
        return "integer";
      }
      else if(strcmp(typeReturn, "double") == 0) {
        return "double";
      }
      else {
        return "Tipo invalido, debe ser int o double";
      }
    }
  }
  else if(size == 3) {
    struct TreeNode * terminal = list->next->node;
    if(strcmp("+", terminal->value) == 0 || strcmp("-", terminal->value) == 0 || strcmp("*", terminal->value) == 0 || strcmp("/", terminal->value) == 0 || strcmp("mod", terminal->value) == 0) {
      char * typeExpr1 = getTypeExpr(list->node, actualScope);
      char * typeExpr2 = getTypeExpr(list->next->next->node, actualScope);
      if(strcmp("integer", typeExpr1) == 0 || strcmp("double", typeExpr1) == 0) {
        if(strcmp("integer", typeExpr2) == 0 || strcmp("double", typeExpr2) == 0) {
          return typeExpr1;
        }
        else {
          return "Segundo tipo invalido en operacion";
        }
      }
      else {
        return "Primer tipo invalido en operacion";
      }
    }
    else if(strcmp("<", terminal->value) == 0 || strcmp("<=", terminal->value) == 0 || strcmp(">", terminal->value) == 0 || strcmp(">=", terminal->value) == 0) {
      char * typeExpr1 = getTypeExpr(list->node, actualScope);
      char * typeExpr2 = getTypeExpr(list->next->next->node, actualScope);
      if(strcmp("integer", typeExpr1) == 0 || strcmp("double", typeExpr1) == 0) {
        if(strcmp("integer", typeExpr2) == 0 || strcmp("double", typeExpr2) == 0) {
          return "boolean";
        }
        else {
          return "Segundo tipo invalido en comparacion de tamano";
        }
      }
      else {
        return "Primer tipo invalido en comparacion de tamano";
      }
    }
    else if(strcmp("==", terminal->value) == 0 || strcmp("!=", terminal->value) == 0) {
      char * typeExpr1 = getTypeExpr(list->node, actualScope);
      char * typeExpr2 = getTypeExpr(list->next->next->node, actualScope);
      if(strcmp(typeExpr2, typeExpr1) == 0) {
        if(strcmp("void", typeExpr2) != 0) {
          return "boolean";
        }
        else {
          return "Segundo tipo invalido en comparacion de tipo";
        }
      }
      else {
        return "Primer tipo invalido en comparacion de tipo";
      }
    }
    else if(strcmp("||", terminal->value) == 0 || strcmp("&&", terminal->value) == 0) {
      char * typeExpr1 = getTypeExpr(list->node, actualScope);
      char * typeExpr2 = getTypeExpr(list->next->next->node, actualScope);
      if(strcmp(typeExpr2, typeExpr1) == 0) {
        if(strcmp("boolean", typeExpr2) == 0) {
          return "boolean";
        }
        else {
          return "Las expresiones deben ser booleanas";
        }
      }
      else {
        return "Las expresiones deben ser del mismo tipo";
      }
    }
    else if(strcmp("(", list->node->value) == 0 ) {
      return getTypeExpr(list->next->node, actualScope);
    }
    else {
      char * typeLValue = getTypeLValue(list->node, actualScope);
      char * typeExpr = getTypeExpr(list->next->next->node, actualScope);
      if(strcmp("integer", typeLValue) == 0 || strcmp("boolean", typeLValue) == 0 || strcmp("double", typeLValue) == 0 || strcmp("string", typeLValue) == 0 || checkClass(typeLValue)) {
        if(strcmp(typeExpr, "null") == 0 ||strcmp(typeExpr, typeLValue) == 0 || checkSubClass(typeExpr, typeLValue)) {
          return "void";
        }
        else {
          return "La asignacion debe ser del mismo tipo o de una clase padre";
        }
      }
      else {
        return "Primera parametro no puede ser void";
      }
    }
  }
  else {
    if(strcmp("readInteger", list->node->value) == 0 || strcmp("readLine", list->node->value) == 0) {
      return "void";
    }
    else if(strcmp("new", list->node->value) == 0) {
      struct Scope * checkScope = checkClass(list->next->next->node->value);
      if(checkScope) {
        return checkScope->id;
      }
      else {
        return "Clase o interfaz no existe";
      }
    }
    else {
      struct TreeNode * expr = list->next->next->node;
      char * typeExpr = getTypeExpr(expr, actualScope);
      if(strcmp("integer", typeExpr) == 0) {
        struct TreeNode * type = list->next->next->next->next->node;
        struct SymbolNode * symbol = createSymbolAux(type, "test", 0);
        return symbol->type;
      }
      else {
        return "El largo debe ser un tipo entero";
      }
    }
  }
};

char * getTypeLValue(struct TreeNode * node, struct Scope * actualScope) {
  struct ListNode * list = node->root;
  int size = listSize(list);
  if(size == 1) { 
    struct SymbolNode * symbol = getTypeId(list->node->value, actualScope);
    if(symbol) {
      return symbol->type;
    }
    else {
      return "Objeto no existe";
    }
  }
  else if(size == 3) {
    struct TreeNode * expr = list->node;
    char * typeReturn = getTypeExpr(expr, actualScope);
    struct Scope * objectScope = getScopeClass(typeReturn);
    if(objectScope) {
      char * id = list->next->next->node->value;
      struct SymbolNode * symbol = getTypeId(id, objectScope);
      if(symbol) {
        return symbol->type;
      }
      else {
        return "Atributo no existe";
      }
    }
    else {
      return "Objeto no existe";
    }
  }
  else {
    char * nodeId = list->node->value;
    struct SymbolNode * typeId = getTypeId(nodeId, actualScope);
    char * verifyReturn = getTypeExpr(list->next->next->node, actualScope);
    if(strcmp(verifyReturn, "integer") == 0) {
      if(typeId) {
        return typeId->type;
      }
      else {
        return "Variable no existe";
      }
    }
    else {
      return "Indice no valido";
    }
  }
};

char * getTypeCall(struct TreeNode * node, struct Scope * actualScope) {
  struct ListNode * list = node->root;
  int size = listSize(list);
  if(size == 4) {
    char * id = list->node->value;
    struct SymbolNode * res = getTypeFunction(id, actualScope);
    if(res) {
      return res->type;
    }
    else {
      return "Metodo no existe";
    }
  }
  else {
    struct TreeNode * expr = list->node;
    char * typeReturn = getTypeExpr(expr, actualScope);
    struct Scope * functionScope = getScopeClass(typeReturn);
    if(functionScope) {
      char * id = list->next->next->node->value;
      struct SymbolNode * symbol = getTypeFunction(id, functionScope);
      if(symbol) {
        return symbol->type;
      }
      else {
        return "Metodo de objeto no existe";
      }
    }
    else {
      return "Objeto no existe";
    }
  }
};

void probarMetodo(struct TreeNode * node, struct Scope * actualScope) {
  struct Scope * newScope = getScope(node);
  if(newScope) {
    actualScope = newScope;
  }
  if(strcmp(node->type, "Expr") == 0) {
    //printf("%s\n", getTypeExpr(node, actualScope));
  }
  if(strcmp(node->type, "ReturnStmt") == 0) {
    printf("%i\n", checkFunctionReturn(node, actualScope));
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
  char * typeReturn = getTypeReturn(returnNode, function);
  if(symbol) {
    if(strcmp(typeReturn, symbol->type) == 0) {
      return 1;
    }
  }
  return 0;
};