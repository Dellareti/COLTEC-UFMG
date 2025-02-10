#include<stdio.h>
#include<stdlib.h>
#include<string.h>
  
    struct dados
{
    char nome[50],curso[30];
    int notas[3];
    int idade;
 
};
  
int main(){
struct dados pessoa;
   int soma=0;
   int notas[3];

    printf("\n---------- Cadastro de aluno -----------\n\n\n");
      
    printf("\n\n Digite seu nome : \n\n");
    fgets(pessoa.nome,50,stdin);
  
    printf("\n\n Digite seu curso : \n\n"); 
    fgets(pessoa.curso,30,stdin);
      
    printf("\n\n Digite sua idade : \n\n");
    scanf("%d",&pessoa.idade);
      
    printf("\n\n Digite as tres notas : \n\n" );
           for (int i = 0; i < 3; i++)
           {
             
               scanf("%d",&pessoa.notas[i]);
               soma+=pessoa.notas[i];
           	 
  	   	   }
 
 
    printf("\n---------- Dados do aluno -----------\n\n\n");
      
    printf("Nome..........: %s",pessoa.nome);
    printf("Curso.........: %s",pessoa.curso);
    printf("Idade.........: %d",pessoa.idade);
    printf("\n A media das notas e :%d",soma/3);
    printf("\n");
             
    return 0;
}