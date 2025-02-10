#include<stdio.h>
#include<stdlib.h>
#include<string.h>
  
    typedef dados{
    	
    int peso = 0;
	int altura = 0;
    int largura = 0;
    int profundidade = 0;
 
}Dados;
  
int main(){
struct dados caixa;
   
    int peso = 0;
	int altura = 0;
    int largura = 0;
    int profundidade = 0;
   
    printf("\n\n Digite a altura da caixa : \n\n");
    scanf("%d",&caixa.altura);
    
    printf("\n\n Digite a largura da caixa : \n\n");
    scanf("%d",&caixa.largura);
    
    printf("\n\n Digite a profundidade  : \n\n");
    scanf("%d",&caixa.profundidade);
    
    printf("\n\n Digite o peso da caixa : \n\n");
    scanf("%d",&caixa.peso);
      
      
    printf("Altura..........: %d",caixa.altura);
    printf("Largura.........: %d",caixa.largura);
    printf("profundidade....: %d",caixa.profundidade);
    printf("peso              :%d",caixa.peso);
    
    printf("Volume.............:%d",altura*largura*profundiade);
    printf("\n");
             
    return 0;
}