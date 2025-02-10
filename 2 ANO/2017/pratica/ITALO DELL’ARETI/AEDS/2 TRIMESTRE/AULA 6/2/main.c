#include <stdio.h>
#include <stdlib.h>
#include "listas.h"

int main(){
	int v,i,j,soma=0;
	char op;
	Lista **grafo;
	Lista *aux;

	printf("Qual o numero de vertices do grafo?\n");
	scanf("%i",&v);
	__fpurge(stdin);

	grafo = (Lista**) malloc(v*sizeof(Lista));

	for(i=0;i<v;i++){
		for(j=0;j<v;j++){
			printf("O vertice %i eh adjacente ao vertice %i ?\n(s/n)",i+1,j+1);
			op = getchar();
			__fpurge(stdin);
			if(op=='s')grafo[i] = lst_insere(grafo[i],j+1); 
			printf("-----------\n");
		}
	}

	system("clear");
	printf("Este e seu grafo no formato de listas adjacentes\n");
	for(i=0;i<v;i++){
		printf("%i: ",i+1);
		lst_imprime(grafo[i]);
		printf("\n--------------\n");
	}
	for(i=0;i<v;i++){
		for(aux=grafo[i];aux!=NULL;aux=aux->prox)
			soma++;
		printf("Vertice %i: grau %i\n",i+1,soma);
		soma=0;
	}
}