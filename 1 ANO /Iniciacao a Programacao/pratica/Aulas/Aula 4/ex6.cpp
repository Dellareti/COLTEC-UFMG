#include <stdio.h>
     #include <stdlib.h>
      
     int main()
     {
         int a;
         float b,c;
      
         printf("Entre com o sexo 1.Masculino ou 2.Feminino \n");
        scanf("%d", &a);
        printf("Entre com sua altura no formato [1.86] \n");
        scanf("%f", &b);
     
        switch (a)
        {
       case 1:
            c=(72.7 * b) - 58;
           printf("Seu peso ideal e: %.2f",c);
            break;
        case 2:
            c=(62.1*b)-44.7;
            printf("Seu peso ideal e: %.2f",c);
            break;
        default:
            printf("Sexo invalido");
        }
     
        return 0;
    }
     

