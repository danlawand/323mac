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
	int i = 0;
	std::string cia;
	std::string aeroporto;
	int numero_voo;
	int tempo;
	bool emergencia;
	bool pouso;
	int e = 0;
	srand(7);

	Fila p1, p2, p3;

	int zero = 0;
	int navioes = 0;
	int qntdd;
	double a;
	int liberada[3] = {1, 1, 1};
	int pista_tamanho;


	/* Considero cada passo de tempo de simulação seja equivalente a uma hora na vida real
	*  Tendo visto que no aeroporto de GRU, chega no máximo 1000 aviões em um dia
	*  1000 aviões / 24 horas =~ 41 aviões/hora
 	*/

	while(i < ts)
	{
		qntdd = (rand() % 41);
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
			if(tempo == 0)
				zero++;

			a = (double)rand()/((double)RAND_MAX+1);
			pouso = 0;
			if(a < 0.5)
				pouso = 1;	

			a = (double)rand()/((double)RAND_MAX+1);
			emergencia = 0;
			if(a <  0.2)
			{	
				emergencia = 1;
				e++;
			}

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
			novo->informacoes(cia, aeroporto, numero_voo, tempo, pouso, emergencia);
		
			
			/*Inserir na fila de alguma pista*/


			/*Análise e Tomada de decisão
			* Vejo onde que o avião vai se encaixar e se é possível ele esperar na fila
			*/
			



			/*Verificar quais pistas estão livres ou interditadas---> chamar pistaLivre()*/

			/*Verificar se é pouso ou decolagem-----> if*/

			/*Verificar se é emergência ou não------> if*/
			/*Verificar se combustível está cheio---> if*/			
	/*		if (emergencia)
				/*Ver pista não interditada pistaLivre*/
				/*pK.insereNoTopo(novo);*/

			/*Aviao *a1 = p.topo();*/
/*

			if(pouso)
			{
				/*Decidindo em qual pista eu vou inseri*/
				/*if(p1.tam < p2.tam)
				{
					if (novo.tempo < 3*p1.tam)
						p1.insere(novo);
					else
						cout<<"Foi pra Viracopos"<<endl;
				} else 
				{
					if (novo.tempo < 3*p2.tam)
						p2.insere(novo);
					else
						cout<<"Foi pra Viracopos"<<endl;
				}
			} else 
			{*/
				/*Ver qual é o menor tempo de espera para as 3 pistas!! Aqui só tem 2*/
/*				if(p1.tam < p2.tam && p1.tam < p3.tam)
				{
					if (novo.tempo < 3*p1.tam)
						p1.insere(novo);
					else
						cout<<"Foi pra Viracopos"<<endl;
				} else if (p2.tam < p1.tam && p2.tam < p3.tam) {
					if (novo.tempo < 3*p2.tam)
						p2.insere(novo);
					else
						cout<<"Foi pra Viracopos"<<endl;
				}  else {
					if (novo.tempo < 3*p2.tam)
						p2.insere(novo);
				}
			}
*/



			qntdd--;
		}

		/*Aqui se realiza o pouso ou a decolagem*/


		i++;
	}

	double p = ((double) e / (double) navioes) *100;
	cout<<"n emergencias: "<<e<<"\n";
	cout<<"Porcentagem de emergencias: "<<p<<"\n";
	cout<<navioes<<" Aviões comunicaram a torre de comando"<<endl<<endl;



}