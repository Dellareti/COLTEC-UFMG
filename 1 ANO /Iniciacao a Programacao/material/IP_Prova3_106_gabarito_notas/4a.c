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
    for (y = x; y < colunas; y++) {
      if (x == y) continue;
      if (matriz[x][y] != (-1)*matriz[y][x]) {
        verdadeiro = 0;
      }
    }
  }

  return verdadeiro;
}



int main() {
  int **matriz;
  int linhas, colunas;


  printf("Digite o valor da linha da matriz (tambem servira para coluna):\n");
  scanf("%d", &linhas);

  colunas = linhas;

  matriz = preencheMatriz(linhas, colunas);
  printf("Matriz digitada:\n");
  imprimeMatriz(matriz, linhas, colunas);

  if (verificaMatriz(matriz, linhas, colunas)) {
    printf("Eh anti-simetrica\n");
  } else {
    printf("NAO EH anti-simetrica\n");
  }


  liberaMatriz(matriz, linhas);
}
