#include <stdio.h>
#include<math.h>
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

    Lista *l3 ;

		for(i=1; i<=n; i++)
			l3 = lst_insere(l3, i);

			Lista *l4 ;

		for(i=1; i<=n; i++)
			l4 = lst_insere(l4, i);

	printf("A interseccao de l4 e l1 : %d\n", lst_igual(l1, l4));

	Lista *fim = NULL, *aux = l, *ini = l ;

   srand(time(NULL))

		while((aux = aux->prox) != NULL)
			fim = aux ;

		fim->prox = ini ;

		do {
			lst_retira(l, l->prox->info);

		} while((l = l->prox) != l->prox);

	printf("%d\n", l->info);


printf("\n\n \n\n");
	return 0 ;
}
