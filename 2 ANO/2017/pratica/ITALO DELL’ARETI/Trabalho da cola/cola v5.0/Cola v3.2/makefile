COLA: main.o arquivo.o menu.o
	        gcc main.o arquivo.o menu.o -o COLA

main.o: main.c
	        gcc -c main.c

menu.o: menu.c menu.h
	        gcc -c menu.c menu.h

arquivo.o: arquivo.c arquivo.h
	        gcc -c arquivo.c arquivo.h

clean:
	rm *.o
	rm *.gch