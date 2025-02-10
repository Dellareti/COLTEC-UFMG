#include "lista.h"
#include <stdio.h>
#include <stdlib.h>


Lista2 *lst2_insere_ordenado(Lista2 *l, int v){
	Lista2 *novo = 	(Lista2*) malloc(sizeof(Lista2));
	Lista2 *p = l;	

	novo->info=v;

	if(l==NULL){
		l=novo;
		l->prox=l;
		l->ant=l;
		return l;
	}
	else{
		if(v <= p->info){
			Lista2 *fim=l;
			do{fim=fim->prox;}while(fim->prox!=l);
			fim->prox=novo;
			novo->ant=fim;
			novo->prox=l;
			l->ant=novo;
			return novo;
		}
		Lista2 *a = p;
		do{
			a=p;
			p=p->prox;

			//se for inserido por ultimo
			if(p->prox->info == l->info){
				p->prox=novo;
				novo->ant=p;
				novo->prox=l;
				l->ant=novo;
				return l;
			}
		}while(v > p->info);
			
		a->prox=novo;
		novo->ant=a;
		novo->prox=p;
		p->ant=novo;

		return l;
	}
}

void *lst2_imprime(Lista2 *l){
	Lista2 *a = l;
	if(a!=NULL){
		printf("----------\n");
		do{
			printf("%i\n",a->info);
			a=a->prox;
		}while(a!=l);
		printf("----------\n");
	}
}


Lista2* lst2_busca(Lista2 *l, int v){
	Lista2 *a = l;
	do{
		if(a->info==v)
			return a;
		a=a->prox;
	}while(a!=l);

	return NULL;
}

Lista2* lst2_retira(Lista2 *l, int v){
	Lista2 *p = lst2_busca(l,v);
	if(p==NULL)
		return l;

	Lista2 *fim=l;
	do{fim=fim->prox;}while(fim->prox!=l);

	Lista2 *ant=p->ant;
	Lista2 *prox=p->prox;

	if(p==l){
		fim->prox=prox;
		prox->ant=fim;
		free(p);
		return prox;
	}
	else if(p==fim){
		ant->prox=l;
		l->ant=ant;
		free(p);
		return l;
	}
	else{
		ant->prox=prox;
		prox->ant=ant;
		free(p);
		return l;	
	}


//		1	-	2	-	3	-	5



/*	Lista2 *p = lst2_busca(l,v);
	printf("achei esse %i\n",p->info);
	printf("o l é %i\n",l->info);
	Lista2 *aux=p->ant;
	Lista2 *aux2=p->prox;
	
	if (p==NULL)
		return l;


	if(l == p){
		p->prox->ant=aux;
		aux->prox=p->prox;
		free(p);
		return aux2;	
	}
	else{
		printf("sou o anterior do p: %i\n",aux->ant->info);
		printf("sou o proximo  do p: %i\n",aux2->info);

		aux->prox = aux2;
		aux2->ant=aux;
		free(p);
		return l;
	}
*/
}

void *lst2_libera(Lista2 *l){
	Lista2 *a =l;
	do{
		Lista2 *b = a->prox;
		free(a);
		a=b;
	}while(a!=l);
}