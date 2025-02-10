#include "arvore.h"
#include <stdio.h>
#include <stdlib.h>


int main(){
	Arv *n3 = arv_cria(3,NULL,NULL);
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

	printf("-------------------------------------------------------------------------------------------\n");
	imprime_arvore(r);
	printf("-------------------------------------------------------------------------------------------\n");

}
