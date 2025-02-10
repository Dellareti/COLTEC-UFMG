#include <stdio.h>
#include "1.h"

int main(){
	Lista *l=NULL;

	l = lst_insere(l,1);
	l = lst_insere(l,2);
	l = lst_insere(l,3);
	lst_imprime_rec(l);
	l = lst_retira_rec(l,2);
	lst_imprime_rec(l);
	lst_libera_rec(l);
}