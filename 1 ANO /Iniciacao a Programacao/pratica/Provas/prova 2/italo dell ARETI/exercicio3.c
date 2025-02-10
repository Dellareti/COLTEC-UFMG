#include <stdio.h>

int main(void) { 

int numerador,denominador , a, b, temp, mdc; 


	printf("\n\n Digite os dois  numeros:(primeiro numerador e o segundo denominador) \n\n"); 

	scanf("%d %d", &numerador, &denominador); 


	a = numerador;	 

	b = denominador; 

	
	while (b != 0) { 

	temp = a; 

	a = b; 

	b = temp%b; 

	} 

	mdc = a; 

 if(numerador ==0){

        printf("\n\n ate mais \n\n");
}

       else if(denominador ==0){

        printf("\n\n ate mais \n\n");	 


}

	printf("\n\n A simplificacao entre %d  e  %d    e : %d \n\n", numerador,denominador , mdc); 

	
	
 

	return 0; 

}
