#include <stdio.h>
#include <stdlib.h>
#include "listas.h"

int main(){

	Lista *l, *p;
	int in,quant;
	int i;

	l = lst_cria();

    printf("\n\n --------------------------- Problema de Jose ----------------------------------\n\n");

	printf("\n\n Por favor digite a quantidade de pessoas do suicidio coletivo : \n\n");
	scanf("%d", &quant);

	printf("\n\n Por favor digite por qual pessoa ira comecar a matar : \n\n");
	scanf("%d", &in);

	printf("\n\n");

        for(i = quant;i > 0;i--){
            l = lst_insere(l,i);
	}

	p=l;
	p = lst_circular(l);

	l = lst_busca(l, in);

	do
	{
		lcirc_imprime(l);
		printf("\n\n");
		lst_retira(l,l->prox->info);
	}


	while((l = l->prox) != l->prox);

	lcirc_imprime(l);

	printf("\n\n O que nao morreu foi : ");

	lcirc_imprime(l);

	printf("\n\n");

	return 0;
}
