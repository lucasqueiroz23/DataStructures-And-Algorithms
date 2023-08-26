#include <stdlib.h>
#include "mergesort.h"

void merge(int *array, int leftIndex, int middleIndex, int rightIndex)
{
    int *v2 = malloc(sizeof(int) * (rightIndex - leftIndex + 1));

    int k = 0;  
    int i = leftIndex;
    int j = middleIndex + 1;

    while(i <= middleIndex && j <= rightIndex)
    {
        if(array[i]<=array[j])
        {
            v2[k++] = array[i++];
        }
        else v2[k++] = array[j++];
    }

    while(i <= middleIndex)
        v2[k++] = array[i++];
    while(j <= rightIndex)
        v2[k++] = array[j++];

    k = 0;

    for(i = leftIndex; i <= rightIndex; i++)
    {
        array[i] = v2[k++];
    }

    free(v2);
}

void mergeSort(int *array, int leftIndex, int rightIndex)
{
    if(leftIndex >= rightIndex) return;
    int middleIndex = (leftIndex + rightIndex)/2;
    mergeSort(array, leftIndex, middleIndex);
    mergeSort(array, middleIndex + 1, rightIndex);
    merge(array, leftIndex, middleIndex, rightIndex);
}


