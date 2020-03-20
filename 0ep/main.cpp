#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Aviao.h"
#include "Fila.h"
#include "Celula.h"
#include "Categoria.h"
#include "Contador.h"
/*
	if (a->emergencia == -1)
	{
		//É BOM PENSAR NO TAMANHO TBM PRA MELHOR DISTRIBUIR OS AVIÕES
		if (p1->topo()->emergencia != -1)
			p1->insereTopo(a);
		else if (p2->topo()->emergencia != -1)
			p2->insereTopo(a);
		else if (p3->topo()->emergencia != -1)
			p3->insereTopo(a);
	}
*/

using namespace std;


void printaInformacoes (Aviao *a)
{
	cout<<"Vôo No: "<<a->numero_voo<<" | "<<"Cia: "<<a->cia<<" | ";
	if(a->pouso)
	{
		cout<<"Origem: "<<a->aeroporto<<" | "<<"POUSO | ";
		if (a->emergencia)
			cout<<"EMERGÊNCIA | ";
		cout<<"Tempo Combustível: "<<a->tempo<<endl;
	} else {
		cout<<"Destino: "<<a->aeroporto<<" | "<<"DECOLAR | ";
		if (a->emergencia)
			cout<<"EMERGÊNCIA | ";
		cout<<"Tempo de Viagem: "<<a->tempo<<endl;
	}
}

void verificandoCombustivel(Fila *p, Fila *pe, int passoAtual)
{
	Aviao *a;
	Celula *q, *r;
	q = p->fim->prox;
	r = q->prox;
	cout <<endl <<"Iniciando o verificaCombustivel da pista x..." << endl;
	cout<<endl<<"___________________________________________________________________"<<endl;
	getchar();
	cout<<"LeFila"<<endl;
	p->LeFila();

	while (q != p->ini)
	{	
		cout<<"verificando Combustivel da aeronave:"<<endl;
		getchar();
		if (q->aeronave->pouso)
		{
			printaInformacoes(q->aeronave);
			if (passoAtual - q->aeronave->passoContato == q->aeronave->tempo)
			{
				cout<<"Virou emergencia -1"<<endl;
				a = p->removePos(q);
				a->emergencia = -1;
				pe->insereTopo(a);
			} else if (q->aeronave->tempo < passoAtual - q->aeronave->passoContato)
			{
				a = p->removePos(q);
				cout<<"Foi pra Viracopos"<<endl; 
				delete a;
			}
		} else 
		{
			printaInformacoes(q->aeronave);
			double tempoNoPatio = ((double) q->aeronave->tempo) * 0.1;			
			if (tempoNoPatio <= (double)(passoAtual - q->aeronave->passoContato))
			{
				cout<<"Virou emergencia 1"<<endl;
				a = p->removePos(q);
				a->emergencia = 1;
				pe->insereFim(a);
			}
		}
		q = r;
		r = q->prox;
	}
	cout <<endl <<"Fim do verificaCombustivel da pista x" << endl;
	cout<<endl<<"___________________________________________________________________"<<endl;
	getchar();

}

/*Função de entrar na fila --  Acredito que bem feita
Talvez eu possa alterar esse primeiro if e criar uma nova função para escolher a pista
com base na emergência?

*/
void escolhendoPista(Fila *p1, Fila *p2, Fila *p3, Fila *pe, Aviao *a)
{
	int aleat;
	//EMERGÊNCIA DONE
	if (a->emergencia != 0)
	{
		if (a->emergencia == -1)
			pe->insereTopo(a);
		else 
			pe->insereFim(a);
	} else if (a->pouso) //POUSO DONE
	{
		//Se o tempo de espera de p1 é menor que p2
		if(3*(p1->tam) + p1->passoPermissao < 3*(p2->tam) + p2->passoPermissao)
		{
			if (a->tempo > 3*p1->tam + p1->passoPermissao)
			{
				p1->insereFim(a);
				cout<<"Inseriu na P1";
				getchar();
				cout<<endl<<"___________________________________________________________________"<<endl;
			}
			else
			{
				cout<<"Foi pra Viracopos"<<endl; 
				delete a;
			}
		} else if (3*(p2->tam) + p2->passoPermissao < 3*(p1->tam) + p1->passoPermissao)
		{
			if (a->tempo > 3*p2->tam + p2->passoPermissao)
			{
				p2->insereFim(a);
				cout<<"Inseriu na P2";
				getchar();
				cout<<endl<<"___________________________________________________________________"<<endl;
			}
			else
			{
				cout<<"Foi pra Viracopos"<<endl;
				delete a;
			}
		} else //Se são iguais os tempos escolho aleatoriamente p1 ou p2
		{
			if (a->tempo > 3*p1->tam + p1->passoPermissao)
			{
				aleat = (rand()%100);
				if (aleat < 50){
					p1->insereFim(a);
					cout<<"Inseriu na P1";
					getchar();
					cout<<endl<<"___________________________________________________________________"<<endl;
				}
				else {
					p2->insereFim(a);
					cout<<"Inseriu na P2";
					getchar();
					cout<<endl<<"___________________________________________________________________"<<endl;
				}
			}
			else
			{
				cout<<"Foi pra Viracopos"<<endl;
				delete a;
			}
		}
	} else //DECOLAGEM DONE 
	{
		//Se o tempo de espera das 3 pistas forem iguais aloco no na pista 3 que tem menor probabilidade de alocar voos
		if (p3->tam + p3->passoPermissao == p2->tam + p2->passoPermissao && p3->tam + p3->passoPermissao == p1->tam + p1->passoPermissao){
			p3->insereFim(a);
			cout<<"Inseriu na P3";
			getchar();
			cout<<endl<<"___________________________________________________________________"<<endl;
		}
		//p1 menor
		else if (p1->tam + p1->passoPermissao <= p2->tam + p2->passoPermissao && p1->tam + p1->passoPermissao <= p3->tam + p3->passoPermissao){
			p1->insereFim(a);
			cout<<"Inseriu na P1";
			getchar();
			cout<<endl<<"___________________________________________________________________"<<endl;
		}
		//p2 menor
		else if (p2->tam + p2->passoPermissao <= p3->tam + p3->passoPermissao && p2->tam + p2->passoPermissao <= p1->tam + p1->passoPermissao){
			p2->insereFim(a);
			cout<<"Inseriu na P2";
			getchar();
			cout<<endl<<"___________________________________________________________________"<<endl;
		}
		//p3 menor
		else if (p3->tam + p3->passoPermissao <= p2->tam + p2->passoPermissao && p3->tam + p3->passoPermissao <= p1->tam + p1->passoPermissao){
			p3->insereFim(a);
			cout<<"Inseriu na P3";
			getchar();
			cout<<endl<<"___________________________________________________________________"<<endl;
		}
		//com certeza o p3 é maior
		else if (p1->tam + p1->passoPermissao == p2->tam + p2->passoPermissao)
		{
			aleat = (rand()%100);
			if (aleat < 50){
				p1->insereFim(a);
				cout<<"Inseriu na P1";
				getchar();
				cout<<endl<<"___________________________________________________________________"<<endl;
			}
			else {
				p2->insereFim(a);
				cout<<"Inseriu na P2";
				getchar();
				cout<<endl<<"___________________________________________________________________"<<endl;
			}
		}
		//com certeza o p2 é maior
		else if (p1->tam + p1->passoPermissao == p3->tam + p3->passoPermissao)
		{
			aleat = (rand()%100);
			if (aleat < 50){
				p1->insereFim(a);
				cout<<"Inseriu na P1";
				getchar();
				cout<<endl<<"___________________________________________________________________"<<endl;
			}
			else {
				p3->insereFim(a);
				cout<<"Inseriu na P3";
				getchar();
				cout<<endl<<"___________________________________________________________________"<<endl;				
			}
		}
		//com certeza o p1 é maior
		else //if (p2->tam + p2->passoPermissao ==  p3->tam + p3->passoPermissao)
		{
			aleat = (rand()%100);
			if (aleat < 50){
				p3->insereFim(a);
				cout<<"Inseriu na P3";
				getchar();
				cout<<endl<<"___________________________________________________________________"<<endl;
			}
			else {
				p2->insereFim(a);
				cout<<"Inseriu na P2";
				getchar();
				cout<<endl<<"___________________________________________________________________"<<endl;
			}
		}
		
	}	
}

/*Função para Pouso e Decolagem, mais contador de combustível dos que já pousaram*/
double usoPista(Fila *p1, Fila *p2, Fila *p3, Fila *pe, int passoAtual)
{
	int avioes = 0;
	int tcombustivel = 0;
	Aviao *a;

	/*Operando a Pista p1*/
	if (!p1->filaVazia() && p1->passoPermissao == 0)
	{
		/*Pouso ou Decolagem*/
		p1->passoPermissao = 3;
		a = p1->removeTopo();
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
		p2->passoPermissao = 3;
		a = p2->removeTopo();
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
		p3->passoPermissao = 3;
		a = p3->removeTopo();
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

	/*pista 1, 2, 3 e fila dos de emergência*/
	Fila p1(0), p2(0), p3(0), pe(1);


	int i = 0;
	int navioes = 0;
	int qntdd;
	int aleat;
	srand(7);
	

	/* Considero cada passo de tempo de simulação seja equivalente a 6 minutos na vida real 
	*  Tendo visto que no aeroporto de GRU, chega no máximo 1000 aviões em um dia
	*  1000 aviões / 24 Horas =~ 41 aviões/Hora ==> 4 aviões/passo
 	*/

	while(i < ts)
	{
		qntdd = (rand() % 10);
		cout<<endl<<"Numero de Aviões que entraram em contato com a torre de comando: "<<qntdd<<endl;
		while (qntdd > 0)
		{
			//Contador da quantidade de aeronaves por dia
			navioes++;

			numero_voo = (rand() % 9999);

			aeroporto = aeroportos[(rand() % 53)];

			cia = companhias[(rand() % 32)];

			tempo = (rand()%100);

			aleat = (rand()%100);
			pouso = 0;
			if (aleat < 50)
				pouso = 1;

			aleat = (rand()%100);
			emergencia = 0;
			//Considero 20% a probabilidade de um vôo ser emergencial
			if(aleat <  20)
				emergencia = 1;

			Aviao *novo = new Aviao;
			novo->informacoes(cia, aeroporto, numero_voo, tempo, i, pouso, emergencia);

			cout<<" Aeronave comunicando a Torre de Comando.\n"<<"______________________________________\n";

			printaInformacoes(novo);


			
			

			/*Função de entrar na fila*/
			cout<<endl<<"Antes de escolhendoPista"<<endl;
			cout<<"Tam p1: "<<p1.tam<<endl;
			cout<<"Tam p2: "<<p2.tam<<endl;
			cout<<"Tam p3: "<<p3.tam<<endl;
			escolhendoPista(&p1, &p2, &p3, &pe, novo);
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

		//Função de Pouso ou Decolagem
		count.c_Pousado = (usoPista(&p1, &p2, &p3, &pe, i) + count.c_Pousado)/2;

		cout<<"depois do usoPista"<<endl;
		cout<<"Tam p1: "<<p1.tam<<endl;
		cout<<"Tam p2: "<<p2.tam<<endl;
		cout<<"Tam p3: "<<p3.tam<<endl;


		cout<<endl;



		/*Verifica se alguém está ficando sem combustível e manda pra fila de emergência*/
		verificandoCombustivel(&p1, &pe, i);
		verificandoCombustivel(&p2, &pe, i);
		verificandoCombustivel(&p3, &pe, i);


		/*cout<<endl<<p1.tam+p2.tam+p3.tam<<" Aviões estão esperando para pousar e/ou decolar"<<endl;
		cout<<"Tempo médio de espera para pouso: "<<count.tempoMedio_esperaPouso(&p1, &p2, &p3, i)<<endl;
		/*cout<<"Tempo médio de espera para decolagem: "<<count.tempoMedio_esperaDecolagem(&p1, &p2, &p3, i)<<endl;
		cout<<"Quantidade média de combustı́vel dos aviões esperando para pousar: "<<count.combustivelMedio_esperaPouso(&p1, &p2, &p3, i)<<endl;
		cout<<"Quantidade média de combustı́vel dos aviões que pousaram: "<<count.c_Pousado<<endl;
		/*cout<<"Quantidade de aviões pousando/decolando em condições de emergência: "<<endl;*/

		i++;

	}
	cout<<endl<<navioes<<" Aviões comunicaram a torre de comando"<<endl<<endl;
}