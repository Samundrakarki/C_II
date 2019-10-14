/*
JTSK-320112
a2 p2.c
Samundra karki
sa.karki@jacobs-university.de
*/
#include<stdio.h>
#include<stdlib.h>
#include <string.h>

int main(){

    char str1[100];
    char str2[100];
    char *dym_arr;

    dym_arr = (char*) malloc((strlen(str1)+strlen(str2))*sizeof(char));
    if(dym_arr == NULL){
        exit(1);
    }
    fgets(str1, 100, stdin);
    strtok(str1, "\n");

    fgets(str2, 100, stdin);
    strtok(str2, "\n");

    //cocatinating str1 and str2 in dynamically allocated memory
    strcat(dym_arr, str1);
    strcat(dym_arr, str2);

    printf("Result of concatenation: %s\n", dym_arr);
    free(dym_arr);
    return 0;
}