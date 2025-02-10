#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <stdio_ext.h>
#include <string.h>
#include <ctype.h>
#include "arquivo.h"


int qtd_linhas(FILE *nomes) {
	char caracter;
	int numLinhas=0;

	nomes=fopen("Textos/nomes.txt","r");

	while(!feof(nomes)) {
		caracter=fgetc(nomes);
		if (caracter=='\n') {
			numLinhas++;
		}
	}

	fclose(nomes);

	return numLinhas;

}

grafo *aloca_vetor(int tam_sala) {
    int i;
    grafo *sala;

    sala = (grafo*) malloc (tam_sala*sizeof(grafo));

    return sala;
}

void desalocar_vetor (grafo *sala){
	free(sala);
}

int **aloca_matriz(int tam_sala) {
    int i;
    int **adjacencia;
    adjacencia = (int**) malloc (tam_sala*sizeof(int*));
    for (i=0 ; i < tam_sala ; i++)
        adjacencia[i] = (int*) malloc (tam_sala*sizeof(int));
    return adjacencia;
}

void desalocar_matriz (int **sala, int tam_sala){
	for (int i = 0; i < tam_sala; ++i) {
        free(sala[i]);
    }

	free(sala);

}

void Inserir_Aresta(grafo *sala, int tam_sala, FILE *nomes) {
    char *aluno;
    int numLinhas;
 
    int contador=0;
 
    aluno=(char*)malloc(TAM_STR*sizeof(char));
 
    nomes=fopen("Textos/nomes.txt","r");
 
    for (int i = 0; i < tam_sala; ++i) {
        fgets(aluno, TAM_STR, nomes);

        int k;
        int tam=strlen(aluno)-1;

        for (k = 0; k != tam; ++k)
            sala[i].nome[k] = aluno[k];
        sala[i].nome[k]='\0';
    }
 
    fclose(nomes);
 
    free(aluno);
 
}
void Imprimir(grafo *sala, int tam_sala) {
	float tmp;
	int tam_sala_real;
	tmp=ceil(sqrt(tam_sala));
	tam_sala_real=(int)tmp;

	int k=0, contador=0;


	printf("\tNome:\t\t\tTipo de prova:\n");
	for (int i = 0; i < tam_sala; ++i) {
		if (strlen(sala[i].nome) < 10) {
			printf("\t%s\t\t\t\t%d\n", sala[i].nome, sala[i].cor);
		} else{
			printf("\t%s\t\t%d\n", sala[i].nome, sala[i].cor);
		}
	}

	printf("\n");

	for (int i = 0; i < tam_sala_real; ++i) {
		printf("\n\n");
		for (int j = 0; j < tam_sala_real; ++j) {
			if (contador > tam_sala) {
				break;
			} else {
				printf("%s ", sala[k].nome);
				contador++; k++;
			}
		}
	}

	printf("\n");
}

void Imprimir_matriz(int **matriz_adjacencia, int tam_sala) {
	for (int i = 0; i < tam_sala; ++i) {
		printf("\n");
		for (int j = 0; j < tam_sala; ++j) {
			printf("%d ", matriz_adjacencia[i][j]);
		}
	}

	printf("\n");
}

int **aleatoriamente(int tam_sala, int **matriz){
	srand (time(NULL));

	for (int i = 0; i < tam_sala; ++i) {
		for (int j = 0; j < tam_sala; ++j) {
			if(i==j){
				matriz[i][j]=1;
			}
			matriz[i][j]=rand()%2;
		}
	}

	return matriz;
}

void graphColour(int k, int m, grafo *alunos, int **sala, int tam_sala) {
	int c=1;
	for(m = 1; m <= tam_sala; ++m){
		for(c=1; c <= m; ++c){
			if(conferir(k, c, tam_sala, sala, alunos)==1){
				alunos[k].cor=c;
				if(k+1 < tam_sala)
					graphColour(k+1, m, alunos, sala, tam_sala);
			}
		}
	}
}

int conferir(int k, int c, int tam_sala, int **sala, grafo *alunos) {
    for(int i=0; i < tam_sala; i++) {
       if(sala[k][i]==1 && c == alunos[i].cor){
            return 0; //falso
       }
    }
        return 1; //verdadeiro
}

grafo *organizaTurma (grafo *alunos, int tam_sala) {

	int verificacao=1;
	grafo temp;
	do{
		for(int i=1; i < tam_sala; i++){
			if(alunos[i].cor < alunos[i-1].cor) {
				temp = alunos[i-1];
				alunos[i-1]=alunos[i];
				alunos[i]=temp;
			}
		}
		for(int i=1; i < tam_sala; i++){
			if(alunos[i].cor < alunos[i-1].cor) {
				verificacao=0;
			}
		}
	}while(verificacao=0);

	return alunos;
}

int **cria_ficha(grafo *a1, int tam_sala, int **matriz_adjacencia){
	int i, cola=0, ncola=0;
	char opc;

	for(int i = 0; i < tam_sala; ++i){
		for(int j = 0; j < tam_sala; j++){
			if(i==j){
				matriz_adjacencia[i][j]=1;
			}
			if(i>j){
				printf("X alunx %s cola com %s [S/N]", a1[i].nome, a1[j].nome);
				do{
					scanf("	%c",&opc);
					opc=toupper(opc);
					if(opc == 'S'){
						matriz_adjacencia[i][j]=1;
						matriz_adjacencia[j][i]=1;
					}
					else if(opc == 'N'){
						matriz_adjacencia[i][j]=0;
						matriz_adjacencia[j][i]=0;
					}
					else printf("Opcao invalida, digite (S) para sim e (N) nao \n");
				} while(opc != 'N' && opc != 'S');
			}
		}
	}
	return matriz_adjacencia;
}

grafo *manual(grafo *a1,int tam_sala){
	char *aluno;

	aluno=(char*)malloc(TAM_STR*sizeof(char));

	for(int i=0; i < tam_sala; i++){
		printf("Digite o nome do aluno %i: ",i+1);
		fgets(aluno, TAM_STR, stdin);

		int k;
        int tam=strlen(aluno)-1;

        for (k = 0; k != tam; ++k)
        	a1[i].nome[k] = aluno[k];
        a1[i].nome[k]='\0';
	}

	return a1;
}
