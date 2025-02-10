#include <stdio.h>
#include <stdlib.h>
#include <math.h>
 
 
 
    int soma(){
    int a, b;
	
	printf("\n\nEntre dois valores \n\n");
	scanf("%d %d", &a,&b);
	printf("\n\nO resultado da soma de %d + %d = %d \n\n",a,b, a+b);            
return 0;
}
 
    int produto()
{
    int a, b;

	printf("\n\n Entre dois valores \n\n");
	scanf("%d %d", &a,&b);
	printf("\n\nO resultado da multiplicacao de %d * %d = %d \n\n",a,b, a*b);            
return 0;
}
 
    int quociente()
{   
	float a,b;
	
	printf("\n\nEntre dois valores \n\n");
	scanf("%f %f", &a,&b);
	printf("\n\n O resultado da multiplicacao de %.2f / %.2f = %.2f \n\n",a,b, a/b);            
return 0;
}
 
 
    int main(){
    int a, b, operador;
float c;
 
printf("Entre com o Operador \n\n 1.+(soma)\n\n 2.*(Produto)\n\n 3./(Quociente)\n\n 4. (Sair)");
scanf("%d",&operador);
switch (operador)
{
	case 1:soma();
break;

	case 2:produto();
break;

case 3:
if (b == 0)
	printf("Não existe divisão por 0");


	else quociente();
break;

case 4:       
	printf("Até mais");
break;

default:
	printf("Operador invalido");
break;
}
return 0;
}
