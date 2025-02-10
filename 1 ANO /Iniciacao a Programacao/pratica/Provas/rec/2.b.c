#include<stdio.h>
#include<conio.h>
#include<math.h>

int main()  {

	float a,b,c,delta,x1,x2;
	
	printf("\n\n DIGITE O VALOR DE A:\n\n");
	scanf("%f",&a);
	
	printf("\n\n DIGITE O VALOR DE B:\n\n");
	scanf("%f",&b);
	
	printf("\n\n DIGITE O VALOR DE C:\n\n");
	scanf("%f",&c);
	
	if(a!=0) {
		delta = (b*b) -4* a * c;
		
		if(delta ==0) {
	 x1=(-b +sqrt(delta))/(2 * a);
	printf("\n\n Delta e igual a 0 \n\n");
	printf("\n\n x1 e x2 =%.2f\n\n",x1);
}


		else {
		if (delta > 0)	{
		
		x1 = (-b +sqrt(delta))/(2 * a);
		x2 = (-b +sqrt(delta))/(2 * a);
		printf("\n\n Delta e maior que 0\n\n");
		printf("\n\n x1 = %.2f \n\n",x1);
		printf("\n\n x2 = %.2f \n\n",x2);
}
		else{
			printf("\n\n Delta menor que 0\n\n");
			printf("\n\n Nao existe raiz real \n\n");
		}
		
	}
		
		}else{
			printf("\n\n Nao e uma equacao do segundo grau\n\n");
			printf("\n\n a tem que ser diferente de 0\n\n");
		}

		getch();
}
