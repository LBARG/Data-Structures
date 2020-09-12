/* 

This progrman is a static Queue structure implementation.
Author: Luis Bernardo Ambrosi Rincón Gallardo.
Version: 2.0.
Date:12/09/2020
Use with the header ColaEst.h

*/
#include "ColaEst.h"
#include <errno.h>

/* 
	Queue is Full = ENOMEM
	Queue is Empty = EIO
	Pointer to NULL = EFAULT
*/

int main(void) 
{	
	
	return 0;
}

void inizialize(Queue *q)
{	
	if (q == NULL)
	{
		errno = EFAULT;
		return;
	}
	q->front = MAX_SIZE-1;
	q->back = 0;
	q->size = 0;
}
void queue(Queue *q, int elemento)
{
	if (q == NULL)
	{
		errno = EFAULT;
		return;
	}
	else
	{
		if(q->size < MAX_SIZE)
		{
			q->back--;
			if(q->back == -1)
			{
				q->back = MAX_SIZE-1;
			}
			q->data[q->back] = elemento;
			q->size++;
		}
		else
		{
		
			errno = ENOMEM;
			return;
		}
	}
	
}
int dequeue (Queue *q)
{
	int element = 0;

	if (q == NULL)
	{
		errno = EFAULT;
		return;
	}
	
	else
	{
		if(isEmpty(q) == 0)
		{
			element = q->data[q->front];
			q->front--;
			q->size--;
			if(q->front == -1)
			{
				q->front = MAX_SIZE-1;
			}
		
			return element;
		}
	
		else
		{
			errno = EIO;
			return;
		}
	}
}

int isEmpty(Queue *q)
{
	if (q == NULL)
	{
		errno = EFAULT;
		return;
	}
	else
	{ 
		if(q->size == 0)
		{
			return 1;
		}
		else
		{
		return 0;
		}
	}
}
int front(Queue *q)
{
	if (q == NULL)
	{
		errno = EFAULT;
		return;
	}
	else
	{
		if(isEmpty(q) == 1)
		{
			errno = EIO;
			return;
		}
	}
	
	return q->data[q->front];
}
int back(Queue *q)
{
		if (q == NULL)
	{
		errno = EFAULT;
		return;
	}
	else
	{
		if(isEmpty(q) == 1)
		{
			errno = EIO;
			return;
		}
	}
	
	return q->data[q->back];
}
int size(Queue *q)
{
	if (q == NULL)
	{
		errno = EFAULT;
		return;
	}
	return q->size;
}

void destroy(Queue *q)
{
	if (q == NULL)
	{
		errno = EFAULT;
		return;
	}
	inizialize(q);
}

void show (Queue *q)
{
	if(q == NULL)
	{
		errno = EFAULT;
		return;
	}
	else
	{
		if(isEmpty(q) == 1)
		{
			errno = EIO;
			return;
		}
		else
		{
			int aux, i;
			aux = q->front;
			for(i = 0;i < q->size-1;i++)
			{
				printf("%d", q->data[aux--]);
			}
		}
	}
}
