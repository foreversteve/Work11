all: stats.o
	gcc stats.o
stats.o: stats.c
	gcc -c stats.c
run:
	./a.out