#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdio_ext.h>
#include <string.h>
#include <ctype.h>
#include "arquivo.h"


int qtd_linhas(FILE *nomes) {
	char caracter;
	int numLinhas=0;

	nomes=fopen("nomes.txt","r");

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

	nomes=fopen("nomes.txt","r");

	for (int i = 0; i < tam_sala; ++i) {
		fgets(aluno, TAM_STR, nomes);
		for (int k = 0; aluno[k]!='\n'; ++k)
			sala[i].nome[k] = aluno[k];
	}

	fclose(nomes);

	free(aluno);

}

void Imprimir(grafo *sala, int tam_sala) {
	for (int i = 0; i < tam_sala; ++i) {
		printf("%s ", sala[i].nome);
		printf("%d\n", sala[i].cor);
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

	for(int m = 1; m < tam_sala; ++m){
		for(int c=1; c <= m; ++c){
			if(conferir(k, c, tam_sala, sala, alunos)){
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
						a1[i].cor=1;
						cola++;
					}
					else if(opc == 'N'){
						a1[i].cor=0;
						ncola++;
					}
					else printf("Opcao invalida, digite (S) para sim e (N) nao \n");
				} while(opc != 'N' && opc != 'S');
			}
		}
	}
	return matriz_adjacencia;
}

grafo *manual(grafo *a1,int tam_sala){

	for(int i=0; i < tam_sala; i++){
		printf("Digite o nome do aluno %i: ",i+1);
		fgets(a1[i].nome, TAM_STR, stdin);
	}
	return a1;
}

