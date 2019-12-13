%{
#include <stdio.h>
#include "y.tab.h"
%}
%option noyywrap
%%
"/*"(.|\n)"*/" ;
":-)" {return START;}
":-(" {return END;}
"tni" {return INT;}
"rahc" {return CHAR;}
"toafl" {return FLOAT;}
"loob" {return BOOL;}
"fi" {return IF;}
"esle" {return ELSE;}
"fiesle" {return ELSEIF;}
"elihw" {return WHILE;}
"rof" {return FOR;}
"strcpy" {return STRCPY;}
"strlen" {return STRLEN;}
"strcmp" {return STRCMP;}
"+" {return ADD;}
"-" {return MIN;}
"*" {return MUL;}
"/" {return DIV;}
">" {return BIGGER;}
"<" {return SMALLER;}
"=" {return ASSIGN;}
"==" {return EQUAL;}
"}" {return OPEN_CURLY_BRACKET;}
"{" {return CLOSE_CURLY_BRACKET;}
")" {return OPEN_ROUND_BRACKET;}
"(" {return CLOSE_ROUND_BRACKET;}
[A-Za-z][A-Za-z0-9]* {return ID;}
[1-9][0-9]*|0 {return NR;}
[ \t] ;
\n {yylineno++;}
. {return yytext[0];}

 
