#include <stdlib.h>

// This implementation of quickSelect is for integer arrays. But since the algorithm can be used to sort any kind of data type,
// I used typedef to illustrate that it can be adapted to any other kind of data type.
typedef int DATA_TYPE;

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

void quickSelect(DATA_TYPE *v, DATA_TYPE valueToSort, int leftIndex, int rightIndex)
{
	DATA_TYPE j = partition(v,leftIndex,rightIndex);
	if(j == valueToSort) return;
	if(j<valueToSort)
		quickSelect(v,valueToSort,j+1,rightIndex);
	else
		quickSelect(v,valueToSort,leftIndex,j-1);

}
