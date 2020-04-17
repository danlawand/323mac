#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Aviao.h"
#include "Fila.h"
#include "Celula.h"
#include "Categoria.h"
#include "Contador.h"

using namespace std;


/*
	Add: 
		void Fila::moveParaTopo(Celula *q);

	Consegui resolver as questões de emergência e ninguém caiu
	Poucos vôos foram desviados.

	O que falta fazer:
		Padronizar as saídas
		E mostrar as saídas que o carlinhos pediu para ter (tempo médio de espera, e etc...)


*/






//Função que printa no. do voo, cia e aeroporto
void printaInformacoes (Aviao *a)
{
	if(a->pouso)
	{
		cout<<a->cia<<" "<<a->numero_voo<<" "<<a->aeroporto<<"/GRU";

	} else {
		cout<<a->cia<<" "<<a->numero_voo<<" GRU/"<<a->aeroporto;
	}

}

void printaPista(Fila *p)
{
	int i =  1;
	Celula *q, *r;
	q = p->ini->ante;
	r = q->ante;
	while(!p->filaVazia() && q != p->fim)
	{
		cout<<i<<"  ";
		printaInformacoes(q->aeronave);
		cout<<endl;
		q = r;
		r = q->ante;
		i++;
	}
}


//Função que printa informações detalhadas de quando foi feito o contato
void printaContato (Aviao *a)
{
	printaInformacoes(a);

	if(a->pouso)
	{
		if (a->emergencia)
			cout<<" - Pouso de Emergência - ";
		else 
			cout<<" - Pouso - ";
		cout<<a->tempo<<" unidade de Combustível"<<endl;
	} else {
		if (a->emergencia)
			cout<<" - Decolagem de Emergência - ";
		else 
			cout<<" - Decolagem - ";
		cout<<"Tempo de Voo: "<<a->tempo<<" unidades"<<endl;
	}
}

void verificandoCombustivel(Fila *p, int passoAtual)
{
	Aviao *a;
	Celula *q, *r;
	q = p->ini->ante;
	r = q->ante;
	//Retirando os vôos emergenciais da pista p e colocando na pista pe ou enviando para outro aeroporto
	while (q != p->fim)
	{	
		if (q->aeronave->pouso)
		{
			if (passoAtual - q->aeronave->passoContato > q->aeronave->tempo)
			{
				a = p->removePos(q);
				cout<<"- Avião ";
				printaInformacoes(a);
				cout<<" caiu por falta de combustível."<<endl; 
				delete a;
			} 
			else if (passoAtual - q->aeronave->passoContato == q->aeronave->tempo)
			{
				a = p->removePos(q);
				cout<<"- Avião ";
				printaInformacoes(a);
				cout<<" foi desviado para Viracopos"<<endl; 
				delete a;
			}
			//menos tempoEspera para ver se dá tempo de espera na pista
			else if (passoAtual - q->aeronave->passoContato == q->aeronave->tempo - p->tempoEspera)
			{
				p->moveParaTopo(q);
			}
		} else 
		{
			double tempoNoPatio = ((double) q->aeronave->tempo) * 0.1;			
			if (tempoNoPatio <= (double)(passoAtual - q->aeronave->passoContato) && q != p->ini->ante)
			{
				p->moveParaTopo(q);
			}
		}
		q = r;
		r = q->ante;
	}
}

//Função que determina se vaii colocar no fim ou no início da fila
void poeNaFila(Fila *p, Aviao *a)
{
	//se for emergencial põe no topo
	if (a->emergencia != 0)
		p->insereTopo(a);
	else
		p->insereFim(a);
}

//Função que determina qual pista está mais livre
void escolhendoPista(Fila *p1, Fila *p2, Fila *p3, Aviao *a)
{
	int aleat;
	if (a->pouso) //POUSO DONE
	{
		//Se o tempo de espera de p1 é menor que p2
		if(3*(p1->tam) + p1->tempoEspera < 3*(p2->tam) + p2->tempoEspera)
		{
			if (a->tempo > 3*p1->tam + p1->tempoEspera)
			{
				poeNaFila(p1,a);
			}
			else
			{
				cout<<"- Avião ";
				printaInformacoes(a);
				cout<<" foi desviado para Viracopos"<<endl; 
				delete a;
			}
		} else if (3*(p2->tam) + p2->tempoEspera < 3*(p1->tam) + p1->tempoEspera)
		{
			if (a->tempo > 3*p2->tam + p2->tempoEspera)
			{
				poeNaFila(p2,a);
			}
			else
			{
				cout<<"- Avião ";
				printaInformacoes(a);
				cout<<" foi desviado para Viracopos"<<endl;
				delete a;
			}
		} else //Se são iguais os tempos escolho aleatoriamente p1 ou p2
		{
			if (a->tempo > 3*p1->tam + p1->tempoEspera)
			{
				aleat = (rand()%100);
				if (aleat < 50)
				{
					poeNaFila(p1,a);
				}
				else {
					poeNaFila(p2,a);
				}
			}
			else
			{
				cout<<"- Avião ";
				printaInformacoes(a);
				cout<<" foi desviado para Viracopos"<<endl;
				delete a;
			}
		}
	} else //DECOLAGEM DONE 
	{
		//Se o tempo de espera das 3 pistas forem iguais aloco no na pista 3 que tem menor probabilidade de alocar voos
		if (p3->tam + p3->tempoEspera == p2->tam + p2->tempoEspera && p3->tam + p3->tempoEspera == p1->tam + p1->tempoEspera){
			poeNaFila(p3,a);
		}
		//p1 menor
		else if (p1->tam + p1->tempoEspera <= p2->tam + p2->tempoEspera && p1->tam + p1->tempoEspera <= p3->tam + p3->tempoEspera){
			poeNaFila(p1,a);
		}
		//p2 menor
		else if (p2->tam + p2->tempoEspera <= p3->tam + p3->tempoEspera && p2->tam + p2->tempoEspera <= p1->tam + p1->tempoEspera){
			poeNaFila(p2,a);
		}
		//p3 menor
		else if (p3->tam + p3->tempoEspera <= p2->tam + p2->tempoEspera && p3->tam + p3->tempoEspera <= p1->tam + p1->tempoEspera){
			poeNaFila(p3,a);
		}
		//com certeza o p3 é maior
		else if (p1->tam + p1->tempoEspera == p2->tam + p2->tempoEspera)
		{
			aleat = (rand()%100);
			if (aleat < 50){
				poeNaFila(p1,a);
			}
			else {
				poeNaFila(p2,a);
			}
		}
		//com certeza o p2 é maior
		else if (p1->tam + p1->tempoEspera == p3->tam + p3->tempoEspera)
		{
			aleat = (rand()%100);
			if (aleat < 50){
				poeNaFila(p1,a);
			}
			else {
				poeNaFila(p3,a);	
			}
		}
		//com certeza o p1 é maior
		else //if (p2->tam + p2->tempoEspera ==  p3->tam + p3->tempoEspera)
		{
			aleat = (rand()%100);
			if (aleat < 50){
				poeNaFila(p3,a);
			}
			else {
				poeNaFila(p2,a);
			}
		}
		
	}	
}

//Função para Pouso e Decolagem, mais contador de combustível dos que já pousaram
double usoPista(Fila *p, int passoAtual)
{
	int avioes = 0;
	int tcombustivel = 0;
	Aviao *a;
	
	/*Operando a Pista p*/
	if (!p->filaVazia() && p->tempoEspera == 0)
	{
		p->tempoEspera = 3;
		a = p->removeTopo();
		printaInformacoes(a);

		if (a->pouso)
		{	
			if(p->num_pista != 0)
				cout<<" pousa na pista "<<p->num_pista;
			tcombustivel = a->tempo - (a->passoContato - passoAtual - 1);
			avioes++;
		}
		else 
		{
			if(p->num_pista != 0)
				cout<<" decola na pista "<<p->num_pista;
		}
		if (a->emergencia != 0)
			cout<<" (Emergência)"<<endl;
		else
			cout<<endl;
	}
	a = nullptr;

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

	//pista 1, 2, 3
	Fila p1(1), p2(2), p3(3);

	int i = 0;
	int navioes = 0;
	int qntdd;
	int aleat;
	srand(7);

	int k = 0;
	Aviao *a;
	Celula *q, *r;

	/* Considero cada passo de tempo de simulação seja equivalente a 6 minutos na vida real 
	*  Tendo visto que no aeroporto de GRU, chega no máximo 1000 aviões em um dia
	*  1000 aviões / 24 Horas =~ 41 aviões/Hora ==> 4 aviões/passo
 	*/

	while(i < ts)
	{
		cout<<"\nInstante: "<<i<<endl; 
		qntdd = (rand() % 4);
		cout<<qntdd<<" aviões enviam sinais"<<endl; 
		while (qntdd > 0)
		{
			//Contador da quantidade de aeronaves por dia
			navioes++;

			numero_voo = 1000 + (rand() % 8999);

			aeroporto = aeroportos[(rand() % 53)];

			cia = companhias[(rand() % 32)];

			tempo = (rand()%100);

			
			aleat = (rand()%100);
			emergencia = 0;
			//Considero 20% a probabilidade de um vôo ser emergencial
			if(aleat <  20)
				emergencia = 1;

			aleat = (rand()%100);
			pouso = 0;
			if (aleat < 50)
			{
				pouso = 1;
				if (tempo == 0)
					emergencia = -1;
			}
			

			Aviao *novo = new Aviao;
			novo->informacoes(cia, aeroporto, numero_voo, tempo, i, pouso, emergencia);

			printaContato(novo);
			escolhendoPista(&p1, &p2, &p3, novo);


/*
	Instante 0:

	(4 aviões enviam sinais)
	LA329 ACA/GRU - Pouso - 2 unidades de Combustível
	LA563 ADZ/GRU - Pouso - 2 unidades de Combustível
	LA140 GRU/BOG - Decolagem - Tempo de Voo: 60 unidades
	JB666 GRU/BSB - Decolagem de Emergência - Tempo de Voo: 30 unidades 

	Saída:
	- Avião LA329 ACA/GRU pousa na pista 1 
	- Avião LA563 ADZ/GRU pousa na pista 2
	- Avião LA923 ANF/GRU pousa na pista 3 (Emergência)
	- Avião LA734 AQP/GRU é desviado para aeroporto vizinho 
	- Avião LA923 GRU/ANF está aguardando liberação para decolagem
	- Avião LA734 GRU/AQP está aguardando liberação para decolagem
*/

			qntdd--;
		}

		//Tempo de espera sendo diminuído
		if (p1.tempoEspera > 0)
			p1.tempoEspera--;
		if (p2.tempoEspera > 0)
			p2.tempoEspera--;
		if (p3.tempoEspera > 0)
			p3.tempoEspera--;

		//Função de Pouso ou Decolagem
		count.c_Pousado += usoPista(&p1, i);
		count.c_Pousado += usoPista(&p2, i);
		count.c_Pousado += usoPista(&p3, i);	
		cout<<endl;

		//Verifica se alguém está ficando sem combustível e manda pro topo como emergência
		verificandoCombustivel(&p1, i);
		verificandoCombustivel(&p2, i);
		verificandoCombustivel(&p3, i);


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