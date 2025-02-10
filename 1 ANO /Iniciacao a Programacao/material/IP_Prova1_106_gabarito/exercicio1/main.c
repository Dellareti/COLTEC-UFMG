//Para que vocês possam ter mais exemplos, modifiquei a questão para ela mostrar o menu enquanto o usuário não seleciona a opção de saída
#include <stdio.h>

int main() {
	 int opcao;
	 do{
        printf("\n1. A vista.\n2. Cheque para trinta dias\n3. Em duas vezes\n4. Em tres vezes.\n0. Para sair. \nEntre com sua opcao: ");
        scanf("%d", &opcao);
        switch(opcao){
            case 1:printf("Desconto de 20%%\n\n");
                   break;
            case 2:printf("Mesmo preco a vista\n\n");
	 		       break;
            case 3:printf("Mesmo preco a vista\n\n");
	 		       break;
            case 4:printf("Juros de 3%% mes\n\n");
	 		       break;
            case 0:printf("Ateh a proxima!\n\n");
                   exit(0);
                   break;
            default:printf("Opção invalida\n\n");
	 		       break;
        }
     }while (opcao != 0);
	 return 0;
}
