/*
JTSK-320112
a6 p1.c
Samundra karki
sa.karki@jacobs-university.de
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){
    char file_name[200], line[1024];
    char *token;
    int words_count = 0;
    FILE *fp;

    //getting the name of the file
    fgets(file_name, sizeof(file_name), stdin);
    file_name[strlen(file_name)-1] = '\0';

    //opening it if it exists 
    fp = fopen(file_name, "r");
    if(fp == NULL){
        printf("Error loading the file please check the directory\n");
        exit(1);
    }

    // this loops reads line of the file.
    while(fgets(line, sizeof(line), fp)){
        token = strtok( line, " ,?!.\t\r\n");
        while(token != NULL){
            // to check the words individually
            // printf("%s\n", token);            

            //strtok return only the first token. so to loop it until the end we need to pass NULL pointer insteade of the file
            token = strtok(NULL, " ,?!.\t\r\n");
            words_count++;
        }
    }
    printf("The file contains %d words.\n", words_count);
    fclose(fp);
    return 0;
}

