#include<stdio.h>
#include<stdlib.h>

typedef struct alunos_notas{
	char nome[30];
	float nota[4];
	
}alunos;

float calculaMedia(float notas[],int n){
	int i;
	float media = 0.0;
		
		for(i = 0;i < n; i++){
			media += notas[i];
			   return media/(float)n;	
		}
}


void printAlunos(alunos x[],int nota){
	int i;
	int j;
	
		printf("\n\n -------- Dados -------- \n\n");
			for(i = 0;i < nota;i++){
				printf("\n %s",x[i].nome);
				
				for(j = 0;j < 4;j++){
					printf("%.3f",x[i].nota[j]);
						printf("%.3f",calculaMedia(x[i]nota,4));
				}
			}
	
	
}


void leAlunos(alunos x[],int n){
	int i;
	int j;
	
		for(i = 0;i < n;i++){
			printf("\n\n Digite o nome do aluno :\n\n");
			fgets(x[i].nome,30,stdin);
				printf("\n\n Digite a notas : \n\n");
				for(j = 0; j < 4;j++){
					scanf("%f %s",&x[i].nota[j]);
				}
		}
	
}




int main(){
	aluno aluno[8];
	leAlunos(alunos,8);
	printfAlunos(alunos,8);
	
	
	
	return 0;
}