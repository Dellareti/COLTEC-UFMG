#include <stdio.h>
#include <stdlib.h>
#include <termios.h>
#include <unistd.h>

void print_titulo(int opt){
	//printf ("/n Frase motivacional do titulo XDXDXDXD"); --ASCII ART
	
	switch(opt){
		case 1: printf ("\t\t\t\t\t\t\t\t>  Iniciar\n"
						"\t\t\t\t\t\t\t\t     Sair\n");
			break;
		case 2: printf ("\t\t\t\t\t\t\t\t   Iniciar\n"
						"\t\t\t\t\t\t\t\t>    Sair\n");
			break;
	}
}

void menu_1(int opt){
	char seta;

	while(1){
		system("clear || cls");
		printf("\n");
		system("clear || cls");
		print_titulo(opt);
		seta=getch();
		if(seta==87 || seta==119){			// w ou W
			opt++;
			if(opt==3)
				opt=1;
		}
		else if(seta==83 || seta==115){		// s ou S
			opt--;
			if(opt==0)
				opt=2;
		}
		else if(seta==10){		// Enter
			if(opt==2){
				exit(0);
			}
			else{
				break;
			}
		}
	}
}

void print_opt(int opt){
	system("clear || cls");
	printf(			"\t\t\t\t\t\t\t\t             Menu:\n\n");
	switch(opt){
		case 2: printf ("\t\t\t\t\t\t\t\t>       Imprime Sala\n"
				"\t\t\t\t\t\t\t\t   Imprime Lista de Chamada\n"
				"\t\t\t\t\t\t\t\t           Sair\n");
			break;
		case 1: printf ("\t\t\t\t\t\t\t\t        Imprime Sala\n"
				"\t\t\t\t\t\t\t\t>  Imprime Lista de Chamada\n"
				"\t\t\t\t\t\t\t\t           Sair\n");
			break;
		case 0: printf ("\t\t\t\t\t\t\t\t        Imprime Sala\n"
				"\t\t\t\t\t\t\t\t   Imprime Lista de Chamada\n"
				"\t\t\t\t\t\t\t\t>          Sair\n");
			break;
	}
}
// parte da movimentação no teclado ws

int menu_2(int opt){
	char seta=1;

	while(seta!=10){						// Enter
		system("clear || cls");
		printf("\n\n");
		system("clear || cls");
		print_opt(opt);
		seta=getch();

		if(seta==87 || seta==119){			// w ou W
			opt++;
			if(opt==3)
				opt=0;
		}

		else if(seta==83 || seta==115){		// s ou S
			opt--;
			if(opt==-1)
				opt=2;
		}
	}

	return opt;
}

