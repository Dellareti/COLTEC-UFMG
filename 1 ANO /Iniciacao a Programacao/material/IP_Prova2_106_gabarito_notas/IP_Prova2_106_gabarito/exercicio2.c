#include <stdio.h>

void histograma(int salarios[], int histograma[], int numEmpregados) {

  int i;

  for(i = 0; i < numEmpregados; i++) {
    if(salarios[i] >= 901 && salarios[i] <= 1000) {
      histograma[0]++;
    } else if(salarios[i] >= 801 && salarios[i] <= 900 ) {
      histograma[1]++;
    } else if(salarios[i] >= 701 && salarios[i] <= 800) {
      histograma[2]++;
    } else if (salarios[i] >= 600 && salarios[i] <= 700) {
      histograma[3]++;
    }
  }
}

void imprimeHorizontal(int faixa[], int numFaixas[]) {
  int i, j;

  for(i = 0; i < 4; i++) {
    printf("%d: ", faixa[i]);

    for(j = 0; j < numFaixas[i]; j++)
      printf("*");

    printf("\n");
  }

}

void imprimeVertical(int faixas[], int numFaixas[]) {
  int i, j, max = 0;


  // recupera a altura maxima do histograma
  for(i = 0; i < 4; i++) {
    if(max < numFaixas[i])
      max = numFaixas[i];
  }


  // imprime o histograma verticalmente
  for(i = max; i >= 1; i--) {
    for(j = 0; j < 4; j++) {
      if(numFaixas[j] >= i) {
        printf("*");
      }
      printf("\t");
    }
    printf("\n");
  }

  // imprime o nome das faixas
  printf("%d\t%d\t%d\t%d\n", faixas[0], faixas[1], faixas[2], faixas[3]);

}


int main() {
  srand(time(NULL));

  int salarios[25], i, j;
  int numFaixas[] = {0,0,0,0};
  int faixas[] = {1, 2, 3, 4};

  printf("Salarios:\n");
  for(i = 0; i < 25; i++) {
    salarios[i] = (1000 - (rand()%401));
    printf("%d\n", salarios[i]);
  }
//calcula hitograma
  histograma(salarios, numFaixas, 25);

  printf("\nHistograma de salarios\n");
  imprimeHorizontal(faixas, numFaixas);

  printf("\nHistograma de salarios\n");
  imprimeVertical(faixas, numFaixas);

  return 0;
}
