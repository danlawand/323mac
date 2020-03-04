#include "Fila.h"
#include "Aviao.h"
#include "Celula.h"
#include <iostream>
using namespace std;

/*Construtor*/
Fila::Fila()
{
	tam = 0;
	passoPermissao = 3;
	ini->prox = fim;
	fim->prox = ini;
}
/*Destrutor*/
Fila::~Fila()
{
/*	Preciso deletar celula por celula*/
	Celula *c;
	while(!filaVazia())
	{
		c = ini->prox;
		ini->prox = c->prox;
		delete c;
	}
	delete ini;
	delete fim;
}

/* <---<----<---<------
* INI 1 2 3 4 5 6 7 FIM
* FIM->PROX = 7;
* 7->PROX = 6;
*/
void Fila::insereFim(Aviao* a)
{
	Celula *nova = new Celula(a);
	tam++;
	nova->prox = fim->prox;
	fim->prox = nova;
}

void Fila::insereTopo(Aviao* a)
{
	Celula *nova = new Celula(a);
	tam++;
	nova->prox = ini->prox;
	ini->prox = nova;
}

Aviao* Fila::remove()
{
	Celula *c;
	Aviao *a;
	a = ini->prox->aeronave;
	c = ini->prox;
	ini->prox = c->prox;
	delete c;
	tam--;
	return a;
}

Aviao* Fila::topo()
{
	Aviao *a;
	a = ini->prox->aeronave;
	return a;
}

int Fila::tamanho()
{
	return tam;
}

bool Fila::filaVazia()
{
	if(ini->prox == fim)
		return true;
	return false;
}