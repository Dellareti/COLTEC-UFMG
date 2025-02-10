#include <stdio.h>
#include <stdlib.h>
#include "cola.h"
#include "menu.h"

int main(){
	// Declaracao de variaveis
	int n, i;
	int op=1;						// Variavel usada para entrar nas funcoes de menu
	int op_real;					// Variavel usada para navegar no menu secundario
	int x, y; 						// Tamanho da sala (x = num colunas ; y = num linhas)
	int **grafo;					//
	int *cores;						// Vetor com as cores dos alunos (0 = nao cola / 1 = cola)
	int **rep;
	Aluno *sala;					// Lista dos alunos
	Aluno *a1;
	
	menu_1(op);						// Funcao do menu principal

	// Configuracoes dos chupingole
	printf("Digite o numero de alunos: ");
	scanf("%i",&n);
	if(n<=0){
		printf("Precisa de ao menos 1 aluno \n");
		exit(0);	
	}
	printf("Digite o tamanho da sala [X][Y] (numero de linhas e numero de colunas): ");
	scanf("%i %i",&x, &y);
	system("clear || cls");
	
	if((x*y) < n){ 
		printf(" Existem mais alunos que cadeiras disponiveis chupinga \n");
		exit(0);
	}
	
	// Alocando os vetores/matrizes iniciais 

	grafo=(int**)malloc(n*sizeof(int*));
	for(i=0; i<n; i++){
		grafo[i]=(int*)malloc(n*sizeof(int));
}
	
	rep=(int**)malloc( x *sizeof(int*));
	for(i=0; i<y ; i++){
		rep[i]=(int*)malloc(y*sizeof(int));
}
	
	cores = (int*) malloc (n*sizeof(int));
	grafo = cria_matriz(grafo, x, y, n);
	a1 = (Aluno*) malloc (n*sizeof(Aluno));
	sala = (Aluno*) malloc (n*sizeof(Aluno));
	
//----------------------------------------------------------------------------------------------------------
	colore_grafo(grafo, cores, n);
	a1=cria_ficha(a1, n);
	for(i=0; i<n; i++){
		sala[i].num=-1;
	}
	for(i=0; i<n; i++){
		cria_sala(i, sala, a1, n, cores);
	}
	corrige_erros(sala, a1, n);
	mapeia_sala(sala, n, rep, x, y);

	                                // Resultados  printados
	op=2;							// Quando for printar o menu , a seta comeca na primeira funcao
	while(1){
		op_real=menu_2(op);
		if(op_real==2){
			imprime_sala(rep, x, y);
			getch();
			system("clear || cls");
		}
		else if(op_real==1){
			imprime_lista(a1, n);
			getch();
			system("clear || cls");
		}
		else if(op_real==0)
			exit(0);
	}
	return 0;
}
