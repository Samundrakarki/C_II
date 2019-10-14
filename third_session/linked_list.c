#include "linked_list.h"
#include <stdio.h>
#include <stdlib.h>
//push the element at the begining of the list
struct list* push_front(struct list *my_list, int value){
    struct list *newel;
    newel = (struct list *) malloc((sizeof(struct list*)));
    if(newel == NULL){
        printf("Error allocatin memory");
        return my_list;
    }
    newel->info = value;
    newel->next = my_list;
    return newel;
}

//push elemnent at the back of the list
struct list* push_back(struct list *my_list, int value){
    struct list *cursor,*newel;
    cursor = my_list;
    newel = (struct list*) malloc(sizeof(struct list));
    
    if(newel == NULL){
        printf("Error allocating memory\n");
        return my_list;
    }
    
    newel->info = value;
    newel->next = NULL;
    
    if(my_list == NULL){
        return newel;
    }
    while(cursor->next != NULL)
        cursor = cursor->next;
    cursor->next = newel;
    return my_list;
}

//pop the element a the beginning of the list
struct list* pop_front(struct list *my_list){
    //if list contains NULL then return NULL rather than trying to remove the momory that doesnot exits
    if (my_list == NULL){
        return NULL;
    }
    return my_list->next;
}

//free the elements
void dispose_list(struct list* my_list){
    struct list * nextelem;
    while(my_list != NULL){
        nextelem = my_list-> next;
        free(my_list);
        my_list = nextelem;
    }
}

//print the elements
void print_list(struct list* my_list){
    while(my_list != NULL){
        printf("%d ", my_list->info);
        my_list = my_list -> next;
    }
    printf("\n");
}

