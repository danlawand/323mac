#include <stdio.h>
#include <stdlib.h>
#include "transaction.h"

/* Protótipo de rotinas auxiliares */

void *mallocSafe(size_t nbytes);

/* Implementação das rotinas principais */

bool lessT(Transaction *a, Transaction *b) {
  return a->valor < b->valor;
}

Transaction *readT() {
  Transaction *a = mallocSafe(sizeof(*a));
  if (fscanf(stdin, "%s %d/%d/%d %f", a->nome, &(a->mes), &(a->dia), &(a->ano), &(a->valor)) < 5) {
    freeT(a); 
    return NULL;
  }
  return a;
}

void printT(Transaction *a) {
  printf("%10s  %02d/%02d/%4d   %.2f\n", a->nome, a->dia, a->mes, a->ano, a->valor);
}

void freeT(Transaction *a) {
  free(a);
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
