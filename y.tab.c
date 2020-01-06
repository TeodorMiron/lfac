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
        int initialised;

} SymTabEntry;
struct ListOfEntries
{
        struct SymTabEntry*value;
        struct ListOfEntries*next;
        
} ListOfEntries;

struct Checker
{
        GHashTable*localScope;
        int counter;
        char*currentScope;
        struct Checker*next;

};

struct expr_info
{
        char*type;
        char*expString;

} expr_info;
struct eval_expr
{
        int intvalue;
        char*name;

} eval_expr;

struct Checker*head=NULL;
struct ListOfEntries*funcArgs=NULL;
struct ListOfEntries*objVars=NULL;
char*typesOfCall=NULL;
char*inObjectFunc=NULL;
char*classScope=NULL;
char*objName=NULL;
int inArgs=0;
int inClass=0;
int noArgs=0;
int objInstance=0;
FILE*SymTabDump=NULL;
void init_prg();
void free_entry(struct ListOfEntries*val);
void free_checker(struct Checker*val);
void add_new_variable(const char*type,char*identifier,int init);
void add_func_node(char*identifier,const char*returntype);
void add_statement_node();
void add_class_node(char*identifier);
void add_main_node();
const char*return_type(int type);
void add_new_node(struct Checker*head);
void remove_node();
struct expr_info*create_int_expression(int intValue);
struct expr_info*create_bool_expression(const char*boolValue);
struct expr_info*create_float_expression(float floatValue);
struct expr_info*create_string_expression(char*stringValue);
struct expr_info*create_char_expression(const char charValue);
struct expr_info*create_variable_expression(const char*identifier,char*type);
struct expr_info*create_paranthesis_expression(struct expr_info*exp);
struct expr_info*create_expression(char*type,char*eString);
struct eval_expr*create_eval_expression(char*name,int value);
char* is_class_object(char*identifier);
struct ListOfEntries*new_parameter_list(struct ListOfEntries*oldList);
int is_object_variable(char*class,char*variable);
void search_every_class(gpointer key,gpointer value,gpointer userdata);
void print_key_value(gpointer key,gpointer value,gpointer userdata);
int countChars( char* s, char c )
{
    return *s == '\0'? 0: countChars( s + 1, c ) + (*s == c);
}
void add_every_variable(gpointer key,gpointer value,gpointer userdata)
{
        struct ListOfEntries*iterator=value;
        while(iterator)
        {
                if(strcmp(iterator->value->scope,classScope)==0 && strcmp(iterator->value->whatIs,"class-variable")==0)
                {
                        char*customName=malloc(strlen(objName)+strlen(iterator->value->name)+2);
                        strcpy(customName,objName);
                        strcat(customName,".");
                        strcat(customName,iterator->value->name);
                        if(objVars==NULL)
                        {
                                
                                objVars=malloc(sizeof(struct ListOfEntries)); 
                                struct SymTabEntry*newEntry=malloc(sizeof(struct SymTabEntry));
                                newEntry->name=malloc(strlen(customName)+1);
                                newEntry->dataType=malloc(strlen(iterator->value->dataType)+1);
                                newEntry->scope=malloc(strlen(head->currentScope)+1);
                                strcpy(newEntry->dataType,iterator->value->dataType);
                                strcpy(newEntry->scope,head->currentScope);
                                strcpy(newEntry->name,customName);
                                if(iterator->value->initialised==1)
                                        newEntry->initialised=1;
                                else newEntry->initialised=0;
                                objVars->value=newEntry;
                                objVars->next=NULL;
                        }
                        else
                        {
                                struct ListOfEntries*newNode=malloc(sizeof(struct ListOfEntries));
                                struct SymTabEntry*newEntry=malloc(sizeof(struct SymTabEntry));
                                newEntry->name=malloc(strlen(customName)+1);
                                newEntry->dataType=malloc(strlen(iterator->value->dataType)+1);
                                newEntry->scope=malloc(strlen(head->currentScope)+1);
                                strcpy(newEntry->dataType,iterator->value->dataType);
                                strcpy(newEntry->scope,head->currentScope);
                                strcpy(newEntry->name,customName);
                                if(iterator->value->initialised)
                                        newEntry->initialised=1;
                                else newEntry->initialised=0;
                                newNode->value=newEntry;
                                newNode->next=objVars;
                                objVars=newNode;

                        }
                        
                }
                iterator=iterator->next;
        }
}


#line 221 "y.tab.c"

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
    GREATER_EQUAL = 285,
    STRING_TYPE = 286,
    CONST = 287,
    RETURN = 288,
    AND = 289,
    OR = 290,
    NOT = 291,
    EVAL = 292,
    ID = 293,
    INT_VAL = 294,
    STRING_VAL = 295,
    FLOAT_VAL = 296,
    CHAR_VAL = 297,
    INT = 298,
    STRING = 299,
    FLOAT = 300,
    CHAR = 301,
    BOOL = 302,
    VOID = 303,
    BOOL_TRUE = 304,
    BOOL_FALSE = 305
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
#define GREATER_EQUAL 285
#define STRING_TYPE 286
#define CONST 287
#define RETURN 288
#define AND 289
#define OR 290
#define NOT 291
#define EVAL 292
#define ID 293
#define INT_VAL 294
#define STRING_VAL 295
#define FLOAT_VAL 296
#define CHAR_VAL 297
#define INT 298
#define STRING 299
#define FLOAT 300
#define CHAR 301
#define BOOL 302
#define VOID 303
#define BOOL_TRUE 304
#define BOOL_FALSE 305

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 153 "experiment_hash.y"

        int type;
        char*strname;
        int intval;
        char* strval;
        char*boolVal;
        char charval;
        float floatval;
        struct expr_info* expr_ptr;
        struct eval_expr*eval_info;

#line 376 "y.tab.c"

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
#define YYFINAL  34
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   511

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  59
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  51
/* YYNRULES -- Number of rules.  */
#define YYNRULES  126
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  239

#define YYUNDEFTOK  2
#define YYMAXUTOK   305

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
       2,     2,     2,     2,     2,    56,    58,     2,     2,     2,
       2,     2,     2,     2,    52,     2,    57,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    51,
       2,     2,     2,     2,    53,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    54,     2,    55,     2,     2,     2,     2,     2,     2,
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
      45,    46,    47,    48,    49,    50
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   197,   197,   198,   199,   202,   203,   206,   207,   208,
     209,   213,   213,   214,   214,   217,   218,   221,   222,   225,
     225,   237,   237,   249,   249,   260,   260,   273,   274,   277,
     278,   278,   281,   282,   285,   286,   289,   290,   291,   292,
     293,   294,   295,   296,   297,   300,   303,   304,   305,   306,
     307,   308,   311,   312,   327,   330,   393,   401,   411,   469,
     486,   491,   498,   498,   498,   499,   499,   499,   502,   502,
     503,   503,   504,   507,   507,   508,   508,   511,   587,   685,
     728,   728,   731,   732,   737,   752,   756,   804,   812,   831,
     832,   833,   834,   835,   836,   839,   897,   898,   899,   900,
     901,   902,   903,   904,   905,   906,   907,   908,   921,   941,
     960,   978,   996,  1014,  1022,  1045,  1068,  1081,  1094,  1106,
    1116,  1203,  1270,  1318,  1318,  1319,  1319
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
  "INCR", "CLASS", "MAIN", "ELSE", "SMALLER_EQUAL", "GREATER_EQUAL",
  "STRING_TYPE", "CONST", "RETURN", "AND", "OR", "NOT", "EVAL", "ID",
  "INT_VAL", "STRING_VAL", "FLOAT_VAL", "CHAR_VAL", "INT", "STRING",
  "FLOAT", "CHAR", "BOOL", "VOID", "BOOL_TRUE", "BOOL_FALSE", "';'", "','",
  "'@'", "'['", "']'", "'#'", "'.'", "'$'", "$accept", "start_program",
  "declaration_section", "declaration_content", "object_declaration",
  "$@1", "$@2", "object_content", "inside_object", "function_declaration",
  "$@3", "$@4", "$@5", "$@6", "return_statement", "list_param", "$@7",
  "function_content", "multiple_statements", "statements",
  "eval_statement", "int_arithmetic", "eval_supported_value",
  "string_functions", "function_call", "list_call", "if_statement", "$@8",
  "$@9", "$@10", "$@11", "else_statement", "$@12", "$@13",
  "while_statement", "$@14", "$@15", "assign_statement", "for_statement",
  "$@16", "create_variable", "create_array_variable",
  "create_single_variable", "available_types", "expression",
  "object_call_function", "object_access_var", "access_vector",
  "main_section", "$@17", "$@18", YY_NULLPTR
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
     305,    59,    44,    64,    91,    93,    35,    46,    36
};
# endif

#define YYPACT_NINF -171

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-171)))

#define YYTABLE_NINF -126

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -19,   -12,    36,   179,     8,   -19,  -171,  -171,  -171,  -171,
     -20,     2,    11,    56,   227,   227,     3,  -171,  -171,  -171,
    -171,  -171,  -171,   227,    74,   249,  -171,  -171,  -171,  -171,
     336,  -171,  -171,  -171,  -171,  -171,  -171,    89,   360,   100,
      11,   271,  -171,   126,   380,   188,   109,    73,   227,   454,
     227,  -171,   358,   -32,   227,   227,   227,   227,   227,   227,
     227,   227,   227,   227,   227,   133,  -171,  -171,  -171,  -171,
    -171,  -171,   138,   360,  -171,    84,   161,   164,  -171,   141,
      99,   446,  -171,  -171,    95,   153,   142,   227,   453,   244,
     196,   216,   474,   173,   267,   188,   289,   166,  -171,   190,
      48,   187,   202,   169,    14,  -171,  -171,  -171,  -171,  -171,
     209,   227,   211,   360,   219,   125,   101,   239,   101,   201,
      51,   242,  -171,  -171,  -171,   225,   446,   360,   252,  -171,
     248,   227,   156,    43,  -171,  -171,  -171,  -171,  -171,   -18,
    -171,   227,   270,   101,   201,   256,  -171,  -171,  -171,   253,
     314,   227,   241,  -171,    34,  -171,  -171,    83,  -171,  -171,
     283,  -171,   446,  -171,   -18,   285,  -171,   227,    17,   152,
       0,  -171,  -171,   299,  -171,   224,   302,   315,   227,     0,
    -171,  -171,   319,    -2,  -171,  -171,  -171,   227,   322,   323,
     402,   367,   227,     0,     0,     0,     0,   305,   424,   101,
     324,   101,   334,   325,  -171,   124,   237,  -171,    64,   343,
    -171,   350,    49,  -171,    75,  -171,  -171,  -171,  -171,   326,
     337,  -171,   332,  -171,  -171,  -171,   332,   338,  -171,   101,
    -171,   344,    97,   101,   345,  -171,   110,  -171,  -171
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       4,    30,     0,     0,     0,     0,     6,     8,     7,     3,
       0,     0,     0,     0,     0,     0,    95,    96,   100,    97,
     101,    98,    99,     0,     0,     0,   102,    10,     9,    82,
       0,   103,   104,   105,     1,     5,     2,     0,     0,     0,
       0,     0,    31,    11,     0,   118,     0,     0,    61,    95,
       0,    83,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    89,    93,    91,    90,
      92,    94,     0,     0,    29,     0,     0,   106,   121,     0,
       0,    60,    86,    85,     0,     0,    77,     0,   107,   109,
     111,   112,   110,   108,   113,   114,   115,   116,   117,   123,
      23,     0,    30,     0,     0,    16,    17,    14,   119,   122,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    28,
      19,     0,    18,    12,    15,    58,    59,   122,    87,    78,
       0,     0,     0,     0,    35,    36,    37,    38,   126,    28,
      33,     0,     0,     0,    28,     0,    84,    88,    79,     0,
       0,     0,     0,    44,   102,    40,    41,   103,   124,    34,
       0,    32,    27,    26,    28,     0,   120,     0,     0,     0,
       0,    39,    24,     0,    22,     0,     0,     0,     0,     0,
      53,    52,     0,     0,    51,    54,    20,     0,    62,    73,
       0,     0,    61,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    50,     0,    46,    49,    47,    48,
      45,     0,     0,    66,     0,    76,    55,    57,    56,     0,
       0,    63,    72,    74,    58,    80,    72,     0,    67,     0,
      64,    68,     0,     0,     0,    81,     0,    71,    69
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -171,  -171,  -171,   364,  -171,  -171,  -171,  -171,   275,    61,
    -171,  -171,  -171,  -171,    19,  -171,  -171,   240,  -170,  -113,
    -171,   121,  -171,  -171,  -118,   192,  -171,  -171,  -171,  -171,
    -171,   154,  -171,  -171,  -171,  -171,  -171,   140,  -171,  -171,
      53,  -171,    46,   -45,   -14,   258,  -171,  -171,   386,  -171,
    -171
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     4,     5,     6,     7,    75,    76,   104,   105,     8,
     143,   144,   118,   119,   142,    11,    12,   139,   133,   134,
     171,   183,   184,   153,    26,    80,   135,   199,   226,   200,
     222,   228,   233,   234,   136,   201,   202,    27,   137,   229,
      28,    51,    29,    72,    30,    31,    32,    33,     9,   116,
     117
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      44,    45,     1,   131,    83,   140,    86,    37,    34,    47,
      10,    52,   193,   194,   154,   141,   195,   196,    38,     2,
     159,   179,    87,   176,    39,   177,   161,    52,   101,   212,
     140,   214,     3,   132,    81,   102,    84,   123,   180,   181,
      88,    89,    90,    91,    92,    93,    94,    95,    96,    97,
      98,   161,   185,   197,    40,   -42,   182,   -42,    42,   232,
      46,   185,    13,   236,   131,   103,   158,   -42,   128,    41,
     131,   -25,   221,   115,   -21,   185,   185,   185,   185,   194,
      43,   -25,   146,   196,   -21,   -42,    74,    54,    55,    56,
      57,    58,    59,    60,   132,    48,   131,   126,   223,   159,
     132,   159,    61,    62,   -43,   102,   -43,    63,    64,    54,
      55,    56,    57,    58,    59,    60,   -43,   150,   131,   159,
     235,   110,   131,   159,    61,    62,   132,   162,    79,    63,
      64,   131,    65,   238,   -43,   103,   106,   169,    73,    54,
      55,    56,    57,    58,    59,    60,   219,    78,   132,   -13,
     112,   111,   132,   175,    61,    62,   122,    99,   160,    63,
      64,   132,   100,   165,   190,   106,    54,    55,    56,    57,
      58,    59,    60,   198,    77,   108,   111,   151,    81,   109,
     130,    61,    62,   173,   107,   156,    63,    64,    55,    56,
      57,   113,    15,    60,    16,    17,    18,    19,    20,   114,
      14,    64,    61,    62,   178,    21,    22,    63,    64,   152,
      23,   120,    24,  -125,    25,    15,    60,    16,    17,    18,
      19,    20,    63,    64,   121,    61,    62,    25,    21,    22,
      63,    64,    56,    23,   141,    24,    60,    25,    54,    55,
      56,    57,    58,    59,    60,    61,    62,   125,    14,   127,
      63,    64,   194,    61,    62,   195,   196,   129,    63,    64,
      56,    57,   138,    15,    60,    16,    17,    18,    19,    20,
      14,   149,   155,    61,    62,   187,    21,    22,    63,    64,
      38,    23,   145,    24,   147,    15,   148,    49,    17,    18,
      19,    20,    14,   163,   166,   170,    61,    62,    21,    22,
     191,    63,    64,    50,   167,    24,   172,    15,   174,    49,
      17,    18,    19,    20,   206,   207,   208,   209,    61,    53,
      21,    22,   186,    63,    64,    23,   188,    24,    54,    55,
      56,    57,    58,    59,    60,   216,   168,   217,   218,   189,
     192,    53,   210,    61,    62,   -65,   -75,   213,    63,    64,
      54,    55,    56,    57,    58,    59,    60,   215,   194,   220,
     227,   225,   231,    85,   224,    61,    62,   -70,   237,    35,
      63,    64,    54,    55,    56,    57,    58,    59,    60,   124,
     230,   193,   194,   164,   205,   195,   196,    61,    62,   204,
     157,    36,    63,    64,    54,    55,    56,    57,    58,    59,
      60,     0,    77,    66,    67,    68,    69,    70,    71,    61,
      62,     0,     0,     0,    63,    64,    54,    55,    56,    57,
      58,    59,    60,     0,   203,     0,     0,     0,     0,     0,
       0,    61,    62,     0,     0,     0,    63,    64,    54,    55,
      56,    57,    58,    59,    60,     0,   211,     0,     0,     0,
       0,     0,     0,    61,    62,     0,     0,     0,    63,    64,
      54,    55,    56,    57,    58,    59,    60,     0,    55,    56,
      57,    58,    59,    60,     0,    61,    62,     0,     0,     0,
      63,    64,    61,    62,     0,     0,     0,    63,    64,    55,
      56,    57,    82,    59,    60,     0,     0,    66,    67,    68,
      69,    70,    71,    61,    62,     0,     0,     0,    63,    64,
       0,    46
};

static const yytype_int16 yycheck[] =
{
      14,    15,    21,    21,    49,   118,    38,    27,     0,    23,
      22,    25,    14,    15,   132,    33,    18,    19,    38,    38,
     133,    21,    54,     6,    22,     8,   139,    41,    73,   199,
     143,   201,    51,    51,    48,    21,    50,    23,    38,    39,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,   164,   170,    55,    52,    21,    56,    23,    12,   229,
      57,   179,    26,   233,    21,    51,    23,    33,   113,    58,
      21,    23,    23,    87,    23,   193,   194,   195,   196,    15,
      24,    33,   127,    19,    33,    51,    40,    14,    15,    16,
      17,    18,    19,    20,    51,    21,    21,   111,    23,   212,
      51,   214,    29,    30,    21,    21,    23,    34,    35,    14,
      15,    16,    17,    18,    19,    20,    33,   131,    21,   232,
      23,    22,    21,   236,    29,    30,    51,   141,    55,    34,
      35,    21,    43,    23,    51,    51,    75,   151,    38,    14,
      15,    16,    17,    18,    19,    20,    22,    38,    51,    23,
      55,    52,    51,   167,    29,    30,   103,    24,   139,    34,
      35,    51,    24,   144,   178,   104,    14,    15,    16,    17,
      18,    19,    20,   187,    22,    11,    52,    21,   192,    38,
      55,    29,    30,   164,    23,   132,    34,    35,    15,    16,
      17,    38,    36,    20,    38,    39,    40,    41,    42,    57,
      21,    35,    29,    30,    52,    49,    50,    34,    35,    53,
      54,    24,    56,    23,    58,    36,    20,    38,    39,    40,
      41,    42,    34,    35,    22,    29,    30,    58,    49,    50,
      34,    35,    16,    54,    33,    56,    20,    58,    14,    15,
      16,    17,    18,    19,    20,    29,    30,    38,    21,    38,
      34,    35,    15,    29,    30,    18,    19,    38,    34,    35,
      16,    17,    23,    36,    20,    38,    39,    40,    41,    42,
      21,   131,   132,    29,    30,    51,    49,    50,    34,    35,
      38,    54,    57,    56,    32,    36,    38,    38,    39,    40,
      41,    42,    21,    23,    38,    54,    29,    30,    49,    50,
     179,    34,    35,    54,    51,    56,    23,    36,    23,    38,
      39,    40,    41,    42,   193,   194,   195,   196,    29,     5,
      49,    50,    23,    34,    35,    54,    24,    56,    14,    15,
      16,    17,    18,    19,    20,    10,    22,    12,    13,    24,
      21,     5,    37,    29,    30,    23,    23,    23,    34,    35,
      14,    15,    16,    17,    18,    19,    20,    23,    15,     9,
      28,    24,    24,     5,    38,    29,    30,    23,    23,     5,
      34,    35,    14,    15,    16,    17,    18,    19,    20,   104,
     226,    14,    15,   143,   192,    18,    19,    29,    30,    22,
     132,     5,    34,    35,    14,    15,    16,    17,    18,    19,
      20,    -1,    22,    43,    44,    45,    46,    47,    48,    29,
      30,    -1,    -1,    -1,    34,    35,    14,    15,    16,    17,
      18,    19,    20,    -1,    22,    -1,    -1,    -1,    -1,    -1,
      -1,    29,    30,    -1,    -1,    -1,    34,    35,    14,    15,
      16,    17,    18,    19,    20,    -1,    22,    -1,    -1,    -1,
      -1,    -1,    -1,    29,    30,    -1,    -1,    -1,    34,    35,
      14,    15,    16,    17,    18,    19,    20,    -1,    15,    16,
      17,    18,    19,    20,    -1,    29,    30,    -1,    -1,    -1,
      34,    35,    29,    30,    -1,    -1,    -1,    34,    35,    15,
      16,    17,    38,    19,    20,    -1,    -1,    43,    44,    45,
      46,    47,    48,    29,    30,    -1,    -1,    -1,    34,    35,
      -1,    57
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    21,    38,    51,    60,    61,    62,    63,    68,   107,
      22,    74,    75,    26,    21,    36,    38,    39,    40,    41,
      42,    49,    50,    54,    56,    58,    83,    96,    99,   101,
     103,   104,   105,   106,     0,    62,   107,    27,    38,    22,
      52,    58,   101,    24,   103,   103,    57,   103,    21,    38,
      54,   100,   103,     5,    14,    15,    16,    17,    18,    19,
      20,    29,    30,    34,    35,    43,    43,    44,    45,    46,
      47,    48,   102,    38,   101,    64,    65,    22,    38,    55,
      84,   103,    38,   102,   103,     5,    38,    54,   103,   103,
     103,   103,   103,   103,   103,   103,   103,   103,   103,    24,
      24,   102,    21,    51,    66,    67,    68,    23,    11,    38,
      22,    52,    55,    38,    57,   103,   108,   109,    71,    72,
      24,    22,    99,    23,    67,    38,   103,    38,   102,    38,
      55,    21,    51,    77,    78,    85,    93,    97,    23,    76,
      78,    33,    73,    69,    70,    57,   102,    32,    38,    96,
     103,    21,    53,    82,    83,    96,    99,   104,    23,    78,
      73,    78,   103,    23,    76,    73,    38,    51,    22,   103,
      54,    79,    23,    73,    23,   103,     6,     8,    52,    21,
      38,    39,    56,    80,    81,    83,    23,    51,    24,    24,
     103,    80,    21,    14,    15,    18,    19,    55,   103,    86,
      88,    94,    95,    22,    22,    84,    80,    80,    80,    80,
      37,    22,    77,    23,    77,    23,    10,    12,    13,    22,
       9,    23,    89,    23,    38,    24,    87,    28,    90,    98,
      90,    24,    77,    91,    92,    23,    77,    23,    23
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    59,    60,    60,    60,    61,    61,    62,    62,    62,
      62,    64,    63,    65,    63,    66,    66,    67,    67,    69,
      68,    70,    68,    71,    68,    72,    68,    73,    73,    74,
      75,    74,    76,    76,    77,    77,    78,    78,    78,    78,
      78,    78,    78,    78,    78,    79,    80,    80,    80,    80,
      80,    80,    81,    81,    81,    82,    82,    82,    83,    84,
      84,    84,    86,    87,    85,    88,    89,    85,    91,    90,
      92,    90,    90,    94,    93,    95,    93,    96,    96,    96,
      98,    97,    99,    99,   100,   101,   101,   101,   101,   102,
     102,   102,   102,   102,   102,   103,   103,   103,   103,   103,
     103,   103,   103,   103,   103,   103,   103,   103,   103,   103,
     103,   103,   103,   103,   103,   103,   103,   103,   103,   103,
     104,   105,   106,   108,   107,   109,   107
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     1,     0,     2,     1,     1,     1,     2,
       2,     0,     6,     0,     5,     2,     1,     1,     2,     0,
      10,     0,     9,     0,     9,     0,     8,     2,     0,     3,
       0,     2,     2,     1,     2,     1,     1,     1,     1,     3,
       2,     2,     2,     2,     2,     4,     3,     3,     3,     3,
       3,     1,     1,     1,     1,     6,     6,     6,     5,     3,
       1,     0,     0,     0,    10,     0,     0,     9,     0,     5,
       0,     4,     0,     0,     8,     0,     7,     3,     5,     6,
       0,    12,     1,     2,     5,     3,     3,     5,     6,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     2,     4,
       7,     3,     4,     0,     8,     0,     7
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
#line 197 "experiment_hash.y"
    {printf("Programul este corect\n");}
#line 1703 "y.tab.c"
    break;

  case 3:
#line 198 "experiment_hash.y"
    {printf("Programul este corect\n");}
#line 1709 "y.tab.c"
    break;

  case 4:
#line 199 "experiment_hash.y"
    {printf("Programul este corect!\n");}
#line 1715 "y.tab.c"
    break;

  case 11:
#line 213 "experiment_hash.y"
    {add_class_node((yyvsp[-2].strname));inClass=1;}
#line 1721 "y.tab.c"
    break;

  case 12:
#line 213 "experiment_hash.y"
    {remove_node();inClass=0;}
#line 1727 "y.tab.c"
    break;

  case 13:
#line 214 "experiment_hash.y"
    {add_class_node((yyvsp[-2].strname));inClass=1;}
#line 1733 "y.tab.c"
    break;

  case 14:
#line 214 "experiment_hash.y"
    {remove_node();inClass=0;}
#line 1739 "y.tab.c"
    break;

  case 19:
#line 225 "experiment_hash.y"
    {inArgs=0;add_func_node((yyvsp[-2].strname),return_type((yyvsp[-1].type)));}
#line 1745 "y.tab.c"
    break;

  case 20:
#line 225 "experiment_hash.y"
    {
                        remove_node();
                        if(strcmp((yyvsp[-1].expr_ptr)->type,"")!=0)
                        {
                                
                                if(strcmp((yyvsp[-1].expr_ptr)->type,return_type((yyvsp[-5].type))) && (strcmp(return_type((yyvsp[-5].type)),"void")!=0))
                                {
                                        printf("Tipul valoarii de return a functiei [%s] nu se potriveste cu tipul de return declarat al functiei!\n",(yyvsp[-6].strname));
                                        exit(EXIT_FAILURE);
                                }
                        }
                        }
#line 1762 "y.tab.c"
    break;

  case 21:
#line 237 "experiment_hash.y"
    {inArgs=0;add_func_node((yyvsp[-2].strname),return_type((yyvsp[-1].type)));}
#line 1768 "y.tab.c"
    break;

  case 22:
#line 237 "experiment_hash.y"
    {
                            remove_node();
                        if(strcmp((yyvsp[-1].expr_ptr)->type,"")!=0)
                        {
                                
                                if(strcmp((yyvsp[-1].expr_ptr)->type,return_type((yyvsp[-4].type))) && (strcmp(return_type((yyvsp[-4].type)),"void")!=0))
                                {
                                        printf("Tipul valoarii de return a functiei [%s] nu se potriveste cu tipul de return declarat al functiei!\n",(yyvsp[-5].strname));
                                        exit(EXIT_FAILURE);
                                }
                        }
                            }
#line 1785 "y.tab.c"
    break;

  case 23:
#line 249 "experiment_hash.y"
    {inArgs=0;noArgs=1;add_func_node((yyvsp[-2].strname),return_type((yyvsp[-1].type)));}
#line 1791 "y.tab.c"
    break;

  case 24:
#line 249 "experiment_hash.y"
    {remove_node();
                         if(strcmp((yyvsp[-1].expr_ptr)->type,"")!=0)
                        {
                                
                                if(strcmp((yyvsp[-1].expr_ptr)->type,return_type((yyvsp[-5].type))) && (strcmp(return_type((yyvsp[-5].type)),"void")!=0))
                                {
                                        printf("Tipul valoarii de return a functiei [%s] nu se potriveste cu tipul de return declarat al functiei!\n",(yyvsp[-6].strname));
                                        exit(EXIT_FAILURE);
                                }
                        }
                    }
#line 1807 "y.tab.c"
    break;

  case 25:
#line 260 "experiment_hash.y"
    {inArgs=0;noArgs=1;add_func_node((yyvsp[-2].strname),return_type((yyvsp[-1].type)));}
#line 1813 "y.tab.c"
    break;

  case 26:
#line 260 "experiment_hash.y"
    {remove_node();
                         if(strcmp((yyvsp[-1].expr_ptr)->type,"")!=0)
                        {
                                
                                if(strcmp((yyvsp[-1].expr_ptr)->type,return_type((yyvsp[-4].type))) && (strcmp(return_type((yyvsp[-4].type)),"void")!=0))
                                {
                                        printf("Tipul valoarii de return a functiei [%s] nu se potriveste cu tipul de return declarat al functiei!\n",(yyvsp[-5].strname));
                                        exit(EXIT_FAILURE);
                                }
                        }
                    }
#line 1829 "y.tab.c"
    break;

  case 27:
#line 273 "experiment_hash.y"
    {(yyval.expr_ptr)=(yyvsp[0].expr_ptr);}
#line 1835 "y.tab.c"
    break;

  case 28:
#line 274 "experiment_hash.y"
    {(yyval.expr_ptr)=create_expression("","");}
#line 1841 "y.tab.c"
    break;

  case 30:
#line 278 "experiment_hash.y"
    {inArgs=1;}
#line 1847 "y.tab.c"
    break;

  case 46:
#line 303 "experiment_hash.y"
    {(yyval.eval_info)=create_eval_expression("",(yyvsp[-2].eval_info)->intvalue+(yyvsp[0].eval_info)->intvalue);printf("Rezultat:%i\n",(yyval.eval_info)->intvalue);}
#line 1853 "y.tab.c"
    break;

  case 47:
#line 304 "experiment_hash.y"
    {(yyval.eval_info)=create_eval_expression("",(yyvsp[-2].eval_info)->intvalue-(yyvsp[0].eval_info)->intvalue);printf("Rezultat:%i\n",(yyval.eval_info)->intvalue);}
#line 1859 "y.tab.c"
    break;

  case 48:
#line 305 "experiment_hash.y"
    {(yyval.eval_info)=create_eval_expression("",(yyvsp[-2].eval_info)->intvalue*(yyvsp[0].eval_info)->intvalue);printf("Rezultat:%i\n",(yyval.eval_info)->intvalue);}
#line 1865 "y.tab.c"
    break;

  case 49:
#line 306 "experiment_hash.y"
    {(yyval.eval_info)=create_eval_expression("",(yyvsp[-2].eval_info)->intvalue/(yyvsp[0].eval_info)->intvalue);printf("Rezultat:%i\n",(yyval.eval_info)->intvalue);}
#line 1871 "y.tab.c"
    break;

  case 50:
#line 307 "experiment_hash.y"
    {(yyval.eval_info)=create_eval_expression("",(yyvsp[-1].eval_info)->intvalue);}
#line 1877 "y.tab.c"
    break;

  case 52:
#line 311 "experiment_hash.y"
    {(yyval.eval_info)=create_eval_expression("",(yyvsp[0].intval));}
#line 1883 "y.tab.c"
    break;

  case 53:
#line 312 "experiment_hash.y"
    {
                             struct Checker*iterator=head;
                             struct ListOfEntries*searchList;
                        if(searchList=g_hash_table_lookup(iterator->localScope,(yyvsp[0].strname)))
                        {
                                while(searchList)
                                {

                                        if(strcmp(searchList->value->dataType,"int")!=0)
                                            printf("Functia eval poate primi doar variabile de tipul Int\n");
                                        searchList=searchList->next;
                                }
                        }
                             (yyval.eval_info)=create_eval_expression("",0);
                            }
#line 1903 "y.tab.c"
    break;

  case 54:
#line 327 "experiment_hash.y"
    {(yyval.eval_info)=create_eval_expression("",0);}
#line 1909 "y.tab.c"
    break;

  case 55:
#line 331 "experiment_hash.y"
    {
                        
                        if((strcmp((yyvsp[-4].expr_ptr)->type,"char*")!=0) || (strcmp((yyvsp[-2].expr_ptr)->type,"char*")!=0))
                        {
                                printf("Functia [tacrts] accepta doar argumente de tipul [char*],Tip-Argumente:[%s][%s]\n",(yyvsp[-4].expr_ptr)->type,(yyvsp[-2].expr_ptr)->type);
                                exit(EXIT_FAILURE);
                        }
                        int varFound=0;
                        struct Checker*iterator=head;
                        char*retType;
                        while(iterator)
                        {
                                struct ListOfEntries*searchList=g_hash_table_lookup(iterator->localScope,(yyvsp[-2].expr_ptr)->expString);
                                struct ListOfEntries*saveList=NULL;
                                while(searchList)
                                {
                                        if(saveList==NULL)
                                        {
                                                saveList=malloc(sizeof(struct ListOfEntries));
                                                saveList->next=NULL;
                                                saveList->value=searchList->value;
                                        }
                                        else
                                        {
                                                struct ListOfEntries*newNode=malloc(sizeof(struct ListOfEntries));
                                                newNode->value=searchList->value;
                                                newNode->next=saveList;
                                                saveList=newNode;
                                        }
                                        struct ListOfEntries*newNode;
                                        if(!inClass)
                                        {
                                                if((strcmp(searchList->value->name,(yyvsp[-2].expr_ptr)->expString)==0) && (strcmp(searchList->value->scope,iterator->currentScope)==0) && (strcmp(searchList->value->whatIs,"variable")==0))
                                                {
                                                        varFound=1;
                                                        retType=malloc(strlen(searchList->value->dataType)+1);
                                                        strcpy(retType,searchList->value->dataType);
                                                        saveList->value->initialised=1;
                                                        
                                                }
                                        }
                                        else
                                        {
                                                 if((strcmp(searchList->value->name,(yyvsp[-2].expr_ptr)->expString)==0) && (strcmp(searchList->value->scope,iterator->currentScope)==0) && ((strcmp(searchList->value->whatIs,"variable")==0) || (strcmp(searchList->value->whatIs,"class-variable")==0)))
                                                {
                                                        varFound=1;
                                                        retType=malloc(strlen(searchList->value->dataType)+1);
                                                        strcpy(retType,searchList->value->dataType);
                                                        saveList->value->initialised=1;
                                                }
                                        }
                                        searchList=searchList->next;
                                }
                                if(varFound)
                                {
                                        g_hash_table_replace(iterator->localScope,(yyvsp[-2].expr_ptr)->expString,saveList);
                                        break;
                                }

                                iterator=iterator->next;
                        }
                }
#line 1976 "y.tab.c"
    break;

  case 56:
#line 394 "experiment_hash.y"
    {
                        if((strcmp((yyvsp[-4].expr_ptr)->type,"char*")!=0) || (strcmp((yyvsp[-2].expr_ptr)->type,"char*")!=0))
                        {
                                printf("Functia [tacrts] accepta doar argumente de tipul [char*],Tip-Argumente:[%s][%s]\n",(yyvsp[-4].expr_ptr)->type,(yyvsp[-2].expr_ptr)->type);
                                exit(EXIT_FAILURE);
                        }
                }
#line 1988 "y.tab.c"
    break;

  case 57:
#line 402 "experiment_hash.y"
    {
                        if((strcmp((yyvsp[-4].expr_ptr)->type,"char*")!=0) || (strcmp((yyvsp[-2].expr_ptr)->type,"char*")!=0))
                        {
                                printf("Functia [tacrts] accepta doar argumente de tipul [char*],Tip-Argumente:[%s][%s]\n",(yyvsp[-4].expr_ptr)->type,(yyvsp[-2].expr_ptr)->type);
                                exit(EXIT_FAILURE);
                        } 
                }
#line 2000 "y.tab.c"
    break;

  case 58:
#line 412 "experiment_hash.y"
    {
                      struct Checker*iterator=head;
                      int funcFound=0;
                      char*eString=malloc(strlen(typesOfCall)+strlen((yyvsp[0].strname))+3);
                      strcpy(eString,"(");
                      strcat(eString,typesOfCall);
                      strcat(eString,")");
                      strcat(eString,(yyvsp[0].strname));
                      while(iterator)
                      {
                              struct ListOfEntries*searchList=g_hash_table_lookup(iterator->localScope,(yyvsp[0].strname));
                              struct ListOfEntries*iteratorList=searchList;
                              while(iteratorList)
                              {
                                      if(!inClass)
                                      {
                                        if((strcmp(iteratorList->value->whatIs,"function-declaration")==0) && (strcmp(iteratorList->value->name,(yyvsp[0].strname))==0) && (strcmp(iteratorList->value->paramlist,typesOfCall)==0))
                                        {
                                                funcFound=1;
                                                (yyval.expr_ptr)=create_expression(iteratorList->value->dataType,eString);
                                                break;
                                        }
                                        else
                                        {
                                                printf("Functie:%s \t Apel:%s \t Args:%s \n",iteratorList->value->name,typesOfCall,iteratorList->value->paramlist);
                                        }
                                      }
                                      else
                                      {
                                        if((strcmp(iteratorList->value->whatIs,"function-declaration")==0 || (strcmp(iteratorList->value->whatIs,"class-function-declaration")==0)) && (strcmp(iteratorList->value->name,(yyvsp[0].strname))==0) && (strcmp(iteratorList->value->paramlist,typesOfCall)==0))
                                        {
                                                funcFound=1;
                                                (yyval.expr_ptr)=create_expression(iteratorList->value->dataType,eString);
                                                break;
                                        }
                                      }
                                        
                                      iteratorList=iteratorList->next;
                                      
                              }

                              iterator=iterator->next;
                      }
                        
                        
                        if(!funcFound)
                        {
                                printf("Functia [%s] pe care ati apelat-o nu este definita!\n",(yyvsp[0].strname));
                                exit(EXIT_FAILURE);
                        }
                        
                        free(typesOfCall);
                        free(eString);
                        eString=NULL;
                        typesOfCall=NULL;
                }
#line 2061 "y.tab.c"
    break;

  case 59:
#line 470 "experiment_hash.y"
    {
         if(typesOfCall==NULL)
                {
                        typesOfCall=malloc(strlen((yyvsp[0].expr_ptr)->type)+1);
                        strcpy(typesOfCall,(yyvsp[0].expr_ptr)->type);
                        typesOfCall[strlen(typesOfCall)]='\0';
                }
                else
                {
                        char*temp_var=realloc(typesOfCall,strlen(typesOfCall)+strlen((yyvsp[0].expr_ptr)->type)+2);
                        strcat(temp_var,",");
                        strcat(temp_var,(yyvsp[0].expr_ptr)->type);
                        typesOfCall=temp_var;
                        typesOfCall[strlen(typesOfCall)]='\0';
                }
        }
#line 2082 "y.tab.c"
    break;

  case 60:
#line 487 "experiment_hash.y"
    {
               typesOfCall=malloc(strlen((yyvsp[0].expr_ptr)->type)+1);
               strcpy(typesOfCall,(yyvsp[0].expr_ptr)->type);
         }
#line 2091 "y.tab.c"
    break;

  case 61:
#line 491 "experiment_hash.y"
    {
            typesOfCall=malloc(1);
            typesOfCall[0]='\0';
         }
#line 2100 "y.tab.c"
    break;

  case 62:
#line 498 "experiment_hash.y"
    {add_statement_node();}
#line 2106 "y.tab.c"
    break;

  case 63:
#line 498 "experiment_hash.y"
    {remove_node();}
#line 2112 "y.tab.c"
    break;

  case 65:
#line 499 "experiment_hash.y"
    {add_statement_node();}
#line 2118 "y.tab.c"
    break;

  case 66:
#line 499 "experiment_hash.y"
    {remove_node();}
#line 2124 "y.tab.c"
    break;

  case 68:
#line 502 "experiment_hash.y"
    {add_statement_node();}
#line 2130 "y.tab.c"
    break;

  case 69:
#line 502 "experiment_hash.y"
    {remove_node();}
#line 2136 "y.tab.c"
    break;

  case 70:
#line 503 "experiment_hash.y"
    {add_statement_node();}
#line 2142 "y.tab.c"
    break;

  case 71:
#line 503 "experiment_hash.y"
    {remove_node();}
#line 2148 "y.tab.c"
    break;

  case 73:
#line 507 "experiment_hash.y"
    {add_statement_node();}
#line 2154 "y.tab.c"
    break;

  case 74:
#line 507 "experiment_hash.y"
    {remove_node();}
#line 2160 "y.tab.c"
    break;

  case 75:
#line 508 "experiment_hash.y"
    {add_statement_node();}
#line 2166 "y.tab.c"
    break;

  case 76:
#line 508 "experiment_hash.y"
    {remove_node();}
#line 2172 "y.tab.c"
    break;

  case 77:
#line 512 "experiment_hash.y"
    {
                        int varFound=0;
                        struct Checker*iterator=head;
                        char*retType;
                        while(iterator)
                        {
                                struct ListOfEntries*searchList=g_hash_table_lookup(iterator->localScope,(yyvsp[0].strname));
                                struct ListOfEntries*saveList=NULL;
                                while(searchList)
                                {
                                        if(saveList==NULL)
                                        {
                                                saveList=malloc(sizeof(struct ListOfEntries));
                                                saveList->next=NULL;
                                                saveList->value=searchList->value;
                                        }
                                        else
                                        {
                                                struct ListOfEntries*newNode=malloc(sizeof(struct ListOfEntries));
                                                newNode->value=searchList->value;
                                                newNode->next=saveList;
                                                saveList=newNode;
                                        }
                                        struct ListOfEntries*newNode;
                                        if(!inClass)
                                        {
                                                if((strcmp(searchList->value->name,(yyvsp[0].strname))==0) && (strcmp(searchList->value->scope,iterator->currentScope)==0) && (strcmp(searchList->value->whatIs,"variable")==0))
                                                {
                                                        varFound=1;
                                                        retType=malloc(strlen(searchList->value->dataType)+1);
                                                        strcpy(retType,searchList->value->dataType);
                                                        saveList->value->initialised=1;
                                                        
                                                }
                                        }
                                        else
                                        {
                                                 if((strcmp(searchList->value->name,(yyvsp[0].strname))==0) && (strcmp(searchList->value->scope,iterator->currentScope)==0) && ((strcmp(searchList->value->whatIs,"variable")==0) || (strcmp(searchList->value->whatIs,"class-variable")==0)))
                                                {
                                                        varFound=1;
                                                        retType=malloc(strlen(searchList->value->dataType)+1);
                                                        strcpy(retType,searchList->value->dataType);
                                                        saveList->value->initialised=1;
                                                }
                                        }
                                        searchList=searchList->next;
                                }
                                if(varFound)
                                {
                                        g_hash_table_replace(iterator->localScope,(yyvsp[0].strname),saveList);
                                        break;
                                }

                                iterator=iterator->next;
                        }
                        if(!varFound)
                        {
                                printf("Variabila [%s] nu este declarata in scope-ul curent !\n",(yyvsp[0].strname));
                                exit(EXIT_FAILURE);
                        }
                        if(strstr(retType,"const"))
                        {
                                printf("Variabila [%s] este de tipul [%s],valoarea sa nu poate fi modificata!\n",(yyvsp[0].strname),retType);
                                exit(EXIT_FAILURE);
                        }
                        if(strcmp(retType,(yyvsp[-2].expr_ptr)->type)!=0)
                        {
                                printf("Expresia [%s]-[%s] nu poate fi asignata variabilei [%s]-[%s]!\n",(yyvsp[-2].expr_ptr)->expString,(yyvsp[-2].expr_ptr)->type,(yyvsp[0].strname),retType);
                                exit(EXIT_FAILURE);
                        }
                        free(retType);
                        retType=NULL;
                        
                        
                }
#line 2252 "y.tab.c"
    break;

  case 78:
#line 588 "experiment_hash.y"
    {
                        struct Checker*iterator=head;
                        int objectFound=0;
                        char*retType;
                        while(iterator)
                        {
                                struct ListOfEntries*searchList=g_hash_table_lookup(iterator->localScope,(yyvsp[0].strname));
                                while(searchList)
                                {
                                        if((strcmp(searchList->value->name,(yyvsp[0].strname))==0) && (strcmp(searchList->value->whatIs,"object-variable")==0) && (strcmp(searchList->value->scope,iterator->currentScope)==0))
                                        {
                                                objectFound=1;
                                                break;
                                        }
                                        searchList=searchList->next;
                                }
                                iterator=iterator->next;
                        }
                        if(!objectFound)
                        {
                                printf("Identificatorul [%s] nu reprezinta un obiect!\n",(yyvsp[-2].strname));
                                exit(EXIT_FAILURE);
                        }
                        char*searchInstance=malloc(strlen((yyvsp[-2].strname))+strlen((yyvsp[0].strname))+2);
                        strcpy(searchInstance,(yyvsp[0].strname));
                        strcat(searchInstance,".");
                        strcat(searchInstance,(yyvsp[-2].strname));
                        searchInstance[strlen(searchInstance)]='\0';
                        iterator=head;
                        int instanceFound=0;
                        while(iterator)
                        {
                                struct ListOfEntries*searchList=g_hash_table_lookup(iterator->localScope,searchInstance);
                                struct ListOfEntries*saveList=NULL;
                                while(searchList)
                                {
                                        if(saveList==NULL)
                                        {
                                                saveList=malloc(sizeof(struct ListOfEntries));
                                                saveList->next=NULL;
                                                saveList->value=searchList->value;
                                        }
                                        else
                                        {
                                                struct ListOfEntries*newNode=malloc(sizeof(struct ListOfEntries));
                                                newNode->value=searchList->value;
                                                newNode->next=saveList;
                                                saveList=newNode;
                                        }
                                       if(!inClass)
                                       {
                                               
                                               if((strcmp(searchList->value->whatIs,"variable")==0) && (strcmp(searchList->value->scope,iterator->currentScope)==0) && (strcmp(searchList->value->name,searchInstance)==0))
                                               {
                                                       instanceFound=1;;
                                                       retType=malloc(strlen(searchList->value->dataType)+1);
                                                       strcpy(retType,searchList->value->dataType);
                                                       retType[strlen(retType)]='\0';
                                                       saveList->value->initialised=1;
                                               }
                                       }
                                       else
                                        {
                                              if(((strcmp(searchList->value->whatIs,"variable")==0) || (strcmp(searchList->value->whatIs,"class-variable")==0))&& (strcmp(searchList->value->scope,iterator->currentScope)==0) && (strcmp(searchList->value->name,searchInstance)==0))
                                               {
                                                       instanceFound=1;
                                                       retType=malloc(strlen(searchList->value->dataType)+1);
                                                       strcpy(retType,searchList->value->dataType);
                                                       retType[strlen(retType)]='\0';
                                                       saveList->value->initialised=1;
                                               }
                                        }
                                        searchList=searchList->next;
                                }
                                if(instanceFound)
                                {
                                        g_hash_table_replace(iterator->localScope,searchInstance,saveList);
                                        break;
                                }
                                iterator=iterator->next;
                        }
                        if(!instanceFound)
                        {
                                printf("Variabila [%s] nu este variabila membra a obiectului [%s]\n",(yyvsp[-2].strname),(yyvsp[0].strname));
                                exit(EXIT_FAILURE);
                        }
                        if(strcmp((yyvsp[-4].expr_ptr)->type,retType)!=0)
                        {
                                printf("Expresia [%s]-[%s] nu poate fi asignata [%s]-[%s]!\n",(yyvsp[-4].expr_ptr)->expString,(yyvsp[-4].expr_ptr)->type,searchInstance,retType);
                                exit(EXIT_FAILURE);
                        }
                        free(retType);
                        retType=NULL ;
                        searchInstance=NULL;

                }
#line 2353 "y.tab.c"
    break;

  case 79:
#line 686 "experiment_hash.y"
    {
                int exists=0;
                struct Checker*iterator=head;
                char*retType;
                while(iterator && !exists)
                {
                        struct ListOfEntries*searchList;
                        if(searchList=g_hash_table_lookup(iterator->localScope,(yyvsp[0].strname)))
                        {
                                while(searchList)
                                {
                                        if(strstr(searchList->value->dataType,"[") && strstr(searchList->value->dataType,"]") && strcmp(searchList->value->name,(yyvsp[0].strname))==0)
                                        {
                                                char*extChar;
                                                int noChr=strcspn(searchList->value->dataType,"[");
                                                extChar=malloc(noChr+1);
                                                strncpy(extChar,searchList->value->dataType,noChr);
                                                retType=malloc(strlen(extChar)+1);
                                                strcpy(retType,extChar);
                                                exists=1;
                                                break;
                                        } 
                                        searchList=searchList->next;
                                }
                        }
                        iterator=iterator->next;
                }
                if(!exists)
                {
                        printf("Identificatorul [%s] nu defineste un vector!\n",(yyvsp[0].strname));
                        exit(EXIT_FAILURE);

                }
                if(strcmp((yyvsp[-2].expr_ptr)->type,"int")!=0)
                {
                        printf("Pozitia pe care ati incercat sa o accesati din vectorul [%s] nu exista!\n",(yyvsp[0].strname));
                        exit(EXIT_FAILURE);
                }
                }
#line 2397 "y.tab.c"
    break;

  case 80:
#line 728 "experiment_hash.y"
    {add_statement_node();}
#line 2403 "y.tab.c"
    break;

  case 81:
#line 728 "experiment_hash.y"
    {remove_node();}
#line 2409 "y.tab.c"
    break;

  case 84:
#line 737 "experiment_hash.y"
    {
                                 
                                 char*customType=malloc(strlen(return_type((yyvsp[0].type)))+strlen("50"));
                                 if((strcmp((yyvsp[-3].expr_ptr)->type,"int")!=0))
                                 {
                                         printf("Ati incercat sa declarati un vector [%s] cu un numar maxim de elemente invalid [%s]-[%s]!\n",(yyvsp[-1].strname),(yyvsp[-3].expr_ptr)->expString,(yyvsp[-3].expr_ptr)->type);
                                         exit(EXIT_FAILURE);
                                 }
                                 strcpy(customType,return_type((yyvsp[0].type)));
                                 strcat(customType,"[");
                                 strcat(customType,"50");
                                 strcat(customType,"]");
                                 add_new_variable(customType,(yyvsp[-1].strname),1 );
                        }
#line 2428 "y.tab.c"
    break;

  case 85:
#line 752 "experiment_hash.y"
    {
                       
                        add_new_variable(return_type((yyvsp[0].type)),(yyvsp[-1].strname),0);
                        }
#line 2437 "y.tab.c"
    break;

  case 86:
#line 756 "experiment_hash.y"
    {
                            
                             struct Checker*iterator=head;
                             int clsFound=0;
                             while(iterator->next!=NULL)
                             {
                                     iterator=iterator->next;
                             }
                             struct ListOfEntries*searchList=g_hash_table_lookup(iterator->localScope,(yyvsp[0].strname));
                             while(searchList)
                             {
                                     if(strcmp(searchList->value->whatIs,"class-declaration")==0)
                                     {
                                        classScope=malloc(strlen(searchList->value->scope)+1);
                                        strcpy(classScope,searchList->value->scope);
                                        classScope[strlen(classScope)]='\0';
                                        objName=malloc(strlen((yyvsp[-1].strname))+1);
                                        strcpy(objName,(yyvsp[-1].strname));
                                        objName[strlen(objName)]='\0';
                                        clsFound=1;
                                        break;
                                     }
                                     searchList=searchList->next;
                             }
                             if(!clsFound)
                             {
                                     printf("Clasa [%s] pe care doriti sa o instantiati nu este declarata!\n",(yyvsp[0].strname));
                                     exit(EXIT_FAILURE);
                             }
                             objInstance=1;
                             add_new_variable((yyvsp[0].strname),(yyvsp[-1].strname),0);
                             objInstance=0;
                             g_hash_table_foreach(iterator->localScope,add_every_variable,NULL);
                             free(classScope);
                             classScope=NULL;
                             struct ListOfEntries *iteratorVars=objVars;
                             while(iteratorVars)
                             {
                                     add_new_variable(iteratorVars->value->dataType,iteratorVars->value->name,iteratorVars->value->initialised);
                                     iteratorVars=iteratorVars->next;
                             }
                             free_entry(objVars);
                             free(objName);
                             free(classScope);
                             classScope=NULL;
                             objName=NULL;
                             objVars=NULL;
                        }
#line 2490 "y.tab.c"
    break;

  case 87:
#line 804 "experiment_hash.y"
    {
                                add_new_variable(return_type((yyvsp[0].type)),(yyvsp[-1].strname),1);
                                if(strcmp((yyvsp[-3].expr_ptr)->type,return_type((yyvsp[0].type)))!=0)
                                {
                                        printf("Expresia [%s]-[%s] nu poate fi asignata variabilei [%s]-[%s]!\n",(yyvsp[-3].expr_ptr)->expString,(yyvsp[-3].expr_ptr)->type,(yyvsp[-1].strname),return_type((yyvsp[0].type)));
                                        exit(EXIT_FAILURE);
                                }
                        }
#line 2503 "y.tab.c"
    break;

  case 88:
#line 812 "experiment_hash.y"
    {
                                char*newtype=malloc(strlen("const-")+strlen(return_type((yyvsp[-1].type)))+1);
                                strcpy(newtype,"const-");
                                strcat(newtype,return_type((yyvsp[-1].type)));
                                newtype[strlen(newtype)]='\0';
                                add_new_variable(newtype,(yyvsp[-2].strname),1);
                                if(strcmp((yyvsp[-4].expr_ptr)->type,return_type((yyvsp[-1].type)))!=0)
                                {
                                        printf("Variabila [%s]-tip[const-%s] nu poate fi initializata cu o expresie[%s]-tip[%s]",(yyvsp[-2].strname),return_type((yyvsp[-1].type)),(yyvsp[-4].expr_ptr)->expString,(yyvsp[-4].expr_ptr)->type);
                                        exit(EXIT_FAILURE);
                                }
                        }
#line 2520 "y.tab.c"
    break;

  case 89:
#line 831 "experiment_hash.y"
    {(yyval.type)=(yyvsp[0].type);}
#line 2526 "y.tab.c"
    break;

  case 90:
#line 832 "experiment_hash.y"
    {(yyval.type)=(yyvsp[0].type);}
#line 2532 "y.tab.c"
    break;

  case 91:
#line 833 "experiment_hash.y"
    {(yyval.type)=(yyvsp[0].type);}
#line 2538 "y.tab.c"
    break;

  case 92:
#line 834 "experiment_hash.y"
    {(yyval.type)=(yyvsp[0].type);}
#line 2544 "y.tab.c"
    break;

  case 93:
#line 835 "experiment_hash.y"
    {(yyval.type)=(yyvsp[0].type);}
#line 2550 "y.tab.c"
    break;

  case 94:
#line 836 "experiment_hash.y"
    {(yyval.type)=(yyvsp[0].type);}
#line 2556 "y.tab.c"
    break;

  case 95:
#line 839 "experiment_hash.y"
    {
            int initialised=0;
            int exists=0;
            int line;
            char*retType;
                struct Checker*iterator=head;
                while(iterator)
                {
                        struct ListOfEntries*searchList=g_hash_table_lookup(iterator->localScope,(yyvsp[0].strname));
                        while(searchList)
                        {
                                if(!inClass)
                                {
                                        if(strcmp(searchList->value->name,(yyvsp[0].strname))==0 && strcmp(searchList->value->whatIs,"variable")==0 && strcmp(searchList->value->scope,iterator->currentScope)==0)
                                        {
                                                exists=1;
                                                if(searchList->value->initialised)
                                                initialised=1;
                                                if(exists || initialised)
                                                {
                                                retType=malloc(strlen(searchList->value->dataType)+1);
                                                strcpy(retType,searchList->value->dataType);
                                                break;
                                                }
                                        }
                                }
                                else
                                {
                                      if(strcmp(searchList->value->name,(yyvsp[0].strname))==0 && ((strcmp(searchList->value->whatIs,"variable")==0) || (strcmp(searchList->value->whatIs,"class-variable")==0)) && strcmp(searchList->value->scope,iterator->currentScope)==0)
                                        {
                                                exists=1;
                                                if(searchList->value->initialised)
                                                initialised=1;
                                                if(exists || initialised)
                                                {
                                                retType=malloc(strlen(searchList->value->dataType)+1);
                                                strcpy(retType,searchList->value->dataType);
                                                break;
                                                }
                                        }  
                                }
                                searchList=searchList->next;    
                        }
                        iterator=iterator->next;
                }
            
            if(!exists)
            {
                printf("Variabila [%s] nu este declarata in scope-ul curent!\n",(yyvsp[0].strname));
                exit(EXIT_FAILURE);
            }   
            if(!initialised)
            {
                    printf("Variabila [%s] este definita insa nu si initializata!\n",(yyvsp[0].strname));
                    exit(EXIT_FAILURE);
            }
            (yyval.expr_ptr)=create_variable_expression((yyvsp[0].strname),retType);
        }
#line 2619 "y.tab.c"
    break;

  case 96:
#line 897 "experiment_hash.y"
    {(yyval.expr_ptr)=create_int_expression((yyvsp[0].intval));}
#line 2625 "y.tab.c"
    break;

  case 97:
#line 898 "experiment_hash.y"
    {(yyval.expr_ptr)=create_float_expression((yyvsp[0].floatval));}
#line 2631 "y.tab.c"
    break;

  case 98:
#line 899 "experiment_hash.y"
    {(yyval.expr_ptr)=create_bool_expression((yyvsp[0].boolVal));}
#line 2637 "y.tab.c"
    break;

  case 99:
#line 900 "experiment_hash.y"
    {(yyval.expr_ptr)=create_bool_expression((yyvsp[0].boolVal));}
#line 2643 "y.tab.c"
    break;

  case 100:
#line 901 "experiment_hash.y"
    {(yyval.expr_ptr)=create_string_expression((yyvsp[0].strval));}
#line 2649 "y.tab.c"
    break;

  case 101:
#line 902 "experiment_hash.y"
    {(yyval.expr_ptr)=create_char_expression((yyvsp[0].charval));}
#line 2655 "y.tab.c"
    break;

  case 102:
#line 903 "experiment_hash.y"
    {(yyval.expr_ptr)=(yyvsp[0].expr_ptr);}
#line 2661 "y.tab.c"
    break;

  case 103:
#line 904 "experiment_hash.y"
    {(yyval.expr_ptr)=(yyvsp[0].expr_ptr);}
#line 2667 "y.tab.c"
    break;

  case 104:
#line 905 "experiment_hash.y"
    {(yyval.expr_ptr)=(yyvsp[0].expr_ptr);}
#line 2673 "y.tab.c"
    break;

  case 105:
#line 906 "experiment_hash.y"
    {(yyval.expr_ptr)=(yyvsp[0].expr_ptr);}
#line 2679 "y.tab.c"
    break;

  case 106:
#line 907 "experiment_hash.y"
    {(yyval.expr_ptr)=create_paranthesis_expression((yyvsp[-1].expr_ptr));}
#line 2685 "y.tab.c"
    break;

  case 107:
#line 909 "experiment_hash.y"
    {
                        if(strcmp((yyvsp[-2].expr_ptr)->type,(yyvsp[0].expr_ptr)->type)!=0)
                        {
                                printf("Nu se poate efectua operatia de adunare pe tipul [%s] si tipul [%s] \n%s+%s\n",(yyvsp[-2].expr_ptr)->expString,(yyvsp[0].expr_ptr)->expString,(yyvsp[-2].expr_ptr)->expString,(yyvsp[0].expr_ptr)->expString);
                                exit(EXIT_FAILURE);
                        }
                        char*concatExp=malloc(strlen((yyvsp[-2].expr_ptr)->expString)+strlen((yyvsp[0].expr_ptr)->expString)+2);
                        strcpy(concatExp,(yyvsp[-2].expr_ptr)->expString);
                        strcat(concatExp,"+");
                        strcat(concatExp,(yyvsp[0].expr_ptr)->expString);
                        (yyval.expr_ptr)=create_expression((yyvsp[-2].expr_ptr)->type,concatExp);
                }
#line 2702 "y.tab.c"
    break;

  case 108:
#line 922 "experiment_hash.y"
    {
                    if((strcmp((yyvsp[-2].expr_ptr)->type,"char*")==0) || (strcmp((yyvsp[0].expr_ptr)->type,"char*")==0))
                        {
                                printf("Nu se poate efectua operatia de inmultire pe tipul [*rahc]\n%s+%s\n",(yyvsp[-2].expr_ptr)->expString,(yyvsp[0].expr_ptr)->expString);
                                exit(EXIT_FAILURE);
                        }
                        if(strcmp((yyvsp[-2].expr_ptr)->type,(yyvsp[0].expr_ptr)->type)!=0)
                        {
                                printf("Nu se poate efectua operatia de inmultire pe tipul [%s] si tipul [%s] \n%s+%s\n",(yyvsp[-2].expr_ptr)->expString,(yyvsp[0].expr_ptr)->expString,(yyvsp[-2].expr_ptr)->expString,(yyvsp[0].expr_ptr)->expString);
                                exit(EXIT_FAILURE);
                        }
                        char*concatExp=malloc(strlen((yyvsp[-2].expr_ptr)->expString)+strlen((yyvsp[0].expr_ptr)->expString)+2);
                        strcpy(concatExp,(yyvsp[-2].expr_ptr)->expString);
                        strcat(concatExp,"*");
                        strcat(concatExp,(yyvsp[0].expr_ptr)->expString);
                        (yyval.expr_ptr)=create_expression((yyvsp[-2].expr_ptr)->type,concatExp);


          }
#line 2726 "y.tab.c"
    break;

  case 109:
#line 942 "experiment_hash.y"
    {
                   if((strcmp((yyvsp[-2].expr_ptr)->type,"char*")==0) || (strcmp((yyvsp[0].expr_ptr)->type,"char*")==0))
                        {
                                printf("Nu se poate efectua operatia de impartire pe tipul [*rahc]\n%s+%s\n",(yyvsp[-2].expr_ptr)->expString,(yyvsp[0].expr_ptr)->expString);
                                exit(EXIT_FAILURE);
                        }
                        if(strcmp((yyvsp[-2].expr_ptr)->type,(yyvsp[0].expr_ptr)->type)!=0)
                        {
                                printf("Nu se poate efectua operatia de impartire pe tipul [%s] si tipul [%s] \n%s+%s\n",(yyvsp[-2].expr_ptr)->expString,(yyvsp[0].expr_ptr)->expString,(yyvsp[-2].expr_ptr)->expString,(yyvsp[0].expr_ptr)->expString);
                                exit(EXIT_FAILURE);
                        }
                        char*concatExp=malloc(strlen((yyvsp[-2].expr_ptr)->expString)+strlen((yyvsp[0].expr_ptr)->expString)+2);
                        strcpy(concatExp,(yyvsp[-2].expr_ptr)->expString);
                        strcat(concatExp,"/");
                        strcat(concatExp,(yyvsp[0].expr_ptr)->expString);
                        (yyval.expr_ptr)=create_expression((yyvsp[-2].expr_ptr)->type,concatExp);

          }
#line 2749 "y.tab.c"
    break;

  case 110:
#line 961 "experiment_hash.y"
    {
                   if((strcmp((yyvsp[-2].expr_ptr)->type,"char*")==0) || (strcmp((yyvsp[0].expr_ptr)->type,"char*")==0))
                        {
                                printf("Nu se poate efectua operatia de scadeere pe tipul [*rahc]\n%s+%s\n",(yyvsp[-2].expr_ptr)->expString,(yyvsp[0].expr_ptr)->expString);
                                exit(EXIT_FAILURE);
                        }
                        if(strcmp((yyvsp[-2].expr_ptr)->type,(yyvsp[0].expr_ptr)->type)!=0)
                        {
                                printf("Nu se poate efectua operatia de scadere pe tipul [%s] si tipul [%s] \n%s+%s\n",(yyvsp[-2].expr_ptr)->expString,(yyvsp[0].expr_ptr)->expString,(yyvsp[-2].expr_ptr)->expString,(yyvsp[0].expr_ptr)->expString);
                                exit(EXIT_FAILURE);
                        }
                        char*concatExp=malloc(strlen((yyvsp[-2].expr_ptr)->expString)+strlen((yyvsp[0].expr_ptr)->expString)+2);
                        strcpy(concatExp,(yyvsp[-2].expr_ptr)->expString);
                        strcat(concatExp,"-");
                        strcat(concatExp,(yyvsp[0].expr_ptr)->expString);
                        (yyval.expr_ptr)=create_expression((yyvsp[-2].expr_ptr)->type,concatExp);
          }
#line 2771 "y.tab.c"
    break;

  case 111:
#line 979 "experiment_hash.y"
    {
                if((strcmp((yyvsp[-2].expr_ptr)->type,"char*")==0) || (strcmp((yyvsp[0].expr_ptr)->type,"char*")==0))
                {
                                printf("Nu se poate aplica operatorul logic > pe tipul [*rahc]\n%s+%s\n",(yyvsp[-2].expr_ptr)->expString,(yyvsp[0].expr_ptr)->expString);
                                exit(EXIT_FAILURE);
                }
                if((strcmp((yyvsp[-2].expr_ptr)->type,"bool")==0) || (strcmp((yyvsp[0].expr_ptr)->type,"bool")==0))
                {
                                printf("Nu se poate aplica operatorul > pe tipul [bool]\n%s+%s\n",(yyvsp[-2].expr_ptr)->expString,(yyvsp[0].expr_ptr)->expString);
                                exit(EXIT_FAILURE);
                }
                char*concatExp=malloc(strlen((yyvsp[-2].expr_ptr)->expString)+strlen((yyvsp[0].expr_ptr)->expString)+2);
                strcpy(concatExp,(yyvsp[-2].expr_ptr)->expString);
                strcat(concatExp,">");
                strcat(concatExp,(yyvsp[0].expr_ptr)->expString);
                (yyval.expr_ptr)=create_expression("bool",concatExp);
          }
#line 2793 "y.tab.c"
    break;

  case 112:
#line 997 "experiment_hash.y"
    {
                if((strcmp((yyvsp[-2].expr_ptr)->type,"char*")==0) || (strcmp((yyvsp[0].expr_ptr)->type,"char*")==0))
                {
                                printf("Nu se poate aplica operatorul < tipul [*rahc]\n%s+%s\n",(yyvsp[-2].expr_ptr)->expString,(yyvsp[0].expr_ptr)->expString);
                                exit(EXIT_FAILURE);
                }
                if((strcmp((yyvsp[-2].expr_ptr)->type,"bool")==0) || (strcmp((yyvsp[0].expr_ptr)->type,"bool")==0))
                {
                                printf("Nu se poate aplica operatorul > pe tipul [bool]\n%s+%s\n",(yyvsp[-2].expr_ptr)->expString,(yyvsp[0].expr_ptr)->expString);
                                exit(EXIT_FAILURE);
                }
                char*concatExp=malloc(strlen((yyvsp[-2].expr_ptr)->expString)+strlen((yyvsp[0].expr_ptr)->expString)+2);
                strcpy(concatExp,(yyvsp[-2].expr_ptr)->expString);
                strcat(concatExp,"<");
                strcat(concatExp,(yyvsp[0].expr_ptr)->expString);
                (yyval.expr_ptr)=create_expression("bool",concatExp);
          }
#line 2815 "y.tab.c"
    break;

  case 113:
#line 1015 "experiment_hash.y"
    {
                char*concatExp=malloc(strlen((yyvsp[-2].expr_ptr)->expString)+strlen((yyvsp[0].expr_ptr)->expString)+2);
                strcpy(concatExp,(yyvsp[-2].expr_ptr)->expString);
                strcat(concatExp,"==");
                strcat(concatExp,(yyvsp[0].expr_ptr)->expString);
                (yyval.expr_ptr)=create_expression("bool",concatExp);
          }
#line 2827 "y.tab.c"
    break;

  case 114:
#line 1023 "experiment_hash.y"
    {
                if((strcmp((yyvsp[-2].expr_ptr)->type,"char*")==0) || (strcmp((yyvsp[0].expr_ptr)->type,"char*")==0))
                {
                                printf("Nu se poate aplica operatorul <= tipul [*rahc]\n%s+%s\n",(yyvsp[-2].expr_ptr)->expString,(yyvsp[0].expr_ptr)->expString);
                                exit(EXIT_FAILURE);
                }
                if((strcmp((yyvsp[-2].expr_ptr)->type,"bool")==0) || (strcmp((yyvsp[0].expr_ptr)->type,"bool")==0))
                {
                                printf("Nu se poate aplica operatorul <= pe tipul [bool]\n%s+%s\n",(yyvsp[-2].expr_ptr)->expString,(yyvsp[0].expr_ptr)->expString);
                                exit(EXIT_FAILURE);
                }
                if(strcmp((yyvsp[-2].expr_ptr)->type,(yyvsp[0].expr_ptr)->type)!=0)
                {
                                printf("Nu se poate efectua operatorul<= pe tipul [%s] si tipul [%s] \n%s+%s\n",(yyvsp[-2].expr_ptr)->expString,(yyvsp[0].expr_ptr)->expString,(yyvsp[-2].expr_ptr)->expString,(yyvsp[0].expr_ptr)->expString);
                                exit(EXIT_FAILURE);
                }
                 char*concatExp=malloc(strlen((yyvsp[-2].expr_ptr)->expString)+strlen((yyvsp[0].expr_ptr)->expString)+2);
                strcpy(concatExp,(yyvsp[-2].expr_ptr)->expString);
                strcat(concatExp,"<=");
                strcat(concatExp,(yyvsp[0].expr_ptr)->expString);
                (yyval.expr_ptr)=create_expression("bool",concatExp);
          }
#line 2854 "y.tab.c"
    break;

  case 115:
#line 1046 "experiment_hash.y"
    {
                  if((strcmp((yyvsp[-2].expr_ptr)->type,"char*")==0) || (strcmp((yyvsp[0].expr_ptr)->type,"char*")==0))
                {
                                printf("Nu se poate aplica operatorul >= tipul [*rahc]\n%s+%s\n",(yyvsp[-2].expr_ptr)->expString,(yyvsp[0].expr_ptr)->expString);
                                exit(EXIT_FAILURE);
                }
                if((strcmp((yyvsp[-2].expr_ptr)->type,"bool")==0) || (strcmp((yyvsp[0].expr_ptr)->type,"bool")==0))
                {
                                printf("Nu se poate aplica operatorul >= pe tipul [bool]\n%s+%s\n",(yyvsp[-2].expr_ptr)->expString,(yyvsp[0].expr_ptr)->expString);
                                exit(EXIT_FAILURE);
                }
                if(strcmp((yyvsp[-2].expr_ptr)->type,(yyvsp[0].expr_ptr)->type)!=0)
                {
                                printf("Nu se poate efectua operatorul >= pe tipul [%s] si tipul [%s] \n%s+%s\n",(yyvsp[-2].expr_ptr)->expString,(yyvsp[0].expr_ptr)->expString,(yyvsp[-2].expr_ptr)->expString,(yyvsp[0].expr_ptr)->expString);
                                exit(EXIT_FAILURE);
                }
                 char*concatExp=malloc(strlen((yyvsp[-2].expr_ptr)->expString)+strlen((yyvsp[0].expr_ptr)->expString)+2);
                strcpy(concatExp,(yyvsp[-2].expr_ptr)->expString);
                strcat(concatExp,">=");
                strcat(concatExp,(yyvsp[0].expr_ptr)->expString);
                (yyval.expr_ptr)=create_expression("bool",concatExp);
          }
#line 2881 "y.tab.c"
    break;

  case 116:
#line 1069 "experiment_hash.y"
    {
                if((strcmp((yyvsp[-2].expr_ptr)->type,"bool")!=0) && (strcmp((yyvsp[0].expr_ptr)->type,"bool")!=0))
                {
                                printf("Nu se poate efectua operatorul && \n%s&&%s\n",(yyvsp[-2].expr_ptr)->expString,(yyvsp[0].expr_ptr)->expString);
                                exit(EXIT_FAILURE);
                }
                char*concatExp=malloc(strlen((yyvsp[-2].expr_ptr)->expString)+strlen((yyvsp[0].expr_ptr)->expString)+3);
                strcpy(concatExp,(yyvsp[-2].expr_ptr)->expString);
                strcat(concatExp,"&&");
                strcat(concatExp,(yyvsp[0].expr_ptr)->expString);
                (yyval.expr_ptr)=create_expression("bool",concatExp);
          }
#line 2898 "y.tab.c"
    break;

  case 117:
#line 1082 "experiment_hash.y"
    {
          if((strcmp((yyvsp[-2].expr_ptr)->type,"bool")!=0) && (strcmp((yyvsp[0].expr_ptr)->type,"bool")!=0))
                {
                                printf("Nu se poate efectua operatorul || \n%s||%s\n",(yyvsp[-2].expr_ptr)->expString,(yyvsp[0].expr_ptr)->expString);
                                exit(EXIT_FAILURE);
                }
                char*concatExp=malloc(strlen((yyvsp[-2].expr_ptr)->expString)+strlen((yyvsp[0].expr_ptr)->expString)+3);
                strcpy(concatExp,(yyvsp[-2].expr_ptr)->expString);
                strcat(concatExp,"&&");
                strcat(concatExp,(yyvsp[0].expr_ptr)->expString);
                (yyval.expr_ptr)=create_expression("bool",concatExp);
          }
#line 2915 "y.tab.c"
    break;

  case 118:
#line 1095 "experiment_hash.y"
    {
                if(strcmp((yyvsp[0].expr_ptr)->type,"bool")!=0)
                {
                        printf("Nu se poate aplica operatorul ! expresiei [%s]!\n",(yyvsp[0].expr_ptr)->expString);
                        exit(EXIT_FAILURE);
                }
                char*concatExp=malloc(strlen((yyvsp[0].expr_ptr)->expString)+2);
                strcat(concatExp,"!");
                strcat(concatExp,(yyvsp[0].expr_ptr)->expString);
                (yyval.expr_ptr)=create_expression("bool",concatExp);
          }
#line 2931 "y.tab.c"
    break;

  case 119:
#line 1106 "experiment_hash.y"
    {
                  char*concatExp=malloc(strlen("strlen()")+strlen((yyvsp[-2].expr_ptr)->expString)+1);
                  strcpy(concatExp,"(");
                  strcat(concatExp,(yyvsp[-2].expr_ptr)->expString);
                  strcat(concatExp,")nelrts");
                  (yyval.expr_ptr)=create_expression("int",concatExp);
                  }
#line 2943 "y.tab.c"
    break;

  case 120:
#line 1117 "experiment_hash.y"
    {

                                struct Checker*iterator=head;
                                int objFound=0;
                                int funcFound=0;
                                char*objClass=NULL;
                                char*scopeOf=NULL;
                                char*eString;
                                eString=malloc(strlen(typesOfCall)+strlen((yyvsp[-2].strname))+strlen((yyvsp[0].strname))+4);
                                strcpy(eString,"(");
                                strcat(eString,typesOfCall);
                                strcat(eString,")");
                                strcat(eString,(yyvsp[-2].strname));
                                strcat(eString,".");
                                strcat(eString,(yyvsp[0].strname));
                                eString[strlen(eString)]='\0';
                                while(iterator && !objFound)
                                {
                                        struct ListOfEntries*searchList=g_hash_table_lookup(iterator->localScope,(yyvsp[0].strname));
                                        while(searchList)
                                        {
                                                if((strcmp(searchList->value->whatIs,"object-variable")==0) && (strcmp(searchList->value->name,(yyvsp[0].strname))==0) && (strcmp(searchList->value->scope,iterator->currentScope)==0))
                                                {
                                                        objFound=1;
                                                        objClass=malloc(strlen(searchList->value->dataType)+1);
                                                        strcpy(objClass,searchList->value->dataType);
                                                        objClass[strlen(objClass)]='\0';
                                                        break;
                                                }
                                                searchList=searchList->next;

                                        }
                                        iterator=iterator->next;
                                }
                                if(!objFound)
                                {
                                        printf("Identificatorul [%s] nu desemneaza un obiect!\n",(yyvsp[0].strname));
                                        exit(EXIT_FAILURE);
                                }
                                iterator=head;
                                while(iterator)
                                {
                                        struct ListOfEntries*searchList=g_hash_table_lookup(iterator->localScope,objClass);
                                        while(searchList)
                                        {
                                                if((strcmp(searchList->value->whatIs,"class-declaration")==0) && (strcmp(searchList->value->name,objClass)==0))
                                                {
                                                        scopeOf=malloc(strlen(searchList->value->scope)+1);
                                                        strcpy(scopeOf,searchList->value->scope);
                                                        scopeOf[strlen(scopeOf)]='\0';
                                                        break;
                                                }
                                                searchList=searchList->next;
                                        }
                                        iterator=iterator->next;
                                }
                                iterator=head;
                                 while(iterator)
                                {
                                        struct ListOfEntries*searchList=g_hash_table_lookup(iterator->localScope,(yyvsp[-2].strname));
                                        while(searchList)
                                        {
                                                if((strcmp(searchList->value->whatIs,"class-function-declaration")==0) && (strcmp(searchList->value->name,(yyvsp[-2].strname))==0) && (strstr(searchList->value->scope,scopeOf)) && (strcmp(typesOfCall,searchList->value->paramlist)==0))
                                                {
                                                        funcFound=1;
                                                        (yyval.expr_ptr)=create_expression(searchList->value->dataType,eString);
                                                        break;
                                                }
                                                searchList=searchList->next;
                                        }
                                        iterator=iterator->next;
                                }
                                if(!funcFound)
                                {
                                        printf("Functia [%s] nu este functie membra a clasei [%s]!\n",(yyvsp[-2].strname),objClass);
                                        exit(EXIT_FAILURE);
                                }
                                free(objClass);
                                free(scopeOf);
                                free(typesOfCall);
                                typesOfCall=NULL;
                                
                        }
#line 3031 "y.tab.c"
    break;

  case 121:
#line 1204 "experiment_hash.y"
    {
                        struct Checker*iterator=head;
                        int objectFound=0;
                        while(iterator)
                        {
                                struct ListOfEntries*searchList=g_hash_table_lookup(iterator->localScope,(yyvsp[0].strname));
                                while(searchList)
                                {
                                        if((strcmp(searchList->value->name,(yyvsp[0].strname))==0) && (strcmp(searchList->value->whatIs,"object-variable")==0) && (strcmp(searchList->value->scope,iterator->currentScope)==0))
                                        {
                                                objectFound=1;
                                                break;
                                        }
                                        searchList=searchList->next;
                                }
                                iterator=iterator->next;
                        }
                        if(!objectFound)
                        {
                                printf("Identificatorul [%s] nu reprezinta un obiect!\n",(yyvsp[0].strname));
                                exit(EXIT_FAILURE);
                        }
                        char*searchInstance=malloc(strlen((yyvsp[-2].strname))+strlen((yyvsp[0].strname))+2);
                        strcpy(searchInstance,(yyvsp[0].strname));
                        strcat(searchInstance,".");
                        strcat(searchInstance,(yyvsp[-2].strname));
                        searchInstance[strlen(searchInstance)]='\0';
                        iterator=head;
                        int instanceFound=0;
                        while(iterator)
                        {
                                struct ListOfEntries*searchList=g_hash_table_lookup(iterator->localScope,searchInstance);
                                while(searchList)
                                {
                                       if(!inClass)
                                       {
                                               
                                               if((strcmp(searchList->value->whatIs,"variable")==0) && (strcmp(searchList->value->scope,iterator->currentScope)==0) && (strcmp(searchList->value->name,searchInstance)==0))
                                               {
                                                       instanceFound=1;
                                                       (yyval.expr_ptr)=create_expression(searchList->value->dataType,searchInstance);
                                                       break;
                                               }
                                       }
                                       else
                                        {
                                              if(((strcmp(searchList->value->whatIs,"variable")==0) || (strcmp(searchList->value->whatIs,"class-variable")==0))&& (strcmp(searchList->value->scope,iterator->currentScope)==0) && (strcmp(searchList->value->name,searchInstance)==0))
                                               {
                                                       instanceFound=1;
                                                       (yyval.expr_ptr)=create_expression(searchList->value->dataType,searchInstance);
                                                       break;
                                               }
                                        }
                                        searchList=searchList->next;
                                }
                                iterator=iterator->next;
                        }
                        if(!instanceFound)
                        {
                                printf("Variabila [%s] nu este variabila membra a obiectului [%s]\n",(yyvsp[-2].strname),(yyvsp[0].strname));
                                exit(EXIT_FAILURE);
                        }
                        free(searchInstance);
                        searchInstance=NULL;
                }
#line 3101 "y.tab.c"
    break;

  case 122:
#line 1270 "experiment_hash.y"
    {
                int exists=0;
                struct Checker*iterator=head;
                char*retType;
                while(iterator && !exists)
                {
                        struct ListOfEntries*searchList;
                        if(searchList=g_hash_table_lookup(iterator->localScope,(yyvsp[0].strname)))
                        {
                                while(searchList)
                                {
                                        if(strstr(searchList->value->dataType,"[") && strstr(searchList->value->dataType,"]") && strcmp(searchList->value->name,(yyvsp[0].strname))==0)
                                        {
                                                char*extChar;
                                                int noChr=strcspn(searchList->value->dataType,"[");
                                                extChar=malloc(noChr+1);
                                                strncpy(extChar,searchList->value->dataType,noChr);
                                                retType=malloc(strlen(extChar)+1);
                                                strcpy(retType,extChar);
                                                exists=1;
                                                break;
                                        } 
                                        searchList=searchList->next;
                                }
                        }
                        iterator=iterator->next;
                }
                if(!exists)
                {
                        printf("Identificatorul [%s] nu defineste un vector!",(yyvsp[0].strname));
                        exit(EXIT_FAILURE);

                }
                if(strcmp((yyvsp[-2].expr_ptr)->type,"int")!=0)
                {
                        printf("Pozitia pe care ati incercat sa o accesati din vectorul [%s] nu exista!\n",(yyvsp[0].strname));
                        exit(EXIT_FAILURE);
                }

                  char*eString=malloc(3+strlen((yyvsp[-2].expr_ptr)->expString)+strlen((yyvsp[0].strname)));
                  strcpy(eString,"[");
                  strcat(eString,(yyvsp[-2].expr_ptr)->expString);
                  strcat(eString,"]");
                  strcat(eString,(yyvsp[0].strname));
                (yyval.expr_ptr)=create_expression(retType,eString);
                }
#line 3152 "y.tab.c"
    break;

  case 123:
#line 1318 "experiment_hash.y"
    {add_main_node();}
#line 3158 "y.tab.c"
    break;

  case 124:
#line 1318 "experiment_hash.y"
    {remove_node();}
#line 3164 "y.tab.c"
    break;

  case 125:
#line 1319 "experiment_hash.y"
    {add_main_node();}
#line 3170 "y.tab.c"
    break;

  case 126:
#line 1319 "experiment_hash.y"
    {remove_node();}
#line 3176 "y.tab.c"
    break;


#line 3180 "y.tab.c"

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
#line 1321 "experiment_hash.y"

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
        struct ListOfEntries*temp;
        while(val)
        {
                temp=val;
                val=val->next;
                g_free(temp);
        }
}
void free_checker(struct Checker*val)
{
        struct Checker*temp;
        while(val)
        {
                temp=val;
                val=val->next;
                g_free(temp);
        }
}
void add_func_node(char*identifier,const char*returntype)
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
        struct SymTabEntry*newEntry=malloc(sizeof(struct SymTabEntry));
        newEntry->name=malloc(strlen(identifier)+1);
        strcpy(newEntry->name,identifier);
        newEntry->name[strlen(newEntry->name)]='\0';
        newEntry->dataType=malloc(strlen(returntype)+1);
        strcpy(newEntry->dataType,returntype);
        newEntry->dataType[strlen(newEntry->dataType)]='\0';
        if(inClass==1)
        {
              newEntry->whatIs=malloc(strlen("class-function-declaration")+1);
                strcpy(newEntry->whatIs,"class-function-declaration");  
        }
        else
        {
                newEntry->whatIs=malloc(strlen("function-declaration")+1);
                strcpy(newEntry->whatIs,"function-declaration");
        }
        newEntry->whatIs[strlen(newEntry->whatIs)]='\0';
        newEntry->scope=malloc(strlen(head->currentScope)+1);
        strcpy(newEntry->scope,head->currentScope);
        newEntry->scope[strlen(newEntry->scope)]='\0';
        newEntry->lineOf=yylineno;
        struct ListOfEntries*iterator=funcArgs;
        int numChar=0;
        while(iterator)
        {
                numChar+=strlen(iterator->value->dataType)+1;
                iterator=iterator->next;
        }
        newEntry->paramlist=malloc(numChar+1);
        iterator=funcArgs;
        while(iterator)
        {
                strcat(newEntry->paramlist,iterator->value->dataType);
                strcat(newEntry->paramlist,",");
                iterator=iterator->next;
        }
        newEntry->paramlist[strlen(newEntry->paramlist)-1]='\0';
        newEntry->paramlist[strlen(newEntry->paramlist)]='\0';
        
        struct ListOfEntries*val;
        if((val=g_hash_table_lookup(head->next->localScope,identifier)))
        {
                while(val)
                {
                        if(strncmp(val->value->scope,newEntry->scope,strlen(newEntry->scope)-nLenght)==0 && ((strcmp(val->value->whatIs,"function-declaration")==0) || (strcmp(val->value->whatIs,"class-function-declaration")==0)) && strcmp(val->value->paramlist,newEntry->paramlist)==0)
                        {
                                printf("Functia [%s] de tipul de retur %s a fost redeclarata in scope-ul %s\nProgramul a fost incheiat fortat!\n",newEntry->name,newEntry->dataType,val->value->scope);
                                exit(EXIT_FAILURE);
                        }
                        val=val->next;
                }
        }
                struct ListOfEntries*newVal=malloc(sizeof(struct ListOfEntries));
                newVal->value=newEntry;
                newVal->next=NULL;
                g_hash_table_insert(head->localScope,identifier,newVal);
                if(funcArgs)
                {
                        struct ListOfEntries*iterator=funcArgs;
                        char*parList;
                        while(iterator)
                        {
                                add_new_variable(iterator->value->dataType,iterator->value->name,1);
                                iterator=iterator->next;
                        }
                }
                struct ListOfEntries*tmp;
                while(iterator)
                {
                        tmp=iterator;
                        iterator=iterator->next;
                        free(tmp);
                }
                funcArgs=NULL;

}
void add_new_variable(const char*type,char*identifier,int init)
{
        if(strcmp(type,"void")==0)
        {
                printf("Variabila [%s] declarata de tipul void\n",identifier);
                exit(EXIT_FAILURE);
        }
        struct SymTabEntry*newEntry=malloc(sizeof(struct SymTabEntry));
        newEntry->name=malloc(strlen(identifier)+1);
        newEntry->name[strlen(newEntry->name)]='\0';
        strcpy(newEntry->name,identifier);
        newEntry->dataType=malloc(strlen(type)+1);
        strcpy(newEntry->dataType,type);
        newEntry->dataType[strlen(newEntry->dataType)]='\0';
        if(inClass)
        {
                newEntry->whatIs=malloc(strlen("class-variable")+1);
                strcpy(newEntry->whatIs,"class-variable");
        }
        else
        {
                newEntry->whatIs=malloc(strlen("variable")+1);
                strcpy(newEntry->whatIs,"variable");
        }
         if(objInstance)
        {
                newEntry->whatIs=malloc(strlen("object-variable")+1);
                strcpy(newEntry->whatIs,"object-variable");
        }
        else
        {
                if(inClass==0)
                {
                        newEntry->whatIs=malloc(strlen("variable")+1);
                        strcpy(newEntry->whatIs,"variable");
                }
        }
        newEntry->whatIs[strlen(newEntry->whatIs)]='\0';
        newEntry->scope=malloc(strlen(head->currentScope)+1);
        strcpy(newEntry->scope,head->currentScope);
        newEntry->scope[strlen(newEntry->scope)]='\0';
        newEntry->lineOf=yylineno;
        newEntry->initialised=init;
        if(inArgs)
        {
                if(funcArgs==NULL)
                {
                   funcArgs=malloc(sizeof(struct ListOfEntries));
                   funcArgs->value=newEntry;
                   funcArgs->next=NULL;
                }
                else
                {
                       struct ListOfEntries*iterator=funcArgs;
                       struct ListOfEntries*newNode=malloc(sizeof(struct ListOfEntries));
                       newNode->value=newEntry;
                       while(iterator->next!=NULL)
                       {
                               iterator=iterator->next;
                       }
                       iterator->next=newNode;
                }
                return;
                   
        }
        struct ListOfEntries*val;
        if((val=g_hash_table_lookup(head->localScope,identifier)))
        {
                while(val)
                {
                        if(strcmp(val->value->scope,newEntry->scope)==0 && ((strcmp(val->value->whatIs,"variable")==0) || (strcmp(val->value->whatIs,"class-variable")==0)))
                        {
                                printf("Variabila [%s] de tipul %s a fost redeclarat in scope-ul %s\n",newEntry->name,newEntry->dataType,newEntry->scope);
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
           printf("%s \t%s\t %s\n",var->value->name,var->value->whatIs,var->value->scope);
           if((strcmp(var->value->whatIs,"variable")==0) || (strcmp(var->value->whatIs,"class-variable")==0) || (strcmp(var->value->whatIs,"object-variable")==0))
           {
                   fprintf(SymTabDump,"%i \t %s \t %s\t %s \t %i \t %s \t %i \n",var->value->lineOf,var->value->name,var->value->whatIs,var->value->dataType,var->value->intvalue,var->value->scope,var->value->initialised);
           }
           if((strcmp(var->value->whatIs,"function-declaration")==0) || (strcmp(var->value->whatIs,"class-function-declaration")==0))
           {
                   fprintf(SymTabDump,"%i \t %s \t %s \t %s \t %s \t %s\n",var->value->lineOf,var->value->name,var->value->whatIs,var->value->dataType,var->value->paramlist,var->value->scope);
           }
           if(strcmp(var->value->whatIs,"class-declaration")==0)
           {
                   fprintf(SymTabDump,"%i \t %s \t %s \t %s\n",var->value->lineOf,var->value->name,var->value->whatIs,var->value->scope);
           }
           if(strcmp(var->value->whatIs,"main-declaration")==0)
           {
                   fprintf(SymTabDump,"%i \t %s \t %s \t %s\n",var->value->lineOf,var->value->name,var->value->whatIs,var->value->scope);
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
        struct SymTabEntry*newEntry=malloc(sizeof(struct SymTabEntry));
        newEntry->name=malloc(strlen(identifier)+1);
        strcpy(newEntry->name,identifier);
        newEntry->name[strlen(newEntry->name)]='\0';
        newEntry->whatIs=malloc(strlen("class-declaration")+1);
        strcpy(newEntry->whatIs,"class-declaration");
        newEntry->whatIs[strlen(newEntry->whatIs)]='\0';
        newEntry->scope=malloc(strlen(head->currentScope)+1);
        strcpy(newEntry->scope,head->currentScope);
        newEntry->scope[strlen(newEntry->scope)]='\0';
        newEntry->lineOf=yylineno;
        struct ListOfEntries*val;
        if((val=g_hash_table_lookup(head->next->localScope,identifier)))
        {  
                while(val)
                {
                        if(strcmp(val->value->whatIs,"class-declaration")==0)
                        {
                                printf("Clasa [%s] a fost redeclarat\nProgramul a fost incheiat fortat!\n",newEntry->name);
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
        struct SymTabEntry*newEntry=malloc(sizeof(struct SymTabEntry));
        newEntry->name=malloc(strlen("main")+1);
        strcpy(newEntry->name,"main");
        newEntry->whatIs=malloc(strlen("main-declaration")+1);
        strcpy(newEntry->whatIs,"main-declaration");
        newEntry->scope=malloc(strlen(head->currentScope)+1);
        strcpy(newEntry->scope,head->currentScope);
        struct ListOfEntries*val;
        newEntry->lineOf=yylineno;
         if((val=g_hash_table_lookup(head->next->localScope,"main")))
        {  
                while(val)
                {
                        if(strcmp(val->value->whatIs,"class-declaration")==0)
                        {
                                printf("Clasa [%s] a fost redeclarat\nProgramul a fost incheiat fortat!\n",newEntry->name);
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
char* is_class_object(char*identifier)
{
                        struct Checker *allScope=head;
                        char*theScope=NULL;
                        int classFound=0;
                        int exists=0;
                                while(allScope && !classFound)
                                {
                                        struct ListOfEntries*searchList;
                                        if(searchList=g_hash_table_lookup(allScope->localScope,identifier))
                                        {
                                                while(searchList && !classFound)
                                                {
                                                        struct Checker*globalScope=head;
                                                        while(globalScope->next!=NULL)
                                                        {
                                                                globalScope=globalScope->next;
                                                        }       
                                                        struct ListOfEntries*insideList;
                                                        if(insideList=g_hash_table_lookup(globalScope->localScope,searchList->value->dataType))
                                                        {
                                                                while(insideList)
                                                                {
                                                                        if(strcmp(insideList->value->whatIs,"object-declaration"))
                                                                        {
                                                                                classFound=1;
                                                                                theScope=malloc(strlen(insideList->value->scope)+1);
                                                                                strcpy(theScope,insideList->value->scope);
                                                                                break;
                                                                        }
                                                                        insideList=insideList->next;
                                                                }
                                                        }
                                                        searchList=searchList->next;
                                                }
                                                exists=1;
                                        }
                                        allScope=allScope->next;
                                }
                                if(!exists)
                                {
                                        printf("Identificatorul [%s] nu este declarat!\n",identifier);
                                        return 0;
                                }
                                if(!classFound)
                                {
                                        printf("Identificatorul [%s] este declarat insa nu desemneaza un obiect!\n",identifier);
                                        return 0;
                                }
                                return theScope;
}
int is_object_variable(char*object,char*variable)
{
        struct Checker *allScope=head;
                        int classFound=0;
                        int exists=0;
                        char*classScope;
                         struct Checker*globalScope=head;
                        while(globalScope->next!=NULL)
                        {
                                globalScope=globalScope->next;
                        }  
                        while(allScope && !classFound)
                        {
                                struct ListOfEntries*searchList;
                                if(searchList=g_hash_table_lookup(allScope->localScope,object))
                                {
                                        while(searchList && !classFound)
                                        {
                                                        
                                                struct ListOfEntries*insideList;
                                                if(insideList=g_hash_table_lookup(globalScope->localScope,searchList->value->dataType))
                                                {
                                                        while(insideList)
                                                        {
                                                                if(strcmp(insideList->value->whatIs,"object-declaration"))
                                                                {
                                                                        classFound=1;
                                                                        classScope=malloc(strlen(insideList->value->scope)+1);
                                                                        strcpy(classScope,insideList->value->scope);
                                                                        break;
                                                                }
                                                                insideList=insideList->next;
                                                        }
                                                }
                                                searchList=searchList->next;
                                        }
                                        exists=1;
                                }
                                allScope=allScope->next;
                        }
                        if(!exists)
                        {
                                printf("Identificatorul [%s] nu este declarat!\n",object);
                                return 0;
                        }
                        if(!classFound)
                        {
                                printf("Identificatorul [%s] este declarat insa nu desemneaza un obiect!\n",object);
                                return 0;
                        }
                        int variableFound=0;
                        struct ListOfEntries*listVar;
                        if(listVar=g_hash_table_lookup(globalScope->localScope,variable))
                        {
                                while(listVar)
                                {
                                        if(strcmp(listVar->value->scope,classScope)==0)
                                        {
                                                variableFound=1;
                                                break;
                                        }
                                        listVar=listVar->next;
                                }
                        }
                        if(!variableFound)
                        {
                                printf("Identificatorul [%s] nu este declarat ca variabila membra a obiectului [%s]\n",variable,object);
                                return 0;
                        }
                        return 1;
                        
}
struct expr_info*create_int_expression(int intValue)
{
        struct expr_info*newExp=malloc(sizeof(struct expr_info));
        newExp->type=malloc(strlen("int")+1);
        strcpy(newExp->type,"int");
        char toString[20];
        sprintf(toString,"%i",intValue);
        newExp->expString=malloc(strlen(toString)+1);
        strcpy(newExp->expString,toString);

        return newExp;
}
struct expr_info*create_bool_expression(const char*boolValue)
{
       struct expr_info*newExp=malloc(sizeof(struct expr_info));
       newExp->type=malloc(strlen("bool")+1);
       strcpy(newExp->type,"bool");
       newExp->expString=malloc(strlen(boolValue)+1);
       strcpy(newExp->expString,boolValue);
       return newExp;  
}
struct expr_info*create_float_expression(float floatValue)
{
        struct expr_info*newExp=malloc(sizeof(struct expr_info));
        newExp->type=malloc(strlen("float")+1);
        strcpy(newExp->type,"float");
        char toString[20];
        sprintf(toString,"%f",floatValue);
        newExp->expString=malloc(strlen(toString)+1);
        strcpy(newExp->expString,toString);
        return newExp;
}
struct expr_info*create_string_expression(char*stringValue)
{
       struct expr_info*newExp=malloc(sizeof(struct expr_info));
       newExp->type=malloc(strlen("char*"));
       strcpy(newExp->type,"char*");
       newExp->expString=malloc(strlen(stringValue)+1);
       strcpy(newExp->expString,stringValue);
       return newExp;  
}
struct expr_info*create_char_expression(const char charValue)
{
        struct expr_info*newExp=malloc(sizeof(struct expr_info));
        newExp->type=malloc(strlen("char")+1);
        strcpy(newExp->type,"char");
        newExp->expString=malloc(2);
        newExp->expString[0]=charValue;
        
        return newExp;
}
struct expr_info*create_variable_expression(const char*identifier,char*type)
{
        struct expr_info*newExp=malloc(sizeof(struct expr_info));
       newExp->type=malloc(strlen(type)+1);
       strcpy(newExp->type,type);
       newExp->expString=malloc(strlen(identifier)+1);
       strcpy(newExp->expString,identifier);
       return newExp;
}
struct expr_info*create_paranthesis_expression(struct expr_info*exp)
{
        struct expr_info*newExp=malloc(sizeof(struct expr_info));
        newExp->type=exp->type;
        newExp->expString=malloc(strlen(exp->expString)+3);
        strcat(newExp->expString,"(");
        strcat(newExp->expString,exp->expString);
        strcat(newExp->expString,")");
        return newExp;
}
struct expr_info*create_expression(char*type,char*eString)
{
        struct expr_info*newExp=malloc(sizeof(struct expr_info));
        newExp->type=malloc(strlen(type)+1);
        strcpy(newExp->type,type);
        newExp->expString=malloc(strlen(eString)+1);
        strcpy(newExp->expString,eString);
        return newExp;
}
struct eval_expr*create_eval_expression(char*name,int value)
{
        struct eval_expr*var=malloc(sizeof(struct eval_expr));
        bzero(var,sizeof(struct eval_expr));
        var->name=malloc(strlen(name)+1);
        strcpy(var->name,name);
        var->intvalue=value;
        return var;
}
