#include <stdio.h>
#include <stdlib.h>
#include <termios.h>
#include <stdio_ext.h>
#include <ctype.h>
#include <time.h>
#include "menu.h"
#include "arquivo.h"

void main() {
	int op=1, op_menu=2, op_final;

	menu_1(op);

	op=3;
	while(1){

		op_menu=menu_2(op_menu);

		if(op_menu==2){

			system ("clear || cls");

			int tam_sala=0;
			printf("Quantos alunos estão na sala para fazer a prova?");
			scanf("%d", &tam_sala);
			__fpurge(stdin);

			grafo *alunos=aloca_vetor(tam_sala);

			int **matriz=aloca_matriz(tam_sala);

			manual(alunos, tam_sala);

			op_final=menu_final(op);

			if (op_final==3) {
				int m=1, k=0;

				graphColour(k, m, alunos, matriz, tam_sala);
				organizaTurma (alunos, tam_sala);
				Imprimir(alunos, tam_sala);

				op_final=menu_final(op);

			}else if(op_final==2){

				matriz = aleatoriamente(tam_sala, matriz);

				getch();
				system("clear || cls");

				op_final=menu_final(op);

			} else if(op_final==1){
				cria_ficha(alunos, tam_sala, matriz);

				getch();
				system("clear || cls");

				op_final=menu_final(op);
			} else if(op_final==0) { op_menu=menu_2(op); }
		}
		else if(op_menu==1){
				FILE *nomes;
				system ("clear || cls");

				int tam_sala=0;
				printf("Quantos alunos estão na sala para fazer a prova?");
				scanf("%d", &tam_sala);
				__fpurge(stdin);

				grafo *alunos=aloca_vetor(tam_sala);

				int **matriz=aloca_matriz(tam_sala);

				Inserir_Aresta(alunos, tam_sala, nomes);

				op_final=menu_final(op);

				if (op_final==3) {
					int m=1, k=0;

					graphColour(k, m, alunos, matriz, tam_sala);
					organizaTurma (alunos, tam_sala);
					Imprimir(alunos, tam_sala);

					op_final=menu_final(op);

				}else if(op_final==2){

					matriz = aleatoriamente(tam_sala, matriz);

					getch();
					system("clear || cls");

					op_final=menu_final(op);

				} else if(op_final==1){
					cria_ficha(alunos, tam_sala, matriz);

					getch();
					system("clear || cls");

					op_final=menu_final(op);
				} else if(op_final==0) { op_menu=menu_2(op); }
			}
			else if(op_menu==0)
			exit(0);
		}
	}
