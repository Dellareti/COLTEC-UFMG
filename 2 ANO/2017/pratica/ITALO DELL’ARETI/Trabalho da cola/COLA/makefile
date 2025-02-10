COLA: main.o cola.o menu.o
	gcc main.o cola.o menu.o -o COLA

main.o: main.c
	gcc -c main.c

menu.o: menu.c menu.h
	gcc -c menu.c menu.h

cola.o: cola.c cola.h
	gcc -c cola.c cola.h
