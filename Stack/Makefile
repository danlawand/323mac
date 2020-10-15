# Ajuste os diretórios abaixo conforme o seu sistema 
LIBDIR = /usr/local/lib 
CFLAGS = -g -Wall -ansi -pedantic -Wno-unused-result
###########################################################################

all: clientRd

clientLL: client.o stackLL.o node.o
	gcc -o client client.o stackLL.o node.o

clientRd: client.o stackRd.o
	gcc -o client client.o stackRd.o 

client.o: client.c stack.h
	gcc $(CFLAGS) client.c -c 

node.o: node.c node.h item.h
	gcc $(CFLAGS) node.c -c

stackLL.o: stackLL.c stack.h item.h node.h 
	gcc $(CFLAGS) -c stackLL.c

stackRd.o: stackRd.c stack.h item.h
	gcc $(CFLAGS) stackRd.c -c

clean:
	rm -rf *.o *~ client

