#ifndef CONTADOR_H
#define CONTADOR_H
#include "Aviao.h"
#include "Celula.h"
#include "Fila.h"

class Contador
{
	public:
		int tempo_esperaPouso;
		int tempo_esperaDecolagem;
		int combustivel_esperaPouso;
		int combustivel_Pousado;
		Contador();
		~Contador();
		int tempo_esperaPouso;
		int tempo_esperaDecolagem;
		int combustivel_esperaPouso;
		int combustivel_Pousado;
};

#endif