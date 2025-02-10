#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

//PILHA FEITA COM LISTA
Pilha_l *pilha_l_cria(){
	Pilha_l *p = (Pilha_l*) malloc(sizeof(Pilha_l));
	return p;
}

void pilha_l_push(Pilha_l *p, char v){
	Lista *novo = (Lista*) malloc(sizeof(Lista));
	novo->info = v;
	novo->prox = p->prim;
	p->prim = novo;
}

char pilha_l_pop(Pilha_l *p){
	Lista *a;
	char v;
	if(pilha_l_vazia(p)){
		printf("Pilha vazia");
		exit(1);
	}
	a = p->prim;
	v = a ->info;
	p->prim = a->prox;
	free(a);
	return v;
}

int pilha_l_vazia(Pilha_l *p){
	if(p->prim == NULL)
		return 1;
	else
		return 0;
}
void pilha_l_libera(Pilha_l *p){
	Lista *u = p->prim;
	while(u != NULL){
		Lista *a = u->prox;
		free(u);
		u=a;
	}
	free(p);
}

void pilha_l_imprime(Pilha_l *p){
	Lista *a;
	for(a = p->prim;a!=NULL;a=a->prox)
		printf("%f ",a->info); 

}
//PILHA FEITA COM VETOR

Pilha *pilha_cria() {
	Pilha *p = (Pilha *) malloc(sizeof(Pilha));
	p->n = 0;

	return p;
}

void pilha_push(Pilha *p, char v) {
	if (p->n == N) {
		printf("A capacidade da pilha estorou.");
		exit(1);
	}

	p->vet[p->n] = v;
	p->n++;
}

char pilha_pop(Pilha *p) {
	if (pilha_vazia(p)==-1) {
		printf("Pilha vazia.");
		exit(1);
	}
	char a = p->vet[p->n-1];
	p->n--;
	return a;
}

int pilha_vazia(Pilha *p) {
	if(p->n==0)
		return 1;
	else
		return 0;
}

void pilha_libera(Pilha *p) {
	free(p);	
}

void pilha_imprime(Pilha *p){
	int i;
	for(i=p->n-1;i>=0;i--)
		printf("%c ",p->vet[i]);
}