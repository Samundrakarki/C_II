/*
JTSK-320112
a1 p5.c
Samundra karki
sa.karki@jacobs-university.de
*/

#include <stdio.h>

int main(){
    unsigned char c;
    scanf("%c", &c);

    printf("The decimal representation is: %d\n", c);
    printf("The backwards binary representation is: ");

    //this loops chekcs the left most bit and prints it in order and if found that c while right shifted by i yeilds zero then breaks the loop
    for(int i = 0; i < 8; i++){
        int j = ((c & 1 << i) ? 1 : 0);
        if (!(c >> i)){
            break;
        }
        printf("%d", j);
    }
    printf("\n");

    return 0;
}