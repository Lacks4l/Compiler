#ifndef LEXER_H
#define LEXER_H

#include "token.h"
#include <stdio.h>

typedef struct LEXER_STRUCT{
    char* contents;
    char c;
    int i;
}lexer_T;

lexer_T* init_lexer(char* buff);

void lexer_skip(lexer_T* lexer);
int ischar(char c);
token_T* advance_lexer(lexer_T* lexer);
void lexer(char* file_name);


void file_print(token_T* token, FILE* fptr);

#endif /* LEXER_H */