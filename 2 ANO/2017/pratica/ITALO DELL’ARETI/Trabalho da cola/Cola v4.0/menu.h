#ifndef MENU_H
#define MENU_H

#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include <termios.h>
#include <unistd.h>
#include "menu.h"

char getch();

void print_titulo(int opt);

void menu_1(int opt);

void print_opt(int opt);

int menu_op1(int opt);

void print_opt2(int opt);

int menu_op2(int opt);

void print_opt_final(int opt);

int menu_opt_final(int opt);


#endif
