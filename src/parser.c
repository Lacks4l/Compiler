#include "include/parser.h"

#include <stdio.h>

parser_T* init_parser(lexer_T* lexer){
    parser_T* parser = malloc(1*sizeof(struct PARSER_STRUCT));
    parser->lexer = lexer;
    parser->current_token = advance_lexer(lexer);

    return parser;
}

void parser_eat(parser_T* parser, int token_type){
    if(parser->current_token->type==token_type){
        parser->current_token = advance_lexer(parser->lexer);
    }else{
        printf("Unexpected token %s with type %d", parser->current_token->value, parser->current_token->type);
        exit(1);
    }
}