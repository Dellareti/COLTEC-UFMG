#include<stdio.h>

	int main(){
	   char nome[100];
	   int idade;
	   float renda;
	   int endereco;
	   char cidade[30];
	   char estado[1];
	   int cep;
	   float credito;
	   
	      
	printf("\n\n Digite seu nome : \n\n");
	scanf("%s",&nome);
	
	printf("\n\n Digite sua idade : \n\n");
	scanf("%d",&idade);
	
	printf("\n\n Digite sua renda :\n\n");
	scanf("%f",&renda);
	
	printf("\n\n Digite seu endereco \n\n");
	scanf("%d",&endereco);
	
	printf("\n\n Digite o nome de sua cidade :\n\n");
	scanf("%s",&cidade);
	
	printf("\n\n Digite o seu estado(somente as 2 siglas) \n\n");
	scanf("%s",&estado);
	
	printf("\n\n Digite o nome de seu cep \n\n");
	scanf("%d",&cep);
	
	credito = renda;
	
	printf("\n\n Seu credito e: %.3f",credito/2);
	
	return 0;
	}