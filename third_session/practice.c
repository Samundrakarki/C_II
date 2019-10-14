#include<stdio.h>
#include<stdlib.h>

struct list{
    int a;
    int b;
};

int main(){
    int *p;
    int counter= 3, b;
    int a[5] = {1, 2, 3, 4, 5};
    scanf("%d", &b);
    p = a;
    if (b == counter){
        *(p + (counter+1)) = 4;
    }
    for(int i = 0; i<5; i++){
        printf("%d ", a[i]);
    }
}