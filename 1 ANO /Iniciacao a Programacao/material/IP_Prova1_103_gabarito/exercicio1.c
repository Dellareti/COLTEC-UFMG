#include <stdio.h>

int main() {

  int opcao = 0;

  do {
    printf("Tipo do produto:");
    printf("\n1. Eletrônico.");
    printf("\n2. Roupa.");
    printf("\n3. Perfume.");
    printf("\n4. Livros.");
    printf("\nEntre com sua opção: ");

    scanf("%d", &opcao);

    switch(opcao) {
      case 1:
        printf("25%% de imposto\n");
        break;
      case 2:
      case 3:
        printf("15%% de imposto\n");
        break;
      case 4:
        printf("Isento de imposto\n");
        break;
      case 0:
        printf("Saindo do programa\n");
        break;
      default:
        printf("Opção inválida\n");
        break;
    }
  } while(opcao != 0);

  return 0;
}
