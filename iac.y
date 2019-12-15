%{
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
extern FILE* yyin;
extern int yylineno;
int yydebug=1;
typedef struct expr_info
{
        char*name;
        int exprtype;
        int intvalue;
        float floatvalue;
        _Bool boolvalue;
        char*stringvalue;
        char charvalue;
        
} expr_info;


expr_info*create_int_expression(char*name,int value);
expr_info*create_string_expression(char*name,char*expr1,char*expr2);
expr_info*create_bool_expression(char*name,_Bool value);
expr_info*create_float_expression(char*name,float value);
void init_ptr(struct expr_info*expr);
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
/*%token START END INT CHAR FLOAT ASSIGN BOOL IF ELSEIF WHILE FOR STRCPY STRLEN STRCMP ID NR ADD DIV BIGGER SMALLER MIN MUL EQUAL OPEN_ROUND_BRACKET CLOSE_ROUND_BRACKET CLOSE_CURLY_BRACKET OPEN_CURLY_BRACKET INCR CLASS MAIN ELSE STRING CONST SMALLER_EQUAL BOOL_TRUE BOOL_FALSE GREATER_EQUAL*/
%left ADD
%left MUL
%left MIN
%left DIV
%left SMALLER
%left BIGGER
%left INCR
%left EQUAL
%left ELSE
%left OR
%left AND
%left NOT
%left STRCAT
%left STRCPY
%left STRLEN

%token CLASS CLOSE_CURLY_BRACKET OPEN_CURLY_BRACKET CLOSE_ROUND_BRACKET OPEN_ROUND_BRACKET CONST MAIN END ELSEIF
%token<intval> INT CHAR FLOAT BOOL STRING NR IF ELSE WHILE FOR ADD MIN MUL DIV INCR ASSIGN EQUAL ID INT_NUMBER OR AND NOT STRCAT
%token<strval> STRING_VAL
%token<boolval> BIGGER SMALLER SMALLER_EQUAL GREATER_EQUAL BOOL_FALSE BOOL_TRUE 
%token<strvalue> STRCPY STRLEN STRCMP
%token<floatval> FLOAT_NR
%token<charval> CHAR_VAL
%type<expr_ptr> int_arithmetic float_arithmetic bool_arithmetic string_arithmetic supported_number bool_values string_values float_number

%%
start_program:declaration_section main_section
             ;

declaration_section:declaration_section declaration_content;
                    | declaration_content
                    ;

declaration_content:function_declaration
                    | object_declaration
                    ;

object_declaration:ID CLASS OPEN_CURLY_BRACKET object_content CLOSE_CURLY_BRACKET
                   | ID CLASS OPEN_CURLY_BRACKET CLOSE_CURLY_BRACKET
                   ;

object_content:object_content inside_object
              | inside_object
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
            | function_call
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
               | create_array_variable
               | create_const_variable
               ;

create_array_variable:'['NR']' ID available_types
                     ;

create_single_variable: ID available_types
                      ;

create_multiple_variable:create_multiple_variable ',' ID
                        | ID
                        ;

create_const_variable:expression ASSIGN ID CONST
                     ;

available_types: INT
               | CHAR
               | FLOAT
               | BOOL
               | ID 
               ;

expression:NR
          | ID  
          | STRING_VAL
          | OPEN_ROUND_BRACKET expression CLOSE_ROUND_BRACKET
          | expression BIGGER expression
          | expression SMALLER expression
          | expression EQUAL expression
          | ID INCR
          ;

main_section:OPEN_ROUND_BRACKET CLOSE_ROUND_BRACKET MAIN INT OPEN_CURLY_BRACKET multiple_instructions CLOSE_CURLY_BRACKET
             |OPEN_ROUND_BRACKET CLOSE_ROUND_BRACKET MAIN INT OPEN_CURLY_BRACKET float_arithmetic CLOSE_CURLY_BRACKET
             |OPEN_ROUND_BRACKET CLOSE_ROUND_BRACKET MAIN INT OPEN_CURLY_BRACKET CLOSE_CURLY_BRACKET
             ;

supported_number:NR {$$=create_int_expression("",$<intval>1); printf("Ce am create:%i\n",$$->intvalue);}
                ;

int_arithmetic: int_arithmetic ADD int_arithmetic {$$=create_int_expression("",$1->intvalue+$3->intvalue);printf("Rezultat:%i\n",$$->intvalue);}
              | int_arithmetic MIN int_arithmetic {$$=create_int_expression("",$1->intvalue-$3->intvalue);}
              | int_arithmetic MUL int_arithmetic {$$=create_int_expression("",$1->intvalue*$3->intvalue);}
              | int_arithmetic DIV int_arithmetic {$$=create_int_expression("",$1->intvalue/$3->intvalue);}
              | supported_number 
              ;

string_values:STRING_VAL {$$=create_string_expression("",$<strval>1,NULL);}
             ;

string_arithmetic:STRCPY OPEN_ROUND_BRACKET string_arithmetic ',' string_arithmetic CLOSE_ROUND_BRACKET {$$=create_string_expression("",$5->stringvalue,NULL);printf("Rezultat:%s",$$->stringvalue);}
                 | STRCAT OPEN_ROUND_BRACKET string_arithmetic ','string_arithmetic CLOSE_ROUND_BRACKET {$$=create_string_expression("",$3->stringvalue,$5->stringvalue);printf("Rezultat:%s",$$->stringvalue);}
                 | STRLEN OPEN_ROUND_BRACKET string_arithmetic CLOSE_ROUND_BRACKET {$$=create_int_expression("",strlen($3->stringvalue));printf("Rezultat:%i",$$->intvalue);}
                 | string_values
                 ;

float_number:FLOAT_NR {$$=create_float_expression("",$<floatval>1); printf("Ce am create:%i\n",$$->floatvalue);}
                ;

float_arithmetic: float_arithmetic ADD float_arithmetic {$$=create_float_expression("",$1->floatvalue+$3->floatvalue);printf("Rezultat:%lf\n",$$->floatvalue);}
              | float_arithmetic MIN float_arithmetic {$$=create_float_expression("",$1->floatvalue-$3->floatvalue);}
              | float_arithmetic MUL float_arithmetic {$$=create_float_expression("",$1->floatvalue*$3->floatvalue);}
              | float_arithmetic DIV float_arithmetic {$$=create_float_expression("",$1->floatvalue/$3->floatvalue);}
              | float_number 
              ;


bool_values: BOOL_TRUE {$$=create_bool_expression("",true);}
           | BOOL_FALSE {$$=create_bool_expression("",false);}
           ;

bool_arithmetic: bool_arithmetic AND bool_arithmetic {$$=create_bool_expression("",$1->boolvalue && $3->boolvalue);printf("Rezultat:%i",$$->boolvalue);}
                | bool_arithmetic OR bool_arithmetic {$$=create_bool_expression("",$1->boolvalue || $3->boolvalue);}
                | NOT bool_arithmetic {$$=create_bool_expression("",!$2->boolvalue); }
                | bool_values
                ;

%%
int yyerror(char * s){
 printf("eroare: %s la linia:%d\n",s,yylineno);
}

int main(int argc, char** argv){
 yyin=fopen(argv[1],"r");
 yyparse();
} 

expr_info*create_int_expression(char*name,int value)
{
        expr_info*var=malloc(sizeof(struct expr_info));
        bzero(var,sizeof(struct expr_info));
        var->name=malloc(strlen(name)+1);
        strcpy(var->name,name);
        var->intvalue=value;
        var->exprtype=1;
        printf("Rezultat in functie:%i\n",var->intvalue);
        return var;
}
void init_ptr(struct expr_info*expr)
{
        expr->name=NULL;
        expr->exprtype=0;
        expr->floatvalue=0;
        expr->boolvalue=0;
        expr->stringvalue =NULL;
        expr->charvalue=0;
}

expr_info*create_string_expression(char*name,char*expr1,char*expr2)
{
        expr_info*var=malloc(sizeof(struct expr_info));
        bzero(var,sizeof(struct expr_info));
        var->exprtype=5;
        int len2 = expr2 ? strlen(expr2) : 0;
        var->stringvalue = (char*) malloc(sizeof(char)*(strlen(expr1) + len2 +1)); 
        strcpy(var->stringvalue,expr1);
        if(expr2)
        {
                strcat(var->stringvalue,expr2);
        }
        return var;
}
expr_info*create_bool_expression(char*name,_Bool value)
{
        expr_info*var =malloc(sizeof(struct expr_info));
        bzero(var,sizeof(struct expr_info));
        var->name=malloc(strlen(name)+1);
        strcpy(var->name,name);
        var->boolvalue=value;
        var->exprtype=4;
        printf("Rezultat in functie:%i\n",var->boolvalue);
        return var;
}
expr_info*create_float_expression(char*name,float value)
{
        expr_info*var=malloc(sizeof(struct expr_info));
        bzero(var,sizeof(struct expr_info));
        var->name=malloc(strlen(name)+1);
        strcpy(var->name,name);
        var->floatvalue=value;
        var->exprtype=3;
        printf("Rezultat in functie:%lf\n",var->floatvalue);
        return var;
}