#include <stdio.h>
#include "pilhas.h"

int main(){
	Pilha_l *teste = pilha_l_cria();

	pilha_l_push(teste,'o');
	pilha_l_push(teste,'t');
	pilha_l_push(teste,'a');
	pilha_l_push(teste,'t');
	pilha_l_push(teste,'i');

	printf("\tPilha de Ayra Stark \n\n");
	
	printf("\nMatei o %c\n",pilha_l_pop(teste));
	printf("Matei o %c\n",pilha_l_pop(teste));
	printf("Matei o %c\n",pilha_l_pop(teste));
	printf("Matei o %c\n",pilha_l_pop(teste));
	printf("Matei o %c\n",pilha_l_pop(teste));

	pilha_l_libera(teste);

}
