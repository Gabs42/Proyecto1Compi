#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include "symbol.c"

/* Structures */

struct Scope {
  char * id;
  char * type;
  struct SymbolNode * root;
  struct Scope * fScope;
  struct ScopeNode * pScope;
};

struct ScopeNode {
    struct Scope * value;
    struct ScopeNode * next;
};

/* Functions */

struct Scope * createScope(char * id, char * type);

struct Scope * setFScope(struct Scope * fScope, struct ScopeNode * scope);
struct Scope * setPScope(struct Scope * scope, struct ScopeNode * pScope);

struct Scope * insertSymbol(struct Scope * scope, struct SymbolNode * symbol);

struct ScopeNode * createScopeNode(struct Scope * value);
struct ScopeNode * insertScopeNode(struct ScopeNode * root, struct ScopeNode * node);

int sizeScopeList(struct ScopeNode * root);

struct ScopeNode * createScopeNode(struct Scope * value) {
    struct ScopeNode * newNode;
    newNode = malloc(sizeof(struct ScopeNode));
    newNode->value = value;
    newNode->next = 0;
    return newNode;
};

struct ScopeNode * insertScopeNode(struct ScopeNode * root, struct ScopeNode * newNode) {
    int size = sizeScopeList(root);
    if(size == 0) {
        root = newNode;
    }
    else {
        struct ScopeNode * temp = root;
        for(int i = 0; i < size - 1; i++) {
        temp = temp->next;
        }
        temp->next = newNode;
    }
    return root;
};

int sizeScopeList(struct ScopeNode * root) {
    int size = 0;
    struct ScopeNode * temp = root;
    while(temp) {
        size++;
        temp = temp->next;
    }
    return size;
};

struct Scope * createScope(char * id, char * type) {
    struct Scope * newScope;
    newScope = malloc(sizeof(struct Scope));
    newScope->id = id;
    newScope->type = type;
    newScope->root = 0;
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
  int size = sizeScopeList(pScope);
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