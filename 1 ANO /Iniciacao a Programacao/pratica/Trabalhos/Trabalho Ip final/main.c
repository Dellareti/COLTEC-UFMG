#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "gerente.h"
#include "cliente.h"

void menuGerente(){
  int x=1;
  while(x == 1){
    int opcao;
   
    printf("\t\t\t\tMENU GERENTE\n\n\nSelecione:\n\n(0) Sair\n(1) Criar conta\n(2) Excluir conta\n(3) Alterar limites de transferência\n(4) Listar clientes por ordem alfabética\n(5) Listar clientes por data de cadastro\n(6) Listar total de reservas bancárias\n");
    scanf("%d", &opcao);
   
    switch(opcao){
      case 0: x=2;
              break;
      case 1: CriarConta();
	      break;
      case 2: ExcluirConta();
              break;
      case 3: AlterarLimites();
              break;
      case 4: ListarClientes();
              break;
      case 5: ListarClientesData();
	      break;
      case 6: ListarReservas();
              break;
      default: printf("\n\n Opcao invalida !!!\n\n");
               menuGerente();
               break;
    }
  }
}

	void menuCliente(char numConta[]){
  	int x=1;
  	
  	while(x == 1){
    
    int opcao;
    
    printf("\t\t\t\tMENU CLIENTE\n\n\nSelecione:\n\n(0) Sair\n(1) Visualizar saldo\n(2) Depositar\n(3) Retirar\n(4) Realizar tranferência\n(5) Visualizar data de cadastro\n(6) Visualizar limite de tranferência\n(7) Visualizar extrato\n");
    scanf("%d", &opcao);
    
      switch(opcao){
      case 0: x = 2;
              break;

      case 1: VisualizarSaldo(numConta);
              break;

      case 2: Depositar(numConta);
              break;

      case 3: Retirar(numConta);
              break;

      case 4: Transferencia(numConta);
              break;

      case 5: VisualizarData(numConta);
              break;

      case 6: VisualizarLimite(numConta);
              break;

      case 7: VisualizarExtrato(numConta);
              break;

      default: menuCliente(numConta);
               break;
    }
  }
}

		int main(){
  		Criptografar("login.txt");
 		
 		 FILE *login;
  		char numConta[100], matriculaG[100], confMatriculaG[100];
  		
  		int escolha, matricula, senha, confMatricula, confSenha, i=0, controle=0;
		Descriptografar("login.txt"); 
		
		  while(1){
	  	  Criptografar("login.txt");

	  	system("clear");
	  	printf("\t\t Bem Vindo ao Banco Simplificado da Y_SOLUTIONS \n\n ");
	  	printf("\n\n\n Selecione : \n\n");
	  
	  	printf("\n\n (1) Entrar como gerente \n\n(2) Entrar como cliente \n\n(3) Sobre \n\n(4) Sair \n\n");
	  	scanf("%d", &escolha);

	  	if(escolha == 1){
	    	
	    	
	    	printf(" Matricula : ");
	    	scanf("%s", matriculaG);
	    	
	    	printf("Senha: ");
	    	scanf("%d", &senha);
	    	
	    	login = fopen("login.txt", "r");
	    	
	    	if(!login){
	      	
	      	printf("\n\n ERRO ! : Arquivo com as informações de login nao encontrado.\n\n");
	      	system("sleep 2s");
	      	exit(0);
            
              Criptografar("login.txt");
	    	}
	    	fseek(login, 9, SEEK_CUR);
	    	fscanf(login, "%s", confMatriculaG);
	    	fseek(login, 8, SEEK_CUR);
	    	fscanf(login, "%d", &confSenha);
	    	
	    		if((strcmp(confMatriculaG, matriculaG) == 0) && confSenha == senha){
	      		printf("\n\n Acesso permitido \n\n");
	      	
	      		system("sleep 2s");
	      		system("clear");
	     	
	     		Criptografar("login.txt");
	      		menuGerente();
	    	}
	    
	    		else{
	      		printf("\n\n ERRO ! : Acesso negado \n\n");
	      		system("sleep 2s");
	      		
	      		fclose(login);
	      		Criptografar("login.txt");
	      	}
	   	}

	  			else if(escolha==2){
	    		
	    		Descriptografar("login.txt");
	    		
	    		printf("\n\n Por vavor digite o numero da conta : \n\n");
	    		scanf("%s", numConta);
	    		
	    		printf("\n\n Por favor digite a senha :  \n\n");
	    		scanf("%d", &senha);
	    		
	    		matricula = atoi(numConta);
	    			strcat(numConta, ".txt");
	   				 login = fopen("login.txt", "r");
	  			
	  				  if(!login){
	    				 
	    				 printf("\n\n ERRO ! : Arquivo com as informações de login nao encontrado \n\n");
	     				 system("sleep 2s");
	     				 
	     				 fclose(login);
	    				 Criptografar("login.txt");
	     				 exit(0);
	   			 }
	   
	    			fseek(login, 39, SEEK_SET);
	   
	    		while(!feof(login)){
				
				fseek(login, 2, SEEK_CUR);
				fscanf(login, "%d", &confMatricula);
				fseek(login, 1, SEEK_CUR);
		
				if(confMatricula==matricula){
				fscanf(login, "%d", &confSenha);
			
				if(confSenha==senha){
				printf("\n\n Acesso permitido \n\n Seja bem vindo \n\n");
				system("sleep 2s");
				system("clear");
				
				fclose(login);
				Criptografar("login.txt");
				menuCliente(numConta);
			}
			
			else{
				
				printf("\n\n ERRO ! : Acesso negado \n\n");
				system("sleep 2s");
				system("clear");
				fclose(login);
				Criptografar("login.txt");				
			}
			
			controle = 1;
			break;
	   	}
	    	else{
			fscanf(login, "%d", &confSenha); //mudar o cursor para o final da linha
	  	}
	    }
	    if(controle==0){
		printf("\n\n ERRO ! : Numero de conta nao cadastrado \n\n");
	  	system("sleep 2s");
		system("clear");
		fclose(login);
		Criptografar("login.txt");
	    }
	}
	
	  else if(escolha == 3){
		system("clear");
		
		printf("\t\t\t\t Sobre \n\n Desenvolvido por : \t Italo Dell`Areti \n\t\t\t\n\n Turma : \t\t\t 106 \n\n Professora : \t\t Virginia \n\n Disciplina : \t\t Introdução a Programação \n\n Ano : \t\t\t 2015 \n\n");
		system("sleep 10s");
	  }

	  else if(escolha == 4) exit(0);
	  else{
	    
	    printf("\n\n Esta opção e invalida \n\n");
	    system("sleep 1s"); 
	  }
	
	Descriptografar("login.txt");
  }
  return 0;
}
}
