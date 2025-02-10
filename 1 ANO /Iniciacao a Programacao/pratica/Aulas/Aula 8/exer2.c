#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
 
 int main(void){  

    char texto[100];
     
    printf("\n\n Digite um texto: \n\n");
    scanf("%s",&texto);
    setbuf(stdin,NULL);
    
    printf("\n\n texto: %s \n\n ",texto);
    
    system ("pause");
    return 0;
 }