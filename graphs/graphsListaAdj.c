#include <stdlib.h>
#include <stdio.h>

int infinity = 2147483647;

/// LISTA DE ADJACENCIAS

// "celula" representa cada node de uma lista encadeada
typedef struct celula
{
    int vertice;
    int peso;
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
    int peso;

} aresta;

aresta inicializa_aresta(int v1,int v2, int pesoDaAresta)
{
    aresta a;

    a.vertice1 = v1;
    a.vertice2 = v2;
    a.peso = pesoDaAresta;


    return a;
}

celula *cria_no_cabeca(int vertice)
{
    celula *novaCelula = malloc(sizeof(celula));
    novaCelula->vertice = vertice;
    novaCelula->prox = NULL;

    return novaCelula;
}

void cria_adjacencia(int valorDoVertice, celula *noCabeca, int peso)
{
    celula *novaCelula = malloc(sizeof(celula));
    novaCelula->vertice = valorDoVertice;
    novaCelula->peso = peso;
    novaCelula->prox = noCabeca->prox;
    noCabeca->prox = novaCelula;
}

graph *graphInit(int qtdVertices)
{
    int i;
    graph *g = malloc(sizeof(graph));
    g->quantidadeVertices = qtdVertices;
    g->quantidadeArestas = 0;
    g->listaDeAdjacencias = malloc(qtdVertices*sizeof(celula));

    for(i = 0; i< qtdVertices; i++)
        g->listaDeAdjacencias[i] = criaNoCabeca(i);

    return g;
}

void insere_aresta(graph *g,aresta a)
{
    int peso = a.peso;
    int v1 = a.vertice1;
    int v2 = a.vertice2;
    criaAdjacencia(v2, g->listaDeAdjacencias[v1], peso);
    criaAdjacencia(v1, g->listaDeAdjacencias[v2], peso);

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

int devolve_quantidade_arestas_e_forma_vetor_de_arestas(aresta a[],graph *g)
{
    int quantidadeArestas = 0;
    for(int indiceVertices = 0; indiceVertices<g->quantidadeVertices; indiceVertices++)
        for(celula *indiceCelulas = g->listaDeAdjacencias[indiceVertices] ; indiceCelulas!=NULL ; indiceCelulas = indiceCelulas->prox)
            if(indiceVertices < indiceCelulas -> vertice) a[quantidadeArestas++] = inicializaAresta(indiceVertices,indiceCelulas->vertice,indiceCelulas->peso);

    return quantidadeArestas;
}

int *verticesJaVisitados;

int *inicia_vetor_vertices_ja_visitados(int qtdVertices)
{
    int *vetor = malloc(qtdVertices*sizeof(int));
    for(int i = 0; i<qtdVertices; i++)
        vetor[i] = 0;
    return vetor;
}

void DFS(graph *g, aresta a)
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

int devolve_quantidade_de_componentes_conexos(graph *g)
{
    int qtdConexos = 0;
    verticesJaVisitados = iniciaVetor_verticesJaVisitados(g->quantidadeVertices);
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

void BFS(graph *g, aresta a)
{
    fila *f = criaFila();

    int v2 = a.vertice2;
    verticesJaVisitados[v2] = 1;

    enfileira(&f,a);

    while(f->prox->aAresta.vertice1!=-1 && f->prox->aAresta.vertice2 != -1) /// FILA VAZIA!
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

void insere_aresta_DIRECAO_UNICA(graph *g,aresta a)
{
    int peso = a.peso;
    int v1 = a.vertice1;
    int v2 = a.vertice2;

    criaAdjacencia(v2, g->listaDeAdjacencias[v1], peso);

}

graph *inverte_arestas_DIGRAPH(graph* g)
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

typedef struct filaDeVertices
{
    int vertice;
    struct filaDeVertices *prox;

} filaDeVertices;

filaDeVertices *criaFilaDeVertices()
{
    filaDeVertices *novaFila = malloc(sizeof(filaDeVertices));

    novaFila->prox = novaFila;
    novaFila->vertice = -1;

    return novaFila;
}

void enfileiraFilaDeVertices(filaDeVertices **f, int vertice)
{
    filaDeVertices *novaCelula = malloc(sizeof(filaDeVertices));
    novaCelula->prox = (*f)->prox;
    (*f)->prox = novaCelula;
    (*f)->vertice = vertice;

    *f = novaCelula;
    (*f)->vertice = -1;
}

int desenfileiraFilaDeVertices(filaDeVertices **f)
{
    filaDeVertices *novaCelula = malloc(sizeof(filaDeVertices));
    novaCelula = (*f)->prox;
    if(novaCelula->vertice == -1) /// FILA VAZIA!
    {
        return -1;
    }

    int x = novaCelula->vertice;

    (*f)->prox = novaCelula->prox;
    free(novaCelula);

    return x;
}

int bellman_ford(graph *g,int vertice, int *pa, int *distanciaEntreVertices)
{
    int naFila[g->quantidadeVertices];
    for(int i = 0; i<g->quantidadeVertices; i++)
    {
        pa[i] = -1;
        distanciaEntreVertices[i] = infinity;
        naFila[i] = 0;
    }
    pa[vertice] = vertice;
    distanciaEntreVertices[vertice] = 0;
    filaDeVertices *fila = criaFilaDeVertices();
    enfileiraFilaDeVertices(&fila,vertice);
    naFila[vertice] = 1;
    enfileiraFilaDeVertices(&fila,g->quantidadeVertices);
    int k = 0;
    while(1)
    {
        int v = desenfileiraFilaDeVertices(&fila);
        if(v < g->quantidadeVertices)
        {
            for(celula *a = g->listaDeAdjacencias[v]->prox; a!=NULL; a = a->prox)
            {
                if(distanciaEntreVertices[v] + a->peso < distanciaEntreVertices[a->vertice])
                {
                    distanciaEntreVertices[a->vertice] = distanciaEntreVertices[v] + a->peso;
                    pa[a->vertice] = v;
                    if(naFila[a->vertice] == 0)
                    {
                        enfileiraFilaDeVertices(&fila,a->vertice);
                        naFila[a->vertice] = 1;
                    }
                }
            }
        }
        else
        {
            if(fila->prox->vertice==-1) return 1;
            if(++k >= g->quantidadeVertices) return 0;
            enfileiraFilaDeVertices(&fila,v);
            for(int t = 0; t<g->quantidadeVertices; t++)
                naFila[t] = 0;
        }
    }

}

void dijkstra(graph *g, int source)
{

    int *mature = malloc(g->quantidadeVertices*sizeof(int));
    int *distances = malloc(g->quantidadeVertices*sizeof(int));
    int *parent = malloc(g->quantidadeVertices*sizeof(int));

    for(int v = 0; v < g->quantidadeVertices; v++)
    {
        parent[v] = -1;
        distances[v] = infinity;
        mature[v] = 0;
    }

    parent[source] = source;
    distances[source] = 0;

    while(1)
    {
        int min = infinity;
        int y;

        for(int z = 0; z < g->quantidadeVertices; z++)
        {
            if(mature[z]) continue;
            if(distances[z] < min)
            {
                min = distances[z];
                y = z;
            }
        }

        if(min == infinity) break;

        for(celula *t = g->listaDeAdjacencias[y]; t != NULL; t = t->prox)
        {
            if(mature[t->vertice] == 1) continue;
            if(distances[y] + t->peso < distances[t->vertice])
            {
                distances[t->vertice] = distances[y] + t->peso;
                parent[t->vertice] = y;
            }
        }
        mature[y] = 1;
    }

}

