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
      printf("\nm[%d][%d] = ", i, j);
      scanf("%d", &matriz[i][j]);
    }
  }

  return matriz;
}



int verificaMatriz(int **matriz, int linhas, int colunas) {

  int verdadeiro = 1;
  int x, y;

  for (x = 0; x < linhas; x++) {
    for (y = 0; y < colunas; y++) {
      if (matriz[x][y] != matriz[y][x] || matriz[x][y] <= 0) {
        verdadeiro = 0;
      }
    }
  }

  return verdadeiro;
}



int main() {
  int **matriz;
  int linhas, colunas;


  printf("Digite o valor da linha da matriz (também servirá para coluna):\n");
  scanf("%d", &linhas);

  colunas = linhas;

  matriz = preencheMatriz(linhas, colunas);
  printf("Matriz digitada:\n");
  imprimeMatriz(matriz, linhas, colunas);

  if (verificaMatriz(matriz, linhas, colunas)) {
    printf("É simétrica positiva definida\n");
  } else {
    printf("NÃO É simétrica positiva definida\n");
  }


  liberaMatriz(matriz, linhas);
}
