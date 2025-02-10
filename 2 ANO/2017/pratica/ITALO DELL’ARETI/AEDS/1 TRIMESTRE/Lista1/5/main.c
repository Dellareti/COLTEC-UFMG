#include "pilha.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){
	Pilha *pilha = pilha_cria(); 
	char provisoria[50],l,a,frase[50]={'\0'};
	int i,j=0,cont=0;

	printf("Digite a frase\n");
	fgets(provisoria,50,stdin);
	//ARRUMA A FRASE(TIRA CARACTERES QUE NAO SAO LETRAS).
	
	for(i=0;i<strlen(provisoria);i++){
		provisoria[i]=toupper(provisoria[i]);
		if(isalpha(provisoria[i])||isdigit(provisoria[i])){
			frase[j]=provisoria[i];
			j++;
				frase[strlen(frase)]='\0';

			printf("copiei o %c\n",provisoria[i]);
			printf("%s\n",frase);
		}
	}	
	frase[strlen(frase)]='\0';
	printf("Frase filtrada %s\n",frase);


	for(i=0;i<strlen(frase);i++){
		if(cont!=0)
			a=pilha->vet[pilha->n-1];

		pilha_push(pilha,frase[i]);
		printf("a == %c e o  frasei== %c\n",a,frase[i]);
		if(cont!=0 && a==frase[i]){
			printf("tirei\n");
			l=pilha_pop(pilha);
			l=pilha_pop(pilha);
			printf("tirei o %c\n",l);
		}
		if(cont==0)
			cont++;
	}

	if(pilha_vazia(pilha)){
		printf("FUNCIONOU\n");
	}

	printf("FOI?   %i\n",pilha->n);

}