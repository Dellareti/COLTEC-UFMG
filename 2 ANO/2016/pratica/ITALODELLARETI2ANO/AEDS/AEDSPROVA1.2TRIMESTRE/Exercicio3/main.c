#include <stdio.h>
#include <stdlib.h>
#include "Grafo.h"

int main(){
    int eh_digrafo = 1;
    Grafo* gr = cria_Grafo(6, 6, 1);

    insereAresta(gr, 1, 6, eh_digrafo, 1);
    insereAresta(gr, 1, 5, eh_digrafo, 1);
    insereAresta(gr, 1, 4, eh_digrafo, 1);
    insereAresta(gr, 1, 2, eh_digrafo, 1);
    insereAresta(gr, 2, 1, eh_digrafo, 1);
    insereAresta(gr, 2, 5, eh_digrafo, 1);
    insereAresta(gr, 2, 4, eh_digrafo, 1);
    insereAresta(gr, 2, 3, eh_digrafo, 1);
    insereAresta(gr, 3, 2, eh_digrafo, 1);
    insereAresta(gr, 3, 4, eh_digrafo, 1);
    insereAresta(gr, 4, 5, eh_digrafo, 1);
    insereAresta(gr, 4, 3, eh_digrafo, 1);
    insereAresta(gr, 5, 6, eh_digrafo, 1);
    insereAresta(gr, 5, 1, eh_digrafo, 1);
    insereAresta(gr, 5, 2, eh_digrafo, 1);
    insereAresta(gr, 5, 4, eh_digrafo, 1);
    insereAresta(gr, 6, 5, eh_digrafo, 1);
    insereAresta(gr, 6, 1, eh_digrafo, 1);


    imprime_Grafo(gr);
    printf("\nBusca \n");
    int vis1[6], vis2[6];//Mesmo número de vertices do grafo.


    buscaLargura_Grafo(gr, 2, vis2);
    libera_Grafo(gr);

    return 0;
}

