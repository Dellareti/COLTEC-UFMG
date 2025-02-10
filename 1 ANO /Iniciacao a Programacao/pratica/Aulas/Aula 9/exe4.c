#include<stdio.h>
#include<stdlib.h>

int soma(int m[7][5]){
int i,j;
int s=0;
  
    for(i=0;i<7;i++){
        for(j=0;j<5;j++)
            s=s+m[i][j];
		printf("\n Loja : %d = %d \n", i+1,s);
 
    } 
}
     
int main(void){

    int i,j,menor;
    int m[7][5];
    printf("\n\n Digite os valores \n\n");
   
	 for(i=0;i < 7;i++){
        	for(j=0;j < 5;j++){
           
		 printf("\n\n Digite o produto %d da loja %d : \n\n",j+1,i+1);
           	 scanf("%d", &m[i][j]);

       	 }
    }
    soma(m);


        if (i==0) {
            menor=soma;
        }
       
	 if(soma<menor){
            menor=i;
       }
    
    printf("\n\n A loja que teve menos produtos é a %i.\n\n",menor);
   
    

return 0;
}


