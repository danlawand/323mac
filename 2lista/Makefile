CC     = gcc
CFLAGS = -Wall -g -pedantic
# -ansi
RM     = rm
OBJS   = SkipListST.o st.o client.o
#------------------------------------------------

client: $(OBJS)
	$(CC)  $(OBJS) -o client -lm

client.o: client.c SkipListST.o st.o
	$(CC) $(CFLAGS) -c client.c

SkipListST.o: SkipListST.c SkipListST.h st.c st.h
	$(CC) $(CFLAGS) -c SkipListST.c

st.o: st.c st.h
	$(CC) $(CFLAGS) -c st.c

clean:
	$(RM) *.o *~ ep2
