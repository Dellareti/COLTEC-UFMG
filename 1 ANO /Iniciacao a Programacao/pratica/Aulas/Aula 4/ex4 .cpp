 #include <stdio.h>
     #include <stdlib.h>
      
     int main()
     {
        int a, b, operador;
        float c;
        printf("Entre dois valores: \n");
        scanf("%d %d", &a,&b);
        printf("Entre com o Operador 1.+(soma) 2.-(subtracao) 3.*(multiplicacao) 4./ (divisao)");
        scanf("%d",&operador);
          switch (operador)
        {
        case 1:
           printf("O resultado da soma de %d + %d = %d",a,b, a+b);
            break;
        case 2:
            printf("O resultado da subtracao de %d - %d = %d",a,b, a-b);
            break;
        case 3:
            printf("O resultado da multiplicacao de %d * %d = %d",a,b, a*b);
            break;
        case 4:
            if (b == 0)
            printf("Não existe divisao por 0");
           else
            c = (float)a/(float)b;
            printf("O resultado da divisao de %d / %d = %f",a,b, c);
            break;
        default:
            printf("Operador invalido");
            break;
        }
    
    
		return 0;
	}
   

