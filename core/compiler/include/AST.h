#ifndef PACL_AST_H
#define PACL_AST_H

#include <stdlib.h>
#include "list.h"

typedef struct AST_STRUCT{
    enum{
        //FUNCTION TYPES
        AST_FUNCTION_DEF,
        AST_FUNCTION_CALL,          //0
        AST_ARGUMENT_DEFINITION,

        //VARIABLE TYPES
        AST_VARIABLE_DEFINITION,    //1
        AST_VARIABLE,               //2

        //BASIC TYPES
        AST_INT,                    //3
        AST_FLOAT,                  //4
        AST_DOUBLE,                 //5
        AST_BOOL,                   //6
        AST_STRING,                 //7
        AST_CHAR,                   //8

        //COMPOUND TYPES
        AST_COMP0UND                //9
    }type;

    // AST VARIABLE DEFINITION
    char* variable_def_var_name;
    struct AST_STRUCT* variable_def_value;

    // AST VARIABLE
    char* variable_name;

    // AST FUNCTION CALL
    char* function_call_name;
    char* function_call_argument;
    struct AST_STRUCT** function_call_arguments;
    size_t function_call_argument_size;

    // AST BASIC TYPES
    char* int_value;
    char* float_value;
    char* double_value;
    char* bool_value;
    char* string_value;
    char* char_value;

    // AST COMPOUND
    struct AST_STRUCT** compound_value;
    size_t compound_size;

    list_T* children;

}AST_T;

AST_T* init_ast(int type);

#endif /* PACL_AST_H */