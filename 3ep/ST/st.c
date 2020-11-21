/* ************************* *
 *        stSkipList.c       *
 * ************************* */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

#include "st.h"

/* Variáveis privadas da stack */

typedef struct cell *Link;

struct cell {
  Key key;
  Value val;
  Link *next;
};

static struct cell first;    /* no cabeca */
static int n;                /* numero de itens na ST */
static int MAXLEVELS = 32;   /* numero maximo de niveis */
static int lgN;              /* numero de niveis */
static Link nulo = NULL;     /* sentinela */
    
/* Protótipo de rotinas auxiliares */

static Link newNode(Key, Value, int); 
static void *mallocSafe(size_t);
static int  compare (Key, Key);
static Link rank(Key, Link, int);
static int randLevel();
/* static void print_level(int k); */

/* Implementação das rotinas principais */

void stInit() {
  int k;
  first.next = mallocSafe(MAXLEVELS * sizeof(Link)); 
  nulo = newNode(NULL,NULL,MAXLEVELS); /* sentinela */
  for (k = 0; k < MAXLEVELS; k++) 
    first.next[k] = nulo;
  n = 0;
  lgN = 1;
  srand(time(NULL)); 
}
    
void stPut(Key key, Value val) {
  Link *s, p, q;  int k, levels;
  s = mallocSafe(MAXLEVELS * sizeof(Link)); 
  p = &first;
  for (k = lgN-1; k >= 0; k--) {
    p = rank(key, p, k); 
    q = p->next[k];
    if (q != nulo && compare(key, q->key) == 0) {
      q->val = val; 
      return;
    }
    s[k] = p;
  }
  /* key não está na ST */
  levels = randLevel(); 
  p = newNode(key, val, levels);
  if (levels == lgN + 1) {
    s[lgN] = &first;
    lgN++;
  }
  for (k = levels-1; k >= 0; k--) {
    q = s[k]->next[k];
    s[k]->next[k] = p;
    p->next[k] = q;
  }
  n++;
  /* for (k = 0; k < lgN; k++)
     print_level(k); */
}

Value stGet(Key key) {
  Link p = &first, q; 
  int k;
  for (k = lgN-1; k >= 0; k--) {
    p = rank(key, p, k); 
    q = p->next[k];
    if (q != nulo && compare(key, q->key) == 0)
      return q->val;
  }
  return NULL;
}

void stDelete(Key key) {
  Link p = &first, q; int k;
  for (k = lgN-1; k >= 0; k--) {
    p = rank(key, p, k); 
    q = p->next[k];
    if (q != nulo && compare(key, q->key) == 0)
      p->next[k] = q->next[k]; 
  }
  if (compare(key, q->key) == 0) {
    free(q);
    n--;
  }
}

bool stContains(Key key) {
  return stGet(key) != NULL; 
}

bool stIsEmpty() {
  return n == 0;
}

void stFree() {
  while (first.next[0] != nulo)
    stDelete(first.next[0]->key);
  n = 0;
}
    
/* Implementação das rotinas do iterador */

static Link current;
    
void stStartIterator() {
  current = &first;
}
    
bool stHasNext() {
  return current->next[0] != nulo;
}
    
Key stNext() {
  current = current->next[0];
  return current->key;
}

/* Implementação das rotinas auxiliares */

static bool compare(Key k1, Key k2) {
  return strcmp(k1, k2); 
}

static void *mallocSafe(size_t nbytes) {
  void *p = malloc(nbytes);
  
  if (p == NULL) {
    printf("Erro: alocação de memória falhou no módulo st.");
    exit(0);
  }
  return p;
}

static Link rank(Key key, Link start, int k) {
  Link p = start, q = p->next[k];
  while (q != nulo && compare(key, q->key) < 0) {
    p = q; 
    q = q->next[k];
  }
  return p;
}

static int randLevel() {
  int level = 0; long r = rand() % (1<<(MAXLEVELS-1));
  while ((r & 1) == 1) {
    if (level == lgN) {
      if (lgN == MAXLEVELS) return MAXLEVELS;
      else return lgN + 1;
    }
    level++;
    r >>= 1;
  }
  return level + 1;
}

static Link newNode(Key key, Value val, int levels) {
  Link p = mallocSafe(sizeof(*p)); int k;
  p->key = key; 
  p->val = val;
  p->next = mallocSafe(levels*sizeof(Link));
  for (k = 0; k < levels; k++) p->next[k] = nulo;
  return p;
}

/*
static void print_level(int k) {
  Link p;
  printf("Nivel %d:\n", k);
  for (p = first.next[k]; p != nulo; p = p->next[k])
    printf("   %s\n", p->key);
  printf("-------\n");
}
*/
