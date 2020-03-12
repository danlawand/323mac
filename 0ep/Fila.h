#ifndef FILA_H
#define FILA_H
#include "Aviao.h"
#include "Celula.h"

class Fila
{
	public:
		int tam;
		int passoPermissao;
		bool emergencia;
		double combustivelMedioFilaPouso;
		Aviao* a = new Aviao;
		Aviao* b = new Aviao;
		Celula* ini = new Celula(a);
		Celula* fim = new Celula(b);
		Fila(int emergency);
		~Fila();
		void insereFim(Aviao*);
		void insereTopo(Aviao*);
		Aviao* removeTopo();
		Aviao* removePos(Celula *q);
		Aviao* topo();
		int tamanho();
	  	bool filaVazia();

	  	/*Será que faço uma função para pesquisar qual é
	  	o que mais tem urgência?*/

};

#endif