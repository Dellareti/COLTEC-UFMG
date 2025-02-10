
#include <stdio.h>
 
 int digitos(int x) {
	if( (x) < 10 )
    return 1;
 
   else
   return(1 + digitos(x/10));
  }
 int  main() {
 	
	int num;
	printf("\n\n Entre com um número: \n\n ");
	
	scanf("%d", &num);
    printf("\n\n O numero de digitos de %d e :%d. \n\n", num, digitos(num));
 } 