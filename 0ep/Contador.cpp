#include "Aviao.h"
#include "Celula.h"
#include "Fila.h"
#include "Contador.h"
#include <iostream>

Contador::Contador(){}
Contador::~Contador(){}

int tempo_esperaPouso(Fila *p1, Fila *p2, Fila *p3, int passoAtual)
{
	int espera = 0;
	Celula  *c;
	c = p1.ini->prox;
	while(c->prox != ini)
	{
		if(c->aeronave->pouso == 1)
			espera++;
	}	
}
int tempo_esperaDecolagem();
int combustivel_esperaPouso();
int combustivel_Pousado();