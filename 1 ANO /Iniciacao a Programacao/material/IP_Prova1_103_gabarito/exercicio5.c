#include <stdio.h>

int main() {

  int votosC1 = 0, votosC2 = 0, votosC3 = 0, votosC4 = 0, votosN = 0, votosB = 0, votoAtual = 0;
  float percentualVotosN, percentualVotosB;

  do {
    printf("Digite o numero de seu candidato: ");
    scanf("%d", &votoAtual);

    switch(votoAtual) {
      case 1:
        votosC1++;
        break;
      case 2:
        votosC2++;
        break;
      case 3:
        votosC3++;
        break;
      case 4:
        votosC4++;
        break;
      case 5:
        votosN++;
        break;
      case 6:
        votosB++;
        break;
      case 0:
        printf("Calculando os votos...\n");
        break;
      default:
        printf("Opção inválida\n");
        break;
    }
  } while(votoAtual != 0);


  printf("Votos Candidato 1: %d \n", votosC1);
  printf("Votos Candidato 2: %d \n", votosC2);
  printf("Votos Candidato 3: %d \n", votosC3);
  printf("Votos Candidato 4: %d \n", votosC4);
  printf("Votos Nulo: %d \n", votosN);
  printf("Votos Branco: %d \n", votosB);

  percentualVotosN = (float)votosN/(float)(votosC1 + votosC2 + votosC3 + votosC4 + votosN + votosB) * 100.0;

  percentualVotosB = (float)votosB/(float)(votosC1 + votosC2 + votosC3 + votosC4 + votosN + votosB) * 100.0;

  printf("Percentual de votos nulos: %.2f \n", percentualVotosN);
  printf("Percentual de votos em branco: %.2f \n", percentualVotosB);

  return 0;
}
