# Ajuste os diretórios abaixo conforme o seu sistema
LIBDIR = /usr/local/lib
CFLAGS = -g -Wall -ansi -pedantic -Wno-unused-result
###########################################################################

client: client.o queue.o
	gcc -o client client.o queue.o 

client.o: client.c queue.h
	gcc $(CFLAGS) client.c -c


queue.o: queue.c queue.h item.h
	gcc $(CFLAGS) queue.c -c

clean:
	rm -rf *.o *~ client
