%{
#include "proyecto1Scanner.h"
%}
%%
"void"                  return VOID;
"int"                   return INTEGER;
"double"                return DOUBLE;
"bool"                  return BOOL;
"string"                return STRING;
"class"                 return INTEGER;
"interface"             return INTERFACE;
"null"                  return NULL;
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
[a-zA-Z][_a-zA-Z0-9]{0,30}   return ID;
[1-9][0-9]*             return INTEGER;
[+\-\*\/\<\<=\>\>=\=]   return OPERATOR;
[==\!=\&&\||\!\;\,\.]   return OPERATOR;
[[\]\(\)\{\}]           return OPERATOR;
[/][/][ _a -zA -Z0 -9 ]*     ;
[/*][ _a -zA -Z0 -9\n]*[*/] ;
[ \t\n]                 ;
%%
main()
{
 int token;
 token = yylex();
 while(token){
    printf("%d\n",token);
    token = yylex();
 }
}
