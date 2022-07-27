#include "include/IO.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* read_file(char* file_name){
    char line[32000];
    char* buff=malloc(1*sizeof(char));
    buff[0] = '\0';

    FILE* fptr = fopen(file_name, "rb");

    while(fgets(line, 32000, fptr)){
        buff=realloc(buff, (strlen(buff)+strlen(line)+1)*sizeof(char));
        strcat(buff, line);
    }
    fclose(fptr);

    return buff;
}

void write_file(const char* file_name, char* buff){
    
}