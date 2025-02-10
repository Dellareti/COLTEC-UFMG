#include <stdio.h>
#include <string.h>

void transformaFrase(char frase[]) {

  int i = 0;
  int tam = strlen(frase);
  char atual;

  for(i = 0; i < tam; i++) {

    atual = tolower(frase[i]);
    if(atual == 'a' || atual == 'e' || atual == 'i' || atual == 'o' || atual == 'u') {
      frase[i] = tolower(atual);
    } else {
      frase[i] = toupper(atual);
    }
  }
}


int main() {

  char frase[50];
  int vogais;

  printf("Digite uma frase (máx 50 caracteres)\n");
  gets(frase);

  puts(frase);
  transformaFrase(frase);
  puts(frase);
}
