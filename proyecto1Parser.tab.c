/* A Bison parser, made by GNU Bison 3.4.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2019 Free Software Foundation,
   Inc.

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.4.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "proyecto1Parser.y"


#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include "scopeList.c"

extern FILE* yyin;
extern int yylineno;
extern int yyparse();
void yyerror (char *s);
struct SymbolNode * createSymbol(struct TreeNode * variable);
struct SymbolNode * createSymbolAux(struct TreeNode * type, char * id, int dimension);
int yylex();
char* symbols[50][3];
int fila = 0;

struct TreeNode * tree;

struct Scope * globalScope;

struct ScopeNode * classList;

struct ScopeNode * scopeList;
struct SymbolNode * symbolList;

struct SymbolNode * symbolClass;

struct SymbolNode * symbolGlobal;
struct ScopeNode * functionsGlobal;

struct SymbolNode * symbolExtends;
struct ScopeNode * scopeExtends;

//Validations functions

void adjustFScope();

struct Scope * getScope(struct TreeNode * node);
struct Scope * getScopeAux(struct TreeNode * node, struct Scope * scope);

struct Scope * checkClass(char * id);

struct Scope * getScopeClass(char * id);

int checkSubClass(char * class, char * subClass);

int checkSymbolScope(struct Scope * scope);

int checkFunctionReturn(struct TreeNode * returnNode, struct Scope * function);

struct SymbolNode * getTypeId(char * id, struct Scope * scope);

struct SymbolNode * getTypeFunction(char * id, struct Scope * scope);

char * getTypeConstant(struct TreeNode * node);
char * getValueConstant(struct TreeNode * node);

char * getTypeReturn(struct TreeNode * node, struct Scope * actualScope);

char * getTypeExpr(struct TreeNode * node, struct Scope * actualScope);

char * getTypeLValue(struct TreeNode * node, struct Scope * actualScope);

char * getTypeCall(struct TreeNode * node, struct Scope * actualScope);

void probarMetodo(struct TreeNode * node, struct Scope * actualScope);


#line 142 "proyecto1Parser.tab.c"

# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
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
    COMMA = 282,
    POINT = 283,
    LFTBRCKT = 284,
    RGHBRCKT = 285,
    LFTPARTH = 286,
    RGHPARTH = 287,
    SEMICLN = 288,
    LFTGATE = 289,
    RGHGATE = 290,
    STRINGERROR = 291,
    INVCHAR = 292,
    INVESCP = 293,
    LINEJMP = 294,
    TAB = 295,
    SPACE = 296,
    INTVAL = 297,
    DOUBLEVAL = 298,
    STRINGVAL = 299,
    OR = 300,
    LESSEQL = 301,
    ID = 302,
    SUM = 303,
    SUB = 304,
    MULT = 305,
    DIV = 306,
    LESSTHN = 307,
    GREATERTHN = 308,
    MOD = 309,
    GREATEREQL = 310,
    EQUAL = 311,
    SAME = 312,
    DIFF = 313,
    AND = 314,
    NOT = 315
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 75 "proyecto1Parser.y"

  char* str;
	struct TreeNode * treeNode;
  int intval;
  struct SymbolNode * symbolNode;
  struct Scope * scope;

#line 254 "proyecto1Parser.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif

/* Location type.  */
#if ! defined YYLTYPE && ! defined YYLTYPE_IS_DECLARED
typedef struct YYLTYPE YYLTYPE;
struct YYLTYPE
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
};
# define YYLTYPE_IS_DECLARED 1
# define YYLTYPE_IS_TRIVIAL 1
#endif


extern YYSTYPE yylval;
extern YYLTYPE yylloc;
int yyparse (void);

#endif /* !YY_YY_PROYECTO1PARSER_TAB_H_INCLUDED  */



#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL \
             && defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
  YYLTYPE yyls_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE) + sizeof (YYLTYPE)) \
      + 2 * YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  24
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   353

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  61
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  41
/* YYNRULES -- Number of rules.  */
#define YYNRULES  105
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  193

#define YYUNDEFTOK  2
#define YYMAXUTOK   315

/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                                \
  ((unsigned) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   109,   109,   123,   124,   127,   132,   140,   141,   144,
     147,   150,   151,   152,   153,   154,   155,   158,   161,   162,
     165,   166,   169,   175,   178,   196,   199,   203,   206,   210,
     213,   214,   217,   218,   221,   226,   236,   252,   255,   256,
     259,   266,   267,   270,   273,   274,   277,   278,   279,   280,
     281,   282,   283,   284,   285,   292,   293,   296,   299,   300,
     303,   306,   309,   312,   315,   318,   319,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   331,   332,   333,   334,
     335,   336,   337,   338,   339,   340,   341,   342,   343,   344,
     345,   346,   349,   350,   351,   354,   357,   358,   361,   362,
     365,   366,   367,   368,   369,   370
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "VOID", "INTEGER", "DOUBLE", "BOOL",
  "STRING", "CLASS", "INTERFACE", "NULLN", "THIS", "EXTENDS", "IMPLEMENTS",
  "FOR", "WHILE", "IF", "ELSE", "RETURN", "BREAK", "NEW", "NEWARRAY",
  "PRINT", "READINTEGER", "READLINE", "TRUE", "FALSE", "COMMA", "POINT",
  "LFTBRCKT", "RGHBRCKT", "LFTPARTH", "RGHPARTH", "SEMICLN", "LFTGATE",
  "RGHGATE", "STRINGERROR", "INVCHAR", "INVESCP", "LINEJMP", "TAB",
  "SPACE", "INTVAL", "DOUBLEVAL", "STRINGVAL", "OR", "LESSEQL", "ID",
  "SUM", "SUB", "MULT", "DIV", "LESSTHN", "GREATERTHN", "MOD",
  "GREATEREQL", "EQUAL", "SAME", "DIFF", "AND", "NOT", "$accept",
  "Program", "Declarations", "Declaration", "VariableDecl", "Variable",
  "Type", "FunctionDecl", "FunctionName", "Formals", "Variables",
  "ClassDecl", "ClassName", "Extend", "Implement", "ListIdents", "Fields",
  "Field", "InterfaceDecl", "InterfaceName", "Prototypes", "Prototype",
  "PrototypeName", "StmtBlock", "Stmts", "Stmt", "PossibleExpr", "IfStmt",
  "PossibleElse", "WhileStmt", "ForStmt", "ReturnStmt", "BreakStmt",
  "PrintStmt", "ListExpr", "Expr", "LValue", "FixLValue", "Call",
  "Actuals", "Constant", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315
};
# endif

#define YYPACT_NINF -93

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-93)))

#define YYTABLE_NINF -19

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      30,   -38,   -93,   -93,   -93,   -93,   -25,   -23,   -93,    32,
      30,   -93,   -93,    10,   -27,   -93,    -1,   -93,    38,   -93,
      17,   -93,   -93,   -93,   -93,   -93,   -93,    54,    29,     1,
      40,    90,   -93,   -93,   -93,   -18,    56,    78,   -93,    61,
      77,    12,   -93,    79,     1,   -93,    87,   -93,    69,   -93,
       2,   -93,    94,   -93,   -93,   -93,    74,   155,   -93,   -93,
       1,    75,   -93,   -93,   -93,   -93,   -93,    98,   -93,   -93,
     100,   103,   118,   163,   117,   120,   121,   124,   126,   132,
     -93,   -93,   163,   -93,   -93,   -93,   -93,    73,   163,   163,
     -93,   -93,   -93,   -93,   -93,   -93,   -93,   -93,   -93,   294,
     111,   163,   -93,   -93,   135,   163,   163,   163,   -28,   144,
     294,   -93,   131,   163,   163,   147,   148,   204,   -93,   163,
      -3,   153,   138,   163,   163,   163,   163,   163,   163,   163,
     163,   163,   163,   163,   163,   163,   163,   236,   -93,   159,
     251,   279,   -93,   161,   176,    51,   294,   -93,   -93,   -93,
     168,   164,   167,   153,    -3,    -3,    -3,    -3,    -3,    -3,
      -3,    -3,    -3,   153,   153,   153,   153,   -93,   163,   122,
     122,   -93,     1,   163,   166,   -93,   163,   175,   -93,   183,
      -6,   294,   -93,   169,   163,   122,   -93,   -93,   -93,   177,
     -93,   122,   -93
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,    11,    12,    13,    14,     0,     0,    15,     0,
       2,     3,     5,     0,     0,     6,     0,     7,    27,     8,
       0,    19,    25,    37,     1,     4,     9,     0,    10,    21,
       0,    29,    39,    16,    22,     0,     0,    20,    26,     0,
       0,     0,    10,     0,     0,    30,    28,    33,     0,    36,
       0,    38,     0,    45,    17,    23,     0,     0,    42,    41,
      21,     0,    31,    24,    34,    35,    32,     0,   105,    70,
       0,     0,     0,    56,     0,     0,     0,     0,     0,     0,
     102,   103,     0,    43,   100,   101,   104,    92,     0,     0,
      54,    52,    44,    46,    47,    48,    50,    49,    51,    53,
      69,     0,    71,    68,     0,    56,     0,     0,    92,     0,
      55,    63,     0,     0,     0,     0,     0,     0,    95,    99,
      78,    87,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    40,     0,
       0,     0,    62,     0,     0,     0,    65,    88,    89,    72,
      98,     0,    93,    86,    80,    73,    74,    75,    76,    79,
      81,    77,    82,    83,    84,    85,    67,    94,    56,     0,
       0,    90,     0,     0,     0,    96,    99,     0,    60,    59,
       0,    66,    64,     0,    56,     0,    57,    91,    97,     0,
      58,     0,    61
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -93,   -93,   -93,   201,     4,   110,     0,   156,   -93,   154,
     -93,   -93,   -93,   -93,   -93,   -93,   -93,   -93,   -93,   -93,
     -93,   -93,   -93,   172,   -93,     6,   -92,   -93,   -93,   -93,
     -93,   -93,   -93,   -93,   102,   -61,   -93,   -93,   -93,    41,
     -93
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     9,    10,    11,    90,    13,    35,    15,    16,    36,
      37,    17,    18,    31,    40,    46,    57,    66,    19,    20,
      41,    51,    52,    91,    61,    92,   109,    93,   186,    94,
      95,    96,    97,    98,   150,    99,   100,   101,   102,   151,
     103
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      14,   118,    27,   119,    12,     2,     3,     4,     5,    21,
      14,    27,   110,   139,    12,    48,     2,     3,     4,     5,
      28,   117,    22,    27,    23,   122,   187,   120,   121,    42,
      29,    27,    24,     1,     2,     3,     4,     5,     6,     7,
     137,    50,   123,    26,   110,   140,   141,    49,     8,    59,
      30,    32,   144,   146,   133,   134,   135,    14,   146,     8,
     -18,    64,   153,   154,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   177,     8,   173,     2,
       3,     4,     5,   174,    33,    68,    69,    38,    43,    70,
      71,    72,   189,    73,    74,    75,    76,    77,    78,    79,
      80,    81,   118,    39,   119,    44,    82,   110,    45,    53,
      83,    47,   181,    53,    56,   146,    58,    84,    85,    86,
     -15,    62,    87,   110,    88,    60,     2,     3,     4,     5,
     104,   105,    68,    69,   106,    89,    70,    71,    72,    34,
      73,    74,    75,    76,    77,    78,    79,    80,    81,   107,
     111,   112,   113,    82,    55,   114,    53,   115,     1,     2,
       3,     4,     5,   116,    84,    85,    86,   136,   138,    87,
      34,    88,   180,    68,    69,   178,   179,   142,   143,   147,
     148,   122,    89,    75,    76,   152,    78,    79,    80,    81,
      63,   190,   168,   171,    82,   173,   175,   192,   176,   182,
     185,   188,     8,   172,   122,    84,    85,    86,   184,   191,
     108,    25,    88,    65,    67,    54,   145,   183,     0,     0,
       0,   123,   124,    89,   125,   126,   127,   128,   129,   130,
     131,   132,   122,   133,   134,   135,   149,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   123,
     124,     0,   125,   126,   127,   128,   129,   130,   131,   132,
       0,   133,   134,   135,   122,     0,   167,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   122,
       0,   123,   124,   169,   125,   126,   127,   128,   129,   130,
     131,   132,     0,   133,   134,   135,   123,   124,     0,   125,
     126,   127,   128,   129,   130,   131,   132,   122,   133,   134,
     135,   170,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   122,     0,   123,   124,     0,   125,   126,   127,
     128,   129,   130,   131,   132,     0,   133,   134,   135,   123,
     124,     0,   125,   126,   127,   128,   129,   130,   131,   132,
       0,   133,   134,   135
};

static const yytype_int16 yycheck[] =
{
       0,    29,    29,    31,     0,     4,     5,     6,     7,    47,
      10,    29,    73,   105,    10,     3,     4,     5,     6,     7,
      47,    82,    47,    29,    47,    28,    32,    88,    89,    47,
      31,    29,     0,     3,     4,     5,     6,     7,     8,     9,
     101,    41,    45,    33,   105,   106,   107,    35,    47,    47,
      12,    34,   113,   114,    57,    58,    59,    57,   119,    47,
      31,    57,   123,   124,   125,   126,   127,   128,   129,   130,
     131,   132,   133,   134,   135,   136,   168,    47,    27,     4,
       5,     6,     7,    32,    30,    10,    11,    47,    32,    14,
      15,    16,   184,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    29,    13,    31,    27,    31,   168,    47,    34,
      35,    34,   173,    34,    27,   176,    47,    42,    43,    44,
      47,    47,    47,   184,    49,    31,     4,     5,     6,     7,
      32,    31,    10,    11,    31,    60,    14,    15,    16,    29,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    31,
      33,    31,    31,    31,    44,    31,    34,    31,     3,     4,
       5,     6,     7,    31,    42,    43,    44,    56,    33,    47,
      60,    49,   172,    10,    11,   169,   170,    33,    47,    32,
      32,    28,    60,    20,    21,    47,    23,    24,    25,    26,
      35,   185,    33,    32,    31,    27,    32,   191,    31,    33,
      17,    32,    47,    27,    28,    42,    43,    44,    33,    32,
      47,    10,    49,    57,    60,    43,   114,   176,    -1,    -1,
      -1,    45,    46,    60,    48,    49,    50,    51,    52,    53,
      54,    55,    28,    57,    58,    59,    32,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    45,
      46,    -1,    48,    49,    50,    51,    52,    53,    54,    55,
      -1,    57,    58,    59,    28,    -1,    30,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    28,
      -1,    45,    46,    32,    48,    49,    50,    51,    52,    53,
      54,    55,    -1,    57,    58,    59,    45,    46,    -1,    48,
      49,    50,    51,    52,    53,    54,    55,    28,    57,    58,
      59,    32,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    28,    -1,    45,    46,    -1,    48,    49,    50,
      51,    52,    53,    54,    55,    -1,    57,    58,    59,    45,
      46,    -1,    48,    49,    50,    51,    52,    53,    54,    55,
      -1,    57,    58,    59
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     4,     5,     6,     7,     8,     9,    47,    62,
      63,    64,    65,    66,    67,    68,    69,    72,    73,    79,
      80,    47,    47,    47,     0,    64,    33,    29,    47,    31,
      12,    74,    34,    30,    66,    67,    70,    71,    47,    13,
      75,    81,    47,    32,    27,    47,    76,    34,     3,    35,
      67,    82,    83,    34,    84,    66,    27,    77,    47,    47,
      31,    85,    47,    35,    65,    68,    78,    70,    10,    11,
      14,    15,    16,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    31,    35,    42,    43,    44,    47,    49,    60,
      65,    84,    86,    88,    90,    91,    92,    93,    94,    96,
      97,    98,    99,   101,    32,    31,    31,    31,    47,    87,
      96,    33,    31,    31,    31,    31,    31,    96,    29,    31,
      96,    96,    28,    45,    46,    48,    49,    50,    51,    52,
      53,    54,    55,    57,    58,    59,    56,    96,    33,    87,
      96,    96,    33,    47,    96,    95,    96,    32,    32,    32,
      95,   100,    47,    96,    96,    96,    96,    96,    96,    96,
      96,    96,    96,    96,    96,    96,    96,    30,    33,    32,
      32,    32,    27,    27,    32,    32,    31,    87,    86,    86,
      67,    96,    33,   100,    33,    17,    89,    32,    32,    87,
      86,    32,    86
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    61,    62,    63,    63,    64,    64,    64,    64,    65,
      66,    67,    67,    67,    67,    67,    67,    68,    69,    69,
      70,    70,    71,    71,    72,    73,    74,    74,    75,    75,
      76,    76,    77,    77,    78,    78,    79,    80,    81,    81,
      82,    83,    83,    84,    85,    85,    86,    86,    86,    86,
      86,    86,    86,    86,    86,    87,    87,    88,    89,    89,
      90,    91,    92,    93,    94,    95,    95,    96,    96,    96,
      96,    96,    96,    96,    96,    96,    96,    96,    96,    96,
      96,    96,    96,    96,    96,    96,    96,    96,    96,    96,
      96,    96,    97,    97,    97,    98,    99,    99,   100,   100,
     101,   101,   101,   101,   101,   101
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     2,     1,     1,     1,     1,     2,
       2,     1,     1,     1,     1,     1,     3,     5,     2,     2,
       1,     0,     1,     3,     6,     2,     2,     0,     2,     0,
       1,     3,     2,     0,     1,     1,     4,     2,     2,     0,
       5,     2,     2,     3,     2,     0,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     0,     6,     2,     0,
       5,     9,     3,     2,     5,     1,     3,     3,     1,     1,
       1,     1,     3,     3,     3,     3,     3,     3,     2,     3,
       3,     3,     3,     3,     3,     3,     3,     2,     3,     3,
       4,     6,     1,     3,     3,     2,     4,     6,     1,     0,
       1,     1,     1,     1,     1,     1
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)                                \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;        \
          (Current).first_column = YYRHSLOC (Rhs, 1).first_column;      \
          (Current).last_line    = YYRHSLOC (Rhs, N).last_line;         \
          (Current).last_column  = YYRHSLOC (Rhs, N).last_column;       \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).first_line   = (Current).last_line   =              \
            YYRHSLOC (Rhs, 0).last_line;                                \
          (Current).first_column = (Current).last_column =              \
            YYRHSLOC (Rhs, 0).last_column;                              \
        }                                                               \
    while (0)
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K])


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL

/* Print *YYLOCP on YYO.  Private, do not rely on its existence. */

YY_ATTRIBUTE_UNUSED
static int
yy_location_print_ (FILE *yyo, YYLTYPE const * const yylocp)
{
  int res = 0;
  int end_col = 0 != yylocp->last_column ? yylocp->last_column - 1 : 0;
  if (0 <= yylocp->first_line)
    {
      res += YYFPRINTF (yyo, "%d", yylocp->first_line);
      if (0 <= yylocp->first_column)
        res += YYFPRINTF (yyo, ".%d", yylocp->first_column);
    }
  if (0 <= yylocp->last_line)
    {
      if (yylocp->first_line < yylocp->last_line)
        {
          res += YYFPRINTF (yyo, "-%d", yylocp->last_line);
          if (0 <= end_col)
            res += YYFPRINTF (yyo, ".%d", end_col);
        }
      else if (0 <= end_col && yylocp->first_column < end_col)
        res += YYFPRINTF (yyo, "-%d", end_col);
    }
  return res;
 }

#  define YY_LOCATION_PRINT(File, Loc)          \
  yy_location_print_ (File, &(Loc))

# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value, Location); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  YYUSE (yylocationp);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yytype], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  YYFPRINTF (yyo, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  YY_LOCATION_PRINT (yyo, *yylocationp);
  YYFPRINTF (yyo, ": ");
  yy_symbol_value_print (yyo, yytype, yyvaluep, yylocationp);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, YYLTYPE *yylsp, int yyrule)
{
  unsigned long yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &yyvsp[(yyi + 1) - (yynrhs)]
                       , &(yylsp[(yyi + 1) - (yynrhs)])                       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, yylsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            else
              goto append;

          append:
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return (YYSIZE_T) (yystpcpy (yyres, yystr) - yyres);
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
                    yysize = yysize1;
                  else
                    return 2;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
      yysize = yysize1;
    else
      return 2;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep, YYLTYPE *yylocationp)
{
  YYUSE (yyvaluep);
  YYUSE (yylocationp);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Location data for the lookahead symbol.  */
YYLTYPE yylloc
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
  = { 1, 1, 1, 1 }
# endif
;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.
       'yyls': related to locations.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    /* The location stack.  */
    YYLTYPE yylsa[YYINITDEPTH];
    YYLTYPE *yyls;
    YYLTYPE *yylsp;

    /* The locations where the error started and ended.  */
    YYLTYPE yyerror_range[3];

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;
  YYLTYPE yyloc;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N), yylsp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yylsp = yyls = yylsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  yylsp[0] = yylloc;
  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yynewstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  *yyssp = (yytype_int16) yystate;

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = (YYSIZE_T) (yyssp - yyss + 1);

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;
        YYLTYPE *yyls1 = yyls;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yyls1, yysize * sizeof (*yylsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
        yyls = yyls1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
        YYSTACK_RELOCATE (yyls_alloc, yyls);
# undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;
      yylsp = yyls + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END
  *++yylsp = yylloc;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];

  /* Default location. */
  YYLLOC_DEFAULT (yyloc, (yylsp - yylen), yylen);
  yyerror_range[1] = yyloc;
  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2:
#line 109 "proyecto1Parser.y"
    { (yyval.treeNode) = createTreeNode(yylineno, "Program", 1, (yyvsp[0].treeNode));
                                tree = (yyval.treeNode);
                                globalScope = createScope("global", "Global");
                                globalScope = setFScope(globalScope, classList);
                                globalScope = setPScope(globalScope, classList);
                                globalScope = setPScope(globalScope, functionsGlobal);
                                globalScope = setFScope(globalScope, functionsGlobal);
                                globalScope = insertSymbol(globalScope, symbolGlobal);
                                globalScope = setTree(globalScope, (yyval.treeNode));
                                symbolGlobal = 0;
                                functionsGlobal = 0;
                              }
#line 1651 "proyecto1Parser.tab.c"
    break;

  case 3:
#line 123 "proyecto1Parser.y"
    { (yyval.treeNode) = createTreeNode(yylineno, "Declarations", 1, (yyvsp[0].treeNode)); }
#line 1657 "proyecto1Parser.tab.c"
    break;

  case 4:
#line 124 "proyecto1Parser.y"
    { (yyval.treeNode) = createTreeNode(yylineno, "Declarations", 2, (yyvsp[-1].treeNode), (yyvsp[0].treeNode)); }
#line 1663 "proyecto1Parser.tab.c"
    break;

  case 5:
#line 127 "proyecto1Parser.y"
    { (yyval.treeNode) = createTreeNode(yylineno, "Declaration", 1, (yyvsp[0].treeNode));
                                struct TreeNode * variable = (yyvsp[0].treeNode)->root->node;
                                struct SymbolNode * newSymbol = createSymbol(variable);
                                symbolGlobal = insertSymbolNode(symbolGlobal, newSymbol);
                              }
#line 1673 "proyecto1Parser.tab.c"
    break;

  case 6:
#line 132 "proyecto1Parser.y"
    { (yyval.treeNode) = createTreeNode(yylineno, "Declaration", 1, (yyvsp[0].treeNode));
                                struct Scope * newScope = createScope((yyvsp[0].treeNode)->root->node->root->next->node->value, "Function");
                                newScope = insertSymbol(newScope, symbolList);
                                newScope = setTree(newScope, (yyvsp[0].treeNode));
                                struct ScopeNode * newNode = createScopeNode(newScope);
                                functionsGlobal = insertScopeNode(functionsGlobal, newNode);
                                symbolList = 0;
                              }
#line 1686 "proyecto1Parser.tab.c"
    break;

  case 7:
#line 140 "proyecto1Parser.y"
    { (yyval.treeNode) = createTreeNode(yylineno, "Declaration", 1, (yyvsp[0].treeNode)); }
#line 1692 "proyecto1Parser.tab.c"
    break;

  case 8:
#line 141 "proyecto1Parser.y"
    { (yyval.treeNode) = createTreeNode(yylineno, "Declaration", 1, (yyvsp[0].treeNode)); }
#line 1698 "proyecto1Parser.tab.c"
    break;

  case 9:
#line 144 "proyecto1Parser.y"
    { (yyval.treeNode) = createTreeNode(yylineno, "VariableDecl", 2, (yyvsp[-1].treeNode), tN(";")); }
#line 1704 "proyecto1Parser.tab.c"
    break;

  case 10:
#line 147 "proyecto1Parser.y"
    { (yyval.treeNode) = createTreeNode(yylineno, "Variable", 2, (yyvsp[-1].treeNode), tT(yylval.str, "ID")); }
#line 1710 "proyecto1Parser.tab.c"
    break;

  case 11:
#line 150 "proyecto1Parser.y"
    { (yyval.treeNode) = createTreeNode(yylineno, "Type", 1, tN("integer")); }
#line 1716 "proyecto1Parser.tab.c"
    break;

  case 12:
#line 151 "proyecto1Parser.y"
    { (yyval.treeNode) = createTreeNode(yylineno, "Type", 1, tN("double")); }
#line 1722 "proyecto1Parser.tab.c"
    break;

  case 13:
#line 152 "proyecto1Parser.y"
    { (yyval.treeNode) = createTreeNode(yylineno, "Type", 1, tN("boolean")); }
#line 1728 "proyecto1Parser.tab.c"
    break;

  case 14:
#line 153 "proyecto1Parser.y"
    { (yyval.treeNode) = createTreeNode(yylineno, "Type", 1, tN("string")); }
#line 1734 "proyecto1Parser.tab.c"
    break;

  case 15:
#line 154 "proyecto1Parser.y"
    { (yyval.treeNode) = createTreeNode(yylineno, "Type", 1, tN(yylval.str)); }
#line 1740 "proyecto1Parser.tab.c"
    break;

  case 16:
#line 155 "proyecto1Parser.y"
    { (yyval.treeNode) = createTreeNode(yylineno, "Type", 3, (yyvsp[-2].treeNode), tN("["), tN("]")); }
#line 1746 "proyecto1Parser.tab.c"
    break;

  case 17:
#line 158 "proyecto1Parser.y"
    { (yyval.treeNode) = createTreeNode(yylineno, "FunctionDecl", 5, (yyvsp[-4].treeNode), tN("("), (yyvsp[-2].treeNode), tN(")"), (yyvsp[0].treeNode)); }
#line 1752 "proyecto1Parser.tab.c"
    break;

  case 18:
#line 161 "proyecto1Parser.y"
    { (yyval.treeNode) = createTreeNode(yylineno, "FunctionName", 2, (yyvsp[-1].treeNode), tT(yylval.str, "ID")); }
#line 1758 "proyecto1Parser.tab.c"
    break;

  case 19:
#line 162 "proyecto1Parser.y"
    { (yyval.treeNode) = createTreeNode(yylineno, "FunctionName", 2, tN("void"), tT(yylval.str, "ID")); }
#line 1764 "proyecto1Parser.tab.c"
    break;

  case 20:
#line 165 "proyecto1Parser.y"
    { (yyval.treeNode) = createTreeNode(yylineno, "Formals", 1, (yyvsp[0].treeNode)); }
#line 1770 "proyecto1Parser.tab.c"
    break;

  case 21:
#line 166 "proyecto1Parser.y"
    { (yyval.treeNode) = eN(); }
#line 1776 "proyecto1Parser.tab.c"
    break;

  case 22:
#line 169 "proyecto1Parser.y"
    { (yyval.treeNode) = createTreeNode(yylineno, "Variables", 1, (yyvsp[0].treeNode));
                                            struct TreeNode * variable = (yyvsp[0].treeNode);
                                            struct SymbolNode * newSymbol = createSymbol(variable);
                                            newSymbol->parameter = 1;
                                            symbolList = insertSymbolNode(symbolList, newSymbol);
                                          }
#line 1787 "proyecto1Parser.tab.c"
    break;

  case 23:
#line 175 "proyecto1Parser.y"
    { (yyval.treeNode) = createTreeNode(yylineno, "Variables", 3, (yyvsp[-2].treeNode), tN(","), (yyvsp[0].treeNode)); }
#line 1793 "proyecto1Parser.tab.c"
    break;

  case 24:
#line 178 "proyecto1Parser.y"
    { (yyval.treeNode) = createTreeNode(yylineno, "ClassDecl", 6, (yyvsp[-5].treeNode), (yyvsp[-4].treeNode), (yyvsp[-3].treeNode), tN("{"), (yyvsp[-1].treeNode), tN("}"));
                                                                    struct Scope * newScope = createScope((yyvsp[-5].treeNode)->root->next->node->value, "Class");
                                                                    newScope = insertSymbol(newScope, symbolClass);
                                                                    newScope = setFScope(newScope, scopeList);
                                                                    newScope = setPScope(newScope, scopeList);
                                                                    newScope = setTree(newScope, (yyval.treeNode));
                                                                    struct ScopeNode * newNode = createScopeNode(newScope);
                                                                    classList = insertScopeNode(classList, newNode);
                                                                    scopeList = 0;
                                                                    symbolClass = 0;
                                                                    struct Scope * newScopeExtend = createScope((yyvsp[-5].treeNode)->root->next->node->value, "Class");
                                                                    newScopeExtend = insertSymbol(newScopeExtend, symbolExtends);
                                                                    struct ScopeNode * newNodeExtend = createScopeNode(newScopeExtend);
                                                                    scopeExtends = insertScopeNode(scopeExtends, newNodeExtend);
                                                                    symbolExtends = 0;
                                                                  }
#line 1814 "proyecto1Parser.tab.c"
    break;

  case 25:
#line 196 "proyecto1Parser.y"
    {(yyval.treeNode) = createTreeNode(yylineno, "ClassName", 2, tN("Class"), tT(yylval.str, "ID"));}
#line 1820 "proyecto1Parser.tab.c"
    break;

  case 26:
#line 199 "proyecto1Parser.y"
    { (yyval.treeNode) = createTreeNode(yylineno, "Extend", 2, tN("extends"), tT(yylval.str, "ID"));
                              struct SymbolNode * newSymbol = createSymbolNode("extend", yylval.str);
                              symbolExtends = insertSymbolNode(symbolExtends, newSymbol);
                            }
#line 1829 "proyecto1Parser.tab.c"
    break;

  case 27:
#line 203 "proyecto1Parser.y"
    { (yyval.treeNode) = eN(); }
#line 1835 "proyecto1Parser.tab.c"
    break;

  case 28:
#line 206 "proyecto1Parser.y"
    { (yyval.treeNode) = createTreeNode(yylineno, "Implement", 2, tN("implements"), (yyvsp[0].treeNode));
                                        struct SymbolNode * newSymbol = createSymbolNode("implement", yylval.str);
                                        symbolExtends = insertSymbolNode(symbolExtends, newSymbol);
                                      }
#line 1844 "proyecto1Parser.tab.c"
    break;

  case 29:
#line 210 "proyecto1Parser.y"
    { (yyval.treeNode) = eN(); }
#line 1850 "proyecto1Parser.tab.c"
    break;

  case 30:
#line 213 "proyecto1Parser.y"
    { (yyval.treeNode) = createTreeNode(yylineno, "ListIdents", 1, tT(yylval.str, "ID")); }
#line 1856 "proyecto1Parser.tab.c"
    break;

  case 31:
#line 214 "proyecto1Parser.y"
    { (yyval.treeNode) = createTreeNode(yylineno, "ListIdents", 3, (yyvsp[-2].treeNode), tN(","), tT(yylval.str, "ID")); }
#line 1862 "proyecto1Parser.tab.c"
    break;

  case 32:
#line 217 "proyecto1Parser.y"
    { (yyval.treeNode) = createTreeNode(yylineno, "Fields", 2, (yyvsp[-1].treeNode), (yyvsp[0].treeNode)); }
#line 1868 "proyecto1Parser.tab.c"
    break;

  case 33:
#line 218 "proyecto1Parser.y"
    { (yyval.treeNode) = eN(); }
#line 1874 "proyecto1Parser.tab.c"
    break;

  case 34:
#line 221 "proyecto1Parser.y"
    { (yyval.treeNode) = createTreeNode(yylineno, "Field", 1, (yyvsp[0].treeNode));
                                struct TreeNode * variable = (yyvsp[0].treeNode)->root->node;
                                struct SymbolNode * newSymbol = createSymbol(variable);
                                symbolClass = insertSymbolNode(symbolClass, newSymbol);
                              }
#line 1884 "proyecto1Parser.tab.c"
    break;

  case 35:
#line 226 "proyecto1Parser.y"
    { (yyval.treeNode) = createTreeNode(yylineno, "Field", 1, (yyvsp[0].treeNode)); 
                                struct Scope * newScope = createScope((yyvsp[0].treeNode)->root->node->root->next->node->value, "Function");
                                newScope = insertSymbol(newScope, symbolList);
                                newScope = setTree(newScope, (yyvsp[0].treeNode));
                                struct ScopeNode * newNode = createScopeNode(newScope);
                                scopeList = insertScopeNode(scopeList, newNode);
                                symbolList = 0;
                              }
#line 1897 "proyecto1Parser.tab.c"
    break;

  case 36:
#line 236 "proyecto1Parser.y"
    { (yyval.treeNode) = createTreeNode(yylineno, "InterfaceDecl", 4, (yyvsp[-3].treeNode), tN("{"), (yyvsp[-1].treeNode), tN("}"));
                                                            struct Scope * newScope = createScope((yyvsp[-3].treeNode)->root->next->node->value, "Interface");
                                                            newScope = setFScope(newScope, scopeList);
                                                            newScope = setPScope(newScope, scopeList);
                                                            newScope = setTree(newScope, (yyval.treeNode));
                                                            struct ScopeNode * newNode = createScopeNode(newScope);
                                                            classList = insertScopeNode(classList, newNode);
                                                            scopeList = 0;
                                                            struct Scope * newScopeExtend = createScope((yyvsp[-3].treeNode)->root->next->node->value, "Interface");
                                                            newScopeExtend = insertSymbol(newScopeExtend, symbolExtends);
                                                            struct ScopeNode * newNodeExtend = createScopeNode(newScopeExtend);
                                                            scopeExtends = insertScopeNode(scopeExtends, newNodeExtend);
                                                            symbolExtends = 0;
                                                          }
#line 1916 "proyecto1Parser.tab.c"
    break;

  case 37:
#line 252 "proyecto1Parser.y"
    { (yyval.treeNode) = createTreeNode(yylineno, "InterfaceName", 2, tN("interface"), tT(yylval.str, "ID")); }
#line 1922 "proyecto1Parser.tab.c"
    break;

  case 38:
#line 255 "proyecto1Parser.y"
    { (yyval.treeNode) = createTreeNode(yylineno, "Prototypes", 2, (yyvsp[-1].treeNode), (yyvsp[0].treeNode)); }
#line 1928 "proyecto1Parser.tab.c"
    break;

  case 39:
#line 256 "proyecto1Parser.y"
    { (yyval.treeNode) = eN(); }
#line 1934 "proyecto1Parser.tab.c"
    break;

  case 40:
#line 259 "proyecto1Parser.y"
    { (yyval.treeNode) = createTreeNode(yylineno, "Prototype", 5, (yyvsp[-4].treeNode), tN("("), (yyvsp[-2].treeNode), tN(")"), tN(";"));
                                                                  struct Scope * newScope = createScope((yyvsp[-4].treeNode)->root->next->node->value, "Function");
                                                                  struct ScopeNode * newNode = createScopeNode(newScope);
                                                                  scopeList = insertScopeNode(scopeList, newNode);
                                                                }
#line 1944 "proyecto1Parser.tab.c"
    break;

  case 41:
#line 266 "proyecto1Parser.y"
    { (yyval.treeNode) = createTreeNode(yylineno, "PrototypeName", 2, (yyvsp[-1].treeNode), tT(yylval.str, "ID")); }
#line 1950 "proyecto1Parser.tab.c"
    break;

  case 42:
#line 267 "proyecto1Parser.y"
    { (yyval.treeNode) = createTreeNode(yylineno, "PrototypeName", 2, tN("void"), tT(yylval.str, "ID")); }
#line 1956 "proyecto1Parser.tab.c"
    break;

  case 43:
#line 270 "proyecto1Parser.y"
    { (yyval.treeNode) = createTreeNode(yylineno, "StmtBlock", 3, tN("{"), (yyvsp[-1].treeNode), tN("}")); }
#line 1962 "proyecto1Parser.tab.c"
    break;

  case 44:
#line 273 "proyecto1Parser.y"
    { (yyval.treeNode) = createTreeNode(yylineno, "Stmts", 2, (yyvsp[-1].treeNode), (yyvsp[0].treeNode)); }
#line 1968 "proyecto1Parser.tab.c"
    break;

  case 45:
#line 274 "proyecto1Parser.y"
    { (yyval.treeNode) = eN(); }
#line 1974 "proyecto1Parser.tab.c"
    break;

  case 46:
#line 277 "proyecto1Parser.y"
    { (yyval.treeNode) = createTreeNode(yylineno, "Stmt", 1, (yyvsp[0].treeNode)); }
#line 1980 "proyecto1Parser.tab.c"
    break;

  case 47:
#line 278 "proyecto1Parser.y"
    { (yyval.treeNode) = createTreeNode(yylineno, "Stmt", 1, (yyvsp[0].treeNode)); }
#line 1986 "proyecto1Parser.tab.c"
    break;

  case 48:
#line 279 "proyecto1Parser.y"
    { (yyval.treeNode) = createTreeNode(yylineno, "Stmt", 1, (yyvsp[0].treeNode)); }
#line 1992 "proyecto1Parser.tab.c"
    break;

  case 49:
#line 280 "proyecto1Parser.y"
    { (yyval.treeNode) = createTreeNode(yylineno, "Stmt", 1, (yyvsp[0].treeNode)); }
#line 1998 "proyecto1Parser.tab.c"
    break;

  case 50:
#line 281 "proyecto1Parser.y"
    { (yyval.treeNode) = createTreeNode(yylineno, "Stmt", 1, (yyvsp[0].treeNode)); }
#line 2004 "proyecto1Parser.tab.c"
    break;

  case 51:
#line 282 "proyecto1Parser.y"
    { (yyval.treeNode) = createTreeNode(yylineno, "Stmt", 1, (yyvsp[0].treeNode)); }
#line 2010 "proyecto1Parser.tab.c"
    break;

  case 52:
#line 283 "proyecto1Parser.y"
    { (yyval.treeNode) = createTreeNode(yylineno, "Stmt", 1, (yyvsp[0].treeNode)); }
#line 2016 "proyecto1Parser.tab.c"
    break;

  case 53:
#line 284 "proyecto1Parser.y"
    { (yyval.treeNode) = createTreeNode(yylineno, "Stmt", 1, (yyvsp[0].treeNode)); }
#line 2022 "proyecto1Parser.tab.c"
    break;

  case 54:
#line 285 "proyecto1Parser.y"
    { (yyval.treeNode) = createTreeNode(yylineno, "Stmt", 1, (yyvsp[0].treeNode));
                                struct TreeNode * variable = (yyvsp[0].treeNode)->root->node;
                                struct SymbolNode * newSymbol = createSymbol(variable);
                                symbolList = insertSymbolNode(symbolList, newSymbol);
                              }
#line 2032 "proyecto1Parser.tab.c"
    break;

  case 55:
#line 292 "proyecto1Parser.y"
    { (yyval.treeNode) = createTreeNode(yylineno, "PossibleExpr", 1, (yyvsp[0].treeNode)); }
#line 2038 "proyecto1Parser.tab.c"
    break;

  case 56:
#line 293 "proyecto1Parser.y"
    { (yyval.treeNode) = eN(); }
#line 2044 "proyecto1Parser.tab.c"
    break;

  case 57:
#line 296 "proyecto1Parser.y"
    { (yyval.treeNode) = createTreeNode(yylineno, "IfStmt", 6, tN("if"), tN("("), (yyvsp[-3].treeNode), tN(")"), (yyvsp[-1].treeNode), (yyvsp[0].treeNode)); }
#line 2050 "proyecto1Parser.tab.c"
    break;

  case 58:
#line 299 "proyecto1Parser.y"
    { (yyval.treeNode) = createTreeNode(yylineno, "Else", 2, tN("else"), (yyvsp[0].treeNode)); }
#line 2056 "proyecto1Parser.tab.c"
    break;

  case 59:
#line 300 "proyecto1Parser.y"
    { (yyval.treeNode) = eN(); }
#line 2062 "proyecto1Parser.tab.c"
    break;

  case 60:
#line 303 "proyecto1Parser.y"
    { (yyval.treeNode) = createTreeNode(yylineno, "WhileStmt", 5, tN("while"), tN("("), (yyvsp[-2].treeNode), tN(")"), (yyvsp[0].treeNode)); }
#line 2068 "proyecto1Parser.tab.c"
    break;

  case 61:
#line 306 "proyecto1Parser.y"
    { (yyval.treeNode) = createTreeNode(yylineno, "ForStmt", 9, tN("for"), tN("("), (yyvsp[-6].treeNode), tN(";"), (yyvsp[-4].treeNode), tN(";"), (yyvsp[-2].treeNode), tN(")"), (yyvsp[0].treeNode)); }
#line 2074 "proyecto1Parser.tab.c"
    break;

  case 62:
#line 309 "proyecto1Parser.y"
    { (yyval.treeNode) = createTreeNode(yylineno, "ReturnStmt", 3, tN("return"), (yyvsp[-1].treeNode), tN(";")); }
#line 2080 "proyecto1Parser.tab.c"
    break;

  case 63:
#line 312 "proyecto1Parser.y"
    { (yyval.treeNode) = createTreeNode(yylineno, "BreakStmt", 2, tN("break"), tN(";")); }
#line 2086 "proyecto1Parser.tab.c"
    break;

  case 64:
#line 315 "proyecto1Parser.y"
    { (yyval.treeNode) = createTreeNode(yylineno, "PrintStmt", 5, tN("print"), tN("("), (yyvsp[-2].treeNode), tN(")"), tN(";")); }
#line 2092 "proyecto1Parser.tab.c"
    break;

  case 65:
#line 318 "proyecto1Parser.y"
    { (yyval.treeNode) = createTreeNode(yylineno, "ListExpr", 1, (yyvsp[0].treeNode)); }
#line 2098 "proyecto1Parser.tab.c"
    break;

  case 66:
#line 319 "proyecto1Parser.y"
    { (yyval.treeNode) = createTreeNode(yylineno, "ListExpr", 3, (yyvsp[-2].treeNode), tN(","), (yyvsp[0].treeNode)); }
#line 2104 "proyecto1Parser.tab.c"
    break;

  case 67:
#line 322 "proyecto1Parser.y"
    { (yyval.treeNode) = createTreeNode(yylineno, "Expr", 3, (yyvsp[-2].treeNode), tN("="), (yyvsp[0].treeNode)); }
#line 2110 "proyecto1Parser.tab.c"
    break;

  case 68:
#line 323 "proyecto1Parser.y"
    { (yyval.treeNode) = createTreeNode(yylineno, "Expr", 1, (yyvsp[0].treeNode)); }
#line 2116 "proyecto1Parser.tab.c"
    break;

  case 69:
#line 324 "proyecto1Parser.y"
    { (yyval.treeNode) = createTreeNode(yylineno, "Expr", 1, (yyvsp[0].treeNode)); }
#line 2122 "proyecto1Parser.tab.c"
    break;

  case 70:
#line 325 "proyecto1Parser.y"
    { (yyval.treeNode) = createTreeNode(yylineno, "Expr", 1, tN("this")); }
#line 2128 "proyecto1Parser.tab.c"
    break;

  case 71:
#line 326 "proyecto1Parser.y"
    { (yyval.treeNode) = createTreeNode(yylineno, "Expr", 1, (yyvsp[0].treeNode)); }
#line 2134 "proyecto1Parser.tab.c"
    break;

  case 72:
#line 327 "proyecto1Parser.y"
    { (yyval.treeNode) = createTreeNode(yylineno, "Expr", 3, tN("("), (yyvsp[-1].treeNode), tN(")")); }
#line 2140 "proyecto1Parser.tab.c"
    break;

  case 73:
#line 328 "proyecto1Parser.y"
    { (yyval.treeNode) = createTreeNode(yylineno, "Expr", 3, (yyvsp[-2].treeNode), tN("+"), (yyvsp[0].treeNode)); }
#line 2146 "proyecto1Parser.tab.c"
    break;

  case 74:
#line 329 "proyecto1Parser.y"
    { (yyval.treeNode) = createTreeNode(yylineno, "Expr", 3, (yyvsp[-2].treeNode), tN("-"), (yyvsp[0].treeNode)); }
#line 2152 "proyecto1Parser.tab.c"
    break;

  case 75:
#line 330 "proyecto1Parser.y"
    { (yyval.treeNode) = createTreeNode(yylineno, "Expr", 3, (yyvsp[-2].treeNode), tN("*"), (yyvsp[0].treeNode)); }
#line 2158 "proyecto1Parser.tab.c"
    break;

  case 76:
#line 331 "proyecto1Parser.y"
    { (yyval.treeNode) = createTreeNode(yylineno, "Expr", 3, (yyvsp[-2].treeNode), tN("/"), (yyvsp[0].treeNode)); }
#line 2164 "proyecto1Parser.tab.c"
    break;

  case 77:
#line 332 "proyecto1Parser.y"
    { (yyval.treeNode) = createTreeNode(yylineno, "Expr", 3, (yyvsp[-2].treeNode), tN("mod"), (yyvsp[0].treeNode)); }
#line 2170 "proyecto1Parser.tab.c"
    break;

  case 78:
#line 333 "proyecto1Parser.y"
    { (yyval.treeNode) = createTreeNode(yylineno, "Expr", 2, tN("-"), (yyvsp[0].treeNode)); }
#line 2176 "proyecto1Parser.tab.c"
    break;

  case 79:
#line 334 "proyecto1Parser.y"
    { (yyval.treeNode) = createTreeNode(yylineno, "Expr", 3, (yyvsp[-2].treeNode), tN("<"), (yyvsp[0].treeNode)); }
#line 2182 "proyecto1Parser.tab.c"
    break;

  case 80:
#line 335 "proyecto1Parser.y"
    { (yyval.treeNode) = createTreeNode(yylineno, "Expr", 3, (yyvsp[-2].treeNode), tN("<="), (yyvsp[0].treeNode)); }
#line 2188 "proyecto1Parser.tab.c"
    break;

  case 81:
#line 336 "proyecto1Parser.y"
    { (yyval.treeNode) = createTreeNode(yylineno, "Expr", 3, (yyvsp[-2].treeNode), tN(">"), (yyvsp[0].treeNode)); }
#line 2194 "proyecto1Parser.tab.c"
    break;

  case 82:
#line 337 "proyecto1Parser.y"
    { (yyval.treeNode) = createTreeNode(yylineno, "Expr", 3, (yyvsp[-2].treeNode), tN(">="), (yyvsp[0].treeNode)); }
#line 2200 "proyecto1Parser.tab.c"
    break;

  case 83:
#line 338 "proyecto1Parser.y"
    { (yyval.treeNode) = createTreeNode(yylineno, "Expr", 3, (yyvsp[-2].treeNode), tN("=="), (yyvsp[0].treeNode)); }
#line 2206 "proyecto1Parser.tab.c"
    break;

  case 84:
#line 339 "proyecto1Parser.y"
    { (yyval.treeNode) = createTreeNode(yylineno, "Expr", 3, (yyvsp[-2].treeNode), tN("!="), (yyvsp[0].treeNode)); }
#line 2212 "proyecto1Parser.tab.c"
    break;

  case 85:
#line 340 "proyecto1Parser.y"
    { (yyval.treeNode) = createTreeNode(yylineno, "Expr", 3, (yyvsp[-2].treeNode), tN("&&"), (yyvsp[0].treeNode)); }
#line 2218 "proyecto1Parser.tab.c"
    break;

  case 86:
#line 341 "proyecto1Parser.y"
    { (yyval.treeNode) = createTreeNode(yylineno, "Expr", 3, (yyvsp[-2].treeNode), tN("||"), (yyvsp[0].treeNode)); }
#line 2224 "proyecto1Parser.tab.c"
    break;

  case 87:
#line 342 "proyecto1Parser.y"
    { (yyval.treeNode) = createTreeNode(yylineno, "Expr", 2, tN("!"), (yyvsp[0].treeNode)); }
#line 2230 "proyecto1Parser.tab.c"
    break;

  case 88:
#line 343 "proyecto1Parser.y"
    { (yyval.treeNode) = createTreeNode(yylineno, "Expr", 3, tN("readInteger"), tN("("), tN(")")); }
#line 2236 "proyecto1Parser.tab.c"
    break;

  case 89:
#line 344 "proyecto1Parser.y"
    { (yyval.treeNode) = createTreeNode(yylineno, "Expr", 3, tN("readLine"), tN("("), tN(")")); }
#line 2242 "proyecto1Parser.tab.c"
    break;

  case 90:
#line 345 "proyecto1Parser.y"
    { (yyval.treeNode) = createTreeNode(yylineno, "Expr", 4, tN("new"), tN("("), tT(yylval.str, "ID"), tN(")")); }
#line 2248 "proyecto1Parser.tab.c"
    break;

  case 91:
#line 346 "proyecto1Parser.y"
    { (yyval.treeNode) = createTreeNode(yylineno, "Expr", 6, tN("newArray"), tN("("), (yyvsp[-3].treeNode), tN(","), (yyvsp[-1].treeNode), tN(")")); }
#line 2254 "proyecto1Parser.tab.c"
    break;

  case 92:
#line 349 "proyecto1Parser.y"
    { (yyval.treeNode) = createTreeNode(yylineno, "LValue", 1, tT(yylval.str, "ID")); }
#line 2260 "proyecto1Parser.tab.c"
    break;

  case 93:
#line 350 "proyecto1Parser.y"
    { (yyval.treeNode) = createTreeNode(yylineno, "LValue", 3, (yyvsp[-2].treeNode), tN("."), tT(yylval.str, "ID")); }
#line 2266 "proyecto1Parser.tab.c"
    break;

  case 94:
#line 351 "proyecto1Parser.y"
    { (yyval.treeNode) = createTreeNode(yylineno, "LValue", 4, (yyvsp[-2].treeNode)->root->node, (yyvsp[-2].treeNode)->root->next->node, (yyvsp[-1].treeNode), tN("]")); }
#line 2272 "proyecto1Parser.tab.c"
    break;

  case 95:
#line 354 "proyecto1Parser.y"
    { (yyval.treeNode) = createTreeNode(yylineno, "FixLValue", 2, tT(yylval.str, "ID"), tN("[")); }
#line 2278 "proyecto1Parser.tab.c"
    break;

  case 96:
#line 357 "proyecto1Parser.y"
    { (yyval.treeNode) = createTreeNode(yylineno, "Call", 4, tT(yylval.str, "ID"), tN("("), (yyvsp[-1].treeNode), tN(")")); }
#line 2284 "proyecto1Parser.tab.c"
    break;

  case 97:
#line 358 "proyecto1Parser.y"
    { (yyval.treeNode) = createTreeNode(yylineno, "Call", 6, (yyvsp[-5].treeNode), tN("."), tT(yylval.str, "ID"), tN("("), (yyvsp[-1].treeNode), tN(")")); }
#line 2290 "proyecto1Parser.tab.c"
    break;

  case 98:
#line 361 "proyecto1Parser.y"
    { (yyval.treeNode) = createTreeNode(yylineno, "Actuals", 1, (yyvsp[0].treeNode)); }
#line 2296 "proyecto1Parser.tab.c"
    break;

  case 99:
#line 362 "proyecto1Parser.y"
    { (yyval.treeNode) = eN(); }
#line 2302 "proyecto1Parser.tab.c"
    break;

  case 100:
#line 365 "proyecto1Parser.y"
    { (yyval.treeNode) = createTreeNode(yylineno, "Constant", 1, tT(yylval.str, "integer")); }
#line 2308 "proyecto1Parser.tab.c"
    break;

  case 101:
#line 366 "proyecto1Parser.y"
    { (yyval.treeNode) = createTreeNode(yylineno, "Constant", 1, tT(yylval.str, "double")); }
#line 2314 "proyecto1Parser.tab.c"
    break;

  case 102:
#line 367 "proyecto1Parser.y"
    { (yyval.treeNode) = createTreeNode(yylineno, "Constant", 1, tT("true", "boolean")); }
#line 2320 "proyecto1Parser.tab.c"
    break;

  case 103:
#line 368 "proyecto1Parser.y"
    { (yyval.treeNode) = createTreeNode(yylineno, "Constant", 1, tT("false", "boolean")); }
#line 2326 "proyecto1Parser.tab.c"
    break;

  case 104:
#line 369 "proyecto1Parser.y"
    { (yyval.treeNode) = createTreeNode(yylineno, "Constant", 1, tT(yylval.str, "string")); }
#line 2332 "proyecto1Parser.tab.c"
    break;

  case 105:
#line 370 "proyecto1Parser.y"
    { (yyval.treeNode) = createTreeNode(yylineno, "Constant", 1, tT("null", "null")); }
#line 2338 "proyecto1Parser.tab.c"
    break;


#line 2342 "proyecto1Parser.tab.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;
  *++yylsp = yyloc;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }

  yyerror_range[1] = yylloc;

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval, &yylloc);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;

      yyerror_range[1] = *yylsp;
      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp, yylsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  yyerror_range[2] = yylloc;
  /* Using YYLLOC is tempting, but would change the location of
     the lookahead.  YYLOC is available though.  */
  YYLLOC_DEFAULT (yyloc, yyerror_range, 2);
  *++yylsp = yyloc;

  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;


#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif


/*-----------------------------------------------------.
| yyreturn -- parsing is finished, return the result.  |
`-----------------------------------------------------*/
yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval, &yylloc);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp, yylsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 373 "proyecto1Parser.y"


int main() {
  //Variables
  globalScope = 0;
  classList = 0;
  scopeList = 0;
  symbolList = 0;
  symbolClass = 0;
  symbolGlobal = 0;
  symbolExtends = 0;
  scopeExtends = 0;
  functionsGlobal = 0;
  tree = 0;
  //Parser
  yyin = stdin;
  do {
    yyparse();
	} while(!feof(yyin));
  adjustFScope();
  probarMetodo(tree, 0);
	return 0;
}

void yyerror(char *s) {
  fprintf(stderr,"Error | Line: %d\n%s\n",yylineno,s);
}

struct SymbolNode * createSymbol(struct TreeNode * variable) {
  struct ListNode * root = variable->root;
  char * id = root->next->node->value;
  return createSymbolAux(root->node, id, 0);
}

struct SymbolNode * createSymbolAux(struct TreeNode * type, char * id, int dimension) {
  struct ListNode * root = type->root;
  int size = listSize(root);
  if(size > 1) {
    return createSymbolAux(root->node, id, dimension + 1);
  }
  else {
    struct SymbolNode * node = createSymbolNode(root->node->value, id);
    node = setArray(node, dimension);
    return node;
  }
}

//Validation Functions

void adjustFScope() {
  struct ScopeNode * list = scopeExtends;
  int size = sizeScopeList(list);
  for(int i = 0; i < size; i++) {
    struct Scope * scope = list->value;
    struct SymbolNode * root = scope->root;
    int length = sizeSymbol(root);
    for(int j = 0; j < length; j++) {
      if(strcmp("extend", root->type) == 0) {
        if(checkClass(scope->id) && checkClass(root->id)) {
          struct Scope * fScope = getScopeClass(root->id);
          struct Scope * pScope = getScopeClass(scope->id);
          pScope->fScope = fScope;
        }
      }
      root = root->next;
    }
    list = list->next;
  }
}

struct Scope * getScope(struct TreeNode * node) {
  return getScopeAux(node, globalScope);
};

struct Scope * getScopeAux(struct TreeNode * node, struct Scope * scope) {
  struct TreeNode * treeScope = scope->tree;
  if(treeScope == node) {
    return scope;
  }
  else {
    struct ScopeNode * scopes = scope->pScope;
    int size = sizeScopeList(scopes);
    for(int i = 0; i < size; i++) {
      struct Scope * value = scopes->value;
      struct Scope * res = getScopeAux(node, value);
      if(res) {
        return res;
      }
      scopes = scopes->next;
    }
    return 0;
  }
};

struct Scope * checkClass(char * id) {
  int size = sizeScopeList(scopeExtends);
  struct ScopeNode * temp = scopeExtends;
  for(int i = 0; i < size; i++) {
    struct Scope * scope = temp->value;
    if(strcmp(id, scope->id) == 0) {
      return scope;
    }
    temp = temp->next;
  }
  return 0;
};

struct Scope * getScopeClass(char * id) {
  struct ScopeNode * list = globalScope->pScope;
  int size = sizeScopeList(list);
  for(int i = 0; i < size; i++) {
    struct Scope * scope = list->value;
    if(strcmp(id, scope->id) == 0 && (strcmp(scope->type, "Class") == 0 || strcmp(scope->type, "Interface") == 0) ) {
      return scope;
    }
    list = list->next;
  }
  return 0;
};

int checkSubClass(char * class, char * subClass) {
  struct Scope * scopeClass = checkClass(subClass);
  if(checkClass(class) && scopeClass) {
    struct SymbolNode * temp = scopeClass->root;
    int size = sizeSymbol(temp);
    for(int i = 0; i < size; i++) {
      if(strcmp(class, temp->id) == 0) {
        return 1;
      }
      if(strcmp("Class", temp->type) == 0) {
        int check = checkSubClass(temp->id, subClass);
        if(check) {
          return 1;
        }
      }
      temp = temp->next;
    }
  }
  return 0;
};

struct SymbolNode * getTypeId(char * id, struct Scope * scope) {
  struct SymbolNode * root = scope->root;
  int size = sizeSymbol(root);
  for(int i = 0; i < size; i++) {
    if(strcmp(root->id, id) == 0) {
      return root;
    }
    root = root->next;
  }
  if(strcmp("global", scope->id) == 0) {
    return 0;
  }
  else {
    return getTypeId(id, scope->fScope);
  }
};

struct SymbolNode * getTypeFunction(char * id, struct Scope * scope) {
  struct ScopeNode * list = scope->pScope;
  int size = sizeScopeList(list);
  for(int i = 0; i < size; i++) {
    struct Scope * value = list->value;
    if(strcmp(id, value->id) == 0 && strcmp("Function", value->type) == 0) {
      struct TreeNode * node = value->tree;
      struct TreeNode * functionName = node->root->node;
      char * name = functionName->root->next->node->value;
      if(strcmp("Terminal", functionName->root->node->type) == 0) {
        struct SymbolNode * res = createSymbolNode(functionName->root->node->value, name);
        return res;
      }
      else {
        struct SymbolNode * res = createSymbolAux(functionName->root->node, name, 0);
        return res;
      }
    }
    list = list->next;
  }
  if(strcmp("global", scope->id) == 0) {
    return 0;
  }
  else {
    return getTypeFunction(id, scope->fScope);
  }
};

char * getTypeConstant(struct TreeNode * node) {
  struct TreeNode * terminal = node->root->node;
  return terminal->type;
};

char * getValueConstant(struct TreeNode * node) {
  struct TreeNode * terminal = node->root->node;
  return terminal->value;
};

char * getTypeReturn(struct TreeNode * node, struct Scope * actualScope) {
  struct ListNode * list = node->root;
  int size = listSize(list);
  if(size == 2) {
    return "void";
  }
  else {
    struct TreeNode * possibleExpr = list->next->node;
    struct TreeNode * expr = possibleExpr->root->node;
    return getTypeExpr(expr, actualScope);
  } 
};

char * getTypeExpr(struct TreeNode * node, struct Scope * actualScope) {
  struct ListNode * list = node->root;
  int size = listSize(list);
  if(size == 1) {
    struct TreeNode * value = list->node;
    if(strcmp("Terminal", value->type) == 0) {
      if(actualScope->fScope) {
        return actualScope->fScope->id;
      }
      else {
        return "This fuera de scope";
      }
    }
    else if(strcmp("Constant", value->type) == 0) {
      return getTypeConstant(value);
    }
    else if(strcmp("LValue", value->type) == 0) {
      return getTypeLValue(value, actualScope);
    }
    else {
      return getTypeCall(value, actualScope);
    }
  }
  else if(size == 2) {
    char * typeReturn = getTypeExpr(list->next->node, actualScope);
    if(strcmp("!", list->node->value) == 0) {
      if(strcmp(typeReturn, "boolean") == 0) {
        return "boolean";
      }
      else {
        return "Tipo invalido, debe ser boolean";
      }
    }
    else {
      if(strcmp(typeReturn, "integer") == 0) {
        return "integer";
      }
      else if(strcmp(typeReturn, "double") == 0) {
        return "double";
      }
      else {
        return "Tipo invalido, debe ser int o double";
      }
    }
  }
  else if(size == 3) {
    struct TreeNode * terminal = list->next->node;
    if(strcmp("+", terminal->value) == 0 || strcmp("-", terminal->value) == 0 || strcmp("*", terminal->value) == 0 || strcmp("/", terminal->value) == 0 || strcmp("mod", terminal->value) == 0) {
      char * typeExpr1 = getTypeExpr(list->node, actualScope);
      char * typeExpr2 = getTypeExpr(list->next->next->node, actualScope);
      if(strcmp("integer", typeExpr1) == 0 || strcmp("double", typeExpr1) == 0) {
        if(strcmp("integer", typeExpr2) == 0 || strcmp("double", typeExpr2) == 0) {
          return typeExpr1;
        }
        else {
          return "Segundo tipo invalido en operacion";
        }
      }
      else {
        return "Primer tipo invalido en operacion";
      }
    }
    else if(strcmp("<", terminal->value) == 0 || strcmp("<=", terminal->value) == 0 || strcmp(">", terminal->value) == 0 || strcmp(">=", terminal->value) == 0) {
      char * typeExpr1 = getTypeExpr(list->node, actualScope);
      char * typeExpr2 = getTypeExpr(list->next->next->node, actualScope);
      if(strcmp("integer", typeExpr1) == 0 || strcmp("double", typeExpr1) == 0) {
        if(strcmp("integer", typeExpr2) == 0 || strcmp("double", typeExpr2) == 0) {
          return "boolean";
        }
        else {
          return "Segundo tipo invalido en comparacion de tamano";
        }
      }
      else {
        return "Primer tipo invalido en comparacion de tamano";
      }
    }
    else if(strcmp("==", terminal->value) == 0 || strcmp("!=", terminal->value) == 0) {
      char * typeExpr1 = getTypeExpr(list->node, actualScope);
      char * typeExpr2 = getTypeExpr(list->next->next->node, actualScope);
      if(strcmp(typeExpr2, typeExpr1) == 0) {
        if(strcmp("void", typeExpr2) != 0) {
          return "boolean";
        }
        else {
          return "Segundo tipo invalido en comparacion de tipo";
        }
      }
      else {
        return "Primer tipo invalido en comparacion de tipo";
      }
    }
    else if(strcmp("||", terminal->value) == 0 || strcmp("&&", terminal->value) == 0) {
      char * typeExpr1 = getTypeExpr(list->node, actualScope);
      char * typeExpr2 = getTypeExpr(list->next->next->node, actualScope);
      if(strcmp(typeExpr2, typeExpr1) == 0) {
        if(strcmp("boolean", typeExpr2) == 0) {
          return "boolean";
        }
        else {
          return "Las expresiones deben ser booleanas";
        }
      }
      else {
        return "Las expresiones deben ser del mismo tipo";
      }
    }
    else if(strcmp("(", list->node->value) == 0 ) {
      return getTypeExpr(list->next->node, actualScope);
    }
    else {
      char * typeLValue = getTypeLValue(list->node, actualScope);
      char * typeExpr = getTypeExpr(list->next->next->node, actualScope);
      if(strcmp("integer", typeLValue) == 0 || strcmp("boolean", typeLValue) == 0 || strcmp("double", typeLValue) == 0 || strcmp("string", typeLValue) == 0 || checkClass(typeLValue)) {
        if(strcmp(typeExpr, "null") == 0 ||strcmp(typeExpr, typeLValue) == 0 || checkSubClass(typeExpr, typeLValue)) {
          return "void";
        }
        else {
          return "La asignacion debe ser del mismo tipo o de una clase padre";
        }
      }
      else {
        return "Primera parametro no puede ser void";
      }
    }
  }
  else {
    if(strcmp("readInteger", list->node->value) == 0 || strcmp("readLine", list->node->value) == 0) {
      return "void";
    }
    else if(strcmp("new", list->node->value) == 0) {
      struct Scope * checkScope = checkClass(list->next->next->node->value);
      if(checkScope) {
        return checkScope->id;
      }
      else {
        return "Clase o interfaz no existe";
      }
    }
    else {
      struct TreeNode * expr = list->next->next->node;
      char * typeExpr = getTypeExpr(expr, actualScope);
      if(strcmp("integer", typeExpr) == 0) {
        struct TreeNode * type = list->next->next->next->next->node;
        struct SymbolNode * symbol = createSymbolAux(type, "test", 0);
        return symbol->type;
      }
      else {
        return "El largo debe ser un tipo entero";
      }
    }
  }
};

char * getTypeLValue(struct TreeNode * node, struct Scope * actualScope) {
  struct ListNode * list = node->root;
  int size = listSize(list);
  if(size == 1) { 
    struct SymbolNode * symbol = getTypeId(list->node->value, actualScope);
    if(symbol) {
      return symbol->type;
    }
    else {
      return "Objeto no existe";
    }
  }
  else if(size == 3) {
    struct TreeNode * expr = list->node;
    char * typeReturn = getTypeExpr(expr, actualScope);
    struct Scope * objectScope = getScopeClass(typeReturn);
    if(objectScope) {
      char * id = list->next->next->node->value;
      struct SymbolNode * symbol = getTypeId(id, objectScope);
      if(symbol) {
        return symbol->type;
      }
      else {
        return "Atributo no existe";
      }
    }
    else {
      return "Objeto no existe";
    }
  }
  else {
    char * nodeId = list->node->value;
    struct SymbolNode * typeId = getTypeId(nodeId, actualScope);
    char * verifyReturn = getTypeExpr(list->next->next->node, actualScope);
    if(strcmp(verifyReturn, "integer") == 0) {
      if(typeId) {
        return typeId->type;
      }
      else {
        return "Variable no existe";
      }
    }
    else {
      return "Indice no valido";
    }
  }
};

char * getTypeCall(struct TreeNode * node, struct Scope * actualScope) {
  struct ListNode * list = node->root;
  int size = listSize(list);
  if(size == 4) {
    char * id = list->node->value;
    struct SymbolNode * res = getTypeFunction(id, actualScope);
    if(res) {
      return res->type;
    }
    else {
      return "Metodo no existe";
    }
  }
  else {
    struct TreeNode * expr = list->node;
    char * typeReturn = getTypeExpr(expr, actualScope);
    struct Scope * functionScope = getScopeClass(typeReturn);
    if(functionScope) {
      char * id = list->next->next->node->value;
      struct SymbolNode * symbol = getTypeFunction(id, functionScope);
      if(symbol) {
        return symbol->type;
      }
      else {
        return "Metodo de objeto no existe";
      }
    }
    else {
      return "Objeto no existe";
    }
  }
};

void probarMetodo(struct TreeNode * node, struct Scope * actualScope) {
  struct Scope * newScope = getScope(node);
  if(newScope) {
    actualScope = newScope;
  }
  if(strcmp(node->type, "Expr") == 0) {
    //printf("%s\n", getTypeExpr(node, actualScope));
  }
  if(strcmp(node->type, "ReturnStmt") == 0) {
    printf("%i\n", checkFunctionReturn(node, actualScope));
  }
  struct ListNode * temp = node->root;
  int size = listSize(temp);
  for(int i = 0; i < size; i++) {
    struct TreeNode * value = temp->node;
    probarMetodo(value, actualScope);
    temp = temp->next;
  }
};

int checkSymbolScope(struct Scope * scope) {
  struct SymbolNode * root = scope->root;
  int size = sizeSymbol(root);
  for(int i = 0; i < size; i++) {
    char * id = root->id;
    if(i < size - 2) {
      struct SymbolNode * temp = root->next;
      for(int j = i + 1; j < size; i++) {
        if(strcmp(id, temp->id) == 0) {
          return 0;
        }
        temp = temp->next;
      }
      root = root->next;
    }
  }
  return 1;
};

int checkFunctionReturn(struct TreeNode * returnNode, struct Scope * function) {
  struct SymbolNode * symbol = getTypeFunction(function->id, function->fScope);
  char * typeReturn = getTypeReturn(returnNode, function);
  if(symbol) {
    if(strcmp(typeReturn, symbol->type) == 0) {
      return 1;
    }
  }
  return 0;
};
