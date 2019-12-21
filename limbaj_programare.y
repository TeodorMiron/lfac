%{
#include <stdio.h>
#include <stdbool.h>
extern FILE* yyin;
extern int yylineno;
int yydebug=1;
int yylex();
int yyerror(char *s);
typedef struct expr_info
{
        char*name;
        int datatype;
        int intvalue;
        float floatvalue;
        _Bool boolvalue;
        
} expr_info;

%}

%union 
{
        int intval;
        char* strval;
        _Bool boolval;
        char charval;
        float floatval;
        struct expr_info* expr_ptr;
        struct expr_info** list_expr_ptr;
}

%start start_program
%token START END INT CHAR FLOAT ASSIGN BOOL IF ELSEIF WHILE FOR STRCPY STRLEN STRCMP STRCAT ID INT_VAL ADD DIV BIGGER SMALLER MIN MUL EQUAL OPEN_ROUND_BRACKET CLOSE_ROUND_BRACKET CLOSE_CURLY_BRACKET OPEN_CURLY_BRACKET INCR CLASS MAIN ELSE STRING_VAL STRING CONST SMALLER_EQUAL BOOL_TRUE BOOL_FALSE GREATER_EQUAL STRING_TYPE FLOAT_VAL
%left ADD 
%left MIN
%left MUL
%left DIV
%left SMALLER
%left BIGGER
%left INCR
%left EQUAL
%left IF
%left ELSEIF

/*
%token CLASS CLOSE_CURLY_BRACKET OPEN_CURLY_BRACKET CLOSE_ROUND_BRACKET OPEN_ROUND_BRACKET CONST MAIN 
%token<intval> INT CHAR FLOAT BOOL NR IF ELSE WHILE FOR ADD MIN MUL DIV INCR ASSIGN EQUAL ID STRING
%token<strval> STRING
%token<boolval> BIGGER SMALLER SMALLER_EQUAL GREATER_EQUAL BOOL_FALSE BOOL_TRUE 
*/

%%
start_program:declaration_section main_section {printf("Programul este corect\n");}
             ;

declaration_section:declaration_section declaration_content;
                    | declaration_content
                    ;

declaration_content:function_declaration
                    | object_declaration
                    | create_variable

object_declaration:ID CLASS OPEN_CURLY_BRACKET object_content CLOSE_CURLY_BRACKET
                   | ID CLASS OPEN_CURLY_BRACKET CLOSE_CURLY_BRACKET
                   ;

object_content:object_content inside_object
              | inside_object
              | expression
              ; 

inside_object:function_declaration
             | create_variable
             ; 
                    
function_declaration: OPEN_ROUND_BRACKET list_param CLOSE_ROUND_BRACKET ID available_types OPEN_CURLY_BRACKET function_content CLOSE_CURLY_BRACKET
                    | OPEN_ROUND_BRACKET list_param CLOSE_ROUND_BRACKET ID available_types OPEN_CURLY_BRACKET CLOSE_CURLY_BRACKET
                    ;

list_param:list_param ',' ID available_types
           |ID available_types
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
            | create_variable
            | expression
            ;

function_call:'#'OPEN_ROUND_BRACKET list_call CLOSE_ROUND_BRACKET  ID
             |'#'OPEN_ROUND_BRACKET CLOSE_ROUND_BRACKET  ID
             ;


list_call: expression  ',' list_call
         | expression
         ;

if_instr:OPEN_ROUND_BRACKET expression CLOSE_ROUND_BRACKET IF OPEN_CURLY_BRACKET multiple_instructions CLOSE_CURLY_BRACKET else_instr
        |OPEN_ROUND_BRACKET expression CLOSE_ROUND_BRACKET IF OPEN_CURLY_BRACKET CLOSE_CURLY_BRACKET else_instr
        ;

else_instr:ELSE OPEN_CURLY_BRACKET multiple_instructions CLOSE_CURLY_BRACKET
          |ELSE OPEN_CURLY_BRACKET CLOSE_CURLY_BRACKET
          | 
          ;

while_instr: OPEN_ROUND_BRACKET expression CLOSE_ROUND_BRACKET WHILE OPEN_CURLY_BRACKET multiple_instructions CLOSE_CURLY_BRACKET
            |OPEN_ROUND_BRACKET expression CLOSE_ROUND_BRACKET WHILE OPEN_CURLY_BRACKET CLOSE_CURLY_BRACKET
            ;

assign_instr:expression ASSIGN ID 
            ;

for_instr: OPEN_ROUND_BRACKET assign_instr ';' expression ';' expression CLOSE_ROUND_BRACKET FOR OPEN_CURLY_BRACKET multiple_instructions CLOSE_CURLY_BRACKET
         | OPEN_ROUND_BRACKET assign_instr ';' expression ';' expression CLOSE_ROUND_BRACKET FOR OPEN_CURLY_BRACKET CLOSE_CURLY_BRACKET
         | OPEN_ROUND_BRACKET CLOSE_ROUND_BRACKET FOR OPEN_CURLY_BRACKET CLOSE_CURLY_BRACKET
         ;

create_variable: create_single_variable 
               | '#'create_multiple_variable available_types
               | '$'create_array_variable
               | create_const_variable
               ;

create_array_variable:'['INT_VAL']' ID available_types
                     ;

create_single_variable: '$' ID available_types
                      | '$' expression ASSIGN ID available_types
                      ;

create_multiple_variable:create_multiple_variable ',' ID
                        | ID
                        ;


create_const_variable:expression ASSIGN ID CONST available_types
                     ;

available_types: INT
               | CHAR
               | FLOAT
               | BOOL
               | ID 
               | CONST
               | STRING
               ;

expression: supported_values
          | ID  

          | function_call
          | object_call_function
          | object_access_var
          | object_modify_var
          | access_vector
          | OPEN_ROUND_BRACKET expression CLOSE_ROUND_BRACKET
          | expression ADD expression
          | expression MUL expression
          | expression DIV expression
          | expression MIN expression
          | expression BIGGER expression
          | expression SMALLER expression
          | expression EQUAL expression
          | STRCPY OPEN_ROUND_BRACKET expression expression CLOSE_ROUND_BRACKET
          | STRLEN OPEN_ROUND_BRACKET expression CLOSE_ROUND_BRACKET
          | STRCAT OPEN_ROUND_BRACKET expression expression CLOSE_ROUND_BRACKET
          ;

supported_values:INT_VAL
                | FLOAT_VAL
                | BOOL_TRUE
                | STRING_VAL
                | BOOL_FALSE
                ;

object_call_function:function_call '.' ID
                    ;

object_modify_var:'@'expression ASSIGN ID'.'ID
                 ;

object_access_var:ID'.'ID
                 ;

access_vector:'['INT_VAL']' ID
             ;

main_section:OPEN_ROUND_BRACKET CLOSE_ROUND_BRACKET MAIN INT OPEN_CURLY_BRACKET multiple_instructions CLOSE_CURLY_BRACKET
            | OPEN_ROUND_BRACKET CLOSE_ROUND_BRACKET MAIN INT OPEN_CURLY_BRACKET CLOSE_CURLY_BRACKET
            ;
%%
int yyerror(char * s){
    printf("eroare: %s la linia:%d\n",s,yylineno);
    return 0;
}

int main(int argc, char** argv){
   yyin=fopen(argv[1],"r");
   yyparse();
   return 0;
} 