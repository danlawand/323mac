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

  Node.c

  \__\__\__\__\__\__\__\__\__\__\__\__\__\__\__\__\__\__\__\__\__\__\__*/
#include "Node.h"
#include <stdlib.h>
#include <stdio.h>

/* Protótipo de rotinas auxiliares */

static void *mallocSafe(size_t nbytes);

No newNodeLinear (Processo processo, No next) {
  No q = mallocSafe(sizeof(*q));
  q->processo = processo;
  q->next = next;
  return q;
}

void freeNodeLinear (No q) {
  q->next = NULL;
  free(q);
}

Link newNodeCircular (Processo processo, Link next, Link previous) {
  Link q = mallocSafe(sizeof(*q));
  q->processo = processo;
  q->next = next;
  q->previous = previous;
  return q;
}

void freeNodeCircular (Link q) {
  q->next = NULL;
  q->previous = NULL;
  free(q);
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
