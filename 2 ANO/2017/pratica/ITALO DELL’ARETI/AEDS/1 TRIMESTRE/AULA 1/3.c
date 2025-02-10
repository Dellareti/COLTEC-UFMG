#include <stdio.h>
#include <stdlib.h>

typedef struct {
	char nome[30];
	int *notas;
}aluno;


 aluno* aloca(int tam,int n){
	aluno *p = (aluno*)malloc(tam*sizeof(aluno));
	int i=0;
	for(i=0;i<tam;i++)
		p[i].notas= (int*) malloc(n*sizeof(int));
	return p;
}

	float media(aluno aluninho,int n){
		int i;
		float media=0;
		for(i=0;i<n;i++){
		media+=	aluninho.notas[i];
	}
	      return media/n;
 }


	void ler_informacoes(aluno *aluninho,int qtd,int n){

	int i,j;
	for(i=0;i<qtd;i++){
		printf("Nome do aluno %i:",i+1);
		fgets(aluninho[i].nome,30,stdin);
		putchar('\n');
		printf(" Digite %i notas:",n);
		
			for(j=0;j<n;j++)
			scanf("%i",&aluninho[i].notas[j]);
			__fpurge(stdin);
			putchar('\n');
        	}
          }


	void imprime(aluno *aluninho,int qtd,int n){

	int i,j;
	for(i=0;i<qtd;i++){
		printf("----%snotas:\n",aluninho[i].nome);
		for (j=0;j<n;j++)
			printf("Nota %i:%i\n",j+1,aluninho[i].notas[j]);
	        	printf("Media:%.2f\n\n",media(aluninho[i],n));
	
	}
}

	  int main(){
	  aluno *aluninhos = NULL;
	   int i,tam,num;
		printf("Quantos alunos deseja calcular?\n");
			scanf("%i",&tam);
		
			printf("Quantas notas de cada aluno deseja calcular ?\n");
			scanf("%i",&num);
			__fpurge(stdin);
			aluninhos=aloca(tam,num);
			ler_informacoes(aluninhos,tam,num);
			imprime(aluninhos,tam,num);
	
			for (i=0;i<tam;i++)
			free(aluninhos[i].notas);
			free(aluninhos);
           }
