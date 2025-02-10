#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int quantidadeNos = 0;

typedef struct _no{
        int chave;
        int cont;
        
        struct _no *esq, *dir, *pai;
        }no;

no* auxPai = NULL;

void vaziaArvore(no *raiz){
    if (raiz == NULL){
             printf("   A arvore esta vazia\n\n");
             }
             else {
                  printf("   A arvore nao esta vazia\n\n");
                  }
    }
        
void insere (int x, no **p){
      
      if (*p==NULL){
                    *p=(no *)malloc(sizeof(no));
                    (*p)->chave=x;
                    (*p)->dir=NULL;
                    (*p)->esq=NULL;
                    (*p)->pai = auxPai;
                    (*p)->cont=0;
                    (*p)->cont++;
      }
      else{
            if (x<(*p)->chave){
                if((*p)->esq == NULL)
                    auxPai = *p;
                insere(x, &(*p)->esq);
            }
            if(x>(*p)->chave){
                if((*p)->dir == NULL)
                    auxPai = *p;               
                insere(x, &(*p)->dir);
            }
            if(x == (*p)->chave){
                (*p)->cont++;
                return;
            }
      }
}

int contaNos(no *p){
    if(p != NULL){
         quantidadeNos ++;
         contaNos(p -> dir);
         contaNos(p -> esq);        
    }
    return quantidadeNos;
}

no* busca(no *arvore, int x){
   if (arvore == NULL)
       return NULL;
   if (x == arvore->chave)
       return arvore;
   if (x < arvore->chave) 
       return busca(arvore->esq, x);
   else 
       return busca(arvore->dir, x);
}


void imprime(no *p, int nivel){
     int i;
     if(p == NULL)
        return;
     imprime(p->dir, nivel+1);
     for(i=0;i<nivel;i++)
        printf("      ");
     printf("%6d\n\n",p->chave);
     imprime(p->esq,nivel+1);
     
}


void preordem (no *arvore){
     if(arvore != NULL){
          printf("%d\n",arvore->chave);
          preordem(arvore->esq);
          preordem(arvore->dir);
     }
}

void emordem(no *arvore){
     if(arvore != NULL){
           emordem(arvore->esq);
           printf("%d\n",arvore->chave);
           emordem(arvore->dir);
     }
}

void posordem(no *arvore){
     if(arvore != NULL){
                 posordem(arvore->esq);
                 posordem(arvore->dir);
                 printf("%d\n",arvore->chave);
     }
}

int contaFolhas(no *arvore){
   if(arvore == NULL)
        printf("\n\n Arvore vazia");
    
   if(arvore->esq == NULL && arvore->dir == NULL)
        return 1;
   return contaFolhas(arvore->esq) + contaFolhas(arvore->dir);
}

                          
 int menu(){
           int op;
           
           printf("1 - Consultar lista\n");
           printf("2 - Inserir valor\n");
           printf("3 - Imprimir pre ordem\n");
           printf("4 - Imprimir in-ordem\n");
           printf("5 - Imprimir pos ordem\n");
           printf("6 - Quantidades de nos da arvore com numero de filhos\n");
           printf("7 - Imprimir arvore\n");           
           printf("8 - Quantidades de folhas da arvore com numero de filhos\n");
		   printf("9 - Sair\n\n>>>>>>>>>>MENU<<<<<<<<<<\n\n\n");
		   printf("Digite sua opcao: ");
           fflush(stdin);
		   scanf("%d", &op);
           return op;
           }
      

int main(){
    int n,a,b,c,d,e;
    no *raiz, *aux;
    raiz = NULL;
    int opcao;
    
    while(opcao!=9){
    system("cls");
    opcao = menu();
    switch(opcao){
                  
                  case 1:
                       system("cls");
                       printf("\n>>>>>>>>>>>>><<<<<<<<<<<<<\n\n");
                       vaziaArvore(raiz);
                       printf(">>>>>>>>>>>>><<<<<<<<<<<<<\n\n");
                       getch();
                       break;
                  case 2:
                       system("cls");
                       printf("\n>>>>>>>>>>>>><<<<<<<<<<<<<\n\n");
                       printf("Digite -1 para terminar\n");
                       printf("\n>>>>>>>>>>>>><<<<<<<<<<<<<\n\n");
                       do{
                            printf("Digite um numero: ");
           					fflush(stdin);
		                    scanf("%d", &n);
                            if(n!=-1){
                            insere(n, &raiz);                             
                            }
                       }while (n!=-1);
                       system("cls");
                       
                       imprime(raiz,0);
                       fflush(stdin);
					   getch();
                       break;
                  case 3:
                       system("cls");
                       printf("\n>>>>>>>>>>>>><<<<<<<<<<<<<\n\n");
                       printf("------> Pre-Ordem <------\n");
                       printf("\n>>>>>>>>>>>>><<<<<<<<<<<<<\n\n");
                       preordem(raiz);
                       fflush(stdin);
					   getch();
                       break;
                  case 4:
                       system("cls");
                       printf("\n>>>>>>>>>>>>><<<<<<<<<<<<<\n\n");
                       printf("------> Em-Ordem <------\n");
                       printf("\n>>>>>>>>>>>>><<<<<<<<<<<<<\n\n");
                       emordem(raiz);
                       fflush(stdin);
					   getch();
                       break;
                  case 5:
                       system("cls");
                       printf("\n>>>>>>>>>>>>><<<<<<<<<<<<<\n\n");
                       printf("------> Pos-Ordem <------\n");
                       printf("\n>>>>>>>>>>>>><<<<<<<<<<<<<\n\n");
                       posordem(raiz);
                       fflush(stdin);
					   getch();
                       break;
                
                  case 6:
                       system("cls");
                       b=contaNos(raiz);
                       d=contaFolhas(raiz);
					   printf("\n>>>>>>>>>>>>><<<<<<<<<<<<<\n\n");
                       printf("  A arvore possui %d nos e %d folhas\n",b,d);
                       printf("\n>>>>>>>>>>>>><<<<<<<<<<<<<\n\n");
                       fflush(stdin);
					   getch();
                       break;
                  case 7:
                       system("cls");
                       printf("ARVORE BINARIA\n");
                       imprime(raiz,0);
                       getch();
                       break;
                 case 8 :
				 	system("cls");
					   c=contaFolhas(raiz);
                       e= contaNos(raiz);
					   printf("\n>>>>>>>>>>>>><<<<<<<<<<<<<\n\n");
                       printf("  A arvore possui %d folhas e %d nos\n",c,e);
                       printf("\n>>>>>>>>>>>>><<<<<<<<<<<<<\n\n");
                       fflush(stdin);
					   getch();
                       break;	
				 
				 
				  case 9:                       
                       exit(0);
                       break;
                  	
                  default :
                       system("cls");
                       printf("opcao nao existe! tente novamente");
                       getch();
                       break;   
                  }
                    
                    }

    system("PAUSE");
    return 0;

}
