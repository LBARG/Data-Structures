/* 
This is a header to implement a singly linked list
Author: Luis Bernardo Ambrosi Rincón Gallardo
Version: 1.0

*/


#ifndef __LinkedList_H__
#define __LinkedList_H__
#include <stdio.h>
#include <stdlib.h>

typedef struct List
{
	int string;
	struct List *next;
	int size;
}List;

List *head;

void initialize(List *);
void insert(List *,int);
void remove_element(List *);
int isEmpty(List *);
int size(List *);
void destroy(List *);
void show(List *);



#endif
