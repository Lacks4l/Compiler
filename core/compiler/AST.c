#include "include/AST.h"

AST_T* init_ast(int type){
    AST_T* ast = malloc(1*sizeof(struct AST_STRUCT));
    ast->type = type;
    
    // AST VARIABLE DEFINITION
    ast->variable_def_var_name = (void*)0;
    ast->variable_def_value = (void*)0;

    // AST VARIABLE CALL
    ast->variable_name = (void*)0;

    // AST FUNCTION CALL
    ast->function_def_type = (void*)0;
    ast->function_def_name = (void*)0;
    ast->argument_def_type = (void*)0;
    ast->argument_def_name = (void*)0;
    ast->function_def_argument_size = 0;

    // AST FUNCTION DEF
    ast->function_call_name = (void*)0;
    ast->function_call_arguments = (void*)0;

    // AST BASIC TYPES
    ast->int_value = (void*)0;
    ast->bool_value = (void*)0;
    ast->string_value = (void*)0;
    ast->char_value = (void*)0;

    // AST COMPOUND
    ast->compound_value = (void*)0;
    ast->compound_size = 0;

    if(type == AST_COMP0UND){
        ast->children = init_list(sizeof(struct AST_STRUCT*));
    }
}

