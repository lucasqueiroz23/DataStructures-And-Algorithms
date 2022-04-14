#include <stdlib.h>

// This implementation of mergesort is for integer arrays. But since the algorithm can be used to sort any kind of data type,
// I used typedef to illustrate that it can be adapted to any other kind of data type.
typedef int DATA_TYPE;

void merge(DATA_TYPE *v, int leftIndex, int middleIndex, int rightIndex)
{
    DATA_TYPE *v2 = malloc(sizeof(DATA_TYPE)*(rightIndex-leftIndex+1));

    int k = 0;  // k is an index that will be used to traverse through v2
    int i = leftIndex;
    int j = middleIndex+1;

    while(i<=middleIndex && j<=rightIndex)
    {
        if(v[i]<=v[j])
        {
            v2[k++] = v[i++];
        }
        else v2[k++] = v[j++];
    }

    while(i<=middleIndex)
        v2[k++] = v[i++];
    while(j<=rightIndex)
        v2[k++] = v[j++];

    k=0;

    for(i = leftIndex; i<=rightIndex; i++)
    {
        v[i] = v2[k++];
    }


    free(v2);

}

void mergeSort(DATA_TYPE *v, int leftIndex, int rightIndex)
{
    if(leftIndex>=rightIndex) return;
    int middleIndex = (leftIndex+rightIndex)/2;
    mergeSort(v,leftIndex,middleIndex);
    mergeSort(v,middleIndex+1,rightIndex);
    merge(v,leftIndex,middleIndex,rightIndex);

}


