#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>

/* Structures */

struct SymbolNode {
    char * type;
    char * id;
    int parameter;
    int array;
    struct SymbolNode * next;
};

/* Functions */

struct SymbolNode * createSymbolNode(char * type, char * id);
struct SymbolNode * insertSymbolNode(struct SymbolNode * root, struct SymbolNode * node);

struct SymbolNode * searchSymbol(struct SymbolNode * root, char * id);

struct SymbolNode * setArray(struct SymbolNode * node, int array);

int sizeSymbol(struct SymbolNode * root);

struct SymbolNode * setArray(struct SymbolNode * node, int array);

struct SymbolNode * setArray(struct SymbolNode * node, int array) {
  node->array = array;
};

struct SymbolNode * searchSymbol(struct SymbolNode * root, char * id) {
    int size = sizeSymbol(root);
    struct SymbolNode * temp = root;
    for(int i = 0; i < size; i++) {
        char * value = temp->id;
        if(strcmp(id, value) == 0) {
            return temp;
        }
        temp = temp->next;
    }
    return 0;
};

struct SymbolNode * createSymbolNode(char * type, char * id) {
    struct SymbolNode * newNode;
    newNode = malloc(sizeof(struct SymbolNode));
    newNode->type = type;
    newNode->id = id;
    newNode->next = 0;
    newNode->parameter = 0;
    newMode->array = 0;
    return newNode;
};

struct SymbolNode * insertSymbolNode(struct SymbolNode * root, struct SymbolNode * newNode) {
    int size = sizeSymbol(root);
    if(size == 0) {
        root = newNode;
    }
    else {
        struct SymbolNode * temp = root;
        for(int i = 0; i < size - 1; i++) {
        temp = temp->next;
        }
        temp->next = newNode;
    }
    return root;
};

int sizeSymbol(struct SymbolNode * root) {
    int size = 0;
    struct SymbolNode * temp = root;
    while(temp) {
        size++;
        temp = temp->next;
    }
    return size;
};
