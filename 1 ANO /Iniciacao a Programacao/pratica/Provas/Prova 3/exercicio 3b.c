#include <stdio.h>
#include <stdlib.h>

float calculaMediaRecursiva(float *vetor, int tamanho, int indiceAtual, float soma, int quantidade) {

  if (tamanho == indiceAtual - 1) {
    
	return ((quantidade != 0)? soma/quantidade : soma);
  }
  
   else {
  
     if (vetor[indiceAtual] > 0.0) {
      soma += vetor[indiceAtual];
      quantidade++;
    }
  
    indiceAtual++;
  
    return calculaMediaRecursiva(vetor, tamanho, indiceAtual, soma, quantidade);
  }
}

int main() {

  int numero, i;
  float media;
  float* vetor;

  printf("\n\n Digite a quantidade de elementos do vetor : \n\n" );
  scanf("%d",&numero);

  vetor = (float*)malloc(numero*sizeof(float));

  for (i = 0; i < numero; i++) {
    printf("\n\n vetor[%d] = ", i);
    scanf("%f", &vetor[i]);
  }

  media = calculaMediaRecursiva(vetor, numero-1, 0, 0, 0);

  printf("\n\n A media do valores positivos do vetor e : %f \n\n", media);


  free(vetor);
  return 0;
}
