#include <stdio.h>
#include <stdio_ext.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define TAM_STR 50

enum boolean {
    cola = 1, naoCola = 0
};typedef enum boolean bool;

struct sala_aula{
	int cor;
	char nome[TAM_STR];
}; typedef struct sala_aula grafo;

void desalocar (grafo **sala, int tam_sala);
grafo **aloca(int tam_sala);
void Inserir_Aresta(grafo **sala, int tam_sala, FILE *nomes, int tam_sala_real);
void Imprimir(grafo **sala, int tam_sala);
int qtd_linhas(FILE *nomes);
grafo **aleatorio(grafo **sala, int tam_sala);
grafo **alunos_colam(grafo **sala, int tam_sala, int tam_sala_real);
grafo **mudando_alunos(grafo **sala, int tam_sala, int alunos_cheaters, int tam_sala_real);

int main () {
	system("clear");

	grafo **sala;
	int tam_sala;
	FILE *nomes;
	float tmp;
	int tam_sala_real;


	printf("Quantos alunos existem na sala: ");
	scanf("%d", &tam_sala_real);

	tmp=ceil(sqrt(tam_sala_real));

	tam_sala=(int)tmp;

	sala=aloca(tam_sala);


	Inserir_Aresta(sala, tam_sala, nomes, tam_sala_real);
	//Imprimir(sala, tam_sala);

	sala=aleatorio(sala, tam_sala);
	sala=alunos_colam(sala, tam_sala, tam_sala_real);

	Imprimir(sala, tam_sala);

	desalocar(sala, tam_sala);

	return 0;
}

grafo **aloca(int tam_sala) {
    int i;
    grafo **sala;
    sala = (grafo**) malloc (tam_sala*sizeof(grafo*));
    for (i=0 ; i < tam_sala ; i++)
        sala[i] = (grafo*) malloc (tam_sala*sizeof(grafo));
    return sala;
}

void desalocar (grafo **sala, int tam_sala){
	for (int i = 0; i < tam_sala; ++i) {
        free(sala[i]);
    }

	free(sala);
}

void Inserir_Aresta(grafo **sala, int tam_sala, FILE *nomes, int tam_sala_real) {
	char *aluno;
	int numLinhas;

	int contador=0;

	aluno=(char*)malloc(TAM_STR*sizeof(char));

	numLinhas=qtd_linhas(nomes);

	nomes=fopen("nomes.txt","r");

	for (int i = 0; i < tam_sala; ++i) {
		for (int j = 0; j < tam_sala; ++j) {
			fgets(aluno, TAM_STR, nomes);

			if (contador >= tam_sala_real){
				strcpy(sala[i][j].nome, "vazio");
			} else {
				for (int k = 0; aluno[k]!='\n'; ++k) {
					sala[i][j].nome[k] = aluno[k];
				}
				contador++;
			}
		}
	}

	fclose(nomes);

	free(aluno);

	return;

}

void Imprimir(grafo **sala, int tam_sala) {
	for (int i = 0; i < tam_sala; ++i) {
		printf("\n");
		for (int j = 0; j < tam_sala; ++j) {
			puts(sala[i][j].nome);
			//printf("%s\n", sala[i][j].nome);
		}
	}

	printf("\n");
}

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

grafo **aleatorio(grafo **sala, int tam_sala){
	srand (time(NULL));

	for (int i = 0; i < tam_sala; ++i) {
		for (int j = 0; j < tam_sala; ++j) {
			sala[i][j].cor=rand()%2;
			if (strcmp(sala[i][j].nome, "vazio")==0) {
				sala[i][j].cor=naoCola;
			}
		}
	}

	for (int i = 0; i < tam_sala; ++i) {
		printf("\n");
		for (int j = 0; j < tam_sala; ++j) {
			printf("%d ", sala[i][j].cor);
		}
	}
	return (sala);
}

grafo **alunos_colam(grafo **sala, int tam_sala, int tam_sala_real) {
	int contador=0;
	int alunos_cheaters=0;

	for (int i = 1; i < tam_sala+1; ++i) {
		if(i%2!=0){
			contador+=i;
		}
	}

	for (int i = 0; i < tam_sala; ++i) {
		for (int j = 0; j < tam_sala; ++j) {
			if (sala[i][j].cor==cola) {
				alunos_cheaters++;
			}
		}
	}

	if (alunos_cheaters<=contador) {
		sala=mudando_alunos(sala, tam_sala, alunos_cheaters, tam_sala_real);
		return (sala);
	} else { printf("Não tem jeito de ter uma sala sem ninguém colar\n"); exit(1);}
}

grafo **mudando_alunos(grafo **sala, int tam_sala, int alunos_cheaters, int tam_sala_real) {
	grafo **comparar; //passar para este grafo
	//grafo **sala_resultante;
	int *x_cheaters, *y_cheaters;
	int l=0, m=0;
	int *x_Naocheaters, *y_Naocheaters;

	int alunosNao_cheaters=pow(tam_sala,2)-alunos_cheaters;
	//int k=alunos_cheaters, b=alunosNao_cheaters;
	int contador=0;

	comparar=aloca(tam_sala);

	x_cheaters=(int*) malloc (alunos_cheaters*sizeof(int));
	y_cheaters=(int*) malloc (alunos_cheaters*sizeof(int));

	x_Naocheaters=(int*) malloc (alunosNao_cheaters*sizeof(int));
	y_Naocheaters=(int*) malloc (alunosNao_cheaters*sizeof(int));

	//printf("%d\n", alunosNao_cheaters);

	for (int i = 0; i < tam_sala; ++i){
		for (int j = 0; j < tam_sala; ++j){
			if (sala[i][j].cor==cola) {
				//printf("%s\n", sala[i][j].nome);
				x_cheaters[l]=i;
				y_cheaters[l]=j;

				//printf("%d %d\n", x_cheaters[l], y_cheaters[l]);

				l++;

				//alunos_cheaters--;
			} else if(sala[i][j].cor==naoCola){
					//printf("%s\n", sala[i][j].nome);
					x_Naocheaters[m]=i;
					y_Naocheaters[m]=j;

					//printf("%d %d\n", x_cheaters[l], y_cheaters[l]);

					m++;

					//alunosNao_cheaters--;

					//printf("%d\n", alunosNao_cheaters);
			}
		}
	}

	printf("\n");

	//alunos_cheaters=k;
	//alunosNao_cheaters=b;

	/*for (int i = 0; i < alunosNao_cheaters; ++i) {
		//printf("4\n");
		printf("%d %d\n", x_Naocheaters[i], y_Naocheaters[i]);
	}*/

	m=0;
	l=0;

	for (int i = 0; i < tam_sala; ++i) {
		for (int j = 0; j < tam_sala; ++j) {
			if (contador >= tam_sala_real){
				strcpy(comparar[i][j].nome, "vazio");
				//printf("%d\n", 6);
			} if((i+1)%2!=0 && (j+1)%2!=0 && alunos_cheaters > 0){
				//printf("%s\n", sala[g[l]][h[m]].nome);
				strcpy(comparar[i][j].nome, sala[x_cheaters[l]][y_cheaters[l]].nome); //aqui ocorre a troca da matriz toda para o grafo comparar.
				//printf("%s|\n", comparar[i][j].nome);
				alunos_cheaters--;

				l++;

			} else if (alunosNao_cheaters > 0){
					//printf("%s\n", sala[n[p]][o[q]].nome);
					strcpy(comparar[i][j].nome, sala[x_Naocheaters[m]][y_Naocheaters[m]].nome); //aqui ocorre a troca da matriz toda para o grafo comparar.
					//printf("%s|\n", comparar[i][j].nome);
					alunosNao_cheaters--;

					m++;

			}
			contador++;
			//printf("%d\n", contador);
		}
	}


	free(x_cheaters);
	free(y_cheaters);
	free(x_Naocheaters);
	free(y_Naocheaters);

	desalocar(sala, tam_sala);

	return (comparar);
}
