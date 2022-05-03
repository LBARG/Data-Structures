/* 
This progrman is a simply linked list structure implementation with integers.
The addition and the elimination of one element are made in the begining of the list.
Author: Luis Bernardo Ambrosi Rincón Gallardo.
Version: 1.0
Date:13/09/2020
Use with the header LinkedList.h
*/

#include "Linked_List.h"
#include <errno.h>
#include <string.h>

/* 
	List is Empty = EIO
	Pointer to NULL = EFAULT
*/

int main(void)
{
	int option;
	List * l;
	l = (List *)malloc(sizeof(List));
	initialize(l);
	printf("Select one option:\n"
			"Insert element(1)\n"
			"Delete element (2)\n"
			"Size List(3)\n"
			"Show List(4)\n"
			"Exit(5)\n");
	
	scanf("%d",&option);
	
	do
	{
		if(option == 1)
		{
			char * element;
			element = (char *)malloc(sizeof(char));
			printf("Insert an integer number:\n");
			scanf("%s",element);
			printf("\n");
			insert(l,element);
		}
		else if(option == 2)
		{
				printf("Deleting element...\n\n");
				remove_element(l);
				if(errno != EIO)
				{
					printf("Element Deleted\n\n");
				}
				else
				{
					printf("The List is Empty, was not possible to remove the element\n\n");
				}
		}
		else if(option == 3)
		{
			int ListSize;
			printf("The size of the list is:\n");
			ListSize = size(l);
			printf("%d\n\n",ListSize);
		}
		else if(option == 4)
		{
			printf("The list is:\n");
			show(l);
		}
		
		else
		{
			if(option == 5)
		{
			return 0;
		}

			printf("Not valid, please enter a valid number");
		}
		
			
			printf("Select one option:\n"
			"Insert element(1)\n"
			"Delete element (2)\n"
			"Size List(3)\n"
			"Show List(4)\n"
			"Exit(5)\n");
			scanf("%d",&option);
	}while(option);
	
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
void insert(List *l,char* e)
{
	if(l == NULL)
	{
		errno = EFAULT;
		return;	
	}
	else
	{
		List *aux;
		aux = (List *)malloc(sizeof(List));
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
		exit(-1);
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
		exit(-1);
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
			aux = (List*)malloc(sizeof(List));
			aux = head;
		
		
			while(aux != NULL)
			{
				
	
				printf("%s\n",aux -> string);
				aux = aux->next;
				
			}
			printf("\n");
		}
	}
}