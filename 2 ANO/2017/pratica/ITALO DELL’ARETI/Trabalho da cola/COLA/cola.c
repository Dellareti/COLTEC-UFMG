#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <termios.h>
#include <unistd.h>
#include "cola.h"

int **cria_matriz(int **G, int x, int y, int n){		// Funcao para criar o grafo da sala
	int i, j;										    // i==x E j==y 
	int tamSala=y;
	for(i=0; i<n; i++){								// Inicializando matriz de adjacencia
		for(j=0; j<n; j++){							// Iniciando todos os espacos com 0
			G[i][j]=0;
		}
	}
	
	for(i=0;i<n;i++){                               //Montando Matriz de Adjacencia
		for(j=0;j<n;j++){
			if(j == i+1 && j != y){
				G[i][j]=1;
				G[j][i]=1;
			}
			if(j == tamSala && tamSala < n){
				G[i][j]=1;
				G[j][i]=1;
			}
		}
		tamSala++;
	}
	return G;
}

void next_color(int **G, int x[], int k){	    // Funcao aux para colorir o grafo
   	int i;
   	x[k]=1;  									// Colore o vertice com 1

   	for(i=0; i<k; i++){ 						// Checa todos k-1 vertices
    	if(G[i][k]!=0 && x[k]==x[i]){ 			// Se estiverem conectados e tiverem a mesma cor
       		x[k]=x[i]+1;  						// Adiciona +1 para o vertice comparado
		}
	}
}

Aluno *cria_ficha(Aluno *a1,int n){
	int i, cola=0, ncola=0, pcola=0, npcola=0;
	char opc;
	for(i=0;i<n;i++){
				printf("Digite o nome do aluno %i: ",i+1);
				scanf("%s",a1[i].nome);
				a1[i].num=i;
				printf("Esse aluno cola? (S/N) ");
				do{
					scanf("	%c",&opc);
					opc=toupper(opc);
					if(opc == 'S'){
						a1[i].cola=1;
						cola++;
					}
					else if(opc == 'N'){
						a1[i].cola=2;
						ncola++;
					}
					else printf("Opcao invalida, digite (S) para sim e (N) nao \n");
				}while(opc != 'N' && opc != 'S');
				
		}	
	if(cola>ncola && n > 1){ 
		
		// ---------------------------------- Modificar ------------------------------------------------------- 
		printf("Existem mais alunos que colam do que nao colam, sendo impossivel uma configura%co para os separar\n",135);
		exit(0);
	}
	return a1;
}

void cria_sala(int k,Aluno *sla,Aluno *a1,int n, int x[]){
	int i;
	int cont=0;
	
	for(i=0;i<n;i++){                                           //checa todos k-1 vertices
     	if(x[k] == a1[i].cola && k != n && cont == 0){         //se a coloracao tiver o mesmo numero da pripiedade cola, pode dar o lugar ao aluno
   			 sla[k].num=a1[i].num; 
   			 sla[k].cola=a1[i].cola;
   			 strcpy(sla[k].nome,a1[i].nome);
   			 a1[i].cola=0;
	  		 cont++;
	     }
	}
}
// Migué , modificar
void corrige_erros(Aluno *sla,Aluno *a1,int n){
	int i,j;
	
	for(i=0;i<n;i++){                                          //checa todos k-1 vertices
     	for(j=0;j<n;j++){                                      //Corrigido o caso de haver mais alunos que nao colam do que colam
			 if(sla[i].num==-1 && a1[j].cola==2){             // se tiver um lugar vazio e o aluno nao colar
				 sla[i].num=a1[j].num;
				 strcpy(sla[i].nome,a1[j].nome);
				 a1[j].cola=0;
			 }
		 }
	}
}

void mapeia_sala(Aluno *a1,int n, int **rep, int x,int y){    //Constroi a matriz usada para a sala
	int i,j,k=0;
	for(i=0;i<x;i++){ 
		for(j=0;j<y;j++)
			rep[i][j]=-1;
}
	for(i=0;i<x;i++){
		for(j=0;j<y;j++){
			if(k<n){
				rep[i][j]=a1[k].num;
				k++;
			}
		}
	}
}

void colore_grafo(int **grafo, int *cores, int n){
	int i;
	for(i=0;i<n;i++){                               //Colore cada vertice por vez , bactracking
		next_color(grafo,cores,i);
	}
}

void imprime_lista(Aluno *a1, int n){
	int i;
	printf( "\n\n"
			"\t\t\t Lista de Alunos:\n"
			"\t\t\t ^^^^^^^^^^^^^^^\n\n"
			"\tNum\t\t\t\t\t\tNome\n");
	for(i=0;i<n;i++){
		printf("\t%i\t\t\t\t\t\t%s\n", a1[i].num+1, a1[i].nome);
	}
}

void imprime_sala(int **rep, int x, int y){
	int i,j;
	printf("\n Mapeamento  da sala de acordo com o numero do aluno \n\t(0 É um lugar vazio)\n\n");
	for(i=0; i<x; i++){
		for(j=0; j<y; j++){
			printf("%i	",rep[i][j]+1);
		}
		printf("\n");
	}
}
// ------------------- Internet god , modificar ------------------- 

char getch(){
	char buf=0;
	struct termios old={0};
    __fpurge(stdout);
    if(tcgetattr(0, &old)<0)
        perror("tcsetattr()");
    old.c_lflag&=~ICANON;
    old.c_lflag&=~ECHO;
    old.c_cc[VMIN]=1;
    old.c_cc[VTIME]=0;
    if(tcsetattr(0, TCSANOW, &old)<0)
        perror("tcsetattr ICANON");
    if(read(0,&buf,1)<0)
        perror("read()");
    old.c_lflag|=ICANON;
    old.c_lflag|=ECHO;
    if(tcsetattr(0, TCSADRAIN, &old)<0)
        perror ("tcsetattr ~ICANON");
    printf("%c\n",buf);
    return buf;
}
