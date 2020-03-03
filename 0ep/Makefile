CC     = g++
CFLAGS = -Wall -g
RM     = rm
#------------------------------------------------


simulacao:  Aviao.o Celula.o Fila.o Contador.o main.o 
	$(CC) Aviao.o Celula.o Fila.o main.o -o simulacao -lm

main.o: main.cpp Celula.h  Aviao.h Fila.h Categoria.h Contador.h  
	$(CC) $(CFLAGS) -c main.cpp 

Contador.o: Contador.cpp Aviao.h Celula.h Fila.h  
	$(CC) $(CFLAGS) -c Contador.cpp 

Fila.o: Fila.cpp Celula.h  Aviao.h Fila.h
	$(CC) $(CFLAGS) -c Fila.cpp

Celula.o: Celula.cpp Aviao.h Celula.h   
	$(CC) $(CFLAGS) -c Celula.cpp 

Aviao.o: Aviao.cpp Aviao.h
	$(CC) $(CFLAGS) -c Aviao.cpp