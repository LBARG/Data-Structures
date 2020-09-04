#include <stdio.h>
#include "pilaEst.h"

int main (void)
{
	return 0;
}
void initialize(Pila *p)
{
	if(p == NULL)
	{
		return;
	}
	p->tope = -1;
}
void push(Pila *p, Elemento e)
{
	if(p == NULL)
	{
		return;
	}
	else if(p->tope == 10000)
	{
		printf("No es posible insertar el " 
			"elemento la pila esta llena\n");
	}
	else
	{
		p->tope++;
		p->array[p->tope] = e;
	}
}
Elemento pop(Pila *p)
{
  Elemento r;
	if(p == NULL)
	{
		return;
	}
	else if(isEmpty(p) == 1)
	{
		printf("La pila esta vacia\n");
	}
	else
	{
		r = p->array[p->tope];
		p->tope--;
		return r;
	}
}
int isEmpty(Pila *p)
{
	if(p == NULL)
	{
		return;
	}
	else if(p->tope == -1)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
Elemento top(Pila *p)
{
	if(p == NULL)
	{
		return;
	}
	else if(isEmpty(p)==0)
	{
		printf("La pila esta vacia");
	}
	else
	{
		return p->array[p->tope];	
	}
}
int size(Pila *p)
{
	if(p == NULL)
	{
		return;
	}
	return p->tope++;
}
void destroy(Pila *p)
{
		if(p == NULL)
	{
		return;
	}
	initialize(p);

}
