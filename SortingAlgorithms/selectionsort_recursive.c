#include "swap.h"
#include "selectionsort_recursive.h"

void selectionSort(int* array, int leftIndex, int rightIndex)
{
    if(leftIndex == rightIndex) return;

    int smallestValuePosition = leftIndex;
    for(int j = leftIndex + 1; j <= rightIndex; j++)
    {
        if(array[j] < array[smallestValuePosition])
            smallestValuePosition = j;
    }

    swap(array, smallestValuePosition, leftIndex);
    selectionSort(array,leftIndex+1,rightIndex);
}
