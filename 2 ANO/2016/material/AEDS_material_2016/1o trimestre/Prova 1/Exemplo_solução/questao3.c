#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "pilhas.h"

int main(){
	srand(time(NULL));
	Pilha_vet *pilha1=pilha_vet_cria();
	Pilha_vet *pilha2=pilha_vet_cria();
	int num, val;

	while((pilha1->n)+(pilha2->n)<80){
		val=rand()%100; //valor minimo de 0 e maximo de 99
		num=rand()%2; //escolha da pilha a receber val
		if(num==0){
			if(pilha1->n<50){
				pilha_vet_push(pilha1, val);
			}
		}
		else if(num==1){
			if(pilha2->n<50){
				pilha_vet_push(pilha2, val);
			}
		}
	}

	printf("\nPilha 1:\n");
	pilha_vet_imprime(pilha1);
	printf("\nPilha 2:\n");
	pilha_vet_imprime(pilha2);

	pilha_vet_libera(pilha1);
	pilha_vet_libera(pilha2);

	return 0;
}