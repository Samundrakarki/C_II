/*
JTSK-320112
a3 p2.c
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

//Inserting new element in the list
struct list* insert_element(struct list *my_list, int position, int value);

//Reversing the elements of the list
struct list* reverse_element(struct list *my_list);

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
    int position;

    
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
            case 'R':
                my_list = reverse_element(my_list);
                break;
            case 'i':
                scanf("%d", &position);
                getchar();
                scanf("%d", &temp_var);
                getchar();
                my_list = insert_element(my_list, position, temp_var);
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
    while(cursor->next != NULL){
        
        cursor = cursor->next;

    }
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

//inserts new element at given index in the list
struct list* insert_element(struct list *my_list, int position, int value){
    struct list *newel, *cursor;
    int counter = 0;
    cursor = my_list;

    newel = (struct list*) malloc(sizeof(struct list));

    if(newel == NULL){
        printf("Error allocating memory\n");
        return my_list;
    }
    if(position < 0){
        printf("Invalid position!\n");
        return my_list;
    }
    if (position == 0){
        my_list = push_front(my_list, value);
        return my_list;
    }
    newel->info = value;
    while(counter < (position-1)){
        if(cursor->next == NULL){
            printf("Invalid position!\n");
            return my_list;
        }
        cursor = cursor->next;
        counter++;
    }
    newel->next = cursor->next;
    cursor->next = newel;
    return my_list;
}

struct list *reverse_element(struct list *my_list){
    struct list* currrent = my_list;
    struct list *prev = NULL;
    struct list *next;
    while(currrent != NULL){
        next = currrent->next;
        currrent->next = prev;
        prev = currrent;
        currrent = next; 
    }
    my_list = prev;
    return my_list;
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

