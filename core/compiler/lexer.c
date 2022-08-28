#include "include/lexer.h"

#include <string.h>
#include <stdlib.h>
#include <ctype.h>

lexer_T* init_lexer(char* buff){
    lexer_T* lexer = malloc(1*sizeof(struct LEXER_STRUCT));
    lexer->contents = buff;
    lexer->i = 0;
    lexer->c = lexer->contents[lexer->i];
    return lexer;
}

lexer_T* lexer_advance(lexer_T* lexer){
    lexer->i++;
    lexer->c = lexer->contents[lexer->i];
}

void lexer_skip(lexer_T* lexer){
    while(lexer->c!=10){
        lexer_advance(lexer);
    }
}

char* to_string(lexer_T* lexer){
    char* str = malloc(1*sizeof(char));
    str[0] = lexer->c;
    str[1] = '\0';
    return str;
}

char* symbol_to_string(lexer_T* lexer){
    char* str = malloc(1*sizeof(char));
    str[0] = lexer->c;
    str[1] = '\0';
    lexer_advance(lexer);
    return str;
}

token_T* get_token(lexer_T* lexer){
    char* str = malloc(1*sizeof(char));
    str[0]='\0';
    while(isalnum(lexer->c)||lexer->c=='_'||lexer->c=='.'){
        str = realloc(str, (strlen(str)+strlen(to_string(lexer))+1)*sizeof(char));
        strcat(str, to_string(lexer));
        lexer_advance(lexer);
    }

    return init_token(str, TOKEN_IDENTIFIER);
}

token_T* lexer_collect_string(lexer_T* lexer){
    lexer_advance(lexer);

    char* str = malloc(1*sizeof(char));
    str[0] = '\0';
    
    while(lexer->c!='\"' && lexer->c!='\''){
        char* s = to_string(lexer);
        str = realloc(str, (strlen(str)+strlen(s)+1)*sizeof(char));
        strcat(str, s);
        lexer_advance(lexer);
    }

    lexer_advance(lexer);

    return strlen(str)==2?init_token(str, TOKEN_CHARCONST):init_token(str, TOKEN_STRINGCONST);
}

//Function Call for Lexer in Parser
token_T* advance_lexer(lexer_T* lexer){
    while(lexer->c==' '||lexer->c==10){
        lexer_advance(lexer);
    }

    if(lexer->c=='/'&&lexer->contents[lexer->i+1]=='/'){
        lexer_skip(lexer);
    }

    if(lexer->c=='\"'||lexer->c=='\''){
        return lexer_collect_string(lexer);
    }

    if(isalnum(lexer->c)){
        return get_token(lexer);
    }else{
        switch(lexer->c){
            //----------------- SYMBOLS -----------------------
            case ';':return init_token(symbol_to_string(lexer), TOKEN_SEMICOLON);
            case ':':return init_token(symbol_to_string(lexer), TOKEN_COLON);
            case '(':return init_token(symbol_to_string(lexer), TOKEN_LPAREN);
            case ')':return init_token(symbol_to_string(lexer), TOKEN_RPAREN);
            case '[':return init_token(symbol_to_string(lexer), TOKEN_LBRACE);
            case ']':return init_token(symbol_to_string(lexer), TOKEN_RBRACE);
            case '{':return init_token(symbol_to_string(lexer), TOKEN_LBRACKET);
            case '}':return init_token(symbol_to_string(lexer), TOKEN_RBRACKET);
            case '\'':return init_token(symbol_to_string(lexer), TOKEN_TICK);
            case '\"':return init_token(symbol_to_string(lexer), TOKEN_DITTO);
            case '<':return init_token(symbol_to_string(lexer), TOKEN_LT);
            case '>':return init_token(symbol_to_string(lexer), TOKEN_GT);
            case '!':return init_token(symbol_to_string(lexer), TOKEN_BANG);
            case '_':return init_token(symbol_to_string(lexer), TOKEN_UNDERSCORE);
            case '/':return init_token(symbol_to_string(lexer), TOKEN_SLASH);
            case '\\':return init_token(symbol_to_string(lexer), TOKEN_BACKSLASH);
            case ',':return init_token(symbol_to_string(lexer), TOKEN_COMMA);
            case '~':return init_token(symbol_to_string(lexer), TOKEN_TILDE);
            case '`':return init_token(symbol_to_string(lexer), TOKEN_BACKTICK);
            case '?':return init_token(symbol_to_string(lexer), TOKEN_QUESTION);
            case '|':return init_token(symbol_to_string(lexer), TOKEN_PIPE);
            case '&':return init_token(symbol_to_string(lexer), TOKEN_AMPERSAND);
            case '@':return init_token(symbol_to_string(lexer), TOKEN_AT);
            case '=':return init_token(symbol_to_string(lexer), TOKEN_EQUALS);

            //----------------- MATH SYMBOLS -----------------------
            case '+':return init_token(symbol_to_string(lexer), TOKEN_PLUS);
            case '-':return init_token(symbol_to_string(lexer), TOKEN_MINUS);
            case '*':return init_token(symbol_to_string(lexer), TOKEN_STAR);
            case '%':return init_token(symbol_to_string(lexer), TOKEN_MOD);
            case '^':return init_token(symbol_to_string(lexer), TOKEN_EXPONENT);  
            case 0: exit(EXIT_SUCCESS);
            default: printf("ERROR: Unrecognized symbol %s", lexer->c); exit(1);
        }
    }
    return (void*)0;
}
