#include <stdio.h>
#include <stdlib.h>

///quickSort para inteiros. Adaptar o algoritmo para outros tipos de dado.

int separa(int *v,int l, int r)
{

    int c = v[r];
    int j = l;
    for(int k = l; k< r ; k++)
        if(v[k]<=c)
        {
            int tmp = v[k];
            v[k] = v[j];
            v[j] = tmp;
            j++;

        }
    int tmp = v[j];
    v[j] = v[r];
    v[r] = tmp;

    //printf("separa(v,%d,%d) = %d \n\n",l,r,j);
    return j;


}

void quickSort(int *v, int l, int r)
{
    printf("quickSort(v,%d,%d)\n",l,r);
    if(r<=l) return;
    int j = separa(v,l,r);
    quickSort(v,l,j-1);
    quickSort(v,j+1,r);


}

int main()
{
    int *v = malloc(100*sizeof(int));
    int k=100;
    for(int i=0;i<100;i++)
    {
        v[i] = k--;

    }
    for(int i=0;i<100;i++) printf("v[%d] = %d\n",i,v[i]);

    quickSort(v,0,99);
    for(int i=0;i<100;i++) printf("v[%d] = %d\n",i,v[i]);

    free(v);


    return 0;
}
