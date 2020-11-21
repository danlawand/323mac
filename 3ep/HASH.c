#include "HASH.h"
#include "stdlib.h"
#include "stdio.h"
#include <string.h>


static int n;/* número de chaves */
static int m;/* tam. da tabela de hash */

/* vetor da tabela de símbolos */
static Item **st;

static void put(int, Key, Value);
static Value get(int, Key);
static void resize(int);
static void insertST(Key , Value);
static void freeST(Item**, int);
static int hash(Key);
static void *mallocSafe(size_t nbytes);
static int compare(Key, Key);


void SeparateChainingHashSTInit(int size) {
  n = 0;
  m = size;
  st = mallocSafe(m * sizeof(*st));
  for (int h = 0; h < m; h++)
    st[h] = NULL;
}

Value getST(Key key) {
  int h = hash(key);
  return get(h, key);
}

void putST(Key key) {
  if (n >= 10*m) resize(2*m);
  int h = hash(key);
  put(h, key, 1);
}

int sizeHASH() {
  return n;
}

static void put(int h, Key key, Value val) {
  /*Implementar aqui a lista encadeada*/
  Item *p, *q, *item;
  if (st[h] ==  NULL) {
    item = mallocSafe(sizeof(*item));
    item->key = key;
    item->val = val;
    item->next = NULL;
    st[h] = item;
    n++;
    return;
  }
  for (p = st[h]; p != NULL; p = p->next) {
    q = p;
    if (compare(p->key, key) == 0) {
      p->val = p->val + 1;
      return;
    }
  }
  item = mallocSafe(sizeof(*item));
  item->key = key;
  item->val = val;
  item->next = NULL;
  q->next = item;
  n++;
}

static Value get(int h, Key key) {
  Item *p;
  for (p = st[h]; p != NULL ; p = p->next) {
    if (compare(p->key, key) == 0) {
      return p->val;
    }
  }
  return 0;
}

static void resize(int size) {
  Item *p, **t = st;
  int h, aux = m;
  m = size;
  st = mallocSafe(size*sizeof(*st));
  for (h = 0; h < m; h++) st[h] = NULL;
  for (h = 0; h < aux; h++) {
    for (p = t[h]; p != NULL; p = p->next) {
      insertST(p->key, p->val);
    }
  }
  freeST(t, aux); /*Precisa implementar isso*/
}

static void insertST(Key key, Value val) {
  int h = hash(key);
  Item *p, *item;
  if (st[h] == NULL) {
    item = mallocSafe(sizeof(*item));
    item->key = key;
    item->val = val;
    item->next = NULL;
    st[h] = item;
    return;
  }
  for (p = st[h]; p->next != NULL ; p = p->next);
  item = mallocSafe(sizeof(*item));
  item->key = key;
  item->val = val;
  item->next = NULL;
  p->next = item;
}

static void freeST(Item** t, int aux) {
  Item *q, *p;
  int h;
  for (h = 0; h < aux; h++) {
    for (p = t[h]; p != NULL; p = p->next) {
      q = p;
      free(p);
      p = q;
    }
  }
  free(t);
}

static int hashCode(Key key) {
  int h = 0;
  for (int i = 0; i < strlen(key); i++)
    h = (31 * h + key[i]) % m;
  return h;
}

static int hash(Key key) {
  return hashCode(key) % m;
}

static int compare(Key k1, Key k2) {
  return strcmp(k1, k2);
}

static void *mallocSafe(size_t nbytes) {
  void *p = malloc(nbytes);

  if (p == NULL) {
    printf("Erro: alocação de memória falhou no módulo Node.");
    exit(0);
  }
  return p;
}
