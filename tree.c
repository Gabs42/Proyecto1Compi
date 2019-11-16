#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>

/* Structures */

struct ListNode {
  struct TreeNode * node;
  struct ListNode * next;
};

struct TreeNode {
  struct ListNode * root;
  int lineNumber;
  int columnNumber;
  char * value;
  char * type;
};

/* List Functions */

struct ListNode * createListNode(struct TreeNode * node);
struct ListNode * insertListNode(struct ListNode * root, struct ListNode * newNode);
int listSize(struct ListNode * root);

/* Tree Functions */

struct TreeNode * createTreeNode(int lineNumber, char * type, int childs, ...);
struct TreeNode * eN();
struct TreeNode * tN(char * value);
struct TreeNode * tT(char * value, char * type);
void freeTree(struct TreeNode * node);

/* Print functions */

void nodeToString(struct TreeNode * node, int level);
void printNode(struct TreeNode * node, int level);
void printTree(struct TreeNode * root);
void printString(char * string);

/* Functions */

int listSize(struct ListNode * root) {
  int size = 0;
  struct ListNode * temp = root;
  while(temp) {
    size++;
    temp = temp->next;
  }
  return size;
};

struct ListNode * createListNode(struct TreeNode * node) {
  struct ListNode * newNode;
  newNode = malloc(sizeof(struct ListNode));
  newNode->node = node;
  newNode->next = 0;
  return newNode;
};

struct ListNode * insertListNode(struct ListNode * root, struct ListNode * newNode) {
  int size = listSize(root);
  if(size == 0) {
    root = newNode;
  }
  else {
    struct ListNode * temp = root;
    for(int i = 0; i < size - 1; i++) {
      temp = temp->next;
    }
    temp->next = newNode;
  }
  return root;
};

struct TreeNode * createTreeNode(int lineNumber, char * type, int childs, ...) {
  struct TreeNode * treeNode = malloc(sizeof(struct TreeNode));
  treeNode->lineNumber = lineNumber;
  treeNode->columnNumber = 0;
  treeNode->value = "NaT";
  treeNode->type = type;
  treeNode->root = 0;
  va_list ap;
  va_start(ap, childs);
  for(int i = 0; i < childs; i++) {
    struct TreeNode * argument = va_arg(ap, struct TreeNode *);
    if(argument->columnNumber > -1) {
      struct ListNode * child = createListNode(argument);
      treeNode->root = insertListNode(treeNode->root, child);
    }
  }
  va_end(ap);
  return treeNode;
};

struct TreeNode * eN() {
  struct TreeNode * treeNode = malloc(sizeof(struct TreeNode));
  treeNode->columnNumber = -1;
  return treeNode;
};

struct TreeNode * tN(char * value) {
  struct TreeNode * treeNode = malloc(sizeof(struct TreeNode));
  treeNode->value = value;
  treeNode->type = "Terminal";
  treeNode->columnNumber = 0;
  treeNode->root = 0;
  treeNode->lineNumber = 0;
  return treeNode;
};

struct TreeNode * tT(char * value, char * type) {
  struct TreeNode * treeNode = malloc(sizeof(struct TreeNode));
  treeNode->value = malloc(sizeof(char *));
  treeNode->value = value;
  treeNode->type = type;
  treeNode->columnNumber = 0;
  treeNode->root = 0;
  treeNode->lineNumber = 0;
  return treeNode;
};

void freeTree(struct TreeNode * node) {
  int size = listSize(node->root);
  struct ListNode * nodes[size];
  struct ListNode * temp = node->root;
  for(int i = 0; i < size; i++) {
    nodes[i] = temp;
    temp = temp->next;
  }
  for(int i = size - 1; i > -1; i--) {
    struct ListNode * element = nodes[i];
    struct TreeNode * child = element->node;
    freeTree(child);
    free(element);
  }
  free(node);
};

void printString(char * string) {
  char * temp = string;
  while(*temp != '\0') {
    printf("%c", *temp);
    temp++;
  }
};

void nodeToString(struct TreeNode * node, int level) {
  for(int i = 0; i <= level; i++) {
    if(i == level) {
      printf("->");
    }
    else {
      printf("  ");
    }
  }
  printf(" | Line: %d | ", node->lineNumber);
  printf("Column: %d | ", node->columnNumber);
  printf("Type: ");
  printString(node->type);
  printf(" | ");
  printf("Value: ");
  printString(node->value);
  printf(" |");
  printf("\n");
};

void printNode(struct TreeNode * node, int level) {
  nodeToString(node, level);
  int size = listSize(node->root);
  int newLevel = level + 1;
  struct ListNode * temp = node->root;
  for(int i = 0; i < size; i++) {
    printNode(temp->node, newLevel);
    temp = temp->next;
  }
};

void printTree(struct TreeNode * root) {
  printNode(root, 1);
};
