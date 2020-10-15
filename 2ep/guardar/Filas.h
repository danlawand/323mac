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

  FilaCircular.h

  \__\__\__\__\__\__\__\__\__\__\__\__\__\__\__\__\__\__\__\__\__\__\__*/
#ifndef _FILAS_H
#define _FILAS_H
#include "Node.h"
#include <stdio.h>
#define bool int
/**********************FILA CIRCULAR****************************************/

typedef struct circularFila* Circular;
struct circularFila {
  Link cabeca;
  Link last;

  /*Armazena o tamanho*/
  int n;

  /*Armazena o tempo de execução na cpu, para depois verficiar se excedeu as 20 UT na execução do processo*/
  int tempoDeProcesso;

  /*Numero de processos terminados naquela fila*/
  int n_processosTerminados;

  /*Somatório do tempo de Permanência no Sistema*/
  int sumPermanencia;
};

/*Construtor*/
Circular filaCircularInit();

/*Adiciona Processo na Fila da CPU*/
void addProcessoFilaCircular(Processo, Circular);

/*Adiciona Link na Fila Circular*/
void addNodeFilaCircular(Link, Circular);

/*Retira processo da fila da CPU*/
Link retiraNodeFilaCircular(Circular);

Processo retiraProcessoFilaCircular(Circular);


/*Manda o processo para o fim da fila Circular*/
void fim20UT(Circular);


/*Imprime a fila em determinado UT*/
void imprimeFilaCircular(Circular, int);

/*Retorna o tamanho da Fila*/
int filaCircularSize(Circular);

/*Devolve true se a fila está vazia*/
bool filaCircularIsEmpty(Circular);

/*Contador de Processos Terminados na Fila em questão*/
void incrementaProcessosTerminadosCircular(Circular);

Processo processoAtualCPU(Circular);

/*Destrutor*/
void filaCircularFree();

/**********************FILA DE ESPERA****************************************/

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

void somatorioTempoPermanencia(Fila);

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
