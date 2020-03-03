#ifndef FILA_H
#define FILA_H
#include "Aviao.h"
#include "Celula.h"

class Fila
{
	private:
		int tam;
		Aviao* a = new Aviao;
		Aviao* b = new Aviao;
		Celula* ini = new Celula(a);
		Celula* fim = new Celula(b);
	public:	
		Fila();
		~Fila();
		void insere(Aviao*);
		Aviao* remove();
		Aviao* topo();
		int tamanho();
	  	bool filaVazia();
	  	int esperaDecolagem();
	  	int esperaPouso();

	  	/*Será que faço uma função para pesquisar qual é
	  	o que mais tem urgência?*/

};

#endif