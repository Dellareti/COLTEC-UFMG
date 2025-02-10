#include <stdio.h>
#include <stdlib.h>

	int  NumeroDeLinhas(FILEarquivo ){
	int  linhas = 0;
	char  aux ;

	  while  ( ! feof ( arquivo ) ){
	  fscanf ( arquivo ,  "%c" , &aux) ;
      if  (aux == '\n ' )
      linhas++;
    }

   return  linhas ;
}

int  main (){

	FILE *arquivo ;
    int  linhas ;

    arquivo = fopen ("entrada.txt","r") ;

    if ( ! arquivo )
    printf ("Erro ! ") ;
    exit (1) ;


    linhas = NumeroDeLinhas( arquivo );
    printf ("\n\n O arquivo tem %d  linhas \n\n" ,  linhas-1) ;

    fclose( arquivo ) 

return  0;