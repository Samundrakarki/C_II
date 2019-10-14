/*
JTSK-320112
a3 p3.c
Samundra karki
sa.karki@jacobs-university.de
*/

#include <stdio.h>
#include <stdlib.h>

struct double_list{
    char data;
    struct double_list *prev;
    struct double_list *next;
};

//gets new elemnt and send to push_fornt
struct double_list* getNewel(char value);

//removes the specific element from the list
struct double_list* delElem(struct double_list *mylist);

//push elements at the front of the list
struct double_list* push_front(struct double_list *my_list, char value);

//pop the element a the beginning of the list
struct double_list* remove_element(struct double_list *my_list, char value);

//push elements at the back of the list
struct double_list* push_back(struct double_list *my_list, char value);

//free the elements
void dispose_list(struct double_list* my_list);

//print the elements
void print_list(struct double_list* my_list);

//printing the elements backwards
void rev_print(struct double_list *my_list);

int main(){
    struct double_list *my_list = NULL;
    int i;
    char value;
    while(1){
        //getting a character to do the operations
        scanf("%d", &i);
        getchar();

        //decision making
        switch (i)
        {
            case 1:
                scanf("%c", &value);
                getchar();
                my_list = push_front(my_list, value);
                break;
             case 2:
                scanf("%c", &value);
                getchar();
                my_list = remove_element(my_list, value);
                break;
            case 4:
                rev_print(my_list);
                break;
            case 3:
                 print_list(my_list);
                 break;
            case 5:
                dispose_list(my_list);
                break;    
            case 6:
                scanf("%c", &value);
                getchar();
                my_list = push_back(my_list, value);
                break;
             default:
                break;
        }
        if(i == 5){
            break;
        }
    }
}

struct double_list* getNewel(char value){
    struct double_list *newel;

    newel =(struct double_list*) malloc(sizeof(struct double_list));
    newel->data = value;
    newel->prev = NULL;
    newel->next = NULL;
    return newel;
}


//push elements at the front of the list
struct double_list* push_front(struct double_list *my_list, char value){
    struct double_list *newel = getNewel(value);
    
    if(my_list == NULL){
        my_list = newel;
        return my_list;
    }
    my_list->prev = newel;
    newel->next = my_list;
    my_list = newel;
    return my_list;
}

struct double_list* push_back(struct double_list *my_list, char value){
     struct double_list *newel = getNewel(value);
     struct double_list *cursor = my_list;
    
    if(my_list == NULL){
        my_list = newel;
        return my_list;
    }
    while(my_list->next != NULL){
        my_list = my_list->next;
    }
    my_list->next = newel;
    newel->prev = my_list;
    while(newel->prev != NULL){
        newel = newel->prev;
    }
    return newel;
}

//removes the elemt from the list
struct double_list* remove_element(struct double_list *my_list, char value){
    struct double_list *cursor;
    cursor = my_list;
    int status = 1;
    while(cursor->next != NULL){
        if(cursor->data == value){
            if(cursor->prev == NULL){
                cursor = cursor->next;
                cursor->prev = NULL;
            }else{
                (cursor->prev)->next = cursor->next;
                (cursor->next)->prev = cursor->prev;
            }
            status = 0;
        }
        cursor = cursor->next;
    }
    if(cursor->next == NULL){
        if(cursor->data == value){
            cursor = cursor -> prev;
            cursor -> next = NULL;
            status = 0;
        }
    }
    if(status){
        printf("The element is not in the list!\n");
    }
    while(cursor->prev != NULL){
        cursor = cursor -> prev;
    }
    
    return cursor;
}

void rev_print(struct double_list *my_list) {
    struct double_list* cursor = my_list;
    if( my_list == NULL){
        return ;
    }
    while (cursor->next != NULL){
        cursor = cursor->next;
    }
    while(cursor != NULL){
        printf("%c ", cursor->data);
        cursor = cursor->prev; 
    }
    printf("\n");
}

void dispose_list(struct double_list* my_list){
    struct double_list * nextelem;
    while(my_list != NULL){
        nextelem = my_list-> next;
        free(my_list);
        my_list = nextelem;
    }
}


void print_list(struct double_list* my_list){
    while(my_list != NULL){
        printf("%c ", my_list->data);
        my_list = my_list -> next;
    }
    printf("\n");
}