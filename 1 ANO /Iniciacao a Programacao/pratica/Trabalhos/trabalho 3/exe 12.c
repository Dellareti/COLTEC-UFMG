#include <stdio.h>
#include <stdlib.h>
 
#define MAX 10
 
 float soma(float v[],int tam){
 
 	 if(tam<1){
 
 	 printf("Tamanho invalido!");
 	 exit(1);
 
 }
 
 	 if(tam==1){
 	 return v[0];
 }
	  else{
 
 return v[tam­1] + soma(v,tam­1);
 
 }
 
 int main(){
 
 	 float v[MAX];
   	 int i;
 	 	 for(i=0;i<MAX;i++){
 
 	 	 printf("V[%d]= ",i);
 	 	 scanf("%f",&v[i]);
 
 	 }
 	 	 printf("O valor da soma e: %f",soma(v,MAX));
 	 	 return 0;
 
 }
