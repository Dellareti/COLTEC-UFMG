#include<stdio.h>

int main(){

	int pagamento;

	printf("\n\n1: a vista\n\n");

	printf("\n\n2: cheque\n\n ");

	printf("\n\n3:em duas vezes\n\n");

	printf("\n\n4:em tres vezes\n\n");	

	printf("\n\ndigite o numero de forma de pagamento \n\n");

	scanf("%d",&pagamento);

	switch(pagamento){

	case 1:
		printf("\n\n desconto de 20 porcento\n\n");
		break;

	case 2:
		printf("\n\n mesmo preco a vista \n\n");
		break;
	
	case 3:
		printf("\n\n mesmo preco a vista\n\n");
		break;

	case 4:
		printf("\n\n juros de 3 por cento ao mes\n\n");
		break;

	default:
		printf("numero invalido");
	}

	return 0;
}
