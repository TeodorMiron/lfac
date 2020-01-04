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

struct Checker*head=NULL;
struct ListOfEntries*funcArgs=NULL;
struct ListOfEntries*objVars=NULL;
char*typesOfCall=NULL;
char*inObjectFunc=NULL;
char*classScope=NULL;
char*objName=NULL;
int inArgs=0;
int inClass=0;
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
struct expr_info*create_variable_expression(const char*identifier);
struct expr_info*create_paranthesis_expression(struct expr_info*exp);
struct expr_info*create_expression(char*type,char*eString);
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


#line 213 "y.tab.c"

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
    ID = 292,
    INT_VAL = 293,
    STRING_VAL = 294,
    FLOAT_VAL = 295,
    CHAR_VAL = 296,
    INT = 297,
    STRING = 298,
    FLOAT = 299,
    CHAR = 300,
    BOOL = 301,
    VOID = 302,
    BOOL_TRUE = 303,
    BOOL_FALSE = 304
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
#define ID 292
#define INT_VAL 293
#define STRING_VAL 294
#define FLOAT_VAL 295
#define CHAR_VAL 296
#define INT 297
#define STRING 298
#define FLOAT 299
#define CHAR 300
#define BOOL 301
#define VOID 302
#define BOOL_TRUE 303
#define BOOL_FALSE 304

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 145 "experiment_hash.y"

        int type;
        char*strname;
        int intval;
        char* strval;
        char*boolVal;
        char charval;
        float floatval;
        struct expr_info* expr_ptr;

#line 365 "y.tab.c"

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
#define YYLAST   571

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  57
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  48
/* YYNRULES -- Number of rules.  */
#define YYNRULES  113
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  215

#define YYUNDEFTOK  2
#define YYMAXUTOK   304

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
       2,     2,     2,     2,     2,    52,    56,     2,     2,     2,
       2,     2,     2,     2,    51,     2,    53,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    50,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
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
      45,    46,    47,    48,    49
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   187,   187,   188,   189,   192,   193,   196,   197,   198,
     202,   202,   203,   203,   206,   207,   210,   211,   214,   214,
     215,   215,   216,   216,   217,   217,   220,   221,   224,   225,
     225,   228,   229,   232,   233,   236,   237,   238,   239,   240,
     241,   242,   243,   246,   247,   248,   251,   294,   311,   316,
     320,   320,   320,   321,   321,   321,   324,   324,   325,   325,
     326,   329,   329,   330,   330,   333,   391,   475,   482,   482,
     485,   486,   491,   501,   502,   550,   551,   570,   571,   572,
     573,   574,   575,   578,   613,   614,   615,   616,   617,   618,
     619,   620,   621,   622,   623,   624,   625,   626,   627,   628,
     629,   630,   631,   632,   633,   634,   635,   639,   720,   785,
     833,   833,   834,   834
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
  "STRING_TYPE", "CONST", "RETURN", "AND", "OR", "NOT", "ID", "INT_VAL",
  "STRING_VAL", "FLOAT_VAL", "CHAR_VAL", "INT", "STRING", "FLOAT", "CHAR",
  "BOOL", "VOID", "BOOL_TRUE", "BOOL_FALSE", "';'", "','", "'#'", "'.'",
  "'['", "']'", "'$'", "$accept", "start_program", "declaration_section",
  "declaration_content", "object_declaration", "$@1", "$@2",
  "object_content", "inside_object", "function_declaration", "$@3", "$@4",
  "$@5", "$@6", "return_statement", "list_param", "$@7",
  "function_content", "multiple_statements", "statements",
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
      59,    44,    35,    46,    91,    93,    36
};
# endif

#define YYPACT_NINF -101

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-101)))

#define YYTABLE_NINF -113

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -13,    -6,    -5,    -1,    60,   -13,  -101,  -101,  -101,  -101,
      -9,     3,    17,    56,   207,  -101,  -101,  -101,  -101,  -101,
      69,   291,    77,    17,   228,  -101,    80,   249,   249,   518,
    -101,  -101,  -101,  -101,  -101,  -101,   102,   249,  -101,  -101,
     312,  -101,  -101,  -101,   100,  -101,  -101,  -101,  -101,  -101,
    -101,   105,   291,  -101,   249,    40,   107,    86,   356,    41,
    -101,    98,  -101,   249,    49,   104,   249,   249,   249,   249,
     249,   249,   249,   249,   249,   249,   249,   114,   121,   122,
     134,   140,    -1,   -12,  -101,  -101,  -101,  -101,  -101,    55,
     466,   128,   291,   473,   517,   196,   524,   494,   501,   156,
      41,    92,   131,  -101,    75,   144,    75,   149,   150,   137,
     151,  -101,  -101,  -101,   157,   249,   291,   155,   249,    61,
      12,  -101,  -101,  -101,  -101,  -101,     1,  -101,  -101,    75,
     172,  -101,   152,   466,  -101,  -101,   158,   290,   185,   186,
     188,  -101,   -19,  -101,  -101,   334,   -18,  -101,  -101,   249,
     187,  -101,     1,  -101,   176,   249,    82,    11,   249,   249,
     249,   466,  -101,   191,  -101,   204,   174,   249,   205,   208,
     163,   378,   163,  -101,   249,   198,   141,   213,   214,   400,
    -101,   422,   444,  -101,   203,    75,   218,    75,   219,  -101,
    -101,   241,  -101,    35,  -101,    36,  -101,   227,  -101,   224,
    -101,  -101,   224,   229,  -101,    75,  -101,   234,    66,    75,
     235,  -101,    84,  -101,  -101
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       4,    29,     0,     0,     0,     0,     6,     8,     7,     3,
       0,     0,     0,     0,     0,     9,    70,     1,     5,     2,
       0,     0,     0,     0,     0,    30,    10,     0,     0,    83,
      84,    88,    85,    89,    86,    87,     0,     0,    90,    71,
       0,    91,    92,    93,     0,    77,    81,    79,    78,    80,
      82,     0,     0,    28,     0,     0,     0,    83,     0,   106,
      74,     0,    73,    49,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   110,    22,     0,
       0,    29,     0,     0,    15,    16,    13,    94,   108,     0,
      48,     0,     0,    95,    97,    99,   100,    98,    96,   101,
     102,   103,   104,   105,     0,     0,     0,     0,    18,     0,
       0,    17,    11,    14,     0,     0,   109,    75,     0,     0,
       0,    34,    35,    36,    37,   113,    27,    32,    25,     0,
       0,   109,    46,    47,    72,    76,     0,     0,     0,     0,
       0,    42,    90,    38,    39,     0,    91,   111,    33,     0,
       0,    31,    27,    21,     0,     0,     0,     0,     0,     0,
       0,    26,    23,     0,   107,     0,    65,     0,     0,     0,
       0,     0,     0,    19,     0,     0,     0,    50,    61,     0,
      44,     0,     0,    66,     0,     0,     0,     0,     0,    43,
      45,     0,    67,     0,    54,     0,    64,     0,    51,    60,
      62,    68,    60,     0,    55,     0,    52,    56,     0,     0,
       0,    69,     0,    59,    57
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -101,  -101,  -101,   255,  -101,  -101,  -101,  -101,   179,    -2,
    -101,  -101,  -101,  -101,   111,  -101,  -101,   142,   -67,  -100,
    -101,   153,  -101,  -101,  -101,  -101,  -101,  -101,    71,  -101,
    -101,  -101,  -101,  -101,   159,  -101,  -101,   -69,  -101,     0,
     -22,   -27,   160,  -101,  -101,   269,  -101,  -101
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     4,     5,     6,     7,    55,    56,    83,    84,     8,
     129,   130,   106,   107,   150,    11,    12,   126,   120,   121,
     141,    38,    89,   122,   185,   202,   186,   199,   204,   209,
     210,   123,   187,   188,   136,   124,   205,    15,    39,    16,
      51,    40,    41,    42,    43,     9,   104,   105
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      58,    59,   -40,   -41,   -40,   -41,   127,    62,     1,    81,
      64,   112,    25,   111,   -40,   -41,    10,   168,    20,   169,
     148,    13,   118,    53,     2,    22,   151,    80,    21,   127,
      79,   -40,   -41,   118,   149,   147,    90,     3,    82,    93,
      94,    95,    96,    97,    98,    99,   100,   101,   102,   103,
     144,   119,   151,    85,    23,    14,   118,   118,   198,   200,
      17,    81,   119,    66,    67,    68,    69,    70,    71,    72,
     117,   138,   139,    24,   140,    75,    76,   114,    73,    74,
      26,    85,    27,    75,    76,   119,   119,   118,   133,   211,
      82,   137,   145,   148,   134,   148,   118,    28,    57,    30,
      31,    32,    33,   -12,    91,   118,   115,   214,   148,    34,
      35,    44,   148,    36,    52,    54,   119,    14,   193,   166,
     195,    73,   161,    63,    77,   119,    75,    76,   165,    78,
      86,   170,   171,   172,   119,    88,   167,  -112,   208,    61,
     176,    92,   212,   179,   -24,   181,   108,   182,    66,    67,
      68,    69,    70,    71,    72,    66,    67,    68,    69,    70,
      71,    72,   110,    73,    74,   116,    76,   125,    75,    76,
      73,    74,   128,   -20,   131,    75,    76,    66,    67,    68,
      69,    70,    71,    72,    27,    73,    74,   135,    21,   109,
      75,    76,    73,    74,   132,   153,   184,    75,    76,    28,
      57,    30,    31,    32,    33,   154,   158,   159,   155,   160,
     162,    34,    35,   164,   173,    36,    72,    54,    66,    67,
      68,    69,    70,    71,    72,    73,    74,   175,    27,   177,
      75,    76,   178,    73,    74,   183,   -53,   -63,    75,    76,
     192,   194,   196,    28,    29,    30,    31,    32,    33,    27,
     197,   201,   203,   207,   174,    34,    35,   -58,   213,    36,
      18,    37,   113,   163,    28,    29,    30,    31,    32,    33,
      27,   152,   142,   206,    19,     0,    34,    35,   143,   146,
      36,     0,    54,     0,     0,    28,    57,    30,    31,    32,
      33,     0,     0,     0,     0,   156,     0,    34,    35,     0,
       0,    36,     0,    54,    66,    67,    68,    69,    70,    71,
      72,     0,   157,     0,     0,     0,     0,    65,     0,    73,
      74,     0,     0,     0,    75,    76,    66,    67,    68,    69,
      70,    71,    72,    45,    46,    47,    48,    49,    50,   156,
       0,    73,    74,     0,     0,     0,    75,    76,    66,    67,
      68,    69,    70,    71,    72,     0,     0,     0,     0,     0,
       0,     0,     0,    73,    74,     0,     0,     0,    75,    76,
      66,    67,    68,    69,    70,    71,    72,     0,    87,     0,
       0,     0,     0,     0,     0,    73,    74,     0,     0,     0,
      75,    76,    66,    67,    68,    69,    70,    71,    72,     0,
     180,     0,     0,     0,     0,     0,     0,    73,    74,     0,
       0,     0,    75,    76,    66,    67,    68,    69,    70,    71,
      72,     0,   189,     0,     0,     0,     0,     0,     0,    73,
      74,     0,     0,     0,    75,    76,    66,    67,    68,    69,
      70,    71,    72,     0,   190,     0,     0,     0,     0,     0,
       0,    73,    74,     0,     0,     0,    75,    76,    66,    67,
      68,    69,    70,    71,    72,     0,   191,     0,     0,     0,
       0,     0,     0,    73,    74,     0,     0,     0,    75,    76,
      66,    67,    68,    69,    70,    71,    72,     0,    67,    68,
      69,    70,    71,    72,     0,    73,    74,     0,     0,     0,
      75,    76,    73,    74,     0,     0,     0,    75,    76,    67,
      68,    69,     0,    71,    72,     0,    67,    68,    69,     0,
       0,    72,     0,    73,    74,     0,     0,     0,    75,    76,
      73,    74,     0,    68,    69,    75,    76,    72,     0,     0,
      68,     0,     0,     0,    72,     0,    73,    74,     0,     0,
       0,    75,    76,    73,    74,    60,     0,     0,    75,    76,
      45,    46,    47,    48,    49,    50,     0,     0,     0,     0,
       0,    61
};

static const yytype_int16 yycheck[] =
{
      27,    28,    21,    21,    23,    23,   106,    29,    21,    21,
      37,    23,    12,    82,    33,    33,    22,     6,    27,     8,
     120,    26,    21,    23,    37,    22,   126,    54,    37,   129,
      52,    50,    50,    21,    33,    23,    63,    50,    50,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    75,    76,
     119,    50,   152,    55,    51,    56,    21,    21,    23,    23,
       0,    21,    50,    14,    15,    16,    17,    18,    19,    20,
      92,    10,    11,    56,    13,    34,    35,    22,    29,    30,
      24,    83,    21,    34,    35,    50,    50,    21,   115,    23,
      50,   118,   119,   193,   116,   195,    21,    36,    37,    38,
      39,    40,    41,    23,    55,    21,    51,    23,   208,    48,
      49,    42,   212,    52,    37,    54,    50,    56,   185,    37,
     187,    29,   149,    21,    24,    50,    34,    35,   155,    24,
      23,   158,   159,   160,    50,    37,    54,    23,   205,    53,
     167,    37,   209,   170,    23,   172,    24,   174,    14,    15,
      16,    17,    18,    19,    20,    14,    15,    16,    17,    18,
      19,    20,    22,    29,    30,    37,    35,    23,    34,    35,
      29,    30,    23,    23,    37,    34,    35,    14,    15,    16,
      17,    18,    19,    20,    21,    29,    30,    32,    37,    55,
      34,    35,    29,    30,    37,    23,    55,    34,    35,    36,
      37,    38,    39,    40,    41,    53,    21,    21,    50,    21,
      23,    48,    49,    37,    23,    52,    20,    54,    14,    15,
      16,    17,    18,    19,    20,    29,    30,    53,    21,    24,
      34,    35,    24,    29,    30,    37,    23,    23,    34,    35,
      37,    23,    23,    36,    37,    38,    39,    40,    41,    21,
       9,    24,    28,    24,    50,    48,    49,    23,    23,    52,
       5,    54,    83,   152,    36,    37,    38,    39,    40,    41,
      21,   129,   119,   202,     5,    -1,    48,    49,   119,   119,
      52,    -1,    54,    -1,    -1,    36,    37,    38,    39,    40,
      41,    -1,    -1,    -1,    -1,     5,    -1,    48,    49,    -1,
      -1,    52,    -1,    54,    14,    15,    16,    17,    18,    19,
      20,    -1,    22,    -1,    -1,    -1,    -1,     5,    -1,    29,
      30,    -1,    -1,    -1,    34,    35,    14,    15,    16,    17,
      18,    19,    20,    42,    43,    44,    45,    46,    47,     5,
      -1,    29,    30,    -1,    -1,    -1,    34,    35,    14,    15,
      16,    17,    18,    19,    20,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    29,    30,    -1,    -1,    -1,    34,    35,
      14,    15,    16,    17,    18,    19,    20,    -1,    22,    -1,
      -1,    -1,    -1,    -1,    -1,    29,    30,    -1,    -1,    -1,
      34,    35,    14,    15,    16,    17,    18,    19,    20,    -1,
      22,    -1,    -1,    -1,    -1,    -1,    -1,    29,    30,    -1,
      -1,    -1,    34,    35,    14,    15,    16,    17,    18,    19,
      20,    -1,    22,    -1,    -1,    -1,    -1,    -1,    -1,    29,
      30,    -1,    -1,    -1,    34,    35,    14,    15,    16,    17,
      18,    19,    20,    -1,    22,    -1,    -1,    -1,    -1,    -1,
      -1,    29,    30,    -1,    -1,    -1,    34,    35,    14,    15,
      16,    17,    18,    19,    20,    -1,    22,    -1,    -1,    -1,
      -1,    -1,    -1,    29,    30,    -1,    -1,    -1,    34,    35,
      14,    15,    16,    17,    18,    19,    20,    -1,    15,    16,
      17,    18,    19,    20,    -1,    29,    30,    -1,    -1,    -1,
      34,    35,    29,    30,    -1,    -1,    -1,    34,    35,    15,
      16,    17,    -1,    19,    20,    -1,    15,    16,    17,    -1,
      -1,    20,    -1,    29,    30,    -1,    -1,    -1,    34,    35,
      29,    30,    -1,    16,    17,    34,    35,    20,    -1,    -1,
      16,    -1,    -1,    -1,    20,    -1,    29,    30,    -1,    -1,
      -1,    34,    35,    29,    30,    37,    -1,    -1,    34,    35,
      42,    43,    44,    45,    46,    47,    -1,    -1,    -1,    -1,
      -1,    53
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    21,    37,    50,    58,    59,    60,    61,    66,   102,
      22,    72,    73,    26,    56,    94,    96,     0,    60,   102,
      27,    37,    22,    51,    56,    96,    24,    21,    36,    37,
      38,    39,    40,    41,    48,    49,    52,    54,    78,    95,
      98,    99,   100,   101,    42,    42,    43,    44,    45,    46,
      47,    97,    37,    96,    54,    62,    63,    37,    98,    98,
      37,    53,    97,    21,    98,     5,    14,    15,    16,    17,
      18,    19,    20,    29,    30,    34,    35,    24,    24,    97,
      98,    21,    50,    64,    65,    66,    23,    22,    37,    79,
      98,    55,    37,    98,    98,    98,    98,    98,    98,    98,
      98,    98,    98,    98,   103,   104,    69,    70,    24,    55,
      22,    94,    23,    65,    22,    51,    37,    97,    21,    50,
      75,    76,    80,    88,    92,    23,    74,    76,    23,    67,
      68,    37,    37,    98,    97,    32,    91,    98,    10,    11,
      13,    77,    78,    91,    94,    98,    99,    23,    76,    33,
      71,    76,    74,    23,    53,    50,     5,    22,    21,    21,
      21,    98,    23,    71,    37,    98,    37,    54,     6,     8,
      98,    98,    98,    23,    50,    53,    98,    24,    24,    98,
      22,    98,    98,    37,    55,    81,    83,    89,    90,    22,
      22,    22,    37,    75,    23,    75,    23,     9,    23,    84,
      23,    24,    82,    28,    85,    93,    85,    24,    75,    86,
      87,    23,    75,    23,    23
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    57,    58,    58,    58,    59,    59,    60,    60,    60,
      62,    61,    63,    61,    64,    64,    65,    65,    67,    66,
      68,    66,    69,    66,    70,    66,    71,    71,    72,    73,
      72,    74,    74,    75,    75,    76,    76,    76,    76,    76,
      76,    76,    76,    77,    77,    77,    78,    79,    79,    79,
      81,    82,    80,    83,    84,    80,    86,    85,    87,    85,
      85,    89,    88,    90,    88,    91,    91,    91,    93,    92,
      94,    94,    95,    96,    96,    96,    96,    97,    97,    97,
      97,    97,    97,    98,    98,    98,    98,    98,    98,    98,
      98,    98,    98,    98,    98,    98,    98,    98,    98,    98,
      98,    98,    98,    98,    98,    98,    98,    99,   100,   101,
     103,   102,   104,   102
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     1,     0,     2,     1,     1,     1,     2,
       0,     6,     0,     5,     2,     1,     1,     2,     0,    10,
       0,     8,     0,     9,     0,     7,     2,     0,     3,     0,
       2,     2,     1,     2,     1,     1,     1,     1,     2,     2,
       2,     2,     2,     5,     4,     5,     5,     3,     1,     0,
       0,     0,    10,     0,     0,     9,     0,     5,     0,     4,
       0,     0,     8,     0,     7,     3,     5,     6,     0,    12,
       1,     2,     5,     3,     3,     5,     6,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     2,     7,     3,     4,
       0,     8,     0,     7
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
#line 187 "experiment_hash.y"
    {printf("Programul este corect\n");}
#line 1692 "y.tab.c"
    break;

  case 3:
#line 188 "experiment_hash.y"
    {printf("Programul este corect\n");}
#line 1698 "y.tab.c"
    break;

  case 4:
#line 189 "experiment_hash.y"
    {printf("Programul este corect!\n");}
#line 1704 "y.tab.c"
    break;

  case 10:
#line 202 "experiment_hash.y"
    {add_class_node((yyvsp[-2].strname));inClass=1;}
#line 1710 "y.tab.c"
    break;

  case 11:
#line 202 "experiment_hash.y"
    {remove_node();inClass=0;}
#line 1716 "y.tab.c"
    break;

  case 12:
#line 203 "experiment_hash.y"
    {add_class_node((yyvsp[-2].strname));inClass=1;}
#line 1722 "y.tab.c"
    break;

  case 13:
#line 203 "experiment_hash.y"
    {remove_node();inClass=0;}
#line 1728 "y.tab.c"
    break;

  case 18:
#line 214 "experiment_hash.y"
    {inArgs=0;add_func_node((yyvsp[-2].strname),return_type((yyvsp[-1].type)));}
#line 1734 "y.tab.c"
    break;

  case 19:
#line 214 "experiment_hash.y"
    {remove_node();}
#line 1740 "y.tab.c"
    break;

  case 20:
#line 215 "experiment_hash.y"
    {inArgs=0;add_func_node((yyvsp[-2].strname),return_type((yyvsp[-1].type)));}
#line 1746 "y.tab.c"
    break;

  case 21:
#line 215 "experiment_hash.y"
    {remove_node();}
#line 1752 "y.tab.c"
    break;

  case 22:
#line 216 "experiment_hash.y"
    {inArgs=0;add_func_node((yyvsp[-2].strname),return_type((yyvsp[-1].type)));}
#line 1758 "y.tab.c"
    break;

  case 23:
#line 216 "experiment_hash.y"
    {remove_node();}
#line 1764 "y.tab.c"
    break;

  case 24:
#line 217 "experiment_hash.y"
    {inArgs=0;add_func_node((yyvsp[-2].strname),return_type((yyvsp[-1].type)));}
#line 1770 "y.tab.c"
    break;

  case 25:
#line 217 "experiment_hash.y"
    {remove_node();}
#line 1776 "y.tab.c"
    break;

  case 29:
#line 225 "experiment_hash.y"
    {inArgs=1;}
#line 1782 "y.tab.c"
    break;

  case 46:
#line 252 "experiment_hash.y"
    {
                      struct Checker*iterator=head;
                      int funcFound=0;
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
                                                break;
                                        }
                                      }
                                      else
                                      {
                                        if((strcmp(iteratorList->value->whatIs,"function-declaration")==0 || (strcmp(iteratorList->value->whatIs,"class-function-declaration")==0)) && (strcmp(iteratorList->value->name,(yyvsp[0].strname))==0) && (strcmp(iteratorList->value->paramlist,typesOfCall)==0))
                                        {
                                                funcFound=1;
                                                break;
                                        }
                                      }
                                        
                                      iteratorList=iteratorList->next;
                                      
                              }

                              iterator=iterator->next;
                      }
                        
                        free(typesOfCall);
                        typesOfCall=NULL;
                        if(!funcFound)
                        {
                                printf("Functia [%s] pe care ati apelat-o nu este definita!\n",(yyvsp[0].strname));
                                exit(EXIT_FAILURE);
                        }
                }
#line 1828 "y.tab.c"
    break;

  case 47:
#line 295 "experiment_hash.y"
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
#line 1849 "y.tab.c"
    break;

  case 48:
#line 312 "experiment_hash.y"
    {
               typesOfCall=malloc(strlen((yyvsp[0].expr_ptr)->type)+1);
               strcpy(typesOfCall,(yyvsp[0].expr_ptr)->type);
         }
#line 1858 "y.tab.c"
    break;

  case 49:
#line 316 "experiment_hash.y"
    {typesOfCall=malloc(0);}
#line 1864 "y.tab.c"
    break;

  case 50:
#line 320 "experiment_hash.y"
    {add_statement_node();}
#line 1870 "y.tab.c"
    break;

  case 51:
#line 320 "experiment_hash.y"
    {remove_node();}
#line 1876 "y.tab.c"
    break;

  case 53:
#line 321 "experiment_hash.y"
    {add_statement_node();}
#line 1882 "y.tab.c"
    break;

  case 54:
#line 321 "experiment_hash.y"
    {remove_node();}
#line 1888 "y.tab.c"
    break;

  case 56:
#line 324 "experiment_hash.y"
    {add_statement_node();}
#line 1894 "y.tab.c"
    break;

  case 57:
#line 324 "experiment_hash.y"
    {remove_node();}
#line 1900 "y.tab.c"
    break;

  case 58:
#line 325 "experiment_hash.y"
    {add_statement_node();}
#line 1906 "y.tab.c"
    break;

  case 59:
#line 325 "experiment_hash.y"
    {remove_node();}
#line 1912 "y.tab.c"
    break;

  case 61:
#line 329 "experiment_hash.y"
    {add_statement_node();}
#line 1918 "y.tab.c"
    break;

  case 62:
#line 329 "experiment_hash.y"
    {remove_node();}
#line 1924 "y.tab.c"
    break;

  case 63:
#line 330 "experiment_hash.y"
    {add_statement_node();}
#line 1930 "y.tab.c"
    break;

  case 64:
#line 330 "experiment_hash.y"
    {remove_node();}
#line 1936 "y.tab.c"
    break;

  case 65:
#line 334 "experiment_hash.y"
    {
                        int varFound=0;
                        struct Checker*iterator=head;
                        struct ListOfEntries*assgVar;
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
                                                        saveList->value->initialised=1;
                                                        
                                                }
                                        }
                                        else
                                        {
                                                 if((strcmp(searchList->value->name,(yyvsp[0].strname))==0) && (strcmp(searchList->value->scope,iterator->currentScope)==0) && ((strcmp(searchList->value->whatIs,"variable")==0) || (strcmp(searchList->value->whatIs,"class-variable")==0)))
                                                {
                                                        varFound=1;
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
                                printf("Variabila [%s] nu este declarata!\n",(yyvsp[0].strname));
                                exit(EXIT_FAILURE);
                        }
                        
                }
#line 1998 "y.tab.c"
    break;

  case 66:
#line 392 "experiment_hash.y"
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
                                                       instanceFound=1;
                                                       saveList->value->initialised=1;
                                               }
                                       }
                                       else
                                        {
                                              if(((strcmp(searchList->value->whatIs,"variable")==0) || (strcmp(searchList->value->whatIs,"class-variable")==0))&& (strcmp(searchList->value->scope,iterator->currentScope)==0) && (strcmp(searchList->value->name,searchInstance)==0))
                                               {
                                                       instanceFound=1;
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
                        searchInstance=NULL;

                }
#line 2085 "y.tab.c"
    break;

  case 67:
#line 476 "experiment_hash.y"
    {
                        
                }
#line 2093 "y.tab.c"
    break;

  case 68:
#line 482 "experiment_hash.y"
    {add_statement_node();}
#line 2099 "y.tab.c"
    break;

  case 69:
#line 482 "experiment_hash.y"
    {remove_node();}
#line 2105 "y.tab.c"
    break;

  case 72:
#line 491 "experiment_hash.y"
    {
                                 
                                 char*customType=malloc(strlen(return_type((yyvsp[0].type)))+strlen("50"));
                                 strcpy(customType,return_type((yyvsp[0].type)));
                                 strcat(customType,"[");
                                 strcat(customType,"50");
                                 strcat(customType,"]");
                                 add_new_variable(customType,(yyvsp[-1].strname),1 );
                        }
#line 2119 "y.tab.c"
    break;

  case 73:
#line 501 "experiment_hash.y"
    {add_new_variable(return_type((yyvsp[0].type)),(yyvsp[-1].strname),0);}
#line 2125 "y.tab.c"
    break;

  case 74:
#line 502 "experiment_hash.y"
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
#line 2178 "y.tab.c"
    break;

  case 75:
#line 550 "experiment_hash.y"
    {add_new_variable(return_type((yyvsp[0].type)),(yyvsp[-1].strname),1);}
#line 2184 "y.tab.c"
    break;

  case 76:
#line 551 "experiment_hash.y"
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
#line 2201 "y.tab.c"
    break;

  case 77:
#line 570 "experiment_hash.y"
    {(yyval.type)=(yyvsp[0].type);}
#line 2207 "y.tab.c"
    break;

  case 78:
#line 571 "experiment_hash.y"
    {(yyval.type)=(yyvsp[0].type);}
#line 2213 "y.tab.c"
    break;

  case 79:
#line 572 "experiment_hash.y"
    {(yyval.type)=(yyvsp[0].type);}
#line 2219 "y.tab.c"
    break;

  case 80:
#line 573 "experiment_hash.y"
    {(yyval.type)=(yyvsp[0].type);}
#line 2225 "y.tab.c"
    break;

  case 81:
#line 574 "experiment_hash.y"
    {(yyval.type)=(yyvsp[0].type);}
#line 2231 "y.tab.c"
    break;

  case 82:
#line 575 "experiment_hash.y"
    {(yyval.type)=(yyvsp[0].type);}
#line 2237 "y.tab.c"
    break;

  case 83:
#line 578 "experiment_hash.y"
    {
            (yyval.expr_ptr)=create_variable_expression((yyvsp[0].strname)); 
            int initialised=0;
            int exists=0;
            int line;
                struct Checker*iterator=head;
                while(iterator)
                {
                        struct ListOfEntries*searchList=g_hash_table_lookup(iterator->localScope,(yyvsp[0].strname));
                        while(searchList)
                        {
                                if(strcmp(searchList->value->name,(yyvsp[0].strname))==0 && strcmp(searchList->value->whatIs,"variable")==0 && strcmp(searchList->value->scope,iterator->currentScope)==0)
                                {
                                        exists=1;
                                        if(searchList->value->initialised)
                                           initialised=1;
                                        if(exists || initialised)
                                         break;
                                }
                                searchList=searchList->next;
                        }
                        iterator=iterator->next;
                }
            
            if(!exists)
            {
                printf("Variabila [%s] din expresia [%s] nu este definita!\n",(yyvsp[0].strname),(yyval.expr_ptr)->expString);
                exit(EXIT_FAILURE);
            }   
            if(!initialised)
            {
                    printf("Variabila [%s] este definita insa nu si initializata in expresia[%s]!\n",(yyvsp[0].strname),(yyval.expr_ptr)->expString);
                    exit(EXIT_FAILURE);
            }
        }
#line 2277 "y.tab.c"
    break;

  case 84:
#line 613 "experiment_hash.y"
    {(yyval.expr_ptr)=create_int_expression((yyvsp[0].intval));}
#line 2283 "y.tab.c"
    break;

  case 85:
#line 614 "experiment_hash.y"
    {(yyval.expr_ptr)=create_float_expression((yyvsp[0].floatval));}
#line 2289 "y.tab.c"
    break;

  case 86:
#line 615 "experiment_hash.y"
    {(yyval.expr_ptr)=create_bool_expression((yyvsp[0].boolVal));}
#line 2295 "y.tab.c"
    break;

  case 87:
#line 616 "experiment_hash.y"
    {(yyval.expr_ptr)=create_bool_expression((yyvsp[0].boolVal));}
#line 2301 "y.tab.c"
    break;

  case 88:
#line 617 "experiment_hash.y"
    {(yyval.expr_ptr)=create_string_expression((yyvsp[0].strval));}
#line 2307 "y.tab.c"
    break;

  case 89:
#line 618 "experiment_hash.y"
    {(yyval.expr_ptr)=create_char_expression((yyvsp[0].charval));}
#line 2313 "y.tab.c"
    break;

  case 90:
#line 619 "experiment_hash.y"
    {(yyval.expr_ptr)=(yyvsp[0].expr_ptr);}
#line 2319 "y.tab.c"
    break;

  case 94:
#line 623 "experiment_hash.y"
    {(yyval.expr_ptr)=create_paranthesis_expression((yyvsp[-1].expr_ptr));}
#line 2325 "y.tab.c"
    break;

  case 107:
#line 640 "experiment_hash.y"
    {
                                struct Checker*iterator=head;
                                int objFound=0;
                                int funcFound=0;
                                char*objClass=NULL;
                                char*scopeOf=NULL;
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
                                                        break;
                                                }
                                                else
                                                {
                                                        printf("Nume:%s \t Param:%s \t Scope:%s \n",searchList->value->name,searchList->value->paramlist,searchList->value->scope);
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
#line 2407 "y.tab.c"
    break;

  case 108:
#line 721 "experiment_hash.y"
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
                                                       break;
                                               }
                                       }
                                       else
                                        {
                                              if(((strcmp(searchList->value->whatIs,"variable")==0) || (strcmp(searchList->value->whatIs,"class-variable")==0))&& (strcmp(searchList->value->scope,iterator->currentScope)==0) && (strcmp(searchList->value->name,searchInstance)==0))
                                               {
                                                       instanceFound=1;
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
#line 2475 "y.tab.c"
    break;

  case 109:
#line 785 "experiment_hash.y"
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
#line 2526 "y.tab.c"
    break;

  case 110:
#line 833 "experiment_hash.y"
    {add_main_node();}
#line 2532 "y.tab.c"
    break;

  case 111:
#line 833 "experiment_hash.y"
    {remove_node();}
#line 2538 "y.tab.c"
    break;

  case 112:
#line 834 "experiment_hash.y"
    {add_main_node();}
#line 2544 "y.tab.c"
    break;

  case 113:
#line 834 "experiment_hash.y"
    {remove_node();}
#line 2550 "y.tab.c"
    break;


#line 2554 "y.tab.c"

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
#line 836 "experiment_hash.y"

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
        newExp->type=malloc(strlen("int"))+1;
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
       newExp->type=malloc(strlen("bool"));
       strcpy(newExp->type,"bool");
       newExp->expString=malloc(strlen(boolValue)+1);
       strcpy(newExp->expString,boolValue);
       return newExp;  
}
struct expr_info*create_float_expression(float floatValue)
{
        struct expr_info*newExp=malloc(sizeof(struct expr_info));
        newExp->type=malloc(strlen("float"))+1;
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
        newExp->type=malloc(strlen("char"))+1;
        strcpy(newExp->type,"char");
        newExp->expString=malloc(2);
        newExp->expString[0]=charValue;
        
        return newExp;
}
struct expr_info*create_variable_expression(const char*identifier)
{
        struct expr_info*newExp=malloc(sizeof(struct expr_info));
       newExp->type=malloc(strlen("variable"));
       strcpy(newExp->type,"variable");
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
