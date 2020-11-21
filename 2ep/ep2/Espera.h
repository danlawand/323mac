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

  Espera.h

  \__\__\__\__\__\__\__\__\__\__\__\__\__\__\__\__\__\__\__\__\__\__\__*/
#ifndef _ESPERA_H
#define _ESPERA_H
#include "Node.h"
#include <stdio.h>
#define bool int

typedef struct EsperaFila* Espera;
struct EsperaFila {
  Link cabeca;
  Link last;

  /*Armazena o tempo de permanencia dos processos de cada prioridade*/
  int tempoPermanencia[10];

  /*Quantos processos concluíram a cpu e tem tempo inicial maior que 100UT*/
  int maiores100;

  /*Armazena quantos processos de cada prioridade passaram pela fila*/
  int quantidadePrioridades[10];

  /*Armazena quantos processos de cada prioridade com tempo inicial maior que 100 passaram pela fila*/
  int quantidadePrioridades100[10];

  /*Armazena o tamanho*/
  int n;

  /*Numero de processos terminados naquela fila*/
  int n_processosTerminados;

  /*Somatório do tempo de Permanência no Sistema*/
  int sumPermanencia;
};

/*Construtor*/
Espera EsperaInit();

void printEspera();

/*Adiciona Processo na Fila da Espera*/
void addProcessoEspera(Processo, Espera);

Processo retiraProcessoEspera(Espera, int);

void retiraNodeEspera(Espera, Link);

/*Imprime a fila em determinado UT*/
void imprimeEspera(Espera, int);

/*Retorna o tamanho da Fila*/
int EsperaSize(Espera);

/*Devolve true se a fila está vazia*/
bool EsperaIsEmpty(Espera);

/*Contador de Processos Terminados na Fila em questão*/
void incrementaProcessosTerminadosEspera(Espera);

Processo processoAtualEspera(Espera);

int posicaoProcessoAtual(Espera);

void somatorioTempoPermanenciaEspera(Espera, Processo);

double mediaTempoPermanenciaEspera(Espera);

int sizePrioridade(Espera, int);

double mediaPrioridadesEspera(Espera, int);

/*Destrutor*/
void EsperaFree();

#endif
