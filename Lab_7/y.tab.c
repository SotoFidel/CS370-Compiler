/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "lab7.y" /* yacc.c:339  */


    /* LAB 6: C-ALGOL YACC ROUTINE*/
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
            *Tokens will be brought in from the lex routine, with some of them 
                (namely 'NUM' and 'ID') having  a type coming from a %union{}

        
        
        Date: March 20, 2020
        ADDED AST ACTION:
            *Implemented syntax directed semantic action that will generate an abstract syntax tree from
                the input.
            *Introduced the AST node, DATATYPE enum, and OPERATOR enum to the union.
            *Made some terminals and nonterminals to be of type node, and others
                to be an element of either the DATATYPE or OPERATOR enums.
            *NO PRODUCTION RULES WERE CHANGED. ONLY ACTION WAS ADDED.
    */

    int yylex();
    #include <stdio.h>
    #include <stdlib.h>
    #include <ctype.h>
    #include "ast.h"
    #include "symtable.h"
    
    extern int lineCount;
    int offset = 0;
    int maxOffset = 0;
    int globalOffset = 0;
    int level = 0;
    ASTNode *GlobalPointer;
    
    void yyerror (s)  /* Called by yyparse on error */
     char *s;
    {
        printf ("%s on line %d\n", s, lineCount);
    }


#line 116 "y.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "y.tab.h".  */
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
#line 53 "lab7.y" /* yacc.c:355  */

    int typeInt;
    char *typeString;
    struct ASTNodeType * node;
    enum DATATYPE type;
    enum OPERATOR opType;

#line 220 "y.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 237 "y.tab.c" /* yacc.c:358  */

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
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
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
#  define YYSIZE_T unsigned int
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

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
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
#define YYLAST   123

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  40
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  36
/* YYNRULES -- Number of rules.  */
#define YYNRULES  79
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  126

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   283

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
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
       0,    76,    76,    79,    80,    90,    91,    94,   114,   134,
     155,   178,   203,   206,   209,   214,   214,   233,   234,   237,
     238,   251,   261,   283,   283,   300,   301,   307,   308,   326,
     327,   328,   329,   330,   331,   332,   333,   336,   337,   340,
     352,   367,   381,   394,   398,   403,   409,   415,   418,   426,
     436,   437,   449,   450,   451,   452,   453,   454,   458,   459,
     472,   473,   476,   477,   491,   492,   493,   494,   497,   498,
     502,   503,   504,   512,   519,   531,   541,   542,   545,   550
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
  "funDeclaration", "$@1", "params", "paramsList", "param",
  "compoundStatement", "$@2", "localDeclarations", "statementList",
  "statement", "expressionStatement", "selectionStatement",
  "iterationStatement", "assignmentStatement", "returnStatement",
  "readStatement", "writeStatment", "expression", "var",
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

#define YYPACT_NINF -94

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-94)))

#define YYTABLE_NINF -18

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int8 yypact[] =
{
      49,   -94,   -94,   -94,    23,   -94,    49,   -94,    36,   -94,
     -94,   -94,   -15,     2,    38,    41,   -94,   -94,    52,    42,
     -94,    51,    53,    50,    65,    60,   -94,    63,    41,    66,
      72,    49,   -94,    67,   -94,   -94,   -94,   -94,    49,    49,
      41,    18,   -94,   -94,   -94,    40,    40,    71,    40,    11,
      40,   -94,    -8,   -94,    40,   -94,    74,    18,   -94,   -94,
     -94,   -94,   -94,   -94,   -94,    73,    69,    68,   -24,     3,
     -94,   -94,   -94,   -94,    89,    75,    77,    78,   -94,    79,
      85,    40,    40,    76,   -94,   -94,   -94,    40,   -94,   -94,
     -94,   -94,   -94,   -94,    40,   -94,   -94,    40,   -94,   -94,
     -94,   -94,    40,    18,   -94,   -94,   -94,    18,    80,    81,
      82,   -94,   -94,    57,   -24,     3,   -94,    96,   -94,   -94,
      40,   -94,   -94,    18,   -94,   -94
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    12,    13,    14,     0,     2,     3,     5,     0,     6,
       1,     4,     8,     0,     0,     0,    15,     7,     0,     8,
      10,     0,     9,    13,     0,     0,    18,    19,     0,    22,
       0,     0,    11,     0,    23,    16,    20,    21,    25,    25,
       0,    27,    26,    72,    73,     0,     0,     0,     0,     0,
       0,    69,    49,    38,     0,    30,     0,    27,    29,    31,
      32,    33,    34,    35,    36,     0,    70,    47,    50,    58,
      62,    71,    70,    74,     0,    49,     0,     0,    44,     0,
       0,     0,    76,     0,    24,    28,    37,     0,    53,    54,
      52,    55,    56,    57,     0,    60,    61,     0,    66,    67,
      64,    65,     0,     0,    45,    46,    43,     0,     0,    78,
       0,    77,    68,     0,    51,    59,    63,    39,    41,    48,
       0,    75,    42,     0,    79,    40
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -94,   -94,   106,   -94,    22,    -4,    32,   -94,   -94,   -94,
      83,   -94,    87,   -94,    84,    58,   -93,   -94,   -94,   -94,
     -94,   -94,   -94,   -94,   -45,   -41,    31,   -94,    25,   -94,
      24,   -94,   -43,   -94,   -94,     0
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     4,     5,     6,     7,    13,     8,     9,    21,    25,
      26,    27,    55,    38,    41,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    72,    67,    94,    68,    97,
      69,   102,    70,    71,   110,   111
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      66,    74,    73,    77,    79,    80,    76,    98,    99,    83,
     117,    20,    95,    96,   118,    14,    66,    15,    16,    43,
      44,    45,    81,    10,    32,    82,    43,    44,    45,    46,
     125,    17,    47,    48,    49,    50,   108,   109,    51,    52,
      78,   100,   101,    34,    54,    51,    52,    53,    43,    44,
      45,    54,     1,    24,     1,     2,     3,    23,     3,   116,
      39,    39,    66,    24,    12,    18,    66,    51,    52,    19,
      40,    40,    14,    54,    15,   109,    88,    89,    90,    91,
      92,    93,    66,    22,   -17,    28,   122,    88,    89,    90,
      91,    92,    93,    29,    30,    31,    33,    34,    37,    75,
      84,   103,    86,   107,    87,    81,   104,   105,   106,   123,
     112,   119,    11,   120,    36,    85,   121,    35,   113,   114,
     124,   115,     0,    42
};

static const yytype_int8 yycheck[] =
{
      41,    46,    45,    48,    49,    50,    47,     4,     5,    54,
     103,    15,    36,    37,   107,    30,    57,    32,    33,     8,
       9,    10,    30,     0,    28,    33,     8,     9,    10,    11,
     123,    29,    14,    15,    16,    17,    81,    82,    27,    28,
      29,    38,    39,    25,    33,    27,    28,    29,     8,     9,
      10,    33,     3,    21,     3,     6,     7,     6,     7,   102,
      38,    39,   103,    31,    28,    27,   107,    27,    28,    28,
      38,    39,    30,    33,    32,   120,    19,    20,    21,    22,
      23,    24,   123,    31,    34,    32,    29,    19,    20,    21,
      22,    23,    24,    28,    34,    32,    30,    25,    31,    28,
      26,    12,    29,    18,    35,    30,    29,    29,    29,    13,
      34,    31,     6,    32,    31,    57,    34,    30,    87,    94,
     120,    97,    -1,    39
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     6,     7,    41,    42,    43,    44,    46,    47,
       0,    42,    28,    45,    30,    32,    33,    29,    27,    28,
      45,    48,    31,     6,    46,    49,    50,    51,    32,    28,
      34,    32,    45,    30,    25,    52,    50,    31,    53,    44,
      46,    54,    54,     8,     9,    10,    11,    14,    15,    16,
      17,    27,    28,    29,    33,    52,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    68,    70,
      72,    73,    65,    72,    64,    28,    65,    64,    29,    64,
      64,    30,    33,    64,    26,    55,    29,    35,    19,    20,
      21,    22,    23,    24,    67,    36,    37,    69,     4,     5,
      38,    39,    71,    12,    29,    29,    29,    18,    64,    64,
      74,    75,    34,    66,    68,    70,    72,    56,    56,    31,
      32,    34,    29,    13,    75,    56
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    40,    41,    42,    42,    43,    43,    44,    45,    45,
      45,    45,    46,    46,    46,    48,    47,    49,    49,    50,
      50,    51,    51,    53,    52,    54,    54,    55,    55,    56,
      56,    56,    56,    56,    56,    56,    56,    57,    57,    58,
      58,    59,    60,    61,    61,    62,    63,    64,    65,    65,
      66,    66,    67,    67,    67,    67,    67,    67,    68,    68,
      69,    69,    70,    70,    71,    71,    71,    71,    72,    72,
      72,    72,    72,    72,    72,    73,    74,    74,    75,    75
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     2,     1,     1,     3,     1,     4,
       3,     6,     1,     1,     1,     0,     7,     1,     1,     1,
       3,     4,     2,     0,     5,     0,     2,     0,     2,     1,
       1,     1,     1,     1,     1,     1,     1,     2,     1,     4,
       6,     4,     4,     3,     2,     3,     3,     1,     4,     1,
       1,     3,     1,     1,     1,     1,     1,     1,     1,     3,
       1,     1,     1,     3,     1,     1,     1,     1,     3,     1,
       1,     1,     1,     1,     2,     4,     0,     1,     1,     3
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
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


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
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
  unsigned long int yylno = yyrline[yyrule];
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
                       &(yyvsp[(yyi + 1) - (yynrhs)])
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
            /* Fall through.  */
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

  return yystpcpy (yyres, yystr) - yyres;
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
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
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
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
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
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
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
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
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
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

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
| yyreduce -- Do a reduction.  |
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
#line 76 "lab7.y" /* yacc.c:1646  */
    { GlobalPointer = (yyvsp[0].node); }
#line 1406 "y.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 79 "lab7.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 1412 "y.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 80 "lab7.y" /* yacc.c:1646  */
    {
                                                    /*
                                                        Connect declarations
                                                        using the next pointer
                                                    */
                                                    (yyvsp[-1].node) -> next = (yyvsp[0].node);
                                                    (yyval.node) = (yyvsp[-1].node);
                                                }
#line 1425 "y.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 90 "lab7.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 1431 "y.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 91 "lab7.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 1437 "y.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 94 "lab7.y" /* yacc.c:1646  */
    { 
                                                        (yyval.node) = (yyvsp[-1].node);

                                                        /*
                                                        Make a node, set it equal to
                                                        our current pointer reference
                                                        ($$), and set the datatypes 
                                                        of each of the declared variables
                                                        in the list to be of the typeSpecifier.
                                                        */
                                                        struct ASTNodeType *p;
                                                        p = (yyval.node);
                                                        while (p != NULL) 
                                                        {
                                                            p->dataType = (yyvsp[-2]. type );
                                                            p = p->s1;
                                                        }
                                                    }
#line 1460 "y.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 114 "lab7.y" /* yacc.c:1646  */
    {
                                    /*
                                        Declare just a variable
                                    */
                                    if (Search((yyvsp[0]. typeString ), level, 0) != NULL)
                                    {
                                        yyerror("Duplicate Variable");
                                        yyerror((yyvsp[0]. typeString ));
                                        exit(1);
                                    }
                                    else 
                                    {
                                        Insert((yyvsp[0]. typeString ), -1, 0, level, 1, offset, NULL); //TODO: Change that -1 to the type of the variable.
                                        Display();
                                        offset = offset + 1;
                                    }
                                    (yyval.node) = ASTCreateNode(varDeclaration);
                                    (yyval.node)->name = (yyvsp[0]. typeString );
                                    (yyval.node)->size = 1;
                                }
#line 1485 "y.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 134 "lab7.y" /* yacc.c:1646  */
    {
                                    /*
                                        Declare an array
                                    */
                                    if (Search((yyvsp[-3]. typeString ), level, 0) != NULL)
                                    {
                                        yyerror("Duplicate Variable");
                                        yyerror((yyvsp[-3]. typeString ));
                                        exit(1);
                                    }
                                    else
                                    {
                                        Insert((yyvsp[-3]. typeString ), -1, 0, level, (yyvsp[-1]. typeInt ), offset, NULL);
                                        Display();
                                        offset = offset + (yyvsp[-1]. typeInt );
                                    }
                                    
                                    (yyval.node) = ASTCreateNode(varDeclaration);
                                    (yyval.node)->name = (yyvsp[-3]. typeString );
                                    (yyval.node)->size = (yyvsp[-1]. typeInt );
                                }
#line 1511 "y.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 155 "lab7.y" /* yacc.c:1646  */
    {
                                    /*
                                        Declare a comma separated list of
                                        variables (of the same type
                                        of course)
                                    */
                                    if (Search((yyvsp[-2]. typeString ), level, 0) != NULL)
                                    {
                                        yyerror("Duplicate Variable");
                                        yyerror((yyvsp[-2]. typeString ));
                                        exit(1);
                                    }
                                    else 
                                    {
                                        Insert((yyvsp[-2]. typeString ), -1, 0, level, 1, offset, NULL); //TODO: Change that -1 to the type of the variable.
                                        offset = offset + 1;
                                    }
                                    
                                    (yyval.node) = ASTCreateNode(varDeclaration);
                                    (yyval.node)->name = (yyvsp[-2]. typeString );
                                    (yyval.node)->size = 1;
                                    (yyval.node)-> s1 = (yyvsp[0].node);
                                }
#line 1539 "y.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 178 "lab7.y" /* yacc.c:1646  */
    {
                                                /*
                                                    Declare a comma separated list of
                                                    variables (of the same type
                                                    of course)
                                                */
                                                if (Search((yyvsp[-5]. typeString ), level, 0) != NULL)
                                                {
                                                    yyerror("Duplicate Variable");
                                                    yyerror((yyvsp[-5]. typeString ));
                                                    exit(1);
                                                }
                                                else
                                                {
                                                    Insert((yyvsp[-5]. typeString ), -1, 0, level, (yyvsp[-3]. typeInt ), offset, NULL);
                                                    offset = offset + (yyvsp[-3]. typeInt );
                                                }
                                                
                                                (yyval.node) = ASTCreateNode(varDeclaration);
                                                (yyval.node)->name = (yyvsp[-5]. typeString );
                                                (yyval.node)->size = (yyvsp[-3]. typeInt );
                                                (yyval.node)-> s1 = (yyvsp[0].node);
                                            }
#line 1567 "y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 203 "lab7.y" /* yacc.c:1646  */
    {
                                (yyval. type ) = intType;
                            }
#line 1575 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 206 "lab7.y" /* yacc.c:1646  */
    {
                                (yyval. type ) = voidType;
                            }
#line 1583 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 209 "lab7.y" /* yacc.c:1646  */
    {
                                (yyval. type ) = boolType;
                            }
#line 1591 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 214 "lab7.y" /* yacc.c:1646  */
    {globalOffset = offset; offset = 0;}
#line 1597 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 214 "lab7.y" /* yacc.c:1646  */
    {
                                                                                /*
                                                                                    Declare a function with a 
                                                                                    return type. If there
                                                                                    are no parameters
                                                                                    in the function, then 
                                                                                    there should at
                                                                                    least be a 'void' in there
                                                                                */
                                                                                (yyval.node) = ASTCreateNode(funDeclaration);
                                                                                (yyval.node)->name = (yyvsp[-5]. typeString );
                                                                                (yyval.node)->dataType = (yyvsp[-6]. type );
                                                                                (yyval.node)->s1 = (yyvsp[-2].node);
                                                                                (yyval.node)->s2 = (yyvsp[0].node);

                                                                                offset = globalOffset;
                                                                            }
#line 1619 "y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 233 "lab7.y" /* yacc.c:1646  */
    { (yyval.node) = NULL; }
#line 1625 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 234 "lab7.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 1631 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 237 "lab7.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 1637 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 238 "lab7.y" /* yacc.c:1646  */
    {
                                            /*
                                                Each parameter must have its own type
                                                specifier, and it can be just one parameter
                                                or a comma separated list of parameters, again,
                                                each with its own type specifier. Connected by 
                                                the 'next' pointer
                                            */
                                            (yyval.node)->next = (yyvsp[0].node);
                                            (yyval.node) = (yyvsp[-2].node);
                                        }
#line 1653 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 251 "lab7.y" /* yacc.c:1646  */
    {
                                                        /*
                                                            Array parameter
                                                        */
                                                        
                                                        (yyval.node) = ASTCreateNode(param);
                                                        (yyval.node)->dataType = (yyvsp[-3]. type );
                                                        (yyval.node)->name = (yyvsp[-2]. typeString );
                                                        (yyval.node)->size = -1;
                                                    }
#line 1668 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 261 "lab7.y" /* yacc.c:1646  */
    {
                                        /*
                                            Regular parameter
                                        */
                                        if (Search((yyvsp[0]. typeString ), level + 1, 0) != NULL)
                                        {
                                            yyerror("Duplicate Variable");
                                            yyerror((yyvsp[0]. typeString ));
                                            exit(1);
                                        }
                                        else 
                                        {
                                            Insert((yyvsp[0]. typeString ), (yyvsp[-1]. type ), 0, level + 1, 1, offset, NULL);
                                            offset = offset + 1;
                                        }
                                        (yyval.node) = ASTCreateNode(param);
                                        (yyval.node)->dataType = (yyvsp[-1]. type );
                                        (yyval.node)->name = (yyvsp[0]. typeString );
                                        (yyval.node)->size = 0;
                                    }
#line 1693 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 283 "lab7.y" /* yacc.c:1646  */
    { level++; }
#line 1699 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 283 "lab7.y" /* yacc.c:1646  */
    {
                                                                        /*
                                                                            Usually follows a function
                                                                            declaration, selection statement,
                                                                            or iteration statement. In any scope,
                                                                            make sure that the variable
                                                                            declarations are put before anything
                                                                            else, or else get a syntax error.
                                                                        */
                                                                        (yyval.node) = ASTCreateNode(body);
                                                                        (yyval.node)->s1 = (yyvsp[-2].node);
                                                                        (yyval.node)->s2 = (yyvsp[-1].node);
                                                                        offset -= Delete(level);
                                                                        level--;
                                                                             }
#line 1719 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 300 "lab7.y" /* yacc.c:1646  */
    { (yyval.node) = NULL; }
#line 1725 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 301 "lab7.y" /* yacc.c:1646  */
    { 
                                                        (yyvsp[-1].node)->next = (yyvsp[0].node);
                                                        (yyval.node) = (yyvsp[-1].node);
                                                    }
#line 1734 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 307 "lab7.y" /* yacc.c:1646  */
    { (yyval.node) = NULL; }
#line 1740 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 308 "lab7.y" /* yacc.c:1646  */
    {
                                            /*
                                                Without this check, we get a sef fault
                                                because we could just have no statement, 
                                                but a statement list followed afterwards.
                                            */
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
#line 1761 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 326 "lab7.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 1767 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 327 "lab7.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 1773 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 328 "lab7.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 1779 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 329 "lab7.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 1785 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 330 "lab7.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 1791 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 331 "lab7.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 1797 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 332 "lab7.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 1803 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 333 "lab7.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 1809 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 336 "lab7.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[-1].node); }
#line 1815 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 337 "lab7.y" /* yacc.c:1646  */
    { (yyval.node) = NULL; }
#line 1821 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 340 "lab7.y" /* yacc.c:1646  */
    {
                                                            /*
                                                                For selection statement, we need to make
                                                                a separate node whose s1 pointer
                                                                will be the positive statement, and
                                                                s2 will be null.
                                                            */
                                                            (yyval.node) = ASTCreateNode(selection);
                                                            (yyval.node)->s1 = (yyvsp[-2].node);
                                                            (yyval.node)->s2 = ASTCreateNode(selectionBody);
                                                            (yyval.node)->s2->s1 = (yyvsp[0].node);
                                                        }
#line 1838 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 352 "lab7.y" /* yacc.c:1646  */
    {
                                                                /*
                                                                    For selection statement, we need to make
                                                                    a separate node whose s1 pointer
                                                                    will be the positive statement, and
                                                                    s2 will be the negative statement
                                                                */
                                                                (yyval.node) = ASTCreateNode(selection);
                                                                (yyval.node)->s1 = (yyvsp[-4].node);
                                                                (yyval.node)->s2 = ASTCreateNode(selectionBody);
                                                                (yyval.node)->s2->s1 = (yyvsp[-2].node);
                                                                (yyval.node)->s2->s2 = (yyvsp[0].node);
                                                            }
#line 1856 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 367 "lab7.y" /* yacc.c:1646  */
    {
                                                            /*
                                                                Unlike the selection statement,
                                                                it is ok to just make the 
                                                                iteration statement s1 and s2 connect,
                                                                where s1 is the condition and s2 is
                                                                the body.
                                                            */
                                                            (yyval.node) = ASTCreateNode(iteration);
                                                            (yyval.node)->s1 = (yyvsp[-2].node);
                                                            (yyval.node)->s2 = (yyvsp[0].node);
                                                        }
#line 1873 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 381 "lab7.y" /* yacc.c:1646  */
    {
                                                            /*
                                                                We need to make a new node type
                                                                for assignment since '=' is not
                                                                defined in the relop terminal.
                                                            */
                                                            (yyval.node) = ASTCreateNode(assignment);
                                                            (yyval.node)->s1 = (yyvsp[-3].node);
                                                            (yyval.node)->operator = equals;
                                                            (yyval.node)->s2 = (yyvsp[-1].node);
                                                        }
#line 1889 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 394 "lab7.y" /* yacc.c:1646  */
    {
                                                    (yyval.node) = ASTCreateNode(myReturn);
                                                    (yyval.node)->s1 = (yyvsp[-1].node);
                                                }
#line 1898 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 398 "lab7.y" /* yacc.c:1646  */
    {
                                    (yyval.node) = ASTCreateNode(myReturn);
                                }
#line 1906 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 403 "lab7.y" /* yacc.c:1646  */
    {
                                            (yyval.node) = ASTCreateNode(myRead);
                                            (yyval.node)->s1 = (yyvsp[-1].node);
                                        }
#line 1915 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 409 "lab7.y" /* yacc.c:1646  */
    {
                                                    (yyval.node) = ASTCreateNode(myWrite);
                                                    (yyval.node)->s1 = (yyvsp[-1].node);
                                                }
#line 1924 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 415 "lab7.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 1930 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 418 "lab7.y" /* yacc.c:1646  */
    {
                                                    /*
                                                        Array reference
                                                    */
                                                    (yyval.node) = ASTCreateNode(variable);
                                                    (yyval.node)->name = (yyvsp[-3]. typeString );
                                                    (yyval.node)->s1 = (yyvsp[-1].node);
                                                }
#line 1943 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 426 "lab7.y" /* yacc.c:1646  */
    {
                        /*
                            Variable reference
                        */
                        (yyval.node) = ASTCreateNode(variable);
                        (yyval.node)->name = (yyvsp[0]. typeString );
                        (yyval.node)->s1 = NULL;
                    }
#line 1956 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 436 "lab7.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 1962 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 437 "lab7.y" /* yacc.c:1646  */
    {
                                                                /*
                                                                    Compare simpleExpression (LHS) to the
                                                                    additiveExpression (RHS)
                                                                */
                                                                (yyval.node) = ASTCreateNode(expression);
                                                                (yyval.node)->s1 = (yyvsp[-2].node);
                                                                (yyval.node)->operator = (yyvsp[-1]. opType );
                                                                (yyval.node)->s2 = (yyvsp[0].node);
                                                            }
#line 1977 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 449 "lab7.y" /* yacc.c:1646  */
    { (yyval. opType ) = le; }
#line 1983 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 450 "lab7.y" /* yacc.c:1646  */
    { (yyval. opType ) = lt; }
#line 1989 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 451 "lab7.y" /* yacc.c:1646  */
    { (yyval. opType ) = gt; }
#line 1995 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 452 "lab7.y" /* yacc.c:1646  */
    { (yyval. opType ) = ge; }
#line 2001 "y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 453 "lab7.y" /* yacc.c:1646  */
    { (yyval. opType ) = eq; }
#line 2007 "y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 454 "lab7.y" /* yacc.c:1646  */
    { (yyval. opType ) = ne; }
#line 2013 "y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 458 "lab7.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 2019 "y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 459 "lab7.y" /* yacc.c:1646  */
    { 
                                                /*
                                                    LHS = s1
                                                    operator is addop
                                                    RHS = s2
                                                */
                                                (yyval.node) = ASTCreateNode(expression);
                                                (yyval.node)->s1 = (yyvsp[-2].node);
                                                (yyval.node)->operator = (yyvsp[-1]. opType );
                                                (yyval.node)->s2 = (yyvsp[0].node);
                                             }
#line 2035 "y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 472 "lab7.y" /* yacc.c:1646  */
    { (yyval. opType ) = plus; }
#line 2041 "y.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 473 "lab7.y" /* yacc.c:1646  */
    { (yyval. opType ) = minus; }
#line 2047 "y.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 476 "lab7.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 2053 "y.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 477 "lab7.y" /* yacc.c:1646  */
    { 
                                        /*
                                            LHS = term
                                            operator = multop (can be '*'' '/' ' 'AND' or 'OR')
                                            RHS = the factor
                                        */
                                        (yyval.node) = ASTCreateNode(expression);
                                        (yyval.node)->s1 = (yyvsp[-2].node);
                                        (yyval.node)->operator = (yyvsp[-1]. opType );
                                        (yyval.node)->s2 = (yyvsp[0].node);
                                    }
#line 2069 "y.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 491 "lab7.y" /* yacc.c:1646  */
    { (yyval. opType ) = mult; }
#line 2075 "y.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 492 "lab7.y" /* yacc.c:1646  */
    { (yyval. opType ) = division; }
#line 2081 "y.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 493 "lab7.y" /* yacc.c:1646  */
    { (yyval. opType ) = myAnd; }
#line 2087 "y.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 494 "lab7.y" /* yacc.c:1646  */
    { (yyval. opType ) = myOr; }
#line 2093 "y.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 497 "lab7.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[-1].node); }
#line 2099 "y.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 498 "lab7.y" /* yacc.c:1646  */
    {
                        (yyval.node) = ASTCreateNode(myNum);
                        (yyval.node)->size = (yyvsp[0]. typeInt );
                    }
#line 2108 "y.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 502 "lab7.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 2114 "y.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 503 "lab7.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 2120 "y.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 504 "lab7.y" /* yacc.c:1646  */
    {
                            /*
                                This will be a number, and its value will be 
                                1
                            */
                            (yyval.node) = ASTCreateNode(myNum);
                            (yyval.node)->size = 1;
                        }
#line 2133 "y.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 512 "lab7.y" /* yacc.c:1646  */
    {
                            /*
                                This will be a number, and its value will be 0
                            */
                            (yyval.node) = ASTCreateNode(myNum);
                            (yyval.node)->size = 0;
                        }
#line 2145 "y.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 519 "lab7.y" /* yacc.c:1646  */
    {
                                /*
                                    Just for this, we need to make it
                                    an expression rather than an enum because
                                    of the 'NOT' operator.
                                */
                                (yyval.node) = ASTCreateNode(expression);
                                (yyval.node)->operator = myNot;
                                (yyval.node)->s1 = (yyvsp[0].node);
                            }
#line 2160 "y.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 531 "lab7.y" /* yacc.c:1646  */
    {
                                        /*
                                            Function call with arguments
                                        */
                                        (yyval.node) = ASTCreateNode(myCall);
                                        (yyval.node)->name = (yyvsp[-3]. typeString );
                                        (yyval.node)->s1 = (yyvsp[-1].node);
                                    }
#line 2173 "y.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 541 "lab7.y" /* yacc.c:1646  */
    { (yyval.node) = NULL; }
#line 2179 "y.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 542 "lab7.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 2185 "y.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 545 "lab7.y" /* yacc.c:1646  */
    { 
                                    (yyval.node) = ASTCreateNode(argslist);
                                    (yyval.node)->s1 = (yyvsp[0].node);
                                    (yyval.node)->next = NULL; 
                               }
#line 2195 "y.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 550 "lab7.y" /* yacc.c:1646  */
    {
                                            /*
                                                List of arguments, connected using
                                                the 'next' pointer
                                            */
                                            (yyval.node) = ASTCreateNode(argslist);
                                            (yyval.node)->next = (yyvsp[0].node);
                                            (yyval.node)->s1 = (yyvsp[-2].node);
                                        }
#line 2209 "y.tab.c" /* yacc.c:1646  */
    break;


#line 2213 "y.tab.c" /* yacc.c:1646  */
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

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

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

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

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
#line 561 "lab7.y" /* yacc.c:1906  */


int main() 
{
    yyparse();
    // ASTprint(GlobalPointer, 0);
    // Print Out
}
