/*
JTSK-320112
a1 p1.c
Samundra karki
sa.karki@jacobs-university.de
*/

#include <stdio.h>

#define SWAP(t, x, y) {t z; z = x; x = y; y = z;}

int main(){
    int a, b;
    double c, d;

    scanf("%d", &a);
    scanf("%d", &b);
    scanf("%lf", &c);
    scanf("%lf", &d);

    SWAP(int, a, b);
    SWAP(double, c, d);
    printf("After swapping:\n%d\n%d\n%lf\n%lf\n", a, b,c,d);
    
    return 0;
}
