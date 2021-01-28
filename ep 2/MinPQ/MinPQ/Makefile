# Ajuste os diretórios abaixo conforme o seu sistema 
LIBDIR = /usr/local/lib 
CFLAGS = -g -Wall -ansi -pedantic -Wno-unused-result
###########################################################################

all: TopM

TopM: TopM.o MinPQ.o stack.o transaction.o
	gcc -o TopM TopM.o MinPQ.o stack.o transaction.o

LTopM: TopM.o LMinPQ.o stack.o transaction.o
	gcc -o TopM TopM.o LMinPQ.o stack.o transaction.o

BTopM: TopM.o binomialMinPQ.o stack.o transaction.o
	gcc -o TopM TopM.o binomialMinPQ.o stack.o transaction.o

TopM.o: TopM.c MinPQ.h stack.h transaction.h
	gcc $(CFLAGS) TopM.c -c 

transaction.o: transaction.c transaction.h
	gcc $(CFLAGS) transaction.c -c

MinPQ.o: MinPQ.c MinPQ.h transaction.h
	gcc $(CFLAGS) -c MinPQ.c

LMinPQ.o: LMinPQ.c MinPQ.h transaction.h
	gcc $(CFLAGS) -c LMinPQ.c

binomialMinPQ.o: binomialMinPQ.c MinPQ.h transaction.h
	gcc $(CFLAGS) -c binomialMinPQ.c

stack.o: stack.c stack.h transaction.h
	gcc $(CFLAGS) stack.c -c

clean:
	rm -rf *.o *~ TopM

