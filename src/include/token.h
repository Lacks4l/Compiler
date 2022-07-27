#ifndef TOKEN_H
#define TOKEN_G

typedef struct TOKENS_STRUCT{
    enum token_type{
        /* TOKEN BASIC TYPES */
        TOKEN_INT,              //0
        TOKEN_BOOL,             //1
        TOKEN_STRING,           //2
        TOKEN_CHAR,             //3

        /* TOKEN SYMBOLS */
        TOKEN_SEMICOLON,        //4
        TOKEN_COLON,            //5
        TOKEN_LPAREN,           //6
        TOKEN_RPAREN,           //7
        TOKEN_LBRACE,           //8
        TOKEN_RBRACE,           //9
        TOKEN_LBRACKET,         //10
        TOKEN_RBRACKET,         //11
        TOKEN_TICK,             //12
        TOKEN_DITTO,            //13
        TOKEN_GT,               //14
        TOKEN_LT,               //15
        TOKEN_BANG,             //16
        TOKEN_UNDERSCORE,       //17
        TOKEN_SLASH,            //18
        TOKEN_BACKSLASH,        //19
        TOKEN_COMMA,            //20
        TOKEN_TILDE,            //21
        TOKEN_BACKTICK,         //22
        TOKEN_QUESTION,         //23
        TOKEN_PIPE,             //24
        TOKEN_AMPERSAND,        //25
        TOKEN_AT,               //26
        TOKEN_EQUALS,           //27

        /* TOKEN MATH SYMBOLS */
        TOKEN_PLUS,             //28
        TOKEN_MINUS,            //29
        TOKEN_STAR,             //30
        TOKEN_MOD,              //31
        TOKEN_EXPONENT,         //32

        /* TOKEN TYPE CONSTANTS */
        TOKEN_INTCONST,         //33
        TOKEN_FLOATCONST,       //34  
        TOKEN_DOUBLECONST,      //35    
        TOKEN_STRINGCONST,      //36    
        TOKEN_CHARCONST,        //37    
        TOKEN_BOOLTYPE,         //38

        /* TOKEN COMPLEX DATA TYPE */
        TOKEN_STRUCT,           //39
        TOKEN_ENUM,             //40
        TOKEN_VECTOR,           //41

        /* OTHER */
        TOKEN_IDENTIFIER        //42
    }type;
    char* value;

}token_T;

token_T* init_token(char* str, int type);

#endif /* TOKEN__H */