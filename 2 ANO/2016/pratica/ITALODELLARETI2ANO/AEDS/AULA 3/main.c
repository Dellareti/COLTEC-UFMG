#include<stdio.h>
#include<stdlib.h>
#include<strings.h>
#include"pilhas.h"

int main(){
	Pilha *P = pilha_cria();
	char quant;

do{
	printf("\n\n Por favor digite os parenteses : \n\n");
	scanf("%c", &quant);
	if(quant == ')'){
		if(pilha_vazia(P)){
		printf("\n\n Seus parenteses estao incompletos\n\n");
	}
		else{
		pilha_pop(P);
	}
  }
		else if (quant == '('){
			pilha_push(P, quant);
	}
  } 
		while(quant!='q' && quant!='Q');

			if(pilha_vazia(P)){
			printf("\n\n Voce possui par de parenteses \n\n");
	}
	
		else{
		printf("\n\n Seus parenteses estao incompletos \n\n");
	}

	return 0;
}
