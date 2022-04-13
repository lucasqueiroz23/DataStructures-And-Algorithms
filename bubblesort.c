#include <stdio.h>
#include <stdlib.h>

void ordenacaoDaBolha(int *v, int n)
{
    int tmp =0;
    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<n-1;j++)
        {
           if(v[j+1] < v[j])
           {
             tmp = v[j];
             v[j] = v[j+1];
             v[j+1] = tmp;
           }
        }
    }
}

void printaVetor(int *v, int tam)
{
    for(int i=0;i< tam;i++)
    {
        if(i+1 == tam)
        {
            printf("%d }",v[i]);
            break;
        }
        printf("%d, ",v[i]);
    }
}

int main()
{
    int qtdElementosVetor=0;
    printf("Digite a quantidade de elementos no vetor: ");
    scanf("%d",&qtdElementosVetor);

    int *vetor = malloc(qtdElementosVetor*sizeof(int));

    printf("\nDigite os elementos do vetor:\n");
    for(int i=0;i<qtdElementosVetor;i++)
    {
        printf("%do elemento: ",i+1);
        scanf("%d",&vetor[i]);
    }

    printf("\n\n");

    printf("O vetor eh definido pelos elementos, a principio, na seguinte ordem: { ");
    printaVetor(vetor,qtdElementosVetor);

    printf("\n");
    ordenacaoDaBolha(vetor,qtdElementosVetor);

    printf("O vetor, agora, eh definido pelos seguintes elementos, em ordem: { ");
    printaVetor(vetor,qtdElementosVetor);

    printf("\n");
    free(vetor);
    return 0;
}
