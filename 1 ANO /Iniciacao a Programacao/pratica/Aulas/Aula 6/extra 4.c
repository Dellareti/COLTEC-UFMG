 #include <stdio.h> 
int contaimpar (int n1, int n2) { 
int cont=0, ini, fim, i; 
if (n1 > n2) { 
ini = n1; 
fim = n2; 
} 
else { 
ini = n2; 
fim = n1; 
} 
for (i=ini; i <=fim; i++) 
if (i%2 != 0) 
cont++; 
return cont; 
} 

int main() {
int n1,n2;
 
printf("DIGITE O PRIMEIRO VALOR");
scanf("%d",&n1);
printf("DIGITE O SEGUNDO VALOR");
scanf("%d",&n2);

printf("\n%d", contaimpar); 
printf("\n%d", contaimpar); 
return 0; 
}
