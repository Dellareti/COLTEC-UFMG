#include "arvore.h"
#include <stdio.h>
#include <stdlib.h>

void somador(Arv *a,int *soma){
	if(!arv_vazia(a)){
		*soma=a->info + *soma;
		somador(a->esq,soma);
		somador(a->dir,soma);
	}
}

int main(){
	Arv *n10 = arv_cria(10,NULL,NULL);
	Arv *n11 = arv_cria(11,NULL,NULL);
	Arv *n3 = arv_cria(3,n10,n11);
	Arv *n4 = arv_cria(4,NULL,NULL);
	Arv *n6 = arv_cria(6,NULL,NULL);
	Arv *n2 = arv_cria(2,n3,n4);
	Arv *n5 = arv_cria(5,NULL,n6);
	Arv *r = arv_cria(1,n2,n5);


	imprime_arvore(r);
	int soma=0;
	somador(r,&soma);
	printf("A soma dos elementos e igual a --%i--\n",soma);
}
