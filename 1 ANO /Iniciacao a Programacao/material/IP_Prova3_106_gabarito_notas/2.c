#include <stdio.h>
#include <stdlib.h>

typedef struct{
	char nome[30];
	float nota[3];
}Disciplina;

typedef struct{
	char nome[30];
	int matricula;
	Disciplina disciplinas[5];
}Aluno;


Aluno* alocaTurma(int n) {
  Aluno* Turma = (Aluno *)malloc( n * sizeof(Aluno));
  return Turma;
}


void LeTurma(Aluno* Turma, int n) {

    int i, j, k;

    for (i = 0; i < n; i++){
        printf("\nDigite o nome do aluno: ");
        fflush(stdin); //ou __fpurge(stdin);
        scanf("%s", Turma[i].nome);
        printf("\nDigite a matricula de %s: ", Turma[i].nome);
        scanf("%d", &Turma[i].matricula);
        for (j = 0; j < 5; j++){
            printf("\nDigite o nome da disciplina %d de %s: ", j+1, Turma[i].nome);
            fflush(stdin); //ou __fpurge(stdin);
            scanf("%s", Turma[i].disciplinas[j].nome);
            printf("\nDigite as 3 notas de %s: ", Turma[i].disciplinas[j].nome);
            for (k = 0; k < 3; k++){
                scanf("%f", &Turma[i].disciplinas[j].nota[k]);
            }
        }
    }

}


float calculaMediaAlunoPorDisciplina(float nota[3]) {
    int i;
    float media = 0.0;

    for (i = 0; i < 3; i++) media += nota[i];

    return (media/3.0);
}



int main(){

	Aluno *Turma;
	int n, i, j;
	float media;

	printf("Digite o numero de alunos: ");
	scanf("%d", &n);

	Turma = alocaTurma(n);
	LeTurma(Turma, n);

	for (i = 0; i < n; i++){
        for (j = 0; j < 5; j++){
            media = calculaMediaAlunoPorDisciplina(Turma[i].disciplinas[j].nota);
            printf("Aluno %s \n Matricula %d \n Disciplina %s \n Media %.2f \n", Turma[i].nome, Turma[i].matricula, Turma[i].disciplinas[j].nome, media);
        }
	}

	free(Turma);
    return 0;
}
