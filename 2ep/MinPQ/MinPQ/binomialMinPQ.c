/* *********************** *
 *     binomialMinPQ.c     *
 * *********************** */

#include<stdio.h>
#include<stdlib.h>

#include "binomialMinPQ.h"

typedef struct node *Link;

struct node {
  Transaction *item; 
  Link child, sibling;
  int order;
};

static Link r;

static int n;

/* Protótipo de rotinas auxiliares */

static void *mallocSafe(size_t);

static Link newNode(Transaction *, Link, Link, int); 
static void freeNode(Link);
static void freeBHeap(Link);

static Link merge(Link, Link);
static Link eraseMin();

/* Rotinas principais */

void MinPQInit(int m) {
  r = NULL; 
  n = 0;
}
    
void MinPQInsert(Transaction *item) {
  Link s = newNode(item, NULL, NULL, 0);
  r = merge(r, s); 
  n++; 
}

Transaction *MinPQMin() {
  return r->item;
}
    
Transaction *MinPQDelMin() {
  Link x, prevx, nextx, min = eraseMin();
  Transaction *item = min->item;

  if (min->child != NULL) {
    x = min->child;
    /* inverta a lista */
    prevx = NULL;  nextx = x->sibling;
    while (nextx != NULL) {
      x->sibling = prevx;
      prevx = x;
      x = nextx;
      nextx = x->sibling;
    }
    x->sibling = prevx;
    r = merge(r, x);
  }
  freeNode(min);
  n--;
  return item;
}

int MinPQSize() {
  return n;
}

bool MinPQEmpty() {
  return n == 0;
}
    
void MinPQFree() {
  freeBHeap(r);
  r = NULL;
  n = 0;
}

/* Implementação das rotinas auxiliares */

static void link(Link r1, Link r2) {
  /* r2->item < r1->item; inclui r1 como filho de r2 */
  r1->sibling = r2->child;
  r2->child = r1;
  r2->order++;
}

static Link mergeR(Link r1, Link r2) {
  /* intercala a lista de siblings de r1 e r2 */
  if (r1 == NULL) return r2;
  if (r2 == NULL) return r1;
  if (lessT(r2->item, r1->item)) {
    Link aux = r1;  r1 = r2;  r2 = aux;
  }
  /* r1->item < r2->item */
  r1->sibling = mergeR(r1->sibling, r2);
  return r1;
}

static Link merge(Link r1, Link r2) {
  Link r, x, prevx, nextx;

  if (r1 == NULL) return r2;
  if (r2 == NULL) return r1;
  /* intercala as listas de siblings */
  r = mergeR(r1, r2);

  /* junta árvores da mesma ordem */
  x = r;  prevx = NULL;  nextx = x->sibling;
  while (nextx != NULL) {
    if (x->order < nextx->order || 
	/* se há mais de duas de mesma ordem, junta as duas últimas */
	(nextx->sibling != NULL && nextx->sibling->order == x->order)) {
      prevx = x;  x = nextx;
    }
    else if (lessT(x->item, nextx->item)) {
      /* nextx vira filho de x */
      x->sibling = nextx->sibling;
      link(nextx, x);
    }
    else {
      /* x vira filho de nextx */
      if (prevx == NULL) r = nextx;
      else prevx->sibling = nextx;
      link(x, nextx);
      x = nextx;
    }
    nextx = x->sibling;
  }

  return r;
}

static Link eraseMin() {
  Link min = r, prev = NULL, current = r;
  /* find the minimum of the list r of siblings */
  while (current->sibling != NULL) {
    if (lessT(current->sibling->item, min->item)) {
      prev = current;
      min = current->sibling;
    }
    current = current->sibling;
  }
  /* remove the minimum and return it */
  if (prev == NULL) r = min->sibling;
  else prev->sibling = min->sibling;
  return min;
}

static void *mallocSafe(size_t nbytes) {
  void *p = malloc(nbytes);
  
  if (p == NULL) {
    printf("Erro: alocação de memória falhou no módulo Node.");
    exit(0);
  }
  return p;
}

Link newNode(Transaction *item, Link child, Link sibling, int order) {
  Link p = mallocSafe(sizeof(*p)); 

  p->item    = item;
  p->child   = child;
  p->sibling = sibling;
  p->order   = order;

  return p;
}

void freeNode(Link p) {
  free(p);
}

void freeBHeap(Link r) {
  if (r == NULL) return;
  freeBHeap(r->child);
  freeBHeap(r->sibling);
  freeNode(r);
}
