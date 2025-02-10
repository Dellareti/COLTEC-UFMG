#include <stdio.h>
#include <stdlib.h>
#include <termios.h>
#include <stdio_ext.h>
#include <unistd.h>
#include <ctype.h>
#include <time.h>
#include "menu.h"
#include "arquivo.h"

void main() {
	int op=2, op_menu=2, op_final, op_impressao, op_configuracoes, variavel_menu=0;
	
	//menu_print_imagem_ASCII(); //imagem tá muito grande

	menu_instrucoes();

	system("clear || cls");

	while(1) {
		op=menu_1(op);
		if (op==0) {
			op_menu=menu_op1(op_menu);

			if(op_menu==2){

				system ("clear || cls");

				int tam_sala=0;
				printf("Quantos alunos estão na sala para fazer a prova?");
				scanf("%d", &tam_sala);
				__fpurge(stdin);

				grafo *alunos=aloca_vetor(tam_sala);

				int **matriz=aloca_matriz(tam_sala);

				alunos=manual(alunos, tam_sala);

				op_final=menu_op2(op);

				if (op_final==2) {
					matriz = aleatoriamente(tam_sala, matriz);

					int m=1, k=0;
					system("clear || cls");
					graphColour(k, m, alunos, matriz, tam_sala);
					alunos=organizaTurma (alunos, tam_sala);

					variavel_menu=0;
					op_impressao=menu_opt_final(variavel_menu);

					if (op_impressao==2) {
						system("clear || cls");
						Imprimir_matriz(matriz, tam_sala);
						getch();
						system("clear || cls");
					} else if (op_impressao == 1) {
						system("clear || cls");
						Imprimir(alunos, tam_sala);

						getch();
						system("clear || cls");

					} else if (op_impressao == 0) { op_final=menu_op2(op); }

				}else if(op_final==1) {
					matriz=cria_ficha(alunos, tam_sala, matriz);

					int m=1, k=0;
					system("clear || cls");
					graphColour(k, m, alunos, matriz, tam_sala);
					alunos=organizaTurma (alunos, tam_sala);

					variavel_menu=0;
					op_impressao=menu_opt_final(variavel_menu);

					if (op_impressao==2) {
						system("clear || cls");
						Imprimir_matriz(matriz, tam_sala);
						getch();
						system("clear || cls");
					} else if (op_impressao == 1) {
						system("clear || cls");
						Imprimir(alunos, tam_sala);

						getch();
						system("clear || cls");

					} else if (op_impressao == 0) { op_final=menu_op2(op); }

				} else if(op_final==0) { op_menu=menu_op1(op_menu); }

			} else if(op_menu==1) {
				FILE *nomes;
				system ("clear || cls");

				int tam_sala;
				printf("Quantos alunos estão na sala para fazer a prova?");
				scanf("%d", &tam_sala);
				__fpurge(stdin);

				grafo *alunos=aloca_vetor(tam_sala);

				int **matriz=aloca_matriz(tam_sala);

				Inserir_Aresta(alunos, tam_sala, nomes);

				op_final=menu_op2(op);

				if (op_final==2) {
					matriz = aleatoriamente(tam_sala, matriz);

					int m=1, k=0;
					system("clear || cls");
					graphColour(k, m, alunos, matriz, tam_sala);
					alunos=organizaTurma (alunos, tam_sala);

					variavel_menu=0;
					op_impressao=menu_opt_final(variavel_menu);

					if (op_impressao==2) {
						system("clear || cls");
						Imprimir_matriz(matriz, tam_sala);
						getch();
						system("clear || cls");
					} else if (op_impressao == 1) {
						system("clear || cls");
						Imprimir(alunos, tam_sala);

						getch();
						system("clear || cls");

				} else if (op_impressao == 0) { op_final=menu_op2(op); }

				} else if(op_final==1){
					matriz=cria_ficha(alunos, tam_sala, matriz);

					int m=1, k=0;
					system("clear || cls");
					graphColour(k, m, alunos, matriz, tam_sala);
					alunos=organizaTurma (alunos, tam_sala);

					variavel_menu=0;
					op_impressao=menu_opt_final(variavel_menu);

					if (op_impressao==2) {
						system("clear || cls");
						Imprimir_matriz(matriz, tam_sala);
						getch();
						system("clear || cls");
					} else if (op_impressao == 1) {
						system("clear || cls");
						Imprimir(alunos, tam_sala);

						getch();
						system("clear || cls");
						
					} else if (op_impressao == 0) { op_final=menu_op2(op); }
				} else if(op_final==0) { op_menu=menu_op1(op_menu); }
			} else if(op_menu==0)
				op=menu_1(op);
		} else if (op==1) {
			variavel_menu=1;
			system("clear || cls");
			op_configuracoes=menu_configuracoes(variavel_menu);
			if (op_configuracoes==1) {
				system("firefox http://www.infinitelooper.com/?v=JtyByefOvgQ&p=n");
				system("clear || cls");
				getch();
			} else { op_menu=menu_op1(op_menu); }

		} else if (op==2) { system("killall -9 firefox");
			getch();
			system("clear || cls");
			menu_creditos();
			exit(0);
		} //Pensar nos exit(0);
	}
}