/*
JTSK-320112
a4 p2.c
Samundra karki
sa.karki@jacobs-university.de
*/


#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

//change case to upper case
void to_upper_case(char str[]);

//change case to lower if upper and upper if lower
void to_case_exchange( char str[]);

//change case to lower case
void to_lower_case( char str[]);

//case to exit the loop
void to_exit(char str[]);

//pointer to a function
void (*func[5]) (char[]);


int main(){
    int i;
    char str[100];
    fgets(str, 100, stdin);
    
    //endless loop until the program exits
    while(1){
        
        //get the case for which the function should be called
        scanf("%d", &i); getchar();        

        //assigning the pointer of function to the function address
        func[1] = to_upper_case;
        func[2] = to_lower_case;
        func[3] = to_case_exchange;
        func[4] = to_exit;

        //calling specific functions
        (*func[i]) (str);   
    }
    return 0;
}

//printd the uppercase letters
void to_upper_case(char str[]){
    int i = 0;
    while(str[i]) {
        putchar(toupper(str[i]));
        i++;
    }
}

//prints the lowercase letters
void to_lower_case(char str[]){
    int i = 0;
    while(str[i]){
        putchar(tolower(str[i]));
        i++;
    }
}

//prints the lower to upper case and upper to lower case
void to_case_exchange(char str[]){
    int i = 0;
    while(str[i]){
        if(str[i] >= 'A' && str[i] <= 'Z'){
            putchar(tolower(str[i]));
        }
        else{
            putchar(toupper(str[i]));
        }
        i++;
    }
}

//to exit this function is called.
void to_exit(char str[]){
    exit(1);
}