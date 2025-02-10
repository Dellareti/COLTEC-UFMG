#include<stdio.h>
#include<stdlib.h>
#include<strings.h>
#include"fila.h"

int main(){
    FilaL *f;
    fila_cria_l();
    int opcao = 0;
    char placa;

    printf("------------------------------------------------------- Garagem -------------------------------------------------------");
    printf("\n\n 1:Para inserir um carro.\n");
    printf(" 2:Para ver a fila.\n");
    printf("3:remover um carro da fila.\n");
    printf("4:sair/n/n");
    scanf("%d",&opcao);


    switch(opcao){
        case 1:

            printf("\n\n Por favor digite a placa :");
            scanf("%s",&placa);
            fpurge(stdin);

            fila_insere_l(f);

            break;

        case 2:

            fila_imprime_l(f);
            break;

        case 3:

            printf("\n\n Digite a placa do carro  que deseja retirar:");
            fgets(placa,20,stdin);
            fpurge(stdin);

            fila_retira_l(f);

            break;

        case 4:

            return 0;

        break;

        default:
            printf("\n\n Digite uma opcao correta !!!");
            return main;

    }
return 0;
}
