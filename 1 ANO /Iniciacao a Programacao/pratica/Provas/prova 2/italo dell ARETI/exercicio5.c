#include<stdio.h>

int main(void){

int tam;
int i;
float total=0.0;
int metadetam=0;

		printf("\n\n Digite o tamanho do vetor \n\n");

	scanf("%i",&tam);

		printf("\n\n");

		float vet[tam];
	
	   for(i=0;i<tam;i++){
	
		printf("\n\n vetor posicao[%d]: \n\n",i+1);

	scanf("%f",&vet[i]);

	metadetam=vet[0]+vet[1]	

    }
		printf("\n\n A metade do vetor e : %d \n\n",metadetam);	
	
	return 0;

}

