#ifndef CONTADOR_H
#define CONTADOR_H
#include "Aviao.h"
#include "Celula.h"
#include "Fila.h"

class Contador
{
	public:
		double c_Pousado;
		Contador();
		~Contador();
		double calculaMediaFila(Fila *p, int passoAtual, bool mediaDeTempo, bool pouso);
		double tempoMedio_esperaPouso(Fila *p1, Fila *p2, Fila *p3, int passoAtual);
		double tempoMedio_esperaDecolagem(Fila *p1, Fila *p2, Fila *p3, int passoAtual);
		double combustivelMedio_esperaPouso(Fila *p1, Fila *p2, Fila *p3, int passoAtual);
};

#endif