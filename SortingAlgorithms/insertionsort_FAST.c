#include "swap.h"
#include "insertionsort_FAST.h"

void insertionSort(int *array, int leftIndex, int rightIndex)
{
    for(int i = leftIndex; i < rightIndex; i++)
    {

        if(array[i] > array[i+1])
        {
            swap(array, i, i+1);

        }
    }
    for(int i = leftIndex; i < rightIndex; i++)
    {
        for(int j = i + 1; j > leftIndex; j--)
        {
            if(array[j] < array[j-1])
            {
                swap(array, j, j - 1);
            }
            else break;
        }
    }

}
