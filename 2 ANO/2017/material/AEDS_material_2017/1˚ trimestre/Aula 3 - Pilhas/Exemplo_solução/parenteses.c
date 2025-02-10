#include <stdio.h>
#include <stdlib.h>
#include "pilhas.h"

int main(){
	Pilha *pilha=pilha_cria();
	char caracter;

	do{
		scanf("%c", &caracter);
		if(caracter == ')'){
			if(pilha_vazia(pilha)){
				printf("Errado\n");
				exit(1);
			}
			else{
				pilha_pop(pilha);
			}
		}
		else if (caracter == '('){
			pilha_push(pilha, caracter);
		}

	} while(caracter != 'q' && caracter != 'Q');

	if(pilha_vazia(pilha)){
		printf("Correto\n");
	}
	else{
		printf("Errado\n");
	}

	pilha_libera(pilha);

	return 0;
}