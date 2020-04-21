CC     = g++
CFLAGS = -Wall -g
RM     = rm
OBJS   = aviao.o celula.o fila.o contador.o ep0.o 
#------------------------------------------------

ep0:  $(OBJS)
	$(CC)  $(OBJS) -o ep0 -lm

ep0.o: ep0.cpp celula.h  aviao.h fila.h categoria.h contador.h  
	$(CC) $(CFLAGS) -c ep0.cpp 

contador.o: contador.cpp aviao.h celula.h fila.h  
	$(CC) $(CFLAGS) -c contador.cpp 

fila.o: fila.cpp celula.h  aviao.h fila.h
	$(CC) $(CFLAGS) -c fila.cpp

celula.o: celula.cpp aviao.h celula.h   
	$(CC) $(CFLAGS) -c celula.cpp 

aviao.o: aviao.cpp aviao.h
	$(CC) $(CFLAGS) -c aviao.cpp
clean:
	$(RM) *.o *~ ep0
