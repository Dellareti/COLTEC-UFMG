#include <stdio.h> 

int somalc(int matriz[7][6]){ 
int soma = 0, i; 

for (i=0; i < 7 ; i++) 
soma += matriz[5][i];
	for (i=0; i < 6; i++) 
	soma += matriz[i][3]; 

return (soma - matriz[5][3]); 
} 

int main() { 

		printf("\n\n Digite sua matriz : \n\n");
		
int x[7][6], i, j; 
for (i=0; i<7; i++) 
for (j=0; j<6; j++) 
scanf("%d", &x[i][j]); 


		printf("\n\n A matriz digitada e :\n\n");   
 
    for(i=0;i < 7;i++){
        for(j=0;j < 6 ;j++){
         
        printf("%d\t",x[i][j]);
         
             }
        printf("\n");
    }
         

printf("\n\n Soma dos elementos da linha 5 com os da coluna 3: %d \n\n", somalc(x)); 
return 0; 
}