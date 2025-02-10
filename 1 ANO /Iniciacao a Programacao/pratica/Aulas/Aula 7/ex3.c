#include <stdio.h>
int main(void) {
    int i, soma, v1[10], v2[10];
    soma = 0;
   
		 printf("\n\n Digite os 10 valores do vetor 1: \n\n");
    for(i = 0; i < 10; i++) {
        scanf("%d", &v1[i]);
    }
   		

		 printf("\n\n Digite os 10 valores do vetor 2: \n\n");
    for(i = 0; i < 10; i++) {
        
	 scanf("%d", &v2[i]); soma += v1[i] * v2[i];
    }


   		 printf("\n\n O produto escalar e: %d \n\n", soma);
    return 0;
}
