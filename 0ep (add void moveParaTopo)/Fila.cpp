#include "Fila.h"
#include "Aviao.h"
#include "Celula.h"
#include <iostream>
using namespace std;

/*Construtor*/
Fila::Fila(int numero_da_pista)
{
	num_pista = numero_da_pista;
	tam = 0;
	tempoEspera = 0;
	ini->ante = fim;
	ini->prox = nullptr;
	fim->ante = nullptr;
	fim->prox = ini;
}
/*Destrutor*/
Fila::~Fila()
{
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

void Fila::LeFila()
{
/*	Preciso deletar celula por celula*/
	Celula *c, *r;
	int i = tam;
	c = fim;
	//cout<<"Primeiro da Fila  -----  "<<ini->ante->ante->aeronave->cia<<endl;
	cout<<"Tamanho: "<<tam<<endl;
	while (c != ini)
	{
		if (c == fim)
			cout<<"fim - ";
		else{
			i--;
			cout<<c->aeronave->cia<<" - "<<c->aeronave->numero_voo<<endl;
		} 
		c = c->prox;
	}
	if (c == ini)
		cout<<"ini"<<endl;
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
	nova->ante = ini->ante;
	ini->ante->prox = nova;
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
	tam--;
	delete c;
	return a;
}

void Fila::moveParaTopo(Celula *q)
{

	q->prox->ante = q->ante;
	q->ante->prox = q->prox;
	q->prox = ini;
	q->ante = ini->ante;
	ini->ante->prox = q;
	ini->ante = q;	
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