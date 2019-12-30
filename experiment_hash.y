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
        int initialised;

} SymTabEntry;
struct ListOfEntries
{
        struct SymTabEntry*value;
        struct ListOfEntries*next;
} ListOfEntries;

struct Checker
{
        GHashTable*localScope;
        int counter;
        char*currentScope;
        struct Checker*next;

};
struct Checker*head=NULL;
struct ListOfEntries*funcArgs=NULL;
FILE*SymTabDump=NULL;
int currLine;
void init_prg();
void free_entry(struct ListOfEntries*val);
void add_new_variable(const char*type,char*identifier);
void add_func_node(char*identifier,const char*returntype,char*arg_list);
void add_statement_node();
void add_class_node(char*identifier);
void add_main_node();
const char*return_type(int type);
void add_new_node(struct Checker*head);
void remove_node();
int is_class_object(char*identifier);
int is_object_variable(char*class,char*variable);
void search_every_class(gpointer key,gpointer value,gpointer userdata);
void print_key_value(gpointer key,gpointer value,gpointer userdata);

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
%token START END ASSIGN IF ELSEIF WHILE FOR STRCPY STRLEN STRCMP STRCAT ADD DIV BIGGER SMALLER MIN MUL EQUAL OPEN_ROUND_BRACKET CLOSE_ROUND_BRACKET CLOSE_CURLY_BRACKET OPEN_CURLY_BRACKET INCR CLASS MAIN ELSE SMALLER_EQUAL BOOL_TRUE BOOL_FALSE GREATER_EQUAL STRING_TYPE CONST RETURN 
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
%token<type> INT STRING FLOAT CHAR BOOL VOID
%type<type> available_types 

%%

start_program: declaration_section main_section {printf("Programul este corect\n");}
             | main_section {printf("Programul este corect\n");}
             | {printf("Programul este corect!\n");}
             ;

declaration_section:declaration_section declaration_content;
                    | declaration_content 
                    ;

declaration_content: function_declaration 
                    | object_declaration  
                    | create_variable 
                    ;


object_declaration: ID CLASS OPEN_CURLY_BRACKET {add_class_node($1);}object_content CLOSE_CURLY_BRACKET  {remove_node();}
                   | ID CLASS OPEN_CURLY_BRACKET {add_class_node($1);}CLOSE_CURLY_BRACKET
                   ;

object_content:object_content inside_object 
              | inside_object
              | expression 
              ; 

inside_object:function_declaration
             | create_variable 
             ; 
                    
function_declaration: OPEN_ROUND_BRACKET list_param CLOSE_ROUND_BRACKET ID available_types  OPEN_CURLY_BRACKET {add_func_node($4,return_type($5),NULL);} function_content return_statement CLOSE_CURLY_BRACKET {remove_node();}
                    | OPEN_ROUND_BRACKET list_param CLOSE_ROUND_BRACKET ID available_types OPEN_CURLY_BRACKET {add_func_node($4,return_type($5),NULL);} CLOSE_CURLY_BRACKET {remove_node();}
                    | OPEN_ROUND_BRACKET CLOSE_ROUND_BRACKET ID available_types OPEN_CURLY_BRACKET {add_func_node($3,return_type($4),NULL);} function_content return_statement CLOSE_CURLY_BRACKET {remove_node();}
                    | OPEN_ROUND_BRACKET CLOSE_ROUND_BRACKET ID available_types OPEN_CURLY_BRACKET {add_func_node($3,return_type($4),NULL);} CLOSE_CURLY_BRACKET {remove_node();}
                    ;

return_statement:RETURN expression
                | 
                ;

list_param:list_param ',' ID available_types
           |ID available_types 
                {

                }
           | ID available_types CONST
           ;

function_content: function_content statements
                | statements
                ;

multiple_statements:multiple_statements statements
                     | statements
                     ;

statements: if_statement
            | while_statement
            | for_statement
            | assign_statement
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

if_statement:OPEN_ROUND_BRACKET expression CLOSE_ROUND_BRACKET IF OPEN_CURLY_BRACKET {add_statement_node();}multiple_statements CLOSE_CURLY_BRACKET {remove_node();} else_statement
        |OPEN_ROUND_BRACKET expression CLOSE_ROUND_BRACKET IF OPEN_CURLY_BRACKET {add_statement_node();}CLOSE_CURLY_BRACKET {remove_node();}else_statement 
        ;

else_statement:ELSE OPEN_CURLY_BRACKET {add_statement_node();}multiple_statements CLOSE_CURLY_BRACKET{remove_node();}
          |ELSE OPEN_CURLY_BRACKET {add_statement_node();}CLOSE_CURLY_BRACKET{remove_node();}
          | 
          ;

while_statement: OPEN_ROUND_BRACKET expression CLOSE_ROUND_BRACKET WHILE OPEN_CURLY_BRACKET {add_statement_node();}multiple_statements CLOSE_CURLY_BRACKET{remove_node();}
            |OPEN_ROUND_BRACKET expression CLOSE_ROUND_BRACKET WHILE OPEN_CURLY_BRACKET {add_statement_node();}CLOSE_CURLY_BRACKET{remove_node();}
            ;

assign_statement: ';'expression ASSIGN ID 
            | ';'expression ASSIGN object_access_var
            | ';'expression ASSIGN access_vector
            ;


for_statement: OPEN_ROUND_BRACKET assign_statement ';' expression ';' expression CLOSE_ROUND_BRACKET FOR OPEN_CURLY_BRACKET {add_statement_node();}multiple_statements CLOSE_CURLY_BRACKET {remove_node();}
         | OPEN_ROUND_BRACKET assign_statement ';' expression ';' expression CLOSE_ROUND_BRACKET FOR OPEN_CURLY_BRACKET {add_statement_node();}CLOSE_CURLY_BRACKET {remove_node();}
         | OPEN_ROUND_BRACKET CLOSE_ROUND_BRACKET FOR OPEN_CURLY_BRACKET {add_statement_node();}CLOSE_CURLY_BRACKET {remove_node();}
         ;

create_variable: ';'create_single_variable 
             //  | ';''#'create_multiple_variable available_types
               | ';''$'create_array_variable
              // | ';'create_const_variable
               ;

create_array_variable:'['expression']' ID available_types {
                                 
                                 char*customType=malloc(strlen(return_type($5))+strlen("50"));
                                 strcpy(customType,return_type($5));
                                 strcat(customType,"[");
                                 strcat(customType,"50");
                                 strcat(customType,"]");
                                 add_new_variable(customType,$4);
                        }
                     | '[' expression ']' ID ID
                     ;

create_single_variable:  '$' ID available_types {add_new_variable(return_type($3),$2);}
                        |'$' ID ID {
                            struct Checker*iterator=head;
                            while(iterator->next!=NULL)
                            {
                                    iterator=iterator->next;
                            }
                            struct ListOfEntries*list=g_hash_table_lookup(iterator->localScope,$3);
                            int objFound=0;
                            while(list)
                            {
                                    if(strcmp(list->value->whatIs,"object-declaration"))
                                    {
                                            objFound=1;
                                            break;
                                    }
                                    list=list->next;
                            }
                            if(objFound)
                            {
                               add_new_variable($3,$2);
                            }
                            else
                            {
                                    printf("Ati incercat sa instantiati clasa [%s] care nu existat\nProgramul a fost incheiat fortat!\n",$2);
                                    exit(EXIT_FAILURE);
                            }

                        }
                        |'$' expression ASSIGN ID available_types {add_new_variable(return_type($5),$4);}
                        |'$' expression ASSIGN ID ID {add_new_variable($5,$4);}
                        |'$' expression ASSIGN ID available_types CONST {
                                char*newtype=malloc(strlen("const-")+strlen(return_type($5))+1);
                                strcpy(newtype,"const-");
                                strcat(newtype,return_type($5));
                                newtype[strlen(newtype)]='\0';
                                add_new_variable(newtype,$4);
                        }
                        ;
/*
create_multiple_variable:create_multiple_variable ',' ID
                        | ID
*/                     ;


available_types: INT {$$=$1;}
               | CHAR {$$=$1;}
               | FLOAT {$$=$1;}
               | BOOL {$$=$1;}
               | STRING {$$=$1;}
               | VOID {$$=$1;}
               ;

expression: ID 
          | INT_VAL 
          | FLOAT_VAL
          | BOOL_TRUE
          | BOOL_FALSE
          | STRING_VAL
          | CHAR_VAL
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
                        {
                                
                                if(!is_class_object($3))
                                {
                                        exit(EXIT_FAILURE);
                                }
                        }
                ;

object_access_var:ID'.'ID
                {
                        if(!is_object_variable($3,$1))
                        {
                                exit(EXIT_FAILURE);
                        }

                }
                 ;

access_vector:'['expression']' ID
             ;

main_section:OPEN_ROUND_BRACKET CLOSE_ROUND_BRACKET MAIN INT OPEN_CURLY_BRACKET {add_main_node();}multiple_statements CLOSE_CURLY_BRACKET {remove_node();}
            | OPEN_ROUND_BRACKET CLOSE_ROUND_BRACKET MAIN INT OPEN_CURLY_BRACKET {add_main_node();}CLOSE_CURLY_BRACKET{remove_node();}
            ;
%%
int yyerror(char * s){
    printf("eroare: %s la linia:%d\n",s,yylineno);
    return 0;
}

int main(int argc, char** argv){
   yyin=fopen(argv[1],"r");
   init_prg();
   yyparse();
   struct Checker*test=head;
   while(test)
   {
           g_hash_table_foreach(test->localScope,print_key_value,NULL);
           test=test->next;
   }
   return 0;
} 
void init_prg()
{
        head=malloc(sizeof(struct Checker));
        head->next=NULL;
        head->localScope=g_hash_table_new_full(g_str_hash,g_str_equal,g_free,(void*)free_entry);
        head->currentScope=malloc(5);
        strcpy(head->currentScope,"0");
        head->counter=0;
        if(NULL==(SymTabDump=fopen("symbol_table.txt","w")))
        {
                perror("Eroare la deschiderea fisierului symbol_table.txt\n");
                exit(EXIT_FAILURE);
        }
        funcArgs=malloc(sizeof(struct ListOfEntries));
}
void free_entry(struct ListOfEntries*val)
{
        g_free(val);
}
void add_func_node(char*identifier,const char*returntype,char*arg_list)
{
        head->counter++;
        struct Checker*newNode=malloc(sizeof(struct Checker));
        newNode->next=head;
        char valuef[5];
        sprintf(valuef,"%d",head->counter);
        int nLenght=strlen(valuef)+1;
        newNode->currentScope=malloc(strlen(head->currentScope)+strlen(valuef)+2);
        strcpy(newNode->currentScope,head->currentScope);
        strcat(newNode->currentScope,"-");
        strcat(newNode->currentScope,valuef);
        newNode->localScope=g_hash_table_new_full(g_str_hash,g_str_equal,g_free,(void*)free_entry);
        head=newNode;
        struct SymTabEntry*newEntry=malloc(sizeof(struct SymTabEntry));
        newEntry->name=malloc(strlen(identifier)+1);
        strcpy(newEntry->name,identifier);
        newEntry->name[strlen(newEntry->name)]='\0';
        newEntry->dataType=malloc(strlen(returntype)+1);
        strcpy(newEntry->dataType,returntype);
        newEntry->dataType[strlen(newEntry->dataType)]='\0';
        newEntry->whatIs=malloc(strlen("function-declaration")+1);
        strcpy(newEntry->whatIs,"function-declaration");
        newEntry->whatIs[strlen(newEntry->whatIs)]='\0';
        newEntry->scope=malloc(strlen(head->currentScope)+1);
        strcpy(newEntry->scope,head->currentScope);
        newEntry->scope[strlen(newEntry->scope)]='\0';
        newEntry->lineOf=yylineno;
        struct ListOfEntries*val;
        if((val=g_hash_table_lookup(head->next->localScope,identifier)))
        {
                while(val)
                {
                        if(strncmp(val->value->scope,newEntry->scope,strlen(newEntry->scope)-nLenght)==0 && strcmp(val->value->whatIs,"function-declaration")==0)
                        {
                                printf("Functia [%s] de tipul de retur %s a fost redeclarata in scope-ul %s\nProgramul a fost incheiat fortat!\n",newEntry->name,newEntry->dataType,val->value->scope);
                                exit(EXIT_FAILURE);
                        }
                        val=val->next;
                }
        }
                struct ListOfEntries*newVal=malloc(sizeof(struct ListOfEntries));
                newVal->value=newEntry;
                newVal->next=NULL;
                g_hash_table_insert(head->localScope,identifier,newVal);

}
void add_new_variable(const char*type,char*identifier)
{
        if(strcmp(type,"void")==0)
        {
                printf("Variabila [%s] declarata de tipul void\n",identifier);
                exit(EXIT_FAILURE);
        }
        struct SymTabEntry*newEntry=malloc(sizeof(struct SymTabEntry));
        newEntry->name=malloc(strlen(identifier)+1);
        newEntry->name[strlen(newEntry->name)]='\0';
        strcpy(newEntry->name,identifier);
        newEntry->dataType=malloc(strlen(type)+1);
        strcpy(newEntry->dataType,type);
        newEntry->dataType[strlen(newEntry->dataType)]='\0';
        newEntry->whatIs=malloc(strlen("variable")+1);
        strcpy(newEntry->whatIs,"variable");
        newEntry->whatIs[strlen(newEntry->whatIs)]='\0';
        newEntry->scope=malloc(strlen(head->currentScope)+1);
        strcpy(newEntry->scope,head->currentScope);
        newEntry->scope[strlen(newEntry->scope)]='\0';
        newEntry->lineOf=yylineno;
        struct ListOfEntries*val;
        if((val=g_hash_table_lookup(head->localScope,identifier)))
        {
                while(val)
                {
                        if(strcmp(val->value->scope,newEntry->scope)==0 && strcmp(val->value->whatIs,"variable")==0)
                        {
                                printf("Variabila [%s] de tipul %s a fost redeclarat in scope-ul %s\n",newEntry->name,newEntry->dataType,newEntry->scope);
                                exit(EXIT_FAILURE);
                        }
                        val=val->next;
                }
        }
                struct ListOfEntries*newVal=malloc(sizeof(struct ListOfEntries));
                newVal->value=newEntry;
                newVal->next=NULL;
                g_hash_table_insert(head->localScope,identifier,newVal);

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
                case 5:{return "void";}
        }

}
void print_key_value(gpointer key,gpointer value,gpointer userdata)
{
        struct ListOfEntries*var=value;
        while(var)
        {
           printf("%s \t%s\t %s\n",var->value->name,var->value->whatIs,var->value->scope);
           if(strcmp(var->value->whatIs,"variable")==0)
           {
                   fprintf(SymTabDump,"%i \t %s \t %s\t %s \t %i \t %s\n",var->value->lineOf,var->value->name,var->value->whatIs,var->value->dataType,var->value->intvalue,var->value->scope);
           }
           if(strcmp(var->value->whatIs,"function-declaration")==0)
           {
                   fprintf(SymTabDump,"%i \t %s \t %s \t %s \t %s \t %s\n",var->value->lineOf,var->value->name,var->value->whatIs,var->value->dataType,var->value->paramlist,var->value->scope);
           }
           if(strcmp(var->value->whatIs,"class-declaration")==0)
           {
                   fprintf(SymTabDump,"%i \t %s \t %s \t %s\n",var->value->lineOf,var->value->name,var->value->whatIs,var->value->scope);
           }
           if(strcmp(var->value->whatIs,"main-declaration")==0)
           {
                   fprintf(SymTabDump,"%i \t %s \t %s \t %s\n",var->value->lineOf,var->value->name,var->value->whatIs,var->value->scope);
           }
           var=var->next;
        }
}
void copy_hash(gpointer key,gpointer value,gpointer userdata)
{
        struct ListOfEntries*content;
        if((content=g_hash_table_lookup(head->next->localScope,key)))
        {
                struct ListOfEntries*concatList=malloc(sizeof(struct ListOfEntries));
                struct ListOfEntries*itf=content;
                while(itf)
                {
                        struct ListOfEntries*newNode=malloc(sizeof(struct ListOfEntries));
                        newNode->value=itf->value;
                        newNode->next=concatList;
                        concatList=newNode;
                        itf=itf->next;
                }
                struct ListOfEntries*its=value;
                while(its)
                {
                        struct ListOfEntries*newNode=malloc(sizeof(struct ListOfEntries));
                        newNode->value=its->value;
                        newNode->next=concatList;
                        concatList=newNode;
                        its=its->next;
                }
                struct ListOfEntries*itt=concatList;
                while(itt)
                {
                        if(itt->next->next==NULL)
                                {
                                        itt->next=NULL;
                                        break;
                                }
                        itt=itt->next;
                }
                g_hash_table_replace(head->next->localScope,key,concatList);
        }
        else
        {
                 g_hash_table_insert(head->next->localScope,key,value);
        }
}
void remove_node()
{
        g_hash_table_foreach(head->localScope,copy_hash,NULL);
        head=head->next;
}
void add_class_node(char*identifier)
{
        head->counter++; 
        struct Checker*newNode=malloc(sizeof(struct Checker));
        newNode->next=head;
        char valuef[5];
        sprintf(valuef,"%d",head->counter);
        newNode->currentScope=malloc(strlen(head->currentScope)+strlen(valuef)+2);
        strcpy(newNode->currentScope,head->currentScope);
        strcat(newNode->currentScope,"-");
        strcat(newNode->currentScope,valuef);
        newNode->localScope=g_hash_table_new_full(g_str_hash,g_str_equal,g_free,(void*)free_entry);
        head=newNode;
        struct SymTabEntry*newEntry=malloc(sizeof(struct SymTabEntry));
        newEntry->name=malloc(strlen(identifier)+1);
        strcpy(newEntry->name,identifier);
        newEntry->name[strlen(newEntry->name)]='\0';
        newEntry->whatIs=malloc(strlen("class-declaration")+1);
        strcpy(newEntry->whatIs,"class-declaration");
        newEntry->whatIs[strlen(newEntry->whatIs)]='\0';
        newEntry->scope=malloc(strlen(head->currentScope)+1);
        strcpy(newEntry->scope,head->currentScope);
        newEntry->scope[strlen(newEntry->scope)]='\0';
        newEntry->lineOf=yylineno;
        struct ListOfEntries*val;
        if((val=g_hash_table_lookup(head->next->localScope,identifier)))
        {  
                while(val)
                {
                        if(strcmp(val->value->whatIs,"class-declaration")==0)
                        {
                                printf("Clasa [%s] a fost redeclarat\nProgramul a fost incheiat fortat!\n",newEntry->name);
                                exit(EXIT_FAILURE);
                        }
                        val=val->next;
                }
        }
                struct ListOfEntries*newVal=malloc(sizeof(struct ListOfEntries));
                newVal->next=NULL;
                newVal->value=newEntry;
                g_hash_table_insert(head->localScope,identifier,newVal);
       
                
}
void add_statement_node()
{7
        head->counter++;
        struct Checker*newNode=malloc(sizeof(struct Checker));
        newNode->localScope=g_hash_table_new_full(g_str_hash,g_str_equal,g_free,(void*)free_entry);
        char value[5];
        sprintf(value,"%d",head->counter);
        newNode->currentScope=malloc(strlen(head->currentScope)+strlen(value)+2);
        strcpy(newNode->currentScope,head->currentScope);
        strcat(newNode->currentScope,"-");
        strcat(newNode->currentScope,value);
        newNode->next=head;
        head=newNode;
        
}
void add_main_node()
{
        head->counter++;
        struct Checker*newNode=malloc(sizeof(struct Checker));
        newNode->localScope=g_hash_table_new_full(g_str_hash,g_str_equal,g_free,(void*)free_entry);
        char value[5];
        sprintf(value,"%d",head->counter);
        newNode->currentScope=malloc(strlen(head->currentScope)+strlen(value)+2);
        strcpy(newNode->currentScope,head->currentScope);
        strcat(newNode->currentScope,"-");
        strcat(newNode->currentScope,value);
        newNode->next=head;
        head=newNode;
        struct SymTabEntry*newEntry=malloc(sizeof(struct SymTabEntry));
        newEntry->name=malloc(strlen("main")+1);
        strcpy(newEntry->name,"main");
        newEntry->whatIs=malloc(strlen("main-declaration")+1);
        strcpy(newEntry->whatIs,"main-declaration");
        newEntry->scope=malloc(strlen(head->currentScope)+1);
        strcpy(newEntry->scope,head->currentScope);
        struct ListOfEntries*val;
        newEntry->lineOf=yylineno;
         if((val=g_hash_table_lookup(head->next->localScope,"main")))
        {  
                while(val)
                {
                        if(strcmp(val->value->whatIs,"class-declaration")==0)
                        {
                                printf("Clasa [%s] a fost redeclarat\nProgramul a fost incheiat fortat!\n",newEntry->name);
                                exit(EXIT_FAILURE);
                        }
                        val=val->next;
                }
        }
                struct ListOfEntries*newVal=malloc(sizeof(struct ListOfEntries));
                newVal->next=NULL;
                newVal->value=newEntry;
                g_hash_table_insert(head->localScope,"main",newVal);
}
int is_class_object(char*identifier)
{
                        struct Checker *allScope=head;
                        int classFound=0;
                        int exists=0;
                                while(allScope && !classFound)
                                {
                                        struct ListOfEntries*searchList;
                                        if(searchList=g_hash_table_lookup(allScope->localScope,identifier))
                                        {
                                                while(searchList && !classFound)
                                                {
                                                        struct Checker*globalScope=head;
                                                        while(globalScope->next!=NULL)
                                                        {
                                                                globalScope=globalScope->next;
                                                        }       
                                                        struct ListOfEntries*insideList;
                                                        if(insideList=g_hash_table_lookup(globalScope->localScope,searchList->value->dataType))
                                                        {
                                                                while(insideList)
                                                                {
                                                                        if(strcmp(insideList->value->whatIs,"object-declaration"))
                                                                        {
                                                                                classFound=1;
                                                                                break;
                                                                        }
                                                                        insideList=insideList->next;
                                                                }
                                                        }
                                                        searchList=searchList->next;
                                                }
                                                exists=1;
                                        }
                                        allScope=allScope->next;
                                }
                                if(!exists)
                                {
                                        printf("Identificatorul [%s] nu este declarat!\n",identifier);
                                        return 0;
                                }
                                if(!classFound)
                                {
                                        printf("Identificatorul [%s] este declarat insa nu desemneaza un obiect!\n",identifier);
                                        return 0;
                                }
                                return 1;
}
int is_object_variable(char*object,char*variable)
{
        struct Checker *allScope=head;
                        int classFound=0;
                        int exists=0;
                        char*classScope;
                         struct Checker*globalScope=head;
                        while(globalScope->next!=NULL)
                        {
                                globalScope=globalScope->next;
                        }  
                        while(allScope && !classFound)
                        {
                                struct ListOfEntries*searchList;
                                if(searchList=g_hash_table_lookup(allScope->localScope,object))
                                {
                                        while(searchList && !classFound)
                                        {
                                                        
                                                struct ListOfEntries*insideList;
                                                if(insideList=g_hash_table_lookup(globalScope->localScope,searchList->value->dataType))
                                                {
                                                        while(insideList)
                                                        {
                                                                if(strcmp(insideList->value->whatIs,"object-declaration"))
                                                                {
                                                                        classFound=1;
                                                                        classScope=malloc(strlen(insideList->value->scope)+1);
                                                                        strcpy(classScope,insideList->value->scope);
                                                                        break;
                                                                }
                                                                insideList=insideList->next;
                                                        }
                                                }
                                                searchList=searchList->next;
                                        }
                                        exists=1;
                                }
                                allScope=allScope->next;
                        }
                        if(!exists)
                        {
                                printf("Identificatorul [%s] nu este declarat!\n",object);
                                return 0;
                        }
                        if(!classFound)
                        {
                                printf("Identificatorul [%s] este declarat insa nu desemneaza un obiect!\n",object);
                                return 0;
                        }
                        int variableFound=0;
                        struct ListOfEntries*listVar;
                        if(listVar=g_hash_table_lookup(globalScope->localScope,variable))
                        {
                                while(listVar)
                                {
                                        if(strcmp(listVar->value->scope,classScope)==0)
                                        {
                                                variableFound=1;
                                                break;
                                        }
                                        listVar=listVar->next;
                                }
                        }
                        if(!variableFound)
                        {
                                printf("Identificatorul [%s] nu este declarat ca variabila membra a obiectului [%s]\n",variable,object);
                                return 0;
                        }
                        return 1;
                        
}