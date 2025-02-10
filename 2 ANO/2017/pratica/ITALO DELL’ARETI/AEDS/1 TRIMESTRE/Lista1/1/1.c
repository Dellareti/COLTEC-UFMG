#include "1.h"
#include <stdio.h>
#include <stdlib.h>


void lst_imprime_rec(Lista *l){
	if(l==NULL)
		return;
	else{
		printf("Conteudo da lista:\n%i\n",l->info);
		return lst_imprime_rec(l->prox);
	}
}

Lista* lst_insere(Lista *l, int i){
	Lista *novo = (Lista*)malloc(sizeof(Lista));
	novo->prox = l;
	novo->info = i;
	return novo;
}



Lista *lst_retira_rec(Lista *l,int v){
	Lista *p = l;

	if(p == NULL)
		return l;

	if(p->prox->info!=v)
		p->prox = lst_retira_rec(p->prox,v);
	else{
		Lista *a=p->prox;
		p->prox=p->prox->prox;
		free(a);
	}
	return l;
}

void lst_libera_rec(Lista *l){
	Lista *a =l;
	if(a!=NULL){
		Lista *b = a->prox;
		free(a);
		a=b;
		return lst_libera_rec(a);
	}
}