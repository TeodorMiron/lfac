%{
#include <stdio.h>
extern FILE* yyin;
extern int yylineno;
int yydebug=1;
%}
%start start_program
%token START END INT CHAR FLOAT ASSIGN BOOL IF ELSE ELSEIF WHILE FOR STRCPY STRLEN STRCMP ID NR ADD DIV BIGGER SMALLER MIN MUL EQUAL OPEN_ROUND_BRACKET CLOSE_ROUND_BRACKET CLOSE_CURLY_BRACKET OPEN_CURLY_BRACKET
%%
start_program:declaration_section {printf("Program corect sintactic!\n");}
             ;

declaration_section:declaration_section declaration_content;
                    | declaration_content
                    ;

declaration_content:available_types ID OPEN_ROUND_BRACKET list_param CLOSE_ROUND_BRACKET OPEN_CURLY_BRACKET function_content CLOSE_CURLY_BRACKET
                   ;

list_param:list_param ',' available_types ID
           |available_types ID
           ;

function_content: function_content instructions
                | instructions
                ;

multiple_instructions:multiple_instructions instructions
                     | instructions
                     ;

instructions: if_instr
            | while_instr
            | for_instr
            | assign_instr
            ;

if_instr:IF OPEN_ROUND_BRACKET ID CLOSE_ROUND_BRACKET OPEN_CURLY_BRACKET multiple_instructions CLOSE_CURLY_BRACKET
        | IF OPEN_ROUND_BRACKET ID CLOSE_ROUND_BRACKET OPEN_CURLY_BRACKET CLOSE_CURLY_BRACKET
        ;

while_instr:WHILE OPEN_ROUND_BRACKET ID CLOSE_ROUND_BRACKET OPEN_CURLY_BRACKET multiple_instructions CLOSE_CURLY_BRACKET
            | WHILE OPEN_ROUND_BRACKET ID CLOSE_ROUND_BRACKET OPEN_CURLY_BRACKET CLOSE_CURLY_BRACKET
            ;

assign_instr:ID ASSIGN ID
            | ID ASSIGN NR
            ;

for_instr:FOR OPEN_ROUND_BRACKET ASSIGN ';' ID ';' ID CLOSE_ROUND_BRACKET OPEN_CURLY_BRACKET multiple_instructions CLOSE_CURLY_BRACKET
         | FOR OPEN_ROUND_BRACKET ASSIGN ';' ID ';' ID CLOSE_ROUND_BRACKET OPEN_CURLY_BRACKET CLOSE_CURLY_BRACKET
         ;


available_types:INT
               | CHAR
               | FLOAT
               | BOOL
               ;



%%
int yyerror(char * s){
 printf("eroare: %s la linia:%d\n",s,yylineno);
}

int main(int argc, char** argv){
 yyin=fopen(argv[1],"r");
 yyparse();
} 