#include<stdio.h>

int main(void){

int tam;
int i;
float total=0.0;
float media=0.0;

		printf("\n\n Digite o tamanho do vetor \n\n");

	scanf("%i",&tam);

		printf("\n\n");

		float vet[tam];
	
	   for(i=0;i<tam;i++){
	
		printf("\n\n vetor posicao[%d]: \n\n",i+1);

	scanf("%f",&vet[i]);

	media+=vet[i];	

    }
		printf("\n\n Media:%.2f \n\n",media/i);	
	
	return 0;

}


