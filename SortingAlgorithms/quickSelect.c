#include <stdlib.h>
#include "partition.h"
#include "quickSelect.h"


void quickSelect(int* array, int valueToSort, int leftIndex, int rightIndex) {
	int j = partition(array, leftIndex, rightIndex);
	if(j == valueToSort) return;
	if(j < valueToSort) quickSelect(array, valueToSort, j+1, rightIndex);
	else quickSelect(array, valueToSort, leftIndex, j-1);
}
