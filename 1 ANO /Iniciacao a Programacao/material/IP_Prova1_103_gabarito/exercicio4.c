#include <math.h>
#include <stdio.h>

int main() {
  srand(time(NULL));

  int i, player1 = 0, player2 = 0, cartaP1, cartaP2;


  for(i = 0; i < 3; i++) {

    cartaP1 = rand() % 12 + 1;
    cartaP2 = rand() % 12 + 1;

    printf("Jogador 1: %d \nJogador 2: %d \n\n", cartaP1, cartaP2);

    if(cartaP1 > cartaP2) {
      player1 ++;
    } else if(cartaP1 < cartaP2) {
      player2 ++;
    }
  }

  if(player1 > player2) {
    printf("Jogador 1 venceu!!\n");
  } else if(player2 > player1) {
    printf("Jogador 2 venceu!!\n");
  } else {
    printf("Jogo empatado!!\n");
  }

  return 0;
}
