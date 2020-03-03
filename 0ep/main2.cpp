#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Aviao.h"
#include "Fila.h"

using namespace std;

int main()
{
	int ts;
	cout<<"Aeroporto Internacional BCÇÓIDE\n";
	cout<<"________________________________\n\n";
	cout<<"Digite o tempo de simulação:";
	cin>>ts;
	cout<<"\n\n";
	int i = 0;
	std::string cia;
	std::string aeroporto;
	int numero_voo;
	int tempo;
	bool emergencia; /**/
	bool pouso;
	double a;
	cia = "OLA";
	aeroporto = "GRU";
	int e = 0;
	srand(time(0));

	Fila p1, p2, p3;

	int zero = 0;

	/*vamos receber um tempo ts de simulação
	* Constatamos que em GRU em um dia pode-se chegar até 1000 aviões	
	* Com isso, façamos uma aproximação de ts a 24 horas
	* sendo a cada passo x aeronaves
	*
	*
	*
	*/



	int navioes = 0;
	int qntdd;
	double d;

	d = 96.0*24.0/((double)ts); 
	/*Tendo visto que no máximo chega-se  1000 aviões em um dia no aeroporto de GRU
	* converto a proporção de horas por tempo de simulação
	* e multiplico pela quantidade 
	*/

	while(i < ts)
	{
		a = (double)rand()/((double)RAND_MAX+1);	
		a = a*d;
		qntdd = (int)a;
		cout<<"Numero de Aviões que entraram em contato com a torre de comando: "<<qntdd<<endl<<endl;
		while (qntdd > 0)
		{
			navioes++;
			/*Tenho que ver a parada da semente*/
			numero_voo = rand()/100;
			a = (double)rand()/((double)RAND_MAX+1);		
			
			tempo = a*20; /*Pelo método científico, percebi que multiplicando por 20 torno a probabilidade de vir um avião com zero de combustível fica em 5%, numero que eu acho que é válido*/
			/*cout<<"Tempo"<<i<<": "<<tempo<<endl<<endl;*/
			if(tempo == 0)
				zero++;

			a = (double)rand()/((double)RAND_MAX+1);
			pouso = 0;
			if(a < 0.5)
				pouso = 1;	

			a = (double)rand()/((double)RAND_MAX+1);
			emergencia = 0;
			if(a <  0.2)
				emergencia = 1;

			/*cout<<navioes<<" Aeronave comunicando a Torre de Comando.\n"<<"______________________________________\n\n";
			/*cout<<"Sigla da Companhia aérea:\n"<<cia<<"\n";

			cout<<"Numero do Vôo:\n"<<numero_voo<<"\n";
			cout<<"Pouso:\n"<<pouso<<"\n";
			cout<<"Voo de emergencia:\n"<<emergencia<<"\n";
			*/if(emergencia)
				e++;
			/*if(pouso)
			{
				cout<<"Sigla do Aeroporto de Origem:\n"<<aeroporto<<"\n";
				cout<<"Tempo de Combustível:\n"<<tempo<<"\n";
			} else {
				cout<<"Sigla do Aeroporto de Destino:\n"<<aeroporto<<"\n";
				cout<<"Tempo Estimado da Viagem:\n"<<tempo<<"\n";
			}*/
			qntdd--;
		}


		/*Aviao *novo = new Aviao;
		novo->informacoes(numero_voo, tempo, pouso, emergencia);
		p1.insere(novo);*/
		i++;
	}

	double p = ((double) e / (double) ts) *100;
	cout<<"n emergencias: "<<e<<"\n";
	cout<<"Porcentagem: "<<p<<"\n";
	cout<<navioes<<" Aviões comunicaram a torre de comando: "<<endl<<endl;



}