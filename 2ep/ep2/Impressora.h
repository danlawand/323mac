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

  Impressora.h

  \__\__\__\__\__\__\__\__\__\__\__\__\__\__\__\__\__\__\__\__\__\__\__*/
#ifndef _IMPRESSORA_H
#define _IMPRESSORA_H
#include "Node.h"
#include <stdio.h>
#define bool int

typedef struct impressoraFila* Impressora;
struct impressoraFila {
  No cabeca;
  No last;

  /*Armazena o tempo de permanencia dos processos de cada prioridade*/
  int tempoPermanencia[10];

  /*Armazena quantos processos de cada prioridade passaram pela fila*/
  int quantidadePrioridades[10];

  /*Quantos processos concluíram a cpu e tem tempo inicial maior que 100UT*/
  int maiores100;
  /*Armazena o tamanho*/
  int n;

  No primeiro;
  No segundo;
  No terceiro;

  /*Numero de processos terminados naquela fila*/
  int n_processosTerminados;

  /*Somatório do tempo de Permanência no Sistema*/
  int sumPermanencia;
};

/*Construtor*/
Impressora impressoraInit();

/*Adiciona Processo na Impressora*/
void addProcessoImpressora(Processo, Impressora);

/*Imprime a fila em determinado UT*/
void imprimeImpressora(Impressora, int);

/*Retorna o tamanho da Fila*/
int impressoraSize(Impressora);

/*Devolve true se a fila está vazia*/
bool impressoraIsEmpty(Impressora);

void incrementaProcessosTerminadosImpressora(Impressora);

void somatorioTempoPermanenciaImpressora(Impressora, Processo);

double mediaTempoPermanenciaImpressora(Impressora);


/*Retira No da fila de Impressao*/
Processo retiraPrimeiroProcessoImpressora(Impressora);

Processo retiraSegundoProcessoImpressora(Impressora);

Processo retiraTerceiroProcessoImpressora(Impressora);

bool primeiroVazio(Impressora);

bool segundoVazio(Impressora);

bool terceiroVazio(Impressora);

Processo primeiroImpressora(Impressora);

Processo segundoImpressora(Impressora);

Processo terceiroImpressora(Impressora);

double mediaPrioridadesImpressora(Impressora, int);


/*Destrutor*/
void impressaoFree();

#endif
