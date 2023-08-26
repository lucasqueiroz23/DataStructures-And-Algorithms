#include "swap.h"
#include "insertionsort_FAST.h"
#include "partition.h"


void quickSort(int* array, int leftIndex, int rightIndex)
{

    if(rightIndex-leftIndex <= 32)
    {
        insertionSort(array, leftIndex, rightIndex);
        return;

    }
    int middleIndex = (leftIndex + rightIndex)/2;

    int middleValue = array[middleIndex];
    swap(array, middleIndex, rightIndex - 1);

    if(array[leftIndex] > array[rightIndex - 1])
        swap(array, leftIndex, rightIndex - 1);

    if(array[rightIndex] < array[leftIndex])
        swap(array, leftIndex, rightIndex);

    if(array[middleIndex] < array[rightIndex - 1])
        swap(array, middleIndex, rightIndex - 1);

    int j = partition(array, leftIndex,rightIndex);
    quickSort(array, leftIndex, j - 1);
    quickSort(array, j + 1, rightIndex);
}
