#ifndef CONTADOR_H
#define CONTADOR_H
#include "Aviao.h"
#include "Celula.h"
#include "Fila.h"

class Contador
{
	public:
		double combustivel_Pousado[2];
		double tempoMedio_esperaPouso[2];
		double tempoMedio_esperaDecolagem[2];
		double combustivelMedio_esperaPouso[2];
		double quantidadeVoos_emergencia;
		Contador();
		~Contador();
};

#endif