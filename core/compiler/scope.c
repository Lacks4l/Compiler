#include "include/scope.h"

scope_T* init_scope() {
    scope_T* scope = malloc(1*sizeof(struct SCOPE_STRUCT));

    scope->function_defs = (void*)0;
    scope->function_defs_size = 0;

    scope->variable_defs = (void*)0;
    scope->variable_defs_size = 0;

    return scope;
}

AST_T* scope_add_function_definition(scope_T* scope, AST_T* fdef){
    scope->function_defs_size+=1;
    
}