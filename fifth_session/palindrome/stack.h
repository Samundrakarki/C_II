/*
JTSK-320112
Problem 5.3
Samundra karki
sa.karki@jacobs-university.de
*/

#define MAX_SIZE 30

struct stack {
   unsigned int count;
   char words[][MAX_SIZE]; 
};

void push(char [],struct stack *words_list);
char *pop(struct stack *words_list);

int check_palin(char (*word)[30],struct stack *words_list);
void dispose_words(struct stack *words_list);
void print();

