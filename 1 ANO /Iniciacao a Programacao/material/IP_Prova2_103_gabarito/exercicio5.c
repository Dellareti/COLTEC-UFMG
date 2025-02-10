#include <stdio.h>

int main() {

  int tam, i, vetor[10000];

  printf("Digite o tamanho do vetor (max 10000):\n");
  scanf("%d", &tam);

  for(i = 0; i < tam; i++) {
    printf("vetor[%d]=", i);
    scanf("%d", &vetor[i]);
  }

  printf("Posições: ");
  for(i = 1; i < tam; i++) {
    if(vetor[i-1] == vetor[i] / 2) {
      printf("%d ", i);
    }
  }
  printf("\n");
}
