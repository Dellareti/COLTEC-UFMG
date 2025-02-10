#include "fila.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define get_print printf("Aperte <enter>\n"); getchar();

void mostrar_carros(FilaL *fila);
void entrar_com_carro(FilaL *f){
	(void)printf("Digite o nome do aviao:\t");
	char placa[20];
	fgets(placa,20,stdin);
	placa[strlen(placa)-1]='\0';
	Lista *q = (Lista*)malloc(sizeof(Lista));
	q = f->ini;

	if(fila_vazia_l(f)){
		fila_insere_l(f,placa);
		(void)printf("aviao inserido!\n");
		get_print
		return;
	}

	for(;q!= NULL; q=q->prox){
		printf("--%s--%s--\n",q->info,placa);
		if(strcmp(q->info,placa)==0){
			(void)printf("aviao ja existe!\n");
			get_print
			return;
		}
	}
	fila_insere_l(f,placa);
	(void)printf("aviao inserido!\n");
	get_print
}

void retira(FilaL *fila,char valor[]){
	char *a;
	for(;;){
		fila_insere_l(fila,fila->ini->info);
		a=fila_retira_l(fila);
		if(strcmp(fila->ini->info,valor)==0){
			fila->ini=fila->ini->prox;
			printf("aviao retirado!\n");
			get_print
			return;
		}
	}
}

void sair_com_carro(FilaL *fila){
	//VERIFICA SE O CARRO EXISTE
	char placa[20];
	(void)printf("Digite o nome do aviao a ser retirado:\n");
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
	(void)printf("aviao nao encontrado!\n");
	get_print
}

void mostrar_carros(FilaL *fila){
	Lista *a;
	int i=1;

	if(fila_vazia_l(fila))
		printf("pista vazia!\n");

	for(a=fila->ini;a!=NULL;a=a->prox,i++)
		(void)printf("Aviao %i\tNome %s\n",i,a->info);
	get_print
}

int main(){
	FilaL *fila = fila_cria_l();
	int c;
	char a[20];
	do{
		system("clear");
		(void)printf("Bem vindo!\nDigite:\n1-Para entrar com um aviao\n2-Para retirar um aviao\n3-Para ver a fila de avioes\n4-Para autorizar aviao\n0-Para sair\n\n");
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
			case 4:{
                printf("\n\n Digite o nome do avião a ser autorizado :\n");
                fgets(a,20,stdin);
                sair_com_carro(fila);
                printf("\n\n Aviao retirado :\n\n");

                break;
			}

			case 0: return;
			default:{
				(void)printf("Nao existe tal opcao\n");
				break;
			}
		get_print
		}
	}while(c!='0');
}
