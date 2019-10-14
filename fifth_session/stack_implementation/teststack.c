#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

int main(){
    char ch;
    int data;

    while(1){
        scanf("%c", &ch);
        getchar();
        
        //this case determines which character will lead to which function call
        switch(ch){
            case 's':
                scanf("%d", &data);
                getchar();
                push(data);
                break;
            case 'p':
                pop();
                break;
            case 'c':
                isEmpty();
                printf("\n");
                break;
            case 'e':
                empty();
                break;
            case 'q':
                printf("Quit\n");
                break;
            default:
                break;
        }
        if(ch == 'q'){
            break;
        }
    }
}