CC			= gcc
CFLAGS	= -Wall -g -pedantic -Wno-unused-result
rm 			= rm
OBJS		= MaxPQ.o ep.o
#------------------------------------------------
ep: $(OBJS)
	$(CC)	$(OBJS) -o ep -lm

ep.o: ep.c MaxPQ.o
	$(CC) $(CFLAGS) -c ep.c


MaxPQ.o: MaxPQ.c MaxPQ.h item.h
	$(CC) $(CFLAGS) -c MaxPQ.c

clean:
	$(RM) *.o *~ ep
