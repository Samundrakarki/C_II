#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"
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
