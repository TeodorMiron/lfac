%{
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include </usr/include/glib-2.0/glib.h>

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
struct SymTabEntry
{
        char*name;
        char*scope;
        char*whatIs;
        char*dataType;
        int intvalue;
        int lineOf;
        char*stringval;
        char charvalue;
        float floatvalue;
        char*paramlist;

} SymTabEntry;
struct Checker
{
        GHashTable*localScope;
        int counter;
        char*currentScope;
        struct Checker*next;

};
struct Checker*head=NULL;
void init_checker();
void free_entry(struct SymTabEntry*val);
void start_program();
void add_new_variable(struct Checker*head,const char*type,char*identifier);
const char*return_type(int type);
void dump_symtab(gpointer key,gpointer value,gpointer userdata);
void add_new_node(struct Checker*head);
void remove_head_node(struct Checker*head);
void add_class_node(char*name);
void add_func_node(char*name,char*returntype,char*arg_list,struct Checker*head);
void add_statement_node(struct Checker*head);

%}

%union 
{
        int type;
        char*strname;
        int intval;
        char* strval;
        _Bool boolval;
        char charval;
        float floatval;
        struct expr_info* expr_ptr;
}

%start start_program
%token START END ASSIGN IF ELSEIF WHILE FOR STRCPY STRLEN STRCMP STRCAT ADD DIV BIGGER SMALLER MIN MUL EQUAL OPEN_ROUND_BRACKET CLOSE_ROUND_BRACKET CLOSE_CURLY_BRACKET OPEN_CURLY_BRACKET INCR CLASS MAIN ELSE SMALLER_EQUAL BOOL_TRUE BOOL_FALSE GREATER_EQUAL STRING_TYPE CONST
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


%token<strname> ID
%token<intval> INT_VAL;
%token<strval> STRING_VAL
%token<floatval> FLOAT_VAL
%token<charval> CHAR_VAL
%token<type> INT STRING FLOAT CHAR BOOL
%type<type> available_types 

%%
start_program:{init_checker(head);} declaration_section main_section {printf("Programul este corect\n");}
             ;

declaration_section:declaration_section declaration_content;
                    | declaration_content
                    ;

declaration_content: function_declaration 
                    | object_declaration  
                    | create_variable 
                    ;


object_declaration: ID CLASS OPEN_CURLY_BRACKET {add_new_node(head);}object_content CLOSE_CURLY_BRACKET 
                   | ID CLASS OPEN_CURLY_BRACKET CLOSE_CURLY_BRACKET
                   ;

object_content:object_content inside_object 
              | inside_object
              | expression 
              ; 

inside_object:function_declaration
             | create_variable 
             ; 
                    
function_declaration: OPEN_ROUND_BRACKET list_param CLOSE_ROUND_BRACKET ID available_types OPEN_CURLY_BRACKET {add_new_node(head);}function_content CLOSE_CURLY_BRACKET 
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
            | ';'function_call
            | ';' object_call_function
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

assign_instr: ';'expression ASSIGN ID 
            | ';'expression ASSIGN object_access_var
            | ';'expression ASSIGN access_vector
            ;


for_instr: OPEN_ROUND_BRACKET assign_instr ';' expression ';' expression CLOSE_ROUND_BRACKET FOR OPEN_CURLY_BRACKET multiple_instructions CLOSE_CURLY_BRACKET
         | OPEN_ROUND_BRACKET assign_instr ';' expression ';' expression CLOSE_ROUND_BRACKET FOR OPEN_CURLY_BRACKET CLOSE_CURLY_BRACKET
         | OPEN_ROUND_BRACKET CLOSE_ROUND_BRACKET FOR OPEN_CURLY_BRACKET CLOSE_CURLY_BRACKET
         ;

create_variable: ';'create_single_variable 
             //  | ';''#'create_multiple_variable available_types
               | ';''$'create_array_variable
               | ';'create_const_variable
               ;

create_array_variable:'['expression']' ID available_types
                     | '[' expression ']' ID ID
                     ;

create_single_variable:  '$' ID available_types {add_new_variable(head,return_type($3),$2);}
                        |'$' ID ID {add_new_variable(head,$3,$2);}
                        |'$' expression ASSIGN ID available_types {add_new_variable(head,return_type($5),$4);}
                        |'$' expression ASSIGN ID ID {add_new_variable(head,$5,$4);}
                        |'$' expression ASSIGN ID available_types CONST {
                                char*newtype=malloc(strlen("const-")+strlen(return_type($5))+1);
                                strcpy(newtype,"const-");
                                strcat(newtype,return_type($5));
                                newtype[strlen(newtype)]='\0';
                                add_new_variable(head,newtype,$4);
                        }
                        ;
/*
create_multiple_variable:create_multiple_variable ',' ID
                        | ID
*/                     ;

create_const_variable:expression ASSIGN ID CONST available_types
                     | expression ASSIGN ID CONST ID
                     ;

available_types: INT {$$=$1;}
               | CHAR {$$=$1;}
               | FLOAT {$$=$1;}
               | BOOL {$$=$1;}
               | STRING {$$=$1;}
               ;

expression: ID 
          | INT_VAL 
          | FLOAT_VAL
          | BOOL_TRUE
          | BOOL_FALSE
          | STRING_VAL
          | function_call
          | object_call_function
          | object_access_var
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


object_call_function:function_call '.' ID
                    ;

object_access_var:ID'.'ID
                 ;

access_vector:'['expression']' ID
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
   init_checker();
   yyparse();
   return 0;
} 
void init_checker()
{
        head=malloc(sizeof(struct Checker));
        head->next=NULL;
        head->localScope=g_hash_table_new_full(g_str_hash,g_str_equal,g_free,(void*)free_entry);
        head->currentScope=malloc(2);
        strcpy(head->currentScope,"0");
        head->currentScope[strlen(head->currentScope)]='\0';
        head->counter=0;
}
void free_entry(struct SymTabEntry*val)
{
        g_free(val);
}
void add_new_variable(struct Checker*head,const char*type,char*identifier)
{
        
        struct SymTabEntry*newEntry=malloc(sizeof(struct SymTabEntry));
        newEntry->name=malloc(strlen(identifier)+1);
        newEntry->name[strlen(newEntry->name)]='\0';
        strcpy(newEntry->name,identifier);
        newEntry->dataType=malloc(strlen(type)+1);
        strcpy(newEntry->dataType,type);
        newEntry->whatIs=malloc(strlen("variable")+1);
        strcpy(newEntry->whatIs,"variable");
        newEntry->scope=malloc(strlen(head->currentScope));
        strcpy(newEntry->scope,head->currentScope);
        newEntry->lineOf=yylineno;
        printf("Adaug:%s de tipul %s in cu path-ul %s\n",identifier,type,newEntry->scope);
        g_hash_table_insert(head->localScope,identifier,newEntry);
}
const char*return_type(int type)
{
        switch(type)
        {
                case 0:{return "int";}
                case 1:{return "char";}
                case 2:{return "float";}
                case 3:{return "bool";}
                case 4:{return "char*";}
                case 5:{return "const";}
        }

}
void print_key_value(gpointer key,gpointer value,gpointer userdata)
{
        struct SymTabEntry*var=value;
        printf("%s \t%s\t %s \t %s\n",var->name,var->whatIs,var->dataType,var->scope);
}
void add_new_node(struct Checker*head)
{
        printf("Am adaugat ceva nou\n");
        head->counter++;
        struct Checker*newChecker=malloc(sizeof(struct Checker));
        newChecker->currentScope=malloc(strlen(head->currentScope)+3);
        if(head->next==NULL)
        {

            sprintf(newChecker->currentScope,"%d",head->counter);
        }
        else
        {
                strcpy(newChecker->currentScope,head->currentScope);
                strcat(newChecker->currentScope,"-");
                char value[6];
                sprintf(value,"%d",newChecker->counter);
                strcat(newChecker->currentScope,value);   
        }
        newChecker->localScope=g_hash_table_new_full(g_str_hash,g_str_equal,g_free,(void*)free_entry);
        newChecker->next=head;
        head=newChecker;
        printf("New Scope:%s\n",head->currentScope);
}
void insert_next(gpointer key,gpointer value,gpointer userData)
{
        g_hash_table_insert(head->next->localScope,key,value);
}
void remove_head_node(struct Checker*head)
{
    g_hash_table_foreach(head->localScope,insert_next,NULL);
    head=head->next;
}
void add_class_node(char*name)
{
        struct Checker*newChecker=malloc(sizeof(struct Checker));
        head->counter++;
        
}
