#include <stdio.h>
#include <stdlib.h>
#include "listas.h"

                                /*lista encadeada*/

Lista* lst_cria(){
	return NULL;
}

Lista* lst_insere(Lista *l, int i){
	Lista *novo = (Lista *) malloc (sizeof(Lista));
	novo->info = i;
	novo->prox = l;
	return novo;
}

Lista* lst_enche(Lista *l, int i){
	int j;
	for(j=0;j<i;j++){
		Lista *novo = (Lista *) malloc (sizeof(Lista));
		novo->info = j+1;
		novo->prox = l;
		return novo;
	}
}

void lst_imprime(Lista *l){
	Lista *p;
	for(p=l; p!= NULL; p=p->prox){
		printf("info %d ", p->info);
	}
}

int lst_vazia(Lista *l){
	if (l=NULL)
		return 1;
	else
		return 0;
}

Lista* lst_busca(Lista *l, int v){
	Lista *p;
	for(p=l; p!=NULL; p=p->prox){
		if(p->info == v){
			return p;
		}
	}
	return NULL;
}

Lista *lst_retira(Lista *l, int v){
	Lista *ant = NULL;
	Lista *p = l;

	while(p!=NULL && p->info != v){
		ant=p;
		p = p->prox;
	}
	if (p == NULL){
		return l;
	}
	if (ant == NULL){
		l = p->prox;
	}
	else{
		ant->prox = p->prox;
	}
	free(p);

	return l;
}

void lst_libera(Lista *l){
	Lista *p = l;
	while(p!=NULL){
		Lista *t = p->prox;
		free(p);
		p = t;
	}
}

Lista *lst_insere_ordenado(Lista *l, int v){
	Lista *novo;
	Lista *ant = NULL;
	Lista *p = l;
	while(p!=NULL && p->info < v){
		ant = p;
		p = p->prox;
	}

	novo=(Lista*)malloc(sizeof(Lista));
	novo->info = v;

	if(ant == NULL){
		novo->prox = l;
		l = novo;
	}
	else{
		novo->prox = ant->prox;
		ant->prox = novo;
	}

	return l;
}

int lst_igual(Lista *l1, Lista *l2){
	Lista *p1, *p2;
	int view,i,qt1=0,qt2=0;

	for(p1=l1; p1!=NULL; p1 = p1->prox){
		qt1++;
	}
	for(p2=l2; p2!=NULL; p2 = p2->prox){
		qt2++;
	}
	if (qt1!=qt2){
		return 0;
	}
	else{
		for(p1=l1,p2=l2; p1!=NULL; p1=p1->prox, p2=p2->prox){
			if(p1->info==p2->info){
				continue;
			}
			return 0;
		}
		return 1;
	}
}

/*listas circulares*/

void lcirc_imprime(Lista *l){
	Lista *p = l;
	if (p){
		do{
			printf("%d ", p->info);
			p = p->prox;
		} while(p!=l);
	}
}

Lista* lst_circular(Lista *l){
	Lista *p=l,*a;
	do{
		a=p;
		p=p->prox;
		if(p == NULL)
			a->prox = l;
}
	while(p!=NULL);

	return l;
}

Lista *lst_comeca(Lista *l, int in){
	int i;
	Lista *p;
	for(i=1;i<=in;i++){
		p = p->prox;
	}
	return p;
}

                                /*duplamente encadeadas*/


Lista2 *lst2_insere(Lista2 *l, int v){
	Lista2 *novo = (Lista2 *) malloc (sizeof(Lista2));
	novo->info = v;
	novo->prox = l;
	novo->ant = NULL;
	if(l!=NULL){
		l->ant = novo;
	}

	return novo;
}

Lista2 *lst2_busca(Lista2 *l, int v){
	Lista2 *p;
	for(p=l; p!=NULL; p=p->prox){
		if(p->info == v){
			return p;
		}
	}

	return NULL;
}

Lista2 *lst2_retira(Lista2 *l, int v){
	Lista2 *p = lst2_busca(l, v);

	if(p == NULL){
		return l;
	}

	if(l == p){
		l = p->prox;
	}

	else{

		p->ant->prox = p->prox;
	}

	if(p->prox != NULL){

		p->prox->ant = p->ant;
	}

	free(p);

	return l;
}
