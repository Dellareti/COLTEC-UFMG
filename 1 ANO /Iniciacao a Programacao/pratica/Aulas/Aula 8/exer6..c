#include <stdio.h>
#include <stdlib.h>

#include <strings.h>

main(){
 
 

	char texto[100], inverso[100];
	int i,f;
	
	printf("\n\n Digite um texto: \n\n");
	gets(texto);
	
	printf("\n\n O tamanho e : %d \n\n", strlen(texto));
	f=0;
  
  for (i=strlen(texto)-1; i >=0; i--){
      inverso[f] = texto[i];
      f++;
  }     

  	inverso[f] = '\0';
 	 printf("\n\n O inverso e : %s \n\n",inverso);
  
  
  if(strcmp(texto,inverso)==0){
    printf("\n\n E palindromo\n\n");
  }
  
  else{
	printf("\n\n Nao e palindromo\n\n");
  }     

  	printf("\n\n");     
	system("pause");       
}