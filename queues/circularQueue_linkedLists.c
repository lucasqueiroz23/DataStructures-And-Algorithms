#include <stdlib.h>

// This implementation of the stack data structure is for integer values. But since stacks can store and manipulate any kind of data type,
// I used typedef to illustrate that it can be adapted to any other kind of data type.
typedef int DATA_TYPE;

// linked list with a header node
typedef struct queue
{
    DATA_TYPE element;
    struct queue *next_node;

} queue;

queue *create_queue()
{
    queue *q = malloc(sizeof(queue));
    q->next_node = q;
    q->element = -1;
    return q;

}

void enqueue(queue **q, DATA_TYPE new_item)
{
    queue *new_node = malloc(sizeof(queue));
    new_node->next_node = (*q)->next_node;
    (*q)->next_node = new_node;
    (*q)->element = new_item;
    *q = new_node;
    (*q)->element = -1;
}

DATA_TYPE dequeue(queue **q)
{
    queue *trash = malloc(sizeof(queue));
	trash = (*q)->next_node;
	if(trash->element == -1) return -1;


	DATA_TYPE front_element = trash->element;
	(*q)->next_node = trash->next_node;
	free(trash);

	return front_element;
}
