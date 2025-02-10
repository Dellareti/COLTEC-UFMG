#include <stdio.h>
#include "grafo.h"


int main(){
	Grafo *novo_grafo = cria_grafo(7,0,1);

	novo_grafo = faz_ligacao(novo_grafo,6,1,1);
	novo_grafo = faz_ligacao(novo_grafo,6,5,1);

	novo_grafo = faz_ligacao(novo_grafo,1,5,1);
	novo_grafo = faz_ligacao(novo_grafo,4,2,1);

	novo_grafo = faz_ligacao(novo_grafo,5,4,1);
	novo_grafo = faz_ligacao(novo_grafo,1,2,1);

	novo_grafo = faz_ligacao(novo_grafo,1,4,1);
	novo_grafo = faz_ligacao(novo_grafo,5,2,1);
	
	novo_grafo = faz_ligacao(novo_grafo,4,3,1);
	novo_grafo = faz_ligacao(novo_grafo,2,3,1);

	imprime_informacoes_grafo(novo_grafo);
    busca_em_largura(novo_grafo,1);
	libera_grafo(novo_grafo);

}
