/*\__\__\__\__\__\__\__\__\__\__\__\__\__\__\__\__\__\__\__\__\__\__\__

  AO PREENCHER ESSE CABEÇALHO COM O MEU NOME E O MEU NÚMERO USP, 
  DECLARO QUE SOU O ÚNICO AUTOR E RESPONSÁVEL POR ESSE PROGRAMA. 
  TODAS AS PARTES ORIGINAIS DESSE EXERCÍCIO PROGRAMA (EP) FORAM 
  DESENVOLVIDAS E IMPLEMENTADAS POR MIM SEGUINDO AS INSTRUÇÕES DESSE EP
  E QUE PORTANTO NÃO CONSTITUEM PLÁGIO. DECLARO TAMBÉM QUE SOU RESPONSÁVEL
  POR TODAS AS CÓPIAS DESSE PROGRAMA E QUE EU NÃO DISTRIBUI OU FACILITEI A
  SUA DISTRIBUIÇÃO. ESTOU CIENTE QUE OS CASOS DE PLÁGIO SÃO PUNIDOS COM 
  REPROVAÇÃO DIRETA NA DISCIPLINA.

  Nome: DANIEL ANGELO ESTEVES LAWAND
  NUSP: 10297693

  ep0.cpp

  \__\__\__\__\__\__\__\__\__\__\__\__\__\__\__\__\__\__\__\__\__\__\__*/

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "aviao.h"
#include "fila.h"
#include "celula.h"
#include "categoria.h"
#include "contador.h"

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

void printaPista(Fila *p, int i, Contador *count)
{
	Celula *q, *r;
	q = p->ini->ante;
	r = q->ante;
	while(!p->filaVazia() && q != p->fim)
	{
		cout<<"- Avião ";
		printaInformacoes(q->aeronave);
		cout<<" está aguardando liberação para ";
		if(q->aeronave->pouso)
		{
			cout<<"pouso";
			count->tempoMedio_esperaPouso[0] += (i - q->aeronave->passoContato);
			count->tempoMedio_esperaPouso[1]++;
			count->combustivelMedio_esperaPouso[0] += q->aeronave->tempo - (i - q->aeronave->passoContato);
			count->combustivelMedio_esperaPouso[1]++;
		}
		else 
		{
			cout<<"decolagem";
			count->tempoMedio_esperaDecolagem[0] += (i - q->aeronave->passoContato);
			count->tempoMedio_esperaDecolagem[1]++;
		}
		cout<<endl;
		q = r;
		r = q->ante;
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
	//Retirando os vôos emergenciais da pista p e colocando no topo ou enviando para outro aeroporto
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

//Função que determina se vai colocar no fim ou no início da fila
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
	if (a->pouso && a->emergencia == 0) //POUSO
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
	} else //DECOLAGEM & Emergência
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
void usoPista(Fila *p, int passoAtual, Contador *count)
{
	Aviao *a;
	
	//Operando a Pista p
	if (!p->filaVazia() && p->tempoEspera == 0)
	{
		p->tempoEspera = 3;
		a = p->removeTopo();
		cout<<"- Avião ";
		printaInformacoes(a);
		if (a->pouso)
		{	
			cout<<" pousa na pista "<<p->num_pista;
			count->combustivel_Pousado[0] = a->tempo - (a->passoContato - passoAtual + 1) + count->combustivel_Pousado[0];
			count->combustivel_Pousado[1] = 1 + count->combustivel_Pousado[1];
		}
		else 
		{
			cout<<" decola na pista "<<p->num_pista;
		}
		if (a->emergencia != 0)
		{
			count->quantidadeVoos_emergencia++;
			cout<<" (Emergência)"<<endl;
		}
		else
		{
			cout<<endl;
		}
	}
	a = nullptr;
}

int main()
{
	int tempo_de_simulacao;
	cout<<"Aeroporto Internacional GRU\n";
	cout<<"________________________________\n\n";
	cout<<"Digite o tempo de simulação:";
	cin>>tempo_de_simulacao;
	cout<<"\n\n";

	//Variaveis do Avião
	std::string cia;
	std::string aeroporto;
	int numero_voo;
	int tempo;
	bool emergencia;
	bool pouso;

	//pista 1, 2, 3 e pista de espera
	Fila p1(1), p2(2), p3(3), p_espera(4);

	//passo atual
	int i = 0;

	int noTotal_avioes = 0;
	int quantidade_deContatos;
	double media_combustivel_Pousado;
	double media_espera_pouso;
	double media_espera_decolagem;
	double media_combustivel_esperaPouso;

	//semente dos nos. aleatórios
	srand(7);

	//variavel que armazena no. aleatório gerado
	int aleat;

	//Construtor do contador das informações pedidas no ep
	Contador count;

	while(i < tempo_de_simulacao)
	{
		cout<<"\nInstante: "<<i<<endl; 
		quantidade_deContatos = (rand() % 4);
		cout<<quantidade_deContatos<<" aviões enviam sinais"<<endl; 
		while (quantidade_deContatos > 0)
		{
			//Contador da quantidade de aeronaves por dia
			noTotal_avioes++;

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
			p_espera.insereTopo(novo);
			quantidade_deContatos--;
		}

		cout<<endl<<"Saída:"<<endl;
		while(!p_espera.filaVazia())
		{
			escolhendoPista(&p1, &p2, &p3, p_espera.removeTopo());
		}

		//Tempo de espera das pistas sendo diminuído
		if (p1.tempoEspera > 0)
			p1.tempoEspera--;
		if (p2.tempoEspera > 0)
			p2.tempoEspera--;
		if (p3.tempoEspera > 0)
			p3.tempoEspera--;

		count.quantidadeVoos_emergencia = 0;
		//Função de Pouso ou Decolagem
		usoPista(&p1, i, &count);
		usoPista(&p2, i, &count);
		usoPista(&p3, i, &count);	
		//count.combustivel_Pousado += usoPista(&p1, i);
		//count.combustivel_Pousado += usoPista(&p2, i);
		//count.combustivel_Pousado += usoPista(&p3, i);	

		//Verifica se alguém está ficando sem combustível e manda pro topo como emergência
		verificandoCombustivel(&p1, i);
		verificandoCombustivel(&p2, i);
		verificandoCombustivel(&p3, i);

		count.tempoMedio_esperaPouso[0] = 0;
		count.tempoMedio_esperaPouso[1] = 0;

		count.tempoMedio_esperaDecolagem[0] = 0;
		count.tempoMedio_esperaDecolagem[1] = 0;

		count.combustivelMedio_esperaPouso[0] = 0;
		count.combustivelMedio_esperaPouso[1] = 0;

		printaPista(&p1, i, &count);
		printaPista(&p2, i, &count);
		printaPista(&p3, i, &count);


		if (count.tempoMedio_esperaPouso[1] != 0)
			media_espera_pouso = count.tempoMedio_esperaPouso[0]/count.tempoMedio_esperaPouso[1];
		else
			media_espera_pouso = 0;

		cout<<"Tempo médio de espera para pouso: "<<count.tempoMedio_esperaPouso[0]<<"/"<<count.tempoMedio_esperaPouso[1]<<" == "<<media_espera_pouso<<endl;


		if (count.tempoMedio_esperaDecolagem[1]!= 0)
			media_espera_decolagem = count.tempoMedio_esperaDecolagem[0]/count.tempoMedio_esperaDecolagem[1];
		else
			media_espera_decolagem = 0;

		cout<<"Tempo médio de espera para decolagem: "<<count.tempoMedio_esperaDecolagem[0]<<"/"<<count.tempoMedio_esperaDecolagem[1]<<" == "<<media_espera_decolagem<<endl;


		if (count.combustivelMedio_esperaPouso[1] != 0)
			media_combustivel_esperaPouso = count.combustivelMedio_esperaPouso[0]/count.combustivelMedio_esperaPouso[1];
		else
			media_combustivel_esperaPouso = 0;

		cout<<"Quantidade média de combustı́vel disponı́vel dos aviões esperando para pousar: "<<count.combustivelMedio_esperaPouso[0]<<"/"<<count.combustivelMedio_esperaPouso[1]<<" == "<<media_combustivel_esperaPouso<<endl;


		if (count.combustivel_Pousado[1] != 0)
			media_combustivel_Pousado = count.combustivel_Pousado[0]/count.combustivel_Pousado[1];
		else
			media_combustivel_Pousado = 0;

		cout<<"Quantidade média de combustı́vel disponı́vel dos aviões que pousaram: "<<count.combustivel_Pousado[0]<<"/"<<count.combustivel_Pousado[1]<<" == "<<media_combustivel_Pousado<<endl;

		cout<<"Quantidade de aviões pousando/decolando em condições de emergência no momento: "<<count.quantidadeVoos_emergencia<<endl;

		i++;
	}
	cout<<endl<<noTotal_avioes<<" Aviões comunicaram a torre de comando"<<endl<<endl;
}