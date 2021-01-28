/*Implemente a seguinte biblioteca de uma fila usando vetor com redimensionamento:
Inspire-se na implementação feita em aula para pilhas redimensionáveis.
Diferença é que a Fila te dá acesso ao elemento que mais tempo está no sistema, ou seja,
cabeca->next
 */
 #include <stdio.h>
 #include <stdlib.h>
 #include "queue.h"

 /* Variáveis privadas da queue */
static Item *q;
static int n;
static int s;
static int ini;
static int fim;

/* Protótipo de rotinas auxiliares */
static void *mallocSafe(size_t);
static void queueResize(int);

/*Implementei a Fila de maneira circular, para que não
gaste tempo demais em alocações desnecessárias*/

/* Implementação das rotinas principais */
void queueInit() {
  q = mallocSafe(sizeof(Item));
  ini = 0;
  fim = 0;
  s = 1;
  n = 0;
}

void queueInsert(Item item) {
  if (n == s) queueResize(2*s);
  q[fim++] = item;
  if (fim == s) fim = 0;
  n++;
}

Item queueRemove(){
  Item k = q[ini++];
  if (ini == s) ini = 0 ;
  n--;

  if (n > 0 && n == s/4) {
    queueResize(s/2);
  }

  return k;
}

bool queueEmpty(){
  return n == 0;
}

int queueSize() {
  return n;
}

void queueFree() {
  free(q);
  n = 0;
}


/* Implementação das rotinas auxiliares */

static void queueResize(int capacity) {
  int i, j;
  Item *tmp, *b;
  b = mallocSafe(capacity*sizeof(Item));
  if (capacity < n) {
    printf("Error: invalid capacity choice.\n");
    exit(0);
  }
  j = 0;

  if (ini < fim) {
    for (i = ini; i < fim; i++)
      b[j++] = q[i];
  } else if (ini >= fim) {
    for (i = ini; i < s; i++)
      b[j++] = q[i];
    for (i = 0; i < fim; i++)
       b[j++] = q[i];
  }
  s = capacity;
  tmp = q;
  q = b;
  ini = 0;
  fim = n;
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
