#include<stdio.h>
	
	void leMatriz(int m[3][3]){
		
		int i,j;
		for(i=0;i < 3;i++);
			for(j =0;j < 3;j++)
				scanf("%d",&m[i][j]);
	}

	int somaElementosDiagonalPrincipal (int matriz[3][3]){
		
		int soma=0;
		int i,j;
		
		for(i=0;i < 3;i++){
			for(j=0;j < 3;j++){
				if(i==j || i+j ==2)
					soma=soma + matriz[i][j];
		}
		
	}
	   return soma;	
   }

   
   int somaElementosDiagonalSecundaria(int matriz[3][3]){
	   
	   
	   
   }
   		
int soma 
		
		
		
int main(){

	int m[3][3];
	int somaPimaria=0;
	int somaSecundaria=0;
	printf("\n\n Digite sua matriz : \n\n");
	leMatriz(m);

    somaPimaria = somaElementosDiagonalPrincipal(m);
	somaSecundaria=somaElementosDiagonalSecundaria(m);
	
	  
	   
	   
	return 0;	
}	
	
