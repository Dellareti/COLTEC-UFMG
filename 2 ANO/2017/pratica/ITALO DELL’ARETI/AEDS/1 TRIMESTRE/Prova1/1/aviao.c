#include "fila.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define get_print printf("Aperte <enter>\n"); getchar();





listar_avioes(FilaL *fila){
	Lista *a;
	int i=1;
	if(fila_vazia_l(fila))
		(void)printf("Pista do aeroporto vazia!\n");
	
	for(a=fila->ini;a!=NULL;a=a->prox,i++)
		(void)printf("Aviao :%i \tNome do piloto: %s\tIdentificador: %i\n",i,a->info,a->identificador);
	get_print
}

void insere_aviao(FilaL *f,int i){
	(void)printf("Qual o nome do piloto:\t");
	char modelo[20];
	fgets(modelo,20,stdin);
	modelo[strlen(modelo)-1]='\0';
	Lista *q = (Lista*)malloc(sizeof(Lista));
	q = f->ini;

	if(fila_vazia_l(f)){
		fila_insere_l(f,modelo,i);
		(void)printf("Aviao entrou na fila!\n");
		get_print
		return;
	}

	for(;q!= NULL; q=q->prox){
		if(strcmp(q->info,modelo)==0){
			(void)printf("Este aviao ja existe !\n");
			get_print
			return;
		}
	}
	fila_insere_l(f,modelo,i);
	(void)printf("Aviao entrou na fila!\n");
	get_print
}
void listar_n_avioes(FilaL *a){
	Lista *q=a->ini;
	int i=0;
	while(q!=NULL){
		q = q->prox;
		i++;
	}
		printf("Existem %i avioes na pista\n",i);
		get_print
}



int main(){
	FilaL *fila = fila_cria_l();
	int c,i=1;
	do{
		system("clear");
		(void)printf("Bem vindo ao aeroporto Tie Fighters !!!\nDigite:\n1-Para listar o numero de avioes a decolar\n2-Autorizar decolagem do primeiro\n3-Adicionar avião à fila\n4-Listar avioes\n5-Ver características do primeiro aviao\n0-Para sair\n\n");
		scanf("%i",&c);
		__fpurge(stdin);
		switch(c){
			case 1:{
				listar_n_avioes(fila);
				break;
			}
			case 2:{
				(void)fila_retira_l(fila);
				get_print			
				break;
			}
			case 3:{
				insere_aviao(fila,i);
				i++;
				break;
			}
			case 4:{
				listar_avioes(fila);
				break;
			}
			case 5:{
				if(fila_vazia_l(fila))
					(void)printf("O aeroporto ta vazio!\n");
				else{
					(void)printf("O primeiro aviao da fila e:\n");
					(void)printf("Nome do Piloto: %s\tIdentificador: %i\n",fila->ini->info,fila->ini->identificador);
				}
				get_print			
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
