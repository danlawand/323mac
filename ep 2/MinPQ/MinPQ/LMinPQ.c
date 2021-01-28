/* ******************** *
 *       LMinPQ.c       *
 * ******************** */

#include<stdio.h>
#include<stdlib.h>

#include "LMinPQ.h"

typedef struct node *Link;

struct node {
  Transaction *item; 
  Link left, right;
  int dist;
};

static Link r;

static int n;

/* Protótipo de rotinas auxiliares */

static void *mallocSafe(size_t);

static Link newNode(Transaction *, Link, Link, int); 
static void freeNode(Link);
static void freeTree(Link);

static Link merge(Link, Link);

/* Rotinas principais */

void MinPQInit(int m) {
  r = NULL; 
  n = 0;
}
    
void MinPQInsert(Transaction *item) {
  Link s = newNode(item, NULL, NULL, 1);
  r = merge(r, s); 
  n++; 
}

Transaction *MinPQMin() {
  return r->item;
}
    
Transaction *MinPQDelMin() {
  Transaction *item = r->item;
  Link s = r;
  r = merge(r->left, r->right);
  freeNode(s);
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
  freeTree(r);
  r = NULL;
  n = 0;
}

/* Implementação das rotinas auxiliares */

static Link merge(Link r1, Link r2) {
  Link aux;
  if (r1 == NULL) return r2;
  if (r2 == NULL) return r1;
  if (lessT(r2->item, r1->item)) {
    aux = r1;  r1 = r2;  r2 = aux;
  }
  if (r1->left == NULL) 
    r1->left = r2;
  else {
    r1->right = merge(r1->right, r2);
    if (r1->left->dist < r1->right->dist) {
      aux = r1->left;  r1->left = r1->right;  r1->right = aux;
    }
    r1->dist = r1->right->dist + 1;
  }
  return r1;
}

static void *mallocSafe(size_t nbytes) {
  void *p = malloc(nbytes);
  
  if (p == NULL) {
    printf("Erro: alocação de memória falhou no módulo Node.");
    exit(0);
  }
  return p;
}

Link newNode(Transaction *item, Link left, Link right, int dist) {
  Link p = mallocSafe(sizeof(*p)); 

  p->item  = item;
  p->left  = left;
  p->right = right;
  p->dist  = dist;

  return p;
}

void freeNode(Link p) {
  free(p);
}

void freeTree(Link r) {
  if (r == NULL) return;
  freeTree(r->left);
  freeTree(r->right);
  freeNode(r);
}
