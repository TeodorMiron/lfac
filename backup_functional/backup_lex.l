%{
#include <stdio.h>
#include <string.h>
#include "y.tab.h"
%}
%option noyywrap
%%
"/*"(.|\n)"*/" ;
":-)" {return START;}
":-(" {return END;}
"tni" {return INT;}
\"[^\"\n]*\" {yylval.strval=strdup(yytext); return STRING;}
"ssalc" {return CLASS;}
"rahc" {return CHAR;}
"toafl" {return FLOAT;}
"loob" {return BOOL;}
"fi" {return IF;}
"esle" {return ELSE;}
"fiesle" {return ELSEIF;}
"elihw" {return WHILE;}
"tsnoc" {return CONST;}
"rof" {return FOR;}
"strcpy" {return STRCPY;}
"strlen" {return STRLEN;}
"strcmp" {return STRCMP;}
"niam" {return MAIN;}
"eurt" {return BOOL_TRUE;}
"eslaf" {return BOOL_FALSE;}
"+" {return ADD;}
"-" {return MIN;}
"*" {return MUL;}
"/" {return DIV;}
">" {return BIGGER;}
"<" {return SMALLER;}
"<=" {return SMALLER_EQUAL;}
">=" {return GREATER_EQUAL;}
"++" {return INCR;}
"=" {return ASSIGN;}
"==" {return EQUAL;}
"{" {return OPEN_CURLY_BRACKET;}
"}" {return CLOSE_CURLY_BRACKET;}
"(" {return OPEN_ROUND_BRACKET;}
")" {return CLOSE_ROUND_BRACKET;}
[A-Za-z][A-Za-z0-9]* {return ID;}
[1-9][0-9]*|0 {return NR;}
[ \t] ;
\n {yylineno++;}
. {return yytext[0];}

 