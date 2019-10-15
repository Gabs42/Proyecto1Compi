%option nounput yylineno
%{
#include "proyecto1Parser.tab.h"
#include <stdio.h>
#include <stdlib.h>
struct Node{
    void *data;
    struct Node *next;
};
struct Node *lineStart = NULL;
void add(struct Node** head, void *new, size_t size);
struct Node *columnStart = NULL;
int columnNumber = 1;
struct Node *tokenStart = NULL;
struct Node *valueStart = NULL;
char empty[] = "";
void addListVal(int token,int column,int line,char * val);
void addList(int token,int column,int line);
void printInt(struct Node *nodeLine,struct Node *nodeColumn,struct Node *nodeToken,struct Node *nodeValue);
%}


%%
<<<<<<< HEAD
"void"                  addList(1,columnNumber,yylineno);columnNumber= columnNumber+yyleng-1;return VOID;
"int"                   addList(2,columnNumber,yylineno);columnNumber= columnNumber+yyleng-1; return INTEGER;
"double"                addList(3,columnNumber,yylineno);columnNumber= columnNumber+yyleng-1;return DOUBLE;
"bool"                  addList(4,columnNumber,yylineno);columnNumber= columnNumber+yyleng-1;return BOOL;
"string"                addList(5,columnNumber,yylineno);columnNumber= columnNumber+yyleng-1;return STRING;
"class"                 addList(6,columnNumber,yylineno);columnNumber= columnNumber+yyleng-1;return INTEGER;
"interface"             addList(7,columnNumber,yylineno);columnNumber= columnNumber+yyleng-1;return INTERFACE;
"null"                  addList(8,columnNumber,yylineno);columnNumber= columnNumber+yyleng-1;return NULLN;
"this"                  addList(9,columnNumber,yylineno);columnNumber= columnNumber+yyleng-1;return THIS;
"extends"               addList(10,columnNumber,yylineno);columnNumber= columnNumber+yyleng-1;return EXTENDS;
"implements"            addList(11,columnNumber,yylineno);columnNumber= columnNumber+yyleng-1;return IMPLEMENTS;
"for"                   addList(12,columnNumber,yylineno);columnNumber= columnNumber+yyleng-1;return FOR;
"while"                 addList(13,columnNumber,yylineno);columnNumber= columnNumber+yyleng-1;return WHILE;
"if"                    addList(14,columnNumber,yylineno);columnNumber= columnNumber+yyleng-1;return IF;
"else"                  addList(15,columnNumber,yylineno);columnNumber= columnNumber+yyleng-1;return ELSE;
"return"                addList(16,columnNumber,yylineno);columnNumber= columnNumber+yyleng-1;return RETURN;
"break"                 addList(17,columnNumber,yylineno);columnNumber= columnNumber+yyleng-1;return BREAK;
"New"                   addList(18,columnNumber,yylineno);columnNumber= columnNumber+yyleng-1;return NEW;
"NewArray"              addList(19,columnNumber,yylineno);columnNumber= columnNumber+yyleng-1;return NEWARRAY;
"Print"                 addList(20,columnNumber,yylineno);columnNumber= columnNumber+yyleng-1;return PRINT;
"ReadInteger"           addList(21,columnNumber,yylineno);columnNumber= columnNumber+yyleng-1;return READINTEGER;
"ReadLine"              addList(22,columnNumber,yylineno);columnNumber= columnNumber+yyleng-1;return READLINE;
"true"                  addListVal(23,columnNumber,yylineno,yytext);columnNumber= columnNumber+yyleng-1;return STRINGVAL;return TRUE;
"false"                addListVal(24,columnNumber,yylineno,yytext);columnNumber= columnNumber+yyleng-1;return STRINGVAL;return FALSE;
[a-zA-Z][_a-zA-Z0-9]{0,30}   {addList(25,columnNumber,yylineno);columnNumber= columnNumber+yyleng-1;yylval.str = strdup(yytext);return ID;}
[0-9]+[a-wA-WyzYZ][_a-zA-Z0-9]* printf("Caracter ilegal en la linea %d columna %d\n",yylineno,columnNumber);return INVCHAR;
["][^"\n]*["]           addListVal(57,columnNumber,yylineno,yytext);columnNumber= columnNumber+yyleng-1;return STRINGVAL;
["][^"\n]*[\n]          printf("String no cerrado en la linea %d columna %d\n",yylineno-1,columnNumber);return STRINGERROR;
["][^"\n]*[\n]["]       printf("String no cerrado en la linea %d columna %d\n",yylineno-1,columnNumber);return STRINGERROR;
[1-9][0-9]*             addListVal(57,columnNumber,yylineno,yytext);columnNumber= columnNumber+yyleng-1;return STRINGVAL;return INTVAL;
[0][Xx]+[0-9a-fA-F]*     addListVal(57,columnNumber,yylineno,yytext);columnNumber= columnNumber+yyleng-1;return STRINGVAL;return INTVAL;
[0-9]+[.][0-9]+          addListVal(56,columnNumber,yylineno,yytext);columnNumber= columnNumber+yyleng-1;return STRINGVAL;return DOUBLEVAL;
[0-9]+[.][E][+][1-9][0-9]* addListVal(56,columnNumber,yylineno,yytext);columnNumber= columnNumber+yyleng-1;return STRINGVAL;return DOUBLEVAL;
[+]                     addList(26,columnNumber,yylineno);columnNumber= columnNumber+yyleng-1;return SUM;
[-]                     addList(27,columnNumber,yylineno);columnNumber= columnNumber+yyleng-1;return SUB;
[*]                     addList(28,columnNumber,yylineno);columnNumber= columnNumber+yyleng-1;return MULT;
[/]                     addList(29,columnNumber,yylineno);columnNumber= columnNumber+yyleng-1;return DIV;
[<]                     addList(30,columnNumber,yylineno);columnNumber= columnNumber+yyleng-1;return LESSTHN;
"<="                    addList(31,columnNumber,yylineno);columnNumber= columnNumber+yyleng-1;return LESSEQL;
[>]                     addList(32,columnNumber,yylineno);columnNumber= columnNumber+yyleng-1;return GREATERTHN;
">="                    addList(33,columnNumber,yylineno);columnNumber= columnNumber+yyleng-1;return GREATEREQL;
"="                     addList(34,columnNumber,yylineno);columnNumber= columnNumber+yyleng-1;return EQUAL;
"=="                    addList(35,columnNumber,yylineno);columnNumber= columnNumber+yyleng-1;return SAME;
[!][=]                    addList(36,columnNumber,yylineno);columnNumber= columnNumber+yyleng-1;return DIFF;
[&][&]                    addList(37,columnNumber,yylineno);columnNumber= columnNumber+yyleng-1;return AND;
[|][|]                    addList(38,columnNumber,yylineno);columnNumber= columnNumber+yyleng-1;return OR;
"!"                     addList(39,columnNumber,yylineno);columnNumber= columnNumber+yyleng-1;return NOT;
[;]                     addList(40,columnNumber,yylineno);columnNumber= columnNumber+yyleng-1;return SEMICLN;
[,]                     addList(41,columnNumber,yylineno);columnNumber= columnNumber+yyleng-1;return COMMA;
[.]                     addList(42,columnNumber,yylineno);columnNumber= columnNumber+yyleng-1;return POINT;
[[]                     addList(43,columnNumber,yylineno);columnNumber= columnNumber+yyleng-1;return LFTBRCKT;
[]]                     addList(44,columnNumber,yylineno);columnNumber= columnNumber+yyleng-1;return RGHBRCKT;
[(]                     addList(45,columnNumber,yylineno);columnNumber= columnNumber+yyleng-1;return LFTPARTH;
[)]                     addList(46,columnNumber,yylineno);columnNumber= columnNumber+yyleng-1;return RGHPARTH;
[{]                     addList(47,columnNumber,yylineno);columnNumber= columnNumber+yyleng-1;return LFTGATE;
[}]                     addList(48,columnNumber,yylineno);columnNumber= columnNumber+yyleng-1;return RGHGATE;
=======
"void"                  return VOID;
"int"                   return INTEGER;
"double"                return DOUBLE;
"bool"                  return BOOL;
"string"                return STRING;
"class"                 return CLASS;
"interface"             return INTERFACE;
"null"                  return NULLN;
"this"                  return THIS;
"extends"               return EXTENDS;
"implements"            return IMPLEMENTS;
"for"                   return FOR;
"while"                 return WHILE;
"if"                    return IF;
"else"                  return ELSE;
"return"                return RETURN;
"break"                 return BREAK;
"New"                   return NEW;
"NewArray"              return NEWARRAY;
"Print"                 return PRINT;
"ReadInteger"           return READINTEGER;
"ReadLine"              return READLINE;
"true"                  return TRUE;
"false"                 return FALSE;
"null"                  return NULLVAL;
[a-zA-Z][_a-zA-Z0-9]{0,30}   {yylval.str = strdup(yytext);return ID;}
[0-9]+[a-wA-WyzYZ][_a-zA-Z0-9]* return INVCHAR;
["][^"\n]*["]           return STRINGVAL;
["][^"\n]*[\n]          return STRINGERROR;
["][^"\n]*[\n]["]       return STRINGERROR;
[1-9][0-9]*             return INTVAL;
[0][Xx]+[0-9a-fA-F]*     return INTVAL;
[0-9]+[.][0-9]+          return DOUBLEVAL;
[0-9]+[.][E][+][1-9][0-9]* return DOUBLEVAL;
[+]                     return SUM;
[-]                     return SUB;
[*]                     return MULT;
[/]                     return DIV;
[%]                     return MOD;
[<]                     return LESSTHN;
"<="                    return LESSEQL;
[>]                     return GREATERTHN;
">="                    return GREATEREQL;
"="                     return EQUAL;
"=="                    return SAME;
[!][=]                  return DIFF;
[&][&]                  return AND;
[|][|]                  return OR;
"!"                     return NOT;
[;]                     return SEMICLN;
[,]                     return COMMA;
[.]                     return POINT;
[[]                     return LFTBRCKT;
[]]                     return RGHBRCKT;
[(]                     return LFTPARTH;
[)]                     return RGHPARTH;
[{]                     return LFTGATE;
[}]                     return RGHGATE;
>>>>>>> d44ac492da238286f754a401332d071b3adedcd4
[/][/][ _a -zA -Z0 -9 ]*     ;
[/*][ _a -zA -Z0 -9\n]*[*/] ;
.*[\\][^ntabfnr'"\\?x].*    printf("Secuencia de escape ilegal en la linea %d columna %d\n",yylineno,columnNumber);return INVESCP;
[\t]                 columnNumber= columnNumber+1;return TAB;
[\n]                columnNumber=1;return LINEJMP;
[ ]                  columnNumber= columnNumber+1; return SPACE;
<<EOF>>             printInt(lineStart,columnStart,tokenStart,valueStart); return 0;
.                       printf("Caracter ilegal en la linea %d columna %d\n",yylineno,columnNumber);return INVCHAR;

%%



void addList(int token,int column,int line){
   add(&valueStart,&empty,sizeof(char *));
   add(&lineStart,&line,sizeof(line));
   add(&columnStart,&column,sizeof(column));
   add(&tokenStart,&token,sizeof(token));
}

void addListVal(int token,int column,int line,char * val){
  add(&valueStart,&val,sizeof(char *));
  add(&lineStart,&line,sizeof(line));
  add(&columnStart,&column,sizeof(column));
  add(&tokenStart,&token,sizeof(token));
}
void add(struct Node** head, void *new, size_t size){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data  = malloc(size);
    memcpy(newNode->data,new,size);
    newNode->next = NULL;
    if(*head == NULL){
        *head = newNode;
    }
    else{
        struct Node* pointer = *head;


        while(pointer->next!=NULL){
        pointer = pointer->next;
       }
        pointer->next = newNode;
    }



}

void printInt(struct Node *nodeLine,struct Node *nodeColumn,struct Node *nodeToken,struct Node *nodeValue){
    printf("Line\t\t Column\t\t Token\t\t Value\t\t\n");
    while(nodeLine!=NULL){
        printf(" %d\t\t %d\t\t %d\t\t %s\n",*(int *)nodeLine->data,*(int *)nodeColumn->data,*(int *)nodeToken->data,*(char **)nodeValue->data);
        nodeLine = nodeLine->next;
        nodeColumn = nodeColumn->next;
        nodeToken = nodeToken->next;
        nodeValue = nodeValue->next;
    }

}
// void main()
// {
//  char* p;
//  int columnNumber = 1;
//  char empty[] = " ";
//  struct Node *lineStart = NULL;
//  struct Node *columnStart = NULL;
//  struct Node *tokenStart = NULL;
//  struct Node *valueStart = NULL;
//  int token;
//  token = yylex();
//  while(token){
//         printf(" %d\n",token);
//     switch (token){
//         case STRINGERROR:
//              printf("String no cerrado en la linea %d columna %d\n",yylineno-1,columnNumber);
//              return;
//              break;
//         case INVCHAR:
//              printf("Caracter ilegal en la linea %d columna %d\n",yylineno,columnNumber);
//              return;
//              break;
//         case INVESCP:
//              printf("Secuencia de escape ilegal en la linea %d columna %d\n",yylineno,columnNumber);
//              return;
//              break;
//        case  LINEJMP:
//              columnNumber =1;
//              token = yylex();
//              continue;
//              break;
//        case TAB:
//              token = yylex();
//              columnNumber= columnNumber+1;
//              continue;
//              break;
//        case SPACE:
//             token = yylex();
//             columnNumber= columnNumber+1;
//             continue;
//             break;
//        case INTVAL:
//             add(&valueStart,&yytext,sizeof(char *));
//             add(&lineStart,&yylineno,sizeof(yylineno));
//             add(&columnStart,&columnNumber,sizeof(columnNumber));
//             add(&tokenStart,&token,sizeof(token));
//             token = yylex();
//             columnNumber= columnNumber+1;
//             continue;
//             break;
//        case DOUBLEVAL:
//             add(&valueStart,&yytext,sizeof(char *));
//             add(&lineStart,&yylineno,sizeof(yylineno));
//             add(&columnStart,&columnNumber,sizeof(columnNumber));
//             add(&tokenStart,&token,sizeof(token));
//             token = yylex();
//             columnNumber= columnNumber+1;
//             continue;
//             break;
//        case STRINGVAL:
//             add(&valueStart,&yytext,sizeof(char *));
//             add(&lineStart,&yylineno,sizeof(yylineno));
//             add(&columnStart,&columnNumber,sizeof(columnNumber));
//             add(&tokenStart,&token,sizeof(token));
//             token = yylex();
//             columnNumber= columnNumber+1;
//             continue;
//             break;
//       case TRUE:
//             add(&valueStart,&yytext,sizeof(char *));
//             add(&lineStart,&yylineno,sizeof(yylineno));
//             add(&columnStart,&columnNumber,sizeof(columnNumber));
//             add(&tokenStart,&token,sizeof(token));
//             token = yylex();
//             columnNumber= columnNumber+1;
//             continue;
//             break;
//        case FALSE:
//             add(&valueStart,&yytext,sizeof(char *));
//             add(&lineStart,&yylineno,sizeof(yylineno));
//             add(&columnStart,&columnNumber,sizeof(columnNumber));
//             add(&tokenStart,&token,sizeof(token));
//             token = yylex();
//             columnNumber= columnNumber+1;
//             continue;
//             break;

//     }

//     add(&valueStart,&empty,sizeof(char *));
//     add(&lineStart,&yylineno,sizeof(yylineno));
//     add(&columnStart,&columnNumber,sizeof(columnNumber));
//     add(&tokenStart,&token,sizeof(token));
//     columnNumber = columnNumber + yyleng-1;
//     token = yylex();
//     columnNumber = columnNumber+1;

//  }
//  printInt(lineStart,columnStart,tokenStart,valueStart);
// }
