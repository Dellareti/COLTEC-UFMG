#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

int main(){
	int op;
	int p=0; //fila prioritaria
	int n=0; //fila normal

	FilaL *prior=fila_cria_l();
	FilaL *norm=fila_cria_l();
	FilaL *final=fila_cria_l();

	//leitura dos dados
	do{
		system("clear");
		printf("O proximo cliente e prioritario ou nao? \n\n1-prioritario. \n\n2-normal.\n\n Digite algo diferente de 1 e 2 para sair\n");
		scanf("%i",&op);

		if(op==1){
			fila_insere_l(prior,p);
			printf("Cliente com senha prioritaria :P%i%i\n",p/10,p%10);
			p++;
		}
		if(op==2){
			fila_insere_l(norm,n);
			printf("Cliente com senha normal :N%i%i\n",n/10,n%10);
			n++;
		}
		__fpurge(stdin);
		printf("Press enter.\n");
		getchar();
	}while(op==1||op==2);
	//arquivo de texto
	int aux;
	char c;
	while(fila_vazia_l(prior)!=1 || fila_vazia_l(norm)!=1){
		if(!fila_vazia_l(prior)){
			aux = fila_retira_l(prior,&c);
			fila_insere_l(final,aux);
			final->fim->c='P';
		}
		if(!fila_vazia_l(norm)){
			aux = fila_retira_l(norm,&c);
			fila_insere_l(final,aux);
			final->fim->c='N';
		}
	}

	FILE * arq = fopen("saida.txt","w");
	fprintf(arq,"ORDEM:\n");
	fila_imprime_l(final);
	while(!fila_vazia_l(final)){
		aux = fila_retira_l(final,&c);
		fprintf(arq,"SENHA %c%i%i\n",c,aux/10,aux%10);
	}

	fclose(arq);
	fila_libera_l(final);
	printf("O arquivo gerado e o saida.txt\n");
}
