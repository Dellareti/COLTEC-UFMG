#include <stdio.h> 
#include <stdlib.h> 
#include "listas.h" 

int main() { 

	Lista *l = NULL ; 
	int i ; 

	int n ; 
	scanf("%d", &n);  

		for(i=n; i>=1; i--)
			l = lst_insere(l, i);

	Lista *l2 ; 

		for(i=1; i<=n; i++) 
			l2 = lst_insere(l2, i); 

	printf("The result of funcion lst_igual(l1, l2) is: %d\n", lst_igual(l, l2)); 

	Lista *fim = NULL, *aux = l, *ini = l ;

	
		while((aux = aux->prox) != NULL) 
			fim = aux ; 

		fim->prox = ini ;
 
		do {  
			lst_retira(l, l->prox->info); 

		} while((l = l->prox) != l->prox);

	printf("%d\n", l->info);   
	
	return 0 ; 
} 
