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

  fila.h

  \__\__\__\__\__\__\__\__\__\__\__\__\__\__\__\__\__\__\__\__\__\__\__*/
#ifndef FILA_H
#define FILA_H
#include "aviao.h"
#include "celula.h"

class Fila
{
	public:
		int num_pista;
		int tam;
		int tempoEspera;
		double combustivelMedioFilaPouso;
		Aviao* a = new Aviao;
		Aviao* b = new Aviao;
		Celula* ini = new Celula(a);
		Celula* fim = new Celula(b);
		Fila(int numero_da_pista);
		~Fila();
		void insereFim(Aviao*);
		void insereTopo(Aviao*);
		Aviao* removeTopo();
		void moveParaTopo(Celula *q);
		Aviao* removePos(Celula *q);
		Aviao* topo();
		int tamanho();
	  	bool filaVazia();
};

#endif