#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Aviao.h"
#include "Fila.h"
#include "Celula.h"
#include "Categoria.h"
#include "Contador.h"

using namespace std;

void verificandoCombustivel(Fila *p1, Fila *p2, Fila *p3)
{

}

/*Função de entrar na fila --  INCOMPLETA*/
void escolhendoPista(Fila *p1, Fila *p2, Fila *p3, Aviao *a)
{
	/*EMERGÊNCIA DONE*/
	/*Para Vôos de emergência, vamos analisar qual passoPermissão é menor*/
	if (a->emergencia)
	{
		if(p3->passoPermissao < p2->passoPermissao && p3->passoPermissao < p1->passoPermissao)
			p3->insereTopo(a);
		else if (p1->passoPermissao < p2->passoPermissao && p1->passoPermissao < p3->passoPermissao)
			p1->insereTopo(a);
		else if (p2->passoPermissao < p3->passoPermissao && p2->passoPermissao < p1->passoPermissao)
			p2->insereTopo(a);
		else if ((p1->passoPermissao == p2->passoPermissao) && p1->passoPermissao < p3->passoPermissao)
			if (p1->tam < p2->tam)
				p1->insereTopo(a);
			else
				p2->insereTopo(a);
		else if ((p1->passoPermissao == p2->passoPermissao) && p1->passoPermissao > p3->passoPermissao)
			p3->insereTopo(a);
		else if ((p1->passoPermissao == p3->passoPermissao) && p1->passoPermissao < p2->passoPermissao)
			if (p1->tam < p3->tam)
				p1->insereTopo(a);
			else
				p3->insereTopo(a);
		else if ((p1->passoPermissao == p3->passoPermissao) && p1->passoPermissao > p2->passoPermissao)
			p2->insereTopo(a);

		else if ((p2->passoPermissao == p3->passoPermissao) && p2->passoPermissao < p1->passoPermissao)
			if (p2->tam < p3->tam)
				p2->insereTopo(a);
			else
				p3->insereTopo(a);
		else /* if ((p2->passoPermissao == p3->passoPermissao) && p2->passoPermissao > p1->passoPermissao)*/
			p1->insereTopo(a);

	} else if (a->pouso)
	{
		/*POUSO DONE*/
		if(3*(p1->tam) + p1->passoPermissao < 3*(p2->tam) + p2->passoPermissao)
		{
			if (a->tempo > 3*p1->tam + p1->passoPermissao)
				p1->insereFim(a);
			else
			{
				cout<<"Foi pra Viracopos"<<endl; 
				delete a;
			}
		} else if (3*(p2->tam) + p2->passoPermissao < 3*(p1->tam) + p1->passoPermissao)
		{
			if (a->tempo > 3*p2->tam + p2->passoPermissao)
				p2->insereFim(a);
			else
			{
				cout<<"Foi pra Viracopos"<<endl;
				delete a;
			}
		} else
		{
			if (a->tempo > 3*p1->tam + p1->passoPermissao)
				p1->insereFim(a);
			else
			{
				cout<<"Foi pra Viracopos"<<endl;
				delete a;
			}
		}
	} else 
	{
		/*DECOLAGEM*/
		/*FALTA ANALISAR A QUESTÃO DE 10% DO TEMPO DE VIAGEM EM RELAÇÃO AO TEMPO DE ESPERA*/
		if(3*p3->tam + p3->passoPermissao < 3*p2->tam + p2->passoPermissao && 3*p3->tam + p3->passoPermissao < 3*p1->tam + p1->passoPermissao)
			p3->insereFim(a);

		else if (3*p1->tam + p1->passoPermissao < 3*p2->tam + p2->passoPermissao && 3*p1->tam + p1->passoPermissao < 3*p3->tam + p3->passoPermissao)

			p1->insereFim(a);

		else if (3*p2->tam + p2->passoPermissao < 3*p3->tam + p3->passoPermissao && 3*p2->tam + p2->passoPermissao < 3*p1->tam + p1->passoPermissao)

				p2->insereFim(a);

		else if ((3*p1->tam + p1->passoPermissao == 3*p2->tam + p2->passoPermissao) && 3*p1->tam + p1->passoPermissao < 3*p3->tam + p3->passoPermissao)
			if (3*p1->tam + p1->passoPermissao < 3*p2->tam + p2->passoPermissao)
					p1->insereFim(a);
			else
					p2->insereFim(a);

		
		else if ((3*p1->tam + p1->passoPermissao == 3*p2->tam + p2->passoPermissao) && 3*p1->tam + p1->passoPermissao > 3*p3->tam + p3->passoPermissao)
					p3->insereFim(a);

		else if ((3*p1->tam + p1->passoPermissao == 3*p3->tam + p3->passoPermissao) && 3*p1->tam + p1->passoPermissao < 3*p2->tam + p2->passoPermissao)
			if (3*p1->tam + p1->passoPermissao < 3*p3->tam + p3->passoPermissao)

					p1->insereFim(a);

			else
					p3->insereFim(a);

		
		else if ((3*p1->tam + p1->passoPermissao == 3*p3->tam + p3->passoPermissao) && 3*p1->tam + p1->passoPermissao > 3*p2->tam + p2->passoPermissao)

				p2->insereFim(a);


		else if ((3*p2->tam + p2->passoPermissao == 3*p3->tam + p3->passoPermissao) && 3*p2->tam + p2->passoPermissao < 3*p1->tam + p1->passoPermissao)
			if (3*p2->tam + p2->passoPermissao < 3*p3->tam + p3->passoPermissao)

					p2->insereFim(a);

			else

					p3->insereFim(a);

		else /*if ((3*p2->tam + p2->passoPermissao == 3*p3->tam + p3->passoPermissao) && 3*p2->tam + p2->passoPermissao > 3*p1->tam + p1->passoPermissao)*/

				p2->insereFim(a);
		
	}	
}

/*Função para Pouso e Decolagem, mais contador de combustível dos que já pousaram*/
double usoPista(Fila *p1, Fila *p2, Fila *p3, int passoAtual)
{
	int avioes = 0;
	int tcombustivel = 0;
	Aviao *a;

	/*Operando a Pista p1*/
	if (!p1->filaVazia() && p1->passoPermissao == 0)
	{
		/*Pouso ou Decolagem*/
		p1->passoPermissao = 2;
		a = p1->remove();
		if (a->pouso)
		{
			tcombustivel = a->tempo - (a->passoContato - passoAtual - 1);
			avioes++;
		}
		delete a;
	}
	/*Operando a Pista p2*/
	if (!p2->filaVazia() && p2->passoPermissao == 0)
	{
		/*Pouso ou Decolagem*/
		p2->passoPermissao = 2;
		a = p2->remove();
		if (a->pouso)
		{
			tcombustivel = a->tempo - (a->passoContato - passoAtual - 1);
			avioes++;
		}
		delete a;
	}

	/*Operando a Pista p3*/
	if (!p3->filaVazia() && p3->passoPermissao == 0)
	{
		/*Pouso ou Decolagem*/
		p3->passoPermissao = 2;
		a = p3->remove();
		if (a->pouso)
		{
			tcombustivel = a->tempo - (a->passoContato - passoAtual - 1);
			avioes++;
		}
		delete a;
	}
	if(avioes == 0)
		return 0;
	double media = (double) tcombustivel/((double)avioes);
	return media;
}


int main()
{
	int ts;
/*	cout<<"Aeroporto Internacional GRU\n";
	cout<<"________________________________\n\n";
	cout<<"Digite o tempo de simulação:";*/
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
	

	/* Considero cada passo de tempo de simulação seja equivalente a 6 minutos na vida real 
	*  Tendo visto que no aeroporto de GRU, chega no máximo 1000 aviões em um dia
	*  1000 aviões / 24 Horas =~ 41 aviões/Hora ==> 4 aviões/passo
 	*/

	while(i < ts)
	{
		qntdd = (rand() % 4);
		cout<<endl<<"Numero de Aviões que entraram em contato com a torre de comando: "<<qntdd<<endl;
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

			if(pouso)
			{
				//cout<<" Aeronave comunicando a Torre de Comando.\n"<<"______________________________________\n";
				if (emergencia)
					cout<<"Voo de emergencia:\n"<<emergencia<<"\n";
				cout<<"POUSO"<<endl;
				//cout<<"Solicitando permissão para POUSAR"<<endl;
				//cout<<"Sigla da Companhia aérea:\n"<<cia<<"\n";
				//cout<<"Numero do Vôo:\n"<<numero_voo<<"\n";
				//cout<<"Sigla do Aeroporto de Origem:\n"<<aeroporto<<"\n";
				//cout<<"Tempo de Combustível:\n"<<tempo<<"\n";
			} else {
				//cout<<" Aeronave comunicando a Torre de Comando.\n"<<"______________________________________\n";
				if (emergencia)
					cout<<"Voo de emergencia:\n"<<emergencia<<"\n";
				cout<<"DECOLAR"<<endl;
				//cout<<"Solicitando permissão para DECOLAR"<<endl;
				//cout<<"Sigla da Companhia aérea:\n"<<cia<<"\n";
				//cout<<"Numero do Vôo:\n"<<numero_voo<<"\n";
				//cout<<"Sigla do Aeroporto de Destino:\n"<<aeroporto<<"\n";
				//cout<<"Tempo Estimado da Viagem:\n"<<tempo<<"\n";
			}

			Aviao *novo = new Aviao;
			novo->informacoes(cia, aeroporto, numero_voo, tempo, i, pouso, emergencia);
			
			/*Função que verifica se alguém está ficando sem combustível e aí se remove o sujeito*/

			/*Função de entrar na fila*/
			cout<<endl<<"Antes de escolhendoPista"<<endl;
			cout<<"Tam p1: "<<p1.tam<<endl;
			cout<<"Tam p2: "<<p2.tam<<endl;
			cout<<"Tam p3: "<<p3.tam<<endl;
			escolhendoPista(&p1, &p2, &p3, novo);
			cout<<endl<<"depois de escolhendoPista"<<endl;
			cout<<"Tam p1: "<<p1.tam<<endl;
			cout<<"Tam p2: "<<p2.tam<<endl;
			cout<<"Tam p3: "<<p3.tam<<endl<<endl<<endl;

			qntdd--;
		}

		if (p1.passoPermissao > 0)
			p1.passoPermissao--;
		if (p2.passoPermissao > 0)
			p2.passoPermissao--;
		if (p3.passoPermissao > 0)
			p3.passoPermissao--;

		/*Função de Pouso ou Decolagem*/
		count.c_Pousado = (usoPista(&p1, &p2, &p3, i) + count.c_Pousado)/2;

		cout<<"depois do usoPista"<<endl;
		cout<<"Tam p1: "<<p1.tam<<endl;
		cout<<"Tam p2: "<<p2.tam<<endl;
		cout<<"Tam p3: "<<p3.tam<<endl;

/*		cout<<endl<<p1.tam+p2.tam+p3.tam<<" Aviões estão esperando para pousar e/ou decolar"<<endl;
		cout<<"Tempo médio de espera para pouso: "<<count.tempo_esperaPouso(&p1, &p2, &p3, i)<<endl;
		/*cout<<"Tempo médio de espera para decolagem: "<<count.tempo_esperaDecolagem(&p1, &p2, &p3, i)<<endl;
		cout<<"Quantidade média de combustı́vel dos aviões esperando para pousar: "<<count.combustivel_esperaPouso(&p1, &p2, &p3, i)<<endl;
		cout<<"Quantidade média de combustı́vel dos aviões que pousaram: "<<count.c_Pousado<<endl;
		/*cout<<"Quantidade de aviões pousando/decolando em condições de emergência: "<<endl;*/
		i++;
		cout <<endl <<"Pressione qualquer tecla para continuar..." << endl;
		getchar();
		cout<<endl<<"___________________________________________________________________"<<endl;
	}

	cout<<endl<<navioes<<" Aviões comunicaram a torre de comando"<<endl<<endl;
}