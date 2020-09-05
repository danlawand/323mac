CC     = g++
CFLAGS = -Wall -g
RM     = rm
OBJS   = aviao.o celula.o fila.o contador.o ep0.o 
#------------------------------------------------

default :
	@echo "Para criar o tar, diga make tar NUSP=<NUSP> EMAIL=<EMAIL>."
	@echo "Para compilar o programa, diga make pitao."

tar:
	rm      -rf                     $(NUSP)
	rm      -f                      $(NUSP).tar

	mkdir                           $(NUSP)
	cp              categoria.h     $(NUSP)/categoria.h
	cp              aviao.h         $(NUSP)/aviao.h
	cp              aviao.cpp       $(NUSP)/aviao.cpp
	cp              celula.cpp      $(NUSP)/celula.cpp
	cp              celula.h        $(NUSP)/celula.h
	cp		        fila.cpp        $(NUSP)/fila.cpp
	cp              fila.h          $(NUSP)/fila.h
	cp		        contador.cpp    $(NUSP)/contador.cpp
	cp              contador.h      $(NUSP)/contador.h
	cp              ep0.cpp         $(NUSP)/ep0.cpp
	cp              Makefile        $(NUSP)/Makefile
	echo            $(EMAIL)      > $(NUSP)/email.txt
	echo            $(NUSP)       > $(NUSP)/nusp.txt

	tar     -cvf    $(NUSP).tar     $(NUSP)
	rm -rf                          $(NUSP)
# chama o linker

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
