#include <stdio.h>

int calculaMontanteCategoria(int salarios[], int numEmpregados, char *categoria) {

  int i;
  int montante = 0;

  for(i = 0; i < numEmpregados; i++) {
    montante += salarios[i];
  }

  if(montante <= 15000) {
    *categoria = 'M';
  } else if(montante >= 15001 && montante <= 21250) {
    *categoria = 'P';
  } else if(montante >= 21251) {
    *categoria = 'G';
  }

  return montante;
}

int main() {
  srand(time(NULL));

  int salarios[25], i;
  char categoria;
  int montante = 0;

  printf("salarios:\n");
  for(i = 0; i < 25; i++) {
    salarios[i] = 1000 - (rand() % 401);
    printf("%d\n", salarios[i]);
  }

  montante = calculaMontanteCategoria(salarios, 25, &categoria);

  printf("Montante: %d. Categoria: %c\n", montante, categoria);

  return 0;
}
