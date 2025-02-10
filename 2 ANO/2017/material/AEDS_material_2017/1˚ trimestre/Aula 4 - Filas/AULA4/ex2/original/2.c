#include "fila2.h"
#include <stdio.h>

int main(){

	Fila2 *f = fila2_cria();
	Fila2L *l;
	fila2_insere_ini(f,1);
	fila2_insere_ini(f,2);
	fila2_insere_ini(f,3);
	fila2_insere_fim(f,4);
	fila2_imprime_vet(f);
	printf("tirei o %f\n",fila2_retira_ini(f));
	fila2_imprime_vet(f);
	printf("tirei o %f\n",fila2_retira_fim(f));
	fila2_imprime_vet(f);
	fila2_insere_ini(f,5);
	fila2_imprime_vet(f);
	fila2_libera(f);
	printf("------\n");
	l = fila2_cria_L();
	fila2_insere_ini_L(l,1);
	fila2_insere_ini_L(l,2);
	fila2_insere_ini_L(l,3);
	fila2_insere_fim_L(l,4);
	fila2_imprime_L(l);
	printf("tirei o %f\n",fila2_retira_fim_L(l));
	fila2_imprime_L(l);
	printf("tirei o %f\n",fila2_retira_ini_L(l));
	fila2_imprime_L(l);
	fila2_libera_L(l);
}