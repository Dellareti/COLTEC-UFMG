#include <stdio.h>

void histograma(int notas[], int histograma[], int numNotas) {

  int i;

  for(i = 0; i < numNotas; i++) {
    if(notas[i] >= 90) {
      histograma[0]++;
    } else if(notas[i] >= 80) {
      histograma[1]++;
    } else if(notas[i] >= 70) {
      histograma[2]++;
    } else {
      histograma[3]++;
    }
  }
}

void imprimeHorizontal(char conceitos[], int numConceitos[]) {
  int i, j;

  for(i = 0; i < 4; i++) {
    printf("%c: ", conceitos[i]);

    for(j = 0; j < numConceitos[i]; j++)
      printf("*");

    printf("\n");
  }

}

void imprimeVertical(char conceitos[], int numConceitos[]) {
  int i, j, max = 0;


  // recupera a altura maxima do histograma
  for(i = 0; i < 4; i++) {
    if(max < numConceitos[i])
      max = numConceitos[i];
  }


  // imprime o histograma verticalmente
  for(i = max; i >= 1; i--) {
    for(j = 0; j < 4; j++) {
      if(numConceitos[j] >= i) {
        printf("*");
      }
      printf("\t");
    }
    printf("\n");
  }

  // imprime o nome dos conceitos
  printf("%c\t%c\t%c\t%c\n", conceitos[0], conceitos[1], conceitos[2], conceitos[3]);

}


int main() {
  srand(time(NULL));

  int notas[30], i, j;
  int numConceitos[] = {0,0,0,0};
  char conceitos[] = {'A', 'B', 'C', 'D'};

  printf("notas:\n");
  for(i = 0; i < 30; i++) {
    notas[i] = (rand() % 99) + 1;
    printf("%d\n", notas[i]);
  }

  histograma(notas, numConceitos, 30);
  imprimeHorizontal(conceitos, numConceitos);
  imprimeVertical(conceitos, numConceitos);

  return 0;
}
