#include <stdio.h>
#include <stdlib.h>
#include "grafo.h"

void busca_em_largura(Grafo *g,int inicio,int valor){
    FilaL *fila = fila_cria_l();
    int *visitados = aloc_vetor_int(g->n_vertices);

    Grafo *arvore = cria_grafo(g->n_vertices,1,0);

    int i;
    for(i=0;i<g->n_vertices;i++){
        if(g->matriz[inicio][i]){
            fila_insere_l(fila,i);
            visitados[i]=1;
            arvore = faz_ligacao(arvore,inicio,i,1);
        }
    }
    visitados[inicio]=1;

    while(!fila_vazia_l(fila)){
        inicio = fila_retira_l(fila);
        visitados[inicio]=1;

        for(i=0;i<g->n_vertices;i++){
            if(g->matriz[inicio][i] && visitados[i]==0){
                arvore = faz_ligacao(arvore,inicio,i,1);
                fila_insere_l(fila,i);
            visitados[i]=1;

            }
        }
    }
    printf("GRAFO DA ARVORE GERADA:\n\n");
    imprime_informacoes_grafo(arvore);
    fila_libera_l(fila);
}

Grafo *cria_grafo(int n_vertices,int orientacao,int pesos){
    Grafo *g = (Grafo*)calloc(1,sizeof(Grafo));
    g->matriz = aloca_matriz_int(n_vertices,n_vertices);
    g->graus = (int*) calloc(n_vertices,sizeof(int));
    g->n_vertices=n_vertices;
    g->orientado=orientacao;
    g->tem_pesos=pesos;
    return g;
}

Grafo *faz_ligacao(Grafo *g,int a,int b,int peso){
    //matriz de adjacência
    if(g->tem_pesos)
        g->matriz[a][b]=peso;
    else
        g->matriz[a][b]=1;
    if(!g->orientado){
        g->graus[b]++;
        if(g->tem_pesos)
            g->matriz[b][a]=peso;
        else
            g->matriz[b][a]=1;
    }
    g->graus[a]++;
    return g;
}

void libera_grafo(Grafo *g){
    //libera a matriz
    int i;
    for(i=0;i<g->n_vertices;i++) 
        free(g->matriz[i]);
    free(g->matriz);
    //libera o vetor
    free(g->graus);
}

void imprime_informacoes_grafo(Grafo *g){
    printf("Este e um grafo com %i vertices, ",g->n_vertices);
    g->orientado ? printf("orientado, ") : printf("nao orientado, ");
    g->tem_pesos ? printf("com pesos nas arestas.\n") : printf("sem peso nas arestas.\n");
    
    printf("Abaixo segue sua matriz de adjacencias:\n");
    imprime_matriz_int(g->matriz,g->n_vertices,g->n_vertices);
    printf("O grau de cada vertice e:\n");
    int i;
    for(i=0;i<g->n_vertices;i++)
        printf("O vertice %i tem grau %i.\n",i,g->graus[i]);
    printf("--------\n");
}

int *recebe_copia_vet_int(int *destino,int *origem,int tam){
    int i;
    destino = (int *)calloc(tam,sizeof(int));
    for(i=0;i<tam;i++){
        destino[i]=origem[i];
    }
    return destino;
}

int **aloca_matriz_int(int m, int n){
    int **mat;
    int i;   
    mat = (int**)calloc(m,sizeof(int*));
    for(i=0;i<m;i++)
        mat[i] = (int*) calloc (n,sizeof(int));
    return mat; 
}

int *aloc_vetor_int(int tam){
    return ((int*)calloc(tam,sizeof(int)));
}

void imprime_matriz_int(int **m,int c,int l){
    int i,j;
    printf("--------------\n   ");

    for(i=0;i<l;i++){
        printf("%i",i);
        if(i<9)
            printf("  ");
        else
            putchar(' ');
    }
    putchar('\n');

    for(i=0;i<c;i++){
        printf("%i",i);
        if(i<=9)
            printf("  ");
        else
            putchar(' ');

        for(j=0;j<l;j++){
            printf("%i",m[i][j]); 
                
            if((m[i][j])<10)
                printf("  ");
            else
                putchar(' ');
        }
        putchar('\n');
    }
}



FilaL *fila_cria_l(){
    FilaL *f = (FilaL *) malloc(sizeof(FilaL));
    f->ini = f->fim = NULL;
    return f;
}

void fila_insere_l(FilaL *f,int v){
    Lista *n = (Lista *) malloc(sizeof(Lista));
    int i;
    n->info=v;
    n->prox = NULL;
    if(f->fim != NULL) f->fim->prox = n;
    else f->ini = n;
    f->fim = n;
}

int fila_retira_l(FilaL *f){
    Lista *t;
    int v;
    if(fila_vazia_l(f)){
        printf("Fila vazia!");
        exit(1);
    }
    t = f->ini;
    v = t->info;
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
    for(q=f->ini; q!= NULL; q=q->prox) printf("%i ",q->info);
}
