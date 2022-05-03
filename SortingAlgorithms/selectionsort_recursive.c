// This implementation of selectionSort is for integer arrays. But since the algorithm can be used to sort any kind of data type,
// I used typedef to illustrate that it can be adapted to any other kind of data type.
typedef int DATA_TYPE;

void selectionSort(DATA_TYPE *array, int leftIndex, int rightIndex)
{
	if(leftIndex==rightIndex) return;

    int smallestValuePosition = leftIndex;
    for(int j = leftIndex+1 ; j<=rightIndex; j++)
    {
        if(array[j] < array[smallestValuePosition])
            smallestValuePosition = j;
    }

    DATA_TYPE temporaryValue = array[smallestValuePosition];
    array[smallestValuePosition] = array[leftIndex];
    array[leftIndex] = temporaryValue;

    selectionSort(array,leftIndex+1,rightIndex);
}
