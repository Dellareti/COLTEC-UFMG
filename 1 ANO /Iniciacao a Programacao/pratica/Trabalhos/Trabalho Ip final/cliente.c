#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "cliente.h"

typedef struct c 
{
	char nome[50];
	float saldo;
	float limite;
	char data[10];
} clientes;


		void VisualizarSaldo (char numConta[]){
		system("sleep 1s");
		system("clear");

		int aux=0;
		float saldo;

		FILE *arquivo;

		arquivo = fopen (numConta, "r");
		if (!arquivo){

		printf ("\n\n ERRO ! : Este cliente nao existe,por favor tente novamente. \n\n");
		aux = 1;	//variável auxiliar que confere se o arquivo foi aberto
		
		system ("sleep 1s");
		system ("clear");
	}

		if (aux == 0){

		char linha[80];

		fgets (linha, 80, arquivo);	//lê a primeira linha

		fseek(arquivo, 7, SEEK_CUR);	//anda com o cursor
		fscanf (arquivo, "%f", &saldo);		//lê o saldo

		printf ("\n\n Seu saldo e : R$%.2f \n\n", saldo);
		fclose (arquivo);	
	
		system("sleep 3s");
		system("clear");
	}
}

		void Depositar (char numConta[]){

		system("sleep 1s");
		system("clear");

		int aux=0;
		float dinheiro;
		float saldo;
		float limite;
		clientes c1;	
	
		FILE *arquivo;

		arquivo = fopen (numConta, "r");
		
		if (!arquivo) { //confere se o arquivo com numConta existe 

		printf ("\n\n ERRO !: Este cliente nao existe ,por favor tente novamente. \n\n");
		aux=1;
		
		system ("sleep 1s");
		system ("clear");
	}

	if (aux==0)
	{
		char linha[80]; 

		fgets (linha, 80, arquivo);	//lê a primeira linha

		fseek(arquivo, 7, SEEK_CUR);
		fscanf (arquivo, "%f", &saldo);		//lê e armazena o saldo

		printf ("\n\n Por favor digite a quantia que deseja depositar :  \n\n");
		scanf ("%f", &dinheiro);

		while (dinheiro < 0){ //loop até o usuário digitar uma quantia válida
		
			printf ("\n\n ERRO ! : Esta quantia e invalida. \n\n");
			printf ("\n\n Por favor digite a quantia  que deseja depositar : \n\n");
			scanf ("%f", &dinheiro);
		}

		//lê informações do cliente em questão
		fseek (arquivo, 17, SEEK_SET);
		fscanf (arquivo, " %[^\n]s", c1.nome);
	
		fseek (arquivo, 8, SEEK_CUR);
		fscanf (arquivo, "%f", &c1.saldo);
	
		fseek (arquivo, 26, SEEK_CUR);
		fscanf (arquivo, "%f", &c1.limite);
	
		fseek (arquivo, 19, SEEK_CUR);
		fscanf (arquivo, "%s", c1.data);
	
		fclose (arquivo);
	
		arquivo=fopen(numConta, "w");	//Exclui todo arquivo
		if (!arquivo){

			printf ("\n\n ERRO ! : Este arquivo nao existe. \n\n");
			aux=1;
			system ("sleep 1s");
			system ("clear");
		}

		if (aux == 0){

			saldo+=dinheiro;	
			fprintf (arquivo, "\n\n Nome do Cliente : %s \n\n Saldo : %.2f \n\n Limite de transferencia : %.2f \n\n Data de cadastro : %s \n\n", c1.nome, saldo, c1.limite, c1.data);	//Reescreve o arquivo
		
			fclose (arquivo);	

			printf ("\n\n Seu deposito foi realizado com sucesso !!! \n\n");

			FILE *extrato;
	
			char extratoArquivo[100]; //armazena numConta 

			strcpy (extratoArquivo, numConta);
			strcat (extratoArquivo, ".extrato");  //concartena extratoArquivo com .extrato

			extrato = fopen (extratoArquivo, "a+");	  //cria, caso não existir, um arquivo extrato para este cliente (.txt.extrato)
			if (!extrato){

				printf ("\n\n ERRO ! : Este extrato  nao existe. \n\n");
				aux = 1;
				
				system ("sleep 1s");
				system ("clear");
			}
			
			if (aux==0)	{

				char dataSistema[80]=__DATE__;  //data do sistema
				char horaSistema[80]=__TIME__;  //hora do sistema

				fprintf (extrato, "\n\n %s	%s	Depósito :	R$%.2f; \n\n", dataSistema, horaSistema, dinheiro);
				fclose (extrato);

				system("sleep 2s");
				system("clear");
			}
		}
	}
}

	void Retirar(char numConta[])
{
	system("sleep 1s");
	system("clear");

	int aux=0;
	float dinheiro;
	float saldo;
	float limite;
	clientes c1;	
	
	FILE *arquivo;

	arquivo = fopen (numConta, "r");
	if (!arquivo){

		printf ("\n\n ERRO ! : Este cliente nao existe. \n\n");
		aux = 1;
		
		system ("sleep 1s");
		system ("clear");
	}

	if (aux == 0){

		char linha[80]; 

		fgets (linha, 80, arquivo);

		fseek(arquivo, 7, SEEK_CUR);
		fscanf (arquivo, "%f", &saldo);

		printf ("\n\n Por favor digite a quantia que  se deseja retirar :  \n\n");
		scanf ("%f", &dinheiro);
	
		while (dinheiro < 0){

			printf ("\n\n ERRO ! : Esta quantia e invalida \n\n");
			
			printf ("\n\n Por favor digite a quantia que  se deseja retirar : \n\n");
			scanf ("%f", &dinheiro);
		}

		if (dinheiro <= saldo){	 //garante que o saldo seja sempre positivo
				
			fseek(arquivo, 17, SEEK_SET);
			fscanf(arquivo, " %[^\n]s", c1.nome);

			fseek(arquivo, 8, SEEK_CUR);
			fscanf(arquivo, "%f", &c1.saldo);
		
			fseek(arquivo, 26, SEEK_CUR);
			fscanf(arquivo, "%f", &c1.limite);
	
			fseek(arquivo, 19, SEEK_CUR);
			fscanf(arquivo, "%s", c1.data);
		
			fclose(arquivo);
	
			arquivo=fopen(numConta, "w");
		
			if (!arquivo){

				printf ("\n\n ERRO ! : Este arquivo nao existe .\n\n");
				aux = 1;
				
				system ("sleep 1s");
				system ("clear");
			}

			if (aux == 0){

				saldo-=dinheiro;
				fprintf(arquivo, "\n\n Nome do Cliente: %s \n\n Saldo : %.2f \n\n Limite de transferência : %.2f \n\n Data de cadastro : %s \n\n", c1.nome, saldo, c1.limite, c1.data);

				fclose(arquivo);

				printf ("\n\n Seu saque foi realizado com sucesso !!! \n\n");

				FILE *extrato;
			
				char extratoArquivo[100];
	
				strcpy (extratoArquivo, numConta);
				strcat (extratoArquivo, ".extrato");

				extrato = fopen (extratoArquivo, "a+");		
				if (!extrato){

					printf ("\n\n ERRO ! : Este extrato nao existe.\n\n");
					aux = 1;
					
					system ("sleep 1s");
					system ("clear");
				}
			
				if (aux == 0){

					char dataSistema[80]=__DATE__;
					char horaSistema[80]=__TIME__;

					fprintf (extrato, " \n\n %s 	%s	Saque:		R$%.2f;\n\n", dataSistema, horaSistema, dinheiro);
					fclose (extrato);

					system("sleep 2s");
					system("clear");	
				}
			}
		}
		
				else if (dinheiro > saldo){

				printf ("\n\n Seu saldo e insuficiente. \n\n");
		
				system("sleep 2s");
				system("clear");
			}
		}
	}

	void Transferencia(char numConta[]) {

		system("sleep 1s");
		system("clear");

		int aux=0;
		float dinheiro;
		float saldo, saldo2;
		float limite, limite2;
		char nome[100], nome2[100], data[10], data2[10];	
		char conta[20];
		clientes c2;

		FILE *arquivo;
		FILE *arquivo2;

		arquivo = fopen (numConta, "r");

				if (!arquivo){

				printf ("\n\n ERRO ! : O cliente digitado nao existe. \n\n");
				aux = 1;
				
				system ("sleep 1s");
				system ("clear");
	}

				if (aux == 0){

				//lê informações do cliente em questão
				fseek(arquivo, 17, SEEK_SET);
				fscanf(arquivo, " %[^\n]s", nome); 

				fseek(arquivo, 8, SEEK_CUR);	
				fscanf (arquivo, "%f", &saldo);

				fseek (arquivo, 26, SEEK_CUR);	
				fscanf (arquivo, "%f", &limite);

				fseek(arquivo, 19, SEEK_CUR);
				fscanf(arquivo, "%s", data);

				fclose (arquivo);

				printf ("\n\n Por favor digite o numero da conta que deseja transferencia :  \n\n");
				scanf ("%s", conta);
	 
				char num[100];
	
				strcpy (num, conta);  //copia conta para num para imprimir o número da conta sem .txt no arquivo extrato
				strcat (conta, ".txt");
	
				while (strcmp (numConta, conta) == 0){  //compara se o cliente está digitando o número da própria conta
		
				printf ("\n\n ERRO ! : Este numero invalido !!! \n\n");
				
				printf ("\n\n Por favor digite o numero da conta que deseja realizar a transferencia :  \n\n");
				scanf ("%s", conta);
	 
				strcpy (num, conta);
				strcat (conta, ".txt");
			}

				arquivo2 = fopen(conta, "r");  //abre o arquivo do número digitado depois de concatenar com .txt	
				
				if (!arquivo2) {

				printf ("\n\n ERRO ! : Esta conta nao foi encontrada. \n\n");
				aux =  1; //volta ao menu
				
				system ("sleep 1s");
				system ("clear");
			}	

				if (aux == 0){

				printf ("\n\n Por favor digite a quantia que deseja transferir : \n\n");
				scanf ("%f", &dinheiro);

				while (dinheiro < 0){

				printf ("\n\n ERRO ! : A quantia digitada e invalida. \n\n");
				
				printf ("\n\n  Por favor digite a quantia que deseja transferir:  \n\n");
				scanf ("%f", &dinheiro);
			}

				if (dinheiro > limite){

				printf ("\n\n ERRO ! : A quantia digitada esta  acima do limite.\n\n");
				
				system("sleep 2s");
				system("clear");
			}

				if (dinheiro > saldo){

				printf ("\n\n ERRO ! : O seu saldo e insuficiente.\n\n");
				
				system("sleep 2s");
				system("clear");
			}

				if (dinheiro<=limite){ //garante que a quantia desejada esteja dentro do limite estipulado para o cliente
				
					if (dinheiro<=saldo){

					//lê informações do cliente para o qual será realizado a transferência (arquivo 2)
					fseek(arquivo2, 17, SEEK_SET);
					fscanf(arquivo2, " %[^\n]s", nome2);
			
					fseek(arquivo2, 8, SEEK_CUR);
					fscanf(arquivo2, "%f", &saldo2);
		
					fseek(arquivo2, 26, SEEK_CUR);
					fscanf(arquivo2, "%f", &limite2);
			
					fseek(arquivo2, 19, SEEK_CUR);
					fscanf(arquivo2, "%s", data2);
		
					fclose (arquivo2);	
		
					arquivo=fopen(numConta, "w");	
					
					if (!arquivo){

						printf ("\n\n ERRO ! : O arquivo selecionado nao existe.\n\n");
						aux = 1;
						
						system ("sleep 1s");
						system ("clear");
					}

					if (aux == 0){

						saldo -= dinheiro;
						fprintf(arquivo, "\n\n Nome do Cliente :  %s \n\n Saldo : %.2f \n\n Limite de transferência : %.2f \n\n Data de cadastro : %s \n\n", nome, saldo, limite, data);  //reescreve o arquivo do cliente 1

						fclose(arquivo); 
		
						arquivo2=fopen (conta, "w");
						if (!arquivo2){

							printf ("\n\n ERRO ! : O arquivo selecionado nao existe.\n\n");
							aux = 1;
							
							system ("sleep 1s");
							system ("clear");
						}
						
						if (aux == 0){

							saldo2 += dinheiro;
		
							fprintf(arquivo2, "\n\n Nome do Cliente : %s \n\n Saldo : %.2f \n\n Limite de transferencia : %.2f \n\n Data de cadastro : %s \n\n", nome2, saldo2, limite2, data2);  //reescreve o arquivo do cliente 2

							fclose(arquivo2); 
		
							printf ("\n\n Sua transferencia foi realizada com sucesso !!! \n\n");

							FILE *extrato;
		
							char extratoArquivo[100];
	
							strcpy (extratoArquivo, numConta);
							strcat (extratoArquivo, ".extrato");
		
							extrato = fopen (extratoArquivo, "a+");		

						if (!extrato){

							printf ("\n\n ERRO ! : O arquivo  selecionado nao existe.\n\n");
							aux = 1;
						
							system ("sleep 1s");
							system ("clear");
							}

							if (aux == 0){
		
								char dataSistema[80]=__DATE__;
								char horaSistema[80]=__TIME__;

								fprintf (extrato, "\n\n %s  	%s	 Transferência :	 R$%.2f	   Conta :  %s; \n\n", dataSistema, horaSistema, dinheiro, num);

								fclose (extrato);

								system("sleep 2s");
								system("clear");
							}	
						}
					}
				}
			}
		}
	}
}
		
	void VisualizarData(char numConta[]){

		system("sleep 1s");
		system("clear");

		int aux = 0;
		char data[12];

		FILE *arquivo;

		arquivo = fopen (numConta, "r");

		if (!arquivo){

		printf ("\n\n ERRO ! : O arquivo selecionado nao existe.\n\n");
		aux = 1;
		
		system ("sleep 1s");
		system ("clear");
	}

		if (aux==0){

		char linha[80], linha2[80], linha3[80];

		fgets (linha, 80, arquivo); //lê a linha 1

		fgets (linha2, 80, arquivo); //lê a linha 2

		fgets (linha3, 80, arquivo); //lê a linha 3

		fseek (arquivo, 18, SEEK_CUR); 
		fscanf (arquivo, "%s", data);  //lê a data (linha 4)

		printf ("\n\n Data de cadastro :  %s \n\n", data);

		fclose (arquivo);

		system("sleep 3s");
		system("clear");
	}
}

	void VisualizarLimite(char numConta[]){

		system("sleep 1s");
		system("clear");

		int aux = 0;
		float limite;

		FILE *arquivo;
	
		
		arquivo = fopen (numConta, "r");
	
		if (!arquivo){

		printf ("\n\n ERRO ! : O arquivo selecionado nao existe.\n\n");
		aux = 1;
		
		system ("sleep 1s");
		system ("clear");
	}

		if (aux == 0){

		char linha[80], linha2[80]; 

		fgets (linha, 80, arquivo);

		fgets (linha2, 80, arquivo);

		fseek (arquivo, 25, SEEK_CUR);
		fscanf (arquivo, "%f", &limite);

		printf ("\n\n O seu limite Limite de transferencia e : R$%.2f \n\n", limite);
		fclose (arquivo);

		system("sleep 3s");
		system("clear");	
	}
}

	void VisualizarExtrato(char numConta[]){

		system("sleep 2s");
		system("clear");

		int aux = 0;
		FILE *extrato;

		char arquivo[100];

		strcpy (arquivo, numConta);
		strcat (arquivo, ".extrato");

		extrato = fopen (arquivo, "r");
		
		if (!extrato){

		printf ("\n\n ERRO ! : O arquivo selecionado nao existe.\n\n");
		aux=1;
		
		system ("sleep 1s");
		system ("clear");
	}

		if (aux == 0){

		char string[80];

		while (fscanf(extrato," %[^\n]s",string)!=EOF){  //percorre todo o arquivo extrato deste cliente e imprime as informações
		
		printf("\n\n  %s \n\n",string);
		
		}

		fclose (extrato);

		system("sleep 5s");
		system("clear");	
	}
}
