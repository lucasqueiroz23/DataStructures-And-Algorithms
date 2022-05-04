#include <stdlib.h>

// This implementation of the stack data structure is for integer values. But since stacks can store and manipulate any kind of data type,
// I used typedef to illustrate that it can be adapted to any other kind of data type.
typedef int DATA_TYPE;

typedef struct stack
{
	DATA_TYPE element;
	struct stack *nextNode;

} stack;

// This is a linked list with a header node
stack *createStack()
{
	stack *st = malloc(sizeof(stack));
	st->element = -1;
	st->nextNode = NULL;

	return st;
}

int queue_isEmpty(stack *st)
{
	if(st->nextNode == NULL) return 1;
	return 0;
}

void pull(stack *st, DATA_TYPE valueToInsert)
{
	stack *newNode = malloc(sizeof(stack));
	newNode->nextNode = st->nextNode;
	newNode->element = valueToInsert;
	st->nextNode = newNode;

}

DATA_TYPE pop(stack *st)
{
	if(queue_isEmpty(st)) return -1;

	stack *trashNode = malloc(sizeof(stack));
	trashNode = st->nextNode;

	DATA_TYPE elementAtTheTopOfStack = trashNode->element;
	st->nextNode = trashNode->nextNode;

	free(trashNode);

	return elementAtTheTopOfStack;
}

