#include <stdio.h>
#include <stdlib.h>
#include "fila2.h"

#define N 100

struct lista2 {

    float info;
    struct lista2* ant;
    struct lista2* prox;
};
    typedef struct lista2 Lista2;

/* estrutura da fila */
struct fila2 {
    Lista2* ini;
    Lista2* fim;
};


void insere_ini(Fila2* f, float v) {

    int prec;
    if (f->n == N) { /* fila cheia: capacidade esgotada */

    printf("\n\n Fila estourou !!!\n\n");
    exit(1); /* aborta programa */
}
/* insere elemento na posição precedente ao início */
    prec = (f->ini - 1 + N) % N; /* decremento circular */
    f->vet[prec] = v;
    f->ini = prec; /* atualiza índice para início */
    f->n++

}

void insere_fim (Fila2* f, float v) {
    f->fim = ins2_fim(f->fim,v);
    if (f->ini==NULL) /* fila antes vazia? */
    f->ini = f->fim;
}

float retira_ini (Fila2* f) {
    float v;
    if (vazia(f)) {
    printf("\n\n Fila vazia !!!\n\n");
    exit(1); /* aborta programa */
 }

    v = f->ini->info;
    f->ini = ret2_ini(f->ini);
    if (f->ini == NULL) /* fila ficou vazia? */
    f->fim = NULL;

    return v;
}

float retira_fim (Fila2* f) {
    float v;
    if (vazia(f)) {

    printf("\n\n Fila vazia !!!\n\n");
    exit(1); /* aborta programa */
 }

    v = f->fim->info;
    f->fim = ret2_fim(f->fim);

    if (f->fim == NULL) /* fila ficou vazia? */
    f->ini = NULL;

 return v;
}



