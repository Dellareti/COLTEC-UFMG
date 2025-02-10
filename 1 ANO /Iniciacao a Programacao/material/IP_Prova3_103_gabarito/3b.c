#include <stdio.h>
#include <stdlib.h>

float calculaMediaRecursiva(float *vetor, int tamanho, int indiceAtual, float soma, int quantidade) {

  if (tamanho == indiceAtual - 1) {
    return ((quantidade != 0)? soma/quantidade : soma);
  } else {
    if (vetor[indiceAtual] > 0.0) {
      soma += vetor[indiceAtual];
      quantidade++;
    }
    indiceAtual++;
    return calculaMediaRecursiva(vetor, tamanho, indiceAtual, soma, quantidade);
  }
}

int main() {

  int n, i;
  float media;
  float* vetor;

  printf("Digite a quantidade de elementos do vetor:");
  scanf("%d",&n);

  vetor = (float *)malloc(n * sizeof(float));

  for (i = 0; i < n; i++) {
    printf("\nvetor[%d]=", i);
    scanf("%f", &vetor[i]);
  }

  media = calculaMediaRecursiva(vetor, n-1, 0, 0, 0);

  printf("\nA média é: %f\n", media);


  free(vetor);
  return 0;
}
