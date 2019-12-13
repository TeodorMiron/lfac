%{
#include <stdio.h>
extern FILE* yyin;
extern int yylineno;
%}
%start s
%token START END INT CHAR FLOAT  ASIGN BOOL IF ELSE ELSEIF WHILE FOR STRCPY STRLEN STRCMP ID NR ADD DIV BIGER SMALER MIN MUL EGAL
%%
s: declarare_functii main {printf ("input acceptat!\n");}
 ;

declarare_functii: ID ')'var2'(' corp declarare_functii
       |ID ')'var2'(' corp
       |ID ')''(' corp
       ;

corp: '{' variabile calcule '}'
    | '{''}'
    ;


variabile: variabile tip var
        | tip var
        ;

tip: INT
    |CHAR
    |FLOAT
    |BOOL
    ;

var: ID','var
   |ID';'
   ;

var2: ID','var2
    |ID
    ;

calcule: calcule iff
       |calcule foor
       |calcule whyl
       |calcule asign ';'
       |
       ;

iff: IF ')' expr '(' '{' calcule '}' expr2
    ;

expr2: ELSEIF ')' expr '(' '{' calcule '}' expr2
     | ELSE '{' calcule '}'
     |
     ;

foor: FOR ')' asign ';' expr ';' asign ';' '(' '{' calcule '}'
    ;

whyl: WHILE ')' expr '(' '{' calcule '}'
    ;

asign: ID ASIGN expr 
     ;


expr:'_'
    ;


main: START  END


%%
int yyerror(char * s){
 printf("eroare: %s la linia:%d\n",s,yylineno);
}

int main(int argc, char** argv){
 yyin=fopen(argv[1],"r");
 yyparse();
} 