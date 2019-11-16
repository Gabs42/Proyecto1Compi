#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include "symbol.c"
#include "scopeList.c"

/* Structures */

struct Scope {
  char * id;
  char * type;
  struct SymbolNode * root;
  struct Scope * fScope;
  struct ScopeNode * pScope;
};

/* Functions */

struct Scope * createScope(char * id, char * type);

struct Scope * setFScope(struct Scope * fScope, struct ScopeNode * scope);
struct Scope * setPScope(struct Scope * scope, struct ScopeNode * pScope);

struct Scope * insertSymbol(struct Scope * scope, struct SymbolNode * symbol);

struct Scope * searchScope(struct Scope * root, char * id);

int sizeScope(struct Scope * root);

void printScope(struct Scope * root);

void printList(struct SymbolNode * root);

struct Scope * createScope(char * id, char * type) {
    struct Scope * newScope;
    newScope = malloc(sizeof(struct Scope));
    newScope->id = id;
    newScope->type = type;
    newScope->root = 0;
    newScope->next = 0;
    newScope->pScope = 0;
    return newScope;
};

struct Scope * setFScope(struct Scope * fScope, struct ScopeNode * scope) {
  int size = sizeScopeList(scope);
  struct ScopeNode * temp = scope;
  for(int i = 0; i < size; i++) {
    struct Scope * value = temp->value;
    value->fScope = fScope;
    temp = temp->next;
  }
  return fScope;
};

struct Scope * setPScope(struct Scope * scope, struct ScopeNode * pScope) {
  int size = sizeScopeList(Scope);
  struct ScopeNode * temp = pScope;
  struct ScopeNode * newRoot = 0;
  for(int i = 0; i < size; i++) {
    struct Scope * value = temp->value;
    struct ScopeNode * newNode = createScopeNode(value);
    newRoot = insertScopeNode(newRoot, newNode);
    temp = temp->next;
  }
  scope->pScope = newRoot;
  return scope;
}

struct Scope * insertSymbol(struct Scope * scope, struct SymbolNode * symbol) {
  int size = sizeSymbol(symbol);
  if(size > 0) {
    struct SymbolNode * root = scope->root;
    for(int i = 0; i < size; i++) {
      struct SymbolNode * newSymbol = createSymbolNode(symbol->type, symbol->id);
      root = insertSymbolNode(root, newSymbol);
      symbol = symbol->next;
    }
    scope->root = root;
  }
  return scope;
};

int sizeScope(struct Scope * root) {
  int size = 0;
  struct Scope * temp = root;
  while(temp) {
    size++;
    temp = temp->next;
  }
  return size;
};

struct Scope * searchScope(struct Scope * root, char * id) {
  int size = sizeScope(root);
  struct Scope * temp = root;
  for(int i = 0; i < size; i++) {
    char * value = temp->id;
    if(strcmp(id, value) == 0) {
      return temp;
    }
    temp = temp->next;
  }
  return 0;
};

void printScope(struct Scope * root) {
    printf("Scope");
    printf("%s", root->id);
    printList(root->root);
};

void printList(struct SymbolNode * root) {
    printf("%s", root->id);
    if(root->next) {
        printList(root->next);
    }
};
