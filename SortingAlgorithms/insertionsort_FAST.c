#include <stdlib.h>

// This implementation of mergesort is for integer arrays. But since the algorithm can be used to sort any kind of data type,
// I used typedef to illustrate that it can be adapted to any other kind of data type.
typedef int DATA_TYPE;

void insertionSort(DATA_TYPE *v, int leftIndex, int rightIndex)
{
    int temporaryValue=0;
    for(int i=leftIndex; i<rightIndex; i++)
    {

        if(v[i]>v[i+1])
        {
            temporaryValue=v[i];
            v[i]=v[i+1];
            v[i+1]=temporaryValue;

        }
    }
    for(int i=leftIndex; i<rightIndex; i++)
    {
        for(int j = i+1; j>leftIndex; j--)
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
