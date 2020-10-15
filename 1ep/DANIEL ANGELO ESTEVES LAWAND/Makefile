CC     = gcc
CFLAGS = -Wall -g -pedantic -Wno-unused-result -ansi
RM     = rm
OBJS   = Fila.o Node.o Processo.o ep1.o
#------------------------------------------------

ep1:  $(OBJS)
	$(CC)  $(OBJS) -o ep1 -lm

ep1.o: ep1.c Fila.c Fila.h Node.c Node.h Processo.c Processo.h
	$(CC) $(CFLAGS) -c ep1.c

Fila.o: Fila.c Fila.h Node.c Node.h Processo.c Processo.h
		$(CC) $(CFLAGS) -c Fila.c

Node.o: Node.c Node.h Processo.c Processo.h
	$(CC) $(CFLAGS) -c Node.c

Processo.o: Processo.c Processo.h
	$(CC) $(CFLAGS) -c Processo.c

clean:
	$(RM) *.o *~ ep1
