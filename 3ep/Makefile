CC 			= gcc
CFLAGS 	= -Wall -g -pedantic -Wno-unused-result #-ansi -o2
RM 			= rm
OBJS 		= ep3.o ABB.o ARN.o HASH.o MTF.o LP.o
# ----------------------------------------------------------
ep3: $(OBJS)
	$(CC) $(OBJS) -o ep3 -lm

ep3.o: ep3.c ABB.o ARN.o MTF.o LP.o
	$(CC) $(CFLAGS) -c ep3.c

ABB.o: ABB.c ABB.h
	$(CC) $(CFLAGS) -c ABB.c

ARN.o: ARN.c ARN.h
	$(CC) $(CFLAGS) -c ARN.c

HASH.o: HASH.c HASH.h
	$(CC) $(CFLAGS) -c HASH.c

MTF.o: MTF.c MTF.h
	$(CC) $(CFLAGS) -c MTF.c

LP.o: LP.c LP.h
	$(CC) $(CFLAGS) -c LP.c

clean:
	$(RM) *.o *~ ep3
