#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include "tree.c"
#include "scopeList.c"

struct Scope * scope getScope(struct TreeNode * node);

int checkClass(char * id);
char * getTypeFunction(char * id, struct Scope * scope);
char * getTypeId(char * id, struct Scope * scope);
char * getTypeConstant(struct TreeNode * node);
char * getTypeReturn(struct TreeNode * node);
char * getTypeExpr(struct TreeNode * node);
