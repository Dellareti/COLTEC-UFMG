#include "pilha.h"
#include <stdio.h>

int main(){

	Pilha *pilha = pilha_cria(); 
	char c,ultimo,l;
	int i,cont=0;

	printf("Digite apenas os parenteses e os colchetes (um a um),(q para quit)\n");

	
	do{
		ultimo=pilha->vet[pilha->n-1];
		c = getchar();
		__fpurge(stdin);
	
		if(c=='q')
			break;
		pilha_push(pilha,c);	
		if(cont!=0 && ((ultimo=='(' && c==')')||(ultimo=='[' && c==']'))){
				printf("tirei\n");
				l=pilha_pop(pilha);
				l=pilha_pop(pilha);
		}
		if (cont!=0 && ultimo=='(' && (c=='['||c==']')){
			printf("Colchete nao entra depois de parenteses!\n");
			return 0;
		}
	
		if((c==')' && cont==0)||(c==']' && cont==0)){
			printf("A expressao nao existe\n");
			return 0;
		}
		else if(cont==0)
			cont++;
		
	}while(c!='q');
			if(pilha_vazia(pilha)==1)
				printf("expressao existe\n");
			else
				printf("A expressao nao existe\n");
				

}