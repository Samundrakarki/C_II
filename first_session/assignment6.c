/*
JTSK-320112
a1 p6.c
Samundra karki
sa.karki@jacobs-university.de
*/

#include <stdio.h>

int main() {
    unsigned char c;
    scanf("%c", &c);
    getchar();

    printf("The decimal representation is: %d\n", c);
    printf("The binary representation is: ");

    //printing the bits using the bit masks in which 1 is right shifted by ith position each time 
    for(int i = 0; i < 8; i++){
        int j = ((c & 0b10000000 >> i) ? 1 : 0);
        printf("%d", j);
    }
    printf("\n");
    return 0;
}