#include <stdio.h>
#include <stdlib.h>
      
     int main()
    {
        int a;
        printf(" Digite um valor de 1 a 7 \n");
        scanf("%d", &a);
        switch (a)
        {
        case 1:
            printf("\n\n\n O dia 1 e Domingo \n\n\n");
            break;
        case 2:
            printf("\n\n\n O dia 2 e Segunda \n\n\n");
            break;
       case 3:
            printf("\n\n\n O dia 3 e Terca \n\n\n");
            break;
        case 4:
            printf("\n\n\n O dia 4 e Quarta \n\n\n");
            break;
        case 5:
            printf("\n\n\n O dia 5 e Quinta \n\n\n");
            break;
        case 6:
            printf("\n\n\n O dia 6 e Sexta \n\n\n");
            break;
        case 7:
            printf("\n\n\n O dia 7 e Sabado \n\n\n");
            break;
        default:
           printf("\n\n\n Dia da semana inválido \n\n\n");
       }
     
       return 0;
    }
    

