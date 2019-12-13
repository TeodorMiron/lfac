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
    ELSE = 266,
    ELSEIF = 267,
    WHILE = 268,
    FOR = 269,
    STRCPY = 270,
    STRLEN = 271,
    STRCMP = 272,
    ID = 273,
    NR = 274,
    ADD = 275,
    DIV = 276,
    BIGGER = 277,
    SMALLER = 278,
    MIN = 279,
    MUL = 280,
    EQUAL = 281,
    OPEN_ROUND_BRACKET = 282,
    CLOSE_ROUND_BRACKET = 283,
    CLOSE_CURLY_BRACKET = 284,
    OPEN_CURLY_BRACKET = 285
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
#define ELSE 266
#define ELSEIF 267
#define WHILE 268
#define FOR 269
#define STRCPY 270
#define STRLEN 271
#define STRCMP 272
#define ID 273
#define NR 274
#define ADD 275
#define DIV 276
#define BIGGER 277
#define SMALLER 278
#define MIN 279
#define MUL 280
#define EQUAL 281
#define OPEN_ROUND_BRACKET 282
#define CLOSE_ROUND_BRACKET 283
#define CLOSE_CURLY_BRACKET 284
#define OPEN_CURLY_BRACKET 285

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
