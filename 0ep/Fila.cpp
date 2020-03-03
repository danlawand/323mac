#include "Fila.h"
#include "Aviao.h"
#include "Celula.h"
#include <iostream>
using namespace std;

/*Construtor*/
Fila::Fila()
{
	tam = 0;
	ini->prox = fim;
	ini->ante = fim;
	fim->prox = ini;
	fim->ante = ini;
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
		c->prox->ante = ini;
		delete c;
	}
	delete ini;
	delete fim;
}

/* <---<----<---<------
* INI 1 2 3 4 5 6 7 FIM
* FIM->PROX = 7;
* 7->ANTE = FIM;
* 7->PROX = 6;
*/
void Fila::insere(Aviao* a)
{
	Celula *nova = new Celula(a);
	tam++;
	cout<<"tam: "<<tam<<endl<<endl;
	fim->prox->ante = nova;
	nova->prox = fim->prox;
	fim->prox = nova;
	nova->ante = fim;
}

Aviao* Fila::remove()
{
	Celula *c;
	Aviao *a;
	a = ini->prox->aeronave;
	c = ini->prox;
	ini->prox = c->prox;
	c->prox->ante = ini;
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