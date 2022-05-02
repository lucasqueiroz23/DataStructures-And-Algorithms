#include <stdlib.h>

// This implementation of selectionSort is for integer arrays. But since the algorithm can be used to sort any kind of data type,
// I used typedef to illustrate that it can be adapted to any other kind of data type.
typedef int DATA_TYPE;

void selectionSort(DATA_TYPE *array, int arraySize)
{
    DATA_TYPE smallestValue = 0;
    DATA_TYPE position_Of_SmallestValue = 0, temporaryValue = 0;

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
            temporaryValue = array[i];
            array[i] = array[position_Of_SmallestValue];
            array[position_Of_SmallestValue] = temporaryValue;

        }
    }
}
