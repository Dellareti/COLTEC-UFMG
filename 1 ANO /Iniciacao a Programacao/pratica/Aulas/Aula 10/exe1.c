#include<stdio.h>
#include<stdlib.h>
#include<string.h>

	struct dados
{
	char nome[50],curso[30];
	int idade;
};

int main(void){
	char nome[50],curso[30];
	int idade;

struct dados pessoa;
 	
 	printf("\n---------- Cadastro de aluno -----------\n\n\n");
 	
	printf("\n\n Digite seu nome : \n\n");
	fgets(pessoa.nome,50,stdin);

	printf("\n\n Digite seu curso : \n\n");	
	fgets(pessoa.curso,30,stdin);
	
	printf("\n\n Digite sua idade : \n\n");
	scanf("%d",&pessoa.idade);
	
	printf("\n---------- Dados do aluno -----------\n\n\n");
	
	printf("Nome..........: %s",pessoa.nome);
	printf("Curso.........: %s",pessoa.curso);
	printf("Idade.........: %d",pessoa.idade);
	
		   
	return 0;
}