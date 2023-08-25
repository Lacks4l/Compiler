#include "include/parser.h"
#include "include/AST.h"

#include <stdio.h>
#include <ctype.h>
#include <string.h>

parser_T* init_parser(lexer_T* lexer){
    parser_T* parser = malloc(1*sizeof(struct PARSER_STRUCT));
    parser->lexer = lexer;
    parser->current_token = advance_lexer(lexer);
    return parser;
}

void parser_eat(parser_T* parser, int token_type){
    //printf("%d, %d -> ", parser->current_token->type, token_type);
    if(parser->current_token->type==token_type){    
        printf("\"%s\", %d\n", parser->current_token->value, parser->current_token->type);
        parser->current_token = advance_lexer(parser->lexer);
    }else{
        printf("Unexpected token \"%s\" with type %d\n", parser->current_token->value, parser->current_token->type);
        exit(1);
    }
}   

//Function call for parser in Visitor
AST_T* parser_parse(parser_T* parser){
    return parser_parse_statements(parser);
}

AST_T* parser_parse_statement(parser_T* parser){
    if(parser->current_token->type = TOKEN_IDENTIFIER){
        return parser_parse_identifier(parser);
    }
}

AST_T* parser_parse_statements(parser_T* parser){
    AST_T* compound = init_ast(parser->current_token->type);

    compound->compound_value = malloc(1*sizeof(struct AST_STRUCT));

    AST_T* ast_statement = parser_parse_statement(parser);
    compound->compound_value[0] = ast_statement;

    while(parser->current_token->type == TOKEN_SEMICOLON){   
        parser_eat(parser, TOKEN_SEMICOLON);

        AST_T* ast_statement = parser_parse_statement(parser);
        compound->compound_size = 1;
        compound->compound_value = realloc(
            compound->compound_value, compound->compound_size + sizeof(struct AST_SRUCT*)
        );
        compound->compound_value[compound->compound_size-1] = ast_statement;
    }
}

AST_T* parser_parse_identifier(parser_T* parser){
    if(strcmp(parser->current_token->value, "fn") == 0) {
        return parser_parse_function_dec(parser);

    }else{
        return parser_parse_variable_def(parser);        
    }
    return parser_parse_variable(parser); 
}

AST_T* parser_parse_int(parser_T* parser){
    AST_T* ast_int = init_ast(AST_INT);
    ast_int->int_value = parser->current_token->value;

    parser_eat(parser, TOKEN_INTCONST);
    
    return ast_int;
}

AST_T* parser_parse_float(parser_T* parser){
    AST_T* ast_float = init_ast(AST_FLOAT);
    ast_float->float_value = parser->current_token->value;

    parser_eat(parser, TOKEN_FLOATCONST);

    return ast_float;
}

AST_T* parser_parse_double(parser_T* parser){
    AST_T* ast_double = init_ast(AST_DOUBLE);
    ast_double->int_value = parser->current_token->value;

    parser_eat(parser, TOKEN_DOUBLECONST);

    return ast_double;
}

AST_T* parser_parse_bool(parser_T* parser){
    AST_T* ast_bool = init_ast(AST_BOOL);
    ast_bool->int_value = parser->current_token->value;

    parser_eat(parser, TOKEN_BOOLCONST);

    return ast_bool;
}

AST_T* parser_parse_string(parser_T* parser){
    AST_T* ast_string = init_ast(AST_STRING);
    ast_string->int_value = parser->current_token->value;

    parser_eat(parser, TOKEN_STRINGCONST);

    return ast_string;
}

AST_T* parser_parse_char(parser_T* parser){
    AST_T* ast_char = init_ast(AST_CHAR);
    ast_char->int_value = parser->current_token->value;

    parser_eat(parser, TOKEN_CHARCONST);

    return ast_char;
}

parser_T* parser_parse_term(parser_T* parser){
    int num=1;
    if(isdigit(parser->current_token->value[0])){
        for(int i = 1; i < strlen(parser->current_token->value); i++){
            if(isdigit(parser->current_token->value[i])){
                num++;
                continue;
            }else if(parser->current_token->value[i] == '.'){
                parser->current_token->type = TOKEN_DOUBLECONST;
                return parser;
            }
        }
        if(num = strlen(parser->current_token->value)){
            parser->current_token->type = TOKEN_INTCONST;
            return parser;
        }
    }else{
        return parser;
    }
    return parser;
}

AST_T* parser_parse_expression(parser_T* parser){
    switch(parser->current_token->type){
        case TOKEN_INTCONST:    return parser_parse_int(parser);
        case TOKEN_FLOATCONST:  return parser_parse_float(parser);
        case TOKEN_DOUBLECONST: return parser_parse_double(parser);
        case TOKEN_BOOLCONST:   return parser_parse_bool(parser);
        case TOKEN_STRINGCONST: return parser_parse_string(parser);
        case TOKEN_CHARCONST:   return parser_parse_char(parser);
    }
}

AST_T* parser_parse_variable_def(parser_T* parser){
    parser_eat(parser, TOKEN_IDENTIFIER); //variable type
    char* variable_definition_var_name = parser->current_token->value;
    parser_eat(parser, TOKEN_IDENTIFIER); //variable name

    AST_T* variable_definition_value = init_ast(AST_VARIABLE_DEFINITION);

    if(parser->current_token->type == TOKEN_EQUALS){
        parser_eat(parser, TOKEN_EQUALS);
        variable_definition_value = parser_parse_expression(parser_parse_term(parser)); //variable value 

        AST_T* variable_definition = init_ast(AST_VARIABLE_DEFINITION);  
        variable_definition->variable_def_var_name = variable_definition_var_name;
        variable_definition->variable_def_value = variable_definition_value;
        return variable_definition;
    }
    return variable_definition_value;
}

AST_T* parser_parse_variable(parser_T* parser){
    char* token_value = parser->current_token->value;
    parser_eat(parser, TOKEN_IDENTIFIER);

    if(parser->current_token->type == TOKEN_LPAREN){
        return parser_parse_function_call(parser);
    }

    AST_T* ast_variable = init_ast(AST_VARIABLE);
    ast_variable->variable_name = token_value;

    return ast_variable;
}

AST_T* parser_parse_function_dec(parser_T* parser){
    parser_eat(parser, TOKEN_IDENTIFIER); // Function Token
    AST_T* function_definition = init_ast(AST_FUNCTION_DEF);
    parser_eat(parser, TOKEN_IDENTIFIER); // Function Type
    char* function_dec_function_type = parser->current_token->value;
    parser_eat(parser, TOKEN_IDENTIFIER); // Function Name
    char* function_dec_function_name = parser->current_token->value;

    parser_eat(parser, TOKEN_LPAREN);

    AST_T* argument = init_ast(AST_ARGUMENT_DEFINITION);

    if(parser->current_token->type == TOKEN_RPAREN){
        function_definition->function_def_argument_size = 0;
        function_definition->function_def_arguments=(void*)0;
        parser_eat(parser, TOKEN_RPAREN);
    }else{
        while(parser->current_token->type != TOKEN_RPAREN){  
            argument = parser_parse_variable(parser);     //This is the problem 
            function_definition->function_def_arguments = realloc(
                function_definition->function_def_arguments, function_definition->function_def_argument_size + sizeof(struct AST_STRUCT*)
            );
            function_definition->function_def_arguments[function_definition->function_def_argument_size] = argument;
            function_definition->function_def_argument_size++;
        
            if(parser->current_token->type == TOKEN_COMMA){
                parser_eat(parser, TOKEN_COMMA);
                continue;
        }
        }
        parser_eat(parser, TOKEN_RPAREN);
    }
    return function_definition;
}

AST_T* patrser_parse_function_def(parser_T* parser){
    parser_eat(parser, TOKEN_IDENTIFIER);
    char* function_definition_func_name = parser->current_token->value;
    parser_eat(parser, TOKEN_IDENTIFIER);
}

AST_T* parser_parse_function_call(parser_T* parser){
    
}