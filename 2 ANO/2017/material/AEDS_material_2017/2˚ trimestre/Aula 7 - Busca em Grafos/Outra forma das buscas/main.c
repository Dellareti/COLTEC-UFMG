#include <stdio.h>
#include "grafo.h"


int main(){
	Grafo novo_grafo = cria_grafo(6,0,1);
	novo_grafo = faz_ligacao(novo_grafo,0,1,1);
	novo_grafo = faz_ligacao(novo_grafo,1,2,1);
	novo_grafo = faz_ligacao(novo_grafo,2,3,1);
	novo_grafo = faz_ligacao(novo_grafo,3,5,1);
	novo_grafo = faz_ligacao(novo_grafo,1,5,1);
	novo_grafo = faz_ligacao(novo_grafo,1,4,1);

/*
		2 - 3
		|	|
	0 - 1 - 5
		|
		4


*/

	imprime_informacoes_grafo(novo_grafo);
	busca_em_profundidade(novo_grafo,0,9);
    busca_em_largura(novo_grafo,0,10);
	libera_grafo(novo_grafo);
}