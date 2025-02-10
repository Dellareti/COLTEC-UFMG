#include "fila.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define get_print (void)printf("Aperte <enter>\n"); getchar();
void mostrar_carros(FilaL *fila);

void entrar_com_carro(FilaL *f){
	(void)printf("Qual a placa do carro:\t");
	char placa[20];
	int idade;
	fgets(placa,20,stdin);
	placa[strlen(placa)-1]='\0';
	(void)printf("Qual a idade do motorista?:\t");
	scanf("%i",&idade);
	__fpurge(stdin);
	Lista *q = (Lista*)malloc(sizeof(Lista));
	q = f->ini;

	if(fila_vazia_l(f)){
		fila_insere_l(f,placa,idade);
		(void)printf("Carro inserido!\n");
		get_print
		return;
	}

	for(;q!= NULL; q=q->prox){
		(void)printf("--%s--%s--\n",q->info,placa);
		if(strcmp(q->info,placa)==0){
			(void)printf("Carro ja existe!\n");
			get_print
			return;
		}
	}
	
	//SE FOR MENOR QUE 60 ANOS,INSERE
	if(idade<60){
		fila_insere_l(f,placa,idade);
		(void)printf("Carro inserido!\n");
		get_print
		return;
	}
	char *a;
	//ELSE
	if(f->ini->prioridade > idade){
		//FAZER PROCEDIMENTO DE INSERIR E DEPOIS RODAR ATE O PRIMEIRO VOLTAR A SEU LUGAR
		char cp[20];
		strcpy(cp,f->ini->info);
		do{
			fila_insere_l(f,f->ini->info,f->ini->prioridade);
			a=fila_retira_l(f);
		}while(f->ini->prioridade > idade);
		fila_insere_l(f,placa,idade);

		while(strcmp(cp,f->ini->info)!=0){
			fila_insere_l(f,f->ini->info,f->ini->prioridade);
			a=fila_retira_l(f);
		}

		mostrar_carros(f);
		get_print
		return;

	}
	else{
		//INSERE E DEPOIS RODA ATE O INSERIDO SER O PRIMEIRO
		fila_insere_l(f,placa,idade);
		do{
			char *a;
			fila_insere_l(f,f->ini->info,f->ini->prioridade);
			a=fila_retira_l(f);
		}while(strcmp(placa,f->ini->info)!=0);
		get_print
		return;

	}


	//dps que for inserido, salva o ultimo e loop dnv ate o ultimo ser o primeiro

	
}

void retira(FilaL *fila,char valor[]){
	char *a;
	for(;;){
		fila_insere_l(fila,fila->ini->info,fila->ini->prioridade);
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
	FILE *arquivozin;

	arquivozin = fopen("arquivo.txt","a");
	
	if(fila_vazia_l(fila)){
		(void)printf("ESTACIONAMENTO VAZIO!\n");
		fprintf(arquivozin,"ESTACIONAMENTO VAZIO!\n");
	}

	for(a=fila->ini;a!=NULL;a=a->prox,i++){
		(void)printf("-----\nCarro:\t %i\nPlaca:\t %s\nPrioridade:\t%i\n-----\n",i,a->info,a->prioridade);
		fprintf(arquivozin,"-----\nCarro:\t %i\nPlaca:\t %s\nPrioridade:\t%i\n-----\n",i,a->info,a->prioridade);
	}
	get_print
	fclose(arquivozin);
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
			case 0: return;
			default:{
				(void)printf("Nao existe tal opcao\n");
				break;
			}
		get_print
		}
	}while(c!='0');
}
