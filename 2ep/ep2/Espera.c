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
  int i;
  for (i = 0; i < 10; i++) {
    fila->tempoPermanencia[i] = 0;
    fila->quantidadePrioridades[i] = 0;
    fila->quantidadePrioridades100[i] = 0;
  }
  fila->maiores100 = 0;
  MaxPQInit();
  fila->cabeca = cabeca;
  fila->cabeca->next = cabeca;
  fila->cabeca->previous = cabeca;
  fila->n = 0;
  fila->n_processosTerminados = 0;
  fila->sumPermanencia = 0;
  return fila;
}

void addProcessoEspera(Processo p, Espera fila) {
  Link novo;
  fila->quantidadePrioridades[p->prioridade]++;
  novo = newNodeCircular(p, fila->cabeca, fila->cabeca->previous);
  fila->cabeca->previous->next = novo;
  fila->cabeca->previous = novo;
  MaxPQInsert(novo);
  fila->n++;
}


Processo retiraProcessoEspera(Espera fila, int alterna) {
  Link no, temp;
  Processo processo;
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
  processo = no->processo;
  freeNodeCircular(no);
  fila->quantidadePrioridades[processo->prioridade]--;

  return processo;
}


void retiraNodeEspera(Espera fila, Link no) {
  Link temp;
  if (fila->n == 0) {
    exit(0);
  }
  temp = no->previous;
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
  if (processo->tempoInicial >= 100) {
    fila->maiores100++;
    fila->sumPermanencia += (processo->fimEspera - processo->inicioEspera);
    fila->tempoPermanencia[processo->prioridade] += (processo->fimEspera - processo->inicioEspera);
    fila->quantidadePrioridades100[processo->prioridade]++;
  }
}

double mediaTempoPermanenciaEspera(Espera fila) {
  double divisor, dividendo;
  if (fila->sumPermanencia == 0) {
    return 0;
  }
  dividendo = (double)fila->sumPermanencia;
  divisor = (double)fila->maiores100;
  return dividendo/divisor;
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

int sizePrioridade(Espera fila, int k) {
  return fila->quantidadePrioridades[k];
}

double mediaPrioridadesEspera(Espera fila, int k) {
  double divisor, dividendo;
  if (fila->tempoPermanencia[k] == 0) {
    return 0;
  }
  dividendo = (double)fila->tempoPermanencia[k];
  divisor = (double)fila->quantidadePrioridades100[k];
  return dividendo/divisor;
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
