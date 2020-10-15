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

  Espera.c

  \__\__\__\__\__\__\__\__\__\__\__\__\__\__\__\__\__\__\__\__\__\__\__*/
#include "Espera.h"
#include "MaxPQ.h"
#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>
#define bool int

/* Protótipo de rotinas auxiliares */
static void *mallocSafe(size_t nbytes);

Espera EsperaInit() {
  Espera fila = mallocSafe(sizeof(*fila));
  Link cabeca = mallocSafe(sizeof(*cabeca));
  MaxPQInit();
  fila->cabeca = cabeca;
  fila->cabeca->next = cabeca;
  fila->cabeca->previous = cabeca;
  fila->n = 0;
  fila->n_processosTerminados = 0;
  fila->sumPermanencia = 0;
  return fila;
}

void printEspera() {
  printMaxPQ();
}


void addProcessoEspera(Processo p, Espera fila) {
                                /*Next     previous*/
  Link novo = newNodeCircular(p, fila->cabeca, fila->cabeca->previous);
  fila->cabeca->previous->next = novo;
  fila->cabeca->previous = novo;
  MaxPQInsert(novo);
  fila->n++;
}


/*Relativamente alterado*/
Processo retiraProcessoEspera(Espera fila, int alterna) {
  Link no, temp;
  Processo p;
  if (alterna%2 == 0) {
    no = getMaxPQMax();
    temp = no->previous;
    temp->next = no->next;
    no->next->previous = temp;
  } else {
    no = fila->cabeca->next;
    MaxPQDelMeio(no->processo->posicao);
    no->next->previous = fila->cabeca;
    fila->cabeca->next = no->next;
  }
  fila->n--;
  p = no->processo;
  freeNodeCircular(no);
  return p;
}


void retiraNodeEspera(Espera fila, Link no) {
  if (fila->n == 0) {
    exit(0);
  }
  Link temp = no->previous;
  temp->next = no->next;
  no->next->previous = temp;
  fila->n--;
  free(no);
}

void imprimeEspera (Espera fila, int i) {
  Link no;
  no = fila->cabeca->next;
  while(no != fila->cabeca) {
    imprimeProcesso(no->processo, i);
    no = no->next;
  }
}

int EsperaSize(Espera fila) {
  return fila->n;
}

bool EsperaIsEmpty(Espera fila) {
  return fila->n == 0;
}

void incrementaProcessosTerminadosEspera(Espera fila) {
  fila->n_processosTerminados++;
}

Processo processoAtualEspera(Espera fila) {
  return fila->cabeca->next->processo;
}

int posicaoProcessoAtual(Espera fila) {
  return fila->cabeca->next->processo->posicao;
}

void somatorioTempoPermanenciaEspera(Espera fila, Processo processo) {
  fila->sumPermanencia += (processo->fimEspera - processo->inicioEspera);
}

void EsperaFree(Espera fila) {
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
