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

#include "Acabados.h"
#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>
#define bool int

/* Protótipo de rotinas auxiliares */
static void *mallocSafe(size_t nbytes);

Acabados acabadosInit() {
  Acabados fila = mallocSafe(sizeof(*fila));
  No cabeca = mallocSafe(sizeof(*cabeca));
  for (int i = 0; i < 10; i++) {
    fila->tempoPermanencia[i] = 0;
    fila->quantidadePrioridades[i] = 0;
  }
  fila->maiores100 = 0;
  fila->razaoPerm = 0;
  fila->cabeca = cabeca;
  fila->cabeca->next = NULL;
  fila->last = cabeca;
  fila->n = 0;
  fila->n_processosTerminados = 0;
  fila->sumPermanencia = 0;
  return fila;
}

void addProcessoAcabados(Processo processo, Acabados fila) {
  double divisor, dividendo;

  if (processo->tempoInicial >= 100) {
    dividendo = (double)processo->tempoDeProcessamentoInicial;
    divisor = (double)(processo->tempoFinal - processo->tempoInicial);
    fila->razaoPerm += dividendo/divisor;
    fila->maiores100++;
    fila->sumPermanencia += (processo->tempoFinal - processo->tempoInicial);
    fila->tempoPermanencia[processo->prioridade] += (processo->tempoFinal - processo->tempoInicial);
    fila->quantidadePrioridades[processo->prioridade]++;
  }
  No no = newNodeLinear(processo, NULL);
  fila->last->next = no;
  fila->last = no;
  fila->n++;
}

double mediaTempoPermanenciaAcabados(Acabados fila) {
  if (fila->sumPermanencia == 0) {
    return 0;
  }
  double divisor, dividendo;
  dividendo = (double)fila->sumPermanencia;
  divisor = (double)fila->maiores100;
  return dividendo/divisor;
}

double mediaRazao(Acabados fila) {
  double media, divisor, dividendo;

  dividendo = fila->razaoPerm;
  divisor = (double)fila->maiores100;
  media = dividendo/divisor;
  return media;
}

double mediaPrioridadesAcabados(Acabados fila, int k) {
  double divisor, dividendo;
  if (fila->tempoPermanencia[k] == 0) {
    return 0;
  }
  dividendo = (double)fila->tempoPermanencia[k];
  divisor = (double)fila->quantidadePrioridades[k];
  return dividendo/divisor;
}


void imprimeAcabados (Acabados fila, int i) {
  No no;
  no = fila->cabeca->next;
  while(no != NULL) {
    imprimeProcesso(no->processo, i);
    no = no->next;
  }
}

int acabadosSize(Acabados fila) {
  return fila->n;
}

bool acabadosIsEmpty(Acabados fila) {
  return fila->n == 0;
}

void acabadosFree(Acabados fila) {
  No no, q;
  if (fila->n != 0) {
    no = fila->cabeca->next;
    while(no != NULL) {
      q = no->next;
      freeProcesso(no->processo);
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
