/*
JTSK-320112
a1 p1.c
Samundra karki
sa.karki@jacobs-university.de
*/

#include <stdio.h>

//Maximum value of three numbers
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MAX_THREE(a, b, c) (MAX(a, b) > (c) ? MAX(a, b) : (c))

//minimum value of three numbers
#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define MIN_THREE(a, b, c) (MIN(a, b) < (c) ? MIN(a, b) : (c))

//mid-range of the three numbers
#define MID_RANGE(a, b, c) ((MAX_THREE(a, b, c) + MIN_THREE(a, b, c))/ (2.0))

 int main(){
    int x, y, z;
    scanf("%d", &x);
    getchar();

    scanf("%d", &y);
    getchar();    
    
    scanf("%d", &z);
    getchar();    
    
    printf("The mid-range is: %.6f\n" ,MID_RANGE(x, y, z));

     return 0;
 }