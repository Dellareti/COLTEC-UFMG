#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

void listarTodos(FilaL *fila){
	printf("Inicio:\n");
	fila_imprime_l(fila);
	printf("Fim\n");
}

int listarNumero(FilaL *fila){
	int i, num=0;
	Lista *p;
	for(p=fila->ini;p!=NULL;p=p->prox) num++;
	printf("Numero de avioes na fila de decolagem: %d\n", num);
	return num;
}

void autorizarDecolagem(FilaL *fila){
	int num=listarNumero(fila);
	if(num!=0){
		fila_retira_l(fila);
		listarTodos(fila);
	}
	else{
		printf("Nao ha aviao na fila!\n");
	}
}

void adicionarAviao(FilaL *fila, int num){
	char nome[20];
	int identificador;
	do{
		printf("Insira o nome do avião: ");
		scanf(" %[^\n]s", nome);
		if(fila_busca_l(fila, nome)!=NULL){
			printf("Nome ja utilizado!\n");
		}
	} while(fila_busca_l(fila, nome)!=NULL);
	identificador=num;
	fila_insere_l(fila, nome, num);
	listarTodos(fila);
}

void listarPrimeiro(FilaL *fila){
	Lista *p=fila->ini;
	int num;
	num=listarNumero(fila);
	if(num!=0){
		printf("Nome: %s\n", p->info);
		printf("Id: %d\n", p->id);
	}
	else printf("Fila vazia!\n");
}


int main(){

	FilaL *fila=fila_cria_l();
	int comando, num=1;

	do{
		printf("O que voce quer fazer agora?\n\t0) Sair\n\t1) Listar o numero de avioes\n\t2) Autorizar a decolagem do primeiro aviao\n\t3) Adicionar um aviao a fila de espera\n\t4) Listar os avioes na fila de espera\n\t5) Listar caracteristicas do primeiro aviao\n");
		scanf("%d", &comando);
		switch(comando){
			case 0: printf("Ate mais!\n");
					break;
			case 1: listarNumero(fila);
					break;
			case 2: autorizarDecolagem(fila);
					break;
			case 3: adicionarAviao(fila, num);
					num++;
					break;
			case 4: listarTodos(fila);
					break;
			case 5: listarPrimeiro(fila);
					break;
			default: printf("Comando invalido\n");
					 break;
		}
	} while(comando!=0);

	fila_libera_l(fila);

	return 0;
}