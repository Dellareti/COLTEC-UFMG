#include "arvore.h"
#include <stdio.h>
#include <stdlib.h>



int main(){
	
int preco=0;
int i=0;
int j=0;
int k=0;
int l=0;

	Arv *n10 = arv_cria(1,NULL,NULL);
	Arv *n11 = arv_cria(1,NULL,NULL);
	Arv *n12 = arv_cria(0,NULL,NULL);
	Arv *n13 = arv_cria(0,NULL,NULL);
	Arv *n3 = arv_cria(4,NULL,NULL);
	Arv *n4 = arv_cria(2,n10,n11);
	Arv *n6 = arv_cria(0,NULL,NULL);
	Arv *n2 = arv_cria(6,n3,n4);
	Arv *n14 = arv_cria(1,n12,n13);	
	Arv *n5 = arv_cria(0,n14,n6);
	
	printf("\n Digite o preco : ");
	scanf("%d",&preco);
	Arv *r = arv_cria(preco,n2,n5);

	if(preco<20.000){
	
	Arv *n2 = arv_cria(1,n3,n4);
	Arv *n5 = arv_cria(0,n14,n6);
	Arv *n13 = arv_cria(0,NULL,NULL);
	Arv *n14 = arv_cria(0,NULL,NULL);
	Arv *n5 = arv_cria(0,n14,n6);

	printf("\n O produto é economico 1/0 ?");
	scanf("%d",&i);
	
	if(i=1){
	Arv *n3 = arv_cria(1,NULL,NULL);
	Arv *n4 = arv_cria(0,n10,n11);
   }	
	else{
	printf("Obrigatoriedade ?");
	scanf("%d",&j);
	
	if(j=1){
	Arv *n11 = arv_cria(0,NULL,NULL);
	Arv *n12 = arv_cria(1,NULL,NULL);
}
	else{
	Arv *n11 = arv_cria(1,NULL,NULL);
	Arv *n12 = arv_cria(0,NULL,NULL);
}
}

}	
	if(preco>20.000){

	Arv *n3 = arv_cria(0,NULL,NULL);
	Arv *n4 = arv_cria(0,n10,n11);
	Arv *n6 = arv_cria(0,NULL,NULL);
	Arv *n11 = arv_cria(0,NULL,NULL);
	Arv *n12 = arv_cria(0,NULL,NULL);

	if(k=1){
	Arv *n6 = arv_cria(1,NULL,NULL);	
	Arv *n10 = arv_cria(0,NULL,NULL);
   }	
	else{
	printf("Obrigatoriedade ?");
	scanf("%d",&k);
	
	if(l=1){
	Arv *n13 = arv_cria(0,NULL,NULL);
	Arv *n14 = arv_cria(1,NULL,NULL);
}
	else{
	Arv *n13 = arv_cria(1,NULL,NULL);
	Arv *n14 = arv_cria(0,NULL,NULL);
}
	printf("-----------------------------------------------------------------------------------\n");
	imprime_arvore(r);
	
}
