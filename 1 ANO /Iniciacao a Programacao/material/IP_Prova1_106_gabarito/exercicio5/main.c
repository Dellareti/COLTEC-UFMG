#include <stdio.h>

int main(){
	char cont;
	do{
		float prova1, prova2, trab, falta, notaf;
		printf("\n\nDigite a nota da primeira prova(0 a 10): ");
		scanf("%f", &prova1);
	    printf("Digite a nota da segunda prova(0 a 10): ");
	    scanf("%f", &prova2);
	    printf("Digite a nota do trabalho(0 a 10): ");
	    scanf("%f", &trab);
	    printf("Digite quantas aulas voce faltou: ");
	    scanf("%f", &falta);
		notaf=(prova1*3.0 + prova2*5.0 + trab*2.0)/10.0;
		if(falta<15){
			if (notaf>=6.0) printf("\n\nAPROVADO\n\n\n\n");
			else printf("\n\nFARA A PROVA FINAL\n\n\n\n");
		}
		else{
			printf("\n\nREPROVADO\n\n\n\n");
		}
		fflush(stdin); //ou fpurge no linux
		printf("Tera um proximo aluno? s para sim,  n para nao: ");
		scanf("%c", &cont);
	}while(cont == 's');
}
