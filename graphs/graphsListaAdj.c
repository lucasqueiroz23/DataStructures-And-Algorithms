#include <stdlib.h>
#include <stdio.h>

/// LISTA DE ADJACENCIAS

// "celula" representa cada node de uma lista encadeada
typedef struct celula
{
    int vertice;
    struct celula *prox;
} celula;

typedef struct graph
{
    int quantidadeVertices, quantidadeArestas;
    celula **listaDeAdjacencias;

} graph;

typedef struct aresta
{
    int vertice1;
    int vertice2;

} aresta;

aresta inicializaAresta(int v1,int v2)
{
    aresta a;

    a.vertice1 = v1;
    a.vertice2 = v2;

    return a;
}

celula *criaNoCabeca()
{
    celula *novaCelula = malloc(sizeof(celula));
    novaCelula->vertice = -1;
    novaCelula->prox = NULL;

    return novaCelula;
}

void criaAdjacencia(int valorDoVertice, celula *noCabeca)
{
    celula *novaCelula = malloc(sizeof(celula));
    novaCelula->vertice = valorDoVertice;
    novaCelula->prox = noCabeca->prox;
    noCabeca->prox = novaCelula;
}

graph *graphInit(int qtdVertices)
{
    graph *g = malloc(sizeof(graph));
    g->quantidadeVertices = qtdVertices;
    g->quantidadeArestas = 0;
    g->listaDeAdjacencias = malloc(qtdVertices*sizeof(celula));

    for(int i = 0; i< qtdVertices; i++)
        g->listaDeAdjacencias[i] = criaNoCabeca();

    return g;
}

void insereAresta(graph *g,aresta a)
{
    int v1 = a.vertice1;
    int v2 = a.vertice2;
    criaAdjacencia(v2, g->listaDeAdjacencias[v1]);
    criaAdjacencia(v1, g->listaDeAdjacencias[v2]);

}


/// funcao remove aresta mal escrita. Reescrever quando tiver tempo para ficar mais legivel.
/// OBS: FUNCAO AINDA NAO TESTADA!
void removeAresta(graph *g,aresta a)
{
    int v1 = a.vertice1;
    int v2 = a.vertice2;

    celula *c1 = g->listaDeAdjacencias[v1];
    celula *c2 = g->listaDeAdjacencias[v2];

    while(c1->prox->vertice!= v2 && c1!= NULL)
        c1 = c1->prox;

    if(c1 == NULL) return; ///nao existe conexao

    while(c2->prox->vertice!= v1 )
        c2 = c2->prox;

    celula *novo1 = c1->prox;
    celula *novo2 = c2->prox;

    c1->prox = novo1->prox;
    c2->prox = novo2->prox;

    free(novo1);
    free(novo2);


}

int devolveQuantidadeArestas_E_formaVetorDeArestas(aresta a[],graph *g)
{
    int quantidadeArestas = 0;
    for(int indiceVertices = 0; indiceVertices<g->quantidadeVertices; indiceVertices++)
        for(celula *indiceCelulas = g->listaDeAdjacencias[indiceVertices] ; indiceCelulas!=NULL ; indiceCelulas = indiceCelulas->prox)
            if(indiceVertices < indiceCelulas -> vertice) a[quantidadeArestas++] = inicializaAresta(indiceVertices,indiceCelulas->vertice);

    return quantidadeArestas;
}

int *verticesJaVisitados;

int *iniciaVetor_verticesJaVisitados(int qtdVertices)
{
    int *vetor = malloc(qtdVertices*sizeof(int));
    for(int i = 0; i<qtdVertices; i++)
        vetor[i] = 0;
    return vetor;
}

void DFS_buscaEmProfundidade_RECURSIVA(graph *g, aresta a)
{
    int v2 = a.vertice2;
    verticesJaVisitados[v2] = 1;

    for(celula *indiceVertices = g->listaDeAdjacencias[v2]->prox; indiceVertices!=NULL; indiceVertices = indiceVertices->prox)
    {
        int v1 = indiceVertices->vertice;
        if(verticesJaVisitados[v1] == 0)
        {
            aresta novaAresta;
            novaAresta.vertice1 = v2;
            novaAresta.vertice2 = v1;
            DFS_buscaEmProfundidade_RECURSIVA(g, novaAresta);
        }
    }
}

int devolveQuantidadeDeComponentesConexos(graph *g)
{
    int qtdConexos = 0;
    for(int indiceDeVertices = 0; indiceDeVertices < g->quantidadeVertices; indiceDeVertices++)
    {
        if(verticesJaVisitados[indiceDeVertices] == 0)
        {
            aresta novaAresta;
            novaAresta.vertice1 = indiceDeVertices;
            novaAresta.vertice2 = indiceDeVertices;

            DFS_buscaEmProfundidade_RECURSIVA(g,novaAresta);
            qtdConexos++;

        }
    }

    return qtdConexos;
}


// implementacao de fila circular utilizando listas encadeadas
typedef struct fila
{
    aresta aAresta;
    struct fila *prox;

} fila;

fila *criaFila()
{
    fila *novaFila = malloc(sizeof(fila));

    novaFila->prox = novaFila;
    novaFila->aAresta.vertice1 = -1;
    novaFila->aAresta.vertice2 = -1;

    return novaFila;
}

void enfileira(fila **f, aresta a)
{
    fila *novaCelula = malloc(sizeof(fila));
    novaCelula->prox = (*f)->prox;
    (*f)->prox = novaCelula;
    (*f)->aAresta.vertice1 = a.vertice1;
    (*f)->aAresta.vertice2 = a.vertice2;

    *f = novaCelula;
    (*f)->aAresta.vertice1 = -1;
    (*f)->aAresta.vertice2 = -1;
}

void desenfileira(fila **f)
{
    fila *novaCelula = malloc(sizeof(fila));
    novaCelula = (*f)->prox;
    if(novaCelula->aAresta.vertice1 == -1) /// FILA VAZIA!
    {
        return;
    }

    (*f)->prox = novaCelula->prox;
    free(novaCelula);

}

void BFS_buscaEmLargura(graph *g, aresta a)
{
    fila *f = criaFila();

    int v2 = a.vertice2;
    verticesJaVisitados[v2] = 1;

    enfileira(&f,a);

    while(f->prox->aAresta.vertice1!=-1 && f->prox->aAresta.vertice2 != -1)
    {
        a.vertice1 = f->prox->aAresta.vertice1;
        a.vertice2 = f->prox->aAresta.vertice2;
        desenfileira(&f);
        v2 = a.vertice2;

        for(celula *indiceVertices = g->listaDeAdjacencias[v2]->prox; indiceVertices!=NULL; indiceVertices = indiceVertices->prox)
        {
            int v1 = indiceVertices->vertice;
            if(verticesJaVisitados[v1] == 0)
            {
                aresta novaAresta;
                novaAresta.vertice1 = v2;
                novaAresta.vertice2 = v1;

                enfileira(&f,novaAresta);
                verticesJaVisitados[v1] = 1;

            }
        }
    }
}

/// GRAFOS DIRIGIDOS (DIGRAPHS)

void insereAresta_DIRECAO_UNICA(graph *g,aresta a)
{
    int v1 = a.vertice1;
    int v2 = a.vertice2;

    criaAdjacencia(v2, g->listaDeAdjacencias[v1]);

}

graph *inverteArestas_DIGRAPH(graph* g)
{
    graph *novoGrafo = graphInit(g->quantidadeVertices);
    for(int indexVertices = 0; indexVertices < g->quantidadeVertices ; indexVertices++)
        for(celula *indexArestas = g->listaDeAdjacencias[indexVertices]->prox; indexArestas!=NULL; indexArestas = indexArestas->prox)
        {
			aresta novaAresta;
			novaAresta.vertice1 = indexArestas->vertice;
			novaAresta.vertice2 = indexVertices;

			insereAresta_DIRECAO_UNICA(novoGrafo,novaAresta);
        }

	return novoGrafo;
}

