/* ********************** *
 *        stackRd.c       *
 * ********************** */

#include<stdio.h>
#include<stdlib.h>

#include "stack.h"

/* Variáveis privadas da stack */

static Item *a;
    
static int s; 
    
static int n;
    
/* Protótipo de rotinas auxiliares */

static void *mallocSafe(size_t);
static void stackResize(int);

/* Implementação das rotinas principais */

void stackInit() {
  a = mallocSafe(sizeof(Item));
  s = 1;
  n = 0;
}
    
void stackPush(Item i) {
  if (n == s) stackResize(2*s);
  a[n++] = i;
}

Item stackPop() {
  Item k = a[n-1];

  n--;

  /* shrink size of array if necessary */
  if (n > 0 && n == s/4)
    stackResize(s/2);

  return k;
}

bool stackIsEmpty() {
  return n == 0;
}
    
int stackSize() {
  return n;
}
    
void stackFree() {
  free(a);
  n = 0;
}
    
/* Implementação das rotinas do iterador */

static int current;
    
void stackStartIterator() {
  current = 0;
}
    
bool stackHasNext() {
  return current < n;
}
    
Item stackNext() {
  n++;
  return a[n-1];
}

/* Implementação das rotinas auxiliares */

static void stackResize(int capacity) {
  int i;
  Item *tmp, *b = mallocSafe(capacity*sizeof(Item));

  if (capacity < n) {
    printf("Error: invalid capacity choice.\n");
    exit(0);
  }

  for (i = 0; i < n; i++)
    b[i] = a[i]; 
  s = capacity;
  tmp = a;
  a = b;
  free(tmp);
}

static void *mallocSafe(size_t nbytes) {
  void *p = malloc(nbytes);
  
  if (p == NULL) {
    printf("Erro: alocação de memória falhou no módulo stack.");
    exit(0);
  }
  return p;
}
