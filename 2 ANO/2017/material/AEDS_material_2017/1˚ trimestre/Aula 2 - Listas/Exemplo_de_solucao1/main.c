#include <stdio.h>
#include <stdlib.h>
#include "listas.h"

int main() {

	int n;
	printf("Digite o número de pessoas: ");
	scanf("%d", &n);

	int i;
	Lista *l = NULL;
	
	for (i = n; i >= 1; i--)
		l = lst_insere(l, i);

	Lista *atual = l, *ini = l, *fim = NULL;
	while((atual = atual->prox) != NULL)
		fim = atual;

	fim->prox = ini;
	
	do {
		printf("%d foi morto.\n", l->prox->info);
		l->prox = l->prox->prox;
	} while((l = l->prox) != l->prox);

	printf("O sobrevivente foi: %d\n", l->info);

	return 0;
}
