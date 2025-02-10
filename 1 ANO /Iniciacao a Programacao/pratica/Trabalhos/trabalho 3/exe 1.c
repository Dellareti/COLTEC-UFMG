#include<stdio.h>
#include<stdlib.h>

 void leMatriz (int matriz[5][5] ){
	int i,j;
	for(i=0;i<5;i++){
		for(j=0;j<5;j++){
		scanf("%d",&matriz[i][j]);	
		}
	}
}

 int somaElemento (int matriz[5][5]){
	int i,j;
	int soma=0;
	
	for(i=0;i<5;i++){
		for(j=0;j<5;j++){
			soma=soma+matriz[i][j];
		}
	}
	   return soma;	
}


int main(void){
	
	int matriz[5][5];
	int soma;
	
	printf("\n\n Digite os valores de sua matriz 5x5 : \n\n");
	leMatriz(matriz);
	 
	somaElemento(matriz);
	soma=somaElemento(matriz);
	
	printf("\n\n A soma dos elementos dessa matriz e :%d \n\n",soma);
	
	
	return 0;
}