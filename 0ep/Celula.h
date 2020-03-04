#include "Aviao.h"
#ifndef CELULA_H
#define CELULA_H

class Celula
{
	public:
		Aviao* aeronave;
		Celula* prox;
		Celula(Aviao *a);
		~Celula();
};

#endif