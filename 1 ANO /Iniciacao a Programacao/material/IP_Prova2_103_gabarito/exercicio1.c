#include <stdio.h>

float calculaMediaConceito(int notas[], int numNotas, char *conceito) {

  int i;
  float totalNotas = 0;

  for(i = 0; i < numNotas; i++) {
    totalNotas += notas[i];
  }

  totalNotas = totalNotas / numNotas;

  if(totalNotas >= 90) {
    *conceito = 'A';
  } else if(totalNotas >= 80) {
    *conceito = 'B';
  } else if(totalNotas >= 70) {
    *conceito = 'C';
  } else {
    *conceito = 'D';
  }

  return totalNotas;
}

int main() {
  srand(time(NULL));

  int notas[30], i;
  char conceito;
  float mediaNotas;

  printf("notas:\n");
  for(i = 0; i < 30; i++) {
    notas[i] = (rand() % 99) + 1;
    printf("%d\n", notas[i]);
  }

  mediaNotas = calculaMediaConceito(notas, 30, &conceito);

  printf("Media: %f. Conceito: %c\n", mediaNotas, conceito);

  return 0;
}
