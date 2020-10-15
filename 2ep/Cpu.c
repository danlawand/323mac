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

  Cpu.c

  \__\__\__\__\__\__\__\__\__\__\__\__\__\__\__\__\__\__\__\__\__\__\__*/

#include "Cpu.h"
#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>
#define bool int

/* Protótipo de rotinas auxiliares */
static void *mallocSafe(size_t nbytes);

/*Relativamente alterado*/
CPU CPUInit() {
  CPU fila = mallocSafe(sizeof(*fila));
  Link cabeca = mallocSafe(sizeof(*cabeca));
  for (int i = 0; i < 10; i++) {
    fila->tempoPermanencia[i] = 0;
    fila->quantidadePrioridades[i] = 0;
  }
  fila->maiores100 = 0;
  fila->cabeca = cabeca;
  fila->cabeca->next = cabeca;
  fila->cabeca->previous = cabeca;
  fila->n = 0;
  fila->tempoDeProcesso = 0;
  fila->n_processosTerminados = 0;
  fila->sumPermanencia = 0;
  return fila;
}

/*Relativamente alterado*/
void addProcessoCPU(Processo p, CPU fila) {
                                /*Next     previous*/
  Link novo = newNodeCircular(p, fila->cabeca, fila->cabeca->previous);
  fila->cabeca->previous->next = novo;
  fila->cabeca->previous = novo;
  fila->n++;
}

/*Relativamente alterado*/
Processo retiraProcessoCPU(CPU fila) {
  Link no;
  Processo p;
  if (fila->n == 0) {
    return NULL;
  }
  no = fila->cabeca->next;
  fila->cabeca->next = no->next;
  no->next->previous = fila->cabeca;
  fila->n--;
  fila->n_processosTerminados++;
  p = no->processo;
  freeNodeCircular(no);
  return p;
}

/*Relativamente alterado*/
void fim20UT(CPU fila) {
  Link current;
  /*Tirou da primeira posição*/
  current = fila->cabeca->next;
  fila->cabeca->next = current->next;
  current->next->previous = fila->cabeca;

  /*Coloca em último*/
  current->next = fila->cabeca;
  current->previous = fila->cabeca->previous;
  fila->cabeca->previous->next = current;
  fila->cabeca->previous = current;
}

void imprimeCPU (CPU fila, int i) {
  Link no;
  no = fila->cabeca->next;
  while(no != fila->cabeca) {
    imprimeProcesso(no->processo, i);
    no = no->next;
  }
}

int CPUSize(CPU fila) {
  return fila->n;
}

bool CPUIsEmpty(CPU fila) {
  return fila->n == 0;
}

void incrementaProcessosTerminadosCPU(CPU fila) {
  fila->n_processosTerminados++;
}

Processo processoAtualCPU(CPU fila) {
  return fila->cabeca->next->processo;
}

void somatorioTempoPermanenciaCPU(CPU fila, Processo processo) {
  if (processo->tempoInicial >= 100) {
    fila->maiores100++;
    fila->sumPermanencia += (processo->fimCPU - processo->inicioCPU);
    fila->tempoPermanencia[processo->prioridade] += (processo->fimCPU - processo->inicioCPU);
    fila->quantidadePrioridades[processo->prioridade]++;
  }
}

double mediaTempoPermanenciaCPU(CPU fila) {
  if (fila->sumPermanencia == 0) {
    return 0;
  }
  double divisor, dividendo;
  dividendo = (double)fila->sumPermanencia;
  divisor = (double)fila->maiores100;
  return dividendo/divisor;
}


double mediaPrioridadesCPU(CPU fila, int k) {
  double divisor, dividendo;
  if (fila->tempoPermanencia[k] == 0) {
    return 0;
  }
  dividendo = (double)fila->tempoPermanencia[k];
  divisor = (double)fila->quantidadePrioridades[k];
  return dividendo/divisor;
}


void CPUFree(CPU fila) {
  Link no, q;
  if (fila->n != 0) {
    no = fila->cabeca->next;
    while(no != fila->cabeca) {
      q = no->next;
      freeNodeCircular(no);
      no = q;
    }
  }
  no = fila->cabeca;
  free(no);
  free(fila);
}

/* Implementação das rotinas auxiliares */
static void *mallocSafe(size_t nbytes) {
  void *p = malloc(nbytes);

  if (p == NULL) {
    printf("Erro: alocação de memória falhou no módulo Node.");
    exit(0);
  }
  return p;
}
