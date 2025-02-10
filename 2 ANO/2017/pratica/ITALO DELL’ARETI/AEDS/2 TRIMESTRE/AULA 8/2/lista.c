#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"

/*Funcoes de lista encadeada*/

Lista* lst_cria(){
	return NULL;
}

Lista* lst_insere(Lista *l,char nome[],char tel[],char end[]){
	Lista *novo = (Lista *) malloc (sizeof(Lista));
	strcpy(novo->contato.nome,nome);
	strcpy(novo->contato.telefone,tel);
	strcpy(novo->contato.endereco,end);
	novo->prox = l;
	return novo;
}

void lst_imprime(Lista *l){
/*	Lista *p;
	for(p=l;p!=NULL;p=p->prox){
		printf("%d\n", p->info);
	}
*/}

int lst_vazia(Lista *l){
	if (l == NULL)
		return 1;
	else
		return 0;
}
/*
Lista* lst_busca(Lista *l, int v){
	Lista *p;
	for(p=l;p!=NULL;p=p->prox){
		if(p->info == v)
			return p;
	}
	return NULL;
}
Lista *lst_retira(Lista *l, int v){
/*
	Lista *ant = NULL;
	Lista *p=l;
	while(p!=NULL && p->info!=v){
		ant=p;
		p=p->prox;
	}

	if (p==NULL){
		return l;
	}
	if(ant==NULL)
		l=p->prox;
	else
		ant->prox=p->prox;

	free(p);
	return 1;
}
*/

void lst_libera(Lista *l){
	Lista *p = l;
	while(p!=NULL){
		Lista *t = p->prox;
		free(p);
		p=t;
	}
}