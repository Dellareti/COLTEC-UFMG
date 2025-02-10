#include "arvore.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int determina_meio(char expr[]){
	//Determina o meio da expressao, onde sera
	// a raiz da arvore
	int i,a=0,f=0;
	int save=0;
	for(i=0;i<strlen(expr);i++){
		if(expr[i]=='(')a++;          
		if(expr[i]==')')f++;		
		if((expr[i]=='+'||expr[i]=='-') && a==f)
			return i;
	}
	for(i=0;i<strlen(expr);i++){
		if(expr[i]=='(')a++;          
		if(expr[i]==')')f++;		
		if((expr[i]=='/'||expr[i]=='*') && a==f)
			return i;
	}

		char aux[50];
		for(i=0;i<strlen(expr);i++)
			aux[i]=expr[i+1];

		aux[strlen(aux)-1]='\0';
//		printf("%i\n",determina_meio(aux));
		return determina_meio(aux)+1;
}

Arv* arvorize(char expr[]){
	//Monta primeiro a parte esquerda e depois a direita
	int meio=determina_meio(expr);
	char aux[50]="teste\0";
	char aux2[50]="teste\0";
	int i,j=0;

//	printf("O MEIO É %i  %c\n",meio,expr[meio]);
	Arv *r = arv_cria(expr[meio],NULL,NULL);
//	printf("ESQUERDA!\n");

	if((expr[meio-1])>=48 && (expr[meio-1])<=57){
		r->esq = arv_cria(expr[meio-1],NULL,NULL);
	}
	else if(expr[meio-1]==')'){
		for(i=0;i<meio;i++)
			aux[i]=expr[i];
		aux[strlen(aux)]='\0';
//		printf("aa%liaa\n",strlen(aux));
//		printf("----%s----\n",aux);
		r->esq = arvorize(aux);
	}

//	printf("DIREITA!\n");
	if((expr[meio+1])>=48 && (expr[meio+1])<=57){
		r->dir = arv_cria(expr[meio+1],NULL,NULL);
	}
	else if(expr[meio+1]=='('){
		for(i=meio+1;i<strlen(expr);i++){			
			aux2[j]=expr[i];
			j++;
		}
//		printf("aa%liaa\n",strlen(aux2));
		aux2[strlen(aux2)]='\0';

//		printf("----%s----\n",aux2);
		r->dir = arvorize(aux2);
	}

	return r;
}

void arv_exp_to_txt(Arv *a,FILE *f){
	if(!arv_vazia(a)){
		arv_exp_to_txt(a->esq,f);
		arv_exp_to_txt(a->dir,f);
		fprintf(f,"%c ",a->info);
	}
}


int main(){
	char expr[50];
	printf("Digite a expressao:\t");
	fgets(expr,50,stdin);
	expr[strlen(expr)-1]='\0';


	Arv *r =  arvorize(expr);

	imprime_arvore(r);

	printf("----\n");
	arv_imprime_posordem(r);

	//COPIA PARA O ARQUIVO.TXT
	FILE *arq = fopen("arvores.txt","w");
	arv_exp_to_txt(r,arq);
	fprintf(arq,"\n----------\n");
	fclose(arq);
}
