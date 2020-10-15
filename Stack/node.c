/* ******************** *
 *        Node.c        *
 * ******************** */

#include<stdio.h>
#include<stdlib.h>

#include "node.h"

/* Protótipo de rotinas auxiliares */

static void *mallocSafe(size_t nbytes);

/* Implementação das rotinas principais */

Link newNode(Item item, Link next) {
  Link p = mallocSafe(sizeof(*p)); 

  p->item = item;
  p->next = next;

  return p;
}

void freeNode(Link p) {
  free(p);
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
