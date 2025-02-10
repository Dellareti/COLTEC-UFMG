#include <stdio.h>
#include <stdlib.h>
  
 void imprime_entre(int a,int b){
     int c;
     c = a+1;
     if (b < a){
  
     printf("ERRO: b MENOR QUE a"); 
 }
      else{
  
     if (b > c){ 
  
         printf(" %d ", c);
         imprime_entre(c,b);
  
         }
    }
  
 }
  
 int main(){
  
 int a1,a2;
 int b1,b2;
         
 printf("\n\n Digite os parametros para A :\n\n");
 scanf("%d %d",&a1,&a2);
 imprime_entre(a1,a2); 
  
 printf("\n\n");
  
 printf("\n\n Digite os parametros para B :\n\n");
 scanf("%d %d",&b1,&b2);
 imprime_entre(b1,b2);
  
 printf("\n\n");
  
 return 0;
 }