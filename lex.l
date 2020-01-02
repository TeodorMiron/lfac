
%{
#include <stdio.h>
#include <string.h>
#include "y.tab.h"
%}
%option noyywrap
%%
"/*"(.|\n)"*/" ;
"tni" {yylval.type=0;return INT;}
"ssalc" {return CLASS;}
"rahc" {yylval.type=1;return CHAR;}
"taolf" {yylval.type=2;return FLOAT;}
"loob" {yylval.type=3;return BOOL;}
"*rahc" {yylval.type=4;return STRING;}
"diov" {yylval.type=5;return VOID;}
"nruter" {return RETURN;}
"fi" {return IF;}
"esle" {return ELSE;}
"fiesle" {return ELSEIF;}
"elihw" {return WHILE;}
"tsnoc" {return CONST;}
"rof" {return FOR;}
"ypcrts" {return STRCPY;}
"nelrts" {return STRLEN;}
"pmcrts" {return STRCMP;}
"tacrts" {return STRCAT;}
"niam" {return MAIN;}
"eurt" {yylval.boolVal=strdup(yytext);return BOOL_TRUE;}
"eslaf" {yylval.boolVal=strdup(yytext);return BOOL_FALSE;}
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
[A-Za-z][A-Za-z0-9]* {yylval.strname=strdup(yytext);return ID;}
[-]?[1-9][0-9]*|0 {yylval.intval=atoi(yytext);return INT_VAL;}
[-]?([0-9]*[.])?[0-9]+ {yylval.floatval=atof(yytext);return FLOAT_VAL;}
\"[^\"\n]*\" {yylval.strval=strdup(yytext);return STRING_VAL;}
\'[^\"\n]*\' {yylval.strval=strdup(yytext);return CHAR_VAL;}
[ \t] ;
\n {yylineno++;}
. {return yytext[0];}

 
