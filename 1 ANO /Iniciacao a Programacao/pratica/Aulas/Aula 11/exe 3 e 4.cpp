#include <stdio.h>
#include <stdlib.h>
#include <math.h>

 typedef struct {
 char nome [ 1 5 ] ;
 float notas[2] ;
 }ALUNO;

 void leAlunos (FILE * entrada , ALUNO * alunos , int n ) {

 int i ;

 	 for ( i = 0 ; i < n ; i++){
 	 printf ( "--------------Digite as informacoes do aluno  %d--------------\n\n” , i +1) ;
   	   
	printf( " \n\n  Digite as 2 notas do aluno \n\n" ) ;
    scanf ( "%f %f ", &alunos [i].notas [0] , &alunos [i].notas [1] ) ;
	printf( "\n\n Digite o nome do aluno \n\n” ) ;
    gets ( alunos[i].nome) ;



 	 	 fprintf ( entrada , "\n\n %s %f %f \n\n" , alunos [i].nome , alunos [i].notas[0], alunos[i] .
		 notas[1] ) ;
 	 }
  }

 void calculaMediaAlunos (FILE * entrada , FILE * saida , int n ) {

 	 int i ;
 	 float media , nota1 , nota2 ;
 	 char aux [ 3 0 ] ;

 	 for ( i = 0 ; i < n ; i++){
 	 fscanf ( entrada , "%s %f %f " , aux , &nota1 , &nota2 ) ;
 
    media = ( nota1 + nota2 ) / 2 . 0 ;
    fprintf ( saida , "%s %f \n" , aux , media ) ;
  }

 }

 void calculaMediaVarDesvio (FILE * s ai d a , i n t n ) {

 	 int i ;
 	 float media = 0.0 , var =0.0, nota ;
 	 char aux [30] ;


 	 saida = fopen ( "medias.txt", " r " ) ;


 	 for ( i = 0 ; i < n ; i++){
	fscanf ( saida , "%s %f " , aux , &nota ) ;
 	 media += nota ;
 }
 	 	 
		   media = media / ( float ) n ;

 	 	 	 fseek ( saida , 0 , SEEK SET) ;

 	 	 	 	 for ( i = 0 ; i < n ; i++){
 	  	 	 	 	 fscanf ( saida , "%s %f " , aux , &nota ) ;
  	 	 	 	 	 	 var += ( nota-media ) *( nota-media ) ;
 	 }
 
   	   	   	 var = var / (float) ( n-1) ;


 fclose(saida) ;


 saida = fopen ( "medias .txt" , "a" ) ;
 fprintf ( saida, " \n\n A media , a variancia e o desvio padrao da turma : %f %f %f \n\n" , media );
  var , sqrt ( var)) ;


 fclose (saida) ;
 }

 void imprimir ( char * entrada) {

 FILE * arquivo;

 arquivo = fopen ( entrada , " r " ) ;

 if ( ! arquivo) {
 
 printf ( "\n\n  Erro ao abrir arquivo \n\n" ) ;
 exit(1) ;
 }

 char aux [100] ;

 	 while( ! feof ( arquivo) ) {
 	 if ( fgets( aux , 100 ,arquivo) )
	
	   printf( "%s" ,aux) ;
 }

 	 fclose(arquivo) ;

 }
 int main () {

 	 FILE * entrada , * saida ;
 	 ALUNO * alunos ;
 	 int n ;
 	 char ent[2 0] = "notas.txt " , sai[ 20 ] = "medias . t x t " ;

 	 printf ( " \n\n Digite o numero de alunos : \n\n ") ;
 	 scanf ( "%d" , &n) ;

 	 alunos = (ALUNO*) calloc( n ,sizeof (ALUNO) ) ;

 	 entrada = fopen ( ent , "w" ) ;

 	 if ( ! entrada ) {
   printf ( "ERRO! " ) ;
  exit ( 1 ) ;
 }

    leAlunos ( entrada , alunos, n ) ;

    fclose (entrada) ;


    entrada = f open ( ent , " r " ) ;
    saida = fopen ( sai , "w" ) ;


	calcuaMediaAlunos ( entrada , saida , n ) ;

    fclose(entrada) ;
    fclose(saida) ;


   calculaMediaVarDesvio( saida , n ) ;

    printf ( "\n--------Lista de Alunos e Notas--------\n" ) ;
    imprimir( ent ) ;
	
	printf( "\n\n--------Lista de Alunos e Medias--------\n\n" ) ;
    imprimir(sai) ;

	free( al u n o s ) ;

return 0 ;