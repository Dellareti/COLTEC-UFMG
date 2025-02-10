#include "gerente.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct c {
	char nome[50];
	float saldo;
	float limite;
	char data[10];
	char conta[30];
	int senha;
} clientes;

typedef struct l{
	char linha[80];
} linhas;

typedef struct d{
	char diaC[3];
	char mesC[3];
	char anoC[5];
	int dia;
	int mes;
	int ano;
} datas;


 
	void Criptografar(char entrada[100]){

    FILE *inFile = fopen(entrada, "r");
    FILE *outFile = fopen("tmp.txt", "w+");
      
      if( inFile == NULL ){

        printf("\n\n ERRO ! : Problema em abrir.\n\n");
    }
    
		char c;
    
    	while( fscanf( inFile," %c ", &c ) !=EOF){

		if (c%2 == 0)	fprintf( outFile ," %c ", c+2); //criptografia
	
		else		fprintf(outFile,"%c", c+4);
    
    }

    fclose(inFile);
    fclose(outFile);
    remove(entrada);
    
    //   possibilidade de voce remover um file depois
    
    if( rename("tmp.txt",entrada) == -1){

        printf("\n\n ERRO ! : Problema em tentativa de renomear. \n\n");
    }
}

		void Descriptografar(char entrada[100]){

    	FILE *inFile = fopen(entrada, "r");
    	FILE *outFile = fopen("tmp.txt", "w+");
      
      		if( inFile == NULL ){

        printf("\n\n ERRO ! : Problema em tentativa de abrir. \n\n");
    }
    
    char c;
    
    while( fscanf(inFile," %c ",&c) !=EOF){

        if (c%2 == 0)	fprintf(outFile," %c ", c-2); //criptografia
	
		else		fprintf(outFile,"%c", c-4); //descriptografia
    
	}
    
    	fclose(inFile);
    	fclose(outFile);
    	remove(entrada);
    // possibilidade de voce remover um file depois
    
    	if( rename("tmp.txt",entrada) == -1){

        printf("\n\n ERRO ! : Problema em tentativa de renomear. \n\n");
    }
}



//funçao que retorna o número de digitos

		int digitos(int n, int numero){

		if(n/10 != 0){
			n=n/10;
		
			return digitos(n, numero +1);
       }
	
			else return numero;
    }

		//funcao para conferir se caractere corresponde a um numero
		int isnum(char n){


		if(n =='0' || n =='1' || n =='2' || n =='3' || n =='4' || n =='5' || n =='6' || n =='7' || n =='8' || n =='9') return 1;
		else return 0;
	}

//conferir se data é valida
	
		int isData(char data[10]){
	
		if(data[2]!= '/' || data[5]!='/' || isnum(data[0]) == 0 || isnum(data[1]) == 0 || isnum(data[3]) == 0 || isnum(data[4]) == 0 || isnum(data[6]) == 0 || isnum(data[7]) == 0 || isnum(data[8]) == 0 || isnum(data[9]) == 0 || strlen(data)!=10 || data[0]>'3' || (data[0]=='3' && data[1]>'1') || data[3]>'1' || (data[3]=='1' && data[4]>'2') || (data[3]=='0' && data[4]=='0')) return 0;
		else return 1;
}

//numero de contas
		int numeroContas(){
		FILE *login;
		
		int numContas=0;
		char pular[100];
		
		login=fopen("login.txt", "r");
		
		fseek(login, 40, SEEK_SET);
		
			while(!feof(login)){

		fseek(login, 1, SEEK_CUR);
		fscanf(login, "%s", pular);
		
		if(pular[strlen(pular)-1] =='*') numContas--;
		
		fseek(login, 1, SEEK_CUR);
		fgets(pular, 100, login);
		numContas++;
	}
	
	return numContas-1;
}

		void CriarConta(){
		
		Descriptografar("login.txt");
		
		int numero=1, i, cont=0, numConta, cont2=0; //para funçao que retorna numero de digitos
		
		FILE *arquivo;
		FILE *login;
		clientes cliente;
		
		char existente[30], pular[100];
		system("clear");
		
		printf("\n\n Por favor digite o nome do cliente : \n\n");
		scanf(" %[^\n]s", cliente.nome);
		
		login=fopen("login.txt", "r");
		
		while(1){
		
			cont=0;
			
			printf("\n\n Por favor  digite o numero da conta do cliente : \n\n");
			getchar();
			scanf("%s", cliente.conta);
			
			cont2=0;
				
				for(i = 0; i < strlen(cliente.conta) ;i++){
					if(isnum(cliente.conta[i]) == 0){
					
					printf("\n\n ERRO ! : O  numero digitado e invalido.\n\n");
					cont++;
					cont2++;
					break;
				}
			}
		
						if(cont==0){
						fseek(login, 40, SEEK_SET);
						
						while(!feof(login)){
						
						fseek(login, 1, SEEK_CUR);
						fscanf(login, "%s", existente);
						
							if(strcmp(cliente.conta, existente) == 0){
				
							printf("\n\n ERRO ! : O numero  digitado ja esta  cadastrado.\n\n");
							cont2++;
							break;
					}
							else{
							fseek(login, 1, SEEK_CUR);
							fgets(pular, 100, login);
							cont2=0;
						}
					}
				}
							if(cont2 == 0) break;	
			}
	
							fclose(login);
							
							Criptografar("login.txt");
							
							numConta = atoi(cliente.conta);
							
							strcat(cliente.conta, ".txt");
							arquivo = fopen(cliente.conta, "a+");
							
							while(1){
							
								printf("\n\n Digite a senha da conta deste cliente (mínimo de 8 dígitos que não inicie com '0') :  \n\n");
								scanf("%d", &cliente.senha);
							
									if(digitos(cliente.senha, numero)<8){
									printf("\n\n Número de dígitos insuficiente\n");
								}
							
									else if(cliente.senha<0) printf("\n\n Número inválido\n");
									else break;
							}
							
							while(1){
								printf("\n\n Insira o saldo inicial do cliente:\n\n ");
								scanf("%f", &cliente.saldo);
							
								if(cliente.saldo<0) printf("\n\n Número inválido\n");
								else break;
						}
							while(1){
		
							printf("\n\n Digite  o limite do cliente: ");
							scanf("%f", &cliente.limite);
							if(cliente.limite<0) printf("\n\n Valor inválido\n");
							else break;
	}
	while(1){
		printf("\n\n Digite a data de hoje (dd/mm/aaaa): \n\n ");
		scanf("%s", cliente.data);
		if(isData(cliente.data)==0) printf("Data inválida\n");
		else break;
	}
	fprintf(arquivo, "Nome do cliente: %s\nSaldo: %.2f\nLimite de transferência: %.2f\nData de cadastro: %s", cliente.nome, cliente.saldo, cliente.limite, cliente.data);
	fclose(arquivo);
	Descriptografar("login.txt");
	login=fopen("login.txt", "a+");
	fprintf(login, "\n%d\n%d\n", numConta, cliente.senha);
	fclose(login);
	Criptografar("login.txt");
	printf("\n\n Seu cliente cadastrado com sucesso!!!\n\n");
	system("sleep 2s");
	system("clear");
}

void ExcluirConta(){
	Descriptografar("login.txt");
	char conta[30], confConta[30], pular[100];
	char excluir[40]="rm ";
	int cont=0, i, cont2=0;
	FILE *login;
	login=fopen("login.txt", "r+");
	while(cont2==0){
		printf("\n\n Digite o número da conta que deseja excluir: \n\n");
		scanf("%s", conta);
		for(i=0;i<strlen(conta);i++){
			if(isnum(conta[i])==0){
				printf("\n\n Numero invalido\n");
				cont2=0;
				break;
			}
			else cont2=1;
		}
	}
	fseek(login, 40, SEEK_SET);
	while(!feof(login)){
		fseek(login, 1, SEEK_CUR);
		fscanf(login, "%s", confConta);				
		if(strcmp(conta, confConta)==0){
			fprintf(login, "*\n");
			cont=1;
			break;
		}
		else{
			fseek(login, 1, SEEK_CUR);
			fgets(pular, 100, login);
		}
	}
	if(cont==1){
		strcat(excluir, conta);
		strcat(excluir, ".txt");
		system(excluir);
		fseek(login, 39, SEEK_SET);
		printf("\n\n Seu cliente excluído com sucesso!!!\n\n");
		system("sleep 1s");
	}
	else printf("\n\n Número de conta não encontrado\n");

	fclose (login);
	Criptografar("login.txt");

	system("sleep 1s");
	system("clear");
}

void AlterarLimites(){
	Descriptografar("login.txt");
	int cont=0, i, x=0, numLinhas=0;
	char conta[30], confConta[30], pular[100];
	float limite;
	clientes cliente;
	FILE *login;
	FILE *arqCliente;
	login=fopen("login.txt", "r");
	while(x==0){
		printf("\n\n Digite o numero da conta que deseja alterar: \n\n ");
		scanf("%s", conta);
		for(i=0;i<strlen(conta);i++){
			if(isnum(conta[i])==0){
				printf("\n\n Número inválido\n");
				x=0;
				break;
			}
			else x=1;
		}
	}
	fseek(login, 40, SEEK_SET);
	while(!feof(login)){
		fseek(login, 1, SEEK_CUR);
		fscanf(login, "%s", confConta);
		if(strcmp(conta, confConta)==0){
			cont++;
			break;
		}
		else{
			fseek(login, 1, SEEK_CUR);
			fgets(pular, 100, login);
		}
	}
	fclose(login);
	Criptografar("login.txt");

	if(cont==0) printf("\n\n Numero não cadastrado\n");
	else{
		while(1){
			printf("\n\n Por favor digite o novo limite do cliente: \n\n ");
			scanf("%f", &limite);
			if(limite<0) printf("\n\n Numero inválido\n");
			else break;
		}
		strcat(conta, ".txt");
		arqCliente=fopen(conta, "r");
		if(!arqCliente){
			printf("\n\n Arquivo com as informações do cliente não encontrado\n");
			fclose(arqCliente);
		}
		else {
			fseek(arqCliente, 17, SEEK_SET);
			fscanf(arqCliente, " %[^\n]s", cliente.nome);
			fseek(arqCliente, 8, SEEK_CUR);
			fscanf(arqCliente, "%f", &cliente.saldo);
			fseek(arqCliente, 26, SEEK_CUR);
			fscanf(arqCliente, "%f", &cliente.limite);
			fseek(arqCliente, 19, SEEK_CUR);
			fscanf(arqCliente, "%s", cliente.data);
			fclose(arqCliente);
			arqCliente=fopen(conta, "w");
			fprintf(arqCliente, "Nome do cliente: %s\nSaldo: %.2f\nLimite de transferência: %.2f\nData de cadastro: %s", cliente.nome, cliente.saldo, limite, cliente.data);
			fclose(arqCliente);
			printf("\n\n Seu limite alterado com sucesso!!!\n\n");
		}
	}
	system("sleep 2s");
	system("clear");				
}
	
void ListarReservas(){
	Descriptografar("login.txt");
	FILE *login;
	FILE *contas;
	char pular[100];
	float reservas=0;
	clientes *vetor;
	int numContas, i, controle=0;
	login=fopen("login.txt", "r");
	fseek(login, 40, SEEK_SET);
	numContas=numeroContas();
	vetor=(clientes *)malloc(numContas*sizeof(clientes));
	fseek(login, 40, SEEK_SET);
	for(i=0;i<numContas;i++){
		fseek(login, 1, SEEK_CUR);
		fscanf(login, "%s", pular);
		if(pular[strlen(pular)-1]=='*') i--;
		else{
			strcat(vetor[i].conta, pular);
			strcat(vetor[i].conta, ".txt");
		}
		fseek(login, 1, SEEK_CUR);
		fgets(pular, 100, login);
	}
	fclose(login);
	Criptografar("login.txt");
	
	if(numContas>0){
		for(i=0;i<numContas;i++){
			contas=fopen(vetor[i].conta, "r");
			if(!contas){
				printf("\n\n Arquivos com as informações dos clientes não encontrados\n");
				controle=1;
				break;
			}
			fseek(contas, 17, SEEK_SET);
			fscanf(contas, " %[^\n]s", vetor[i].nome);
			fseek(contas, 8, SEEK_CUR);
			fscanf(contas, "%f", &vetor[i].saldo);
			reservas+=vetor[i].saldo;
			fclose(contas);
		}
	}
	free(vetor);
	if(controle==0)	printf("\n\n Total de reservas bancárias: R$%.2f \n\n", reservas);
	system("sleep 3s");
	system("clear");
}

void ListarClientes(){

	Descriptografar("login.txt");
	FILE *login;
	FILE *contas;
	clientes *vetor;
	clientes aux;
	char pular[80];
	int numContas, i, j, k, controle=0;;
	login=fopen("login.txt", "r");
	fseek(login, 40, SEEK_SET);
	numContas=numeroContas();
	if(numContas==0){
		printf("\n\n Nenhum cliente cadastrado\n");
		system("sleep 2s");
		system("clear");
	}
	else{
		vetor=(clientes *)malloc(numContas*sizeof(clientes));
		for(i=0;i<numContas;i++){
			fseek(login, 1, SEEK_CUR);
			fscanf(login, "%s", pular);
			if(pular[strlen(pular)-1]=='*') i--;
			else{
				strcat(vetor[i].conta, pular);
				strcat(vetor[i].conta, ".txt");
			}
			fseek(login, 1, SEEK_CUR);
			fgets(pular, 100, login);
		}
		fclose(login);
		Criptografar("login.txt");

		for(i=0;i<numContas;i++){
			contas=fopen(vetor[i].conta, "r");
			if(!contas){
				printf("\n\n Arquivos com as informações dos clientes não encontrados\n");
				controle=1;
				break;
			}
			fseek(contas, 17, SEEK_SET);
			fscanf(contas, " %[^\n]s", vetor[i].nome);
			fseek(contas, 8, SEEK_CUR);
			fscanf(contas, "%f", &vetor[i].saldo);
			fseek(contas, 26, SEEK_CUR);
			fscanf(contas, "%f", &vetor[i].limite);
			fseek(contas, 19, SEEK_CUR);
			fscanf(contas, "%s", vetor[i].data);
			fclose(contas);
		}
		if(controle==0){
			for(i=0;i<=(numContas-2);i++){       
		   		for(j=(numContas-1);j>i;j--){
					for(k=0;k<strlen(vetor[j].nome);k++){
			      			if(vetor[j].nome[k]<vetor[j-1].nome[k]){ 
							aux=vetor[j];
							vetor[j]=vetor[j-1];
							vetor[j-1]=aux;	
							break;
						}
						else if(vetor[j].nome[k]>vetor[j-1].nome[k]) break;
					}
		      		}
		    	}
			for(i=0;i<numContas;i++){
				printf("\nCliente %d:\n\tNome: %s\n\tSaldo: %.2f\n\tLimite: %.2f\n\tData de criação: %s\n\n", i+1, vetor[i].nome, vetor[i].saldo, vetor[i].limite, vetor[i].data);
			}
		}
		else{
			system("sleep 2s");
			system("clear");
		}
	}
	if(numContas!=0){
		free(vetor);
	}
}
void ListarClientesData(){
	Descriptografar("login.txt");
	FILE *login;
	FILE *contas;
	clientes *vetor;
	clientes aux;
	datas *data;
	datas auxD;
	char pular[80];
	int numContas, i, j, controle=0;
	login=fopen("login.txt", "r");
	fseek(login, 40, SEEK_SET);
	numContas=numeroContas();
	if(numContas==0){
		printf("\n\n Nenhum cliente cadastrado\n\n");
		system("sleep 2s");
		system("clear");
	}
	else{
		vetor=(clientes *)malloc(numContas*sizeof(clientes));
		data=(datas *)malloc(numContas*sizeof(datas));
		for(i=0;i<numContas;i++){
			fseek(login, 1, SEEK_CUR);
			fscanf(login, "%s", pular);
			if(pular[strlen(pular)-1]=='*') i--;
			else{
				strcat(vetor[i].conta, pular);
				strcat(vetor[i].conta, ".txt");
			}
			fseek(login, 1, SEEK_CUR);
			fgets(pular, 100, login);
		}
		fclose(login);
		Criptografar("login.txt");

		for(i=0;i<numContas;i++){
			contas=fopen(vetor[i].conta, "r");
			if(!contas){
				printf("\n\n Arquivos com as informações dos clientes não encontrados\n\n");
				controle=1;
				break;
			}
			fseek(contas, 17, SEEK_SET);
			fscanf(contas, " %[^\n]s", vetor[i].nome);
			fseek(contas, 8, SEEK_CUR);
			fscanf(contas, "%f", &vetor[i].saldo);
			fseek(contas, 26, SEEK_CUR);
			fscanf(contas, "%f", &vetor[i].limite);
			fseek(contas, 19, SEEK_CUR);
			fscanf(contas, "%s", vetor[i].data);
			fclose(contas);
		}
		if(controle==0){
			for(i=0;i<numContas;i++){ //transforma a data em números
				data[i].diaC[0] = vetor[i].data[0];
				data[i].diaC[1] = vetor[i].data[1];
				data[i].diaC[2] = '\0';
				data[i].mesC[0] = vetor[i].data[3];
				data[i].mesC[1] = vetor[i].data[4];
				data[i].mesC[2] = '\0';
				data[i].anoC[0] = vetor[i].data[6];
				data[i].anoC[1] = vetor[i].data[7];
				data[i].anoC[2] = vetor[i].data[8];
				data[i].anoC[3] = vetor[i].data[9];
				data[i].anoC[4] = '\0';
				data[i].dia=atoi(data[i].diaC);
				data[i].mes=atoi(data[i].mesC);
				data[i].ano=atoi(data[i].anoC);
			}
			for(i=0;i<=(numContas-2);i++){       
		   		for(j=(numContas-1);j>i;j--){
		      			if(data[j].ano<data[j-1].ano){        
						aux=vetor[j];
						vetor[j]=vetor[j-1];
						vetor[j-1]=aux;
						auxD=data[j];
						data[j]=data[j-1];
						data[j-1]=auxD;
					}
					else if(data[j].ano==data[j-1].ano){
						if(data[j].mes<data[j-1].mes){
							aux=vetor[j];
							vetor[j]=vetor[j-1];
							vetor[j-1]=aux;
							auxD=data[j];
							data[j]=data[j-1];
							data[j-1]=auxD;
						}
						else if(data[j].mes==data[j-1].mes){
							if(data[j].dia<data[j-1].dia){
								aux=vetor[j];
								vetor[j]=vetor[j-1];
								vetor[j-1]=aux;
								auxD=data[j];
								data[j]=data[j-1];
								data[j-1]=auxD;
							}
						}
		      			}
		    		}
			}
			for(i=0;i<numContas;i++){
				printf("\nCliente %d:\n\tNome: %s\n\tSaldo: %.2f\n\tLimite: %.2f\n\tData de criação: %s\n\n", i+1, vetor[i].nome, vetor[i].saldo, vetor[i].limite, vetor[i].data);
			}
		}
		else{
			system("sleep 2s");
			system("clear");
		}
	}
	if(numContas!=0){
		free(vetor);
		free(data);
	}

}
}
