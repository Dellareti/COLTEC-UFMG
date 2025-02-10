#include <stdio.h>
#include "pilha.h"

int TTT(Pilha *p){
	int soma=0;
	while(p->n > 1){
		if(p->vet[p->n -1] > 0)
			soma+=p->vet[p->n-1];
		printf("%i foi retirado da pilha\n",pilha_pop(p));
	}
	return soma;
}

int main(){
	Pilha *p = pilha_cria();
	pilha_push(p,1);
	pilha_push(p,2);
	pilha_push(p,-1);
	pilha_push(p,1);
	printf("%i\n",TTT(p));
}
