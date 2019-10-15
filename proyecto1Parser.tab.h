/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

#ifndef YY_YY_PROYECTO1PARSER_TAB_H_INCLUDED
# define YY_YY_PROYECTO1PARSER_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    VOID = 258,
    INTEGER = 259,
    DOUBLE = 260,
    BOOL = 261,
    STRING = 262,
    CLASS = 263,
    INTERFACE = 264,
    NULLN = 265,
    THIS = 266,
    EXTENDS = 267,
    IMPLEMENTS = 268,
    FOR = 269,
    WHILE = 270,
    IF = 271,
    ELSE = 272,
    RETURN = 273,
    BREAK = 274,
    NEW = 275,
    NEWARRAY = 276,
    PRINT = 277,
    READINTEGER = 278,
    READLINE = 279,
    TRUE = 280,
    FALSE = 281,
    ID = 282,
    COMMA = 283,
    POINT = 284,
    LFTBRCKT = 285,
    RGHBRCKT = 286,
    LFTPARTH = 287,
    RGHPARTH = 288,
    SEMICLN = 289,
    LFTGATE = 290,
    RGHGATE = 291,
    STRINGERROR = 292,
    INVCHAR = 293,
    INVESCP = 294,
    LINEJMP = 295,
    TAB = 296,
    SPACE = 297,
    INTVAL = 298,
    DOUBLEVAL = 299,
    STRINGVAL = 300,
    SUM = 301,
    SUB = 302,
    MULT = 303,
    DIV = 304,
    LESSTHN = 305,
    LESSEQL = 306,
    GREATERTHN = 307,
    GREATEREQL = 308,
    EQUAL = 309,
    SAME = 310,
    DIFF = 311,
    AND = 312,
    OR = 313,
    NOT = 314
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 90 "proyecto1Parser.y" /* yacc.c:1909  */

	char* str;
	struct treeNode * ast;

#line 119 "proyecto1Parser.tab.h" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PROYECTO1PARSER_TAB_H_INCLUDED  */
