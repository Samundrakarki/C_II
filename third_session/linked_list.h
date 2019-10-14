/*
JTSK-320112
a3 p1.c
Samundra karki
sa.karki@jacobs-university.de
*/

#ifndef LINKED_LIST_H_INCLUDED
#define LINKED_LIST_H_INCLUDED


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

//structure of list
struct list
    {
        int info;
        struct list *next;
        
    };

#endif