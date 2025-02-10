#include <stdio.h>
#include <stdlib.h>

typedef struct{
	char nome[30];
	int idade;
	char sexo;
	int filme
	int a;
}Filme;

typedef struct{
	char nome[30];
	int idade;
	int sexo;
	int filme;
	int a;
	Filme filme[a];
}Filme;


	Filme* alocaFilme(int a) {
  Filme* filme = (Filme *)malloc( a * sizeof(Filme));
  return Filme;
}


void LeDados(Filme* filme, int a) {

  int i, k;

  for (i = 0; i < n; i++) {
      printf("\n\n Nome : \n\n");
      scanf("%s", &filme[i].nome);

      printf("\n\n digite sua idade: ");
      scanf("%d", &filme[i].);

     