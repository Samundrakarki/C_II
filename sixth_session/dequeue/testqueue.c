/**
 * @file testqueue.c
 */

#include <stdio.h>

#include "queue.h"

int main() 
{
	Queue line;
	Item temp;
	int removed_element;
	char ch;
	
	initialize_queue(&line);
	
	while (((ch = getchar()) != EOF) && (ch != 'q'))
	{
		switch (ch)	{
			case 'a':
				// printf("add int: ");
				scanf("%d", &temp);
				if (!queue_is_full(&line))
				{
					printf("add int: Putting %d into queue\n", temp);
					enqueue(temp, &line);
					break;
				}
				else
					puts("Queue is full");
				break;

			case 'd':
				if (queue_is_empty(&line))
					puts("Nothing to delete!");
				else
				{
					removed_element = dequeue(&temp, &line);
					printf("Removing %d from queue\n",removed_element);
				}
				break;
			case 'p':
				printq(&line);
				break;
			default:
				printf("%d items in queue\n", queue_item_count(&line));
				puts("Type a to add, d to delete, p to print, q to quit:");
				break;
		}

		if(ch == 'q'){
			break;
		}
	}	
	empty_queue(&line);
	puts("Bye.");
	return 0;
}