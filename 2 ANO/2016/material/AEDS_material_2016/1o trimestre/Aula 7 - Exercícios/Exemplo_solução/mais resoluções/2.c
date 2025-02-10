#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct arv {
	char info;
	struct arv *esq;
	struct arv *dir;
} Arv;

Arv *arv_insere(Arv *a, char info);
void pre_imprime(Arv *a);
void sim_imprime(Arv *a);
void pos_imprime(Arv *a);

int main() {

	Arv *a = NULL;

	int i;
	char str[128];

	printf("Inserir na árvore: ");
	scanf("%s", str);
	
	for (i = 0; i < strlen(str); i++)
		a = arv_insere(a, str[i]);

	printf("Impressão PRE-ORDEM.\n");
	pre_imprime(a);
	printf("\n\n");

	printf("Impressão SIMETRICA.\n");
	sim_imprime(a);
	printf("\n\n");

	printf("Impressão POS-ORDEM.\n");
	pos_imprime(a);
	printf("\n\n");

	return 0;
}

Arv *arv_insere(Arv *a, char info) {
	Arv *n = (Arv *) malloc(sizeof(Arv));
	n->info = info;
	n->esq  = NULL;
	n->dir  = NULL;

	if (a == NULL)
		return n;

	if (info >= '0' && info <= '9') {
		if (a->esq)
			a->dir = arv_insere(a->dir, info);
		else
			a->esq = arv_insere(a->esq, info);

		return a;
	} else {
		n->esq = a;
		return n;
	}
}

void pre_imprime(Arv *a) {
	if (a != NULL) {
		printf("%c", a->info);
		pre_imprime(a->esq);
		pre_imprime(a->dir);
	}
}

void sim_imprime(Arv *a) {
	if (a != NULL) {
		sim_imprime(a->esq);
		printf("%c", a->info);
		sim_imprime(a->dir);
	}
}

void pos_imprime(Arv *a) {
	if (a != NULL) {
		pos_imprime(a->esq);
		pos_imprime(a->dir);
		printf("%c", a->info);
	}
}
