#include "swap.h"
#include "selectionsort.h"

void selectionSort(int* array, const int arraySize)
{
    int smallestValue = 0;
    int position_Of_SmallestValue = 0;

    for(int i = 0; i < arraySize; i++)
    {
        smallestValue = array[i];

        for(int j = i+1; j < arraySize; j++)
        {
            if(array[j] < smallestValue)
            {
                smallestValue = array[j];
                position_Of_SmallestValue = j;

            }
        }

        if(smallestValue != array[i])
        {
            swap(array, i, position_Of_SmallestValue);
        }
    }
}
