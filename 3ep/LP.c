#include "LP.h"
#include "stdio.h"
#include "stdlib.h"
#include "string.h"

static int n;
static int m;
static Key   *keys;
static Value *vals;


static void resizeLP(int);
static void insertLP(Key, Value);
static int hashCode(Key);
static int hash(Key);
static int compare(Key, Key);
static void *mallocSafe(size_t nbytes);


void LinearProbingHashSTInit(int cap) {
  int h;
  m = cap;
  keys = mallocSafe(m * sizeof(Key));
  vals = mallocSafe(m * sizeof(Value));
  for (h = 0; h < m; h++) {
    keys[h] = NULL;
    vals[h] = 0;
  }
  n = 0;
}

Value getLP(Key key) {
  int h;
  for (h=hash(key); keys[h]!=NULL; h=(h+1)%m)
    if (compare(keys[h], key) == 0)
      return vals[h];
  return 0;
}

void putLP(Key key) {
  if (n >= m/2) resizeLP(2*m);
  int h;
  for (h=hash(key); keys[h]!=NULL; h=(h+1)%m)
    if (compare(keys[h], key) == 0) {
      vals[h] = vals[h] + 1;
      return;
    }
  keys[h] = key;
  vals[h] = 0;
  n++;
}

int sizeLP(){
  return n;
}

static void resizeLP(int cap) {
  Key *k = keys;
  Value *v = vals;
  int h, aux = m;
  m = cap;
  keys = mallocSafe(m * sizeof(Key));
  vals = mallocSafe(m * sizeof(Value));
  for (int h = 0; h < m; h++) {
    keys[h] = NULL;
    vals[h] = 0;
  }
  for (h = 0; h < aux; h++) {
    if (k[h] != NULL)
      insertLP(k[h], v[h]);
  }
  free(k);
  free(v);
}

static void insertLP(Key key, Value val) {
  int h;
  for (h=hash(key); keys[h] != NULL; h=(h+1)%m);
  keys[h] = key;
  vals[h] = val;
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
