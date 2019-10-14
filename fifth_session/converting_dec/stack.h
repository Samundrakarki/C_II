/*
JTSK-320112
a5 p2.c
Samundra karki
sa.karki@jacobs-university.de
*/

#define MAX_SIZE 32

struct stack {
    int array[MAX_SIZE];
    unsigned int count;
    unsigned int dec;
};

struct stack s;
int dec_value ;

void push();
void print();

