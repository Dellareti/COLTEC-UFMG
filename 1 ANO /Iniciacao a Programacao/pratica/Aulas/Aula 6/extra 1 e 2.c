
#include <stdio.h> 
int main() { 
int n1, n2, a, b, temp, mdc, mmc; 
printf("\n\n Digite os dois  numeros: \n\n"); 
scanf("%d %d", &n1, &n2); 

a = n1; 
b = n2; 
while (b != 0) { 
temp = a; 
a = b; 
b = temp%b; 
} 
mdc = a; 
mmc = n1 * n2 / a; 
printf("\n\n O MDC de %d e %d e : %d \n\n", n1, n2, mdc); 
printf("\n\n O MMC de %d e %d e : %d\n\n", n1, n2, mmc); 
return 0; 
}
