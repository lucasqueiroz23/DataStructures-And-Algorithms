#include "swap.h"
#include "partition.h"


int partition(int* array, int leftIndex, int rightIndex) {

    int valueToCompare = array[rightIndex];
    int j = leftIndex;

    for(int k = leftIndex; k < rightIndex; k++)
        if(array[k] <= valueToCompare) {

            swap(array, k, j);
            j++;

        }

    swap(array, j, rightIndex);

    return j;

}
