#include "Fila.h"
#include "Aviao.h"
#include "Celula.h"
#include <iostream>
using namespace std;

/*Construtor*/
Fila::Fila(int emergency)
{

	if (emergency)
		emergencia = 1;
	else 
		emergencia =0;
	tam = 0;
	passoPermissao = 0;
	ini->ante = fim;
	ini->prox = nullptr;
	fim->ante = nullptr;
	fim->prox = ini;
}
/*Destrutor*/
Fila::~Fila()
{
/*	Preciso deletar celula por celula*/
	Celula *c;

	while(!filaVazia())
	{
		c = ini->ante;
		ini->ante = c->ante;
		ini->ante->prox = ini;
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
	nova->ante = fim;
	fim->prox->ante = nova;
	nova->prox = fim->prox;
	fim->prox = nova;
}

void Fila::insereTopo(Aviao* a)
{
	Celula *nova = new Celula(a);
	tam++;
	nova->prox = ini;
	ini->ante->prox = nova;
	nova->ante = ini->ante;
	ini->ante = nova;
}

Aviao* Fila::removeTopo()
{
	Celula *c;
	Aviao *a;
	a = ini->ante->aeronave;
	c = ini->ante;
	ini->ante = c->ante;
	c->ante->prox = ini;
	delete c;
	tam--;
	return a;
}

Aviao* Fila::removePos(Celula *q)
{
	Aviao *a;
	a = q->aeronave;
	q->prox->ante = q->ante;
	q->ante->prox = q->prox;
	delete q;
	tam--;
	return a;
}

Aviao* Fila::topo()
{
	Aviao *a;
	a = ini->ante->aeronave;
	return a;
}

int Fila::tamanho()
{
	return tam;
}

bool Fila::filaVazia()
{

	if(fim->prox == ini)
		return true;
	return false;
}