#include "binarySearch.h"

int sequentialSearch(int *array, int arraySize, int targetValue)
{
	for(int i = 0; i < arraySize; i++)
		if(array[i] == targetValue) return i;

	return -1;
}

