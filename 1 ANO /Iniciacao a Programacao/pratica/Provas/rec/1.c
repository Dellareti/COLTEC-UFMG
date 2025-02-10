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
                  printf("%5d ", matriz[j][i]);
              }
              printf("\n\n");
      }
}


 int main(){
       int Matriz[6][6];
       int l=0;
	   int c=0;
	    
      printf("\n\n Digite as dimensoes da sua matriz : \n\n");
	  scanf("%d %d",&l,&c);
	   
      printf("\n\n Digite sua matriz : \n\n");
      leMatriz(Matriz);
      
      printf("-----------------------------\n");
      printf("Matriz Trasposta:\n");
      printf("-----------------------------\n");
                  
      imprimeMatriz(Matriz);
	    
      
      printf("\n\n");
      getch();

return 0;
}