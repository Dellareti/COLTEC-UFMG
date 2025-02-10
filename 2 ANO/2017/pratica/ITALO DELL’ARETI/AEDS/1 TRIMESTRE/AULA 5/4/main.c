#include "arvore.h"
#include "listas.h"
#include <stdio.h>
#include <stdlib.h>



Listae *histograma(Arv *r,Listae *lista){
	if(!arv_vazia(r)){
		Listae *a = lst_busca(lista,r->info);
		if(a==NULL){
			lista = lst_insere(lista,r->info);
			lista->qtd=1;
		}
		else
			a->qtd= a->qtd + 1;
		lista = histograma(r->esq,lista);
		lista = histograma(r->dir,lista);
	}
	return lista;
}

void imprime(Listae *lista){
	Listae *e;
	int i;
	for(e=lista;e!=NULL;e = e->prox){
		if(e->qtd!=0){
			printf("%i\t",e->info);
			for(i=0;i<e->qtd;i++) putchar('*');
				putchar('\n');
		}
	}
}

int main(){
	Arv *n3 = arv_cria(1,NULL,NULL);
	Arv *n4 = arv_cria(1,NULL,NULL);
	Arv *n6 = arv_cria(1,NULL,NULL);
	Arv *n7 = arv_cria(3,NULL,NULL);
	Arv *n2 = arv_cria(2,n3,n4);
	Arv *n5 = arv_cria(1,NULL,n6);

	Arv *r = arv_cria(1,n2,n5);

	arv_imprime_preordem(r);
	putchar('\n');
	arv_imprime_simetrica(r);
	putchar('\n');
	arv_imprime_posordem(r);
	putchar('\n');
	printf("-------------------------------------------------------------------------------------------\n");
	imprime_arvore(r);
	Listae *lista = NULL;
	lista =	histograma(r,lista);
	imprime(lista);
}
