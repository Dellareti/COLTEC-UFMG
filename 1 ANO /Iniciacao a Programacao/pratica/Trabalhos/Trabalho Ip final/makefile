all: cachola

cachola: main.o cliente.o gerente.o
    gcc -o cachola main.o cliente.o gerente.o

main.o: main.c cachola.h
    gcc -o main.o -c main.c

cliente.o: gerente.c cachola.h
    gcc -o gerente.o -c cachola.c

gerente.o: gerente.c cachola.h
    gcc -o gerente.o -c gerente.c
