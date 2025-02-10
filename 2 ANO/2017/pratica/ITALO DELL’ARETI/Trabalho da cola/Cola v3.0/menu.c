#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include <termios.h>
#include <unistd.h>
#include "menu.h"

char getch(){
	char buf=0;
	struct termios old={0};
    __fpurge(stdout);
    if(tcgetattr(0, &old)<0)
        perror("tcsetattr()");
    old.c_lflag&=~ICANON;
    old.c_lflag&=~ECHO;
    old.c_cc[VMIN]=1;
    old.c_cc[VTIME]=0;
    if(tcsetattr(0, TCSANOW, &old)<0)
        perror("tcsetattr ICANON");
    if(read(0,&buf,1)<0)
        perror("read()");
    old.c_lflag|=ICANON;
    old.c_lflag|=ECHO;
    if(tcsetattr(0, TCSADRAIN, &old)<0)
        perror ("tcsetattr ~ICANON");
    printf("%c\n",buf);
    return buf;
}

void print_image(FILE *fptr) {
    char read_string[MAX_LEN];
 
    while(fgets(read_string,sizeof(read_string),fptr) != NULL)
        printf("%s",read_string);
}

void print_titulo(int opt){
	char *filename = "titulo.txt";
	FILE *fptr = fopen(filename,"r");

	print_image(fptr);

	fclose(fptr);

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
		//system("clear || cls");
		printf("\n\n\n\n\n\n");
		//system("clear || cls");
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
		case 2: printf ("\t\t\t\t\t\t\t\t>       Inserir Manualmente\n"
				"\t\t\t\t\t\t\t\t   	Inserir por .txt\n"
				"\t\t\t\t\t\t\t\t           Sair\n");
			break;
		case 1: printf ("\t\t\t\t\t\t\t\t        Inserir Manualmente\n"
				"\t\t\t\t\t\t\t\t>  	Inserir por .txt\n"
				"\t\t\t\t\t\t\t\t           Sair\n");
			break;
		case 0: printf ("\t\t\t\t\t\t\t\t        Inserir Manualmente\n"
				"\t\t\t\t\t\t\t\t   	Inserir por .txt\n"
				"\t\t\t\t\t\t\t\t>          Sair\n");
			break;
	}
}

void print_opt2(int opt) {
	system("clear || cls");

	printf(			"\t\t\t\t\t\t\t\t      Menuzao da Poraa\n\n");

	switch(opt){
		case 3: printf ("\t\t\t\t\t\t\t\t > Imprimir como ficará a sala\n"
				"\t\t\t\t\t\t\t\t       Aleatorio\n"
				"\t\t\t\t\t\t\t\t   	Inserir quem cola e quem não cola manualmente\n"
				"\t\t\t\t\t\t\t\t           Sair\n");
			break;
		case 2: printf ("\t\t\t\t\t\t\t\t Imprimir como ficará a sala\n"
				"\t\t\t\t\t\t\t\t>       Aleatorio\n"
				"\t\t\t\t\t\t\t\t   	Inserir quem cola e quem não cola manualmente\n"
				"\t\t\t\t\t\t\t\t           Sair\n");
			break;
		case 1: printf ("\t\t\t\t\t\t\t\t Imprimir como ficará a sala\n"
				"\t\t\t\t\t\t\t\t       Aleatorio\n"
				"\t\t\t\t\t\t\t\t>  	Inserir quem cola e quem não cola manualmente\n"
				"\t\t\t\t\t\t\t\t           Sair\n");
			break;
		case 0: printf ("\t\t\t\t\t\t\t\t Imprimir como ficará a sala\n"
				"\t\t\t\t\t\t\t\t       Aleatorio\n"
				"\t\t\t\t\t\t\t\t   	Inserir quem cola e quem não cola manualmente\n"
				"\t\t\t\t\t\t\t\t>           Sair\n");
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

int menu_final(int opt){
	char seta=1;

	while(seta!=10){						// Enter
		system("clear || cls");
		printf("\n\n");
		system("clear || cls");
		print_opt2(opt);
		seta=getch();

		if(seta==87 || seta==119){			// w ou W
			opt++;
			if(opt==4)
				opt=0;
		}

		else if(seta==83 || seta==115){		// s ou S
			opt--;
			if(opt==-1)
				opt=3;
		}
	}

	return opt;
}


