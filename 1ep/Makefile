CC     = gcc
CFLAGS = -Wall -g
RM     = rm
OBJS   = Processo.o teste.o
#------------------------------------------------

teste:  $(OBJS)
	$(CC)  $(OBJS) -o teste -lm

teste.o: teste.c Processo.c Processo.h
	$(CC) $(CFLAGS) -c teste.c

Processo.o: Processo.c Processo.h
	$(CC) $(CFLAGS) -c Processo.c

clean:
	$(RM) *.o *~ teste
