#include "fila.h"
#include <stdio.h>

int main(){
	FilaL *teste = fila_cria_l();
	fila_insere_l(teste,"1");
	fila_insere_l(teste,"1");
	fila_insere_l(teste,"3");
	fila_insere_l(teste,"4");
	fila_insere_l(teste,"5");
	printf("tirei o %.s da fila\n",fila_retira_l(teste));
	fila_imprime_l(teste);

	fila_libera_l(teste);


}
