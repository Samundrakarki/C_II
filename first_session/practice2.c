#include<stdio.h>

unsigned getbits(unsigned char x, int p, int n);
int main(){
    unsigned char c = 'c';
    printf("%u\n", getbits(c, 4, 3)); 
}

unsigned getbits(unsigned char x, int p, int n){
    return (x >> (p+1-n)) & (~0 << n);
}