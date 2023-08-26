#include "swap.h"
#include "insertionsort_SLOW.h"

void insertionSort(int *array, const int ARRAY_SIZE)
{
    for(int i = 0; i < ARRAY_SIZE; i++)
    {
        for(int j = i + 1; j > 0; j--)
        {
            if(array[j] < array[j-1])
            {
                swap(array, j, j - 1);
            }
            else break;
        }
    }
}
