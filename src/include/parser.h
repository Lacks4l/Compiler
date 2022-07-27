#ifndef PARSER_H
#define PARSER_H

#include "lexer.h"
#include "AST.h"

#include <stdlib.h>

typedef struct PARSER_STRUCT{
    lexer_T* lexer;
    token_T* current_token;
}parser_T;

parser_T* init_parser(lexer_T* lexer);

void parser_eat(parser_T* parser, int token_type);

AST_T* parser_parse(parser_T* parser);
AST_T* parser_parse_statement(parser_T* parser);
AST_T* parser_parse_statements(parser_T* parser);
AST_T* parser_parse_expression(parser_T* parser);

AST_T* parser_parse_identifier(parser_T* parser);

AST_T* parser_parse_variable_def(parser_T* parser);
AST_T* parser_parse_variables(parser_T* parser);
AST_T* parser_parse_function_call(parser_T* parser);

AST_T* parser_parse_int(parser_T* parser);
AST_T* parser_parse_float(parser_T* parser);
AST_T* parser_parse_double(parser_T* parser);
AST_T* parser_parse_bool(parser_T* parser);
AST_T* parser_parse_string(parser_T* parser);
AST_T* parser_parse_char(parser_T* parser);
#endif /* PARSER_H */