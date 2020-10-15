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
  fila->cabeca = cabeca;
  fila->cabeca->next = NULL;
  fila->last = cabeca;
  fila->n = 0;
  fila->n_processosTerminados = 0;
  fila->sumPermanencia = 0;
  return fila;
}

void addProcessoAcabados(Processo processo, Acabados fila) {
  fila->sumPermanencia += (processo->tempoFinal - processo->tempoInicial);
  No no = newNodeLinear(processo, NULL);
  fila->last->next = no;
  fila->last = no;
  fila->n++;
}

// void addNodeAcabados(No no, Acabados fila) {
//   fila->sumPermanencia += (no->processo->tempoFinal - no->processo->tempoInicial);
//   fila->last->next = no;
//   no->next = NULL;
//   fila->last = no;
//   fila->n++;
//
// }


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

// No retiraNodeAcabados(Acabados fila) {
//   No no;
//   if (fila->n == 0) {
//     return NULL;
//   }
//   if (fila->last == fila->cabeca->next) {
//     fila->last = fila->cabeca;
//   }
//   no = fila->cabeca->next;
//   fila->cabeca->next = no->next;
//   fila->n--;
//   fila->n_processosTerminados++;
//   return no;
// }


// void mediasFinais(Acabados fila, double* mediaEspera, double* mediaCPU, double* mediaImpressora, double* razao) {
//   No no;
//   /*Numero de processos contados*/
//   int nproc = 0;
//   /*Variaveis para as fila de Espera e Cpu*/
//   int e = 0, c = 0;
//   /*Variaveis para a impressora*/
//   int i1 = 0, q1 = 0, i2 = 0, q2 = 0, i3 = 0, q3 = 0, q = 0;
//   /*Variaveis para a razão*/
//   int sumUT = 0, perm = 0;
//   double razaoParcial = 0, mediai1, mediai2, mediai3;
//
//   if (fila->n == 0) {
//     *mediaEspera = 0;
//     *mediaCPU = 0;
//     *mediaImpressora = 0;
//     *razao = 0;
//     return;
//   }
//   no = fila->cabeca->next;
//   while(no != NULL) {
//     e += no->processo->fimEspera - no->processo->inicioEspera;
//     c += no->processo->fimCPU - no->processo->inicioCPU;
//
//     if (no->processo->impressoraID == 1) {
//       i1 += no->processo->fimImpressao - no->processo->inicioImpressao;
//       q1++;
//     } else if (no->processo->impressoraID == 2) {
//       i2 += no->processo->fimImpressao - no->processo->inicioImpressao;
//       q2++;
//     } else if( no->processo->impressoraID == 3) {
//       i3 += no->processo->fimImpressao - no->processo->inicioImpressao;
//       q3++;
//     }
//     nproc++;
//     sumUT = no->processo->tempoDeProcessamentoInicial;
//     perm = no->processo->tempoFinal - no->processo->tempoInicial;
//
//     /*Garantia que não dará -nan*/
//     if (perm != 0) {
//       razaoParcial += ((double)sumUT)/((double)perm);
//     }
//     no = no->next;
//   }
//   *mediaEspera = (double)e/(double)nproc;
//   *mediaCPU = (double)c/(double)nproc;
//
//   mediai1 = 0;
//   if (q1 != 0) {
//     q++;
//     mediai1 = (double)i1/(double)q1;
//   }
//   mediai2 = 0;
//   if (q2 != 0) {
//     q++;
//     mediai2 = (double)i2/(double)q2;
//   }
//   mediai3 = 0;
//   if (q3 != 0) {
//     q++;
//     mediai3 = (double)i3/(double)q3;
//   }
//   *mediaImpressora = (mediai1+mediai2+mediai3)/(double)q;
//   *razao = razaoParcial/(double)nproc;
// }

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
