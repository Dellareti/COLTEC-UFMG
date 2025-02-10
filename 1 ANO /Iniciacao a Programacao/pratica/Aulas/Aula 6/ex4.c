#include<stdio.h>

int quadrado (int x)
{
return (x * x);}
int main (){

int numero, res;
printf("\n\nDigite um numero inteiro: \n\n");
scanf("%d", &numero);

while(numero != 0)
{

res = quadrado(numero);
printf ("\n\nO quadrado de %d e %d.\n\n", numero, res);
printf("\n\nDigite um numero inteiro:\n\n ");
scanf("%d", &numero);
}

return 0;
}
