#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

void leMatriz (int matriz[6][6] ){
    int i,j;
    for(i=0;i<6;i++){
        for(j=0;j<6;j++){
        scanf("%d",&matriz[i][j]);  
        }
    }
}

void imprimeMatriz(int matriz[6][6]){
	int i,j;
	for (i=0; i< 6;i++){
            for (j=0; j < 6;j++){
                  printf("%5d ", matriz[i][j]);
              }
              printf("\n\n");
      }
}

void somaDiagonalPrincipal(int matriz[6][6]){
	 int i,j;
	 int soma = 0;
	 for (i=0; i< 6;i++){      
            for (j=0; j< 6;j++){
                 if (j == i){                   
                       printf("%5d ", matriz[i][j]);
                       	soma=soma +	matriz[i][j];		   
				   }
            }
      }  
	printf("\n\n Soma da Diagonal Principal : %d \n\n",soma);
}


void somaDiagonalSecundaria(int matriz[6][6]){
	int i,j;
	int soma=0;
	for (i=0; i< 6;i++){      
            for (j=0; j < 6;j++){
                 if (j == (6 - 1 - i )){                   
                       printf("%5d ", matriz[i][j]);
                       soma=soma + matriz[i][j];               
				   }
            }
      }
    printf("\n\n Soma da Diagonal Secundaria :%d \n\n",soma);
  }

 int main(){
       int Matriz[6][6];
       
       
      printf("\n\n Digite sua matriz : \n\n");
      leMatriz(Matriz);
      
      printf("-----------------------------\n");
      printf("Matriz Digitada:\n");
      printf("-----------------------------\n");
                  
      imprimeMatriz(Matriz);
	    
      printf("\n\n");  
      printf("-----------------------------\n");
      printf("DIAGONAL PRINCIPAL Digitada:\n");
      printf("-----------------------------\n");

      somaDiagonalPrincipal(Matriz);
	   
      printf("\n\n");
      printf("-----------------------------\n");
      printf("DIAGONAL SECUNDARIA Digitada:\n");
      printf("-----------------------------\n");

      somaDiagonalSecundaria(Matriz);
	    
      printf("\n\n");
      getch();

return 0;
}