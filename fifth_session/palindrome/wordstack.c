/*
JTSK-320112
Problem 5.3
Samundra karki
sa.karki@jacobs-university.de
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include"stack.h"


int main(){
   struct stack *given_words;
   char sentence[2024];
   char word[MAX_SIZE][MAX_SIZE];

   given_words = (struct stack *)malloc(sizeof(struct stack));

    //searches for '\n', so it will scan for the sentence until '\n' is pressed
    //efficent than fgets();
    scanf("%[^\n]",sentence);
    getchar();        


   while(strcmp(sentence,"exit")){
   
        given_words->count=0;   
        int i=0, j=0,k=0;

        while(sentence[i]!='\0'){
            if(sentence[i] != ' '){
                word[j][k]=sentence[i];
                k++;      
            }else{
                word[j][k]='\0';         
                j++;
                k=0;
            }
            i++;
        }
        
        word[j][k]='\0';

        for (int i=0;i<=j;i++){
            push(word[i], given_words);
        }
        

        print(word, given_words);
        
        scanf("%[^\n]",sentence);
        getchar();

   }

   dispose_words(given_words);

   return 0;
    
}

