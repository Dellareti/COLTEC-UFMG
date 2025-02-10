#include<stdio.h>
#include<stdlib.h>


int main(){

int vet[5];
int matriz[5][5];
int result[5];
int i,j,soma=0;
	printf("\n\n Digite seu vetor : \n\n");
	for(i=0;i<5;i++)
	scanf("%d",&vet[i]);

	printf("\n\n Digite sua matriz : \n\n");

   	 for(i=0;i < 5; i++){
		for(j=0;j < 5;j++){
			scanf("%d",&matriz[i][j]);
		}
    	}
   	 for(i=0;i < 5; i++){
		for(j=0;j < 5;j++){
			soma = soma + vet[j] * matriz[j][i];
		}
	result[i]= soma;
	soma=0;
    	}

   	 for(i=0;i < 5; i++)
		printf("\n\n %i\t \n\n",result[i]);
	putchar('\n');
	



return 0;
}
