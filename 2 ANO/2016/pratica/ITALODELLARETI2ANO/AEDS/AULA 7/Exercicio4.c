//FIFO
#include <stdio.h>
#include <stdlib.h>
  
//Estrutura da lista que será criada
typedef struct Fila {
    int valor;
    struct Fila *proximo;
} Dados;
  
void insere();
void exclui();
void mostra();
void mostra_erro();
  
//Inicializando os dados da li
Dados *principal = NULL;
Dados *final = NULL;
  
int main(){
    char escolha;
    
    do {
        
        printf("\nMetodo Fila\n\n");
        printf("Escolha uma opcao: \n");
        printf("\t1 - Inserir processo na Fila\n");
        printf("\t2 - Remover o processo de maior tempo da Fila\n");
        printf("\t3 - listar processos da Fila\n");
        printf("\t4 - Sair\n\n");
        printf("Resposta: ");
        scanf("%c", &escolha);
        getchar();
        switch(escolha) {
            
            case '1':
                insere(); 
                break;
            
            case '2':
                if(principal!=NULL){
                    exclui();
                }
                else{
                    printf("\nA Fila esta vazia!\n");
                    getchar();
                }
                break;                
            
            case '3':
                if(principal!=NULL){
                    mostra();
                }
                else{
                    printf("\nA Fila esta vazia!\n");
                    getchar();
                }
                break;                
            case '4':
                printf("\n flw!\n");
                exit(0);
                break;
            
            default:
                printf("\n Voce digitou uma opcao incorreta !!!");
                return 0;
				break;
        }
        getchar();
    }
    while (escolha > 0); 
}
  

void insere(){
    int val;
    printf("\nInsercao: \n");
    printf("--------------------------------------\n");
    printf("Insira o processo desejado: ");
    scanf("%d",&val);
   	getchar();
    Dados *atual = (Dados*)malloc(sizeof(Dados));
    atual -> valor = val;
    atual -> proximo = NULL;
  
    if(principal == NULL){
        principal = final = atual;
    }
   
    else{
        final->proximo=atual;
        final=atual;
    }
  
    printf("\nProcesso inserido!\n");
    printf("--------------------------------------");
    getchar();
}
  

void exclui(){
    Dados *auxiliar;
    printf("\nExclusao: \n");
    printf("--------------------------------------\n");

    auxiliar=principal->proximo;
    
    free(principal);
    //a principal será a auxiliar
    principal=auxiliar;
    printf("\nProcesso excluido!\n");
    printf("--------------------------------------");
    getchar();
}
  

void mostra(){
    int posicao=0;
    Dados *nova=principal;

    printf("\nMostrando processos: \n");
    printf("--------------------------------------\n");
    //laço de repetição para mostrar os valores
    for (; nova != NULL; nova = nova->proximo) {
        posicao++;
        printf("Posicao %d para sair, contem o valor %d\n", posicao, nova->valor);
    }
    printf("--------------------------------------");
    getchar();
}
