#include "lazy.h"
#include "stdio.h"
#include "stdlib.h"
#include "string.h"

static int n;
static int m;
static int defuntos;
static Key   *keys;
static Value *vals;


static void resizeLP(int);
static void insertLP(Key, Value);
static int hashCode(Key);
static int hash(Key);
static int compare(Key, Key);
static void *mallocSafe(size_t nbytes);
static int contains(Key);


void LinearProbingHashSTInit(int cap) {
  int h;
  m = cap;
  defuntos = 0;
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
  return NULL;
}

void putLP(Key key, Value val) {
  int h, i, j;
  if (n + defuntos >= m/2) resizeLP(2*m);

  for (h=hash(key); keys[h]!=NULL; h=(h+1)%m)
    if (compare(keys[h], key) == 0) {
      free(key);
      if (vals[h] == NULL) {
        defuntos--;
        n++;
        vals[h] = 0;
      }
      vals[h] = vals[h] + 1;
      return;
    }

  keys[h] = key;
  vals[h] = val;
  n++;
}

int sizeLP(){
  return n;
}

void printLP() {
  int h;
  for (h = 0; h <= m; h++) {
    if (keys[h] != NULL) printf("%s -- ", keys[h]);
  }
  printf("\n");
}

int sizeDefuntos() {
  return defuntos;
}
int capa() {
  return m;
}

void delete(Key key) {
  if (!contains(key)) return;

  /*Procure key*/
  int h = hash(key);
  while (compare(key, keys[h]) != 0)
    h = (h + 1) % m;

  /*remova key*/
  keys[h] = NULL;
  vals[h] = 0;
  n--;

  /*rehash todas as chaves no cluster*/
  h = (h + 1) %m;
  while (keys[h] != NULL) {
    Key keyToRehash = keys[h];
    Value valToRehash = vals[h];
    keys[h] = NULL;
    vals[h] = 0;
    n--;
    putLP(keyToRehash, valToRehash);
    h = (h + 1) % m;
  }

  /*resize se alfa <= 0.125*/
  if (n > 0 && 8*n <= m) resizeLP(m/2);
}

void lazy_delete(Key key) {
  if (!contains(key)) return;

  /*Procure key*/
  int h = hash(key);
  while (compare(key, keys[h]) != 0)
    h = (h + 1) % m;

  /*remova key*/
  vals[h] = NULL;
  n--;
  defuntos++;

  if (n <= defuntos && n > 0 && 8*n <= m) {
   resizeLP(m/2);
  }
}

static void resizeLP(int cap) {
  Key *k = keys;
  Value *v = vals;
  int h, aux = m;
  m = cap;
  keys = mallocSafe(m * sizeof(Key));
  vals = mallocSafe(m * sizeof(Value));
  for (h = 0; h < m; h++) {
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

static int contains(Key key) {
  if (getLP(key) != 0) return 1;
  return 0;
}

static void insertLP(Key key, Value val) {
  int h;
  if (val == NULL) {
    free(key);
    defuntos--;
    return;
  }
  for (h = hash(key); keys[h] != NULL; h=(h+1)%m);
  keys[h] = key;
  vals[h] = val;
  return;
}


static int hashCode(Key key) {
  int i, h = 0;
  for (i = 0; i < strlen(key); i++)
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
