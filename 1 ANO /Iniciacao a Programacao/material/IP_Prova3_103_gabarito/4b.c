#include <stdio.h>
#include <stdlib.h>


void imprimeMatriz(char** matriz, int linhas, int colunas) {
  int i, j;

  for (i = 0; i < linhas; i++) {
    for (j = 0; j < colunas; j++) {
      printf("%c ", matriz[i][j]);
    }
    printf("\n");
  }
}



void liberaMatriz(char **matriz, int linhas) {
  int i;

  for (i = 0; i < linhas; i++) {
    free(matriz[i]);
  }
  free(matriz);
}



char** preencheMatriz(int linhas, int colunas) {

  char** matriz;
  int i, j;

  matriz = (char**) malloc(linhas * sizeof(char*));

  for (i = 0; i < colunas; i++) {
      matriz[i] = (char*) malloc(colunas * sizeof(char));
  }

  for (i = 0; i < linhas; i++) {
    for (j = 0; j < colunas; j++) {
      if (i == j) {
        matriz[i][j] = 'B';
      } else if (i < j) {
        matriz[i][j] = 'A';
      } else {
        matriz[i][j] = 'C';
      }
    }
  }

  return matriz;
}




int main() {
  char **matriz;
  int linhas, colunas;


  printf("Digite o valor da linha da matriz (também servirá para coluna):\n");
  scanf("%d", &linhas);

  colunas = linhas;

  matriz = preencheMatriz(linhas, colunas);
  imprimeMatriz(matriz, linhas, colunas);
  liberaMatriz(matriz, linhas);
}
