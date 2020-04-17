#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Aviao.h"
#include "Fila.h"
#include "Celula.h"
#include "Categoria.h"
#include "Contador.h"

using namespace std;


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

void verificandoCombustivel(Fila *p, Fila *pe, int passoAtual)
{
	Aviao *a;
	Celula *q, *r;
	q = p->fim->prox;
	r = q->prox;
	while (q != p->ini)
	{	
		if (q->aeronave->pouso)
		{
			if (passoAtual - q->aeronave->passoContato == q->aeronave->tempo)
			{
				a = p->removePos(q);
				a->emergencia = -1;
				pe->insereTopo(a);
			} else if (q->aeronave->tempo < passoAtual - q->aeronave->passoContato)
			{
				a = p->removePos(q);
				cout<<"- Avião ";
				printaInformacoes(a);
				cout<<" foi desviado para Viracopos"<<endl; 
				delete a;
			}
		} else 
		{
			double tempoNoPatio = ((double) q->aeronave->tempo) * 0.1;			
			if (tempoNoPatio <= (double)(passoAtual - q->aeronave->passoContato))
			{
				a = p->removePos(q);
				a->emergencia = 1;
				pe->insereFim(a);
			}
		}
		q = r;
		r = q->prox;
	}
}

//Função que determina se vaii colocar no fim ou no início da fila
void poeNaFila(Fila *p, Aviao *a)
{
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
		if(3*(p1->tam) + p1->passoPermissao < 3*(p2->tam) + p2->passoPermissao)
		{
			if (a->tempo > 3*p1->tam + p1->passoPermissao)
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
		} else if (3*(p2->tam) + p2->passoPermissao < 3*(p1->tam) + p1->passoPermissao)
		{
			if (a->tempo > 3*p2->tam + p2->passoPermissao)
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
			if (a->tempo > 3*p1->tam + p1->passoPermissao)
			{
				aleat = (rand()%100);
				if (aleat < 50){
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
		if (p3->tam + p3->passoPermissao == p2->tam + p2->passoPermissao && p3->tam + p3->passoPermissao == p1->tam + p1->passoPermissao){
			poeNaFila(p3,a);
		}
		//p1 menor
		else if (p1->tam + p1->passoPermissao <= p2->tam + p2->passoPermissao && p1->tam + p1->passoPermissao <= p3->tam + p3->passoPermissao){
			poeNaFila(p1,a);
		}
		//p2 menor
		else if (p2->tam + p2->passoPermissao <= p3->tam + p3->passoPermissao && p2->tam + p2->passoPermissao <= p1->tam + p1->passoPermissao){
			poeNaFila(p2,a);
		}
		//p3 menor
		else if (p3->tam + p3->passoPermissao <= p2->tam + p2->passoPermissao && p3->tam + p3->passoPermissao <= p1->tam + p1->passoPermissao){
			poeNaFila(p3,a);
		}
		//com certeza o p3 é maior
		else if (p1->tam + p1->passoPermissao == p2->tam + p2->passoPermissao)
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
		else if (p1->tam + p1->passoPermissao == p3->tam + p3->passoPermissao)
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
		else //if (p2->tam + p2->passoPermissao ==  p3->tam + p3->passoPermissao)
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
	if (!p->filaVazia() && p->passoPermissao == 0)
	{
		p->LeFila();
		p->passoPermissao = 3;
		a = p->removeTopo();

		cout<<"- Avião ";
		cout<<"FALA MoNSTRO"<<endl;
		cout<<a->cia<<"CIA"<<endl;
		cout<<"FALA MINSTRO"<<endl;
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

	/*pista 1, 2, 3 e fila dos de emergência*/
	Fila p1(0, 1), p2(0, 2), p3(0, 3), pe(1, 0);

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
		//cout<<endl<<"Numero de Aviões que entraram em contato com a torre de comando: "<<qntdd<<endl;
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

		//	cout<<" Aeronave comunicando a Torre de Comando.\n"<<"______________________________________\n";

			printaContato(novo);

			q = pe.fim->prox;
			r = q->prox;

			//EMERGÊNCIA DONE
			if (novo->emergencia != 0)
			{
				if (novo->emergencia == -1) 
				{
					pe.insereTopo(novo);
				}	
				else
				{ 
					pe.insereFim(novo);
				}
				//Escolher a pista para no maximo 3 aviões da fila de emergência
				for (k = 0; k < 3 && q != pe.ini; k++)
				{
					if (q == pe.ini)
						a = pe.removePos(q);
					q = r;
					r = q->prox;
					escolhendoPista(&p1, &p2, &p3, a);
				}
			} else 
			{
				//Escolher a pista para no maximo 3 aviões da fila de emergência
				for (k = 0; k < 3 && q != pe.ini; k++)
				{
					a = pe.removePos(q);
					escolhendoPista(&p1, &p2, &p3, a);
					q = r;
					r = q->prox;
				}
				escolhendoPista(&p1, &p2, &p3, novo);		
			}


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

	//	cout<<"sai do while"<<endl;
		if (p1.passoPermissao > 0)
			p1.passoPermissao--;
		if (p2.passoPermissao > 0)
			p2.passoPermissao--;
		if (p3.passoPermissao > 0)
			p3.passoPermissao--;

	//	cout<<"passei dos ifs"<<endl;
		//Função de Pouso ou Decolagem

		count.c_Pousado += usoPista(&p1, i);

		count.c_Pousado += usoPista(&p2, i);
		count.c_Pousado += usoPista(&p3, i);	
	//	cout<<"passei do c_pousado"<<endl;

		cout<<endl;

		/*Verifica se alguém está ficando sem combustível e manda pra fila de emergência*/
/*		verificandoCombustivel(&p1, &pe, i);
		verificandoCombustivel(&p2, &pe, i);
		verificandoCombustivel(&p3, &pe, i);*/

	//	cout<<"Pista 1"<<endl;
		//printaPista(&p1);
		//cout<<"Pista 2"<<endl;
		//printaPista(&p2);
	//	cout<<"Pista 3"<<endl;
	//	printaPista(&p3);

		//cout<<"Pista de Emergência"<<endl;
		//printaPista(&pe);

		/*cout<<endl<<p1.tam+p2.tam+p3.tam<<" Aviões estão esperando para pousar e/ou decolar"<<endl;
		cout<<"Tempo médio de espera para pouso: "<<count.tempoMedio_esperaPouso(&p1, &p2, &p3, i)<<endl;
		/*cout<<"Tempo médio de espera para decolagem: "<<count.tempoMedio_esperaDecolagem(&p1, &p2, &p3, i)<<endl;
		cout<<"Quantidade média de combustı́vel dos aviões esperando para pousar: "<<count.combustivelMedio_esperaPouso(&p1, &p2, &p3, i)<<endl;
		cout<<"Quantidade média de combustı́vel dos aviões que pousaram: "<<count.c_Pousado<<endl;
		/*cout<<"Quantidade de aviões pousando/decolando em condições de emergência: "<<endl;*/

		i++;

	}
/*
	cout<<"Pista 3"<<endl;
	printaPista(&p3);
	

	Aviao* a1;
	a1 = p3.removeTopo();

	cout<<endl<<"Depois da Remoção"<<endl<<"Pista 3"<<endl;
	printaPista(&p3);

	a1 = p3.removeTopo();

	cout<<endl<<"Depois da 2 Remoção"<<endl<<"Pista 3"<<endl;
	printaPista(&p3);

	Celula* q1;
	q1 = p3.ini->ante;
	a1 = p3.removePos(q1);

	cout<<endl<<"Depois da 3 Remoção"<<endl<<"Pista 3"<<endl;
	printaPista(&p3);*/


	cout<<endl<<navioes<<" Aviões comunicaram a torre de comando"<<endl<<endl;
}