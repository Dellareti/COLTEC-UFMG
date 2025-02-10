#include "fila.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define get_print printf("Aperte <enter>\n"); getchar();
void mostrar_carros(FilaL *fila);
void entrar_com_carro(FilaL *f){
	(void)printf("Qual a placa do carro:\t");
	char placa[20];
	fgets(placa,20,stdin);
	placa[strlen(placa)-1]='\0';
	Lista *q = (Lista*)malloc(sizeof(Lista));
	q = f->ini;

	if(fila_vazia_l(f)){
		fila_insere_l(f,placa);
		(void)printf("Carro inserido!\n");
		get_print
		return;
	}

	for(;q!= NULL; q=q->prox){
		printf("--%s--%s--\n",q->info,placa);
		if(strcmp(q->info,placa)==0){
			(void)printf("Carro ja existe!\n");
			get_print
			return;
		}
	}
	fila_insere_l(f,placa);
	(void)printf("Carro inserido!\n");
	get_print
}

void retira(FilaL *fila,char valor[]){
	char *a;
	for(;;){
		fila_insere_l(fila,fila->ini->info);
		a=fila_retira_l(fila);
		if(strcmp(fila->ini->info,valor)==0){
			fila->ini=fila->ini->prox;
			printf("Carro retirado!\n");
			get_print
			return;
		}
	}
}

void sair_com_carro(FilaL *fila){
	
    //VERIFICA SE O CARRO EXISTE
	char placa[20];
	(void)printf("Digite a placa do carro a ser retirado:\n");
	fgets(placa,20,stdin);
	placa[strlen(placa)-1]='\0';
	
	Lista *q = (Lista*)malloc(sizeof(Lista));
	Lista *aux = (Lista*)malloc(sizeof(Lista));
	q = fila->ini;
	aux=q;
	for(;q!= NULL; q=q->prox){
		if(strcmp(q->info,placa)==0){
			if(aux==q){
				fila->ini=q->prox;
				get_print
				return;
			}
			retira(fila,placa);
			return;
		}
		aux=q;
	}
	(void)printf("Carro nao encontrado!\n");
	get_print
}

void mostrar_carros(FilaL *fila){
	Lista *a;
	int i=1;
	
	if(fila_vazia_l(fila))
		printf("ESTACIONAMENTO VAZIO!\n");
	
	for(a=fila->ini;a!=NULL;a=a->prox,i++)
		(void)printf("CARRO %i\tPlaca %s\n",i,a->info);
	get_print
}

int main(){
	FilaL *fila = fila_cria_l();
	int c;
	do{
		system("clear");
		(void)printf("Bem vindo ao estacionamento!\nDigite:\n1-Para entrar com um carro\n2-Para retirar um carro\n3-Para ver a fila de carros\n0-Para sair\n\n");
		scanf("%i",&c);
		__fpurge(stdin);
		switch(c){
			case 1:{
				entrar_com_carro(fila);
				break;
			}
			case 2:{
				sair_com_carro(fila);
				break;
			}
			case 3:{
				mostrar_carros(fila);
				break;
			}
			//case 0: return;
			default:{
				(void)printf("Nao existe tal opcao\n");
				break;
			}
		get_print
		}
	}while(c!='0');
}
