#include "Include/token.h"

#include <stdlib.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

token_T* init_token(char* str, int type){
    token_T* token = malloc(1*sizeof(struct TOKENS_STRUCT));
    token->value=str;
    token->type = type;
    return token;
}