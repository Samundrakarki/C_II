/*
JTSK-320112
a1 p2.c
Samundra karki
sa.karki@jacobs-university.de
*/

#include<stdio.h>

#define Checker(c) (c&1)

int main(){
    unsigned char c;
    scanf("%c", &c);
    getchar();
    printf("The decimal representation is: %d\n", c);
    printf("The least significant bit is: %d\n", Checker(c));

    return 0;
}