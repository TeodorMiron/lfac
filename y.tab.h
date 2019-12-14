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
    START = 258,
    END = 259,
    INT = 260,
    CHAR = 261,
    FLOAT = 262,
    ASSIGN = 263,
    BOOL = 264,
    IF = 265,
    ELSEIF = 266,
    WHILE = 267,
    FOR = 268,
    STRCPY = 269,
    STRLEN = 270,
    STRCMP = 271,
    ID = 272,
    NR = 273,
    ADD = 274,
    DIV = 275,
    BIGGER = 276,
    SMALLER = 277,
    MIN = 278,
    MUL = 279,
    EQUAL = 280,
    OPEN_ROUND_BRACKET = 281,
    CLOSE_ROUND_BRACKET = 282,
    CLOSE_CURLY_BRACKET = 283,
    OPEN_CURLY_BRACKET = 284,
    INCR = 285,
    CLASS = 286,
    MAIN = 287,
    ELSE = 288,
    STRING = 289,
    CONST = 290
  };
#endif
/* Tokens.  */
#define START 258
#define END 259
#define INT 260
#define CHAR 261
#define FLOAT 262
#define ASSIGN 263
#define BOOL 264
#define IF 265
#define ELSEIF 266
#define WHILE 267
#define FOR 268
#define STRCPY 269
#define STRLEN 270
#define STRCMP 271
#define ID 272
#define NR 273
#define ADD 274
#define DIV 275
#define BIGGER 276
#define SMALLER 277
#define MIN 278
#define MUL 279
#define EQUAL 280
#define OPEN_ROUND_BRACKET 281
#define CLOSE_ROUND_BRACKET 282
#define CLOSE_CURLY_BRACKET 283
#define OPEN_CURLY_BRACKET 284
#define INCR 285
#define CLASS 286
#define MAIN 287
#define ELSE 288
#define STRING 289
#define CONST 290

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 18 "iac.y"

int intval;
char* strval;
_Bool boolval;
char charval;
float floatval;
struct expr_info* expr_ptr;
struct expr_info** list_expr_ptr;

#line 137 "y.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
