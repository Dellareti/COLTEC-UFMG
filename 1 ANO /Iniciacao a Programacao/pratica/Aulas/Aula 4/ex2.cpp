#include <stdio.h>
#include <stdlib.h>

int main() {

	int a, b;

	printf("Digite os dois numeros: \n");
	scanf("%d %d", &a, &b);

	if (a > b)

		printf("O primeiro e maior que o segundo. %d > %d", a , b);
	else if (a == b)
		printf("O Primeiro e igual ao segundo. %d = %d", a, b);
	else
		printf("O Primeiro e menor que o segundo %d<%d", a, b);
	return 0;
}
