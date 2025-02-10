#include <stdio.h>

int main(){
	float nota1,nota2,media,faltas,trabalho;
	printf("\n\nDigite a primeira nota:\n\n");
	scanf("%f",&nota1);

	printf("\n\nDigite a segunda nota:\n\n");
	scanf("%f",&nota2);

	printf("\n\nDigite a nota do trabalho:\n\n");
	scanf("%f",&trabalho);

	printf("\n\nDigite a quantidade de faltas:\n\n");
	scanf("%f",&faltas);

	media=(3*nota1+5*nota2+trabalho*2)/10;
	if(faltas >15){
	
	printf("\n\nO aluno foi reprovado\n\n");
}
	if(media >=6){
	printf("\n\nO aluno foi aprovado\n\n");
}
else
	printf("\n\nO aluno tera que fazer a prova final\n\n");
	return 0;
}
