%{
#include <stdio.h>
#include <stdbool.h>
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
        char*typeOf;
        char*dataType;
        char*scope;
        int intval;
        char*stringval;
        _Bool boolvalue;
        char charvalue;

} SymTabEntry;
struct ListTables
{
        GHashTable*hashTable;
        struct ListTables*next;
} ListTables;
struct ListTables*head=NULL;
void free_entry(struct SymTabEntry*val)
{
        g_free(val);
}
void init_list();
void add_to_list();
void add_entry_head(char*symbol,struct SymTabEntry*ent);
const char*return_type(int value);
void printf_key_value(gpointer key,gpointer value,gpointer userdata);
void delete_list(struct ListTables * head);
void add_object(char*name);
void add_function(char*name,int scope,char*type);
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
%token START END ASSIGN IF ELSEIF WHILE FOR STRCPY STRLEN STRCMP STRCAT ADD DIV BIGGER SMALLER MIN MUL EQUAL OPEN_ROUND_BRACKET CLOSE_ROUND_BRACKET CLOSE_CURLY_BRACKET OPEN_CURLY_BRACKET INCR CLASS MAIN ELSE CONST SMALLER_EQUAL BOOL_TRUE BOOL_FALSE GREATER_EQUAL STRING_TYPE
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
start_program:declaration_section main_section {printf("Programul este corect\n");}
             ;

declaration_section:declaration_section declaration_content;
                    | declaration_content
                    ;

declaration_content:function_declaration
                    | object_declaration
                    | create_variable 
                    ;

object_declaration:  ID CLASS OPEN_CURLY_BRACKET object_content CLOSE_CURLY_BRACKET 
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
               | ';''#'create_multiple_variable available_types 
               | ';''$'create_array_variable
               | ';'create_const_variable
               ;

create_array_variable:'['expression']' ID available_types
                     ;

create_single_variable:  '$' ID available_types 
                        |'$' expression ASSIGN ID available_types
                        ;

create_multiple_variable:create_multiple_variable ',' ID
                        | ID
                        ;


create_const_variable:expression ASSIGN ID CONST available_types
                     ;

available_types: INT {$$=$1;}
               | CHAR {$$=$1;}
               | FLOAT {$$=$1;}
               | BOOL {$$=$1;}
               | ID 
               | CONST 
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
     init_list();
   yyin=fopen(argv[1],"r");
   
   yyparse();
   g_hash_table_foreach(head->hashTable,printf_key_value,NULL);
   return 0;
} 
void init_list()
{ 
        head=malloc(sizeof(struct ListTables));
        head->hashTable=g_hash_table_new_full(g_str_hash,g_str_equal,g_free,(void*)free_entry);
}
void add_to_list()
{
        struct ListTables*var=malloc(sizeof(struct ListTables));
        var->hashTable=g_hash_table_new_full(g_str_hash,g_str_equal,g_free,(void*)free_entry);
        var->next=head;
        head=var;
}
void add_entry_head(char*symbol,struct SymTabEntry*ent)
{
    char*key=malloc(strlen(symbol)+1);
    strcpy(key,symbol);
    g_hash_table_insert(head->hashTable,key,ent);
}
const char*return_type(int value)
{
        switch(value)
        {
                case 0:{return "int";}
                case 1:{return "char";}
                case 2:{return "float";}
                case 3:{return "bool";}
                case 4:{return "char*";}
        }
}
void printf_key_value(gpointer key,gpointer value,gpointer userdata)
{
    struct SymTabEntry*entry=value;
    printf("%s \t %s \t %s \t %s \n ",(char*)key,entry->typeOf,entry->dataType,entry->scope);
}
void delete_list(struct ListTables * head)
{
    while(head->next!=NULL)
    {
        head=head->next;
    }
}
void add_object(char*name)
{
        struct SymTabEntry*entry=malloc(sizeof(struct SymTabEntry));
        entry->scope=malloc(8);
        strcpy(entry->scope,"global");
        entry->typeOf=malloc(12);
        strcpy(entry->typeOf,"object-decl");
        add_entry_head(name,entry);
}
void add_function(char*name,int scope,char*type)
{
        struct SymTabEntry*entry=malloc(sizeof(struct SymTabEntry));
        entry->typeOf=malloc(13);
        entry->dataType=malloc(strlen(type));
        strcpy(entry->typeOf,"function-decl");
        strcpy(entry->dataType,type);
        add_entry_head(name,entry);
}