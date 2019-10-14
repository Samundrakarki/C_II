/*
JTSK-320112
a3 p1.c
Samundra karki
sa.karki@jacobs-university.de
*/

#include <stdio.h>
#include <stdlib.h>

//push the element at the begining of the list
struct list* push_front(struct list *my_list, int value);

//push elemnent at the back of the list
struct list* push_back(struct list* my_list, int value);

//pop the element a the beginning of the list
struct list* pop_front(struct list *my_list);

//free the elements
void dispose_list(struct list* my_list);

//print the elements
void print_list(struct list* my_list);

struct list
    {
        int info;
        struct list *next;
        
    };

int main(){
    //declaring the a pointer to a struct of list
    struct list* my_list = NULL;
    char c;
    int temp_var;

    
    while(1){
        //getting a character to do the operations
        scanf("%c", &c);
        getchar();

        //decision making
        switch (c)
        {
            case 'a': 
                scanf("%d", &temp_var);
                getchar();
                my_list = push_back(my_list, temp_var);
                break;
            case 'b':
                scanf("%d", &temp_var);
                getchar();
                my_list = push_front(my_list, temp_var);
                break;
            case 'r':
                my_list = pop_front(my_list);
                break;
            case 'p':
                print_list(my_list);
                break;
            case 'q':
                dispose_list(my_list);
                break;    
            default:
                break;
        }
        if(c == 'q'){
            break;
        }
    }
    return 0;
}

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

