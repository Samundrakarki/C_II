#include<stdio.h>
#include<stdlib.h>
#include "stack.h"


//push the data into the stack: Without side-effect function
void push(int data){
    if(s.count == MAX_SIZE){
        printf("Pushing Stack Overflow\n");
    }else{
        s.count++;
        s.array[s.count-1] = data;
        printf("Pushing %d\n", s.array[s.count - 1]);
    }
}

//pops the data from the stack
void pop(){
    if(s.count == 0){
        printf("Popping Stack Underflow\n");
        return;
    }
    printf("Popping %d\n",s.array[s.count-1]);
    s.count--;
}

//empties the data from the stack
void empty(){
    printf("Emptying Stack ");
    int counter = s.count ;;
    for(int i = counter; i > 0; i--){
        printf("%d ", s.array[i-1]);
        s.count--;
    }
    printf("\n");
}

//returns if the stack is empty or not
void isEmpty(){
    if(s.count == 0){
        printf("Given array is empty");
    }else{
        printf("Given array is not empty");
    }
}

//for checking if the array is defined correctly or not. you can print it

// void print(){
//     for (int i = 0; i < s.count; i++){
//         printf("%d ", s.array[i]);
//     }
//     printf("\n");
// }