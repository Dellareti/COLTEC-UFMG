#include <stdio.h>
#include <stdlib.h>

 
  #define MAX 10
 
 float menor_elemento_do_vetor(float v[ ],int tam){
 
	float m;
	if(tam<0) {
 
 	 printf("\n\n Tamanho invalido !!! \n\n");
 	 exit(1);
 
 }
 	 if (tam == 1)
 
 	 return v[tam­1];
 	 else{
 
 	 	 m = menor_elemento_do_vetor(v, tam­1);
 
 
 	 if (v[tam­1] < m)
 	 return v[tam­1];
 
 	 else
 	 return m;
 
     }
}
 
 int main() {
 
 	 float v[MAX];
 	 int i;
 for(i=0;i<MAX;i++){
 
 	 printf("V[%d]= ",i);
 	 scanf("%f",&v[i]);
 
  }
 	 printf("O menor elemento é : %f", menor_elemento_do_vetor( v, MAX ) );
 	 return 0;
 
 }