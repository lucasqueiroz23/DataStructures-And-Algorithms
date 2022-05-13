#include <stdlib.h>

// This implementation of the sequential search is for integer arrays. But since the algorithm can be used to search any kind of data type,
// I used typedef to illustrate that it can be adapted to any other kind of data type.
typedef int DATA_TYPE;

int sequentialSearch(DATA_TYPE *array, int arraySize, int targetValue)
{
	for(int i = 0; i<arraySize; i++)
		if(array[i] == targetValue) return i;

	return -1;
}
