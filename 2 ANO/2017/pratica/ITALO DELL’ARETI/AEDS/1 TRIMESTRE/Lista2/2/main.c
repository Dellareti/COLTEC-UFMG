#include "arvore.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>


void conta_folhas(ArvVar *a,int *folhas){
	ArvVar *p;
	if(a->filho==NULL)
		*folhas=*folhas+1;
	for(p=a->filho;p!=NULL;p=p->irmao)
		conta_	folhas(p,folhas);
}


int main(){


	ArvVar *r = arvv_cria(1);
	ArvVar *a2 = arvv_cria(2);
	ArvVar *a3 = arvv_cria(3);
	ArvVar *a4 = arvv_cria(4);
	ArvVar *a5 = arvv_cria(5);
	arvv_insere(r,a2);
	arvv_insere(r,a3);
	arvv_insere(r,a4);
	arvv_insere(r,a5);
	arvv_imprime(r);
	int folhas=0;
	conta_folhas(r,&folhas);
	printf("\n%i folhas\n",folhas);

}
