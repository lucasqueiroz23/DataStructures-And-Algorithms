#include <stdlib.h>
#include <stdio.h>

// This implementation of the binary search is for integer arrays. But since the algorithm can be used to search any kind of data type,
// I used typedef to illustrate that it can be adapted to any other kind of data type.
typedef int DATA_TYPE;

int binarySearch(DATA_TYPE *array, int arraySize, DATA_TYPE targetValue)
{
	int leftIndex = -1;
	int rightIndex = arraySize;

	if(array[leftIndex] == targetValue) return leftIndex;
	if(array[rightIndex] == targetValue) return rightIndex;

	while(leftIndex < rightIndex -1)
	{
		int middleIndex = (leftIndex + rightIndex)/2;
		if(array[middleIndex] == targetValue) return middleIndex;

		if(array[middleIndex] < targetValue) leftIndex = middleIndex;
		else rightIndex = middleIndex;
	}

	return -1;
}
