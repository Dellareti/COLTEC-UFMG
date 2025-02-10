#include <stdio.h>
#include <stdlib.h>

typedef struct{
	char nome[30];
	int cargaHoraria;
}Disciplina;

typedef struct{
	char nome[30];
	int codigo;
	Disciplina disciplinas[5];
}Professor;


Professor* alocaProfessor(int n) {
  Professor* professores = (Professor *)malloc( n * sizeof(Professor));
  return professores;
}


void LeProfessor(Professor* professores, int n) {

  int i, k;

  for (i = 0; i < n; i++) {
      printf("\nNome do professor: ");
      scanf("%s", &professores[i].nome);

      printf("\nCódigo do professor: ");
      scanf("%d", &professores[i].codigo);

      for (k = 0; k < 5; k++) {
        printf("\n\tNome da Disciplina: ");
        scanf("%s", &professores[i].disciplinas[k].nome);

        printf("\n\tCarga horária da Disciplina: ");
        scanf("%d", &professores[i].disciplinas[k].cargaHoraria);
      }
  }
}



int calculaCargaHoraria(Professor professor) {

  int cargaHoraria = 0, i;

  for (i = 0; i < 5; i++) {
    cargaHoraria += professor.disciplinas[i].cargaHoraria;
  }
  return cargaHoraria;
}



int main(){
	Professor *professores;
	int n, i;
	int media;

	printf("Digite o numero de professores\n");
	scanf("%d", &n);

	professores = alocaProfessor(n);
	LeProfessor(professores, n);
	for (i = 0; i < n; i++){
    media = calculaCargaHoraria(professores[i]);
    printf("Professor: %s Código: %d Carga Horária: %d\n", professores[i].nome, professores[i].codigo, media);
	}
	free(professores);
	return 0;
}
