#include <stdio.h>
#include <stdlib.h>
#include "Celula.h"

/* Protótipo de rotinas auxiliares */

void *mallocSafe(size_t nbytes);

/* Implementação das rotinas principais */
Link newCelula (Processo processo, Celula next, Celula previous) {
  Celula q = mallocSafe(sizeof(*q));
  q->processo = processo;
  q->next = next;
  q->previous = previous;
  return q;
}

void freeCelula (Celula q) {
  q->next = NULL;
  q->previous = NULL;
  free(q);
}

/* Implementação das rotinas auxiliares */

void *mallocSafe(size_t nbytes) {
  void *p = malloc(nbytes);

  if (p == NULL) {
    printf("Erro: alocação de memória falhou no módulo Node.");
    exit(0);
  }
  return p;
}
