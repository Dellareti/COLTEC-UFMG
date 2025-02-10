#include "arvore.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void insere_ordenada_arv(Arv *r,int v,Contato contact){
	if(v<=r->info){
		if(r->esq!=NULL)
			insere_ordenada_arv(r->esq,v,contact);
		else{
			Arv *novo = arv_cria(v,contact,NULL,NULL);
			r->esq = novo;
		}
	}
	else if(v>r->info){
		if(r->dir!=NULL)
			insere_ordenada_arv(r->dir,v,contact);
		else{
			Arv *novo = arv_cria(v,contact,NULL,NULL);
			r->dir = novo;
		}
	}
}
	
int main(){
	int c,i,soma=0;
    char aux[30],aux2[9],aux3[30];
    int pos;
	Contato dono,novo;

	strcpy(dono.nome,"Cachu");
	strcpy(dono.telefone,"40028922");
	strcpy(dono.endereco,"Rua Baker ");
	Arv *r = arv_cria(404,dono,NULL,NULL);

	//printf("%i\n",'C'+'a'+'c'+'h'+'u');
	//404
 
    do{
        printf("-----------MENU---------\n1 - Inserir novo contato\n2 - Buscar contato\n3 - Retira--------------\n"); 
        scanf("%i",&c);
        __fpurge(stdin);
        if(c==1){
            printf("Digite o nome: ");
            fgets(novo.nome,30,stdin);
            printf("Digite o num do telefone deste contato: ");
            fgets(novo.telefone,9,stdin);
            printf("Digite seu endereco: ");
            fgets(novo.endereco,30,stdin);
	
			for(i=0;i<strlen(novo.nome);i++)
				soma+=novo.nome[i];

			insere_ordenada_arv(r,soma,novo);
			soma=0;
        }
        else if(c==2){
            printf("Digite o nome a ser buscado: ");
            fgets(aux,30,stdin);
            busca(r,aux);
        }
        else if(c==3){
            printf("Digite o nome a ser limado: ");
            fgets(aux,30,stdin);
   			for(i=0;i<strlen(novo.nome);i++)
				soma+=novo.nome[i];
        	r = abb_retira(r,soma);
			soma=0;
        }
        else{
            printf("NOP\n");            
            break;
        }
        __fpurge(stdin);
    }while(c!=4);

    arv_libera(r);
}
