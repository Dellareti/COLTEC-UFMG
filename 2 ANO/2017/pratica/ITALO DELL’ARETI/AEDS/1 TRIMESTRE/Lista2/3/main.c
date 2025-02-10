#include "arvore.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>


void conta_filhos(ArvVar *a){
	ArvVar *p;
	int cont=0;
	for(p=a->filho;p!=NULL;p=p->irmao){
		conta_filhos(p);
		cont++;
	}
	printf("O No %i tem %i filhos\n",a->info,cont);
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
	arvv_insere(a4,a5);
	arvv_imprime(r);
	putchar('\n');
	conta_filhos(r);
}
