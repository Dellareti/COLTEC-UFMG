#include <stdio.h>
#include <stdlib.h>
#include "grafo.h"


int main(){

	Grafo *v = cria_grafo(0);
	Grafo *v1 = insere_como_adjacente(v,1);
	Grafo *v2 = insere_como_adjacente(v,2);
	Grafo *v3 = insere_como_adjacente(v1,3);
	Grafo *v4 = insere_como_adjacente(v1,4);
	Grafo *v5 = insere_como_adjacente(v2,5);
	Grafo *v6 = insere_como_adjacente(v2,6);
	conecta_vertices(v,v1);


	imprime_grafo(v);
	zera_estados(v);
	imprime_grafo(v);
	zera_estados(v);

	Grafo * b = NULL;
	b = busca_grafo(v,6);
	zera_estados(v);
}