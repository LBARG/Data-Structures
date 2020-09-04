/* 

This progrman is a static Queue structure implementation.
Author: Luis Bernardo Ambrosi Rincón Gallardo.
Version: 1.0.
Date:04/09/2020
Use with the header ColaEst.h

*/

#include <stdio.h>
#include <stdlib.h>
#include "ColaEst.h"

int main(void) 
{	
	
	return 0;
}

void inizialize(Queue *q)
{	
	if (q == NULL)
	{
		return;
	}
	q->front = 99;
	q->back = 0;
	q->size = 0;
}
void queue(Queue *q, int elemento)
{
	if (q == NULL)
	{
		return;
	}
	else if(q->size < 100)
	{
		q->back--;
		if(q->back == -1)
		{
			q->back = 99;
		}
		q->data[q->back] = elemento;
		q->size++;
	}
	else
	{
		printf("The queue is full, error trying to queue the element");
		return;
	}
	
}
int dequeue (Queue *q)
{
	int element = 0;

	if (q == NULL)
	{
		return;
	}
	
	else if(isEmpty(q) == 0)
	{
		element = q->data[q->front];
		q->front--;
		q->size--;
		if(q->front == -1)
		{
			q->front = 99;
		}
		
		return element;
	}
	else
	{
		printf("Is not possible to dequeue the element due the queue is empty\n");
		return;
	}
}

int isEmpty(Queue *q)
{
	if (q == NULL)
	{
		return;
	}
	else if(q->size == 0)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
int front(Queue *q)
{
	if (q == NULL)
	{
		return;
	}
	else if(isEmpty(q) == 1)
	{
		printf("The Queue is Empty");
		return;
	}
	
	return q->data[q->front];
}
int back(Queue *q)
{
		if (q == NULL)
	{
		return;
	}
		else if(isEmpty(q) == 1)
	{
		printf("The Queue is Empty");
		return;
	}
	
	return q->data[q->back];
}
int size(Queue *q)
{
	if (q == NULL)
	{
		return;
	}
	return q->size;
}

void destroy(Queue *q)
{
	if (q == NULL)
	{
		return;
	}
	inizialize(q);
}

