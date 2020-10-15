CC     = gcc
CFLAGS = -Wall -g -pedantic -Wno-unused-result
# -ansi
RM     = rm
OBJS   = Processo.o Impressora.o  Node.o Acabados.o MaxPQ.o Espera.o Cpu.o ep2.o
#------------------------------------------------

ep2: $(OBJS)
	$(CC)  $(OBJS) -o ep2 -lm

ep2.o: ep2.c Acabados.o Impressora.o Cpu.o Espera.o MaxPQ.o Node.o Processo.o
	$(CC) $(CFLAGS) -c ep2.c

Cpu.o: Cpu.c Cpu.h Node.c Node.h Processo.c Processo.h
	$(CC) $(CFLAGS) -c Cpu.c

Espera.o: Espera.c Espera.h Node.c Node.h Processo.c Processo.h MaxPQ.c MaxPQ.h
	$(CC) $(CFLAGS) -c Espera.c

Impressora.o: Impressora.c Impressora.h Node.c Node.h Processo.c Processo.h
	$(CC) $(CFLAGS) -c Impressora.c

Acabados.o: Acabados.c Acabados.h Node.c Node.h Processo.c Processo.h
	$(CC) $(CFLAGS) -c Acabados.c

MaxPQ.o: MaxPQ.c MaxPQ.h Node.c Node.h Processo.c Processo.h
	$(CC) $(CFLAGS) -c MaxPQ.c

Node.o: Node.c Node.h Processo.c Processo.h
	$(CC) $(CFLAGS) -c Node.c

Processo.o: Processo.c Processo.h
	$(CC) $(CFLAGS) -c Processo.c

clean:
	$(RM) *.o *~ ep2
