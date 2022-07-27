#include "include/AST.h"

AST_T* init_ast(int type){
    AST_T* ast = malloc(1*sizeof(struct AST_STRUCT));
    // AST VARIABLE DEFINITION
    ast->variable_def_var_name = (void*)0;
    ast->variable_def_value = (void*)0;

    // AST VARIABLE
    ast->variable_name = (void*)0;

    // AST FUNCTION CALL
    ast->function_call_name = (void*)0;
    ast-> function_call_arguments = (void*)0;
    ast->function_call_argument_size = 0;

    // AST BASIC TYPES
    ast->int_value = (void*)0;
    ast->bool_value = (void*)0;
    ast->string_value = (void*)0;
    ast->char_value = (void*)0;

    // AST COMPOUND
    ast->compound_value = (void*)0;
    ast->compound_size = 0;
}