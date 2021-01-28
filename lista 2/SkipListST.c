#include "SkipListST.h"
#include "stdio.h"
#include "stdlib.h"

static Link* first;
static int n;
static int MAXLEVELS;
static int lgN;
static int s;
static Link rank(int, Link, int);
static void *mallocSafe(size_t);


void stInit(int cap) {
  first = mallocSafe(cap * sizeof(Link));
  for (int i = 0; i < cap; i++) {
    first[i] =NULL;
  }
  lgN = 0;
  n = 0;
  s = cap;
  MAXLEVELS = cap;
}


int stGet(int key) {
  Link p = first[lgN-1];
  Link q;
  int k;
  for (k = lgN-1; k >= 0; k--) {
    p = rank(key, p, k);
    q = p->next[k];
    if (q != NULL && (key - q->key) == 0) {
      return q->val;
    }
  }
  return NULL;
}

void stPut(int key, int val) {
  Link *s, p, q;
  int k, levels;
  s = mallocSafe(MAXLEVELS * sizeof(Link));
  p = first[lgN-1];
  for (k = lgN-1; k >= 0; k--) {
    p = rank(key, p, k);
    q = p->next[k];
    if (q != NULL && (key - q->key) == 0) {
      q->val = val;
      return;
    }
    s[k] = p;
  }
  /* key não está na ST */
  levels = randLevel();
  p = newNode(key, val, levels);
  /* atualizar o no. de níveis? */
  if (levels == lgN + 1) {
    s[lgN] = first;
    lgN++; /* atualiza o no. níveis */
  }
  printf("LgN %d \n", lgN);
  for (k = levels-1; k >= 0; k--) {
    q = s[k]->next[k];
    s[k]->next[k] = p;
    p->next[k] = q;
  }
  n++;
  printf("eba\n" );

}

void stPrint() {
  Link p = first[lgN], q;

  q = NULL;
  // printf("MAMAO\n");
  while (q != NULL) {
    printf("CAJU  \n");
    printf("%d -- ", q->key);
    q = q->next[0];
  }
  printf("\n");
}
// void stDelete(Key key) {
//
// }

int randLevel() {
  printf("opa\n" );
  return lgN;
}


static Link rank(int key, Link start, int k) {
  Link p, q;
  p = start;
  q = start->next[k];
  while (q != NULL && (key - q->key) > 0) {
    p = q;
    q = q->next[k];
  }
  return p;
}


static void *mallocSafe(size_t nbytes) {
  void* p = malloc(nbytes);

  if (p == NULL) {
    printf("Erro: alocação de memória falhou no módulo Node.");
    exit(0);
  }
  return p;
}
