#include "Aviao.h"
#include "Celula.h"
#include "Fila.h"
#include "Contador.h"
#include <iostream>
using namespace std;

Contador::Contador(){c_Pousado = 0;}
Contador::~Contador(){}

double Contador::calculaMediaFila(Fila *p, int passoAtual, bool mediaDeTempo, bool pouso)
{
	double media = 0;
	int tEspera = 0;
	Celula  *c;
	c = p->fim->prox;
	
	if (mediaDeTempo)
	{
		int qntdd = 0;
		while(c != p->ini)
		{

			if(c->aeronave->pouso == 1)
			{
				qntdd++;
				tEspera = (passoAtual - c->aeronave->passoContato) + tEspera;
			}
			c = c->prox;
		}
		media = 0;
		if (tEspera != 0)
			media = ((double)tEspera)/((double)qntdd);
	} else 
	{
		int litros = 0;
		while(c != p->ini)
		{
			if(c->aeronave->pouso == pouso)
			{
				litros += c->aeronave->tempo;
				tEspera = (passoAtual - c->aeronave->passoContato) + tEspera;
			}
			c = c->prox;
		}
		media = 0;
		if (tEspera != 0)
			media = ((double)tEspera)/((double)litros);
	}

	return media;
}
/*tempoMedio_esperaPouso(&fila1, &fila2, &fila3, ts);*/
double Contador::tempoMedio_esperaPouso(Fila *p1, Fila *p2, Fila *p3, int passoAtual) 
{
	
	double m1 = calculaMediaFila(p1, passoAtual, 1, 1);
	double m2 = calculaMediaFila(p2, passoAtual, 1, 1);
	double m3 = calculaMediaFila(p3, passoAtual, 1, 1);

	return (m1+m2+m3)/3.0;
}
double Contador::tempoMedio_esperaDecolagem(Fila *p1, Fila *p2, Fila *p3, int passoAtual)
{
	double m1 = calculaMediaFila(p1, passoAtual, 1, 0);
	double m2 = calculaMediaFila(p2, passoAtual, 1, 0);
	double m3 = calculaMediaFila(p3, passoAtual, 1, 0);
	return (m1+m2+m3)/3.0;
}
double Contador::combustivelMedio_esperaPouso(Fila *p1, Fila *p2, Fila *p3, int passoAtual)
{
	double m1 = calculaMediaFila(p1, passoAtual, 0, 1);
	double m2 = calculaMediaFila(p2, passoAtual, 0, 1);
	double m3 = calculaMediaFila(p3, passoAtual, 0, 1);
	return (m1+m2+m3)/3.0;
}