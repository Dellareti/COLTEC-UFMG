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
	int op=1, op_menu=2, op_final, op_impressao, variavel_menu;

	FILE *fptr = fopen("titulo.txt","r");

	system("clear || cls");

	print_image(fptr);
	fclose(fptr);

	sleep(2);

	system("clear || cls");

	menu_1(op);

	op=2;
	while(1){

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

					variavel_menu=1;
					op_impressao=menu_opt_final(variavel_menu);

					system("clear || cls");
					if (op_impressao == 1) {
						int m=1, k=0;

						graphColour(k, m, alunos, matriz, tam_sala);
						alunos=organizaTurma (alunos, tam_sala);
						Imprimir(alunos, tam_sala);

						getch();
						system("clear || cls");
					} else if (op_impressao == 0) { op_final=menu_op2(op); }

				}else if(op_final==1){
					matriz=cria_ficha(alunos, tam_sala, matriz);

					system("clear || cls");

					op_impressao=menu_opt_final(variavel_menu);
					if (op_impressao == 1) {
						int m=1, k=0;

						Imprimir_matriz(matriz, tam_sala);

						graphColour(k, m, alunos, matriz, tam_sala);
						alunos=organizaTurma (alunos, tam_sala);
						Imprimir(alunos, tam_sala);

						getch();
						system("clear || cls");
					} else if (op_impressao == 0) { op_final=menu_op2(op); }

				} else if(op_final==0) { op_menu=menu_op1(op_menu); }
		}

		else if(op_menu==1){
				FILE *nomes;
				system ("clear || cls");

				int tam_sala=qtd_linhas(nomes);
				//função para ver buscar linhas no .txt

				grafo *alunos=aloca_vetor(tam_sala);

				int **matriz=aloca_matriz(tam_sala);

				Inserir_Aresta(alunos, tam_sala, nomes);

				op_final=menu_op2(op);

				if (op_final==2) {
					matriz = aleatoriamente(tam_sala, matriz);
					system("clear || cls");

					variavel_menu=1;
					op_impressao=menu_opt_final(variavel_menu);
					if (op_impressao == 1) {
						int m=1, k=0;

						graphColour(k, m, alunos, matriz, tam_sala);
						alunos=organizaTurma (alunos, tam_sala);
						Imprimir(alunos, tam_sala);

						getch();
						system("clear || cls");
					} else if (op_impressao == 0) { op_final=menu_op2(op); }

				}else if(op_final==1){
					matriz=cria_ficha(alunos, tam_sala, matriz);

					system("clear || cls");

					variavel_menu=1;
					op_impressao=menu_opt_final(variavel_menu);

					if (op_impressao == 1) {
						int m=1, k=0;

						graphColour(k, m, alunos, matriz, tam_sala);
						alunos=organizaTurma (alunos, tam_sala);
						Imprimir(alunos, tam_sala);

						getch();
						system("clear || cls");

					} else if (op_impressao == 0) { op_final=menu_op2(op); }
				} else if(op_final==0) { op_menu=menu_op1(op_menu); }
			}
			else if(op_menu==0)
			exit(0);
		}
	}
