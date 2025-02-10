#include <stdio.h>
#include <string.h>
#include "lista.h"


int retorna_posicao(char nome[]){
	int i=0;
	int soma=0;
	while(i!=strlen(nome)){	
		soma+=nome[i];
		i++;
	}
	return soma%29;
}

int main(){
	int c;
	char aux[30],aux2[9],aux3[30];
	int pos;
	Lista *contatos[29];

	do{
		printf("-----------MENU---------\n1 - Inserir novo contato\n2 - Buscar contato\n--------------\n");	
		scanf("%i",&c);
		__fpurge(stdin);
		if(c==1){
			printf("Digite o nome: ");
			fgets(aux,30,stdin);
			printf("Digite o num do telefone deste contato: ");
			fgets(aux2,9,stdin);
			printf("Digite seu endereco: ");
			fgets(aux3,30,stdin);

			pos = retorna_posicao(aux);
			printf("Ele vai ser colocado na pos -%i-\n",pos);
			contatos[pos] = lst_insere(contatos[pos],aux,aux2,aux3);
			__fpurge(stdin);
		}
		else if(c==2){
			__fpurge(stdin);
			printf("Digite o nome do cara a ser buscado: ");
			fgets(aux,30,stdin);
			pos = retorna_posicao(aux);
			printf("Ele ta na pos -%i-\n",pos);
		}
		else{
			printf("NO\n");			
			break;
		}
		__fpurge(stdin);
	}while(c!=3);


}