//Considerando que a jogada encerra quando o jogador alcança 21
#include <stdio.h>
#include <math.h>

int main ()
{
	srand(time(NULL));
	int jogador=1, carta, pontuacao=0, num, maior = 0, venc = 0, estour=0;

	printf("Bem-vindo ao Blackjack!\n");
	printf("Para jogar, digite um numero (0 para terminar)\n\n");

	while(jogador<=3){

        printf("Jogada do jogador %d!\n\n", jogador);

        scanf("%d", &num);

		if(num!=0){
			carta=(rand()%10)+1;

			pontuacao=carta+pontuacao;

			printf("Carta = %d\n", carta);
			printf("Pontuacao = %d\n", pontuacao);

			if(pontuacao>maior && pontuacao<=21){
				maior=pontuacao;
				venc=jogador;

				printf("Deseja receber outra carta?(0 para nao)\n");
			}

			else if(pontuacao>21){
				printf("ESTOUROU!\n\n");
				jogador++;
				pontuacao=0;
				estour++;
			}
        }
		else if(num==0){
			jogador++;
			pontuacao=0;
		}
    }

    if(estour == 3){
        printf("Nao temos um ganhador!\n");
    }
	else if(estour<3){
        printf("O ganhador eh o jogador %d com a pontuacao de %d\n", venc, maior);
    }

    return 0;
}
