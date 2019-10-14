/*
JTSK-320112
a5 p1.c
Samundra karki
sa.karki@jacobs-university.de
*/
#include<stdio.h>

#define MAX_SIZE 12

struct stack {
    int array[MAX_SIZE];
    unsigned int count;
};

//defining a struct stack type data as global var 
struct stack s;

void push(int data);
void pop();
void isEmpty();
void empty();