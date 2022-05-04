#include <stdlib.h>

// This implementation of the stack data structure is for integer values. But since stacks can store and manipulate any kind of data type,
// I used typedef to illustrate that it can be adapted to any other kind of data type.
typedef int DATA_TYPE;

// linked list with a header node
typedef struct queue
{
    DATA_TYPE element;
    struct queue *nextNode;

} queue;

queue *createQueue()
{
    queue *q = malloc(sizeof(queue));
    q->nextNode = q;
    q->element = -1;
    return q;

}

void enqueue(queue **q, DATA_TYPE elementToInsert)
{
    queue *newNode = malloc(sizeof(queue));
    newNode->nextNode = (*q)->nextNode;
    (*q)->nextNode = newNode;
    (*q)->element = elementToInsert;
    *q = newNode;
    (*q)->element = -1;
}

DATA_TYPE dequeue(queue **q)
{
    queue *trashNode = malloc(sizeof(queue));
	trashNode = (*q)->nextNode;
	if(trashNode->element == -1) return -1;


	DATA_TYPE frontElement = trashNode->element;
	(*q)->nextNode = trashNode->nextNode;
	free(trashNode);

	return frontElement;
}
