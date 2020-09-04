/*Header for a Queue Structure*/

typedef struct Queue
{
	int data[100];
	int front;
	int back;
	int size;
}Queue;

void inizialize(Queue *q);
void queue(Queue *q, int elemento);
int dequeue (Queue *q);
int isEmpty(Queue *q);
int front(Queue *q);
int back(Queue *q);
int size(Queue *q);
void destroy(Queue *q);
