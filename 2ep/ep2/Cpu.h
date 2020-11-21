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

  Cpu.h

  \__\__\__\__\__\__\__\__\__\__\__\__\__\__\__\__\__\__\__\__\__\__\__*/
#ifndef _CPU_H
#define _CPU_H
#include "Node.h"
#include <stdio.h>
#define bool int

typedef struct circularFila* CPU;
struct circularFila {
  Link cabeca;
  Link last;

  /*Armazena o tempo de permanencia dos processos de cada prioridade*/
  int tempoPermanencia[10];

  /*Armazena quantos processos de cada prioridade passaram pela fila*/
  int quantidadePrioridades[10];

  /*Quantos processos concluíram a cpu e tem tempo inicial maior que 100UT*/
  int maiores100;

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
CPU CPUInit();

/*Adiciona Processo na Fila da CPU*/
void addProcessoCPU(Processo, CPU);

Processo retiraProcessoCPU(CPU);


/*Manda o processo para o fim da fila CPU*/
void fim20UT(CPU);


/*Imprime a fila em determinado UT*/
void imprimeCPU(CPU, int);

/*Retorna o tamanho da Fila*/
int CPUSize(CPU);

/*Devolve true se a fila está vazia*/
bool CPUIsEmpty(CPU);


/*Contador de Processos Terminados na Fila em questão*/
void incrementaProcessosTerminadosCPU(CPU);

Processo processoAtualCPU(CPU);

void somatorioTempoPermanenciaCPU(CPU, Processo);

/*Rotina para contagem dos processos com Prioridade não usadas, mas implementadas*/
double mediaTempoPermanenciaCPU(CPU);
double mediaPrioridadesCPU(CPU, int);

/*Destrutor*/
void CPUFree();

#endif
