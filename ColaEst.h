/*Header for a Queue Structure*/
#ifndef __COLAEST_H__
#define __COLAEST_H__

const int MAX_SIZE = 100;

#include <stdio.h>

typedef struct Queue
{
	int data[100];
	int front;
	int back;
	int size;
}Queue;

void inizialize(Queue *);
void queue(Queue *, int);
int dequeue (Queue *);
int isEmpty(Queue *);
int front(Queue *);
int back(Queue *);
int size(Queue *);
void destroy(Queue *);
void show(Queue *);

#endif
