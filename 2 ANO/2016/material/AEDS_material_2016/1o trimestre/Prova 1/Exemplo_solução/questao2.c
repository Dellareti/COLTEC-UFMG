#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "listas.h"

Lista *cria_L3(Lista *L1, Lista *L2, Lista *L3){
	Lista *p;
	for(p=L1;p!=NULL;p=p->prox){
		if(lst_busca(L3, p->info)==NULL){
			L3=lst_insere(L3, p->info);
		}
	}
	for(p=L2;p!=NULL;p=p->prox){
		if(lst_busca(L3, p->info)==NULL){
			L3=lst_insere(L3, p->info);
		}
	}
	return L3;
}

Lista *cria_L4(Lista *L1, Lista *L2, Lista *L4){
	Lista *p;
	for(p=L1;p!=NULL;p=p->prox){
		if((lst_busca(L2, p->info)!=NULL) && (lst_busca(L4, p->info)==NULL)){
			L4=lst_insere(L4, p->info);
		}
	}
	return L4;
}

int main(){
	srand(time(NULL));
	Lista *L1=lst_cria();
	Lista *L2=lst_cria();
	Lista *L3=lst_cria();
	Lista *L4=lst_cria();
	int i;

	for(i=0;i<5;i++){
		L1=lst_insere(L1, (rand()%10));
		L2=lst_insere(L2, (rand()%10));
	}

	L3=cria_L3(L1, L2, L3);
	L4=cria_L4(L1, L2, L4);

	printf("Lista 1:\n");
	lst_imprime(L1);
	printf("\nLista 2:\n");
	lst_imprime(L2);
	printf("\nLista 3 - União:\n");
	lst_imprime(L3);
	printf("\nLista 4 - Interseção:\n");
	lst_imprime(L4);

	lst_libera(L1);
	lst_libera(L2);
	lst_libera(L3);
	lst_libera(L4);

	return 0;
}