#include <stdio.h>
#include <stdlib.h>
#include <termios.h>
#include <stdio_ext.h>
#include <unistd.h>
#include <ctype.h>
#include <time.h>
#include "menu.h"
#include "arquivo.h"

#define iniciar 0
#define configuracoes 1
#define voltar 1
#define sair 2
#define manualmente 0
#define txt 1
#define aleatorio 0
#define colaNaoCola 1
#define matriz_insercao 0
#define salaFinal 1
#define variavel_menu 0
#define audio 0

void main() {
	int op, op_menu, op_final, op_impressao, op_configuracoes;
	
	//menu_print_imagem_ASCII(); //imagem tá muito grande

	menu_instrucoes();

	system("clear || cls");

	while(1) {
		op=menu_1(variavel_menu);
		if (op==iniciar) {
			op_menu=menu_op1(variavel_menu);

			if(op_menu==manualmente){

				system ("clear || cls");

				int tam_sala=0;
				printf("Quantos alunos estão na sala para fazer a prova?");
				scanf("%d", &tam_sala);
				__fpurge(stdin);

				grafo *alunos=aloca_vetor(tam_sala);

				int **matriz=aloca_matriz(tam_sala);

				alunos=manual(alunos, tam_sala);

				op_final=menu_op2(variavel_menu);

				if (op_final==aleatorio) {
					matriz = aleatoriamente(tam_sala, matriz);

					int m=1, k=0;
					system("clear || cls");
					graphColour(k, m, alunos, matriz, tam_sala);
					alunos=organizaTurma (alunos, tam_sala);

					do{
						op_impressao=menu_opt_final(variavel_menu);

						if (op_impressao==matriz_insercao) {
							system("clear || cls");
							Imprimir_matriz(matriz, tam_sala);
							printf("\n\n\nAperte <enter> para continuar\n");
							getch();
							system("clear || cls");
						} else if (op_impressao == salaFinal) {
							system("clear || cls");
							Imprimir(alunos, tam_sala);
							printf("\n\n\nAperte <enter> para continuar\n");
							getch();
							system("clear || cls");

						} else if (op_impressao == sair) { op_final=menu_op2(variavel_menu); }
					}while(op_impressao == matriz_insercao);

				}else if(op_final==colaNaoCola) {
					system("clear || cls");
					matriz=cria_ficha(alunos, tam_sala, matriz);

					int m=1, k=0;
					system("clear || cls");
					graphColour(k, m, alunos, matriz, tam_sala);
					alunos=organizaTurma (alunos, tam_sala);

					do{
						op_impressao=menu_opt_final(variavel_menu);

						if (op_impressao == matriz_insercao) {
							system("clear || cls");
							Imprimir_matriz(matriz, tam_sala);
							printf("\n\n\nAperte <enter> para continuar\n");
							getch();
							system("clear || cls");
						} else if (op_impressao == salaFinal) {
							system("clear || cls");
							Imprimir(alunos, tam_sala);
							printf("\n\n\nAperte <enter> para continuar\n");
							getch();
							system("clear || cls");

						} else if (op_impressao == sair) { op_final=menu_op2(variavel_menu); }
					}while(op_impressao == matriz_insercao);

				} else if(op_final==sair) { op_menu=menu_op1(variavel_menu); }

			} else if(op_menu==txt) {
				FILE *nomes;
				system ("clear || cls");

				int tam_sala;
				printf("Quantos alunos estão na sala para fazer a prova?");
				scanf("%d", &tam_sala);
				__fpurge(stdin);

				grafo *alunos=aloca_vetor(tam_sala);

				int **matriz=aloca_matriz(tam_sala);

				Inserir_Aresta(alunos, tam_sala, nomes);

				op_final=menu_op2(variavel_menu);

				if (op_final==aleatorio) {
					matriz = aleatoriamente(tam_sala, matriz);

					int m=1, k=0;
					system("clear || cls");
					graphColour(k, m, alunos, matriz, tam_sala);
					alunos=organizaTurma (alunos, tam_sala);

					do{
						op_impressao=menu_opt_final(variavel_menu);

						if (op_impressao==matriz_insercao) {
							system("clear || cls");
							Imprimir_matriz(matriz, tam_sala);
							printf("\n\n\nAperte <enter> para continuar\n");
							getch();
							system("clear || cls");
						} else if (op_impressao == salaFinal) {
							system("clear || cls");
							Imprimir(alunos, tam_sala);
							printf("\n\n\nAperte <enter> para continuar\n");
							getch();
							system("clear || cls");

						} else if (op_impressao == sair) { op_final=menu_op2(variavel_menu); }
					}while(op_impressao==matriz_insercao);

				} else if(op_final==colaNaoCola){
					system("clear || cls");
					matriz=cria_ficha(alunos, tam_sala, matriz);

					int m=1, k=0;
					system("clear || cls");
					graphColour(k, m, alunos, matriz, tam_sala);
					alunos=organizaTurma (alunos, tam_sala);

					do{
						op_impressao=menu_opt_final(variavel_menu);

						if (op_impressao==matriz_insercao) {
							system("clear || cls");
							Imprimir_matriz(matriz, tam_sala);
							printf("\n\n\nAperte <enter> para continuar\n");
							getch();
							system("clear || cls");
						} else if (op_impressao == salaFinal) {
							system("clear || cls");
							Imprimir(alunos, tam_sala);
							printf("\n\n\nAperte <enter> para continuar\n");
							getch();
							system("clear || cls");

						} else if (op_impressao == sair) { op_final=menu_op2(variavel_menu); }
					}while(op_impressao==matriz_insercao);

				} else if(op_final==sair) { op_menu=menu_op1(variavel_menu); }
			} else if(op_menu==sair)
				op=menu_1(variavel_menu);
		} else if (op==configuracoes) {
			system("clear || cls");
			op_configuracoes=menu_configuracoes(variavel_menu);
			if (op_configuracoes==audio) {
				system("firefox http://www.infinitelooper.com/?v=JtyByefOvgQ&p=n");
				system("clear || cls");
				printf("\n\n\nAperte <enter> para continuar\n");
				getch();
			} else { op=menu_1(variavel_menu); }

		} else if (op==sair) { system("killall -9 firefox");
			printf("\n\n\nAperte <enter> para continuar\n");
			getch();
			system("clear || cls");
			menu_creditos();
			exit(0);
		} //Pensar nos exit(0);
	}
}