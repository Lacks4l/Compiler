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

int get_token_type(char* token){
    if(strcmp(token, "int")==0){
        return 0;
    }else if(strcmp(token, "bool")==0){
        return 1;
    }else if(strcmp(token, "string")==0){
        return 2;
    }else if(strcmp(token, "char")==0){
        return 3;
    }else if(isdigit(token[0])){
        return 33;
    }else if(isalpha(token[0])){
        return 42;
    }
    return -1;
}

token_T* get_token(lexer_T* lexer){
    char* str = malloc(1*sizeof(char));
    str[0]='\0';
    while(isalnum(lexer->c)||lexer->c=='_'){
        str = realloc(str, (strlen(str)+strlen(to_string(lexer))+1)*sizeof(char));
        strcat(str, to_string(lexer));
        lexer_advance(lexer);
    }

    printf("%s\n", str);

    return init_token(str, get_token_type(str));
}

token_T* lexer_collect_string(lexer_T* lexer){
    lexer_advance(lexer);

    char* str = malloc(1*sizeof(char));
    str[0] = '\0';

    while(lexer->c!='\"'&&lexer->c!='\''){
        char* s = to_string(lexer);
        str = realloc(str, (strlen(str)+strlen(s)+1)*sizeof(char));
        strcat(str, s);
        lexer_advance(lexer);
    }

    if(lexer->contents[lexer->i+1]=='\''){
        lexer_advance(lexer);
        return init_token(str, TOKEN_CHARCONST);
    }

    return init_token(str, TOKEN_STRINGCONST);
}

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
            case ';':return init_token(symbol_to_string(lexer), TOKEN_SEMICOLON);break;
            case ':':return init_token(symbol_to_string(lexer), TOKEN_COLON);break;
            case '(':return init_token(symbol_to_string(lexer), TOKEN_LPAREN);break;
            case ')':return init_token(symbol_to_string(lexer), TOKEN_RPAREN);break;
            case '[':return init_token(symbol_to_string(lexer), TOKEN_LBRACE);break;
            case ']':return init_token(symbol_to_string(lexer), TOKEN_RBRACE);break;
            case '{':return init_token(symbol_to_string(lexer), TOKEN_LBRACKET);break;
            case '}':return init_token(symbol_to_string(lexer), TOKEN_RBRACKET);break;
            case '\'':return init_token(symbol_to_string(lexer), TOKEN_TICK);break;
            case '\"':return init_token(symbol_to_string(lexer), TOKEN_DITTO);break;
            case '<':return init_token(symbol_to_string(lexer), TOKEN_LT);break;
            case '>':return init_token(symbol_to_string(lexer), TOKEN_GT);break;
            case '!':return init_token(symbol_to_string(lexer), TOKEN_BANG);break;
            case '_':return init_token(symbol_to_string(lexer), TOKEN_UNDERSCORE);break;
            case '/':return init_token(symbol_to_string(lexer), TOKEN_SLASH);break;
            case '\\':return init_token(symbol_to_string(lexer), TOKEN_BACKSLASH);break;
            case ',':return init_token(symbol_to_string(lexer), TOKEN_COMMA);break;
            case '~':return init_token(symbol_to_string(lexer), TOKEN_TILDE);break;
            case '`':return init_token(symbol_to_string(lexer), TOKEN_BACKTICK);break;
            case '?':return init_token(symbol_to_string(lexer), TOKEN_QUESTION);break;
            case '|':return init_token(symbol_to_string(lexer), TOKEN_PIPE);break;
            case '&':return init_token(symbol_to_string(lexer), TOKEN_AMPERSAND);break;
            case '@':return init_token(symbol_to_string(lexer), TOKEN_AT);break;
            case '=':return init_token(symbol_to_string(lexer), TOKEN_EQUALS);break;

            //----------------- MATH SYMBOLS -----------------------
            case '+':return init_token(symbol_to_string(lexer), TOKEN_PLUS);break;
            case '-':return init_token(symbol_to_string(lexer), TOKEN_MINUS);break;
            case '*':return init_token(symbol_to_string(lexer), TOKEN_STAR);break;
            case '%':return init_token(symbol_to_string(lexer), TOKEN_MOD);break;
            case '^':return init_token(symbol_to_string(lexer), TOKEN_EXPONENT);break;  
        }
    }
    return (void*)0;
}
