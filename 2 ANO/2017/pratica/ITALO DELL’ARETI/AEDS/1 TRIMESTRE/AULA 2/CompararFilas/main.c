#include "listas.h"
#include <stdio.h>



int main(){
	Lista *minhaLista = lst_cria();
	Lista *minhaLista2 = lst_cria();
	minhaLista = lst_insere(minhaLista,4);
	minhaLista = lst_insere(minhaLista,3);
	minhaLista = lst_insere_ordenado(minhaLista,1);
	minhaLista2 = lst_insere_ordenado(minhaLista,1);
	minhaLista2 = lst_insere_ordenado(minhaLista,4);
	minhaLista2 = lst_insere_ordenado(minhaLista,3);
	lst_imprime(minhaLista);
	printf("------------\n");
	lst_imprime(minhaLista2);
	
	if(lst_igual(minhaLista,minhaLista2))
		printf("IGUAL\n");
	else
		printf("DIFERENTE\n");
}
