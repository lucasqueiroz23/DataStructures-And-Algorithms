#include <stdlib.h>

/// MATRIZ DE ADJACENCIA
typedef struct graph
{
    int quantidadeVertices, quantidadeArestas;
    int **matrizAdjacencia;
    int **fechoTransitivo;

} graph;

int **MATRIXInit(int qtdVertices,int valorDeInicializacao)
{
    int **matrix = malloc(qtdVertices*sizeof(int*));

    for(int i = 0; i<qtdVertices; i++)
        matrix[i] = malloc(qtdVertices*sizeof(int));

    for(int i = 0; i<qtdVertices; i++)
        for(int j = 0; j<qtdVertices; j++)
            matrix[i][j] = valorDeInicializacao;

    return matrix;
}

graph *graphInit(int qtdVertices) // inicializacao de grafos representados MATRICIALMENTE
{
    graph *g = malloc(sizeof(graph));
    g->quantidadeVertices = qtdVertices;
    g->quantidadeArestas = 0;
    g->matrizAdjacencia = MATRIXInit(qtdVertices,0);

    return g;
}

/// VETOR DE ARESTAS

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

void insereAresta(graph *g,aresta a)
{
    int v1 = a.vertice1;
    int v2 = a.vertice2;

    if(g->matrizAdjacencia[v1][v2] == 0) g->quantidadeArestas++;

    g->matrizAdjacencia[v1][v2] = 1;
    g->matrizAdjacencia[v2][v1] = 1;

}

void removeAresta(graph *g, aresta a)
{
    int v1 = a.vertice1;
    int v2 = a.vertice2;

    if(g->matrizAdjacencia[v1][v2] == 1) g->quantidadeArestas--;

    g->matrizAdjacencia[v1][v2] = 0;
    g->matrizAdjacencia[v2][v1] = 0;

}

int devolveQuantidadeArestas_E_formaVetorDeArestas(aresta a[],graph *g)
{
    int v1,v2, quantidadeArestas = 0;
    for(v1 = 0; v1 < g->quantidadeVertices; v1++)
        for(v2 = v1+1; v2<g->quantidadeVertices; v2++)
            if(g->matrizAdjacencia[v1][v2] == 1)
                a[quantidadeArestas++] = inicializaAresta(v1,v2);

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

    for(int v1 = 0; v1 < g->quantidadeVertices ; v1++)
        if(g->matrizAdjacencia[v2][v1] != 0)
            if(verticesJaVisitados[v1] == 0)
            {
				aresta novaAresta;
				novaAresta.vertice1 = v2;
				novaAresta.vertice2 = v1;
                DFS_buscaEmProfundidade_RECURSIVA(g, novaAresta);
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

void FloydWarshall(graph *g)
{
	int i,s,t;
	g->fechoTransitivo = MATRIXInit(g->quantidadeVertices,0);
	for(s = 0; s<g->quantidadeVertices;s++)
		for(t = 0; t< g->quantidadeVertices;t++)
			g->fechoTransitivo[s][t] = g->matrizAdjacencia[s][t];

	for(s = 0; s<g->quantidadeVertices;s++) g->fechoTransitivo[s][s] = 1;

	for(i = 0; i<g->quantidadeVertices;i++)
		for(s = 0;s<g->quantidadeVertices;s++)
			if(g->fechoTransitivo[s][i] == 1)
				for(t = 0; t< g->quantidadeVertices; t++)
					if(g->fechoTransitivo[i][t] == 1)
						g->fechoTransitivo[s][t] = 1;

}

int devolveAlcancabilidade(graph *g, int v1, int v2)
{
	return g->fechoTransitivo[v1][v2];
}

