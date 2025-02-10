#ifndef MENU_H
#define MENU_H

#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include <termios.h>
#include <unistd.h>
#include "menu.h"

#define MAX_LEN 350

void print_image(FILE *fptr);

char getch();

void print_titulo(int opt);

int menu_1(int opt);

void print_opt(int opt);

int menu_op1(int opt);

void print_opt2(int opt);

int menu_op2(int opt);

void print_opt_final(int opt);

int menu_opt_final(int opt);

void print_configuracoes(int opt);

int menu_configuracoes(int opt);

void print_instrucoes(void);

void menu_instrucoes();

void Creditos(void);

void menu_creditos();

void print_imagem_ASCII();

void menu_print_imagem_ASCII();

#endif
