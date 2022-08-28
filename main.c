#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "core/IO.h"
#include "core/Compiler.h"

int main(int argc, char** argv){
    int len = strlen(argv[1]);
    char* last_four = &argv[1][len-5];
    if(strcmp(last_four, ".pacl")==0){
        lexer_T* lexer = init_lexer(read_file(argv[1]));
        parser_T* parser = init_parser(lexer);
        AST_T* root_node = parser_parse(parser);
    }else{
        printf("ERROR: invalid file type\n");
        exit(1);    
    }
    return 0;
}

//Run program with:
/*  
make
./pacl.out [filepath of .pacl file] -> test/test.pacl  
*/