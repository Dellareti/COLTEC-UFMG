#include <stdio.h>

void geraNovoVetor(int origem[], int destino[], int tam){

  int i, j = 0;
  for(i = 0; i < tam-1; i=i+2) {
    destino[j]  = origem[i] + origem[i+1];
    j++;
  }


}

int main() {

  int tam, i, vetor[100], vetor2[50];

  printf("Digite o tamanho do vetor (par, por favor):\n");
  do{
    scanf("%d", &tam);
  }while ((tam > 100 || tam <= 0) || (tam % 2) );

  //leitura do vetor
  for(i = 0; i < tam; i++) {
    printf("vetor[%d]=", i);
    scanf("%d", &vetor[i]);
  }

  geraNovoVetor(vetor, vetor2, tam);

  printf("O novo vetor:\n");

  for(i = 0; i < tam/2; i++)
    printf("%d\t", vetor2[i]);

}
