#ifndef PACL_LEXER_H
#define PACL_LEXER_H

#include "token.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct LEXER_STRUCT{
    char* contents;
    size_t contents_size;
    char c;
    unsigned int i;
}lexer_T;

lexer_T* init_lexer(char* buff);

void lexer_skip(lexer_T* lexer);
char* to_string(lexer_T* lexer);
char* symbol_to_string(lexer_T* lexer);
token_T* lexer_get_token(lexer_T* lexer);
token_T* lexer_collect_string(lexer_T* lexer);
token_T* advance_lexer(lexer_T* lexer); //Function call for lexer in other files

#endif /* PACL_LEXER_H */