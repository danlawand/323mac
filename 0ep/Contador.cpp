#include "Aviao.h"
#include "Celula.h"
#include "Fila.h"
#include "Contador.h"
#include <iostream>
using namespace std;

Contador::Contador()
{
	combustivel_Pousado[0] = 0; 
	combustivel_Pousado[1] = 0;

	tempoMedio_esperaPouso[0] = 0;
	tempoMedio_esperaPouso[1] = 0;

	tempoMedio_esperaDecolagem[0] = 0;
	tempoMedio_esperaDecolagem[1] = 0;

	combustivelMedio_esperaPouso[0] = 0;
	combustivelMedio_esperaPouso[1] = 0;

	quantidadeVoos_emergencia = 0;
}
Contador::~Contador(){}