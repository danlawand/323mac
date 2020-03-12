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
		double tempo_esperaPouso(Fila *p1, Fila *p2, Fila *p3, int passoAtual);
		double tempo_esperaDecolagem(Fila *p1, Fila *p2, Fila *p3, int passoAtual);
		double combustivel_esperaPouso(Fila *p1, Fila *p2, Fila *p3, int passoAtual);
};

#endif