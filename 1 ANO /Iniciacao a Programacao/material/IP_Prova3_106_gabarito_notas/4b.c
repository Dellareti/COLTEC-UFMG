#include <stdio.h>
#include <stdlib.h>


void imprimeMatriz(int** matriz, int linhas, int colunas) {
  int i, j;

  for (i = 0; i < linhas; i++) {
    for (j = 0; j < colunas; j++) {
      printf("%d ", matriz[i][j]);
    }
    printf("\n");
  }
}



void liberaMatriz(int **matriz, int linhas) {
  int i;

  for (i = 0; i < linhas; i++) {
    free(matriz[i]);
  }
  free(matriz);
}



int** preencheMatriz(int linhas, int colunas) {

  int** matriz;
  int i, j;

  matriz = (int**) malloc(linhas * sizeof(int*));

  for (i = 0; i < colunas; i++) {
      matriz[i] = (int*) malloc(colunas * sizeof(int));
  }

  for (i = 0; i < linhas; i++) {
    for (j = 0; j < colunas; j++) {
      if (i == j || (i+j == colunas - 1)) {
        matriz[i][j] = 1;
      } else {
        matriz[i][j] = 0;
      }
    }
  }

  return matriz;
}




int main() {
  int **matriz;
  int linhas, colunas;


  printf("Digite o valor da linha da matriz (tambem servira para coluna):\n");
  scanf("%d", &linhas);

  colunas = linhas;

  matriz = preencheMatriz(linhas, colunas);
  imprimeMatriz(matriz, linhas, colunas);
  liberaMatriz(matriz, linhas);
}
