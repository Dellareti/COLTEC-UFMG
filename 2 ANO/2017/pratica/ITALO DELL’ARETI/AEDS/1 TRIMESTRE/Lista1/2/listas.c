#include <stdio.h>
#include <stdlib.h>
#include "listas.h"

/*Funcoes de lista encadeada*/

Lista* lst_cria(){
	return NULL;
}

Lista* lst_insere(Lista *l, int i){
	Lista *novo = (Lista*)malloc(sizeof(Lista));
	novo->prox = l;
	novo->info = i;
	return novo;
}

void lst_imprime(Lista *l){
	Lista *a;
	for(a=l;a!=NULL;a = a->prox)
		printf("Conteudo da lista:\n%i\n",a->info);
}

int lst_vazia(Lista *l){
	if (l == NULL)
		return 1;
	else
		return 0;
}

Lista* lst_busca(Lista *l, int v){
	Lista *a;
	for(a=l;a!=NULL;a=a->prox){
		if(a->info==v)
			return a;
	}
	return NULL;
}

Lista *lst_retira(Lista *l, int v){
	Lista *ant = NULL;
	Lista *p = l;
	
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

void lst_libera(Lista *l){
	Lista *a =l;
	while(a!=NULL){
		Lista *b = a->prox;
		free(a);
		a=b;
	}
}

Lista *lst_insere_ordenado(Lista *l, int v){
	Lista *novo;
	Lista *p = l;	
	Lista *ant = NULL;
	while(p!=NULL && (p->info < v) ){
		ant=p;
		p=p->prox;
	}

	novo = (Lista*) malloc(sizeof(Lista));
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

int lst_igual(Lista *l1, Lista *l2){
	Lista *a1=l1;
	Lista *a2=l2;
	
	do{
		if(a1->info != a2->info)
			return 0;
	a1=a1->prox;
	a2=a2->prox;
	}while(a1!=NULL || a2!=NULL);
	return 1;
}

/*listas circulares*/
void lcirc_imprime(Lista *l){
	Lista *a=l;
	if(a!=NULL){
		putchar('\n');
		do{
			printf("%i\t",a->info);
			a=a->prox;
		}while(a!=l);
		putchar('\n');
	}
}
/*listas duplamente encadeadas*/
Lista2 *lst2_insere(Lista2 *l, int v){
	Lista2 *novo = 	(Lista2*) malloc(sizeof(Lista2));
	novo->info=v;
	novo->prox=l;
	novo->ant=NULL;
	if(l!=NULL)
		l->ant=novo;
	return novo;
}

Lista2* lst2_busca(Lista2 *l, int v){
	Lista2 *a;
	for(a=l;a!=NULL;a=a->prox){
		if(a->info==v)
			return a;
	}
	return NULL;
}

Lista2* lst2_retira(Lista2 *l, int v){
	Lista2 *p = lst2_busca(l,v);
	if (p=NULL)
		return l;
	
	if(l == p)
		l = p->prox;
	else
		p->ant->prox = p->prox;
	
	if (p->prox!=NULL)
		p->prox->ant = p->ant;

	free(p);
	return l;
}