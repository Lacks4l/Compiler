#ifndef TOKEN_H
#define TOKEN_G

typedef struct TOKENS_STRUCT{
    enum token_type{
        /* TOKEN BASIC TYPES */
        TOKEN_INT,              //0
        TOKEN_FLOAT,            //1
        TOKEN_DOUBLE,           //2
        TOKEN_BOOL,             //3
        TOKEN_STRING,           //4
        TOKEN_CHAR,             //5

        /* TOKEN SYMBOLS */
        TOKEN_SEMICOLON,        //6
        TOKEN_COLON,            //7
        TOKEN_LPAREN,           //8
        TOKEN_RPAREN,           //9
        TOKEN_LBRACE,           //10
        TOKEN_RBRACE,           //11
        TOKEN_LBRACKET,         //12
        TOKEN_RBRACKET,         //13
        TOKEN_TICK,             //14
        TOKEN_DITTO,            //15
        TOKEN_GT,               //16
        TOKEN_LT,               //17
        TOKEN_BANG,             //18
        TOKEN_UNDERSCORE,       //19
        TOKEN_SLASH,            //20
        TOKEN_BACKSLASH,        //21
        TOKEN_COMMA,            //22
        TOKEN_TILDE,            //23
        TOKEN_BACKTICK,         //24
        TOKEN_QUESTION,         //25
        TOKEN_PIPE,             //26
        TOKEN_AMPERSAND,        //27
        TOKEN_AT,               //28
        TOKEN_EQUALS,           //29

        /* TOKEN MATH SYMBOLS */
        TOKEN_PLUS,             //30
        TOKEN_MINUS,            //31
        TOKEN_STAR,             //32
        TOKEN_MOD,              //33
        TOKEN_EXPONENT,         //34

        /* TOKEN TYPE CONSTANTS */
        TOKEN_INTCONST,         //35
        TOKEN_FLOATCONST,       //36  
        TOKEN_DOUBLECONST,      //37    
        TOKEN_STRINGCONST,      //38    
        TOKEN_CHARCONST,        //39    
        TOKEN_BOOLTYPE,         //40

        /* TOKEN COMPLEX DATA TYPE */
        TOKEN_STRUCT,           //41
        TOKEN_ENUM,             //42
        TOKEN_VECTOR,           //43

        /* OTHER */
        TOKEN_IDENTIFIER        //44
    }type;
    char* value;

}token_T;

token_T* init_token(char* str, int type);

#endif /* TOKEN__H */