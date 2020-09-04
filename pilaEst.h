/*Header for the implementation of a Stack structure*/

typedef struct Elemento
{
	int n;
}Elemento;

typedef struct Pila
{
	Elemento array[10000];
	int tope;
}Pila;

void initialize(Pila *p);
void push(Pila *p, Elemento e);
Elemento pop(Pila *p);
int isEmpty(Pila *p);
Elemento top(Pila *p);
int size(Pila *p);
void destroy(Pila *p);


