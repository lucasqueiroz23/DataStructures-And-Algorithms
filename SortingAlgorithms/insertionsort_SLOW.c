#include <stdlib.h>

// This implementation of insertionsort is for integer arrays. But since the algorithm can be used to sort any kind of data type,
// I used typedef to illustrate that it can be adapted to any other kind of data type.
typedef int DATA_TYPE;

void insertionSort(DATA_TYPE *v, int ARRAY_SIZE)
{
    DATA_TYPE temporaryValue=0;
    for(int i=0; i<ARRAY_SIZE; i++)
    {
        for(int j = i+1; j>0; j--)
        {
            if(v[j]<v[j-1])
            {
                temporaryValue = v[j-1];
                v[j-1] = v[j];
                v[j] = temporaryValue;
            }
            else break;
        }
    }
}
