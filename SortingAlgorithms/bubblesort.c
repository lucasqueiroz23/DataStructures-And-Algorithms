#include "swap.h"
#include "bubblesort.h"

void bubbleSort(int* array, const int arraySize)
{
    for(int i = 0; i < arraySize - 1; i++)
    {
        for(int j = 0; j < arraySize - 1; j++)
        {
            if(array[j+1] < array[j])
            {
                swap(array, j, j + 1);
            }
        }
    }
}

