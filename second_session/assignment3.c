/*
JTSK-320112
a2 p3.c
Samundra karki
sa.karki@jacobs-university.de
*/

#include <stdio.h>
#include <stdlib.h>
//sets the value of the array
int** set_matrix(int** matrix, int x, int y);
//prints the multi dimensional array
void print_matrix(int** matrix, int x, int y);
//multiplies the arrays and prints it to the screen
void matirx_multiplication(int** first_matrx, int** second_matrix, int x, int y, int z);

int main(){
    //declaration and initialization of sizes of matrices
    int n, m, p;
    scanf("%d", &n);
    getchar();

    scanf("%d", &m);
    getchar();

    scanf("%d", &p);
    getchar();

    //dynamic memory allocation of two multi dimentional matrices
    int **matrix1, **matrix2;

    matrix1 = (int **) malloc(sizeof(int *) * n);
    matrix2 = (int **) malloc(sizeof(int *) * m);

    if(matrix1 == NULL || matrix2 == NULL){
        exit(1);
    }

    for(int i = 0; i < n; i++){
        matrix1[i] = (int*) malloc(sizeof(int) * m);
        if(matrix1[i] == NULL){
            exit(1);
        }
    }
    
    for(int i = 0; i < m; i++){
        matrix2[i] = (int*) malloc(sizeof(int) * p);
        if(matrix2[i] == NULL){
            exit(1);
        }
    }

    //calling the function
    matrix1 = set_matrix(matrix1, n, m); 
    matrix2 = set_matrix(matrix2, m, p);

    printf("Matrix A:\n");
    print_matrix(matrix1, n, m); 
    printf("Matrix B:\n");
    print_matrix(matrix2, m, p);

    printf("The multiplication result AxB:\n");
    matirx_multiplication(matrix1, matrix2, n, m, p);

    
    //deallocating the matrices
    for(int i = 0; i < n; i++){
        free(matrix1[i]);
    }

    for(int i = 0; i < n; i++){
        free(matrix2[i]);
    }

    free(matrix1);
    free(matrix2);
    return 0;
}

//this function sets the matices to given values;
int** set_matrix(int** matrix, int x, int y){
   for(int i = 0; i < x; i++){
        for(int j = 0; j < y; j++)
        {
            scanf("%d", &matrix[i][j]);
        }
    }
    return matrix;
}

//this function prints rhe second matrices
void print_matrix(int** matrix, int x, int y){
    for(int i = 0; i < x; i++){
        for(int j = 0; j < y; j++){
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

//array multiplication is done and it is gave to a new array and passed it to print function which prints the array provided to that function
void matirx_multiplication(int** first_matrx, int** second_matrix, int x, int y, int z){
    int ** arr_multiplied;
    arr_multiplied = (int **) malloc(sizeof(int *) * x);
     for(int i = 0; i < x; i++){
        arr_multiplied[i] = (int*) malloc(sizeof(int) * z);
        if(arr_multiplied[i] == NULL){
            exit(1);
        }
    }
    int i = 0;
    int k = 0;
    while(i < x){
        k = 0;
        while(k < z){
            int sum = 0;
            for(int j = 0; j < y; j++){   
                sum = sum + (first_matrx[i][j] * second_matrix[j][k]);
            }
            arr_multiplied[i][k] = sum;
            k++;
        }
            i++;
    }
    print_matrix(arr_multiplied, x, z);
     free(arr_multiplied);

}