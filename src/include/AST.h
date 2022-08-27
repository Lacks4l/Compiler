#ifndef PACL_AST_H
#define PACL_AST_H

#include <stdlib.h>

typedef struct AST_STRUCT{
    enum{
        //FUNCTION TYPES
        AST_FUNCTION_CALL,

        //VARIABLE TYPES
        AST_VARIABLE_DEFINITION,
        AST_VARIABLE,

        //BASIC TYPES
        AST_INT,
        AST_FLOAT,
        AST_DOUBLE,
        AST_BOOL,
        AST_STRING,
        AST_CHAR,

        //COMPOUND TYPES
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
    char* float_value;
    char* double_value;
    char* bool_value;
    char* string_value;
    char* char_value;

    // AST COMPOUND
    struct AST_STRUCT** compound_value;
    size_t compound_size;

}AST_T;

AST_T* init_ast(int type);

#endif /* PACL_AST_H */