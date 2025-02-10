#include <stdio.h>
#include <stdlib.h>
#include "listas.h"

/*Funcoes de Listaeee encadeada*/

Listae* lst_cria(){
	return NULL;
}

Listae* lst_insere(Listae *l, int i){
	Listae *novo = (Listae*)malloc(sizeof(Listae));
	novo->prox = l;
	novo->info = i;
	return novo;
}

void lst_imprime(Listae *l){
	Listae *a;
	for(a=l;a!=NULL;a = a->prox)
		printf("Conteudo da Listaee:\n%i\n",a->info);
}

int lst_vazia(Listae *l){
	if (l == NULL)
		return 1;
	else
		return 0;
}

Listae* lst_busca(Listae *l, int v){
	Listae *a;
	for(a=l;a!=NULL;a=a->prox){
		if(a->info==v)
			return a;
	}
	return NULL;
}

Listae *lst_retira(Listae *l, int v){
	Listae *ant = NULL;
	Listae *p = l;
	
	while(p!=NULL && p->info!=v){
		ant=p;
		p=p->prox;
	}

	if(p == NULL)
		return l;

	if(ant == NULL)
		l=p->prox;
	else
		ant->prox=p->prox;	

	free(p);
	return l;
}

void lst_libera(Listae *l){
	Listae *a =l;
	while(a!=NULL){
		Listae *b = a->prox;
		free(a);
		a=b;
	}
}

Listae *lst_insere_ordenado(Listae *l, int v){
	Listae *novo;
	Listae *p = l;	
	Listae *ant = NULL;
	while(p!=NULL && (p->info < v) ){
		ant=p;
		p=p->prox;
	}

	novo = (Listae*) malloc(sizeof(Listae));
	novo->info = v;

	if(ant==NULL){
		novo->prox=l;
		l=novo;
	}
	else{
		novo->prox=ant->prox;
		ant->prox=novo;
	}
	return l;
}

int lst_igual(Listae *l1, Listae *l2){
	Listae *a1=l1;
	Listae *a2=l2;
	
	do{
		if(a1->info != a2->info)
			return 0;
	a1=a1->prox;
	a2=a2->prox;
	}while(a1!=NULL || a2!=NULL);
	return 1;
}
