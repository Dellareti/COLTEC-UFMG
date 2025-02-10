#include <stdio.h>
#include <stdlib.h>
#include "listas.h"

/*Funcoes de lista encadeada*/

Lista* lst_cria() {
	return NULL;
}

Lista* lst_insere(Lista *l, int i) {
	Lista *novo = (Lista *) malloc (sizeof(Lista));
	novo->info = i;
	novo->prox = l;
	return novo;
}

void lst_imprime(Lista *l) {
	Lista *p;

	for (p = l; p != NULL; p = p->prox)
		printf("info %d\n", p->info);
}

int lst_vazia(Lista *l) {
	if (l == NULL)
		return 1;
	else
		return 0;
}

Lista* lst_busca(Lista *l, int v) {
	Lista *p;

	for (p = l; p != NULL; p->prox)
		if (p->info == v)
			return p;

	return NULL;
}

Lista *lst_retira(Lista *l, int v) {
	Lista *ant = NULL;
	Lista *p = l;

	while (p != NULL && p->info != v) {
		ant = p;
		p = p->prox;
	}

	if (p == NULL)
		return l; // elemento nao encontrado, retorna lista original

	if (ant == NULL)
		l = p->prox; // retira elemento do in´ıcio
	else
		ant->prox = p->prox; // retira elemento do meio

	free(p);

	return l;
}

void lst_libera(Lista *l) {
	Lista *p = l;

	while (p != NULL) {
		Lista *t = p->prox;

		free(p);
		p = t;
	}
}

Lista *lst_insere_ordenado(Lista *l, int v) {
	Lista *novo;
	Lista *ant = NULL;
	Lista *p = l;

	while (p != NULL && p->info < v) {
		ant = p;
		p = p->prox;
	}

	novo = (Lista*) malloc (sizeof(Lista));
	novo->info = v;

	if (ant == NULL) {
		novo->prox = l;
		l = novo;
	} else {
		novo->prox = ant->prox;
		ant->prox = novo;
	}

	return l;
}

int lst_igual(Lista *l1, Lista *l2) {
	Lista *N1, *N2;

	for (N1 = l1, N2 = l2; N1 != NULL; N1 = N1->prox, N2 = N2->prox)
		if(N1->info != N2->info)
			return 0;
	
	return 1;
}

/*listas circulares*/
void lcirc_imprime(Lista *l) {
	Lista *p = l;

	if (p) 
		do {
			printf("%d", p->info);
			p = p->prox;
		} while (p != l);
}

/*listas duplamente encadeadas*/
Lista2 *lst2_insere(Lista2 *l, int v) {
	Lista2 *novo = (Lista2 *) malloc (sizeof(Lista2));

	novo->info = v;
	novo->prox = l;
	novo->ant = NULL; //inserindo no início da lista

	if (l != NULL)
		l->ant = novo;

	return novo;
}

Lista2 *lst2_busca(Lista2 *l, int v) {
	Lista2 *p;

	for (p = l; p != NULL; p = p->prox)
		if (p->info == v)
			return p;

	return NULL; //nao encontrou o elemento
}

Lista2 *lst2_retira(Lista2 *l, int v) {
	Lista2 *p = lst2_busca(l, v);

	if (p == NULL)
		return l; //elemento nao encontrado

	if (l == p)
		l = p->prox; //se retirar o primeiro elemento da lista
	else
		p->ant->prox = p->prox;

	if (p->prox != NULL) //testa se é o último elemento da lista
		p->prox->ant = p->ant;

	free(p);

	return l;
}
