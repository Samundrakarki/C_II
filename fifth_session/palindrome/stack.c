/*
JTSK-320112
Problem 5.1
Samundra karki
sa.karki@jacobs-university.de
*/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#include "stack.h"

void push(char item[],struct stack *words_list){
   if (words_list->count<= (MAX_SIZE - 1)){
      strcpy(words_list->words[words_list->count],item);
      words_list->count++;
   }else{
      printf("Error: Stack overflowLCannot push ant more elements\n");
   }
   
}

char *pop(struct stack *words_list){
   if (words_list->count>0){
      words_list->count--;
      return words_list->words[words_list->count]; 
   }else{
    return "Error: Stack overflowLCannot push ant more elements\n";
   }
}

int check_palin(char (*word)[30],struct stack *words_list){
   for(int count = 0; words_list->count>0; count++){
      if(strcmp(pop(words_list),word[count])){
         return 0;
      }   
    }
   return 1;
}

void print(char (*word)[30],struct stack *words_list){
    if(check_palin(word,words_list)){
         printf("The sentence is palindromic by words!\n");
      }else{
         printf("The sentence is not palindromic by words!\n");
      }
}

void dispose_words(struct stack *words_list){
    free(words_list);
}