/*
JTSK-320112
a4 p2.c
Samundra karki
sa.karki@jacobs-university.de
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//getting the list in ascending order
int my_compare_ascending ( const void *va , const void * vb ) {
    const int * a = ( const int *) va ;
    const int * b = ( const int *) vb ;
    if (*a < *b ) return -1;
    else if (* a > * b) return 1;
    else return 0;
}

//getting the list in descend order
int my_compare_descending ( const void *va , const void * vb ) {
    const int *a = ( const int *) va ;
    const int *b = ( const int *) vb ;
    if (*a > *b ) return -1;
    else if (* a < * b) return 1;
    else return 0;
}

int main () {
    char character;
    int status = 1;
    int size;
    int *arr;
    
    
    scanf("%d", &size); 
    getchar();

    arr = (int*) malloc(sizeof(int) * size);
    if(arr == NULL){
        exit(1);
    }

    //filling the array with the desired numbers
    for(int i = 0; i < size; i++){
        scanf("%d", &arr[i]); 
        getchar();
    }

    // conditon for the ascending or descending or quiting
    while(status){
        scanf("%c", &character);
        getchar();

        if(character == 'a'){
            qsort ( arr , size , sizeof(arr[0]) , my_compare_ascending);
        }else if(character == 'd'){
            qsort(arr, size, sizeof(arr[0]), my_compare_descending);
        }else if(character == 'e'){
            break;
        }else{
            printf("Invalid character");
            break;
        }
        for (int i = 0; i < size ; i++){
            printf ("%d ", arr[i]);
    }
    printf("\n");
    }

    free(arr);
    return 0;
}