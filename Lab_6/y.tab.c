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
#line 1 "lab6.y"


    /* LAB 5: C-ALGOL YACC ROUTINE*/
    /*
        Written by: Fidel Soto
    */
    /*
        Date: March 1, 2020

        INITIAL IMPLEMENTATION:
            *Implemented the rules based on the 'Extended BNF Grammar for C-Algol'
                documentation for our language. In addition to the initial implementation,
                the yacc routine will also throw syntax errors with the corresponding line
                number. The line number variable is declared in Lab5.l.
            *Tokens will be brought in from the lex routine, with some of them (namely 'NUM' and 'ID') having 
             a type coming from a %union{}
    */

    int yylex();
    
    #include "ast.h"
    #include <stdio.h>
    #include <ctype.h>
    
    extern int lineCount;
    ASTNode *GlobalPointer;
    
    void yyerror (s)  /* Called by yyparse on error */
     char *s;
    {
        printf ("%s on line %d\n", s, lineCount);
    }


#line 105 "y.tab.c"

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
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
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
    INT = 258,
    AND = 259,
    OR = 260,
    VOID = 261,
    BOOL = 262,
    TRUE = 263,
    FALSE = 264,
    NOT = 265,
    IF = 266,
    THEN = 267,
    ELSE = 268,
    READ = 269,
    WRITE = 270,
    MYRETURN = 271,
    WHILE = 272,
    DO = 273,
    LT = 274,
    GT = 275,
    LE = 276,
    GE = 277,
    EQ = 278,
    NE = 279,
    MYBEGIN = 280,
    END = 281,
    NUM = 282,
    ID = 283
  };
#endif
/* Tokens.  */
#define INT 258
#define AND 259
#define OR 260
#define VOID 261
#define BOOL 262
#define TRUE 263
#define FALSE 264
#define NOT 265
#define IF 266
#define THEN 267
#define ELSE 268
#define READ 269
#define WRITE 270
#define MYRETURN 271
#define WHILE 272
#define DO 273
#define LT 274
#define GT 275
#define LE 276
#define GE 277
#define EQ 278
#define NE 279
#define MYBEGIN 280
#define END 281
#define NUM 282
#define ID 283

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 38 "lab6.y"

    int typeInt;
    char *typeString;
    struct ASTNodeType * node;
    enum DATATYPE type;
    enum OPERATOR opType;

#line 212 "y.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */



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
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

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
#define YYFINAL  10
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   122

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  40
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  34
/* YYNRULES -- Number of rules.  */
#define YYNRULES  77
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  124

#define YYUNDEFTOK  2
#define YYMAXUTOK   283

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
      33,    34,    38,    36,    32,    37,     2,    39,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    29,
       2,    35,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    30,     2,    31,     2,     2,     2,     2,     2,     2,
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
      25,    26,    27,    28
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    61,    61,    64,    65,    71,    72,    75,    87,    92,
      97,   103,   111,   114,   117,   122,   131,   132,   135,   136,
     142,   148,   156,   163,   164,   170,   171,   184,   185,   186,
     187,   188,   189,   190,   191,   194,   195,   198,   204,   213,
     220,   228,   232,   237,   243,   249,   252,   257,   264,   265,
     273,   274,   275,   276,   277,   278,   282,   283,   291,   292,
     295,   296,   305,   306,   307,   308,   311,   312,   316,   317,
     318,   322,   326,   333,   340,   341,   344,   345
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "INT", "AND", "OR", "VOID", "BOOL",
  "TRUE", "FALSE", "NOT", "IF", "THEN", "ELSE", "READ", "WRITE",
  "MYRETURN", "WHILE", "DO", "LT", "GT", "LE", "GE", "EQ", "NE", "MYBEGIN",
  "END", "NUM", "ID", "';'", "'['", "']'", "','", "'('", "')'", "'='",
  "'+'", "'-'", "'*'", "'/'", "$accept", "program", "declarationList",
  "declaration", "varDeclaration", "varList", "typeSpecifier",
  "funDeclaration", "params", "paramsList", "param", "compoundStatement",
  "localDeclarations", "statementList", "statement", "expressionStatement",
  "selectionStatement", "iterationStatement", "assignmentStatement",
  "returnStatement", "readStatement", "writeStatment", "expression", "var",
  "simpleExpression", "relop", "additiveExpression", "addop", "term",
  "multop", "factor", "call", "args", "argsList", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,    59,
      91,    93,    44,    40,    41,    61,    43,    45,    42,    47
};
# endif

#define YYPACT_NINF -92

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-92)))

#define YYTABLE_NINF -17

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int8 yypact[] =
{
      49,   -92,   -92,   -92,    23,   -92,    49,   -92,    25,   -92,
     -92,   -92,    -8,     2,    38,    44,    54,   -92,    45,   -19,
     -92,    36,    50,    43,   -92,    48,    57,    51,    65,    49,
      44,    60,    49,   -92,   -92,   -92,   -92,    49,    44,    18,
     -92,   -92,   -92,    40,    40,    72,    40,    11,    40,   -92,
     -15,   -92,    40,   -92,    66,    18,   -92,   -92,   -92,   -92,
     -92,   -92,   -92,    73,    68,    75,    27,     3,   -92,   -92,
     -92,   -92,    89,    74,    76,    77,   -92,    78,    90,    40,
      40,    79,   -92,   -92,   -92,    40,   -92,   -92,   -92,   -92,
     -92,   -92,    40,   -92,   -92,    40,   -92,   -92,   -92,   -92,
      40,    18,   -92,   -92,   -92,    18,    80,    82,    81,   -92,
     -92,    64,    27,     3,   -92,    96,   -92,   -92,    40,   -92,
     -92,    18,   -92,   -92
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    12,    13,    14,     0,     2,     3,     5,     0,     6,
       1,     4,     8,     0,     0,     0,     0,     7,     0,     8,
      10,    13,     0,     0,    17,    18,     9,    21,     0,     0,
       0,     0,    23,    15,    19,    11,    20,    23,     0,    25,
      24,    70,    71,     0,     0,     0,     0,     0,     0,    67,
      47,    36,     0,    28,     0,    25,    27,    29,    30,    31,
      32,    33,    34,     0,    68,    45,    48,    56,    60,    69,
      68,    72,     0,    47,     0,     0,    42,     0,     0,     0,
      74,     0,    22,    26,    35,     0,    51,    52,    50,    53,
      54,    55,     0,    58,    59,     0,    64,    65,    62,    63,
       0,     0,    43,    44,    41,     0,     0,    76,     0,    75,
      66,     0,    49,    57,    61,    37,    39,    46,     0,    73,
      40,     0,    77,    38
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -92,   -92,   104,   -92,   -20,    39,    42,   -92,   -92,    83,
     -92,    88,    84,    62,   -91,   -92,   -92,   -92,   -92,   -92,
     -92,   -92,   -43,   -39,    33,   -92,    28,   -92,    24,   -92,
     -41,   -92,   -92,     4
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     4,     5,     6,     7,    13,     8,     9,    23,    24,
      25,    53,    39,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    70,    65,    92,    66,    95,    67,   100,
      68,    69,   108,   109
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      64,    72,    71,    75,    77,    78,    74,    96,    97,    81,
     115,    14,    37,    15,   116,    79,    64,    37,    80,    41,
      42,    43,    14,    10,    15,    16,    41,    42,    43,    44,
     123,    17,    45,    46,    47,    48,   106,   107,    49,    50,
      76,    98,    99,    32,    52,    49,    50,    51,    41,    42,
      43,    52,     1,    12,    20,     2,     3,     1,    22,   114,
      21,     3,    64,    93,    94,    18,    64,    49,    50,    35,
     -16,    22,    19,    52,    38,   107,    26,    28,    27,    38,
      29,    31,    64,    86,    87,    88,    89,    90,    91,    30,
      32,    36,    82,   120,    86,    87,    88,    89,    90,    91,
      73,   101,    84,    85,    79,   102,   103,   104,   105,   121,
      11,   117,    34,   110,   118,   119,    33,    83,   111,   113,
     112,    40,   122
};

static const yytype_uint8 yycheck[] =
{
      39,    44,    43,    46,    47,    48,    45,     4,     5,    52,
     101,    30,    32,    32,   105,    30,    55,    37,    33,     8,
       9,    10,    30,     0,    32,    33,     8,     9,    10,    11,
     121,    29,    14,    15,    16,    17,    79,    80,    27,    28,
      29,    38,    39,    25,    33,    27,    28,    29,     8,     9,
      10,    33,     3,    28,    15,     6,     7,     3,    16,   100,
       6,     7,   101,    36,    37,    27,   105,    27,    28,    30,
      34,    29,    28,    33,    32,   118,    31,    34,    28,    37,
      32,    30,   121,    19,    20,    21,    22,    23,    24,    32,
      25,    31,    26,    29,    19,    20,    21,    22,    23,    24,
      28,    12,    29,    35,    30,    29,    29,    29,    18,    13,
       6,    31,    29,    34,    32,    34,    28,    55,    85,    95,
      92,    37,   118
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     6,     7,    41,    42,    43,    44,    46,    47,
       0,    42,    28,    45,    30,    32,    33,    29,    27,    28,
      45,     6,    46,    48,    49,    50,    31,    28,    34,    32,
      32,    30,    25,    51,    49,    45,    31,    44,    46,    52,
      52,     8,     9,    10,    11,    14,    15,    16,    17,    27,
      28,    29,    33,    51,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    66,    68,    70,    71,
      63,    70,    62,    28,    63,    62,    29,    62,    62,    30,
      33,    62,    26,    53,    29,    35,    19,    20,    21,    22,
      23,    24,    65,    36,    37,    67,     4,     5,    38,    39,
      69,    12,    29,    29,    29,    18,    62,    62,    72,    73,
      34,    64,    66,    68,    70,    54,    54,    31,    32,    34,
      29,    13,    73,    54
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    40,    41,    42,    42,    43,    43,    44,    45,    45,
      45,    45,    46,    46,    46,    47,    48,    48,    49,    49,
      50,    50,    51,    52,    52,    53,    53,    54,    54,    54,
      54,    54,    54,    54,    54,    55,    55,    56,    56,    57,
      58,    59,    59,    60,    61,    62,    63,    63,    64,    64,
      65,    65,    65,    65,    65,    65,    66,    66,    67,    67,
      68,    68,    69,    69,    69,    69,    70,    70,    70,    70,
      70,    70,    70,    71,    72,    72,    73,    73
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     2,     1,     1,     3,     1,     4,
       3,     6,     1,     1,     1,     6,     1,     1,     1,     3,
       4,     2,     4,     0,     2,     0,     2,     1,     1,     1,
       1,     1,     1,     1,     1,     2,     1,     4,     6,     4,
       4,     3,     2,     3,     3,     1,     4,     1,     1,     3,
       1,     1,     1,     1,     1,     1,     1,     3,     1,     1,
       1,     3,     1,     1,     1,     1,     3,     1,     1,     1,
       1,     1,     2,     4,     0,     1,     1,     3
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

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
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
yy_symbol_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyo, yytype, yyvaluep);
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
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
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
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
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
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
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

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
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

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
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
# undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

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


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2:
#line 61 "lab6.y"
    { GlobalPointer = (yyvsp[0].node); }
#line 1398 "y.tab.c"
    break;

  case 3:
#line 64 "lab6.y"
    { (yyval.node) = (yyvsp[0].node); }
#line 1404 "y.tab.c"
    break;

  case 4:
#line 65 "lab6.y"
    { 
                                                    (yyvsp[-1].node) -> next = (yyvsp[0].node);
                                                    (yyval.node) = (yyvsp[-1].node);
                                                }
#line 1413 "y.tab.c"
    break;

  case 5:
#line 71 "lab6.y"
    { (yyval.node) = (yyvsp[0].node); }
#line 1419 "y.tab.c"
    break;

  case 6:
#line 72 "lab6.y"
    { (yyval.node) = (yyvsp[0].node); }
#line 1425 "y.tab.c"
    break;

  case 7:
#line 75 "lab6.y"
    { 
                                                        (yyval.node) = (yyvsp[-1].node);
                                                        struct ASTNodeType *p;
                                                        p = (yyval.node);
                                                        while (p != NULL) 
                                                        {
                                                            p->dataType = (yyvsp[-2]. type );
                                                            p = p->s1;
                                                        }
                                                    }
#line 1440 "y.tab.c"
    break;

  case 8:
#line 87 "lab6.y"
    {
                                    (yyval.node) = ASTCreateNode(varDeclaration);
                                    (yyval.node)->name = (yyvsp[0]. typeString );
                                    (yyval.node)->size = 1;
                                }
#line 1450 "y.tab.c"
    break;

  case 9:
#line 92 "lab6.y"
    {
                                    (yyval.node) = ASTCreateNode(varDeclaration);
                                    (yyval.node)->name = (yyvsp[-3]. typeString );
                                    (yyval.node)->size = (yyvsp[-1]. typeInt );
                                }
#line 1460 "y.tab.c"
    break;

  case 10:
#line 97 "lab6.y"
    {
                                    (yyval.node) = ASTCreateNode(varDeclaration);
                                    (yyval.node)->name = (yyvsp[-2]. typeString );
                                    (yyval.node)->size = 1;
                                    (yyval.node)-> s1 = (yyvsp[0].node);
                                }
#line 1471 "y.tab.c"
    break;

  case 11:
#line 103 "lab6.y"
    {
                                                (yyval.node) = ASTCreateNode(varDeclaration);
                                                (yyval.node)->name = (yyvsp[-5]. typeString );
                                                (yyval.node)->size = (yyvsp[-3]. typeInt );
                                                (yyval.node)-> s1 = (yyvsp[0].node);
                                            }
#line 1482 "y.tab.c"
    break;

  case 12:
#line 111 "lab6.y"
    {
                                (yyval. type ) = intType;
                            }
#line 1490 "y.tab.c"
    break;

  case 13:
#line 114 "lab6.y"
    {
                                (yyval. type ) = voidType;
                            }
#line 1498 "y.tab.c"
    break;

  case 14:
#line 117 "lab6.y"
    {
                                (yyval. type ) = boolType;
                            }
#line 1506 "y.tab.c"
    break;

  case 15:
#line 122 "lab6.y"
    {
                                                                                (yyval.node) = ASTCreateNode(funDeclaration);
                                                                                (yyval.node)->name = (yyvsp[-4]. typeString );
                                                                                (yyval.node)->dataType = (yyvsp[-5]. type );
                                                                                (yyval.node)->s1 = (yyvsp[-2].node);
                                                                                (yyval.node)->s2 = (yyvsp[0].node);
                                                                            }
#line 1518 "y.tab.c"
    break;

  case 16:
#line 131 "lab6.y"
    { (yyval.node) = NULL; }
#line 1524 "y.tab.c"
    break;

  case 18:
#line 135 "lab6.y"
    { (yyval.node) = (yyvsp[0].node); }
#line 1530 "y.tab.c"
    break;

  case 19:
#line 136 "lab6.y"
    {
                                            (yyval.node)->next = (yyvsp[0].node);
                                            (yyval.node) = (yyvsp[-2].node);
                                        }
#line 1539 "y.tab.c"
    break;

  case 20:
#line 142 "lab6.y"
    {
                                                        (yyval.node) = ASTCreateNode(param);
                                                        (yyval.node)->dataType = (yyvsp[-3]. type );
                                                        (yyval.node)->name = (yyvsp[-2]. typeString );
                                                        (yyval.node)->size = -1;
                                                    }
#line 1550 "y.tab.c"
    break;

  case 21:
#line 148 "lab6.y"
    {
                                        (yyval.node) = ASTCreateNode(param);
                                        (yyval.node)->dataType = (yyvsp[-1]. type );
                                        (yyval.node)->name = (yyvsp[0]. typeString );
                                        (yyval.node)->size = 0;
                                    }
#line 1561 "y.tab.c"
    break;

  case 22:
#line 156 "lab6.y"
    {
                                                                        (yyval.node) = ASTCreateNode(body);
                                                                        (yyval.node)->s1 = (yyvsp[-2].node);
                                                                        (yyval.node)->s2 = (yyvsp[-1].node);
                                                                    }
#line 1571 "y.tab.c"
    break;

  case 23:
#line 163 "lab6.y"
    { (yyval.node) = NULL; }
#line 1577 "y.tab.c"
    break;

  case 24:
#line 164 "lab6.y"
    { 
                                                        (yyvsp[-1].node)->next = (yyvsp[0].node);
                                                        (yyval.node) = (yyvsp[-1].node);
                                                    }
#line 1586 "y.tab.c"
    break;

  case 25:
#line 170 "lab6.y"
    { (yyval.node) = NULL; }
#line 1592 "y.tab.c"
    break;

  case 26:
#line 171 "lab6.y"
    {
                                            if ((yyvsp[-1].node) ==  NULL)
                                            {
                                                (yyval.node) = (yyvsp[0].node);
                                            }
                                            else 
                                            {
                                                (yyvsp[-1].node)->next = (yyvsp[0].node);
                                                (yyval.node) = (yyvsp[-1].node);
                                            }
                                        }
#line 1608 "y.tab.c"
    break;

  case 27:
#line 184 "lab6.y"
    { (yyval.node) = (yyvsp[0].node); }
#line 1614 "y.tab.c"
    break;

  case 28:
#line 185 "lab6.y"
    { (yyval.node) = (yyvsp[0].node); }
#line 1620 "y.tab.c"
    break;

  case 29:
#line 186 "lab6.y"
    { (yyval.node) = (yyvsp[0].node); }
#line 1626 "y.tab.c"
    break;

  case 30:
#line 187 "lab6.y"
    { (yyval.node) = (yyvsp[0].node); }
#line 1632 "y.tab.c"
    break;

  case 31:
#line 188 "lab6.y"
    { (yyval.node) = (yyvsp[0].node); }
#line 1638 "y.tab.c"
    break;

  case 32:
#line 189 "lab6.y"
    { (yyval.node) = (yyvsp[0].node); }
#line 1644 "y.tab.c"
    break;

  case 33:
#line 190 "lab6.y"
    { (yyval.node) = (yyvsp[0].node); }
#line 1650 "y.tab.c"
    break;

  case 34:
#line 191 "lab6.y"
    { (yyval.node) = (yyvsp[0].node); }
#line 1656 "y.tab.c"
    break;

  case 35:
#line 194 "lab6.y"
    { (yyval.node) = (yyvsp[-1].node); }
#line 1662 "y.tab.c"
    break;

  case 36:
#line 195 "lab6.y"
    { (yyval.node) = NULL; }
#line 1668 "y.tab.c"
    break;

  case 37:
#line 198 "lab6.y"
    {
                                                            (yyval.node) = ASTCreateNode(selection);
                                                            (yyval.node)->s1 = (yyvsp[-2].node);
                                                            (yyval.node)->s2 = ASTCreateNode(selectionBody);
                                                            (yyval.node)->s2->s1 = (yyvsp[0].node);
                                                        }
#line 1679 "y.tab.c"
    break;

  case 38:
#line 204 "lab6.y"
    {
                                                                (yyval.node) = ASTCreateNode(selection);
                                                                (yyval.node)->s1 = (yyvsp[-4].node);
                                                                (yyval.node)->s2 = ASTCreateNode(selectionBody);
                                                                (yyval.node)->s2->s1 = (yyvsp[-2].node);
                                                                (yyval.node)->s2->s2 = (yyvsp[0].node);
                                                            }
#line 1691 "y.tab.c"
    break;

  case 39:
#line 213 "lab6.y"
    {
                                                            (yyval.node) = ASTCreateNode(iteration);
                                                            (yyval.node)->s1 = (yyvsp[-2].node);
                                                            (yyval.node)->s2 = (yyvsp[0].node);
                                                        }
#line 1701 "y.tab.c"
    break;

  case 40:
#line 220 "lab6.y"
    {
                                                            (yyval.node) = ASTCreateNode(assignment);
                                                            (yyval.node)->s1 = (yyvsp[-3].node);
                                                            (yyval.node)->operator = equals;
                                                            (yyval.node)->s2 = (yyvsp[-1].node);
                                                        }
#line 1712 "y.tab.c"
    break;

  case 41:
#line 228 "lab6.y"
    {
                                                    (yyval.node) = ASTCreateNode(myReturn);
                                                    (yyval.node)->s1 = (yyvsp[-1].node);
                                                }
#line 1721 "y.tab.c"
    break;

  case 42:
#line 232 "lab6.y"
    {
                                    (yyval.node) = ASTCreateNode(myReturn);
                                }
#line 1729 "y.tab.c"
    break;

  case 43:
#line 237 "lab6.y"
    {
                                            (yyval.node) = ASTCreateNode(myRead);
                                            (yyval.node)->s1 = (yyvsp[-1].node);
                                        }
#line 1738 "y.tab.c"
    break;

  case 44:
#line 243 "lab6.y"
    {
                                                    (yyval.node) = ASTCreateNode(myWrite);
                                                    (yyval.node)->s1 = (yyvsp[-1].node);
                                                }
#line 1747 "y.tab.c"
    break;

  case 45:
#line 249 "lab6.y"
    { (yyval.node) = (yyvsp[0].node); }
#line 1753 "y.tab.c"
    break;

  case 46:
#line 252 "lab6.y"
    {
                                                    (yyval.node) = ASTCreateNode(variable);
                                                    (yyval.node)->name = (yyvsp[-3]. typeString );
                                                    (yyval.node)->s1 = (yyvsp[-1].node);
                                                }
#line 1763 "y.tab.c"
    break;

  case 47:
#line 257 "lab6.y"
    {
                        (yyval.node) = ASTCreateNode(variable);
                        (yyval.node)->name = (yyvsp[0]. typeString );
                        (yyval.node)->s1 = NULL;
                    }
#line 1773 "y.tab.c"
    break;

  case 48:
#line 264 "lab6.y"
    { (yyval.node) = (yyvsp[0].node); }
#line 1779 "y.tab.c"
    break;

  case 49:
#line 265 "lab6.y"
    {
                                                                (yyval.node) = ASTCreateNode(expression);
                                                                (yyval.node)->s1 = (yyvsp[-2].node);
                                                                (yyval.node)->operator = (yyvsp[-1]. opType );
                                                                (yyval.node)->s2 = (yyvsp[0].node);
                                                            }
#line 1790 "y.tab.c"
    break;

  case 50:
#line 273 "lab6.y"
    { (yyval. opType ) = le; }
#line 1796 "y.tab.c"
    break;

  case 51:
#line 274 "lab6.y"
    { (yyval. opType ) = lt; }
#line 1802 "y.tab.c"
    break;

  case 52:
#line 275 "lab6.y"
    { (yyval. opType ) = gt; }
#line 1808 "y.tab.c"
    break;

  case 53:
#line 276 "lab6.y"
    { (yyval. opType ) = ge; }
#line 1814 "y.tab.c"
    break;

  case 54:
#line 277 "lab6.y"
    { (yyval. opType ) = eq; }
#line 1820 "y.tab.c"
    break;

  case 55:
#line 278 "lab6.y"
    { (yyval. opType ) = ne; }
#line 1826 "y.tab.c"
    break;

  case 56:
#line 282 "lab6.y"
    { (yyval.node) = (yyvsp[0].node); }
#line 1832 "y.tab.c"
    break;

  case 57:
#line 283 "lab6.y"
    { 
                                                (yyval.node) = ASTCreateNode(expression);
                                                (yyval.node)->s1 = (yyvsp[-2].node);
                                                (yyval.node)->operator = (yyvsp[-1]. opType );
                                                (yyval.node)->s2 = (yyvsp[0].node);
                                             }
#line 1843 "y.tab.c"
    break;

  case 58:
#line 291 "lab6.y"
    { (yyval. opType ) = plus; }
#line 1849 "y.tab.c"
    break;

  case 59:
#line 292 "lab6.y"
    { (yyval. opType ) = minus; }
#line 1855 "y.tab.c"
    break;

  case 60:
#line 295 "lab6.y"
    { (yyval.node) = (yyvsp[0].node); }
#line 1861 "y.tab.c"
    break;

  case 61:
#line 296 "lab6.y"
    { 
                                        (yyval.node) = ASTCreateNode(expression);
                                        (yyval.node)->s1 = (yyvsp[-2].node);
                                        (yyval.node)->operator = (yyvsp[-1]. opType );
                                        (yyval.node)->s2 = (yyvsp[0].node);
                                    }
#line 1872 "y.tab.c"
    break;

  case 62:
#line 305 "lab6.y"
    { (yyval. opType ) = mult; }
#line 1878 "y.tab.c"
    break;

  case 63:
#line 306 "lab6.y"
    { (yyval. opType ) = division; }
#line 1884 "y.tab.c"
    break;

  case 64:
#line 307 "lab6.y"
    { (yyval. opType ) = myAnd; }
#line 1890 "y.tab.c"
    break;

  case 65:
#line 308 "lab6.y"
    { (yyval. opType ) = myOr; }
#line 1896 "y.tab.c"
    break;

  case 66:
#line 311 "lab6.y"
    { (yyval.node) = (yyvsp[-1].node); }
#line 1902 "y.tab.c"
    break;

  case 67:
#line 312 "lab6.y"
    {
                        (yyval.node) = ASTCreateNode(myNum);
                        (yyval.node)->size = (yyvsp[0]. typeInt );
                    }
#line 1911 "y.tab.c"
    break;

  case 68:
#line 316 "lab6.y"
    { (yyval.node) = (yyvsp[0].node); }
#line 1917 "y.tab.c"
    break;

  case 69:
#line 317 "lab6.y"
    { (yyval.node) = (yyvsp[0].node); }
#line 1923 "y.tab.c"
    break;

  case 70:
#line 318 "lab6.y"
    {
                            (yyval.node) = ASTCreateNode(myNum);
                            (yyval.node)->size = 1;
                        }
#line 1932 "y.tab.c"
    break;

  case 71:
#line 322 "lab6.y"
    {  
                            (yyval.node) = ASTCreateNode(myNum);
                            (yyval.node)->size = 0;
                        }
#line 1941 "y.tab.c"
    break;

  case 72:
#line 326 "lab6.y"
    { 
                                (yyval.node) = ASTCreateNode(expression);
                                (yyval.node)->operator = myNot;
                                (yyval.node)->s1 = (yyvsp[0].node);
                            }
#line 1951 "y.tab.c"
    break;

  case 73:
#line 333 "lab6.y"
    {
                                        (yyval.node) = ASTCreateNode(myCall);
                                        (yyval.node)->name = (yyvsp[-3]. typeString );
                                        (yyval.node)->s1 = (yyvsp[-1].node);
                                    }
#line 1961 "y.tab.c"
    break;

  case 74:
#line 340 "lab6.y"
    { (yyval.node) = NULL; }
#line 1967 "y.tab.c"
    break;

  case 75:
#line 341 "lab6.y"
    { (yyval.node) = (yyvsp[0].node); }
#line 1973 "y.tab.c"
    break;

  case 76:
#line 344 "lab6.y"
    { (yyval.node) = (yyvsp[0].node); }
#line 1979 "y.tab.c"
    break;

  case 77:
#line 345 "lab6.y"
    { 
                                            (yyval.node)->next = (yyvsp[0].node);
                                            (yyval.node) = (yyvsp[-2].node);
                                        }
#line 1988 "y.tab.c"
    break;


#line 1992 "y.tab.c"

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
                      yytoken, &yylval);
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


      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


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
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp);
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
#line 351 "lab6.y"


int main() 
{
    yyparse();
    ASTprint(GlobalPointer, 0);
    // Print Out
}
