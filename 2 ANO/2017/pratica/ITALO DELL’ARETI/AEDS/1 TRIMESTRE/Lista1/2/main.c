#include "listas.h"
#include <stdio.h>


Lista *lst_intercala(Lista *l1,Lista *l2){
	Lista *a=l1->prox;
	Lista *b=l2;
	Lista *l3=NULL;

			l3=lst_insere(l3,l1->info);

	while(a!=NULL || b!=NULL){
		if(a!=NULL && b==NULL){
			l3=lst_insere(l3,a->info);
			a=a->prox;
		}
		else if(a==NULL && b!=NULL){
			l3=lst_insere(l3,b->info);
			b=b->prox;
		}
		else{
			l3=lst_insere(l3,b->info);
			l3=lst_insere(l3,a->info);
			a=a->prox;
			b=b->prox;
		}
	}
	return l3;
}


int main(){
	Lista *a=lst_cria();
	Lista *b=lst_cria();
	Lista *c=lst_cria();


	a = lst_insere(a,1);
	a = lst_insere(a,3);
	a = lst_insere(a,5);
	a = lst_insere(a,7);
	a = lst_insere(a,9);
	a = lst_insere(a,11);
	a = lst_insere(a,13);

	lst_imprime(a);
	printf("----");

	b = lst_insere(b,2);
	b = lst_insere(b,4);
	b = lst_insere(b,6);
	b = lst_insere(b,8);

	lst_imprime(b);
	printf("----");

	c=lst_intercala(a,b);
	lst_imprime(c);


	return 0;
}