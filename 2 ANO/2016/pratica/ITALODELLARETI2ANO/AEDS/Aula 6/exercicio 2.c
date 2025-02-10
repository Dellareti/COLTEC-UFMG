#include <stdio.h>
#include <stdlib.h>

struct arvore{
    char item;
    arvore *esq,*dir;
};

arvore *Raiz;
//int contador;

void arvore_Construtor(){
    Raiz = NULL;
    //contador=0;
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

int arvore_Inserir(char element, arvore *&Raiz){   
    
	if(Raiz == NULL){
        if((Raiz=(arvore *) malloc(sizeof(arvore)))==NULL)
    
		        return false;
        else{
    
            Raiz->item = element;
            Raiz->esq = Raiz->dir=NULL;
            //contador++;
    
		        return true;
        }
    }
    else{
        
		if(element<Raiz-> item)
            return arvore_Inserir(element,Raiz->esq);
        
	else{
            if(element>Raiz->item)
                return arvore_Inserir(element,Raiz->dir);
     
	        else
                return false;//elemento ja existente
        }
    }
}

//-----------------------------------------
void arvore_Busca_em_Ordem(arvore *&Raiz){
    if(Raiz!=NULL){
        arvore_Busca_em_Ordem(Raiz->esq);
        printf(" %c",Raiz->item);
        arvore_Busca_em_Ordem(Raiz->dir);
    }
}

/*int elementos(){
	return contador -1;
} 
*/

int main(){
    char x,y;

    arvore_Construtor();
	printf("------------------------------------------------ Arvore Binaria -----------------------------------------------------");
    do{
        printf("\n\n Digite o elemento : ");
        fflush(stdin);
        scanf("%c",&x);

        arvore_Inserir(x,Raiz);

        printf("\n Deseja inserir mais um elemento? 1/0:  ");
        fflush(stdin);
        scanf("%c",&y);
    }
	
	while(y!= '0');

//---------------------------------
    printf("\nArvore em ordem:\n");
    arvore_Busca_em_Ordem(Raiz);
    printf("\n\n");

	arvore_Destrutor(Raiz);

    return 0;
}