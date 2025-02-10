#include<stdio.h>

int main(void){

int tam;
int i;
float total=0.0;
float soma=0.0;

		printf("\n\n Digite o tamanho do vetor \n\n");

	scanf("%i",&tam);

		printf("\n\n");

		float vet[tam];
	
	   for(i=0;i<tam;i++){
	
		printf("\n\n Digite os valores do salario (vetor posicao[%d]): \n\n");

	scanf("%f",&vet[i]);
}
	for(i=0;i < 26;i++){	

	soma+=vet[i];

	
    }	
	
        if((soma > 0) && (soma< 15000,0)){

        printf("\n\n MICRO EMPRESA \n\n");
}


	else if((soma >15000,0)  && (( soma < 21250,0))


	printf("\n\n EMPRESA PEQUENA \n\n");




	else if( soma >21250)

	printf("EMPRESA GRANDE");


	return 0;

}


