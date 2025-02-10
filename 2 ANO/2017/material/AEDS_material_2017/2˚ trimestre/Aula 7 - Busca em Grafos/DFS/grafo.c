#include <stdio.h>
#include <stdlib.h>
#include "grafo.h"

Grafo *busca_grafo(Grafo *g,int valor){
	int i;
	Grafo *a=NULL;
	g->estado=2;
	if(g->v==valor){
		return g;
	}
	for(i=0;i<g->n_adjacentes;i++){
		if(g->adjacentes[i]->estado!=2)
			a = busca_grafo(g->adjacentes[i],valor);
	}
	return a;
}

void imprime_grafo(Grafo *g){
	int i;
	g->estado=2;
	printf("%i ",g->v);
	for(i=0;i<g->n_adjacentes;i++){
		if(g->adjacentes[i]->estado!=2)
			imprime_grafo(g->adjacentes[i]);
	}
}

void zera_estados(Grafo *g){
	int i;
	if(g->estado!=0)
		g->estado=0;

	for(i=0;i<g->n_adjacentes;i++){
		if(g->adjacentes[i]->estado!=0){
			g->adjacentes[i]->estado=0;
			zera_estados(g->adjacentes[i]);
		}
	}
}

Grafo *cria_grafo(int valor){
	Grafo *g = (Grafo*)malloc(sizeof(Grafo));
	g->v = valor;
	g->estado = 0;
	g->n_adjacentes=0;
	return g;
}

Grafo *insere_como_adjacente(Grafo *g,int valor){
	if(g->n_adjacentes==0)
		g->adjacentes = (Grafo**) malloc(sizeof(Grafo*));
	else 
		g->adjacentes = (Grafo**) realloc(g->adjacentes,(g->n_adjacentes+1)*sizeof(Grafo*));

	g->adjacentes[g->n_adjacentes] = (Grafo*) malloc (sizeof(Grafo));

	g->n_adjacentes++;
	g->adjacentes[g->n_adjacentes-1]->estado=0;
	g->adjacentes[g->n_adjacentes-1]->v=valor;
	return g->adjacentes[g->n_adjacentes-1];
}

void conecta_vertices(Grafo *a,Grafo *b){
	int i,c=0;
	//VERIFICA SE HA CONEXAO ENTRE A-B
	for(i=0;i<a->n_adjacentes;i++){
		if(a->adjacentes[i]->v==b->v){	
			printf("JA HA CONEXAO ENTRE A-B\n");
			c=1;
			break;
		}
	}
	if(c==0){
		a->adjacentes = (Grafo**) realloc(a->adjacentes,(a->n_adjacentes+1)*sizeof(Grafo*));
		a->adjacentes[a->n_adjacentes] = (Grafo*) malloc (sizeof(Grafo));
		a->adjacentes[a->n_adjacentes] = b;
		a->n_adjacentes++;
	}
	c=0;
	//VERIFICA SE HA CONEXAO ENTRE B-A
	for(i=0;i<b->n_adjacentes;i++){
		if(b->adjacentes[i]->v==a->v){
			printf("JA HA CONEXAO ENTRE B-A\n");
			c=1;
			break;
		}
	}
	if(c==0){
		b->adjacentes = (Grafo**) realloc(b->adjacentes,(b->n_adjacentes+1)*sizeof(Grafo*));
		b->adjacentes[b->n_adjacentes] = (Grafo*) malloc (sizeof(Grafo));
		b->adjacentes[b->n_adjacentes] = b;
		b->n_adjacentes++;
	}

}

FilaL *fila_cria_l(){
	FilaL *f = (FilaL *) malloc(sizeof(FilaL));
	f->ini = f->fim = NULL;
	return f;
}

void fila_insere_l(FilaL *f,Grafo* no){
	Lista *n = (Lista *) malloc(sizeof(Lista));

	n->g=no;
	n->prox = NULL;
	if(f->fim != NULL) f->fim->prox = n;
	else f->ini = n;
	f->fim = n;
}

Grafo* fila_retira_l(FilaL *f){
	Lista *t;
	Grafo *v;
	if(fila_vazia_l(f)){
		printf("Fila vazia!");
		exit(1);
	}
	t = f->ini;
	v = t->g;
	f->ini = t->prox;
	if(f->ini==NULL) f->fim = NULL;
	free(t);
	return v;
}

int fila_vazia_l(FilaL *f){
	return (f->ini == NULL);
}

void fila_libera_l(FilaL *f){
	Lista *q = f->ini;
	while(q!=NULL){
		Lista *t = q->prox;
		free(q);
		q = t;
	}
	free(f);
}