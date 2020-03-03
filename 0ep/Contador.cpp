#include "Aviao.h"
#include "Celula.h"
#include "Fila.h"
#include "Contador.h"
#include <iostream>

Contador::Contador(){}
Contador::~Contador(){}

double Contador::calculaMediaFila(Fila p, int passoAtual, bool espera)
{
	double media = 0;
	int tEspera = 0;
	Celula  *c;
	c = p.ini->prox;

	if (espera)
	{
		int qntdd = 0;
		while(c->prox != ini)
		{
			if(c->aeronave->pouso == 1)
			{
				qntdd++;
				tEspera = (passoAtual - c->aeronave->passoContato) + tEspera;
			}
		}
		media = qntdd/tEspera;
	} else 
	{
		int litros = 0;
		while(c->prox != ini)
		{
			if(c->aeronave->pouso == 1)
			{
				litros += c->aeronave->tempo;
				tEspera = (passoAtual - c->aeronave->passoContato) + tEspera;
			}
		}
		media = litros/tEspera;
	}

	return media;
}

double Contador::tempo_esperaPouso(Fila *p1, Fila *p2, Fila *p3, int passoAtual)
{
	double m1 = calculaMediaFila(Fila p1, passoAtual, 1);
	double m2 = calculaMediaFila(Fila p2, passoAtual, 1);
	double m3 = calculaMediaFila(Fila p3, passoAtual, 1);

	return (m1+m2+m3)/3;
}
double Contador::tempo_esperaDecolagem(Fila *p1, Fila *p2, Fila *p3, int passoAtual)
{
	double m1 = calculaMediaFila(Fila p1, passoAtual, 1);
	double m2 = calculaMediaFila(Fila p2, passoAtual, 1);
	double m3 = calculaMediaFila(Fila p3, passoAtual, 1);
	return (m1+m2+m3)/3;
}
double Contador::combustivel_esperaPouso(Fila *p1, Fila *p2, Fila *p3, int passoAtual)
{
	double m1 = calculaMediaFila(Fila p1, passoAtual, 0);
	double m2 = calculaMediaFila(Fila p2, passoAtual, 0);
	double m3 = calculaMediaFila(Fila p3, passoAtual, 0);
	return (m1+m2+m3)/3;
}
double Contador::combustivel_Pousado();