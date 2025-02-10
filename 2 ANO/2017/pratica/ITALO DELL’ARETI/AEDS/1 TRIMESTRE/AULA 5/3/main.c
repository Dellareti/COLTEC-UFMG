#include "arvore.h"
#include <stdio.h>
#include <stdlib.h>

void conta_coisas(Arv *a,int *folhas,int *uf,int *df){
	if(!arv_vazia(a)){
		if(a->dir==NULL && a->esq==NULL) *folhas=*folhas + 1;
		if((a->dir!=NULL && a->esq==NULL)||(a->dir==NULL && a->esq!=NULL)) *uf=*uf + 1;
		if(a->dir!=NULL && a->esq!=NULL) *df=*df + 1;
		conta_coisas(a->esq,folhas,uf,df);
		conta_coisas(a->dir,folhas,uf,df);
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

	arv_imprime_preordem(r);
	putchar('\n');
	arv_imprime_simetrica(r);
	putchar('\n');
	arv_imprime_posordem(r);
	putchar('\n');
	printf("------------------------------------------\n");
	imprime_arvore(r);
	int folhas=0,uf=0,df=0;//um filho, dois filhos
	conta_coisas(r,&folhas,&uf,&df);
	printf("A arvore bin tem %i folhas, %i nos com 1 filho, e %i nos com 2 filhos\n",folhas,uf,df);

}