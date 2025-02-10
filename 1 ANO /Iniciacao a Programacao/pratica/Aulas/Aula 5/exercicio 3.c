#include <stdio.h>

int main () {

  int n,maior,menor;
  maior = -9999;
  menor =  9999;

  printf("Digite os numeros de comparacao(Digite 0 para parar)\n\n");
  scanf("%d",&n);

  while (n != 0) {


	if (n<menor)
 		menor=n;

	else if (n>maior)
		maior=n;

	printf("\n\n Digite um numero\n\n");
  	scanf("%d",&n);

  }

  printf("\n\n O menor e = %d\n\n",menor);

  printf("\n\n O maior e = %d\n\n",maior);




  return 0;

}

