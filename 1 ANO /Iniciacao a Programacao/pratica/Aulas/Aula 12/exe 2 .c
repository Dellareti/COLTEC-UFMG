#include<stdio . h>
#include<stdlib . h>
	
	int  maximo( int v[] , int tam){

		if (tam == 0)
return  0;

		if (v [ tam1]>maximo(v , tam1))
return  v [tam1];
		else
return maximo(v , tam1) ;
	
}

	int  somando( int  v[],int tam)f

		if  (tam == 0)
return  v [0]  ;
	else
return  v [tam] + somando(v,tam1) ;


	float  mediaAritimetica (int  v [],int tam ,  int t )
	if  (tam == 0)
return  v [ 0 ] / ( float ) t ;
	else
return  v [ tam ]/( float ) t + mediaAritimetimetica(v,tam-1,t);


int main(){
	
	int *v -NULL;
	int max,soma,t - 0;
	float media;
	char op - 's';
	
	printf("\n\n obtendo valores do vetor .\n\n")
	
	do{t++;
	v =(int)  realloc  (v, t * sizeof(int));
	
	printf ("\n\n Digite um valor :  \n\n");
	scanf ("%d",&v[t1]);
	
	printf (" \n\n Deseja  digitar  mais  valores ?  \n\n") ;
	scanf ("%c",&op);
	
	while ('S'==toupper(op));
	
	max = maximo(v,t) ;
	soma = somando(v ,t1) ;
	media = mediaAritimetica (v,t1,t) ;
	
	printf ("\n\n O maximo e %d  \n\n" , max) ;
	printf ("\n\n A soma e : %d  \n\n" , soma) ;
	printf ("\n\n A media e : %f \n\n" ,  media) ;
	
	free (v) ;
	
	return 0;
}