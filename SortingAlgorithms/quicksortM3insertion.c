#include <stdlib.h>

// This implementation of quicksort is for integer arrays. But since the algorithm can be used to sort any kind of data type,
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

int partition(DATA_TYPE *v,int leftIndex, int rightIndex)
{

    DATA_TYPE valueToCompare = v[rightIndex];
    int j = leftIndex;

    for(int k = leftIndex; k< rightIndex ; k++)
        if(v[k]<=valueToCompare)
        {

            int temporaryValue = v[k];
            v[k] = v[j];
            v[j] = temporaryValue;
            j++;

        }

    int temporaryValue = v[j];
    v[j] = v[r];
    v[r] = temporaryValue;


    return j;


}

void quickSort(DATA_TYPE *v, int leftIndex, int rightIndex)
{

    if(rightIndex-leftIndex<=32)
    {
        insertionSort(v,leftIndex,rightIndex);
        return;

    }
    int middleIndex = (leftIndex+rightIndex)/2;

    DATA_TYPE middleValue = v[middleIndex];
    v[middleIndex] = v[rightIndex-1];
    v[rightIndex-1] = middleValue;

    if(v[leftIndex]>v[rightIndex-1])
    {
        DATA_TYPE temporaryValue = v[leftIndex];
        v[leftIndex] = v[rightIndex-1];
        v[rightIndex-1] = temporaryValue;
    }

    if(v[rightIndex]<v[leftIndex])
    {
        DATA_TYPE temporaryValue = v[rightIndex];
        v[rightIndex] = v[leftIndex];
        v[leftIndex] = temporaryValue;
    }

    if(v[m]<v[r-1])
    {
        DATA_TYPE temporaryValue = v[rightIndex];
        v[rightIndex] = v[rightIndex-1];
        v[rightIndex-1] = temporaryValue;
    }


    int j = partition(v,leftIndex,rightIndex);
    quickSort(v,leftIndex,j-1);
    quickSort(v,j+1,rightIndex);


}
