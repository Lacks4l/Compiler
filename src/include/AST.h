#ifndef AST_H
#define AST_H

#include <stdlib.h>

typedef struct AST_STRUCT{
    enum{
        AST_VARIABLE_DEFINITION,
        AST_VARIABLE,
        AST_FUNCTION_CALL,
        AST_STRING,
        AST_INT,
        AST_COMP0UND
    }type;

    // AST VARIABLE DEFINITION
    char* variable_def_var_name;
    struct AST_STRUCT* variable_def_value;

    // AST VARIABLE
    char* variable_name;

    // AST FUNCTION CALL
    char* function_call_name;
    struct AST_STRUCT** function_call_arguments;
    size_t function_call_argument_size;

    // AST BASIC TYPES
    char* int_value;
    char* bool_value;
    char* string_value;
    char* char_value;

    // AST COMPOUND
    struct AST_STRUCT** compound_value;
    size_t compound_size;

}AST_T;

AST_T* init_ast(int type);

#endif /* AST_H */