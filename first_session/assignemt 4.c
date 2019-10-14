/*
JTSK-320112
a1 p4.c
Samundra karki
sa.karki@jacobs-university.de
*/

#include <stdio.h>


int reverse(int decimal);

int main(){
    unsigned char character;
    scanf("%c", &character);
    int n = 6;
    while(n > 0){
    printf("%d", reverse(character));
    }
}


