/*
JTSK-320112
a1 p7.c
Samundra karki
sa.karki@jacobs-university.de
*/

#define BIT_IDENTIFIER ((x & 0b10000000 >> i) ? 1 : 0)

#include <stdio.h>

void setBits(unsigned char x, int a, int b, int c);

int main() {
    unsigned char c;
    int a, b, d;

    scanf("%d", &a);
    getchar();

    scanf("%d", &b);
    getchar();

    scanf("%d", &d);
    getchar();

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
    setBits(c, a, b, d);
    return 0;
}
 void setBits(unsigned char x, int a, int b, int c){
        int j = (x | 0b00000001 << a) ;
        for(int i = 0; i < 8; i++){
        int y = ((j & 0b10000000 >> i) ? 1 : 0);
        printf("%d", y);
    }
 }
