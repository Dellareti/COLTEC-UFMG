#include<stdio.h>
#include<string.h>


int main(void){
int a=0;
int b=0;
int i=0;
int j=0;


	int matrizA [5][5]={0};
	int matrizB [5][5]={0};

	
	printf("\n\n \tDigite sua matriz :\n\n");

	for(a=0;a < 5 ; a++){
		for(b=0;b < 5; b++){
		
		scanf("%d",&matrizA[a][b]);
	
	       }
      }		
	

	printf("\n A matriz digitada e :\n");	

	for(i=0;i < 5;i++){
		for(j=0;j < 5 ;j++){
		
		printf("%d\t",matrizA[i][j]);
		
             }
		printf("\n");
	}
		
		for (i=0; i< 5; i++){
			for (j=0; j<5; j++){
			
		matrizB[i][j]=matrizA[j][i];
	     }
		
	}

	printf("\n\n A matriz trasposta e :\n\n");
	
	for (i=0; i< 5; i++){
	 	 for (j=0; j< 5; j++) {
           
		 printf("%d\t", matrizB[i][j]);
            
		  }
		  printf("\n");
	}



	return 0;
}
