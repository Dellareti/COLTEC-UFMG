#include "fila.h"
#include <stdio.h>
#include <stdlib.h>

int main(){
	int identificador = 0;
	FilaL *processos = fila_cria_l();
	char c;
	int tempo=0,*v,maior=-1,r,y;
	Lista *a,*q,*e;

	do{
		system("clear");
		printf("1-Incluir novo processo a fila.\n2-Retirar da fila o processo com maior tempo de espera.\n3-Imprimir conteudo da fila.\nQualquer outra opção para sair.\n");
		c=getchar();
		__fpurge(stdin);
		switch(c){
			case '1':{
				printf("What's the current time of the process?\n");
				scanf("%i",&tempo);
				fila_insere_l(processos,identificador,tempo);
				printf("The process with identifier %i has been included.\n",identificador);
				identificador++;
				__fpurge(stdin);
				break;
			}
			case '2':{
				if(!fila_vazia_l(processos)){
					e=processos->ini;
					while(e!=NULL){
						if(e->tempo>maior)
							maior=e->tempo;
						e=e->prox;
					}
					for(;;){
						r =fila_retira_l(processos,&y);
						if(maior == r)
							break;
						else
							fila_insere_l(processos,y,r);
					}
				}
				else
					printf("The queue is currently empty.\n");
				break;
			}
			case '3':{
				printf("Current queue:\t");
				fila_imprime_l(processos);
				printf("------------------\n");
				break;
			}
			case'\n':{
				break;
			}
			default:{
				fila_libera_l(processos);
				exit (-1);
			}
		}	
		printf("Press <enter> to proceed");
		getchar();
	}while(1);
}
