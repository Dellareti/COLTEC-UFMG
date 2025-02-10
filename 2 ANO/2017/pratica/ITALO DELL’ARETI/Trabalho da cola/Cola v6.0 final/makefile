#COLA: main.o arquivo.o menu.o
#	        gcc main.o -lm arquivo.o -lm menu.o -lm -o COLA

#main.o: main.c
#	        gcc -c main.c -lm

#menu.o: menu.c menu.h
#	        gcc -c menu.c -lm menu.h -lm

#arquivo.o: arquivo.c arquivo.h
#	        gcc -c arquivo.c -lm arquivo.h -lm

CC = gcc
bib_menu = menu
bib_arquivo = arquivo
executavel = cola.bin

all: menu arquivo compilacao clean
	@clear
	@echo Compilação concluida!

menu: $(bib_menu).o -lm
	gcc -c $(bib_menu).c -lm

arquivo: $(bib_arquivo).o -lm
	gcc -c $(bib_arquivo).c -lm

compilacao: main.c
	$(CC) main.c -lm menu.o arquivo.o -lm -o $(executavel)

clean: clean_folders
	@echo limpando pastas...

clean_folders:
	rm $(bib_menu).o
	rm $(bib_arquivo).o