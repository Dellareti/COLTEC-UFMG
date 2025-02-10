#include<stdio.h>

int main(){
	int vet[20],i=0,menor;

 printf("\n\n Digite os numeros:\n\n");
               
	while (i<20){
	
	 scanf("%i",&vet[i]);
	i++;}

	menor=vet[0];


	for(i=0;i<20;i++){

	if(vet[i]<menor){
		menor=vet[i];
	
	}}

	printf("\n\n O menor nunero e %i \n\n",menor);

	return 0;
}

