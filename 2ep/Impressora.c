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

  Impressora.c

  \__\__\__\__\__\__\__\__\__\__\__\__\__\__\__\__\__\__\__\__\__\__\__*/

/*
PRECISO IMPLEMENTAR UM MODO DE PEGAR OS 3 PRIMEIROS
PROCESSOS PARA RODAR AS LINHAS E NÃO DAR CONFLITO
*/

#include "Impressora.h"
#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>
#define bool int

/* Protótipo de rotinas auxiliares */
static void *mallocSafe(size_t nbytes);

Impressora impressoraInit() {
  Impressora fila = mallocSafe(sizeof(*fila));
  No cabeca = mallocSafe(sizeof(*cabeca));
  fila->cabeca = cabeca;
  fila->cabeca->next = NULL;
  fila->primeiro = cabeca;
  fila->segundo = cabeca;
  fila->terceiro = cabeca;
  fila->last = cabeca;
  fila->n = 0;
  fila->n_processosTerminados = 0;
  fila->sumPermanencia = 0;
  return fila;
}

void addProcessoImpressora(Processo p, Impressora fila) {
  No no = newNodeLinear(p, NULL);
  fila->last->next = no;
  fila->last = no;
  fila->n++;
  if (fila->primeiro == fila->cabeca) {
    fila->primeiro = no;
  } else if (fila->segundo == fila->cabeca) {
    fila->segundo = no;
  } else if (fila->terceiro == fila->cabeca) {
    fila->terceiro = no;
  }
}

// void addNodeImpressora(No no, Impressora fila) {
//   // fila->totalLinhas += no->processo.linhas;
//   fila->last->next = no;
//   no->next = NULL;
//   fila->last = no;
//   fila->n++;
// }

void imprimeImpressora(Impressora fila, int i) {
  No no;
  no = fila->cabeca->next;
  while(no != NULL) {
    imprimeProcesso(no->processo, i);
    no = no->next;
  }
}

int impressoraSize(Impressora fila) {
  return fila->n;
}

bool impressoraIsEmpty(Impressora fila) {
  return fila->n == 0;
}


void incrementaProcessosTerminadosImpressora(Impressora fila) {
  fila->n_processosTerminados++;
}

void somatorioTempoPermanenciaImpressora(Impressora fila, Processo processo) {
  fila->sumPermanencia += (processo->fimImpressao - processo->inicioImpressao);
}

// No retiraNodeImpressora(Impressora fila) {
//   No no;
//   if (fila->n == 0) {
//     return NULL;
//   }
//   no = fila->cabeca->next;
//   fila->cabeca->next = no->next;
//   fila->n--;
//   fila->n_processosTerminados++;
//   return no;
// }



Processo retiraPrimeiroProcessoImpressora(Impressora fila) {
  No no;
  Processo p;
  if (fila->n == 0) {
    return NULL;
  }
  p = fila->primeiro->processo;
  /*Verifica o anterior*/
  no = fila->cabeca;
  while (no->next != fila->primeiro) {
    no = no->next;
  }
  no->next = fila->primeiro->next;
  /*Se primeiro for o último*/
  if (fila->last == fila->primeiro) {
    fila->last = no;
    fila->primeiro = fila->cabeca;

  } else {
    no = fila->primeiro;
    while (no->next != NULL && (no->next == fila->segundo || no->next == fila->terceiro)) {
      no = no->next;
    }
    /*Verifico se é diferente de NULL por segurança
      mas já de estar dentro desse else me garante que no->next != null
    */
    if (no->next != NULL) {
      fila->primeiro = no->next;
    } else {
      fila->primeiro = fila->cabeca;
    }
  }
  fila->n--;
  fila->n_processosTerminados++;
  return p;
}

Processo retiraSegundoProcessoImpressora(Impressora fila) {
  No no;
  Processo p;
  if (fila->n == 0) {
    return NULL;
  }
  p = fila->segundo->processo;
  /*Verifica o anterior*/
  no = fila->cabeca;
  while (no->next != fila->segundo) {
    no = no->next;
  }
  no->next = fila->segundo->next;
  /*Se segundo for o último*/
  if (fila->last == fila->segundo) {
    fila->last = no;
    fila->segundo = fila->cabeca;

  } else {
    no = fila->segundo;
    while (no->next != NULL && (no->next == fila->primeiro || no->next == fila->terceiro)) {
      no = no->next;
    }
    /*Verifico se é diferente de NULL por segurança
      mas já de estar dentro desse else me garante que no->next != null
    */
    if (no->next != NULL) {
      fila->segundo = no->next;
    } else {
      fila->segundo = fila->cabeca;
    }
  }
  fila->n--;
  fila->n_processosTerminados++;
  return p;
}

Processo retiraTerceiroProcessoImpressora(Impressora fila) {
  No no;
  Processo p;
  if (fila->n == 0) {
    return NULL;
  }
  p = fila->terceiro->processo;
  /*Verifica o anterior*/
  no = fila->cabeca;
  while (no->next != fila->terceiro) {
    no = no->next;
  }
  no->next = fila->terceiro->next;
  /*Se terceiro for o último*/
  if (fila->last == fila->terceiro) {
    fila->last = no;
    fila->terceiro = fila->cabeca;

  } else {
    no = fila->terceiro;
    while (no->next != NULL && (no->next == fila->primeiro || no->next == fila->segundo)) {
      no = no->next;
    }
    /*Verifico se é diferente de NULL por segurança
      mas já de estar dentro desse else me garante que no->next != null
    */
    if (no->next != NULL) {
      fila->terceiro = no->next;
    } else {
      fila->terceiro = fila->cabeca;
    }
  }
  fila->n--;
  fila->n_processosTerminados++;
  return p;
}

bool primeiroVazio(Impressora fila) {
  return fila->primeiro == fila->cabeca;
}

bool segundoVazio(Impressora fila) {
  return fila->segundo == fila->cabeca;
}

bool terceiroVazio(Impressora fila) {
  return fila->terceiro == fila->cabeca;
}
Processo primeiroImpressora(Impressora fila) {
  return fila->primeiro->processo;
}

Processo segundoImpressora(Impressora fila) {
  return fila->segundo->processo;
}

Processo terceiroImpressora(Impressora fila) {
  return fila->terceiro->processo;
}


void impressaoFree(Impressora fila) {
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
