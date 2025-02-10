#include "listas.h"
#include <stdio.h>
#include <math.h>

Lista* enche(Lista * l){
	int tam = rand()%10;
	
	while(tam==0)tam = rand()%10;
	int i=0;

	while(i<tam){
		l = lst_insere(l,rand()%10);
		i++;
	}
	return l;
  }

 Lista* sem_repetir(Lista *l1,Lista *l2){
	Lista *a=l1;
	Lista *b=l2;
	Lista *l3= lst_cria();


	while(a!=NULL){
		if(lst_busca(l3,a->info)==NULL)
			l3 = lst_insere(l3,a->info);
		a=a->prox;
   }
	
        while(b!=NULL){
		if(lst_busca(l3,b->info)==NULL)
			l3 = lst_insere(l3,b->info);
		b=b->prox;
	}
	return l3;
  }



  int main(){
	
        srand(time(NULL));

	Lista *L1 = lst_cria();
	Lista *L2 = lst_cria();
	Lista *L3 = lst_cria();



	L1 = enche(L1);
	L2 = enche(L2);

	printf("-------Lista fas--------\n");
	lst_imprime(L1);
	printf("-------Lista Arya Stark --------\n");
	lst_imprime(L2);
	
	L3 = sem_repetir(L1,L2);

	printf("---------------------- Lista optimizada ------------------------\n");
	lst_imprime(L3);

	lst_libera(L1);
	lst_libera(L2);
	lst_libera(L3);


	return 0;
}
