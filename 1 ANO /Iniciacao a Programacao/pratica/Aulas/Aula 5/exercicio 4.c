#include <stdio.h>

int main()
{
   int  n,i,seq;
   int  primeiroN = 0;
   int  segundoN  = 1;

   printf("\n\n Digite os numeros da sequencia\n\n");
   scanf("%d",&n);

   if(n>2) {

    printf("\n\n\n1:\n\n");
      for(i=0;i<n;i++){

    seq = primeiroN + segundoN;
    segundoN = primeiroN;
    primeiroN = seq;
  	 printf("\n\n%d\n\n",seq);


      }

}

   else
   printf("\n\n Digite um numero maior que 2\n\n");

   return 0;
}
