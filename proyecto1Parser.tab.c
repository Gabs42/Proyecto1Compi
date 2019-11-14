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
#include "tree.c"
#include "scopeList.c"

extern FILE* yyin;
extern int yylineno;
extern int yyparse();
void yyerror (char *s);
int yylex();
char* symbols[50][3]; 
int fila = 0;
struct TreeNode * parent;
struct SymbolNode * rootSymbol;
struct Scope * scopeActual;
struct ScopeNode * listScopes;


#line 94 "proyecto1Parser.tab.c"

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
    NULLVAL = 300,
    OR = 301,
    LESSEQL = 302,
    ID = 303,
    SUM = 304,
    SUB = 305,
    MULT = 306,
    DIV = 307,
    LESSTHN = 308,
    GREATERTHN = 309,
    MOD = 310,
    GREATEREQL = 311,
    EQUAL = 312,
    SAME = 313,
    DIFF = 314,
    AND = 315,
    NOT = 316
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 27 "proyecto1Parser.y"

  char* str;
	struct TreeNode * treeNode;
  int intval;
  struct SymbolNode * symbolNode;
  struct Scope * scope;

#line 207 "proyecto1Parser.tab.c"

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
#define YYFINAL  23
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   364

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  62
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  38
/* YYNRULES -- Number of rules.  */
#define YYNRULES  101
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  194

#define YYUNDEFTOK  2
#define YYMAXUTOK   316

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
      55,    56,    57,    58,    59,    60,    61
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    61,    61,    64,    65,    68,    69,    70,    71,    74,
      77,    83,    84,    85,    86,    87,    88,    91,   102,   103,
     106,   107,   110,   111,   114,   117,   120,   121,   124,   125,
     128,   129,   132,   133,   136,   137,   140,   143,   144,   147,
     148,   151,   154,   155,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   169,   170,   173,   176,   180,   183,   186,
     189,   192,   195,   196,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   226,
     227,   228,   231,   232,   235,   236,   239,   240,   241,   242,
     243,   244
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
  "SPACE", "INTVAL", "DOUBLEVAL", "STRINGVAL", "NULLVAL", "OR", "LESSEQL",
  "ID", "SUM", "SUB", "MULT", "DIV", "LESSTHN", "GREATERTHN", "MOD",
  "GREATEREQL", "EQUAL", "SAME", "DIFF", "AND", "NOT", "$accept",
  "Program", "Declarations", "Declaration", "VariableDecl", "Variable",
  "Type", "FunctionDecl", "FunctionName", "Formals", "Variables",
  "ClassDecl", "ClassName", "Extend", "Implement", "ListIdents", "Fields",
  "Field", "InterfaceDecl", "Prototypes", "Prototype", "StmtBlock",
  "Stmts", "Stmt", "PossibleExpr", "IfStmt", "PossibleElse", "WhileStmt",
  "ForStmt", "ReturnStmt", "BreakStmt", "PrintStmt", "ListExpr", "Expr",
  "LValue", "Call", "Actuals", "Constant", YY_NULLPTR
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
     315,   316
};
# endif

#define YYPACT_NINF -95

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-95)))

#define YYTABLE_NINF -19

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      25,   -42,   -95,   -95,   -95,   -95,   -25,   -21,   -95,    47,
      25,   -95,   -95,    44,   -22,   -95,    52,   -95,    72,   -95,
     -95,   -95,    76,   -95,   -95,   -95,    56,    81,    -2,    39,
     100,   -95,   -95,   -95,   -10,    83,    94,   -95,    77,    97,
       9,   -95,    98,    -2,   -95,   106,   -95,    88,   -95,    53,
     -95,   -95,   -95,   -95,    92,   157,   119,   120,    74,   -95,
     -95,   -95,   -95,   -95,    -2,    -2,   -95,   121,   122,   124,
     165,   125,   128,   138,   139,   143,   144,   -95,   -95,   165,
     -95,   -95,   -95,   -95,   -95,   -11,   165,   165,   -95,   -95,
     -95,   -95,   -95,   -95,   -95,   -95,   -95,   304,    99,   -95,
     -95,   145,   146,   165,   165,   165,   148,   149,   304,   -95,
     133,   165,   165,   151,   155,   207,   165,    -7,     7,   150,
     165,   165,   165,   165,   165,   165,   165,   165,   165,   165,
     165,   165,   165,   165,   165,   160,   161,   164,   240,   256,
     -95,   167,   191,    75,   304,   -95,   -95,   -95,   173,   169,
     171,   289,     7,    -7,    -7,    -7,    -7,    -7,    -7,    -7,
      -7,    -7,     7,     7,     7,     7,   -95,   -95,   165,   123,
     123,   -95,    -2,   165,   170,   -95,   165,   -95,   178,   -95,
     187,    16,   304,   -95,   174,   165,   123,   -95,   -95,   -95,
     180,   -95,   123,   -95
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,    11,    12,    13,    14,     0,     0,    15,     0,
       2,     3,     5,     0,     0,     6,     0,     7,    27,     8,
      19,    25,     0,     1,     4,     9,     0,    10,    21,     0,
      29,    38,    16,    22,     0,     0,    20,    26,     0,     0,
       0,    10,     0,     0,    30,    28,    33,     0,    36,     0,
      37,    43,    17,    23,     0,     0,     0,     0,     0,    31,
      24,    34,    35,    32,    21,    21,    67,     0,     0,     0,
      54,     0,     0,     0,     0,     0,     0,    98,    99,     0,
      41,    96,    97,   100,   101,    89,     0,     0,    52,    50,
      42,    44,    45,    46,    48,    47,    49,    51,    66,    68,
      65,     0,     0,    54,     0,     0,    89,     0,    53,    60,
       0,     0,     0,     0,     0,     0,    95,    75,    84,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      59,     0,     0,     0,    62,    85,    86,    69,    94,     0,
      90,     0,    83,    77,    70,    71,    72,    73,    76,    78,
      74,    79,    80,    81,    82,    64,    40,    39,    54,     0,
       0,    87,     0,     0,     0,    92,    95,    91,     0,    57,
       0,     0,    63,    61,     0,    54,     0,    55,    88,    93,
       0,    56,     0,    58
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -95,   -95,   -95,   204,     1,   152,     0,   166,   -95,    11,
     -95,   -95,   -95,   -95,   -95,   -95,   -95,   -95,   -95,   -95,
     -95,   181,   -95,   -66,   -94,   -95,   -95,   -95,   -95,   -95,
     -95,   -95,   110,   -62,   -95,   -95,    48,   -95
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     9,    10,    11,    88,    13,    34,    15,    16,    35,
      36,    17,    18,    30,    39,    45,    55,    63,    19,    40,
      50,    89,    58,    90,   107,    91,   187,    92,    93,    94,
      95,    96,   148,    97,    98,    99,   149,   100
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      14,    12,     2,     3,     4,     5,    20,    26,   108,   137,
      14,    12,    47,     2,     3,     4,     5,   115,   -15,    26,
     116,   119,   120,    21,   117,   118,    27,    22,     1,     2,
       3,     4,     5,     6,     7,   119,   120,   -15,    41,   121,
      49,   108,   138,   139,    48,    26,     8,    23,   188,   142,
     144,   131,   132,   133,   144,    14,    61,     8,   151,   152,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,     8,   178,   101,   102,    25,     2,     3,
       4,     5,    26,    28,    29,    66,    32,    37,    67,    68,
      69,   190,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    57,   173,   179,   180,    79,   108,   174,    51,    80,
      31,   182,   -18,    38,   144,    42,    81,    82,    83,    84,
     191,    43,    85,   108,    86,    44,   193,     2,     3,     4,
       5,    46,    51,    54,    66,    87,    56,    67,    68,    69,
      59,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      64,    65,   103,   104,    79,   105,   134,    51,   109,   110,
       1,     2,     3,     4,     5,    81,    82,    83,    84,   111,
     112,    85,   181,    86,   113,   114,    66,   135,   136,   116,
      33,   141,   140,   145,    87,    72,    73,   146,    75,    76,
      77,    78,    60,   166,   167,    53,    79,   168,   150,   171,
     173,   175,   176,   183,   186,     8,   189,    81,    82,    83,
      84,   185,   192,   106,    24,    86,    33,    33,   172,   119,
     120,    62,   143,    52,   184,     0,    87,     0,     0,     0,
       0,     0,     0,     0,     0,   119,   120,   121,   122,   147,
     123,   124,   125,   126,   127,   128,   129,   130,     0,   131,
     132,   133,     0,   121,   122,     0,   123,   124,   125,   126,
     127,   128,   129,   130,     0,   131,   132,   133,   119,   120,
       0,     0,   169,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   119,   120,   121,   122,   170,   123,
     124,   125,   126,   127,   128,   129,   130,     0,   131,   132,
     133,     0,   121,   122,     0,   123,   124,   125,   126,   127,
     128,   129,   130,     0,   131,   132,   133,   119,   120,   177,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   119,   120,     0,   121,   122,     0,   123,   124,
     125,   126,   127,   128,   129,   130,     0,   131,   132,   133,
     121,   122,     0,   123,   124,   125,   126,   127,   128,   129,
     130,     0,   131,   132,   133
};

static const yytype_int16 yycheck[] =
{
       0,     0,     4,     5,     6,     7,    48,    29,    70,   103,
      10,    10,     3,     4,     5,     6,     7,    79,    29,    29,
      31,    28,    29,    48,    86,    87,    48,    48,     3,     4,
       5,     6,     7,     8,     9,    28,    29,    48,    48,    46,
      40,   103,   104,   105,    35,    29,    48,     0,    32,   111,
     112,    58,    59,    60,   116,    55,    55,    48,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     132,   133,   134,    48,   168,    64,    65,    33,     4,     5,
       6,     7,    29,    31,    12,    11,    30,    48,    14,    15,
      16,   185,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    48,    27,   169,   170,    31,   168,    32,    34,    35,
      34,   173,    31,    13,   176,    32,    42,    43,    44,    45,
     186,    27,    48,   185,    50,    48,   192,     4,     5,     6,
       7,    34,    34,    27,    11,    61,    48,    14,    15,    16,
      48,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      31,    31,    31,    31,    31,    31,    57,    34,    33,    31,
       3,     4,     5,     6,     7,    42,    43,    44,    45,    31,
      31,    48,   172,    50,    31,    31,    11,    32,    32,    31,
      28,    48,    33,    32,    61,    20,    21,    32,    23,    24,
      25,    26,    35,    33,    33,    43,    31,    33,    48,    32,
      27,    32,    31,    33,    17,    48,    32,    42,    43,    44,
      45,    33,    32,    48,    10,    50,    64,    65,    27,    28,
      29,    55,   112,    42,   176,    -1,    61,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    28,    29,    46,    47,    32,
      49,    50,    51,    52,    53,    54,    55,    56,    -1,    58,
      59,    60,    -1,    46,    47,    -1,    49,    50,    51,    52,
      53,    54,    55,    56,    -1,    58,    59,    60,    28,    29,
      -1,    -1,    32,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    28,    29,    46,    47,    32,    49,
      50,    51,    52,    53,    54,    55,    56,    -1,    58,    59,
      60,    -1,    46,    47,    -1,    49,    50,    51,    52,    53,
      54,    55,    56,    -1,    58,    59,    60,    28,    29,    30,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    28,    29,    -1,    46,    47,    -1,    49,    50,
      51,    52,    53,    54,    55,    56,    -1,    58,    59,    60,
      46,    47,    -1,    49,    50,    51,    52,    53,    54,    55,
      56,    -1,    58,    59,    60
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     4,     5,     6,     7,     8,     9,    48,    63,
      64,    65,    66,    67,    68,    69,    70,    73,    74,    80,
      48,    48,    48,     0,    65,    33,    29,    48,    31,    12,
      75,    34,    30,    67,    68,    71,    72,    48,    13,    76,
      81,    48,    32,    27,    48,    77,    34,     3,    35,    68,
      82,    34,    83,    67,    27,    78,    48,    48,    84,    48,
      35,    66,    69,    79,    31,    31,    11,    14,    15,    16,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    31,
      35,    42,    43,    44,    45,    48,    50,    61,    66,    83,
      85,    87,    89,    90,    91,    92,    93,    95,    96,    97,
      99,    71,    71,    31,    31,    31,    48,    86,    95,    33,
      31,    31,    31,    31,    31,    95,    31,    95,    95,    28,
      29,    46,    47,    49,    50,    51,    52,    53,    54,    55,
      56,    58,    59,    60,    57,    32,    32,    86,    95,    95,
      33,    48,    95,    94,    95,    32,    32,    32,    94,    98,
      48,    95,    95,    95,    95,    95,    95,    95,    95,    95,
      95,    95,    95,    95,    95,    95,    33,    33,    33,    32,
      32,    32,    27,    27,    32,    32,    31,    30,    86,    85,
      85,    68,    95,    33,    98,    33,    17,    88,    32,    32,
      86,    85,    32,    85
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    62,    63,    64,    64,    65,    65,    65,    65,    66,
      67,    68,    68,    68,    68,    68,    68,    69,    70,    70,
      71,    71,    72,    72,    73,    74,    75,    75,    76,    76,
      77,    77,    78,    78,    79,    79,    80,    81,    81,    82,
      82,    83,    84,    84,    85,    85,    85,    85,    85,    85,
      85,    85,    85,    86,    86,    87,    88,    89,    90,    91,
      92,    93,    94,    94,    95,    95,    95,    95,    95,    95,
      95,    95,    95,    95,    95,    95,    95,    95,    95,    95,
      95,    95,    95,    95,    95,    95,    95,    95,    95,    96,
      96,    96,    97,    97,    98,    98,    99,    99,    99,    99,
      99,    99
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     2,     1,     1,     1,     1,     2,
       2,     1,     1,     1,     1,     1,     3,     5,     2,     2,
       1,     0,     1,     3,     6,     2,     2,     0,     2,     0,
       1,     3,     2,     0,     1,     1,     5,     2,     0,     6,
       6,     3,     2,     0,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     0,     6,     2,     5,     9,     3,
       2,     5,     1,     3,     3,     1,     1,     1,     1,     3,
       3,     3,     3,     3,     3,     2,     3,     3,     3,     3,
       3,     3,     3,     3,     2,     3,     3,     4,     6,     1,
       3,     4,     4,     6,     1,     0,     1,     1,     1,     1,
       1,     1
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
#line 61 "proyecto1Parser.y"
    { (yyval.treeNode) = createTreeNode(yylineno, "Program", 1, (yyvsp[0].treeNode)); parent = (yyval.treeNode); }
#line 1592 "proyecto1Parser.tab.c"
    break;

  case 3:
#line 64 "proyecto1Parser.y"
    { (yyval.treeNode) = createTreeNode(yylineno, "Declarations", 1, (yyvsp[0].treeNode)); }
#line 1598 "proyecto1Parser.tab.c"
    break;

  case 4:
#line 65 "proyecto1Parser.y"
    { (yyval.treeNode) = createTreeNode(yylineno, "Declarations", 2, (yyvsp[-1].treeNode), (yyvsp[0].treeNode)); }
#line 1604 "proyecto1Parser.tab.c"
    break;

  case 5:
#line 68 "proyecto1Parser.y"
    { (yyval.treeNode) = createTreeNode(yylineno, "Declaration", 1, (yyvsp[0].treeNode)); }
#line 1610 "proyecto1Parser.tab.c"
    break;

  case 6:
#line 69 "proyecto1Parser.y"
    { (yyval.treeNode) = createTreeNode(yylineno, "Declaration", 1, (yyvsp[0].treeNode)); }
#line 1616 "proyecto1Parser.tab.c"
    break;

  case 7:
#line 70 "proyecto1Parser.y"
    { (yyval.treeNode) = createTreeNode(yylineno, "Declaration", 1, (yyvsp[0].treeNode)); }
#line 1622 "proyecto1Parser.tab.c"
    break;

  case 8:
#line 71 "proyecto1Parser.y"
    { (yyval.treeNode) = createTreeNode(yylineno, "Declaration", 1, (yyvsp[0].treeNode)); }
#line 1628 "proyecto1Parser.tab.c"
    break;

  case 9:
#line 74 "proyecto1Parser.y"
    { (yyval.treeNode) = createTreeNode(yylineno, "VariableDecl", 2, (yyvsp[-1].treeNode), tN(";")); }
#line 1634 "proyecto1Parser.tab.c"
    break;

  case 10:
#line 77 "proyecto1Parser.y"
    { (yyval.treeNode) = createTreeNode(yylineno, "Variable", 2, (yyvsp[-1].treeNode), tT(yylval.str, "ID"));
                          struct SymbolNode * newSymbol = createSymbolNode((yyvsp[-1].treeNode)->value,yylval.str);
                          rootSymbol = insertSymbolNode(rootSymbol,newSymbol);
                        }
#line 1643 "proyecto1Parser.tab.c"
    break;

  case 11:
#line 83 "proyecto1Parser.y"
    { (yyval.treeNode) = createTreeNode(yylineno, "Type", 1, tN("integer")); }
#line 1649 "proyecto1Parser.tab.c"
    break;

  case 12:
#line 84 "proyecto1Parser.y"
    { (yyval.treeNode) = createTreeNode(yylineno, "Type", 1, tN("double")); }
#line 1655 "proyecto1Parser.tab.c"
    break;

  case 13:
#line 85 "proyecto1Parser.y"
    { (yyval.treeNode) = createTreeNode(yylineno, "Type", 1, tN("boolean")); }
#line 1661 "proyecto1Parser.tab.c"
    break;

  case 14:
#line 86 "proyecto1Parser.y"
    { (yyval.treeNode) = createTreeNode(yylineno, "Type", 1, tN("string")); }
#line 1667 "proyecto1Parser.tab.c"
    break;

  case 15:
#line 87 "proyecto1Parser.y"
    { (yyval.treeNode) = createTreeNode(yylineno, "Type", 1, tN(yylval.str)); }
#line 1673 "proyecto1Parser.tab.c"
    break;

  case 16:
#line 88 "proyecto1Parser.y"
    { (yyval.treeNode) = createTreeNode(yylineno, "Type", 3, (yyvsp[-2].treeNode), tN("["), tN("]")); }
#line 1679 "proyecto1Parser.tab.c"
    break;

  case 17:
#line 91 "proyecto1Parser.y"
    {  (yyval.treeNode) = createTreeNode(yylineno, "FunctionDecl", 5, (yyvsp[-4].treeNode), tN("("), (yyvsp[-2].treeNode), tN(")"), (yyvsp[0].treeNode)); 
                                                                    scopeActual = createScope((yyvsp[-4].treeNode)->root->next->node->value);
                                                                    insertSymbol(scopeActual,rootSymbol);
                                                                    struct ScopeNode * scopeNode = createScopeNode(scopeActual);
                                                                    listScopes = insertScopeNode(listScopes, scopeNode);
                                                                    free(rootSymbol);
                                                                    rootSymbol = 0;
                                                                  }
#line 1692 "proyecto1Parser.tab.c"
    break;

  case 18:
#line 102 "proyecto1Parser.y"
    { (yyval.treeNode) = createTreeNode(yylineno, "FunctionName", 2, (yyvsp[-1].treeNode), tT(yylval.str, "ID"));}
#line 1698 "proyecto1Parser.tab.c"
    break;

  case 19:
#line 103 "proyecto1Parser.y"
    { (yyval.treeNode) = createTreeNode(yylineno, "FunctionName", 2, tN("void"), tT(yylval.str, "ID")); }
#line 1704 "proyecto1Parser.tab.c"
    break;

  case 20:
#line 106 "proyecto1Parser.y"
    { (yyval.treeNode) = createTreeNode(yylineno, "Formals", 1, (yyvsp[0].treeNode)); }
#line 1710 "proyecto1Parser.tab.c"
    break;

  case 21:
#line 107 "proyecto1Parser.y"
    { (yyval.treeNode) = eN(); }
#line 1716 "proyecto1Parser.tab.c"
    break;

  case 22:
#line 110 "proyecto1Parser.y"
    { (yyval.treeNode) = createTreeNode(yylineno, "Variables", 1, (yyvsp[0].treeNode)); }
#line 1722 "proyecto1Parser.tab.c"
    break;

  case 23:
#line 111 "proyecto1Parser.y"
    { (yyval.treeNode) = createTreeNode(yylineno, "Variables", 3, (yyvsp[-2].treeNode), tN(","), (yyvsp[0].treeNode)); }
#line 1728 "proyecto1Parser.tab.c"
    break;

  case 24:
#line 114 "proyecto1Parser.y"
    { (yyval.treeNode) = createTreeNode(yylineno, "ClassDecl", 6, (yyvsp[-5].treeNode), (yyvsp[-4].treeNode), (yyvsp[-3].treeNode), tN("{"), (yyvsp[-1].treeNode), tN("}")); }
#line 1734 "proyecto1Parser.tab.c"
    break;

  case 25:
#line 117 "proyecto1Parser.y"
    {(yyval.treeNode) = createTreeNode(yylineno, "ClassName", 2, tN("Class"), tT(yylval.str, "ID"));}
#line 1740 "proyecto1Parser.tab.c"
    break;

  case 26:
#line 120 "proyecto1Parser.y"
    { (yyval.treeNode) = createTreeNode(yylineno, "Extend", 2, tN("extends"), tT(yylval.str, "ID")); }
#line 1746 "proyecto1Parser.tab.c"
    break;

  case 27:
#line 121 "proyecto1Parser.y"
    { (yyval.treeNode) = eN(); }
#line 1752 "proyecto1Parser.tab.c"
    break;

  case 28:
#line 124 "proyecto1Parser.y"
    { (yyval.treeNode) = createTreeNode(yylineno, "Implement", 2, tN("implements"), (yyvsp[0].treeNode)); }
#line 1758 "proyecto1Parser.tab.c"
    break;

  case 29:
#line 125 "proyecto1Parser.y"
    { (yyval.treeNode) = eN(); }
#line 1764 "proyecto1Parser.tab.c"
    break;

  case 30:
#line 128 "proyecto1Parser.y"
    { (yyval.treeNode) = createTreeNode(yylineno, "ListIdents", 1, tT(yylval.str, "ID")); }
#line 1770 "proyecto1Parser.tab.c"
    break;

  case 31:
#line 129 "proyecto1Parser.y"
    { (yyval.treeNode) = createTreeNode(yylineno, "ListIdents", 3, (yyvsp[-2].treeNode), tN(","), tT(yylval.str, "ID")); }
#line 1776 "proyecto1Parser.tab.c"
    break;

  case 32:
#line 132 "proyecto1Parser.y"
    { (yyval.treeNode) = createTreeNode(yylineno, "Fields", 2, (yyvsp[-1].treeNode), (yyvsp[0].treeNode)); }
#line 1782 "proyecto1Parser.tab.c"
    break;

  case 33:
#line 133 "proyecto1Parser.y"
    { (yyval.treeNode) = eN(); }
#line 1788 "proyecto1Parser.tab.c"
    break;

  case 34:
#line 136 "proyecto1Parser.y"
    { (yyval.treeNode) = createTreeNode(yylineno, "Field", 1, (yyvsp[0].treeNode)); }
#line 1794 "proyecto1Parser.tab.c"
    break;

  case 35:
#line 137 "proyecto1Parser.y"
    { (yyval.treeNode) = createTreeNode(yylineno, "Field", 1, (yyvsp[0].treeNode)); }
#line 1800 "proyecto1Parser.tab.c"
    break;

  case 36:
#line 140 "proyecto1Parser.y"
    { (yyval.treeNode) = createTreeNode(yylineno, "InterfaceDecl", 5, tN("interface"), tT(yylval.str, "ID"), tN("{"), (yyvsp[-1].treeNode), tN("}")); }
#line 1806 "proyecto1Parser.tab.c"
    break;

  case 37:
#line 143 "proyecto1Parser.y"
    { (yyval.treeNode) = createTreeNode(yylineno, "Prototypes", 2, (yyvsp[-1].treeNode), (yyvsp[0].treeNode)); }
#line 1812 "proyecto1Parser.tab.c"
    break;

  case 38:
#line 144 "proyecto1Parser.y"
    { (yyval.treeNode) = eN(); }
#line 1818 "proyecto1Parser.tab.c"
    break;

  case 39:
#line 147 "proyecto1Parser.y"
    { (yyval.treeNode) = createTreeNode(yylineno, "Prototype", 6, (yyvsp[-5].treeNode), tT(yylval.str, "ID"), tN("("), (yyvsp[-2].treeNode), tN(")"), tN(";")); }
#line 1824 "proyecto1Parser.tab.c"
    break;

  case 40:
#line 148 "proyecto1Parser.y"
    { (yyval.treeNode) = createTreeNode(yylineno, "Prototype", 6, tN("void"), tT(yylval.str, "ID"), tN("("), (yyvsp[-2].treeNode), tN(")"), tN(";")); }
#line 1830 "proyecto1Parser.tab.c"
    break;

  case 41:
#line 151 "proyecto1Parser.y"
    { (yyval.treeNode) = createTreeNode(yylineno, "StmtBlock", 3, tN("{"), (yyvsp[-1].treeNode), tN("}")); }
#line 1836 "proyecto1Parser.tab.c"
    break;

  case 42:
#line 154 "proyecto1Parser.y"
    { (yyval.treeNode) = createTreeNode(yylineno, "Stmts", 2, (yyvsp[-1].treeNode), (yyvsp[0].treeNode)); }
#line 1842 "proyecto1Parser.tab.c"
    break;

  case 43:
#line 155 "proyecto1Parser.y"
    { (yyval.treeNode) = eN(); }
#line 1848 "proyecto1Parser.tab.c"
    break;

  case 44:
#line 158 "proyecto1Parser.y"
    { (yyval.treeNode) = createTreeNode(yylineno, "Stmt", 1, (yyvsp[0].treeNode)); }
#line 1854 "proyecto1Parser.tab.c"
    break;

  case 45:
#line 159 "proyecto1Parser.y"
    { (yyval.treeNode) = createTreeNode(yylineno, "Stmt", 1, (yyvsp[0].treeNode)); }
#line 1860 "proyecto1Parser.tab.c"
    break;

  case 46:
#line 160 "proyecto1Parser.y"
    { (yyval.treeNode) = createTreeNode(yylineno, "Stmt", 1, (yyvsp[0].treeNode)); }
#line 1866 "proyecto1Parser.tab.c"
    break;

  case 47:
#line 161 "proyecto1Parser.y"
    { (yyval.treeNode) = createTreeNode(yylineno, "Stmt", 1, (yyvsp[0].treeNode)); }
#line 1872 "proyecto1Parser.tab.c"
    break;

  case 48:
#line 162 "proyecto1Parser.y"
    { (yyval.treeNode) = createTreeNode(yylineno, "Stmt", 1, (yyvsp[0].treeNode)); }
#line 1878 "proyecto1Parser.tab.c"
    break;

  case 49:
#line 163 "proyecto1Parser.y"
    { (yyval.treeNode) = createTreeNode(yylineno, "Stmt", 1, (yyvsp[0].treeNode)); }
#line 1884 "proyecto1Parser.tab.c"
    break;

  case 50:
#line 164 "proyecto1Parser.y"
    { (yyval.treeNode) = createTreeNode(yylineno, "Stmt", 1, (yyvsp[0].treeNode)); }
#line 1890 "proyecto1Parser.tab.c"
    break;

  case 51:
#line 165 "proyecto1Parser.y"
    { (yyval.treeNode) = createTreeNode(yylineno, "Stmt", 1, (yyvsp[0].treeNode)); }
#line 1896 "proyecto1Parser.tab.c"
    break;

  case 52:
#line 166 "proyecto1Parser.y"
    { (yyval.treeNode) = createTreeNode(yylineno, "Stmt", 1, (yyvsp[0].treeNode)); }
#line 1902 "proyecto1Parser.tab.c"
    break;

  case 53:
#line 169 "proyecto1Parser.y"
    { (yyval.treeNode) = createTreeNode(yylineno, "Expr", 1, (yyvsp[0].treeNode)); }
#line 1908 "proyecto1Parser.tab.c"
    break;

  case 54:
#line 170 "proyecto1Parser.y"
    { (yyval.treeNode) = eN(); }
#line 1914 "proyecto1Parser.tab.c"
    break;

  case 55:
#line 173 "proyecto1Parser.y"
    { (yyval.treeNode) = createTreeNode(yylineno, "IfStmt", 6, tN("if"), tN("("), (yyvsp[-3].treeNode), tN(")"), (yyvsp[-1].treeNode), (yyvsp[0].treeNode)); }
#line 1920 "proyecto1Parser.tab.c"
    break;

  case 56:
#line 176 "proyecto1Parser.y"
    { (yyval.treeNode) = createTreeNode(yylineno, "Else", 2, tN("else"), (yyvsp[0].treeNode)); }
#line 1926 "proyecto1Parser.tab.c"
    break;

  case 57:
#line 180 "proyecto1Parser.y"
    { (yyval.treeNode) = createTreeNode(yylineno, "WhileStmt", 5, tN("while"), tN("("), (yyvsp[-2].treeNode), tN(")"), (yyvsp[0].treeNode)); }
#line 1932 "proyecto1Parser.tab.c"
    break;

  case 58:
#line 183 "proyecto1Parser.y"
    { (yyval.treeNode) = createTreeNode(yylineno, "ForStmt", 9, tN("for"), tN("("), (yyvsp[-6].treeNode), tN(";"), (yyvsp[-4].treeNode), tN(";"), (yyvsp[-2].treeNode), tN(")"), (yyvsp[0].treeNode)); }
#line 1938 "proyecto1Parser.tab.c"
    break;

  case 59:
#line 186 "proyecto1Parser.y"
    { (yyval.treeNode) = createTreeNode(yylineno, "ReturnStmt", 3, tN("return"), (yyvsp[-1].treeNode), tN(";")); }
#line 1944 "proyecto1Parser.tab.c"
    break;

  case 60:
#line 189 "proyecto1Parser.y"
    { (yyval.treeNode) = createTreeNode(yylineno, "BreakStmt", 2, tN("break"), tN(";")); }
#line 1950 "proyecto1Parser.tab.c"
    break;

  case 61:
#line 192 "proyecto1Parser.y"
    { (yyval.treeNode) = createTreeNode(yylineno, "PrintStmt", 5, tN("print"), tN("("), (yyvsp[-2].treeNode), tN(")"), tN(";")); }
#line 1956 "proyecto1Parser.tab.c"
    break;

  case 62:
#line 195 "proyecto1Parser.y"
    { (yyval.treeNode) = createTreeNode(yylineno, "ListExpr", 1, (yyvsp[0].treeNode)); }
#line 1962 "proyecto1Parser.tab.c"
    break;

  case 63:
#line 196 "proyecto1Parser.y"
    { (yyval.treeNode) = createTreeNode(yylineno, "ListExpr", 3, (yyvsp[-2].treeNode), tN(","), (yyvsp[0].treeNode)); }
#line 1968 "proyecto1Parser.tab.c"
    break;

  case 64:
#line 199 "proyecto1Parser.y"
    { (yyval.treeNode) = createTreeNode(yylineno, "Expr", 3, (yyvsp[-2].treeNode), tN("="), (yyvsp[0].treeNode)); }
#line 1974 "proyecto1Parser.tab.c"
    break;

  case 65:
#line 200 "proyecto1Parser.y"
    { (yyval.treeNode) = createTreeNode(yylineno, "Expr", 1, (yyvsp[0].treeNode)); }
#line 1980 "proyecto1Parser.tab.c"
    break;

  case 66:
#line 201 "proyecto1Parser.y"
    { (yyval.treeNode) = createTreeNode(yylineno, "Expr", 1, (yyvsp[0].treeNode)); }
#line 1986 "proyecto1Parser.tab.c"
    break;

  case 67:
#line 202 "proyecto1Parser.y"
    { (yyval.treeNode) = createTreeNode(yylineno, "Expr", 1, tN("this")); }
#line 1992 "proyecto1Parser.tab.c"
    break;

  case 68:
#line 203 "proyecto1Parser.y"
    { (yyval.treeNode) = createTreeNode(yylineno, "Expr", 1, (yyvsp[0].treeNode)); }
#line 1998 "proyecto1Parser.tab.c"
    break;

  case 69:
#line 204 "proyecto1Parser.y"
    { (yyval.treeNode) = createTreeNode(yylineno, "Expr", 3, tN("("), (yyvsp[-1].treeNode), tN(")")); }
#line 2004 "proyecto1Parser.tab.c"
    break;

  case 70:
#line 205 "proyecto1Parser.y"
    { (yyval.treeNode) = createTreeNode(yylineno, "Expr", 3, (yyvsp[-2].treeNode), tN("+"), (yyvsp[0].treeNode)); }
#line 2010 "proyecto1Parser.tab.c"
    break;

  case 71:
#line 206 "proyecto1Parser.y"
    { (yyval.treeNode) = createTreeNode(yylineno, "Expr", 3, (yyvsp[-2].treeNode), tN("-"), (yyvsp[0].treeNode)); }
#line 2016 "proyecto1Parser.tab.c"
    break;

  case 72:
#line 207 "proyecto1Parser.y"
    { (yyval.treeNode) = createTreeNode(yylineno, "Expr", 3, (yyvsp[-2].treeNode), tN("*"), (yyvsp[0].treeNode)); }
#line 2022 "proyecto1Parser.tab.c"
    break;

  case 73:
#line 208 "proyecto1Parser.y"
    { (yyval.treeNode) = createTreeNode(yylineno, "Expr", 3, (yyvsp[-2].treeNode), tN("/"), (yyvsp[0].treeNode)); }
#line 2028 "proyecto1Parser.tab.c"
    break;

  case 74:
#line 209 "proyecto1Parser.y"
    { (yyval.treeNode) = createTreeNode(yylineno, "Expr", 3, (yyvsp[-2].treeNode), tN("mod"), (yyvsp[0].treeNode)); }
#line 2034 "proyecto1Parser.tab.c"
    break;

  case 75:
#line 210 "proyecto1Parser.y"
    { (yyval.treeNode) = createTreeNode(yylineno, "Expr", 2, tN("-"), (yyvsp[0].treeNode)); }
#line 2040 "proyecto1Parser.tab.c"
    break;

  case 76:
#line 211 "proyecto1Parser.y"
    { (yyval.treeNode) = createTreeNode(yylineno, "Expr", 3, (yyvsp[-2].treeNode), tN("<"), (yyvsp[0].treeNode)); }
#line 2046 "proyecto1Parser.tab.c"
    break;

  case 77:
#line 212 "proyecto1Parser.y"
    { (yyval.treeNode) = createTreeNode(yylineno, "Expr", 3, (yyvsp[-2].treeNode), tN("<="), (yyvsp[0].treeNode)); }
#line 2052 "proyecto1Parser.tab.c"
    break;

  case 78:
#line 213 "proyecto1Parser.y"
    { (yyval.treeNode) = createTreeNode(yylineno, "Expr", 3, (yyvsp[-2].treeNode), tN(">"), (yyvsp[0].treeNode)); }
#line 2058 "proyecto1Parser.tab.c"
    break;

  case 79:
#line 214 "proyecto1Parser.y"
    { (yyval.treeNode) = createTreeNode(yylineno, "Expr", 3, (yyvsp[-2].treeNode), tN(">="), (yyvsp[0].treeNode)); }
#line 2064 "proyecto1Parser.tab.c"
    break;

  case 80:
#line 215 "proyecto1Parser.y"
    { (yyval.treeNode) = createTreeNode(yylineno, "Expr", 3, (yyvsp[-2].treeNode), tN("=="), (yyvsp[0].treeNode)); }
#line 2070 "proyecto1Parser.tab.c"
    break;

  case 81:
#line 216 "proyecto1Parser.y"
    { (yyval.treeNode) = createTreeNode(yylineno, "Expr", 3, (yyvsp[-2].treeNode), tN("!="), (yyvsp[0].treeNode)); }
#line 2076 "proyecto1Parser.tab.c"
    break;

  case 82:
#line 217 "proyecto1Parser.y"
    { (yyval.treeNode) = createTreeNode(yylineno, "Expr", 3, (yyvsp[-2].treeNode), tN("&&"), (yyvsp[0].treeNode)); }
#line 2082 "proyecto1Parser.tab.c"
    break;

  case 83:
#line 218 "proyecto1Parser.y"
    { (yyval.treeNode) = createTreeNode(yylineno, "Expr", 3, (yyvsp[-2].treeNode), tN("||"), (yyvsp[0].treeNode)); }
#line 2088 "proyecto1Parser.tab.c"
    break;

  case 84:
#line 219 "proyecto1Parser.y"
    { (yyval.treeNode) = createTreeNode(yylineno, "Expr", 2, tN("!"), (yyvsp[0].treeNode)); }
#line 2094 "proyecto1Parser.tab.c"
    break;

  case 85:
#line 220 "proyecto1Parser.y"
    { (yyval.treeNode) = createTreeNode(yylineno, "Expr", 3, tN("readInteger"), tN("("), tN(")")); }
#line 2100 "proyecto1Parser.tab.c"
    break;

  case 86:
#line 221 "proyecto1Parser.y"
    { (yyval.treeNode) = createTreeNode(yylineno, "Expr", 3, tN("readLine"), tN("("), tN(")")); }
#line 2106 "proyecto1Parser.tab.c"
    break;

  case 87:
#line 222 "proyecto1Parser.y"
    { (yyval.treeNode) = createTreeNode(yylineno, "Expr", 4, tN("new"), tN("("), tT(yylval.str, "ID"), tN(")")); }
#line 2112 "proyecto1Parser.tab.c"
    break;

  case 88:
#line 223 "proyecto1Parser.y"
    { (yyval.treeNode) = createTreeNode(yylineno, "Expr", 6, tN("newArray"), tN("("), (yyvsp[-3].treeNode), tN(","), (yyvsp[-1].treeNode), tN(")")); }
#line 2118 "proyecto1Parser.tab.c"
    break;

  case 89:
#line 226 "proyecto1Parser.y"
    { (yyval.treeNode) = createTreeNode(yylineno, "LValue", 1, tT(yylval.str, "ID")); }
#line 2124 "proyecto1Parser.tab.c"
    break;

  case 90:
#line 227 "proyecto1Parser.y"
    { (yyval.treeNode) = createTreeNode(yylineno, "LValue", 3, (yyvsp[-2].treeNode), tN("."), tT(yylval.str, "ID")); }
#line 2130 "proyecto1Parser.tab.c"
    break;

  case 91:
#line 228 "proyecto1Parser.y"
    { (yyval.treeNode) = createTreeNode(yylineno, "LValue", 4, (yyvsp[-3].treeNode), tN("["), (yyvsp[-1].treeNode), tN("]")); }
#line 2136 "proyecto1Parser.tab.c"
    break;

  case 92:
#line 231 "proyecto1Parser.y"
    { (yyval.treeNode) = createTreeNode(yylineno, "Call", 4, tT(yylval.str, "ID"), tN("("), (yyvsp[-1].treeNode), tN(")")); }
#line 2142 "proyecto1Parser.tab.c"
    break;

  case 93:
#line 232 "proyecto1Parser.y"
    { (yyval.treeNode) = createTreeNode(yylineno, "Call", 6, (yyvsp[-5].treeNode), tN("."), tT(yylval.str, "ID"), tN("("), (yyvsp[-1].treeNode), tN(")")); }
#line 2148 "proyecto1Parser.tab.c"
    break;

  case 94:
#line 235 "proyecto1Parser.y"
    { (yyval.treeNode) = createTreeNode(yylineno, "Actuals", 1, (yyvsp[0].treeNode)); }
#line 2154 "proyecto1Parser.tab.c"
    break;

  case 95:
#line 236 "proyecto1Parser.y"
    { (yyval.treeNode) = eN(); }
#line 2160 "proyecto1Parser.tab.c"
    break;

  case 96:
#line 239 "proyecto1Parser.y"
    { (yyval.treeNode) = createTreeNode(yylineno, "Constant", 1, tT(yylval.str, "integer")); }
#line 2166 "proyecto1Parser.tab.c"
    break;

  case 97:
#line 240 "proyecto1Parser.y"
    { (yyval.treeNode) = createTreeNode(yylineno, "Constant", 1, tT(yylval.str, "double")); }
#line 2172 "proyecto1Parser.tab.c"
    break;

  case 98:
#line 241 "proyecto1Parser.y"
    { (yyval.treeNode) = createTreeNode(yylineno, "Constant", 1, tT("true", "boolean")); }
#line 2178 "proyecto1Parser.tab.c"
    break;

  case 99:
#line 242 "proyecto1Parser.y"
    { (yyval.treeNode) = createTreeNode(yylineno, "Constant", 1, tT("false", "boolean")); }
#line 2184 "proyecto1Parser.tab.c"
    break;

  case 100:
#line 243 "proyecto1Parser.y"
    { (yyval.treeNode) = createTreeNode(yylineno, "Constant", 1, tT(yylval.str, "string")); }
#line 2190 "proyecto1Parser.tab.c"
    break;

  case 101:
#line 244 "proyecto1Parser.y"
    { (yyval.treeNode) = createTreeNode(yylineno, "Constant", 1, tT("null", "null")); }
#line 2196 "proyecto1Parser.tab.c"
    break;


#line 2200 "proyecto1Parser.tab.c"

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
#line 247 "proyecto1Parser.y"


int main() {
  rootSymbol = 0;
  listScopes = 0;
  yyin = stdin;
  do {
    yyparse();
	} while(!feof(yyin));
  printNode(parent,1);
	return 0;

}

void yyerror(char *s) {
  fprintf(stderr,"Error | Line: %d\n%s\n",yylineno,s);
}
