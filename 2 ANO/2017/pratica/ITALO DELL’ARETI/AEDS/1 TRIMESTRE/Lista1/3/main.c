#include "lista.h"
#include <stdio.h>

int main(){
	Lista2 *l = NULL;
	l=lst2_insere_ordenado(l,4);
	lst2_imprime(l);
	l=lst2_insere_ordenado(l,10);
	lst2_imprime(l);
	l=lst2_insere_ordenado(l,11);
	lst2_imprime(l);	
	l=lst2_insere_ordenado(l,2);
	lst2_imprime(l);
	l=lst2_insere_ordenado(l,5);
	lst2_imprime(l);
	l=lst2_insere_ordenado(l,1);
	lst2_imprime(l);
	l=lst2_insere_ordenado(l,8);
	lst2_imprime(l);
	l=lst2_insere_ordenado(l,0);
	lst2_imprime(l);

	printf("vou começar a retirar agora!\n");
	l=lst2_retira(l,4);
	lst2_imprime(l);
	l=lst2_retira(l,0);
	lst2_imprime(l);
	l=lst2_retira(l,5);
	lst2_imprime(l);
	l=lst2_retira(l,2);
	lst2_imprime(l);
	l=lst2_retira(l,10);
	lst2_imprime(l);


	lst2_libera(l);

}
