#ifndef MENU_H
#define MENU_H

#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include <termios.h>
#include <unistd.h>

#define MAX_LEN 128

char getch();

void print_image(FILE *fptr);

void print_titulo(int opt);

void menu_1(int opt);

void print_opt(int opt);

void print_opt2(int opt);

// parte da movimentação no teclado ws

int menu_2(int opt);

int menu_final(int opt);

#endif
