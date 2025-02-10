#include <stdio.h>
#include <stdlib.h>
#include "pilhas.h"

Pilha *pilha_cria() {
	Pilha *p = (Pilha *) malloc(sizeof(Pilha));
	p->n = 0;

	return p;
}

void pilha_push(Pilha *p, char v) {
	if (p->n == N) {
		printf("A capacidade da pilha estorou.");
		exit(1);
	}

	p->vet[p->n++] = v;
}

char pilha_pop(Pilha *p) {
	if (pilha_vazia(p)) {
		printf("Pilha vazia.");
		exit(1);
	}
	
	return p->vet[--p->n];
}

int pilha_vazia(Pilha *p) {
	return (p->n == 0);
}

void pilha_libera(Pilha *p) {
	free(p);	
}
