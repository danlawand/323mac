/* ******************** *
 *        MaxPQ.c       *
 * ******************** */

#include<stdio.h>
#include<stdlib.h>

#include "MaxPQ.h"

static Item* pq;
static int s;
static int n;

/* Protótipo de rotinas auxiliares */

static void *mallocSafe(size_t);
static void sink(int);
static void swim(int);
static void stackResize(int);
static bool less(Item, Item);

/* Rotinas principais */

void MaxPQInit() {
  pq = mallocSafe(sizeof(Item));
  s = 1;
  n = 0;
}

void MaxPQInsert(Item item) {
  if (n == s) stackResize(2*s);
  /*Aqui entra o redimensionamento*/
  pq[n++] = item;
  swim(n-1);
}

Item MaxPQMax() {
  return pq[0];
}

Item MaxPQDelMax() {
  printf("OLA\n");
  Item item = pq[0];
  printf("MAQUE\n");
  pq[0] = pq[--n];
  printf("PATE\n");
  sink(0);
  printf("BULA\n");

  /* shrink size of array if necessary */
  if (n > 0 && n == s/4)
    stackResize(s/2);

  return item;
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
    printf("%d -- ", pq[i]);
  }
  printf("\n");
}

/* Implementação das rotinas auxiliares */
static bool less(Item a, Item b) {
  return a < b;
}

static void sink(int p) {
  Item x = pq[p];
  int f = 2*p +1;
  if (f+1 < n && less(pq[f], pq[f+1])) f++;
  while(2*p+1 < n) {
    f = 2*p+1;
    if (f < n && less(pq[f], pq[f+1]))
      f++;
    if (!less(x, pq[f])) break;
    pq[p] = pq[f];
    p = f;
  }
  pq[p] = x;
}

static void swim(int f) {
  Item x = pq[f];
  while (f > 0 && less(pq[(f-1)/2], x)) {
    pq[f] = pq[(f-1)/2];
    f = (f-1)/2;
  }
  pq[f] = x;
}


static void stackResize(int capacity) {
  int i;
  Item *tmp, *b = mallocSafe(capacity*sizeof(Item));

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
