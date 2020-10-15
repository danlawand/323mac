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

  FilaLinear.c

  \__\__\__\__\__\__\__\__\__\__\__\__\__\__\__\__\__\__\__\__\__\__\__*/

#include "FilaLinear.h"
#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>
#define bool int

/* Protótipo de rotinas auxiliares */
static void *mallocSafe(size_t nbytes);

Fila filaLinearInit() {
  Fila fila = mallocSafe(sizeof(*fila));
  No cabeca = mallocSafe(sizeof(*cabeca));
  fila->cabeca = cabeca;
  fila->cabeca->next = NULL;
  fila->last = cabeca;
  fila->n = 0;
  fila->n_processosTerminados = 0;
  fila->sumPermanencia = 0;
  return fila;
}

void addProcessoFilaLinear(Processo p, Fila fila) {
  No no = newNodeLinear(p, NULL);
  fila->last->next = no;
  fila->last = no;
  fila->n++;
}

void addNodeFilaLinear(No no, Fila fila) {
  fila->last->next = no;
  no->next = NULL;
  fila->last = no;
  fila->n++;
}

void imprimeFilaLinear (Fila fila, int i) {
  No no;
  no = fila->cabeca->next;
  while(no != NULL) {
    imprimeProcesso(no->processo, i);
    no = no->next;
  }
}

int filaSize(Fila fila) {
  return fila->n;
}

bool filaIsEmpty(Fila fila) {
  return fila->n == 0;
}

void incrementaProcessosTerminadosLinear(Fila fila) {
  fila->n_processosTerminados++;
}

void somatorioTempoPermanenciaLinear(Fila fila) {
  fila->sumPermanencia += (fila->cabeca->next->processo->fimEspera - fila->cabeca->next->processo->inicioEspera);
}

No retiraNodeFilaLinear(Fila fila) {
  No no;
  if (fila->n == 0) {
    return NULL;
  }
  if (fila->last == fila->cabeca->next) {
    fila->last = fila->cabeca;
  }
  no = fila->cabeca->next;
  fila->cabeca->next = no->next;
  fila->n--;
  fila->n_processosTerminados++;
  return no;
}

Processo retiraProcessoEspera(Fila fila) {
  No q = fila->cabeca->next;
  /*Sera que a proxima linha funciona?*/
  Processo p = q->processo;
  fila->cabeca->next = fila->cabeca->next->next;
  freeNodeLinear(q);
  return p;
}

Processo processoAtualEspera(Fila fila) {
  return fila->cabeca->next->processo;
}

void filaFree(Fila fila) {
  No no, q;
  if (fila->n != 0) {
    no = fila->cabeca->next;
    while(no != NULL) {
      q = no->next;
      freeNodeLinear(no);
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
