#include <stdlib.h>

// This implementation of the stack data structure is for integer values. But since stacks can store and manipulate any kind of data type,
// I used typedef to illustrate that it can be adapted to any other kind of data type.
typedef int DATA_TYPE;

typedef struct stack
{
	DATA_TYPE *stackArray;
	int topOfStack;
	int stackSize;

} stack;

stack *createStack(int stackSize)
{
	stack *st = malloc(sizeof(stack));
	st->stackSize = stackSize;
	st->stackArray = malloc(stackSize*sizeof(DATA_TYPE));
	st->topOfStack = 0;
	return st;
}

int queue_isEmpty(stack *st)
{
	if(st->topOfStack == 0) return 1;

	return 0;
}

int queue_isFull(stack *st)
{
	if(st->topOfStack == st->stackSize) return 1;

	return 0;
}

int pop(stack *st, DATA_TYPE *value)
{
	if(queue_isEmpty(st)) return 0;

	st->topOfStack--;
	*value = st->stackArray[st->topOfStack];
	return 1;

}

int pull(stack *st, int valueToInsert)
{
	if(queue_isFull(st))
	{
		st->stackArray = realloc(st->stackArray, 2*st->stackSize * sizeof(DATA_TYPE));
		if(st->stackArray == NULL) return 0;
		st->stackSize *= 2;
	}

	st->stackArray[st->topOfStack] = valueToInsert;
	st->topOfStack++;
	return 1;

}


