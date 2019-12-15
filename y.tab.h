/* A Bison parser, made by GNU Bison 3.4.1.  */

/* Bison interface for Yacc-like parsers in C

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

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

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
    ADD = 258,
    MUL = 259,
    MIN = 260,
    DIV = 261,
    SMALLER = 262,
    BIGGER = 263,
    INCR = 264,
    EQUAL = 265,
    ELSE = 266,
    OR = 267,
    AND = 268,
    NOT = 269,
    STRCAT = 270,
    STRCPY = 271,
    STRLEN = 272,
    CLASS = 273,
    CLOSE_CURLY_BRACKET = 274,
    OPEN_CURLY_BRACKET = 275,
    CLOSE_ROUND_BRACKET = 276,
    OPEN_ROUND_BRACKET = 277,
    CONST = 278,
    MAIN = 279,
    END = 280,
    ELSEIF = 281,
    INT = 282,
    CHAR = 283,
    FLOAT = 284,
    BOOL = 285,
    STRING = 286,
    NR = 287,
    IF = 288,
    WHILE = 289,
    FOR = 290,
    ASSIGN = 291,
    ID = 292,
    INT_NUMBER = 293,
    STRING_VAL = 294,
    SMALLER_EQUAL = 295,
    GREATER_EQUAL = 296,
    BOOL_FALSE = 297,
    BOOL_TRUE = 298,
    STRCMP = 299,
    FLOAT_NR = 300,
    CHAR_VAL = 301
  };
#endif
/* Tokens.  */
#define ADD 258
#define MUL 259
#define MIN 260
#define DIV 261
#define SMALLER 262
#define BIGGER 263
#define INCR 264
#define EQUAL 265
#define ELSE 266
#define OR 267
#define AND 268
#define NOT 269
#define STRCAT 270
#define STRCPY 271
#define STRLEN 272
#define CLASS 273
#define CLOSE_CURLY_BRACKET 274
#define OPEN_CURLY_BRACKET 275
#define CLOSE_ROUND_BRACKET 276
#define OPEN_ROUND_BRACKET 277
#define CONST 278
#define MAIN 279
#define END 280
#define ELSEIF 281
#define INT 282
#define CHAR 283
#define FLOAT 284
#define BOOL 285
#define STRING 286
#define NR 287
#define IF 288
#define WHILE 289
#define FOR 290
#define ASSIGN 291
#define ID 292
#define INT_NUMBER 293
#define STRING_VAL 294
#define SMALLER_EQUAL 295
#define GREATER_EQUAL 296
#define BOOL_FALSE 297
#define BOOL_TRUE 298
#define STRCMP 299
#define FLOAT_NR 300
#define CHAR_VAL 301

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 31 "iac.y"

        int intval;
        char* strval;
        _Bool boolval;
        char charval;
        float floatval;
        struct expr_info* expr_ptr;
        struct expr_info** list_expr_ptr;

#line 159 "y.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
