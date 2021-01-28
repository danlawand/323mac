CC 			= gcc
CFLAGS 	= -Wall -g -pedantic #-Wno-unused-result -ansi
RM 			= rm
OBJS 		= ep3.o lazy.o
# ----------------------------------------------------------
ep3: $(OBJS)
	$(CC) $(OBJS) -o ep3 -lm

ep3.o: ep3.c lazy.o
	$(CC) $(CFLAGS) -c ep3.c

lazy.o: lazy.c lazy.h
	$(CC) $(CFLAGS) -c lazy.c


clean:
	$(RM) *.o *~ ep3
