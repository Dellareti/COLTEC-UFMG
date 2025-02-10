#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
	
	int codigo;
	char nomeLivro[20];
	char autor[20];
	char editora[20];
	int ano;
	int quantidade;
	float valorUnitario;
	
}livro;


//inicio funcoes

void Cabecalheo(){
	printf("--------------------------------------------------------------------------------\n");
	printf("\t Sistema de gerenciamento de biblioteca.\n");
	printf("--------------------------------------------------------------------------------\n");
	
}

int menu(){
	int opcao=0;
	printf("\t\t 1 - Cadastrar Livro \n");
	printf("\t\t 2 - Listar Livro \n");
	printf("\t\t 3 - Sair \n");
	scanf("%d",&opcao);
	return opcao;
}

void zeraVetor(livro *vet){
	int i;
	for(i=0; i < 10 ;i++){
		vet[i].codigo = 0;
	}
}


int retornaUltimaPosicaoUsada(livro *vet){
	
	int i=0;
	while(vet[i].codigo > 0 ){
		i++;
	}
	return i;
}


void cadastraLivro(livro *vet){
	
	int i=0;
	i = retornaUltimaPosicaoUsada(vet);
	
	if(i==10){
		printf("\n Limite de livros atingidos \n");
		return;
	}
	
	printf("\n Esse sera o livro de codigo: [%d]",i+1);
	
	fflush(stdin);
	vet[i+1].codigo = i+1;
	printf("\n Digite o nome do livro:");
	scanf("%c",vet[i+1].nomeLivro);
	fflush(stdin);
	
	printf("\n Digite o autor do livro:");
	scanf("%c",vet[i+1].autor);
	fflush(stdin);
	
	printf("\n Digite a editora do livro :");
	scanf("%c",vet[i+1].editora);
	fflush(stdin);
	
	printf("\n Digite o ano do livro :");
	scanf("%d",&vet[i+1].ano);
	fflush(stdin);
	
	printf("\n Digite a quantidade do livro:");
	scanf("%d",&vet[i+1].quantidade);
	fflush(stdin);
	
	printf("\n Digite o valor do livro:");	
	scanf("%f",&vet[i+1].valorUnitario);
	fflush(stdin);
	
	printf("\n Livro cadastrado com sucesso !\n\n");
	system("PAUSE");
}


void listaAcervo(livro *vet){
	
	int i,totalLivros = 0;
	float valorTotal = 0;
	
	printf("Codigo  Nome              Autor              Editora              Ano      QTD  Valor Unit \n");
	printf("-----------------------------------------------------------------------------------------------\n");
	
	for (i = 0; i < retornaUltimaPosicaoUsada(vet);i++ ){
		printf( " %d     %s    %s    %s    %d    %d   %.2f \n",vet[i].codigo,
									      	  	  	  	  	  vet[i].nomeLivro,
										   	   	   	   	   	  vet[i].autor,
										   	   	   	   	   	  vet[i].editora,
										                      vet[i].ano,
										                      vet[i].quantidade,				
										                      vet[i].valorUnitario);
										  
		valorTotal+=vet[i].valorUnitario * vet[i].quantidade;
		totalLivros+=vet[i].quantidade;																					  
	}
	printf("\n\n Total..........:%d..........%.2f\n",totalLivros,valorTotal);
    system("PAUSE");
}
   
//final funçoes


int main(){
	
	livro vet[10];
	int itemEscolhido;
	
	zeraVetor(vet);
	while(1==1){
		system("CLS");
		Cabecalheo();
		itemEscolhido=menu();
		switch(itemEscolhido){
		
		 case 1:
			system("CLS");
			Cabecalheo();
			printf("\n\t 1- Cadastro de livros  \n");
			cadastraLivro(vet);
		
			break;	
        
	    case 2:
	    	system("CLS");
	    	Cabecalheo();
	    	printf("\n\t 2 - Listagem de acervo  \n");
	    	if (retornaUltimaPosicaoUsada(vet) > 0){
				listaAcervo(vet);
			}
			else{
				printf("\n Nao existem livros cadastrados !!! Cadastre antes de listar  \n");
				system("PAUSE");
				
			}
            break;
		
	    case 3:
			return 0 ;	    
		}
	}   
   	  system("PAUSE");	    
}
