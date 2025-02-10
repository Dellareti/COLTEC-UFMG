#include "arvore.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

Arv* arv_criavazia(){return NULL;}

Arv* arv_cria(int valor,Arv* esq,Arv* dir){
	Arv *raiz = (Arv*) malloc(sizeof(Arv));
	raiz->info =valor;
	raiz->esq = esq;
	raiz->dir = dir;	
	return raiz;
}

int arv_vazia(Arv* a){
	return (a == NULL);	
}

void arv_imprime_preordem(Arv* a){
	if(!arv_vazia(a)){
		printf("%i\t",a->info);
		arv_imprime_preordem(a->esq);
		arv_imprime_preordem(a->dir);
	}
}

void arv_imprime_simetrica(Arv* a){
	if(!arv_vazia(a)){
		arv_imprime_simetrica(a->esq);
		printf("%i\t",a->info);
		arv_imprime_simetrica(a->dir);
	}
}

void arv_imprime_posordem(Arv *a){
	if(!arv_vazia(a)){
		arv_imprime_posordem(a->esq);
		arv_imprime_posordem(a->dir);
		printf("%i\t",a->info);
	}
}

Arv* arv_libera(Arv* a){
	if(!arv_libera(a)){
		arv_libera(a->esq);
		arv_libera(a->dir);
		free(a);
	}
	return NULL;
}

int arv_pertence(Arv* a,int v){
	if(arv_vazia(a))	return 0;
	else return a->info == v || arv_pertence(a->esq,v) || arv_pertence(a->dir,v);
}

static int max2(int a,int b){
	return (a>b) ? a : b ;
}

int arv_altura(Arv *a){
	if(arv_vazia(a))
		return -1; 
	else 
		return 1 + max2 (arv_altura(a->esq),arv_altura(a->dir));
}

void imprime_arvore(Arv *r){
	/*
	  Esta função usa de uma fila de impressão
	  Para imprimir uma árvore binária
	  De forma em que seus espaços são calculados
	  de forma logarítmica de acordo com a linha
	  a ser impressa;
	*/

	FilaL *fila = fila_cria_l(); //FILA DE IMPRESSÃO
	int h = arv_altura(r); // h == altura
	int linha = h-1;
    int i;

	//PRIMEIRA IMPRESSAO
	if(r==NULL){
		printf("Arvore vazia!\n");
		return;
	}
	// A IMPRESÃO FUNCIONA DE FORMA LOGARÍTIMICA
	// A QUANTIDADE DE ESPAÇOS É CALCULADA COMO:
	// ESPAÇOS EM UMA LINHA L É DEFINIDO POR:
	// Nlinha = log base 2 dos espaços
	// ENTÃO:---espaços = 2 ** n_linha---
	
	for(i=0;i<pow(2,h);i++) putchar('\t');
	printf("%i\n",r->info);

	// INSERE OS PRIMEIROS FILHOS NA FILA DE IMPRESSÃO
    fila_insere_l(fila,r->esq);
    fila_insere_l(fila,r->dir);

   	Arv *no_lido; // NÓ QUE SERÁ LIDO DA FILA;
    int pot_atual=1;
    int epl=0; // elemento p/ linha

    while(linha>=0){
		no_lido = fila_retira_l(fila);

		if(no_lido != NULL){
			for(i=0;i<pow(2,linha);i++) putchar('\t');
			printf("%i",no_lido->info);			
	
			if(linha!=0){ // ALINHAMENTO
				for(i=0;i<((pow(2,linha+1)-1)-pow(2,linha));i++)putchar('\t'); 
			}

			fila_insere_l(fila,no_lido->esq);
			fila_insere_l(fila,no_lido->dir);
		}
		else{
			for(i=0;i<pow(2,linha);i++) putchar('\t');
			putchar('\t');

			if(linha!=0){ // ALINHAMENTO
				for(i=0;i<((pow(2,linha+1)-1)-pow(2,linha));i++)putchar('\t'); 
			}

			fila_insere_l(fila,NULL);
			fila_insere_l(fila,NULL);
		}
		epl++;	// APÓS QUALQUER UM DOS CASOS, UM ELEMENTO FOI IMPRESSO
		
		// VERIFICAÇÃO DA QUANTIDADE DE ELEMENTOS NA LINHA
		if(epl==pow(2,pot_atual)){
			pot_atual++;
			linha--;
			epl=0;
			putchar('\n');
		}
	}
	putchar('\n');
	fila_libera_l(fila);
}

//PARTE DE FILAS-----------------------------------------------

FilaL *fila_cria_l(){
	FilaL *f = (FilaL *) malloc(sizeof(FilaL));
	f->ini = f->fim = NULL;
	return f;
}

void fila_insere_l(FilaL *f,Arv* no){
	Lista *n = (Lista *) malloc(sizeof(Lista));

	n->r=no;
	n->prox = NULL;
	if(f->fim != NULL) f->fim->prox = n;
	else f->ini = n;
	f->fim = n;
}

Arv* fila_retira_l(FilaL *f){
	Lista *t;
	Arv *v;
	if(fila_vazia_l(f)){
		printf("Fila vazia!");
		exit(1);
	}
	t = f->ini;
	v = t->r;
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

void fila_imprime_l(FilaL *f){
	Lista *q;
	for(q=f->ini; q!= NULL; q=q->prox) printf("%i",q->r->info);
}

//ARVORE COM FILHOS VARIAVEIS

ArvVar *arvv_cria(int v){
	ArvVar *a = (ArvVar*) malloc (sizeof(ArvVar));
	a->info = v;
	a->filho = NULL;
	a->irmao = NULL;
	return a;
}

void arvv_insere(ArvVar *r,ArvVar *inserido){
	inserido->irmao = r->filho;
	r->filho = inserido;
}

void arvv_imprime(ArvVar *a){
	ArvVar *p;
	printf("%i\t",a->info);
	for(p=a->filho;p!=NULL;p=p->irmao)
		arvv_imprime(p);
}

int arvv_pertence(ArvVar *a,int v){
	ArvVar *p;
	if(a->info ==v)
		return 1;
	else{
		for(p=a->filho;p!=NULL;p=p->irmao){
			if(arvv_pertence(p,v))
			return 1;
		}
		return 0;
	}
}

void arvv_libera(ArvVar *a){
	ArvVar *p = a->filho;
	while(p!=NULL){
		ArvVar *t = p->irmao;
		arvv_libera(p);
		p=t;
	}
	free(a);
}

int arvv_altura(ArvVar *a){
	int hmax = -1;
	ArvVar *p;

	for(p=a->filho;p!=NULL;p=p->irmao){
		int h = arvv_altura(p);
		if(h>hmax) hmax = h;
	}
	return hmax +1;
}

