#include <stdio.h>
#include "pilhas.h"

int main(){
	Pilha_l *teste = pilha_l_cria();

	pilha_l_push(teste,'a');
	pilha_l_push(teste,'b');
	pilha_l_push(teste,'c');

	printf("retirei o %c\n",pilha_l_pop(teste));

	pilha_l_libera(teste);

}
