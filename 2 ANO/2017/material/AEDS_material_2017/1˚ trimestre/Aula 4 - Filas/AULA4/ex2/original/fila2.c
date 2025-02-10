#include <stdio.h>
#include <stdlib.h>
#include "fila2.h"

Fila2 *fila2_cria(){
	Fila2 *f = (Fila2 *) malloc(sizeof(Fila2));
	f->n = 0;
	f->ini = 0;
	return f;
}

void fila2_insere_ini(Fila2 *f, float v){
	int fim;
	if(f->n == N){
		printf("Capacidade da fila estourou\n");
		exit(1);
	}
	fim = (f->ini + f->n)%N;
	f->vet[fim] = v;
	f->n++;
}

void fila2_insere_fim(Fila2 *f, float v){
	if(f->n == N){
		printf("Capacidade da fila estourou\n");
		exit(1);
	}
	int i;
	for(i=f->n-1;i>=0;i--)
			f->vet[i+1]=f->vet[i];

	f->vet[0]=v;
	f->n++;
}

float fila2_retira_ini(Fila2 *f){
	float v;
 	if(fila2_vazia(f)){
 		printf("Fila vazia!\n");
 		exit(1);
 	}
 	v=f->vet[f->ini];
	int i;
	for(i=0;i<f->n-1;i++)
			f->vet[i]=f->vet[i+1];

	f->n--;
 	return v;
}

float fila2_retira_fim(Fila2 *f){
	float v;
 	if(fila2_vazia(f)){
 		printf("Fila vazia!\n");
 		exit(1);
 	}
 	v=f->vet[f->n-1];
	f->n--;
 	return v;
}

int fila2_vazia(Fila2 *f){
	return (f->n == 0);
}

void fila2_libera(Fila2 *f){
	free(f);
}


void fila2_imprime_vet(Fila2 *f){
	int i;
	for (i=0;i<f->n;i++)
		printf("%f\n",f->vet[(f->ini+i)%N]);
}

//------------------------------------------------------------------

	
Fila2L *fila2_cria_L(){
 	Fila2L *f = (Fila2L *) malloc(sizeof(Fila2L));
 	f->ini = NULL;
    f->fim = NULL;
 	return f;
}

void fila2_insere_ini_L(Fila2L *f,float v){
	Lista *n = (Lista *) malloc(sizeof(Lista));
	n->info=v;
	n->prox = NULL;
 	if(f->fim != NULL) 
 		f->fim->prox = n;
 	else
 		f->ini = n;

 	f->fim = n;
}

void fila2_insere_fim_L(Fila2L *f,float v){
	Lista *n = (Lista *) malloc(sizeof(Lista));
	n->info=v;
	n->prox = f->ini;
 	f->ini = n;
}

float fila2_retira_ini_L(Fila2L *f){
 	Lista *t;
 	float v;
 	if(fila2_vazia_L(f)){
 		printf("Fila vazia!");
 		exit(1);
	}
 	t = f->ini;
 	v = t->info;
 	f->ini = t->prox;
 	if(f->ini==NULL)
 		f->fim = NULL;
 	free(t);
 	return v;
}

float fila2_retira_fim_L(Fila2L *f){
 	Lista *t,*q;
 	float v;
 	if(fila2_vazia_L(f)){
 		printf("Fila vazia!");
 		exit(1);
	}
 	t = f->fim;
 	v = t->info;

 	for(q=f->	ini;q->prox->prox!=NULL;q=q->prox);
 	f->fim=q;
 	f->fim->prox=NULL;
 	free(t);
 	return v;
}


int fila2_vazia_L(Fila2L *f){
	return (f->ini == NULL);
}

void fila2_libera_L(Fila2L *f){
	Lista *q = f->ini;
	while(q!=NULL){
		Lista *t = q->prox;
		free(q);
		q = t;
	}
	free(f);
}

void fila2_imprime_L(Fila2L *f){
	Lista *q;
	for(q=f->ini; q!= NULL; q=q->prox) printf("%f\n",q->info);
}