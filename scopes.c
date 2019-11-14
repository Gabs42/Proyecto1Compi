#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include "symbol.c"

/* Structures */

struct Scope {
    char * id;
    struct SymbolNode * root;
    struct Scope * fScope;
    struct Scope * next;
};

/* Functions */

struct Scope * createScope(char * id);
struct Scope * insertScope(struct Scope * root, struct Scope * newNode);

struct Scope * setFScope(struct Scope * fScope, struct Scope * scope);

struct Scope * insertSymbol(struct Scope * scope, struct SymbolNode * symbol);

struct Scope * searchScope(struct Scope * root, char * id);

int sizeScope(struct Scope * root);

void printScope(struct Scope * root);

void printList(struct SymbolNode * root);

struct Scope * createScope(char * id) {
    struct Scope * newScope;
    newScope = malloc(sizeof(struct Scope));
    newScope->id = id;
    newScope->root = 0;
    newScope->next = 0;
    return newScope;
};

struct Scope * setFScope(struct Scope * fScope, struct Scope * scope) {
    scope->fScope = fScope;
    return scope;
};

struct Scope * insertScope(struct Scope * root, struct Scope * newNode) {
    int size = sizeScope(root);
    if(size == 0) {
        root = newNode;
    }
    else {
        struct Scope * temp = root;
        for(int i = 0; i < size - 1; i++) {
        temp = temp->next;
        }
        temp->next = newNode;
    }
    return root;
};

struct Scope * insertSymbol(struct Scope * scope, struct SymbolNode * symbol) {
    int size = sizeSymbol(symbol);
    struct SymbolNode * newRoot = createSymbolNode(symbol->type,symbol->id);
    struct SymbolNode * temp = newRoot;
    struct  SymbolNode * temp2 = symbol;
    for(int i = 0;i<size-1;i++){
        temp->next = createSymbolNode(temp2->next->type,temp2->next->id);
        temp = temp->next;
        temp2 = temp2->next; 
    }
    scope->root = newRoot;
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