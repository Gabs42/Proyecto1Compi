#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include "scopes.c"

struct ScopeNode {
    struct Scope * value;
    struct ScopeNode * next;
};

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