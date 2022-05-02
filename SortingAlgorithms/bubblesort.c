#include <stdlib.h>

// This implementation of bubblesort is for integer arrays. But since the algorithm can be used to sort any kind of data type,
// I used typedef to illustrate that it can be adapted to any other kind of data type.
typedef int DATA_TYPE;

void bubbleSort(DATA_TYPE *array, int arraySize)
{
    DATA_TYPE temporaryValue = 0;
    for(int i = 0; i < arraySize - 1 ; i++)
    {
        for(int j = 0; j < arraySize - 1; j++)
        {
            if(array[j+1] < array[j])
            {
                temporaryValue = array[j];
                array[j] = array[j+1];
                array[j+1] = temporaryValue;
            }
        }
    }
}

