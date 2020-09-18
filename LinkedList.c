/* 
This progrman is a simply linked list structure implementation.
Author: Luis Bernardo Ambrosi Rincón Gallardo.
Version: 1.0
Date:13/09/2020
Use with the header LinkedList.h
*/

#include "LinkedList.h"
#include <errno.h>

/* 
	List is Empty = EIO
	Pointer to NULL = EFAULT
*/


	return 0;
}


void initialize(List *l)
{

	if(l == NULL)
	{
		errno = EFAULT;
		return;	
	}
	
	head = NULL;
	l->next = NULL;
	l->size = 0;
}
void insert(List *l,int e)
{
	if(l == NULL)
	{
		errno = EFAULT;
		return;	
	}
	else
	{
		List *aux;
		aux =(List *)malloc(sizeof(List));
		aux->next = NULL;
		if(aux == NULL)
		{
			errno = EFAULT;
		}
		else
		{
			aux->string = e;
			
			if(isEmpty(l) == 1)
			{
				head = aux;
			}
			else
			{
				aux->next = head;
				head = aux;	
			}
			l->size++;
		}
	}
}

void remove_element(List *l)
{
	if(l == NULL)
	{
		errno = EFAULT;
		return;	
	}
	else
	{
		if(isEmpty(l) == 1)
		{
			errno = EIO;
			return;
		}
		else
		{
			List *aux;
			aux = (List*)malloc(sizeof(List));
			aux = head;
			head = aux->next;
			free(aux);
			l->size--;
		}
	}
}
int isEmpty(List *l)
{
	if (l == NULL)
	{
		errno = EFAULT;
		return;
	}
	else
	{ 
		if(l->size == 0)
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}
	
}

int size(List *l)
{
	if (l == NULL)
	{
		errno = EFAULT;
		return;
	}
	return l->size;
}

void show(List *l)
{

	if (l == NULL)
	{
		errno = EFAULT;
		return;
	}
	else
	{
		if(isEmpty(l) == 1)
		{
			errno = EIO;
			return;
		}
		else
		{
			List *aux;
			aux = head;
			while(aux != NULL)
			{
				printf("%d\n",aux->string);
				aux = aux->next;
			}
			printf("\n");
		}
	}
}
