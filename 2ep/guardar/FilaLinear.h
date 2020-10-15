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

  FilaLinear.h

  \__\__\__\__\__\__\__\__\__\__\__\__\__\__\__\__\__\__\__\__\__\__\__*/
#ifndef _FILALINEAR_H
#define _FILALINEAR_H
#include "Node.h"
#include <stdio.h>
#define bool int

typedef struct sequenciaFila* Fila;
struct sequenciaFila {
  No cabeca;
  No last;
  No current;

  /*Armazena o tamanho*/
  int n;

  /*Numero de processos terminados naquela fila*/
  int n_processosTerminados;

  /*Somatório do tempo de Permanência no Sistema*/
  int sumPermanencia;
};

/*Construtor*/
Fila filaLinearInit();

/*Adiciona Processo na Fila de Espera*/
void addProcessoFilaLinear(Processo, Fila);

/*Adiciona No na Fila de Impressao ou na fila de processos Acabados*/
void addNodeFilaLinear(No, Fila);

void incrementaProcessosTerminadosLinear(Fila);

void somatorioTempoPermanenciaLinear(Fila);

/*Imprime a fila em determinado UT*/
void imprimeFilaLinear(Fila, int);

/*Retorna o tamanho da Fila*/
int filaSize(Fila);

/*Devolve true se a fila está vazia*/
bool filaIsEmpty(Fila);

/*Retira No da fila*/
No retiraNodeFilaLinear(Fila);

/*Retira Processo da fila*/
Processo retiraProcessoEspera(Fila);

Processo processoAtualEspera(Fila);

/*Destrutor*/
void filaFree();

#endif
