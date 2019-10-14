#include <stdio.h>
#include <stdlib.h>

int main(){

    FILE *myFile;
    myFile = fopen("sometxt.txt", "r");

    //read file into array
    int numberArray[100];
    int i = 0;

    if (myFile == NULL){
        printf("Error Reading File\n");
        exit (0);
    }
    char ch;
    while(i<8){
        fscanf(myFile, "%d", &numberArray[i]);
        i++;
    }

    for (int i = 0; i < 8; i++){
        printf("%d ", numberArray[i]);
    }
    fclose(myFile);

    return 0;
}