# Este Makefile e' para a rede do IME
LIBDIR = /usr/local/lib
CFLAGS = -Wall -O2 -ansi -pedantic -Wno-unused-result
CC = gcc

###########################################################################

Index: Index.o queue.o st.o
	$(CC) Index.o queue.o st.o -o Index

IndexSL: Index.o queue.o stSkipList.o
	$(CC) Index.o queue.o stSkipList.o -o Index

IndexMTF: Index.o queue.o stMTF.o
	$(CC) Index.o queue.o stMTF.o -o IndexMTF

IndexLL: Index.o queue.o stSortedLL.o
	$(CC) Index.o queue.o stSortedLL.o -o IndexLL

IndexSA: Index.o queue.o stSortedArray.o
	$(CC) Index.o queue.o stSortedArray.o -o IndexSA

queue.o: queue.c queue.h item.h
	$(CC) $(CFLAGS) -c queue.c

stSortedArray.o: stSortedArray.c queue.h item.h
	$(CC) $(CFLAGS) -c stSortedArray.c

stSortedLL.o: stSortedLL.c queue.h item.h
	$(CC) $(CFLAGS) -c stSortedLL.c

stMTF.o: stMTF.c queue.h item.h
	$(CC) $(CFLAGS) -c stMTF.c

stSkipList.o: stSkipList.c queue.h item.h
	$(CC) $(CFLAGS) -c stSkipList.c

st.o: st.c queue.h item.h
	$(CC) $(CFLAGS) -c st.c

Index.o: Index.c st.h queue.h item.h
	$(CC) $(CFLAGS) -c Index.c

clean:
	rm -rf *.o *~ Index IndexLL IndexMTF IndexSA IndexSL

