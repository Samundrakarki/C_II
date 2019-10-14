/**
 * @file queue.c
 */

#include <stdio.h>
#include <stdlib.h>

#include "queue.h"

// static void copy_to_node(Item item, Node *pn);
// static void copy_to_item(Node *pn, Item *pi);

void initialize_queue(Queue *pq)
{
	pq->front = pq->rear = NULL;
	pq->items = 0;
}

int queue_is_full(const Queue *pq)
{
	return pq->items == MAXQUEUE;
}

int queue_is_empty(const Queue *pq)
{
	return pq->items == 0;
}

int queue_item_count(const Queue *pq)
{
	return pq->items;
}

int enqueue(Item item, Queue *pq)
{
		struct node *temp;
		temp = (struct node*) malloc(sizeof(struct node)); 

		//intializing the value of of struct to temporary var
		temp->item = item;
		temp->next = NULL;
		
		//if the queue is empty then front and rear point at same value
		if( pq->front == NULL && pq->rear == NULL){
			pq->front = pq->rear = temp;
		}

		//assigning the struct Node to the queue.
		(pq->rear)->next = temp;
		pq->rear = temp;

		pq->items++;
        return 0;
}

int dequeue(Item *pitem, Queue *pq)
{	
		struct node *temp;
		temp = pq->front;

		//storing the front end dequed value in a temporary pointer
		*pitem = (pq->front)->item;

		if(pq->front == pq->rear ){
			pq->front = pq->rear = NULL;
		}else {
			pq->front = (pq->front)->next;
		}
		free(temp);

		pq->items--;
        return *pitem;
}

void empty_queue(Queue *pq)
{
	Item dummy;
	while (!queue_is_empty(pq)) {
		dequeue(&dummy, pq);
	}
}

void printq(Queue *pq){
	struct node *temp;
	temp = pq->front;
	printf("content of the queue: ");
	while(temp != NULL){
		printf("%d ", temp->item);
		temp = temp->next;
	}
	printf("\n");
}

// static void copy_to_node(Item item, Node *pn)
// {
// 	pn->item = item;
// }

// static void copy_to_item(Node *pn, Item *pi)
// {
// 	*pi = pn->item;
// }