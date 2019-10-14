/*
JTSK-320112
a2 p4.c
Samundra karki
sa.karki@jacobs-university.de
*/

#include <stdio.h>
#include <stdlib.h>
//sets the value of the array
int*** set_matrix(int*** matrix, int x, int y, int z);
//prints the multi dimensional array
void print_matrix(int*** matrix, int x, int y, int z);

int main(){
    //initilization of the required fields.
    int l, b, h;
    scanf("%d", &l);
    getchar();

    scanf("%d", &b);
    getchar();

    scanf("%d", &h);
    getchar();

    //dynamically allocating the memory
    int ***first_matrix;
    
    first_matrix = (int*** ) malloc(sizeof(int **) * l);
    
    if(first_matrix == NULL){    
         exit(1);
     }
    
    for(int i = 0; i < l; i++){
        first_matrix[i] = (int**) malloc(sizeof(int *) * b);
        if(first_matrix[i] == NULL){
            exit(1);
        }
        for(int j = 0; j < b; j++){
            
            first_matrix[i][j] = (int*) malloc(sizeof(int) * h);
            if(first_matrix[i][j] == NULL){
            exit(1);
            }
        }
    }

    //calling the functions
    first_matrix = set_matrix(first_matrix, l, b, h);
    print_matrix(first_matrix, l, b, h);

    //deallocating the memory
    for(int i = 0; i < l; i++){
        for(int j = 0; j < b; j++){
            free(first_matrix[i][j]);
        }
        free(first_matrix[i]);
    }
    free(first_matrix);
    return 0;
}


//printing the matrix in the given form
void print_matrix(int*** matrix, int x, int y, int z){
    int counter = 1;
    for(int i = 0; i < z; i++){
        printf("Section %d:\n",counter++);
        //as i have experiment-- combination of l(i) and b(j) making z(k) = 0, yeilds 1 1 1 1. So, looping from height and printing each row and column will provide required answer
        for(int j = 0; j < y; j++){
            for(int k = 0; k < x; k++){
                printf("%d ", *(*(*(matrix + k) +j)+i));
            }
            printf("\n");
        }
    }
}

// /setting the elemts of the array
int*** set_matrix(int*** matrix, int x, int y, int z){
    for(int i = 0; i < x; i++){
        for(int j = 0; j < y; j++){
            for(int k = 0; k < z; k++){
                scanf("%d", &matrix[i][j][k]);
            }
        }
    }
    return matrix;
}