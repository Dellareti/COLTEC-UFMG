#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "hash.h" 

Lista* lst_cria(){
    return NULL;
}

int lst_vazia(Lista *l){
    if (l == NULL)
        return 1;
    else
        return 0;
}

void lst_libera(Lista *l){
    Lista *p = l;
    while(p!=NULL){
        Lista *t = p->prox;
        free(p);
        p=t;
    }
}

int define_key(char nome[20]){
    int soma=0,i;
    if(isalpha(nome[0])!=0){
        for(i=0;i<strlen(nome);i++){
            soma+=nome[i];
        }
        return soma%29;
    }   
    else
        return (-1);
}

Lista* insere_contato(Lista *l, char nome[20], int key){
    Lista *novo = (Lista *) malloc (sizeof(Lista));
    int i,tell;
    char endereco[50];

    //insere nome
    for(i=0;i<strlen(nome);i++)
        novo->nome[i] = nome[i];

    //insere numero
    printf("\nDigite o telefone do contato:\t");
    scanf("%d",&tell);
    getchar();
    novo->telefone=tell;

    //insere enderco
    printf("\nDigite seu endereço:\t");
    fgets(endereco,50,stdin);
    for(i=0;i<strlen(endereco);i++)
        novo->endereco[i] = endereco[i]; 

    //insere key
    novo->key=key;   

    novo->prox = l;
    return novo;
}

void imprime_info(Lista *l, int letra){
    Lista *p;
    printf("\nContatos com as letras %c e %c:\n\n", letra,letra+1);
    for(p=l;p!=NULL;p=p->prox){
        printf("Nome:\t%s\n", p->nome);
        printf("Número:\t%d\n",p->telefone);
        printf("Endereço:\t%s\n",p->endereco);
    }
}

void procura_contato(Lista *l,char procurado[20]){
    
    Lista *p;
    int controle=0;

    for(p=l;p!=NULL;p=p->prox){
        if(strcmp(procurado,p->nome)==0){
            controle++;
            printf("\nContato Encontrado.\n\n");
            printf("Nome:\t%s\n", p->nome);
            printf("Número:\t%d\n",p->telefone);
            printf("Endereço:\t%s\n",p->endereco);
        }
    }
    if(controle==0)
        printf("O contato não esta na lista.\n");
}

Lista *lst_retira(Lista *l, int v, int *cont){
    Lista *ant = NULL;
    Lista *p=l;
 
    while(p!=NULL && p->key!=v){
        ant=p;
        p=p->prox;
    }
 
    if (p==NULL){
        printf("O contato não esta na lista.\n");
        *cont=-1;
        return l;
    }
    if(ant==NULL)
        l=p->prox;
    else
        ant->prox=p->prox;
 
    free(p);
 
    return l;
}