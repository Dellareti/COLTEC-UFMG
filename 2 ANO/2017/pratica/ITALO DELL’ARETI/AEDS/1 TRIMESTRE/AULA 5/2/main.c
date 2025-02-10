#include "arvore.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void insere_ordenada_arv(Arv *r,int v){
	if(v<r->info){
		if(r->esq!=NULL)
			insere_ordenada_arv(r->esq,v);
		else{
			Arv *novo = arv_cria(v,NULL,NULL);
			r->esq = novo;
		}
	}
	else if(v>r->info){
		if(r->dir!=NULL)
			insere_ordenada_arv(r->dir,v);
		else{
			Arv *novo = arv_cria(v,NULL,NULL);
			r->dir = novo;
		}
	}
}
	
int main(){

	Arv *r = arv_cria(5,NULL,NULL);

	insere_ordenada_arv(r,1);
	insere_ordenada_arv(r,2);
	insere_ordenada_arv(r,6);
	insere_ordenada_arv(r,7);
	insere_ordenada_arv(r,8);
	insere_ordenada_arv(r,9);
	insere_ordenada_arv(r,3);
	insere_ordenada_arv(r,4);


	arv_imprime_preordem(r);
	printf("\n-------------------------------\n");
	imprime_arvore(r);
}
