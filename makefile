all: infanticide.o
	gcc -o infanticide infanticide.o
infanticide.o: infanticide.c
	gcc -c infanticide.c
run: all
	./infanticide
