#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Aviao.h"
#include "Fila.h"
#include "Categoria.h"
#include "Contador.h"

using namespace std;

int main()
{
	int ts;
	cout<<"Aeroporto Internacional GRU\n";
	cout<<"________________________________\n\n";
	cout<<"Digite o tempo de simulação:";
	cin>>ts;
	cout<<"\n\n";

	std::string cia;
	std::string aeroporto;
	int numero_voo;
	int tempo;
	bool emergencia;
	bool pouso;

	Contador count;
	Fila p1, p2, p3;


	int i = 0;
	int navioes = 0;
	int qntdd;
	double aleat;

	srand(7);
	

	/* Considero cada passo de tempo de simulação seja equivalente a uma hora na vida real
	*  Tendo visto que no aeroporto de GRU, chega no máximo 1000 aviões em um dia
	*  1000 aviões / 24 horas =~ 41 aviões/hora
 	*/

	while(i < ts)
	{
		qntdd = (rand() % 3);
		cout<<"Numero de Aviões que entraram em contato com a torre de comando: "<<qntdd<<endl<<endl;
		while (qntdd > 0)
		{
			/*Contador da quantidade de aeronaves por dia*/
			navioes++;

			/*Numero do Voo*/
			numero_voo = (rand() % 9999);

			aeroporto = aeroportos[(rand() % 53)];

			cia = companhias[(rand() % 32)];

			tempo = (rand()%100);

			aleat = (double)rand()/((double)RAND_MAX+1);
			pouso = 0;
			if(aleat < 0.5)
				pouso = 1;	

			aleat = (double)rand()/((double)RAND_MAX+1);
			emergencia = 0;
			if(aleat <  0.2)
				emergencia = 1;

			/*if(pouso)
			{
				cout<<" Aeronave comunicando a Torre de Comando.\n"<<"______________________________________\n";
				if (emergencia)
					cout<<"Voo de emergencia:\n"<<emergencia<<"\n";
				cout<<"Solicitando permissão para POUSAR"<<endl;
				cout<<"Sigla da Companhia aérea:\n"<<cia<<"\n";
				cout<<"Numero do Vôo:\n"<<numero_voo<<"\n";
				cout<<"Sigla do Aeroporto de Origem:\n"<<aeroporto<<"\n";
				cout<<"Tempo de Combustível:\n"<<tempo<<"\n";
			} else {
				cout<<" Aeronave comunicando a Torre de Comando.\n"<<"______________________________________\n";
				if (emergencia)
					cout<<"Voo de emergencia:\n"<<emergencia<<"\n";
				cout<<"Solicitando permissão para DECOLAR"<<endl;
				cout<<"Sigla da Companhia aérea:\n"<<cia<<"\n";
				cout<<"Numero do Vôo:\n"<<numero_voo<<"\n";
				cout<<"Sigla do Aeroporto de Destino:\n"<<aeroporto<<"\n";
				cout<<"Tempo Estimado da Viagem:\n"<<tempo<<"\n";
			}*/
			Aviao *novo = new Aviao;
			novo->informacoes(cia, aeroporto, numero_voo, tempo, i, 0, pouso, emergencia);
			p1.insere(novo);
			qntdd--;
		}

		cout<<p1.tam+p2.tam+p3.tam<<" Aviões estão esperando para pousar e/ou decolar"<<endl;
		cout<<"Tempo médio de espera para pouso: "<<count.tempo_esperaPouso(&p1, &p2, &p3, i)<<endl;
		/*cout<<"Tempo médio de espera para decolagem: "<<count.tempo_esperaDecolagem(&p1, &p2, &p3, i)<<endl;
		cout<<"Quantidade média de combustı́vel dos aviões esperando para pousar: "<<count.combustivel_esperaPouso(&p1, &p2, &p3, i)<<endl;
		cout<<"Quantidade média de combustı́vel dos aviões que pousaram: "<<count.c_Pousado<<endl;
		/*cout<<"Quantidade de aviões pousando/decolando em condições de emergência: "<<endl;*/
		i++;
	}

	cout<<endl<<navioes<<" Aviões comunicaram a torre de comando"<<endl<<endl;
}