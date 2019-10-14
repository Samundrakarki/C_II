/*
JTSK-320112
a1 p4.c
Samundra karki
sa.karki@jacobs-university.de
*/

#include <stdio.h>
#include <stdlib.h>

#define INTERMEDIATE

int main(){
    int n;
    int *arr1, *arr2;

    scanf("%d", &n);
    
    //defining two vectors
    arr1 = (int *) malloc (n * sizeof(int));
    arr2 = (int *) malloc(n * sizeof(int));
    
    //if either of them is null then, program exits
    if((arr1 == NULL) || (arr2 == NULL)){
        exit(1);
    }
    for(int i = 0; i < n; i++){
        scanf("%d", &arr1[i]);
    }

    for(int i = 0; i < n; i++){
        scanf("%d", &arr2[i]);
    }
    
    //if this program contains INTERMEDIATE in its defination then the code will execute
    
       int *arr_intermediate;
       int scalar_product = 0;
       arr_intermediate = (int *)malloc(n * sizeof(int));
       if(arr_intermediate == NULL){
           exit(1);
       }
       for (int i = 0; i < n; i++){
           arr_intermediate[i] = arr1[i] * arr2[i];
           scalar_product += arr_intermediate[i];
       }
       #ifdef INTERMEDIATE
            printf("The intermediate product values are:\n");
       #endif
       for (int i = 0; i < n; i++){
           #ifdef INTERMEDIATE
           printf("%d\n", arr_intermediate[i]);
           #endif
       }
       printf("The scalar product is: %d\n",scalar_product);
       free(arr_intermediate);
    

    free(arr1);
    free(arr2);

    return 0;
} 