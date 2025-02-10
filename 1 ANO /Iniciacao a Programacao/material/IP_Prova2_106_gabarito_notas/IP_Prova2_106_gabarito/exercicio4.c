#include <stdio.h>
#include <string.h>

void transformaFrase(char frase[]) {

  int i = 0;
  int tam = strlen(frase);
  char atual;

  for(i = 0; i < tam; i++) {
    atual = tolower(frase[i]);
    if(atual == 'a' || atual == 'e' || atual == 'i' || atual == 'o' || atual == 'u') {
      frase[i] = toupper(atual);
    } else {
      frase[i] = tolower(atual);
    }
  }
}


int main() {

  char frase[50];
  int vogais;

  printf("Digite uma frase (max 50 caracteres)\n");
  fgets(frase, 50, stdin);

  puts(frase);
  transformaFrase(frase);
  puts(frase);
}
