#include <iostream>
#include "Aviao.h"

Aviao::Aviao(){}

Aviao::~Aviao(){}

void Aviao::informacoes(std::string comp, std::string ap, int nv, int t, int pContato, bool p, int e)
{
	cia = comp;
	aeroporto = ap; 
	numero_voo = nv;
	tempo = t;
	passoContato = pContato;
	pouso = p;
	emergencia = e;
}