/*
JTSK-320112
a6 p5.c
Samundra karki
sa.karki@jacobs-university.de
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_SIZE 30


int main(){
    int n;
    char buffer[64], ch; //static allocation of buffer
    FILE *fp1, *fp2;
    int i = 0, j;
    
    scanf("%d", &n);
    getchar();

    //temp file helps storing the file name in the file_name variable.
    char file_name[n][50];
    char temp_file_name[50];

    //adding(copying) the elemnts to file)name
    for(int i = 0; i < n; i++){
        scanf("%s", temp_file_name);
        strcpy(file_name[i], temp_file_name);
    }

    //concatinating three files
    printf("Concatinating the result of %d files...\nThe result is:\n", n);
    fp2 = fopen("output.txt", "wb");
    while(i < n){
        j = 0;

        fp1 = fopen(file_name[i], "rb");
        if(fp1 == NULL){
            printf("Please enter a valid file_name thats present in the directory.");
        }

        while((ch = fgetc(fp1) != EOF )){
            j++;
        }

        //this call will lead again the pointer to move to first position
        fseek(fp1, 0, SEEK_SET);
        fread(buffer, sizeof(char), 64, fp1);

        //adding a line breaker before the buffer sentence ends
        buffer[j] = '\n';
        buffer[j+1] = '\0';
        for(int k = 0; k < (j+1); k++)
            printf("%c", buffer[k]);

        //writing buffer to the  desired file
        fwrite(buffer, sizeof(char), strlen(buffer), fp2);           
        
        i++;
        fclose(fp1);
    }
    printf("The result was written in output.txt\n");
    fclose(fp2);
    return 0;
}
