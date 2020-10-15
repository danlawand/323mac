#include "Node.h"
#include <stdlib.h>
#include <stdio.h>

/* Protótipo de rotinas auxiliares */

static void *mallocSafe(size_t nbytes);

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
