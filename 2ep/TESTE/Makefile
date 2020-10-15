CC     = gcc
CFLAGS = -Wall -g -pedantic -Wno-unused-result
# -ansi
RM     = rm
OBJS   = MaxPQ.o Processo.o Node.o Espera.o ep.o
#------------------------------------------------

ep: $(OBJS)
	$(CC)  $(OBJS) -o ep -lm

ep.o: ep.c MaxPQ.o Processo.o Node.o
	$(CC) $(CFLAGS) -c ep.c

Espera.o: Espera.c Espera.h Node.c Node.h Processo.c Processo.h MaxPQ.c MaxPQ.h
	$(CC) $(CFLAGS) -c Espera.c

MaxPQ.o: MaxPQ.c MaxPQ.h Processo.c Processo.h
	$(CC) $(CFLAGS) -c MaxPQ.c

Node.o: Node.c Node.h Processo.c Processo.h
	$(CC) $(CFLAGS) -c Node.c

Processo.o: Processo.c Processo.h
	$(CC) $(CFLAGS) -c Processo.c

clean:
	$(RM) *.o *~ ep
