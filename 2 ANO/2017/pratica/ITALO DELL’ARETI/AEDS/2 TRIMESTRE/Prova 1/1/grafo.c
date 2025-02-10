#include <stdio.h>
#include <stdlib.h>
#include "grafo.h"

void busca_em_largura(Grafo g,int inicio,int valor){
    FilaL *fila = fila_cria_l();
    int *visitados = aloc_vetor_int(g.n_vertices);
    int encontrado=0;
    printf("------BUSCA EM LARGURA------\n");

    if(inicio==valor){ 
        printf("encontrei o %i na primeira pos!\n",valor);
        encontrado=1;
    }
    int i;
    for(i=0;i<g.n_vertices;i++){
        if(g.matriz[inicio][i])
            fila_insere_l(fila,i);
    }
    visitados[inicio]=1;
    printf("vertice atual = %i\n",inicio);

    while(!fila_vazia_l(fila)){
        inicio = fila_retira_l(fila);
        printf("vertice atual = %i\n",inicio);
        if(inicio==valor){
            printf("encontrei o %i!\n",valor);
            encontrado=1;
        }
        visitados[inicio]=1;

        for(i=0;i<g.n_vertices;i++){
            if(g.matriz[inicio][i] && visitados[i]==0)
                fila_insere_l(fila,i);
        }
    }
    if(!encontrado)
        printf("Não encontrei o valor procurado\n");
    fila_libera_l(fila);
}

void busca_prof(Grafo g,int *visitados,int inicial,int encontrar,int cont,int *encontrado){
    int i,j;
    visitados[inicial]=1;
    int *visitados_atual;
    visitados_atual=recebe_copia_vet_int(visitados_atual,visitados,g.n_vertices);
    if(inicial==encontrar){
        printf("Foi encontrado o vertice %i a %i vertices de distancia\n",encontrar,cont);
        *encontrado=1;
    }
    for(i=0;i<g.n_vertices;i++){
        if(g.matriz[inicial][i] && visitados[i]==0){
            printf("Sou o v%i e vou pro v%i\n",inicial,i);
            busca_prof(g,visitados,i,encontrar,cont+1,encontrado);
        }
    } 
}

void busca_em_profundidade(Grafo g,int inicial,int encontrar){
    int *visitados = aloc_vetor_int(g.n_vertices);
    int achar = 0;
    printf("------BUSCA EM PROFUNDIDADE------\n");
    busca_prof(g,visitados,inicial,encontrar,0,&achar);
    if(!achar)
        printf("Não foi encontado o %i\n",encontrar);
}

Grafo cria_grafo(int n_vertices,int orientacao,int pesos){
    Grafo g;
    g.matriz = aloca_matriz_int(n_vertices,n_vertices);
    g.incidencia = aloca_matriz_int(n_vertices,(n_vertices-1)*n_vertices);
    g.graus = (int*) calloc(n_vertices,sizeof(int));
    g.ligacoes = (int*) calloc(n_vertices,sizeof(int));
    g.n_vertices=n_vertices;
    g.orientado=orientacao;
    g.tem_pesos=pesos;
    return g;
}

Grafo faz_ligacao(Grafo g,int a,int b,int peso){
    if(g.tem_pesos)
        g.matriz[a][b]=peso;
    else
        g.matriz[a][b]=1;

    g.incidencia[a][g.ligacoes[a]++]=1;

    if(!g.orientado){
        g.incidencia[b][g.ligacoes[b]++]=1;
        g.graus[b]++;
        if(g.tem_pesos)
            g.matriz[b][a]=peso;
        else
            g.matriz[b][a]=1;
    }
    g.graus[a]++;
    return g;
}

void libera_grafo(Grafo g){
    //libera a matriz
    int i;
    for(i=0;i<g.n_vertices;i++) 
        free(g.matriz[i]);
    free(g.matriz);
    //libera o vetor
    free(g.graus);
}

void imprime_informacoes_grafo(Grafo g){
    printf("Este e um grafo com %i vertices, ",g.n_vertices);
    g.orientado ? printf("orientado, ") : printf("nao orientado, ");
    g.tem_pesos ? printf("com pesos nas arestas.\n") : printf("sem peso nas arestas.\n");
    
    printf("Abaixo segue sua matriz de adjacencias:\n");
    imprime_matriz_int(g.matriz,g.n_vertices,g.n_vertices);
    printf("Abaixo segue sua matriz de incidencia:\n");
    imprime_matriz_int(g.incidencia,g.n_vertices,(g.n_vertices-1)*g.n_vertices);
    printf("O grau de cada vertice e:\n");
    int i;
    for(i=0;i<g.n_vertices;i++)
        printf("O vertice %i tem grau %i.\n",i,g.graus[i]);
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
