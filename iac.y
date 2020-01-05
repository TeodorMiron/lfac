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

struct expr_info
{
        char*type;
        char*expString;

} expr_info;
struct eval_expr
{
        int intvalue;
        char*name;

} eval_expr;

struct Checker*head=NULL;
struct ListOfEntries*funcArgs=NULL;
struct ListOfEntries*objVars=NULL;
char*typesOfCall=NULL;
char*inObjectFunc=NULL;
char*classScope=NULL;
char*objName=NULL;
int inArgs=0;
int inClass=0;
int noArgs=0;
int objInstance=0;
FILE*SymTabDump=NULL;
void init_prg();
void free_entry(struct ListOfEntries*val);
void free_checker(struct Checker*val);
void add_new_variable(const char*type,char*identifier,int init);
void add_func_node(char*identifier,const char*returntype);
void add_statement_node();
void add_class_node(char*identifier);
void add_main_node();
const char*return_type(int type);
void add_new_node(struct Checker*head);
void remove_node();
struct expr_info*create_int_expression(int intValue);
struct expr_info*create_bool_expression(const char*boolValue);
struct expr_info*create_float_expression(float floatValue);
struct expr_info*create_string_expression(char*stringValue);
struct expr_info*create_char_expression(const char charValue);
struct expr_info*create_variable_expression(const char*identifier,char*type);
struct expr_info*create_paranthesis_expression(struct expr_info*exp);
struct expr_info*create_expression(char*type,char*eString);
struct eval_expr*create_eval_expression(char*name,int value);
char* is_class_object(char*identifier);
struct ListOfEntries*new_parameter_list(struct ListOfEntries*oldList);
int is_object_variable(char*class,char*variable);
void search_every_class(gpointer key,gpointer value,gpointer userdata);
void print_key_value(gpointer key,gpointer value,gpointer userdata);
int countChars( char* s, char c )
{
    return *s == '\0'? 0: countChars( s + 1, c ) + (*s == c);
}
void add_every_variable(gpointer key,gpointer value,gpointer userdata)
{
        struct ListOfEntries*iterator=value;
        while(iterator)
        {
                if(strcmp(iterator->value->scope,classScope)==0 && strcmp(iterator->value->whatIs,"class-variable")==0)
                {
                        char*customName=malloc(strlen(objName)+strlen(iterator->value->name)+2);
                        strcpy(customName,objName);
                        strcat(customName,".");
                        strcat(customName,iterator->value->name);
                        if(objVars==NULL)
                        {
                                
                                objVars=malloc(sizeof(struct ListOfEntries)); 
                                struct SymTabEntry*newEntry=malloc(sizeof(struct SymTabEntry));
                                newEntry->name=malloc(strlen(customName)+1);
                                newEntry->dataType=malloc(strlen(iterator->value->dataType)+1);
                                newEntry->scope=malloc(strlen(head->currentScope)+1);
                                strcpy(newEntry->dataType,iterator->value->dataType);
                                strcpy(newEntry->scope,head->currentScope);
                                strcpy(newEntry->name,customName);
                                if(iterator->value->initialised==1)
                                        newEntry->initialised=1;
                                else newEntry->initialised=0;
                                objVars->value=newEntry;
                                objVars->next=NULL;
                        }
                        else
                        {
                                struct ListOfEntries*newNode=malloc(sizeof(struct ListOfEntries));
                                struct SymTabEntry*newEntry=malloc(sizeof(struct SymTabEntry));
                                newEntry->name=malloc(strlen(customName)+1);
                                newEntry->dataType=malloc(strlen(iterator->value->dataType)+1);
                                newEntry->scope=malloc(strlen(head->currentScope)+1);
                                strcpy(newEntry->dataType,iterator->value->dataType);
                                strcpy(newEntry->scope,head->currentScope);
                                strcpy(newEntry->name,customName);
                                if(iterator->value->initialised)
                                        newEntry->initialised=1;
                                else newEntry->initialised=0;
                                newNode->value=newEntry;
                                newNode->next=objVars;
                                objVars=newNode;

                        }
                        
                }
                iterator=iterator->next;
        }
}

%}

%union 
{
        int type;
        char*strname;
        int intval;
        char* strval;
        char*boolVal;
        char charval;
        float floatval;
        struct expr_info* expr_ptr;
        struct eval_expr*eval_info;
}

%start start_program
%token START END ASSIGN IF ELSEIF WHILE FOR STRCPY STRLEN STRCMP STRCAT ADD DIV BIGGER SMALLER MIN MUL EQUAL OPEN_ROUND_BRACKET CLOSE_ROUND_BRACKET CLOSE_CURLY_BRACKET OPEN_CURLY_BRACKET INCR CLASS MAIN ELSE SMALLER_EQUAL GREATER_EQUAL STRING_TYPE CONST RETURN AND OR NOT EVAL
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
%left GREATER_EQUAL
%left SMALLER_EQUAL
%left NOT
%left AND
%left OR


%token<strname> ID
%token<intval> INT_VAL;
%token<strval> STRING_VAL
%token<floatval> FLOAT_VAL
%token<charval> CHAR_VAL
%token<type> INT STRING FLOAT CHAR BOOL VOID
%token<boolVal> BOOL_TRUE BOOL_FALSE
%type<type> available_types 
%type<expr_ptr> expression object_call_function function_call object_access_var access_vector string_functions return_statement
%type<eval_info> int_arithmetic eval_supported_value

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
                    | ';'create_variable 
                    ;


object_declaration: ID CLASS OPEN_CURLY_BRACKET {add_class_node($1);inClass=1;}object_content CLOSE_CURLY_BRACKET  {remove_node();inClass=0;}
                   | ID CLASS OPEN_CURLY_BRACKET {add_class_node($1);inClass=1;}CLOSE_CURLY_BRACKET {remove_node();inClass=0;}
                   ;

object_content:object_content inside_object 
              | inside_object
              ; 

inside_object:function_declaration
             | ';'create_variable 
             ; 
                    
function_declaration: OPEN_ROUND_BRACKET list_param CLOSE_ROUND_BRACKET ID available_types  OPEN_CURLY_BRACKET {inArgs=0;add_func_node($4,return_type($5));} function_content return_statement CLOSE_CURLY_BRACKET {
                        remove_node();
                        if(strcmp($9->type,"")!=0)
                        {
                                
                                if(strcmp($9->type,return_type($5)) && (strcmp(return_type($5),"void")!=0))
                                {
                                        printf("Tipul valoarii de return a functiei [%s] nu se potriveste cu tipul de return declarat al functiei!\n",$4);
                                        exit(EXIT_FAILURE);
                                }
                        }
                        }
                    | OPEN_ROUND_BRACKET list_param CLOSE_ROUND_BRACKET ID available_types OPEN_CURLY_BRACKET {inArgs=0;add_func_node($4,return_type($5));} return_statement CLOSE_CURLY_BRACKET {
                            remove_node();
                        if(strcmp($8->type,"")!=0)
                        {
                                
                                if(strcmp($8->type,return_type($5)) && (strcmp(return_type($5),"void")!=0))
                                {
                                        printf("Tipul valoarii de return a functiei [%s] nu se potriveste cu tipul de return declarat al functiei!\n",$4);
                                        exit(EXIT_FAILURE);
                                }
                        }
                            }
                    | OPEN_ROUND_BRACKET CLOSE_ROUND_BRACKET ID available_types OPEN_CURLY_BRACKET {inArgs=0;noArgs=1;add_func_node($3,return_type($4));} function_content return_statement CLOSE_CURLY_BRACKET {remove_node();
                         if(strcmp($8->type,"")!=0)
                        {
                                
                                if(strcmp($8->type,return_type($4)) && (strcmp(return_type($4),"void")!=0))
                                {
                                        printf("Tipul valoarii de return a functiei [%s] nu se potriveste cu tipul de return declarat al functiei!\n",$3);
                                        exit(EXIT_FAILURE);
                                }
                        }
                    }
                    | OPEN_ROUND_BRACKET CLOSE_ROUND_BRACKET ID available_types OPEN_CURLY_BRACKET {inArgs=0;noArgs=1;add_func_node($3,return_type($4));} return_statement CLOSE_CURLY_BRACKET {remove_node();
                         if(strcmp($7->type,"")!=0)
                        {
                                
                                if(strcmp($7->type,return_type($4)) && (strcmp(return_type($4),"void")!=0))
                                {
                                        printf("Tipul valoarii de return a functiei [%s] nu se potriveste cu tipul de return declarat al functiei!\n",$3);
                                        exit(EXIT_FAILURE);
                                }
                        }
                    }
                    ;

return_statement:RETURN expression {$$=$2;}
                | {$$=create_expression("","");}
                ;

list_param:  list_param ',' create_single_variable
           | {inArgs=1;} create_single_variable 
           ;

function_content: function_content statements
                | statements
                ;

multiple_statements:multiple_statements statements
                     | statements
                     ;

statements:   if_statement
            | while_statement
            | for_statement
            | ';'eval_statement
            | ';'assign_statement
            | ';'create_variable 
            | ';'function_call
            | ';'object_call_function
            | ';'string_functions
            ;

eval_statement:'[' int_arithmetic ']' EVAL
              ;

int_arithmetic:int_arithmetic ADD int_arithmetic  {$$=create_eval_expression("",$1->intvalue+$3->intvalue);printf("Rezultat:%i\n",$$->intvalue);}
              | int_arithmetic MIN int_arithmetic {$$=create_eval_expression("",$1->intvalue-$3->intvalue);printf("Rezultat:%i\n",$$->intvalue);}
              | int_arithmetic MUL int_arithmetic {$$=create_eval_expression("",$1->intvalue*$3->intvalue);printf("Rezultat:%i\n",$$->intvalue);}
              | int_arithmetic DIV int_arithmetic {$$=create_eval_expression("",$1->intvalue/$3->intvalue);printf("Rezultat:%i\n",$$->intvalue);}
              | OPEN_ROUND_BRACKET int_arithmetic CLOSE_ROUND_BRACKET {$$=create_eval_expression("",$2->intvalue);}
              | eval_supported_value
              ;

eval_supported_value:INT_VAL {$$=create_eval_expression("",$<intval>1);}
                    ;

string_functions: STRCPY OPEN_ROUND_BRACKET expression expression CLOSE_ROUND_BRACKET
          | STRLEN OPEN_ROUND_BRACKET expression CLOSE_ROUND_BRACKET
          | STRCAT OPEN_ROUND_BRACKET expression expression CLOSE_ROUND_BRACKET
          ;

function_call:'#'OPEN_ROUND_BRACKET list_call CLOSE_ROUND_BRACKET  ID 
                {
                      struct Checker*iterator=head;
                      int funcFound=0;
                      char*eString=malloc(strlen(typesOfCall)+strlen($5)+3);
                      strcpy(eString,"(");
                      strcat(eString,typesOfCall);
                      strcat(eString,")");
                      strcat(eString,$5);
                      while(iterator)
                      {
                              struct ListOfEntries*searchList=g_hash_table_lookup(iterator->localScope,$5);
                              struct ListOfEntries*iteratorList=searchList;
                              while(iteratorList)
                              {
                                      if(!inClass)
                                      {
                                        if((strcmp(iteratorList->value->whatIs,"function-declaration")==0) && (strcmp(iteratorList->value->name,$5)==0) && (strcmp(iteratorList->value->paramlist,typesOfCall)==0))
                                        {
                                                funcFound=1;
                                                $$=create_expression(iteratorList->value->dataType,eString);
                                                break;
                                        }
                                        else
                                        {
                                                printf("Functie:%s \t Apel:%s \t Args:%s \n",iteratorList->value->name,typesOfCall,iteratorList->value->paramlist);
                                        }
                                      }
                                      else
                                      {
                                        if((strcmp(iteratorList->value->whatIs,"function-declaration")==0 || (strcmp(iteratorList->value->whatIs,"class-function-declaration")==0)) && (strcmp(iteratorList->value->name,$5)==0) && (strcmp(iteratorList->value->paramlist,typesOfCall)==0))
                                        {
                                                funcFound=1;
                                                $$=create_expression(iteratorList->value->dataType,eString);
                                                break;
                                        }
                                      }
                                        
                                      iteratorList=iteratorList->next;
                                      
                              }

                              iterator=iterator->next;
                      }
                        
                        
                        if(!funcFound)
                        {
                                printf("Functia [%s] pe care ati apelat-o nu este definita!\n",$5);
                                exit(EXIT_FAILURE);
                        }
                        
                        free(typesOfCall);
                        free(eString);
                        eString=NULL;
                        typesOfCall=NULL;
                }

list_call:list_call ',' expression      
        {
         if(typesOfCall==NULL)
                {
                        typesOfCall=malloc(strlen($3->type)+1);
                        strcpy(typesOfCall,$3->type);
                        typesOfCall[strlen(typesOfCall)]='\0';
                }
                else
                {
                        char*temp_var=realloc(typesOfCall,strlen(typesOfCall)+strlen($3->type)+2);
                        strcat(temp_var,",");
                        strcat(temp_var,$3->type);
                        typesOfCall=temp_var;
                        typesOfCall[strlen(typesOfCall)]='\0';
                }
        }
         | expression
         {
               typesOfCall=malloc(strlen($1->type)+1);
               strcpy(typesOfCall,$1->type);
         }
         | {
            typesOfCall=malloc(1);
            typesOfCall[0]='\0';
         
         }
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

assign_statement: expression ASSIGN ID 
                {
                        int varFound=0;
                        struct Checker*iterator=head;
                        char*retType;
                        while(iterator)
                        {
                                struct ListOfEntries*searchList=g_hash_table_lookup(iterator->localScope,$3);
                                struct ListOfEntries*saveList=NULL;
                                while(searchList)
                                {
                                        if(saveList==NULL)
                                        {
                                                saveList=malloc(sizeof(struct ListOfEntries));
                                                saveList->next=NULL;
                                                saveList->value=searchList->value;
                                        }
                                        else
                                        {
                                                struct ListOfEntries*newNode=malloc(sizeof(struct ListOfEntries));
                                                newNode->value=searchList->value;
                                                newNode->next=saveList;
                                                saveList=newNode;
                                        }
                                        struct ListOfEntries*newNode;
                                        if(!inClass)
                                        {
                                                if((strcmp(searchList->value->name,$3)==0) && (strcmp(searchList->value->scope,iterator->currentScope)==0) && (strcmp(searchList->value->whatIs,"variable")==0))
                                                {
                                                        varFound=1;
                                                        retType=malloc(strlen(searchList->value->dataType)+1);
                                                        strcpy(retType,searchList->value->dataType);
                                                        saveList->value->initialised=1;
                                                        
                                                }
                                        }
                                        else
                                        {
                                                 if((strcmp(searchList->value->name,$3)==0) && (strcmp(searchList->value->scope,iterator->currentScope)==0) && ((strcmp(searchList->value->whatIs,"variable")==0) || (strcmp(searchList->value->whatIs,"class-variable")==0)))
                                                {
                                                        varFound=1;
                                                        retType=malloc(strlen(searchList->value->dataType)+1);
                                                        strcpy(retType,searchList->value->dataType);
                                                        saveList->value->initialised=1;
                                                }
                                        }
                                        searchList=searchList->next;
                                }
                                if(varFound)
                                {
                                        g_hash_table_replace(iterator->localScope,$3,saveList);
                                        break;
                                }

                                iterator=iterator->next;
                        }
                        if(!varFound)
                        {
                                printf("Variabila [%s] nu este declarata!\n",$3);
                                exit(EXIT_FAILURE);
                        }
                        if(strstr(retType,"const"))
                        {
                                printf("Variabila [%s] este de tipul [%s],valoarea sa nu poate fi modificata!\n",$3,retType);
                                exit(EXIT_FAILURE);
                        }
                        if(strcmp(retType,$1->type)!=0)
                        {
                                printf("Expresia [%s]-[%s] nu poate fi asignata variabilei [%s]-[%s]!\n",$1->expString,$1->type,$3,retType);
                                exit(EXIT_FAILURE);
                        }
                        free(retType);
                        retType=NULL;
                        
                        
                }
                | expression ASSIGN ID'.'ID
                {
                        struct Checker*iterator=head;
                        int objectFound=0;
                        char*retType;
                        while(iterator)
                        {
                                struct ListOfEntries*searchList=g_hash_table_lookup(iterator->localScope,$5);
                                while(searchList)
                                {
                                        if((strcmp(searchList->value->name,$5)==0) && (strcmp(searchList->value->whatIs,"object-variable")==0) && (strcmp(searchList->value->scope,iterator->currentScope)==0))
                                        {
                                                objectFound=1;
                                                break;
                                        }
                                        searchList=searchList->next;
                                }
                                iterator=iterator->next;
                        }
                        if(!objectFound)
                        {
                                printf("Identificatorul [%s] nu reprezinta un obiect!\n",$3);
                                exit(EXIT_FAILURE);
                        }
                        char*searchInstance=malloc(strlen($3)+strlen($5)+2);
                        strcpy(searchInstance,$5);
                        strcat(searchInstance,".");
                        strcat(searchInstance,$3);
                        searchInstance[strlen(searchInstance)]='\0';
                        iterator=head;
                        int instanceFound=0;
                        while(iterator)
                        {
                                struct ListOfEntries*searchList=g_hash_table_lookup(iterator->localScope,searchInstance);
                                struct ListOfEntries*saveList=NULL;
                                while(searchList)
                                {
                                        if(saveList==NULL)
                                        {
                                                saveList=malloc(sizeof(struct ListOfEntries));
                                                saveList->next=NULL;
                                                saveList->value=searchList->value;
                                        }
                                        else
                                        {
                                                struct ListOfEntries*newNode=malloc(sizeof(struct ListOfEntries));
                                                newNode->value=searchList->value;
                                                newNode->next=saveList;
                                                saveList=newNode;
                                        }
                                       if(!inClass)
                                       {
                                               
                                               if((strcmp(searchList->value->whatIs,"variable")==0) && (strcmp(searchList->value->scope,iterator->currentScope)==0) && (strcmp(searchList->value->name,searchInstance)==0))
                                               {
                                                       instanceFound=1;;
                                                       retType=malloc(strlen(searchList->value->dataType)+1);
                                                       strcpy(retType,searchList->value->dataType);
                                                       retType[strlen(retType)]='\0';
                                                       saveList->value->initialised=1;
                                               }
                                       }
                                       else
                                        {
                                              if(((strcmp(searchList->value->whatIs,"variable")==0) || (strcmp(searchList->value->whatIs,"class-variable")==0))&& (strcmp(searchList->value->scope,iterator->currentScope)==0) && (strcmp(searchList->value->name,searchInstance)==0))
                                               {
                                                       instanceFound=1;
                                                       retType=malloc(strlen(searchList->value->dataType)+1);
                                                       strcpy(retType,searchList->value->dataType);
                                                       retType[strlen(retType)]='\0';
                                                       saveList->value->initialised=1;
                                               }
                                        }
                                        searchList=searchList->next;
                                }
                                if(instanceFound)
                                {
                                        g_hash_table_replace(iterator->localScope,searchInstance,saveList);
                                        break;
                                }
                                iterator=iterator->next;
                        }
                        if(!instanceFound)
                        {
                                printf("Variabila [%s] nu este variabila membra a obiectului [%s]\n",$3,$5);
                                exit(EXIT_FAILURE);
                        }
                        if(strcmp($1->type,retType)!=0)
                        {
                                printf("Expresia [%s]-[%s] nu poate fi asignata [%s]-[%s]!\n",$1->expString,$1->type,searchInstance,retType);
                                exit(EXIT_FAILURE);
                        }
                        free(retType);
                        retType=NULL ;
                        searchInstance=NULL;

                }

                | expression ASSIGN '['expression']'ID
                {
                int exists=0;
                struct Checker*iterator=head;
                char*retType;
                while(iterator && !exists)
                {
                        struct ListOfEntries*searchList;
                        if(searchList=g_hash_table_lookup(iterator->localScope,$6))
                        {
                                while(searchList)
                                {
                                        if(strstr(searchList->value->dataType,"[") && strstr(searchList->value->dataType,"]") && strcmp(searchList->value->name,$6)==0)
                                        {
                                                char*extChar;
                                                int noChr=strcspn(searchList->value->dataType,"[");
                                                extChar=malloc(noChr+1);
                                                strncpy(extChar,searchList->value->dataType,noChr);
                                                retType=malloc(strlen(extChar)+1);
                                                strcpy(retType,extChar);
                                                exists=1;
                                                break;
                                        } 
                                        searchList=searchList->next;
                                }
                        }
                        iterator=iterator->next;
                }
                if(!exists)
                {
                        printf("Identificatorul [%s] nu defineste un vector!\n",$6);
                        exit(EXIT_FAILURE);

                }
                if(strcmp($4->type,"int")!=0)
                {
                        printf("Pozitia pe care ati incercat sa o accesati din vectorul [%s] nu exista!\n",$6);
                        exit(EXIT_FAILURE);
                }
                }
                ;


for_statement: OPEN_ROUND_BRACKET assign_statement ';' expression ';' expression CLOSE_ROUND_BRACKET FOR OPEN_CURLY_BRACKET {add_statement_node();}multiple_statements CLOSE_CURLY_BRACKET {remove_node();}
             ;

create_variable: create_single_variable 
               | '$'create_array_variable
               ;



create_array_variable:'['expression']' ID available_types {
                                 
                                 char*customType=malloc(strlen(return_type($5))+strlen("50"));
                                 if((strcmp($2->type,"int")!=0))
                                 {
                                         printf("Ati incercat sa declarati un vector [%s] cu un numar maxim de elemente invalid [%s]-[%s]!\n",$4,$2->expString,$2->type);
                                         exit(EXIT_FAILURE);
                                 }
                                 strcpy(customType,return_type($5));
                                 strcat(customType,"[");
                                 strcat(customType,"50");
                                 strcat(customType,"]");
                                 add_new_variable(customType,$4,1 );
                        }
                     ;
create_single_variable:  '$' ID available_types {
                       
                        add_new_variable(return_type($3),$2,0);
                        }
                        |'$' ID ID {
                            
                             struct Checker*iterator=head;
                             int clsFound=0;
                             while(iterator->next!=NULL)
                             {
                                     iterator=iterator->next;
                             }
                             struct ListOfEntries*searchList=g_hash_table_lookup(iterator->localScope,$3);
                             while(searchList)
                             {
                                     if(strcmp(searchList->value->whatIs,"class-declaration")==0)
                                     {
                                        classScope=malloc(strlen(searchList->value->scope)+1);
                                        strcpy(classScope,searchList->value->scope);
                                        classScope[strlen(classScope)]='\0';
                                        objName=malloc(strlen($2)+1);
                                        strcpy(objName,$2);
                                        objName[strlen(objName)]='\0';
                                        clsFound=1;
                                        break;
                                     }
                                     searchList=searchList->next;
                             }
                             if(!clsFound)
                             {
                                     printf("Clasa [%s] pe care doriti sa o instantiati nu este declarata!\n",$3);
                                     exit(EXIT_FAILURE);
                             }
                             objInstance=1;
                             add_new_variable($3,$2,0);
                             objInstance=0;
                             g_hash_table_foreach(iterator->localScope,add_every_variable,NULL);
                             free(classScope);
                             classScope=NULL;
                             struct ListOfEntries *iteratorVars=objVars;
                             while(iteratorVars)
                             {
                                     add_new_variable(iteratorVars->value->dataType,iteratorVars->value->name,iteratorVars->value->initialised);
                                     iteratorVars=iteratorVars->next;
                             }
                             free_entry(objVars);
                             free(objName);
                             free(classScope);
                             classScope=NULL;
                             objName=NULL;
                             objVars=NULL;
                        }
                        |'$' expression ASSIGN ID available_types {
                                add_new_variable(return_type($5),$4,1);
                                if(strcmp($2->type,return_type($5))!=0)
                                {
                                        printf("Expresia [%s]-[%s] nu poate fi asignata variabilei [%s]-[%s]!\n",$2->expString,$2->type,$4,return_type($5));
                                        exit(EXIT_FAILURE);
                                }
                        }
                        |'$' expression ASSIGN ID available_types CONST {
                                char*newtype=malloc(strlen("const-")+strlen(return_type($5))+1);
                                strcpy(newtype,"const-");
                                strcat(newtype,return_type($5));
                                newtype[strlen(newtype)]='\0';
                                add_new_variable(newtype,$4,1);
                                if(strcmp($2->type,return_type($5))!=0)
                                {
                                        printf("Variabila [%s]-tip[const-%s] nu poate fi initializata cu o expresie[%s]-tip[%s]",$4,return_type($5),$2->expString,$2->type);
                                        exit(EXIT_FAILURE);
                                }
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

expression: ID {
            int initialised=0;
            int exists=0;
            int line;
            char*retType;
                struct Checker*iterator=head;
                while(iterator)
                {
                        struct ListOfEntries*searchList=g_hash_table_lookup(iterator->localScope,$1);
                        while(searchList)
                        {
                                if(strcmp(searchList->value->name,$1)==0 && strcmp(searchList->value->whatIs,"variable")==0 && strcmp(searchList->value->scope,iterator->currentScope)==0)
                                {
                                        exists=1;
                                        if(searchList->value->initialised)
                                           initialised=1;
                                        if(exists || initialised)
                                        {
                                          retType=malloc(strlen(searchList->value->dataType)+1);
                                          strcpy(retType,searchList->value->dataType);
                                          break;
                                        }
                                }
                                searchList=searchList->next;
                        }
                        iterator=iterator->next;
                }
            
            if(!exists)
            {
                printf("Variabila [%s] nu este declarata!\n",$1);
                exit(EXIT_FAILURE);
            }   
            if(!initialised)
            {
                    printf("Variabila [%s] este definita insa nu si initializata in expresia[%s]!\n",$1,$$->expString);
                    exit(EXIT_FAILURE);
            }
            $$=create_variable_expression($1,retType);
        }       
          | INT_VAL {$$=create_int_expression($1);}
          | FLOAT_VAL {$$=create_float_expression($1);}
          | BOOL_TRUE {$$=create_bool_expression($1);}
          | BOOL_FALSE {$$=create_bool_expression($1);}
          | STRING_VAL {$$=create_string_expression($1);}
          | CHAR_VAL {$$=create_char_expression($1);}
          | function_call {$$=$1;}
          | object_call_function {$$=$1;}
          | object_access_var {$$=$1;}
          | access_vector {$$=$1;}
          | OPEN_ROUND_BRACKET expression CLOSE_ROUND_BRACKET {$$=create_paranthesis_expression($2);}
          | expression ADD expression 
                {
                        if((strcmp($1->type,"char*")==0) || (strcmp($3->type,"char*")==0))
                        {
                                printf("Nu se poate efectua operatia de adunare pe tipul [*rahc]\n%s+%s\n",$1->expString,$3->expString);
                                exit(EXIT_FAILURE);
                        }
                        if(strcmp($1->type,$3->type)!=0)
                        {
                                printf("Nu se poate efectua operatia de adunare pe tipul [%s] si tipul [%s] \n%s+%s\n",$1->expString,$3->expString,$1->expString,$3->expString);
                                exit(EXIT_FAILURE);
                        }

                }
          | expression MUL expression
          | expression DIV expression
          | expression MIN expression
          | expression BIGGER expression
          | expression SMALLER expression
          | expression EQUAL expression
          | expression SMALLER_EQUAL expression
          | expression GREATER_EQUAL expression
          | expression AND expression
          | expression OR expression
          | NOT expression
          ;


object_call_function:'#'OPEN_ROUND_BRACKET list_call CLOSE_ROUND_BRACKET ID '.' ID
                        {

                                struct Checker*iterator=head;
                                int objFound=0;
                                int funcFound=0;
                                char*objClass=NULL;
                                char*scopeOf=NULL;
                                char*eString;
                                eString=malloc(strlen(typesOfCall)+strlen($5)+strlen($7)+4);
                                strcpy(eString,"(");
                                strcat(eString,typesOfCall);
                                strcat(eString,")");
                                strcat(eString,$5);
                                strcat(eString,".");
                                strcat(eString,$7);
                                eString[strlen(eString)]='\0';
                                while(iterator && !objFound)
                                {
                                        struct ListOfEntries*searchList=g_hash_table_lookup(iterator->localScope,$7);
                                        while(searchList)
                                        {
                                                if((strcmp(searchList->value->whatIs,"object-variable")==0) && (strcmp(searchList->value->name,$7)==0) && (strcmp(searchList->value->scope,iterator->currentScope)==0))
                                                {
                                                        objFound=1;
                                                        objClass=malloc(strlen(searchList->value->dataType)+1);
                                                        strcpy(objClass,searchList->value->dataType);
                                                        objClass[strlen(objClass)]='\0';
                                                        break;
                                                }
                                                searchList=searchList->next;

                                        }
                                        iterator=iterator->next;
                                }
                                if(!objFound)
                                {
                                        printf("Identificatorul [%s] nu desemneaza un obiect!\n",$7);
                                        exit(EXIT_FAILURE);
                                }
                                iterator=head;
                                while(iterator)
                                {
                                        struct ListOfEntries*searchList=g_hash_table_lookup(iterator->localScope,objClass);
                                        while(searchList)
                                        {
                                                if((strcmp(searchList->value->whatIs,"class-declaration")==0) && (strcmp(searchList->value->name,objClass)==0))
                                                {
                                                        scopeOf=malloc(strlen(searchList->value->scope)+1);
                                                        strcpy(scopeOf,searchList->value->scope);
                                                        scopeOf[strlen(scopeOf)]='\0';
                                                        break;
                                                }
                                                searchList=searchList->next;
                                        }
                                        iterator=iterator->next;
                                }
                                iterator=head;
                                 while(iterator)
                                {
                                        struct ListOfEntries*searchList=g_hash_table_lookup(iterator->localScope,$5);
                                        while(searchList)
                                        {
                                                if((strcmp(searchList->value->whatIs,"class-function-declaration")==0) && (strcmp(searchList->value->name,$5)==0) && (strstr(searchList->value->scope,scopeOf)) && (strcmp(typesOfCall,searchList->value->paramlist)==0))
                                                {
                                                        funcFound=1;
                                                        $$=create_expression(searchList->value->dataType,eString);
                                                        break;
                                                }
                                                searchList=searchList->next;
                                        }
                                        iterator=iterator->next;
                                }
                                if(!funcFound)
                                {
                                        printf("Functia [%s] nu este functie membra a clasei [%s]!\n",$5,objClass);
                                        exit(EXIT_FAILURE);
                                }
                                free(objClass);
                                free(scopeOf);
                                free(typesOfCall);
                                typesOfCall=NULL;
                                
                        }
                       
                ;

object_access_var:ID'.'ID
                {
                        struct Checker*iterator=head;
                        int objectFound=0;
                        while(iterator)
                        {
                                struct ListOfEntries*searchList=g_hash_table_lookup(iterator->localScope,$3);
                                while(searchList)
                                {
                                        if((strcmp(searchList->value->name,$3)==0) && (strcmp(searchList->value->whatIs,"object-variable")==0) && (strcmp(searchList->value->scope,iterator->currentScope)==0))
                                        {
                                                objectFound=1;
                                                break;
                                        }
                                        searchList=searchList->next;
                                }
                                iterator=iterator->next;
                        }
                        if(!objectFound)
                        {
                                printf("Identificatorul [%s] nu reprezinta un obiect!\n",$3);
                                exit(EXIT_FAILURE);
                        }
                        char*searchInstance=malloc(strlen($1)+strlen($3)+2);
                        strcpy(searchInstance,$3);
                        strcat(searchInstance,".");
                        strcat(searchInstance,$1);
                        searchInstance[strlen(searchInstance)]='\0';
                        iterator=head;
                        int instanceFound=0;
                        while(iterator)
                        {
                                struct ListOfEntries*searchList=g_hash_table_lookup(iterator->localScope,searchInstance);
                                while(searchList)
                                {
                                       if(!inClass)
                                       {
                                               
                                               if((strcmp(searchList->value->whatIs,"variable")==0) && (strcmp(searchList->value->scope,iterator->currentScope)==0) && (strcmp(searchList->value->name,searchInstance)==0))
                                               {
                                                       instanceFound=1;
                                                       $$=create_expression(searchList->value->dataType,searchInstance);
                                                       break;
                                               }
                                       }
                                       else
                                        {
                                              if(((strcmp(searchList->value->whatIs,"variable")==0) || (strcmp(searchList->value->whatIs,"class-variable")==0))&& (strcmp(searchList->value->scope,iterator->currentScope)==0) && (strcmp(searchList->value->name,searchInstance)==0))
                                               {
                                                       instanceFound=1;
                                                       $$=create_expression(searchList->value->dataType,searchInstance);
                                                       break;
                                               }
                                        }
                                        searchList=searchList->next;
                                }
                                iterator=iterator->next;
                        }
                        if(!instanceFound)
                        {
                                printf("Variabila [%s] nu este variabila membra a obiectului [%s]\n",$1,$3);
                                exit(EXIT_FAILURE);
                        }
                        free(searchInstance);
                        searchInstance=NULL;
                }

access_vector:'['expression']' ID {
                int exists=0;
                struct Checker*iterator=head;
                char*retType;
                while(iterator && !exists)
                {
                        struct ListOfEntries*searchList;
                        if(searchList=g_hash_table_lookup(iterator->localScope,$4))
                        {
                                while(searchList)
                                {
                                        if(strstr(searchList->value->dataType,"[") && strstr(searchList->value->dataType,"]") && strcmp(searchList->value->name,$4)==0)
                                        {
                                                char*extChar;
                                                int noChr=strcspn(searchList->value->dataType,"[");
                                                extChar=malloc(noChr+1);
                                                strncpy(extChar,searchList->value->dataType,noChr);
                                                retType=malloc(strlen(extChar)+1);
                                                strcpy(retType,extChar);
                                                exists=1;
                                                break;
                                        } 
                                        searchList=searchList->next;
                                }
                        }
                        iterator=iterator->next;
                }
                if(!exists)
                {
                        printf("Identificatorul [%s] nu defineste un vector!",$4);
                        exit(EXIT_FAILURE);

                }
                if(strcmp($2->type,"int")!=0)
                {
                        printf("Pozitia pe care ati incercat sa o accesati din vectorul [%s] nu exista!\n",$4);
                        exit(EXIT_FAILURE);
                }

                  char*eString=malloc(3+strlen($2->expString)+strlen($4));
                  strcpy(eString,"[");
                  strcat(eString,$2->expString);
                  strcat(eString,"]");
                  strcat(eString,$4);
                $$=create_expression(retType,eString);
                }
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
}
void free_entry(struct ListOfEntries*val)
{
        struct ListOfEntries*temp;
        while(val)
        {
                temp=val;
                val=val->next;
                g_free(temp);
        }
}
void free_checker(struct Checker*val)
{
        struct Checker*temp;
        while(val)
        {
                temp=val;
                val=val->next;
                g_free(temp);
        }
}
void add_func_node(char*identifier,const char*returntype)
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
        if(inClass==1)
        {
              newEntry->whatIs=malloc(strlen("class-function-declaration")+1);
                strcpy(newEntry->whatIs,"class-function-declaration");  
        }
        else
        {
                newEntry->whatIs=malloc(strlen("function-declaration")+1);
                strcpy(newEntry->whatIs,"function-declaration");
        }
        newEntry->whatIs[strlen(newEntry->whatIs)]='\0';
        newEntry->scope=malloc(strlen(head->currentScope)+1);
        strcpy(newEntry->scope,head->currentScope);
        newEntry->scope[strlen(newEntry->scope)]='\0';
        newEntry->lineOf=yylineno;
        struct ListOfEntries*iterator=funcArgs;
        int numChar=0;
        while(iterator)
        {
                numChar+=strlen(iterator->value->dataType)+1;
                iterator=iterator->next;
        }
        newEntry->paramlist=malloc(numChar+1);
        iterator=funcArgs;
        while(iterator)
        {
                strcat(newEntry->paramlist,iterator->value->dataType);
                strcat(newEntry->paramlist,",");
                iterator=iterator->next;
        }
        newEntry->paramlist[strlen(newEntry->paramlist)-1]='\0';
        newEntry->paramlist[strlen(newEntry->paramlist)]='\0';
        
        struct ListOfEntries*val;
        if((val=g_hash_table_lookup(head->next->localScope,identifier)))
        {
                while(val)
                {
                        if(strncmp(val->value->scope,newEntry->scope,strlen(newEntry->scope)-nLenght)==0 && ((strcmp(val->value->whatIs,"function-declaration")==0) || (strcmp(val->value->whatIs,"class-function-declaration")==0)) && strcmp(val->value->paramlist,newEntry->paramlist)==0)
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
                if(funcArgs)
                {
                        struct ListOfEntries*iterator=funcArgs;
                        char*parList;
                        while(iterator)
                        {
                                add_new_variable(iterator->value->dataType,iterator->value->name,1);
                                iterator=iterator->next;
                        }
                }
                struct ListOfEntries*tmp;
                while(iterator)
                {
                        tmp=iterator;
                        iterator=iterator->next;
                        free(tmp);
                }
                funcArgs=NULL;

}
void add_new_variable(const char*type,char*identifier,int init)
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
        if(inClass)
        {
                newEntry->whatIs=malloc(strlen("class-variable")+1);
                strcpy(newEntry->whatIs,"class-variable");
        }
        else
        {
                newEntry->whatIs=malloc(strlen("variable")+1);
                strcpy(newEntry->whatIs,"variable");
        }
         if(objInstance)
        {
                newEntry->whatIs=malloc(strlen("object-variable")+1);
                strcpy(newEntry->whatIs,"object-variable");
        }
        else
        {
                if(inClass==0)
                {
                        newEntry->whatIs=malloc(strlen("variable")+1);
                        strcpy(newEntry->whatIs,"variable");
                }
        }
        newEntry->whatIs[strlen(newEntry->whatIs)]='\0';
        newEntry->scope=malloc(strlen(head->currentScope)+1);
        strcpy(newEntry->scope,head->currentScope);
        newEntry->scope[strlen(newEntry->scope)]='\0';
        newEntry->lineOf=yylineno;
        newEntry->initialised=init;
        if(inArgs)
        {
                if(funcArgs==NULL)
                {
                   funcArgs=malloc(sizeof(struct ListOfEntries));
                   funcArgs->value=newEntry;
                   funcArgs->next=NULL;
                }
                else
                {
                       struct ListOfEntries*iterator=funcArgs;
                       struct ListOfEntries*newNode=malloc(sizeof(struct ListOfEntries));
                       newNode->value=newEntry;
                       while(iterator->next!=NULL)
                       {
                               iterator=iterator->next;
                       }
                       iterator->next=newNode;
                }
                return;
                   
        }
        struct ListOfEntries*val;
        if((val=g_hash_table_lookup(head->localScope,identifier)))
        {
                while(val)
                {
                        if(strcmp(val->value->scope,newEntry->scope)==0 && ((strcmp(val->value->whatIs,"variable")==0) || (strcmp(val->value->whatIs,"class-variable")==0)))
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
           if((strcmp(var->value->whatIs,"variable")==0) || (strcmp(var->value->whatIs,"class-variable")==0) || (strcmp(var->value->whatIs,"object-variable")==0))
           {
                   fprintf(SymTabDump,"%i \t %s \t %s\t %s \t %i \t %s \t %i \n",var->value->lineOf,var->value->name,var->value->whatIs,var->value->dataType,var->value->intvalue,var->value->scope,var->value->initialised);
           }
           if((strcmp(var->value->whatIs,"function-declaration")==0) || (strcmp(var->value->whatIs,"class-function-declaration")==0))
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
char* is_class_object(char*identifier)
{
                        struct Checker *allScope=head;
                        char*theScope=NULL;
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
                                                                                theScope=malloc(strlen(insideList->value->scope)+1);
                                                                                strcpy(theScope,insideList->value->scope);
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
                                return theScope;
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
struct expr_info*create_int_expression(int intValue)
{
        struct expr_info*newExp=malloc(sizeof(struct expr_info));
        newExp->type=malloc(strlen("int")+1);
        strcpy(newExp->type,"int");
        char toString[20];
        sprintf(toString,"%i",intValue);
        newExp->expString=malloc(strlen(toString)+1);
        strcpy(newExp->expString,toString);

        return newExp;
}
struct expr_info*create_bool_expression(const char*boolValue)
{
       struct expr_info*newExp=malloc(sizeof(struct expr_info));
       newExp->type=malloc(strlen("bool")+1);
       strcpy(newExp->type,"bool");
       newExp->expString=malloc(strlen(boolValue)+1);
       strcpy(newExp->expString,boolValue);
       return newExp;  
}
struct expr_info*create_float_expression(float floatValue)
{
        struct expr_info*newExp=malloc(sizeof(struct expr_info));
        newExp->type=malloc(strlen("float")+1);
        strcpy(newExp->type,"float");
        char toString[20];
        sprintf(toString,"%f",floatValue);
        newExp->expString=malloc(strlen(toString)+1);
        strcpy(newExp->expString,toString);
        return newExp;
}
struct expr_info*create_string_expression(char*stringValue)
{
       struct expr_info*newExp=malloc(sizeof(struct expr_info));
       newExp->type=malloc(strlen("char*"));
       strcpy(newExp->type,"char*");
       newExp->expString=malloc(strlen(stringValue)+1);
       strcpy(newExp->expString,stringValue);
       return newExp;  
}
struct expr_info*create_char_expression(const char charValue)
{
        struct expr_info*newExp=malloc(sizeof(struct expr_info));
        newExp->type=malloc(strlen("char")+1);
        strcpy(newExp->type,"char");
        newExp->expString=malloc(2);
        newExp->expString[0]=charValue;
        
        return newExp;
}
struct expr_info*create_variable_expression(const char*identifier,char*type)
{
        struct expr_info*newExp=malloc(sizeof(struct expr_info));
       newExp->type=malloc(strlen(type)+1);
       strcpy(newExp->type,type);
       newExp->expString=malloc(strlen(identifier)+1);
       strcpy(newExp->expString,identifier);
       return newExp;
}
struct expr_info*create_paranthesis_expression(struct expr_info*exp)
{
        struct expr_info*newExp=malloc(sizeof(struct expr_info));
        newExp->type=exp->type;
        newExp->expString=malloc(strlen(exp->expString)+3);
        strcat(newExp->expString,"(");
        strcat(newExp->expString,exp->expString);
        strcat(newExp->expString,")");
        return newExp;
}
struct expr_info*create_expression(char*type,char*eString)
{
        struct expr_info*newExp=malloc(sizeof(struct expr_info));
        newExp->type=malloc(strlen(type)+1);
        strcpy(newExp->type,type);
        newExp->expString=malloc(strlen(eString)+1);
        strcpy(newExp->expString,eString);
        return newExp;
}
struct eval_expr*create_eval_expression(char*name,int value)
{
        struct eval_expr*var=malloc(sizeof(struct eval_expr));
        bzero(var,sizeof(struct eval_expr));
        var->name=malloc(strlen(name)+1);
        strcpy(var->name,name);
        var->intvalue=value;
        return var;
}