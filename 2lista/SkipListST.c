#include "SkipListST.h"
#include "stdio.h"
#include "stdlib.h"

static Link first;
static int n;
static int MAXLEVELS;
static int lgN;
static int s;
static Link rank(int, Link, int);
static void *mallocSafe(size_t);


void stInit(int cap) {
  // int keys = mallocSafe(cap * sizeof(keys));
  // int vals = mallocSafe(cap * sizeof(vals));
  n = 0;
  s = cap;
}


int stGet(int key) {
  Link p = first;
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
  p = first;
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
  for (k = levels-1; k >= 0; k--) {
    q = s[k]->next[k];
    s[k]->next[k] = p;
    p->next[k] = q;
  }
  n++;
}

void stPrint() {
  Link p = first, q;

  q = p->next[0];
  printf("MAMAO\n");
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
  return lgN;
}


static Link rank(int key, Link start, int k) {
  Link p, q;
  p = start;
  q = start->next[k];
  while (q != NULL && (key - q->key) < 0) {
    p = q;
    q = q->next[k];
  }
  return p;
}


static void *mallocSafe(size_t nbytes) {
  void *p = malloc(nbytes);

  if (p == NULL) {
    printf("Erro: alocação de memória falhou no módulo Node.");
    exit(0);
  }
  return p;
}
