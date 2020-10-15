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
#ifndef _ACABADOS_H
#define _ACABADOS_H
#include "Node.h"
#include <stdio.h>
#define bool int

typedef struct acabadosFila* Acabados;
struct acabadosFila {
  No cabeca;
  No last;

  /*Armazena o tamanho*/
  int n;

  /*Numero de processos terminados naquela fila*/
  int n_processosTerminados;

  /*Somatório do tempo de Permanência no Sistema*/
  int sumPermanencia;
};

/*Construtor*/
Acabados acabadosInit();

/*Adiciona Processo na Fila de Espera*/
void addProcessoAcabados(Processo, Acabados);

/*Adiciona No na Fila de Impressao ou na fila de processos Acabados*/
// void addNodeAcabados(No, Acabados);

/*Imprime a fila em determinado UT*/
void imprimeAcabados(Acabados, int);

/*Retorna o tamanho da Fila*/
int acabadosSize(Acabados);

/*Devolve true se a fila está vazia*/
bool acabadosIsEmpty(Acabados);

/*Retira No da fila de Impressao*/
// No retiraNodeAcabados(Acabados);


// /*Funcao que calcula a razao media e os tempos medios de Permanência em cada fila*/
// void mediasFinais(Acabados, double*, double*, double*, double*);

/*Destrutor*/
void acabadosFree();

#endif
