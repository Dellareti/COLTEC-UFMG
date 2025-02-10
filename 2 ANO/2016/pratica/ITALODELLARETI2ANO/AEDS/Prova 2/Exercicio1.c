#include <stdio.h>
#include <stdlib.h>


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

void consultaNivel(no *p){
     int i, nivel;
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

 int menu(){
           int op;
           printf("\n>>>>>>>>>>MENU<<<<<<<<<<\n\n");
           printf("1 - Consultar lista\n");
           printf("2 - Inserir valor\n");
           printf("3- Quantidades de nos da arvore\n");
           printf("4 - Imprimir arvore\n");
           printf("5 - Sair\n\n>>>>>>>>>>MENU<<<<<<<<<<\n\n\n");
           printf("Digite sua opcao: ");
           scanf("%d", &op);
           return op;
           }


int main(){
    int n,a,b;
    no *raiz, *aux;
    raiz = NULL;
    int opcao;

    while(opcao!=12){
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
                            scanf("%d", &n);
                            if(n!=-1){
                            insere(n, &raiz);
                            }
                       }while (n!=-1);
                       system("cls");

                       getch();
                       break;

                  case 3:
                       system("cls");
                       b=contaNos(raiz);
                       printf("\n>>>>>>>>>>>>><<<<<<<<<<<<<\n\n");
                       printf("  A arvore possui %d nos!\n",b);
                       printf("\n>>>>>>>>>>>>><<<<<<<<<<<<<\n\n");
                       getch();
                       break;
                  case 4:
                       system("cls");
                       printf("ARVORE BINARIA\n");
                       imprime(raiz,0);
                       getch();
                       break;
                  case 5:
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
