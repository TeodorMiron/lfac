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
"_+_" {return ADD;}
"_-_" {return MIN;}
"_*_" {return MUL;}
"_/_" {return DIV;}
"_>_" {return BIGER;}
"_<_" {return SMALER;}
"_=_" {return ASIGN;}
"_==_" {return EGAL;}
[A-Za-z][A-Za-z0-9]* {return ID;}
[1-9][0-9]*|0 {return NR;}
[ \t] ;
\n {yylineno++;}
. {return yytext[0];}

 
