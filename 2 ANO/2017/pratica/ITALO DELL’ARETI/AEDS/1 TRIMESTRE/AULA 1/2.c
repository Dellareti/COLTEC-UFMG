#include <stdio.h>
#include <stdlib.h>

typedef struct {
	
	char nome[30];
	int notas[4];
}aluno;


	aluno* aloca(int tam){
	return (aluno*)malloc(tam*sizeof(aluno));
  }

	float media(aluno aluninho){
		return (float)(aluninho.notas[0]+aluninho.notas[1]+aluninho.notas[2]+aluninho.notas[3])/4.0;
  }

	void ler_informacoes(aluno aluninho[],int qtd){
	int i,j;

	for(i=0;i<qtd;i++){
		printf("\t Nome do aluno %i:",i+1);
		fgets(aluninho[i].nome,30,stdin);
		putchar('\n');
		printf("Digite 4 notas:");
		for(j=0;j<4;j++)
			scanf("%i",&aluninho[i].notas[j]);
			__fpurge(stdin);
			putchar('\n');
	      }
        }

	void imprime(aluno aluninho[],int qtd){
	
	int i;
	for(i=0;i<qtd;i++)
		printf("--%snotas : %i---%i---%i---%i\nmedia : %.2f\n\n",aluninho[i].nome,aluninho[i].notas[0],aluninho[i].notas[1],aluninho[i].notas[2],aluninho[i].notas[3],media(aluninho[i]));
	
    }
	int main(){

	aluno *aluninhos = NULL;
	int tam;
	
		printf("Quantos alunos voce deseja calcular ?\n");
		scanf("%i",&tam);
		__fpurge(stdin);
		aluninhos=aloca(tam);
		ler_informacoes(aluninhos,tam);
		imprime(aluninhos,tam);
		free(aluninhos);
    }
