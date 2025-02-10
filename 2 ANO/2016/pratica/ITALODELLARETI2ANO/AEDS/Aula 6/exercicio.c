#include <stdio.h>
#include <stdlib.h>

struct arvore{
    char item;
    arvore *esq,*dir;
};

arvore *Raiz;
int contador;

void arvore_Construtor(){
    Raiz = NULL;
    contador=0;
}


void arvore_Destrutor(arvore *&Raiz){
    if(Raiz!=NULL){
       
	    arvore_Destrutor(Raiz->esq);
        arvore_Destrutor(Raiz->dir);
        free(Raiz);
        Raiz=NULL;
    }
}

int arvore_Vazia(){
    return Raiz==NULL;
}

//-----------------------------------------
void arvore_Busca_em_Ordem(arvore *&Raiz){
    if(Raiz!=NULL){
        arvore_Busca_em_Ordem(Raiz->esq);
        printf(" %c",Raiz->item);
        arvore_Busca_em_Ordem(Raiz->dir);
    }
}

//------------------------------------------
void arvore_Busca_pre_Ordem(arvore *&Raiz){
    if(Raiz!=NULL){
        printf(" %c",Raiz->item);
        arvore_Busca_pre_Ordem(Raiz->esq);
        arvore_Busca_pre_Ordem(Raiz->dir);
    }
}

//------------------------------------------
void arvore_Busca_pos_Ordem(arvore *&Raiz){
    if(Raiz!=NULL){
        arvore_Busca_pos_Ordem(Raiz->esq);
        arvore_Busca_pos_Ordem(Raiz->dir);
        printf(" %c",Raiz->item);
    }
}

int main(){
  
    arvore_Construtor();
	printf("------------------------------------------------ Arvore Binaria -----------------------------------------------------");
   

//---------------------------------
    printf("\nArvore em ordem:\n");
    arvore_Busca_em_Ordem(Raiz);
    printf("\n\n");

//----------------------------------
    printf("Arvore em pre-ordem:\n");
    arvore_Busca_pre_Ordem(Raiz);
    printf("\n\n");

//---------------------------------
    printf("Arvore em pos-ordem:\n");
    arvore_Busca_pos_Ordem(Raiz);
    printf("\n\n");
	
	arvore_Destrutor(Raiz);

    return 0;
}
