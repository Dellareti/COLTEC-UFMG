#include<stdio.h>

int main(){

	int numero[3][3];
	int inverso[3][3];
	int in
	printf("digite seu numero :");
	leMatriz(numero)
	in =inverteMatriz(numero);
	
	return 0;
}

	void leMatriz(int m[3][3]){
		
		int i,j;
		for(i=0;i < 3;i++);
			for(j =0;j < 3;j++)
				scanf("%d",&numero[i][j]);
	}			
	
	void inverteMatriz(int m[3][3]){
		
		int i,j;
		for(j=0;j < 3;j++);
			for(i =0;i < 3;i++)
				scanf("%d",&numero[i][j]);
				printf("o inverso e %d",numero[i][j]);
	}		