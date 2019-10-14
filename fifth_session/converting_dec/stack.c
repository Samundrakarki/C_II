#include<stdio.h>
#include<stdlib.h>
#include "stack.h"


//push the data into the stack: Without side-effect function
void push(){
    if(s.count == MAX_SIZE){
        printf("Stack Overflow");
        return;
    }
    int bit = (s.dec%2);
    s.count++;
    s.array[s.count-1] = bit;
    s.dec = s.dec / 2;
}


void print(){
    int counter = s.count;
    printf("The binary representation of %d is ", dec_value);
    for (int i = (counter-1); i >= 0; i--){
        printf("%d", s.array[i]);
    }
    printf(".\n");
}