#include<stdio.h>
int main(){

	int qt,vet[100],i=0,escalar;
	
	printf("Digite o total de numeros do vetor");

	scanf("%d",&qt);

	while (i<qt){
	
	scanf("%d",&vet[i]);
	i++;
	}

	printf("Digite o numero escalar");
	scanf("%d",&escalar);

	i=0;
	while(i<qt){
	printf("%i\n",escalar*vet[i]);
	i++;
	}



	
}

