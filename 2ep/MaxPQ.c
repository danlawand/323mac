/* ******************** *
 *        MaxPQ.c       *
 * ******************** */

#include<stdio.h>
#include<stdlib.h>
#include "MaxPQ.h"

static Link* pq;
static int s;
static int n;

/* Protótipo de rotinas auxiliares */

static void *mallocSafe(size_t);
static void sink(int);
static void swim(int);
static void stackResize(int);
static bool less(Link, Link);

/* Rotinas principais */

void MaxPQInit() {
  pq = mallocSafe(sizeof(Link));
  s = 1;
  n = 0;
}

void MaxPQInsert(Link no) {
  if (n == s) stackResize(2*s);
  no->processo->posicao = n;
  pq[n++] = no;
  swim(n-1);
}

Processo MaxPQMax() {
  return pq[0]->processo;
}

Link getMaxPQMax() {
  Link node = pq[0];
  pq[0] = pq[--n];
  sink(0);

  /* shrink size of array if necessary */
  if (n > 0 && n == s/4)
    stackResize(s/2);

  return node;
}


Link getMaxPQMeio(int p) {
  Link node = pq[p];
  pq[p] = pq[--n];
  sink(p);
  /* shrink size of array if necessary */
  if (n > 0 && n == s/4)
    stackResize(s/2);

  return node;
}

void MaxPQDelMax() {
  pq[0] = pq[--n];
  sink(0);

  /* shrink size of array if necessary */
  if (n > 0 && n == s/4)
    stackResize(s/2);
}


void MaxPQDelMeio(int p) {
  pq[p] = pq[--n];
  sink(p);

  /* shrink size of array if necessary */
  if (n > 0 && n == s/4)
    stackResize(s/2);
}


int MaxPQSize() {
  return n;
}

bool MaxPQEmpty() {
  return n == 0;
}

void MaxPQFree() {
  free(pq);
  pq = NULL;
  n = 0;
}

void printMaxPQ() {
  int i;
  for (i = 0; i < n; i++) {
    imprimeNovoProcesso(pq[i]->processo);
  }
  printf("_______________________\n");
}

/* Implementação das rotinas auxiliares */
static bool less(Link a, Link b) {
  if (a->processo->prioridade == b->processo->prioridade) {
    /*Se o tempo inicial do Pai for maior que do filho, troca*/
    return a->processo->tempoInicial > b->processo->tempoInicial;
  }
  return a->processo->prioridade < b->processo->prioridade;

}

static void sink(int p) {
  Link x = pq[p];
  int f = 2*p +1;
  if (f+1 < n && less(pq[f], pq[f+1])) f++;
  while(2*p+1 < n) {
    f = 2*p+1;
    if (f < n && less(pq[f], pq[f+1]))
      f++;
    if (!less(x, pq[f])) break;
    pq[p] = pq[f];
    pq[p]->processo->posicao = p;
    p = f;
  }
  pq[p] = x;
  pq[p]->processo->posicao = p;
}

static void swim(int f) {
  Link x = pq[f];
  while (f > 0 && less(pq[(f-1)/2], x)) {
    pq[f] = pq[(f-1)/2];
    pq[f]->processo->posicao = f;
    f = (f-1)/2;
  }
  pq[f] = x;
  pq[f]->processo->posicao = f;
}


static void stackResize(int capacity) {
  int i;
  Link *tmp, *b = mallocSafe(capacity*sizeof(Link));

  if (capacity < n) {
    printf("Error: invalid capacity choice.\n");
    exit(0);
  }

  for (i = 0; i < n; i++)
    b[i] = pq[i];
  s = capacity;
  tmp = pq;
  pq = b;
  free(tmp);
}


static void *mallocSafe(size_t nbytes) {
  void *p = malloc(nbytes);

  if (p == NULL) {
    printf("Erro: alocação de memória falhou no módulo Node.");
    exit(0);
  }
  return p;
}
