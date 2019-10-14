/*
JTSK-320112
a1 p7.c
Samundra karki
sa.karki@jacobs-university.de
*/

#include <stdio.h>

//setBits changes the parameteized postion of bits where a, b, and c are the position to be changed.
void setBits(unsigned char x, int a, int b, int c);

int main() {
    unsigned char c;
    int x, y, z;
    
    scanf("%c", &c);
    getchar();

    scanf("%d", &x);
    getchar();

    scanf("%d", &y);
    getchar();

    scanf("%d", &z);
    getchar();

    printf("The decimal representation is: %d\n", c);
    printf("The binary representation is: ");

    //printing the bits using the bit masks in which 1 is right shifted by ith position each time 
    for(int i = 0; i < 8; i++){
        int j = ((c & 0b10000000 >> i) ? 1 : 0);
        printf("%d", j);
    }
    printf("\n");
    setBits(c, x, y, z);
    return 0;
}

void setBits(unsigned char x, int a, int b, int c){
    printf("After setting the bits: ");

    //here after shifting a position of 1 we will get 1 at a-th position and or bitwise operator will set the coressponding value to 1 too.
    int j = (x | 0b00000001 << a | 0b00000001 << b | 0b00000001 << c);
    for(int i = 0; i < 8; i++){
        int y = ((j & 0b10000000 >> i) ? 1 : 0);
        printf("%d", y);
    }
    printf("\n");
 }