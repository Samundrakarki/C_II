/*
JTSK-320112
a4 p4.c
Samundra karki
sa.karki@jacobs-university.de
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//data type of a person
struct person {
  int age;
  char name[30];
};

//this function sorts given array of person with standard bublesort algorithm
void bubble_sort(struct person*, int, int (*comp) (const void*, const void*));

//this function compares the age of persons passed by our bubble_sort algorithm
int compare_age (const void*, const void*);

//this function compares the name of persons passed by our bubble_sort algorithm
int compare_name (const void*, const void*);

//this function prints the name of the list
void print_list(struct person*, int);


int main() {
  int n; 
  
  scanf("%d", &n); getchar();

  struct person arr[n];
  
  for (int i = 0; i < n; i++){
    fgets(arr[i].name, 30, stdin);
    strtok(arr[i].name, "\n");
    
    scanf("%d", &(arr[i].age)); getchar();
  }

  //calling the sorting algorithm to sort in order of the age
  bubble_sort(arr, n, compare_name);
  print_list(arr, n);

  //calling the sorting algorithm to sort in order of the name
  bubble_sort(arr, n, compare_age);
  print_list(arr, n);
  
  return 0;
}


//buble sort algorithms
void bubble_sort(struct person* arr, int size, int (*comp) (const void*, const void*)) {
  struct person tmp; 
  for (int i = 0; i < size-1; i++) {
     for (int j = 0; j < size-i-1; j++) {
       if (comp(&arr[j], &arr[j+1]) > 0) { //here the comparing function is passed and if this returns true then swapping is done
	        tmp = arr[j];
	        arr[j] = arr[j+1];
	        arr[j+1] = tmp;
       }
     }
   }
}

//compares array with the age
int compare_age (const void *void_a, const void *void_b) {
  const struct person* a = (const struct person*) void_a;
  const struct person* b = (const struct person*) void_b;
  
  const int first_age = (*a).age;
  const int second_age = (*b).age;

  if (first_age < second_age) return -1;
  else if (first_age > second_age) return 1;
  return compare_name(a, b); // if age is equal then compare name is called and sorting is done alphabetically 

}

//compares array with the help of name
int compare_name (const void *void_a, const void *void_b) {
  const struct person* a = (const struct person*) void_a;
  const struct person* b = (const struct person*) void_b;
  
  const char* first_name = (*a).name;
  const char* second_name = (*b).name;
  
  int val = strcmp(first_name, second_name);
  if (val)
    return val;
  
  return compare_age(a, b);// if age is equal then compare name is called and sorting is done alphabetically
}

//prints the array of the struct
void print_list (struct person* arr, int size) {
  for (int i = 0; i < size; i++) {
    printf("{%s, %d}; ", arr[i].name, arr[i].age);
  }
  printf("\n");
}
