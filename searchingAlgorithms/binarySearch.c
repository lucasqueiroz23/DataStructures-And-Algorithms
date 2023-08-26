#include <stdlib.h>
#include <stdio.h>
#include "binarySearch.h"


int binarySearch(int *array, int arraySize, int targetValue)
{
	int leftIndex = 0;
	int rightIndex = arraySize - 1;

	if(array[leftIndex] == targetValue) return leftIndex;
	if(array[rightIndex] == targetValue) return rightIndex;

	while(leftIndex < rightIndex - 1)
	{
		int middleIndex = (leftIndex + rightIndex)/2;
		if(array[middleIndex] == targetValue) return middleIndex;

		if(array[middleIndex] < targetValue) leftIndex = middleIndex;
		else rightIndex = middleIndex;
	}

	return -1;
}
