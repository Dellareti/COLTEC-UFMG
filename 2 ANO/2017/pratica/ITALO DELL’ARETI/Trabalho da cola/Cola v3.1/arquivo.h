#ifndef ARQUIVO_H
#define ARQUIVO_H
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdio_ext.h>
#include <string.h>

#define TAM_STR 50
#define MAX_LEN 128

struct sala_aula{
	int cor;
	char nome[TAM_STR];
}; typedef struct sala_aula grafo;

int qtd_linhas(FILE *nomes);
grafo *aloca_vetor(int tam_sala);
void desalocar_vetor (grafo *alunos);
int **aloca_matriz(int tam_sala);
void desalocar_matriz (int **sala, int tam_sala);
void Inserir_Aresta(grafo *sala, int tam_sala, FILE *nomes);
void Imprimir(grafo *alunos, int tam_sala);
int **aleatoriamente(int tam_sala, int **matriz);
void graphColour(int k, int m, grafo *alunos, int **sala, int tam_sala);
int conferir(int k, int c, int tam_sala, int **sala, grafo *alunos);
grafo *organizaTurma (grafo *alunos, int tam_sala);
int **cria_ficha(grafo *a1, int tam_sala, int **matriz_adjacencia);
grafo *manual(grafo *a1,int tam_sala);
void print_image(FILE *fptr);

#endif
