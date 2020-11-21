  
/*
 *  distancias.c
 */
#include <stdio.h>
#include <stdlib.h>

#include "queue.h"

static void *mallocSafe (unsigned int n);

/*
 * FILA: uma implementacao com lista encadeada sem cabeca
 */

typedef struct queueNode* Link;

struct queueNode { 
  Item conteudo; 
  Link prox; 
};

struct queue { /* aqui esta especificado o que e' */
  Link inicio; /* uma fila: dois apontadores para struct queueNode */
  Link fim;    
  int n;       /* e um inteiro com o numero de elementos */
}; 

typedef struct queue *TQueue;

static Link new(Item conteudo, Link prox) { 
  Link x = (Link) mallocSafe(sizeof *x);
  x->conteudo = conteudo; x->prox = prox;     
  return x;                         
}     
                              
Queue queueInit() { 
  TQueue q = (TQueue) mallocSafe(sizeof *q); 
  q->inicio = NULL; 
  q->fim = NULL; 
  q->n = 0;
  return (Queue) q;
}

int queueEmpty(Queue q) { 
  return ((TQueue)q)->n == 0; 
}

int queueSize(Queue q) { 
  return ((TQueue)q)->n;
}

void queuePut(Queue q, Item conteudo) { 
  if (((TQueue)q)->inicio == NULL) { 
    ((TQueue)q)->fim = new(conteudo, NULL);
    ((TQueue)q)->inicio = ((TQueue)q)->fim; 
  }
  else {
    ((TQueue)q)->fim->prox = new(conteudo, NULL); 
    ((TQueue)q)->fim = ((TQueue)q)->fim->prox;
  }
  ((TQueue)q)->n += 1;
}

Item queueGet(Queue q) { 
  Item conteudo = ((TQueue)q)->inicio->conteudo;
  Link t = ((TQueue)q)->inicio->prox;
  free(((TQueue)q)->inicio); 
  ((TQueue)q)->inicio = t;
  ((TQueue)q)->n -= 1;
  return conteudo;
}

void queueDump(Queue q) {
  Link t;
  for (t = ((TQueue)q)->inicio; t != NULL; t = t->prox)  
    printf("%d ", t->conteudo);
  printf("\n");
}

void queueFree(Queue q) { 
  while (((TQueue)q)->inicio != NULL) { 
    Link t = ((TQueue)q)->inicio->prox;
    free(((TQueue)q)->inicio);
    ((TQueue)q)->inicio = t;
  }
  free(q);
}

static void *mallocSafe (unsigned int n) {
  void *p;
  
  p = malloc(n);
  if (p == NULL) {
    fprintf(stderr,"queue: malloc de %u bytes falhou.\n", n);
    exit (-1);
  }
  return p;
}
