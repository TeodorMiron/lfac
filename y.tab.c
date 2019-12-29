/* A Bison parser, made by GNU Bison 3.4.1.  */

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
#define YYBISON_VERSION "3.4.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "experiment_hash.y"

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include </usr/include/glib-2.0/glib.h>

extern FILE* yyin;
extern int yylineno;
int yydebug=1;
int yylex();
int yyerror(char *s);

struct SymTabEntry
{
        char*name;
        char*scope;
        char*whatIs;
        char*dataType;
        int intvalue;
        int lineOf;
        char*stringval;
        char charvalue;
        float floatvalue;
        char*paramlist;

} SymTabEntry;
struct ListOfEntries
{
        struct SymTabEntry value;
        struct ListOfEntries*next;
} ListOfEntries;

struct Checker
{
        GHashTable*localScope;
        int counter;
        char*currentScope;
        struct Checker*next;

};
struct Checker*head=NULL;
FILE*SymTabDump=NULL;
int currLine;
void init_prg();
void free_entry(struct ListOfEntries*val);
void add_new_variable(const char*type,char*identifier);
void add_func_node(char*identifier,const char*returntype,char*arg_list);
void add_statement_node();
void add_class_node(char*identifier);
void add_main_node();
const char*return_type(int type);
void add_new_node(struct Checker*head);
void remove_node();
void search_every_class(gpointer key,gpointer value,gpointer userdata);
void print_key_value(gpointer key,gpointer value,gpointer userdata);


#line 128 "y.tab.c"

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
    START = 258,
    END = 259,
    ASSIGN = 260,
    IF = 261,
    ELSEIF = 262,
    WHILE = 263,
    FOR = 264,
    STRCPY = 265,
    STRLEN = 266,
    STRCMP = 267,
    STRCAT = 268,
    ADD = 269,
    DIV = 270,
    BIGGER = 271,
    SMALLER = 272,
    MIN = 273,
    MUL = 274,
    EQUAL = 275,
    OPEN_ROUND_BRACKET = 276,
    CLOSE_ROUND_BRACKET = 277,
    CLOSE_CURLY_BRACKET = 278,
    OPEN_CURLY_BRACKET = 279,
    INCR = 280,
    CLASS = 281,
    MAIN = 282,
    ELSE = 283,
    SMALLER_EQUAL = 284,
    BOOL_TRUE = 285,
    BOOL_FALSE = 286,
    GREATER_EQUAL = 287,
    STRING_TYPE = 288,
    CONST = 289,
    RETURN = 290,
    ID = 291,
    INT_VAL = 292,
    STRING_VAL = 293,
    FLOAT_VAL = 294,
    CHAR_VAL = 295,
    INT = 296,
    STRING = 297,
    FLOAT = 298,
    CHAR = 299,
    BOOL = 300,
    VOID = 301
  };
#endif
/* Tokens.  */
#define START 258
#define END 259
#define ASSIGN 260
#define IF 261
#define ELSEIF 262
#define WHILE 263
#define FOR 264
#define STRCPY 265
#define STRLEN 266
#define STRCMP 267
#define STRCAT 268
#define ADD 269
#define DIV 270
#define BIGGER 271
#define SMALLER 272
#define MIN 273
#define MUL 274
#define EQUAL 275
#define OPEN_ROUND_BRACKET 276
#define CLOSE_ROUND_BRACKET 277
#define CLOSE_CURLY_BRACKET 278
#define OPEN_CURLY_BRACKET 279
#define INCR 280
#define CLASS 281
#define MAIN 282
#define ELSE 283
#define SMALLER_EQUAL 284
#define BOOL_TRUE 285
#define BOOL_FALSE 286
#define GREATER_EQUAL 287
#define STRING_TYPE 288
#define CONST 289
#define RETURN 290
#define ID 291
#define INT_VAL 292
#define STRING_VAL 293
#define FLOAT_VAL 294
#define CHAR_VAL 295
#define INT 296
#define STRING 297
#define FLOAT 298
#define CHAR 299
#define BOOL 300
#define VOID 301

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 60 "experiment_hash.y"

        int type;
        char*strname;
        int intval;
        char* strval;
        _Bool boolval;
        char charval;
        float floatval;
        struct expr_info* expr_ptr;

#line 274 "y.tab.c"

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
#define YYFINAL  17
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   454

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  54
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  46
/* YYNRULES -- Number of rules.  */
#define YYNRULES  108
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  203

#define YYUNDEFTOK  2
#define YYMAXUTOK   301

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
       2,     2,     2,     2,     2,    49,    50,     2,     2,     2,
       2,     2,     2,     2,    47,     2,    53,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    48,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    51,     2,    52,     2,     2,     2,     2,     2,     2,
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
      45,    46
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    95,    95,    96,    97,   100,   101,   104,   105,   106,
     110,   110,   111,   111,   114,   115,   116,   119,   120,   123,
     123,   124,   124,   127,   128,   131,   132,   135,   136,   139,
     140,   143,   144,   145,   146,   147,   148,   149,   152,   153,
     157,   158,   161,   161,   161,   162,   162,   162,   165,   165,
     166,   166,   167,   170,   170,   171,   171,   174,   175,   176,
     180,   180,   181,   181,   182,   182,   185,   187,   191,   200,
     203,   204,   232,   233,   234,   248,   249,   250,   251,   252,
     253,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   280,   324,   327,   330,   330,   331,   331
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "START", "END", "ASSIGN", "IF", "ELSEIF",
  "WHILE", "FOR", "STRCPY", "STRLEN", "STRCMP", "STRCAT", "ADD", "DIV",
  "BIGGER", "SMALLER", "MIN", "MUL", "EQUAL", "OPEN_ROUND_BRACKET",
  "CLOSE_ROUND_BRACKET", "CLOSE_CURLY_BRACKET", "OPEN_CURLY_BRACKET",
  "INCR", "CLASS", "MAIN", "ELSE", "SMALLER_EQUAL", "BOOL_TRUE",
  "BOOL_FALSE", "GREATER_EQUAL", "STRING_TYPE", "CONST", "RETURN", "ID",
  "INT_VAL", "STRING_VAL", "FLOAT_VAL", "CHAR_VAL", "INT", "STRING",
  "FLOAT", "CHAR", "BOOL", "VOID", "','", "';'", "'#'", "'$'", "'['",
  "']'", "'.'", "$accept", "start_program", "declaration_section",
  "declaration_content", "object_declaration", "$@1", "$@2",
  "object_content", "inside_object", "function_declaration", "$@3", "$@4",
  "return_statement", "list_param", "function_content",
  "multiple_statements", "statements", "function_call", "list_call",
  "if_statement", "$@5", "$@6", "$@7", "$@8", "else_statement", "$@9",
  "$@10", "while_statement", "$@11", "$@12", "assign_statement",
  "for_statement", "$@13", "$@14", "$@15", "create_variable",
  "create_array_variable", "create_single_variable", "available_types",
  "expression", "object_call_function", "object_access_var",
  "access_vector", "main_section", "$@16", "$@17", YY_NULLPTR
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
     295,   296,   297,   298,   299,   300,   301,    44,    59,    35,
      36,    91,    93,    46
};
# endif

#define YYPACT_NINF -119

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-119)))

#define YYTABLE_NINF -108

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      26,    13,     7,   -43,    28,    26,  -119,  -119,  -119,  -119,
    -119,    39,   402,    20,    21,   206,  -119,  -119,  -119,  -119,
      29,  -119,  -119,  -119,  -119,  -119,  -119,  -119,    36,    43,
      57,    54,    62,    63,   228,  -119,  -119,   273,  -119,  -119,
    -119,    64,   228,    37,  -119,   315,  -119,  -119,  -119,    80,
     402,   402,   140,    79,   228,   228,   228,    58,   228,   368,
    -119,    71,  -119,   162,   276,    77,    82,   228,   228,   228,
     228,   228,   228,   228,    98,    99,  -119,   250,   -18,  -119,
    -119,  -119,   422,  -119,    78,   377,    78,   288,  -119,  -119,
      92,   103,   149,    97,  -119,   324,   434,    48,   115,    18,
     231,   253,  -119,   -19,   113,   120,   311,   108,  -119,  -119,
     386,  -119,   395,   116,  -119,   119,   228,   335,  -119,   122,
     109,   184,     3,  -119,  -119,  -119,  -119,  -119,  -119,  -119,
     -19,   126,  -119,  -119,  -119,  -119,  -119,  -119,  -119,  -119,
     153,   228,   133,   404,    89,   331,   -12,  -119,  -119,    52,
    -119,  -119,   150,   228,    38,   -26,   228,   163,  -119,  -119,
       2,   166,   178,    58,  -119,  -119,   422,  -119,   180,   228,
     181,   183,  -119,   413,   -19,   186,   -19,   195,   215,    55,
    -119,   111,  -119,   202,  -119,   200,  -119,   207,   200,   205,
    -119,   -19,   209,  -119,   217,   159,  -119,   -19,   229,  -119,
     164,  -119,  -119
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       4,     0,     0,     0,     0,     0,     6,     8,     7,     9,
       3,     0,     0,     0,     0,     0,    66,     1,     5,     2,
       0,    75,    79,    77,    76,    78,    80,    26,     0,     0,
      10,     0,     0,     0,     0,    84,    85,    81,    82,    86,
      83,     0,     0,    87,    67,     0,    88,    89,    90,     0,
       0,     0,     0,     0,     0,     0,     0,    81,     0,     0,
      71,     0,    70,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   105,     0,    25,     0,     0,    15,
      17,    18,    16,    13,     0,     0,     0,     0,    91,   103,
       0,     0,    41,     0,   102,     0,    92,    94,    96,    97,
      95,    93,    98,     0,     0,    19,    81,     0,    11,    14,
       0,   100,     0,     0,    39,     0,     0,   104,    73,    72,
       0,     0,     0,    30,    31,    32,    34,    33,    35,   108,
       0,     0,    99,   101,   104,    38,    40,    69,    68,    74,
       0,     0,     0,     0,    87,     0,    88,   106,    29,    24,
      28,    22,     0,     0,     0,     0,     0,     0,    27,    64,
       0,     0,     0,    57,    58,    59,    23,    20,     0,     0,
      42,    53,    65,     0,     0,     0,     0,     0,     0,     0,
      46,     0,    56,     0,    43,    52,    54,    60,    52,     0,
      47,     0,     0,    44,    48,     0,    63,     0,     0,    61,
       0,    51,    49
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -119,  -119,  -119,   248,  -119,  -119,  -119,  -119,   176,   -46,
    -119,  -119,  -119,  -119,  -119,    34,  -118,   135,   146,  -119,
    -119,  -119,  -119,  -119,    84,  -119,  -119,  -119,  -119,  -119,
     154,  -119,  -119,  -119,  -119,     8,  -119,  -119,   -36,   -15,
     155,   123,   127,   270,  -119,  -119
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     4,     5,     6,     7,    52,    53,    78,    79,     8,
     130,   131,   157,    13,   149,   122,   123,    43,    91,   124,
     174,   188,   175,   185,   190,   197,   198,   125,   176,   177,
     126,   127,   191,   192,   168,   128,    44,    16,    27,    59,
      46,    47,    48,    10,   103,   104
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      45,    62,   120,   107,   148,   108,    80,    15,     9,   -37,
     163,   -37,   150,     9,    75,    76,    67,    68,    69,    70,
      71,    72,    73,   -37,   120,    58,   147,    64,    17,   121,
       3,   158,    80,    14,    69,    11,   -37,    82,    73,    84,
      85,    86,    28,    87,   161,    30,   162,     1,    92,    12,
     169,   121,    96,    97,    98,    99,   100,   101,   102,   119,
      81,   148,     2,   148,    69,    70,    20,    29,    73,   110,
      49,   112,    50,   120,     3,    54,   120,   148,   184,    51,
     -12,   138,   148,    55,    56,    63,    81,   156,    31,    32,
      65,    33,    67,    68,    69,    70,    71,    72,    73,    34,
     121,    92,    83,   121,    74,   143,   145,    89,    35,    36,
     -36,    61,   -36,    94,    57,    38,    39,    40,    95,    31,
      32,  -107,    33,   105,   -36,   115,   145,    41,   114,    58,
      34,   140,   120,   117,   186,    73,   129,   -36,   160,    35,
      36,   166,    65,   -21,    12,    57,    38,    39,    40,   151,
      31,    32,   134,    33,   173,   135,   139,   141,    41,   121,
      58,    77,   152,    67,    68,    69,    70,    71,    72,    73,
      35,    36,    31,    32,   159,    33,    57,    38,    39,    40,
     120,   153,   199,    34,    90,   120,   167,   202,     3,    41,
     170,    58,    35,    36,    31,    32,   116,    33,    57,    38,
      39,    40,   171,   172,   -45,    34,   -55,   121,   179,   180,
     181,    41,   121,    58,    35,    36,    31,    32,   182,    33,
      57,    38,    39,    40,   183,   195,   187,    34,   189,   194,
     -62,   200,   196,    41,    15,    58,    35,    36,    31,    32,
     -50,    33,    37,    38,    39,    40,    68,    69,    70,    34,
      72,    73,   201,    18,   109,    41,   144,    42,    35,    36,
      31,    32,   136,    33,    57,    38,    39,    40,    68,    69,
      70,    34,   193,    73,   142,    19,   146,    41,   164,    58,
      35,    36,   165,     0,     0,     0,   106,    38,    39,    40,
      67,    68,    69,    70,    71,    72,    73,     0,     0,    41,
       0,    58,    67,    68,    69,    70,    71,    72,    73,    60,
       0,     0,     0,     0,    21,    22,    23,    24,    25,    26,
      66,     0,     0,     0,     0,     0,    61,     0,    93,    67,
      68,    69,    70,    71,    72,    73,   155,     0,     0,     0,
     113,     0,     0,     0,     0,    67,    68,    69,    70,    71,
      72,    73,    21,    22,    23,    24,    25,    26,     0,     0,
     118,     0,     0,     0,    61,    21,    22,    23,    24,    25,
      26,   137,     0,     0,     0,     0,    21,    22,    23,    24,
      25,    26,    67,    68,    69,    70,    71,    72,    73,     0,
      88,    67,    68,    69,    70,    71,    72,    73,     0,   111,
      67,    68,    69,    70,    71,    72,    73,     0,   132,    67,
      68,    69,    70,    71,    72,    73,     0,   133,    67,    68,
      69,    70,    71,    72,    73,     0,   154,    67,    68,    69,
      70,    71,    72,    73,     0,   178,    67,    68,    69,    70,
      71,    72,    73,    21,    22,    23,    24,    25,    26,    68,
      69,    70,    71,    72,    73
};

static const yytype_int16 yycheck[] =
{
      15,    37,    21,    21,   122,    23,    52,    50,     0,    21,
      36,    23,   130,     5,    50,    51,    14,    15,    16,    17,
      18,    19,    20,    35,    21,    51,    23,    42,     0,    48,
      48,   149,    78,    26,    16,    22,    48,    52,    20,    54,
      55,    56,    22,    58,     6,    24,     8,    21,    63,    36,
      48,    48,    67,    68,    69,    70,    71,    72,    73,    95,
      52,   179,    36,   181,    16,    17,    27,    47,    20,    84,
      41,    86,    36,    21,    48,    21,    21,   195,    23,    36,
      23,   117,   200,    21,    21,    21,    78,    35,    10,    11,
      53,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      48,   116,    23,    48,    24,   120,   121,    36,    30,    31,
      21,    53,    23,    36,    36,    37,    38,    39,    36,    10,
      11,    23,    13,    24,    35,    22,   141,    49,    36,    51,
      21,    22,    21,    36,    23,    20,    23,    48,   153,    30,
      31,   156,    53,    23,    36,    36,    37,    38,    39,    23,
      10,    11,    36,    13,   169,    36,    34,    48,    49,    48,
      51,    21,     9,    14,    15,    16,    17,    18,    19,    20,
      30,    31,    10,    11,    24,    13,    36,    37,    38,    39,
      21,    48,    23,    21,    22,    21,    23,    23,    48,    49,
      24,    51,    30,    31,    10,    11,    47,    13,    36,    37,
      38,    39,    24,    23,    23,    21,    23,    48,   174,    23,
     176,    49,    48,    51,    30,    31,    10,    11,    23,    13,
      36,    37,    38,    39,     9,   191,    24,    21,    28,    24,
      23,   197,    23,    49,    50,    51,    30,    31,    10,    11,
      23,    13,    36,    37,    38,    39,    15,    16,    17,    21,
      19,    20,    23,     5,    78,    49,   121,    51,    30,    31,
      10,    11,   116,    13,    36,    37,    38,    39,    15,    16,
      17,    21,   188,    20,   120,     5,   121,    49,   155,    51,
      30,    31,   155,    -1,    -1,    -1,    36,    37,    38,    39,
      14,    15,    16,    17,    18,    19,    20,    -1,    -1,    49,
      -1,    51,    14,    15,    16,    17,    18,    19,    20,    36,
      -1,    -1,    -1,    -1,    41,    42,    43,    44,    45,    46,
       5,    -1,    -1,    -1,    -1,    -1,    53,    -1,    52,    14,
      15,    16,    17,    18,    19,    20,     5,    -1,    -1,    -1,
      52,    -1,    -1,    -1,    -1,    14,    15,    16,    17,    18,
      19,    20,    41,    42,    43,    44,    45,    46,    -1,    -1,
      36,    -1,    -1,    -1,    53,    41,    42,    43,    44,    45,
      46,    36,    -1,    -1,    -1,    -1,    41,    42,    43,    44,
      45,    46,    14,    15,    16,    17,    18,    19,    20,    -1,
      22,    14,    15,    16,    17,    18,    19,    20,    -1,    22,
      14,    15,    16,    17,    18,    19,    20,    -1,    22,    14,
      15,    16,    17,    18,    19,    20,    -1,    22,    14,    15,
      16,    17,    18,    19,    20,    -1,    22,    14,    15,    16,
      17,    18,    19,    20,    -1,    22,    14,    15,    16,    17,
      18,    19,    20,    41,    42,    43,    44,    45,    46,    15,
      16,    17,    18,    19,    20
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    21,    36,    48,    55,    56,    57,    58,    63,    89,
      97,    22,    36,    67,    26,    50,    91,     0,    57,    97,
      27,    41,    42,    43,    44,    45,    46,    92,    22,    47,
      24,    10,    11,    13,    21,    30,    31,    36,    37,    38,
      39,    49,    51,    71,    90,    93,    94,    95,    96,    41,
      36,    36,    59,    60,    21,    21,    21,    36,    51,    93,
      36,    53,    92,    21,    93,    53,     5,    14,    15,    16,
      17,    18,    19,    20,    24,    92,    92,    21,    61,    62,
      63,    89,    93,    23,    93,    93,    93,    93,    22,    36,
      22,    72,    93,    52,    36,    36,    93,    93,    93,    93,
      93,    93,    93,    98,    99,    24,    36,    21,    23,    62,
      93,    22,    93,    52,    36,    22,    47,    36,    36,    92,
      21,    48,    69,    70,    73,    81,    84,    85,    89,    23,
      64,    65,    22,    22,    36,    36,    72,    36,    92,    34,
      22,    48,    84,    93,    71,    93,    94,    23,    70,    68,
      70,    23,     9,    48,    22,     5,    35,    66,    70,    24,
      93,     6,     8,    36,    95,    96,    93,    23,    88,    48,
      24,    24,    23,    93,    74,    76,    82,    83,    22,    69,
      23,    69,    23,     9,    23,    77,    23,    24,    75,    28,
      78,    86,    87,    78,    24,    69,    23,    79,    80,    23,
      69,    23,    23
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    54,    55,    55,    55,    56,    56,    57,    57,    57,
      59,    58,    60,    58,    61,    61,    61,    62,    62,    64,
      63,    65,    63,    66,    66,    67,    67,    68,    68,    69,
      69,    70,    70,    70,    70,    70,    70,    70,    71,    71,
      72,    72,    74,    75,    73,    76,    77,    73,    79,    78,
      80,    78,    78,    82,    81,    83,    81,    84,    84,    84,
      86,    85,    87,    85,    88,    85,    89,    89,    90,    90,
      91,    91,    91,    91,    91,    92,    92,    92,    92,    92,
      92,    93,    93,    93,    93,    93,    93,    93,    93,    93,
      93,    93,    93,    93,    93,    93,    93,    93,    93,    93,
      93,    93,    94,    95,    96,    98,    97,    99,    97
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     1,     0,     2,     1,     1,     1,     1,
       0,     6,     0,     5,     2,     1,     1,     1,     1,     0,
      10,     0,     8,     2,     0,     4,     2,     2,     1,     2,
       1,     1,     1,     1,     1,     1,     2,     2,     5,     4,
       3,     1,     0,     0,    10,     0,     0,     9,     0,     5,
       0,     4,     0,     0,     8,     0,     7,     4,     4,     4,
       0,    12,     0,    11,     0,     6,     2,     3,     5,     5,
       3,     3,     5,     5,     6,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     3,     3,     3,     3,     3,     3,     3,     3,     5,
       4,     5,     3,     3,     4,     0,     8,     0,     7
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
  YYUSE (yytype);
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
#line 95 "experiment_hash.y"
    {printf("Programul este corect\n");}
#line 1570 "y.tab.c"
    break;

  case 3:
#line 96 "experiment_hash.y"
    {printf("Programul este corect\n");}
#line 1576 "y.tab.c"
    break;

  case 4:
#line 97 "experiment_hash.y"
    {printf("Programul este corect!\n");}
#line 1582 "y.tab.c"
    break;

  case 10:
#line 110 "experiment_hash.y"
    {add_class_node((yyvsp[-2].strname));}
#line 1588 "y.tab.c"
    break;

  case 11:
#line 110 "experiment_hash.y"
    {remove_node();}
#line 1594 "y.tab.c"
    break;

  case 12:
#line 111 "experiment_hash.y"
    {add_class_node((yyvsp[-2].strname));}
#line 1600 "y.tab.c"
    break;

  case 19:
#line 123 "experiment_hash.y"
    {add_func_node((yyvsp[-2].strname),return_type((yyvsp[-1].type)),NULL);}
#line 1606 "y.tab.c"
    break;

  case 20:
#line 123 "experiment_hash.y"
    {remove_node();}
#line 1612 "y.tab.c"
    break;

  case 21:
#line 124 "experiment_hash.y"
    {add_func_node((yyvsp[-2].strname),return_type((yyvsp[-1].type)),NULL);}
#line 1618 "y.tab.c"
    break;

  case 22:
#line 124 "experiment_hash.y"
    {remove_node();}
#line 1624 "y.tab.c"
    break;

  case 42:
#line 161 "experiment_hash.y"
    {add_statement_node();}
#line 1630 "y.tab.c"
    break;

  case 43:
#line 161 "experiment_hash.y"
    {remove_node();}
#line 1636 "y.tab.c"
    break;

  case 45:
#line 162 "experiment_hash.y"
    {add_statement_node();}
#line 1642 "y.tab.c"
    break;

  case 46:
#line 162 "experiment_hash.y"
    {remove_node();}
#line 1648 "y.tab.c"
    break;

  case 48:
#line 165 "experiment_hash.y"
    {add_statement_node();}
#line 1654 "y.tab.c"
    break;

  case 49:
#line 165 "experiment_hash.y"
    {remove_node();}
#line 1660 "y.tab.c"
    break;

  case 50:
#line 166 "experiment_hash.y"
    {add_statement_node();}
#line 1666 "y.tab.c"
    break;

  case 51:
#line 166 "experiment_hash.y"
    {remove_node();}
#line 1672 "y.tab.c"
    break;

  case 53:
#line 170 "experiment_hash.y"
    {add_statement_node();}
#line 1678 "y.tab.c"
    break;

  case 54:
#line 170 "experiment_hash.y"
    {remove_node();}
#line 1684 "y.tab.c"
    break;

  case 55:
#line 171 "experiment_hash.y"
    {add_statement_node();}
#line 1690 "y.tab.c"
    break;

  case 56:
#line 171 "experiment_hash.y"
    {remove_node();}
#line 1696 "y.tab.c"
    break;

  case 60:
#line 180 "experiment_hash.y"
    {add_statement_node();}
#line 1702 "y.tab.c"
    break;

  case 61:
#line 180 "experiment_hash.y"
    {remove_node();}
#line 1708 "y.tab.c"
    break;

  case 62:
#line 181 "experiment_hash.y"
    {add_statement_node();}
#line 1714 "y.tab.c"
    break;

  case 63:
#line 181 "experiment_hash.y"
    {remove_node();}
#line 1720 "y.tab.c"
    break;

  case 64:
#line 182 "experiment_hash.y"
    {add_statement_node();}
#line 1726 "y.tab.c"
    break;

  case 65:
#line 182 "experiment_hash.y"
    {remove_node();}
#line 1732 "y.tab.c"
    break;

  case 68:
#line 191 "experiment_hash.y"
    {
                                 
                                 char*customType=malloc(strlen(return_type((yyvsp[0].type)))+strlen("50"));
                                 strcpy(customType,return_type((yyvsp[0].type)));
                                 strcat(customType,"[");
                                 strcat(customType,"50");
                                 strcat(customType,"]");
                                 add_new_variable(customType,(yyvsp[-1].strname));
                        }
#line 1746 "y.tab.c"
    break;

  case 70:
#line 203 "experiment_hash.y"
    {add_new_variable(return_type((yyvsp[0].type)),(yyvsp[-1].strname));}
#line 1752 "y.tab.c"
    break;

  case 71:
#line 204 "experiment_hash.y"
    {
                            struct Checker*iterator=head;
                            while(iterator->next!=NULL)
                            {
                                    iterator=iterator->next;
                            }
                            struct ListOfEntries*list=g_hash_table_lookup(iterator->localScope,(yyvsp[0].strname));
                            int objFound=0;
                            while(list)
                            {
                                    if(strcmp(list->value.whatIs,"object-declaration"))
                                    {
                                            objFound=1;
                                            break;
                                    }
                                    list=list->next;
                            }
                            if(objFound)
                            {
                               add_new_variable((yyvsp[0].strname),(yyvsp[-1].strname));
                            }
                            else
                            {
                                    printf("Ati incercat sa instantiati clasa [%s] care nu existat\nProgramul a fost incheiat fortat!\n",(yyvsp[-1].strname));
                                    exit(EXIT_FAILURE);
                            }

                        }
#line 1785 "y.tab.c"
    break;

  case 72:
#line 232 "experiment_hash.y"
    {add_new_variable(return_type((yyvsp[0].type)),(yyvsp[-1].strname));}
#line 1791 "y.tab.c"
    break;

  case 73:
#line 233 "experiment_hash.y"
    {add_new_variable((yyvsp[0].strname),(yyvsp[-1].strname));}
#line 1797 "y.tab.c"
    break;

  case 74:
#line 234 "experiment_hash.y"
    {
                                char*newtype=malloc(strlen("const-")+strlen(return_type((yyvsp[-1].type)))+1);
                                strcpy(newtype,"const-");
                                strcat(newtype,return_type((yyvsp[-1].type)));
                                newtype[strlen(newtype)]='\0';
                                add_new_variable(newtype,(yyvsp[-2].strname));
                        }
#line 1809 "y.tab.c"
    break;

  case 75:
#line 248 "experiment_hash.y"
    {(yyval.type)=(yyvsp[0].type);}
#line 1815 "y.tab.c"
    break;

  case 76:
#line 249 "experiment_hash.y"
    {(yyval.type)=(yyvsp[0].type);}
#line 1821 "y.tab.c"
    break;

  case 77:
#line 250 "experiment_hash.y"
    {(yyval.type)=(yyvsp[0].type);}
#line 1827 "y.tab.c"
    break;

  case 78:
#line 251 "experiment_hash.y"
    {(yyval.type)=(yyvsp[0].type);}
#line 1833 "y.tab.c"
    break;

  case 79:
#line 252 "experiment_hash.y"
    {(yyval.type)=(yyvsp[0].type);}
#line 1839 "y.tab.c"
    break;

  case 80:
#line 253 "experiment_hash.y"
    {(yyval.type)=(yyvsp[0].type);}
#line 1845 "y.tab.c"
    break;

  case 102:
#line 281 "experiment_hash.y"
    {
                                struct Checker *allScope=head;
                                int classFound=0;
                                while(allScope && !classFound)
                                {
                                        struct ListOfEntries*searchList;
                                        if(searchList=g_hash_table_lookup(allScope->localScope,(yyvsp[0].strname)))
                                        {
                                                printf("Am gasit %s in scope-ul %s\n",(yyvsp[0].strname),allScope->currentScope);
                                                while(searchList && !classFound)
                                                {
                                                        struct Checker*globalScope=head;
                                                        while(globalScope->next!=NULL)
                                                        {
                                                                globalScope=globalScope->next;
                                                        }       
                                                        struct ListOfEntries*insideList;
                                                        if(insideList=g_hash_table_lookup(globalScope->localScope,searchList->value.dataType))
                                                        {
                                                                while(insideList)
                                                                {
                                                                        if(strcmp(insideList->value.whatIs,"object-declaration"))
                                                                        {
                                                                                classFound=1;
                                                                                break;
                                                                        }
                                                                        insideList=insideList->next;
                                                                }
                                                        }
                                                        searchList=searchList->next;
                                                }
                                        }
                                        allScope=allScope->next;
                                }
                                if(!classFound)
                                {
                                        printf("Identificatorul [%s] nu desemneaza un obiect\n",(yyvsp[0].strname));
                                        exit(EXIT_FAILURE);
                                }

                        }
#line 1891 "y.tab.c"
    break;

  case 105:
#line 330 "experiment_hash.y"
    {add_main_node();}
#line 1897 "y.tab.c"
    break;

  case 106:
#line 330 "experiment_hash.y"
    {remove_node();}
#line 1903 "y.tab.c"
    break;

  case 107:
#line 331 "experiment_hash.y"
    {add_main_node();}
#line 1909 "y.tab.c"
    break;

  case 108:
#line 331 "experiment_hash.y"
    {remove_node();}
#line 1915 "y.tab.c"
    break;


#line 1919 "y.tab.c"

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
#line 333 "experiment_hash.y"

int yyerror(char * s){
    printf("eroare: %s la linia:%d\n",s,yylineno);
    return 0;
}

int main(int argc, char** argv){
   yyin=fopen(argv[1],"r");
   init_prg();
   yyparse();
   struct Checker*test=head;
   while(test)
   {
           g_hash_table_foreach(test->localScope,print_key_value,NULL);
           test=test->next;
   }
   return 0;
} 
void init_prg()
{
        head=malloc(sizeof(struct Checker));
        head->next=NULL;
        head->localScope=g_hash_table_new_full(g_str_hash,g_str_equal,g_free,(void*)free_entry);
        head->currentScope=malloc(5);
        strcpy(head->currentScope,"0");
        head->counter=0;
        if(NULL==(SymTabDump=fopen("symbol_table.txt","w")))
        {
                perror("Eroare la deschiderea fisierului symbol_table.txt\n");
                exit(EXIT_FAILURE);
        }
}
void free_entry(struct ListOfEntries*val)
{
        g_free(val);
}
void add_func_node(char*identifier,const char*returntype,char*arg_list)
{
        head->counter++;
        struct Checker*newNode=malloc(sizeof(struct Checker));
        newNode->next=head;
        char valuef[5];
        sprintf(valuef,"%d",head->counter);
        int nLenght=strlen(valuef)+1;
        newNode->currentScope=malloc(strlen(head->currentScope)+strlen(valuef)+2);
        strcpy(newNode->currentScope,head->currentScope);
        strcat(newNode->currentScope,"-");
        strcat(newNode->currentScope,valuef);
        newNode->localScope=g_hash_table_new_full(g_str_hash,g_str_equal,g_free,(void*)free_entry);
        head=newNode;
        struct SymTabEntry newEntry;
        newEntry.name=malloc(strlen(identifier)+1);
        strcpy(newEntry.name,identifier);
        newEntry.name[strlen(newEntry.name)]='\0';
        newEntry.dataType=malloc(strlen(returntype)+1);
        strcpy(newEntry.dataType,returntype);
        newEntry.dataType[strlen(newEntry.dataType)]='\0';
        newEntry.whatIs=malloc(strlen("function-declaration")+1);
        strcpy(newEntry.whatIs,"function-declaration");
        newEntry.whatIs[strlen(newEntry.whatIs)]='\0';
        newEntry.scope=malloc(strlen(head->currentScope)+1);
        strcpy(newEntry.scope,head->currentScope);
        newEntry.scope[strlen(newEntry.scope)]='\0';
        newEntry.lineOf=yylineno;
        struct ListOfEntries*val;
        if((val=g_hash_table_lookup(head->next->localScope,identifier)))
        {
                while(val)
                {
                        if(strncmp(val->value.scope,newEntry.scope,strlen(newEntry.scope)-nLenght)==0 && strcmp(val->value.whatIs,"function-declaration")==0)
                        {
                                printf("Functia [%s] de tipul de retur %s a fost redeclarata in scope-ul %s\nProgramul a fost incheiat fortat!\n",newEntry.name,newEntry.dataType,val->value.scope);
                                exit(EXIT_FAILURE);
                        }
                        val=val->next;
                }
        }
                struct ListOfEntries*newVal=malloc(sizeof(struct ListOfEntries));
                newVal->value=newEntry;
                newVal->next=NULL;
                g_hash_table_insert(head->localScope,identifier,newVal);

}
void add_new_variable(const char*type,char*identifier)
{
        if(strcmp(type,"void")==0)
        {
                printf("Variabila [%s] declarata de tipul void\n",identifier);
                exit(EXIT_FAILURE);
        }
        struct SymTabEntry newEntry;
        newEntry.name=malloc(strlen(identifier)+1);
        newEntry.name[strlen(newEntry.name)]='\0';
        strcpy(newEntry.name,identifier);
        newEntry.dataType=malloc(strlen(type)+1);
        strcpy(newEntry.dataType,type);
        newEntry.dataType[strlen(newEntry.dataType)]='\0';
        newEntry.whatIs=malloc(strlen("variable")+1);
        strcpy(newEntry.whatIs,"variable");
        newEntry.whatIs[strlen(newEntry.whatIs)]='\0';
        newEntry.scope=malloc(strlen(head->currentScope)+1);
        strcpy(newEntry.scope,head->currentScope);
        newEntry.scope[strlen(newEntry.scope)]='\0';
        newEntry.lineOf=yylineno;
        struct ListOfEntries*val;
        if((val=g_hash_table_lookup(head->localScope,identifier)))
        {
                while(val)
                {
                        if(strcmp(val->value.scope,newEntry.scope)==0 && strcmp(val->value.whatIs,"variable")==0)
                        {
                                printf("Variabila [%s] de tipul %s a fost redeclarat in scope-ul %s\n",newEntry.name,newEntry.dataType,newEntry.scope);
                                exit(EXIT_FAILURE);
                        }
                        val=val->next;
                }
        }
                struct ListOfEntries*newVal=malloc(sizeof(struct ListOfEntries));
                newVal->value=newEntry;
                newVal->next=NULL;
                g_hash_table_insert(head->localScope,identifier,newVal);

}
const char*return_type(int type)
{
        switch(type)
        {
                case 0:{return "int";}
                case 1:{return "char";}
                case 2:{return "float";}
                case 3:{return "bool";}
                case 4:{return "char*";}
                case 5:{return "void";}
        }

}
void print_key_value(gpointer key,gpointer value,gpointer userdata)
{
        struct ListOfEntries*var=value;
        while(var)
        {
           printf("%s \t%s\t %s\n",var->value.name,var->value.whatIs,var->value.scope);
           if(strcmp(var->value.whatIs,"variable")==0)
           {
                   fprintf(SymTabDump,"%i \t %s \t %s\t %s \t %i \t %s\n",var->value.lineOf,var->value.name,var->value.whatIs,var->value.dataType,var->value.intvalue,var->value.scope);
           }
           if(strcmp(var->value.whatIs,"function-declaration")==0)
           {
                   fprintf(SymTabDump,"%i \t %s \t %s \t %s \t %s \t %s\n",var->value.lineOf,var->value.name,var->value.whatIs,var->value.dataType,var->value.paramlist,var->value.scope);
           }
           if(strcmp(var->value.whatIs,"class-declaration")==0)
           {
                   fprintf(SymTabDump,"%i \t %s \t %s \t %s\n",var->value.lineOf,var->value.name,var->value.whatIs,var->value.scope);
           }
           if(strcmp(var->value.whatIs,"main-declaration")==0)
           {
                   fprintf(SymTabDump,"%i \t %s \t %s \t %s\n",var->value.lineOf,var->value.name,var->value.whatIs,var->value.scope);
           }
           var=var->next;
        }
}
void copy_hash(gpointer key,gpointer value,gpointer userdata)
{
        struct ListOfEntries*content;
        if((content=g_hash_table_lookup(head->next->localScope,key)))
        {
                struct ListOfEntries*concatList=malloc(sizeof(struct ListOfEntries));
                struct ListOfEntries*itf=content;
                while(itf)
                {
                        struct ListOfEntries*newNode=malloc(sizeof(struct ListOfEntries));
                        newNode->value=itf->value;
                        newNode->next=concatList;
                        concatList=newNode;
                        itf=itf->next;
                }
                struct ListOfEntries*its=value;
                while(its)
                {
                        struct ListOfEntries*newNode=malloc(sizeof(struct ListOfEntries));
                        newNode->value=its->value;
                        newNode->next=concatList;
                        concatList=newNode;
                        its=its->next;
                }
                struct ListOfEntries*itt=concatList;
                while(itt)
                {
                        if(itt->next->next==NULL)
                                {
                                        itt->next=NULL;
                                        break;
                                }
                        itt=itt->next;
                }
                g_hash_table_replace(head->next->localScope,key,concatList);
        }
        else
        {
                 g_hash_table_insert(head->next->localScope,key,value);
        }
}
void remove_node()
{
        g_hash_table_foreach(head->localScope,copy_hash,NULL);
        head=head->next;
}
void add_class_node(char*identifier)
{
        head->counter++; 
        struct Checker*newNode=malloc(sizeof(struct Checker));
        newNode->next=head;
        char valuef[5];
        sprintf(valuef,"%d",head->counter);
        newNode->currentScope=malloc(strlen(head->currentScope)+strlen(valuef)+2);
        strcpy(newNode->currentScope,head->currentScope);
        strcat(newNode->currentScope,"-");
        strcat(newNode->currentScope,valuef);
        newNode->localScope=g_hash_table_new_full(g_str_hash,g_str_equal,g_free,(void*)free_entry);
        head=newNode;
        struct SymTabEntry newEntry;
        newEntry.name=malloc(strlen(identifier)+1);
        strcpy(newEntry.name,identifier);
        newEntry.name[strlen(newEntry.name)]='\0';
        newEntry.whatIs=malloc(strlen("class-declaration")+1);
        strcpy(newEntry.whatIs,"class-declaration");
        newEntry.whatIs[strlen(newEntry.whatIs)]='\0';
        newEntry.scope=malloc(strlen(head->currentScope)+1);
        strcpy(newEntry.scope,head->currentScope);
        newEntry.scope[strlen(newEntry.scope)]='\0';
        newEntry.lineOf=yylineno;
        struct ListOfEntries*val;
        if((val=g_hash_table_lookup(head->next->localScope,identifier)))
        {  
                while(val)
                {
                        if(strcmp(val->value.whatIs,"class-declaration")==0)
                        {
                                printf("Clasa [%s] a fost redeclarat\nProgramul a fost incheiat fortat!\n",newEntry.name);
                                exit(EXIT_FAILURE);
                        }
                        val=val->next;
                }
        }
                struct ListOfEntries*newVal=malloc(sizeof(struct ListOfEntries));
                newVal->next=NULL;
                newVal->value=newEntry;
                g_hash_table_insert(head->localScope,identifier,newVal);
       
                
}
void add_statement_node()
{
        head->counter++;
        struct Checker*newNode=malloc(sizeof(struct Checker));
        newNode->localScope=g_hash_table_new_full(g_str_hash,g_str_equal,g_free,(void*)free_entry);
        char value[5];
        sprintf(value,"%d",head->counter);
        newNode->currentScope=malloc(strlen(head->currentScope)+strlen(value)+2);
        strcpy(newNode->currentScope,head->currentScope);
        strcat(newNode->currentScope,"-");
        strcat(newNode->currentScope,value);
        newNode->next=head;
        head=newNode;
        
}
void add_main_node()
{
        head->counter++;
        struct Checker*newNode=malloc(sizeof(struct Checker));
        newNode->localScope=g_hash_table_new_full(g_str_hash,g_str_equal,g_free,(void*)free_entry);
        char value[5];
        sprintf(value,"%d",head->counter);
        newNode->currentScope=malloc(strlen(head->currentScope)+strlen(value)+2);
        strcpy(newNode->currentScope,head->currentScope);
        strcat(newNode->currentScope,"-");
        strcat(newNode->currentScope,value);
        newNode->next=head;
        head=newNode;
        struct SymTabEntry newEntry;
        newEntry.name=malloc(strlen("main")+1);
        strcpy(newEntry.name,"main");
        newEntry.whatIs=malloc(strlen("main-declaration")+1);
        strcpy(newEntry.whatIs,"main-declaration");
        newEntry.scope=malloc(strlen(head->currentScope)+1);
        strcpy(newEntry.scope,head->currentScope);
        struct ListOfEntries*val;
        newEntry.lineOf=yylineno;
         if((val=g_hash_table_lookup(head->next->localScope,"main")))
        {  
                while(val)
                {
                        if(strcmp(val->value.whatIs,"class-declaration")==0)
                        {
                                printf("Clasa [%s] a fost redeclarat\nProgramul a fost incheiat fortat!\n",newEntry.name);
                                exit(EXIT_FAILURE);
                        }
                        val=val->next;
                }
        }
                struct ListOfEntries*newVal=malloc(sizeof(struct ListOfEntries));
                newVal->next=NULL;
                newVal->value=newEntry;
                g_hash_table_insert(head->localScope,"main",newVal);
}
