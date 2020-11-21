/* *************************** *
 *        stSortedList.c       *
 * *************************** */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include "st.h"

/* Variáveis privadas da stack */

static Key *keys;
    
static Value *vals;
    
static int s;
    
static int n;
    
/* Protótipo de rotinas auxiliares */

static void *mallocSafe(size_t);
static void stResize(int);
static int compare (Key, Key);
static int rank(Key key);

/* Implementação das rotinas principais */

void stInit() {
  keys = mallocSafe(sizeof(Key));
  vals = mallocSafe(sizeof(Queue));
  s = 1;
  n = 0;
}
    
void stPut(Key key, Value val) {
  int i = rank(key), j;
  if (i < n && compare(key, keys[i]) == 0) 
    vals[i] = val;
  else {
    if (n == s) stResize(2*s);
    for (j = n; j > i; j--) {
      keys[j] = keys[j-1];
      vals[j] = vals[j-1];
    }
    keys[i] = key;
    vals[i] = val;
    n++;
  }
}

Value stGet(Key key) {
  int i = rank(key); 
  if (i < n && compare(keys[i], key) == 0)
    return vals[i];
  return NULL;
}

void stDelete(Key key) {
  int i = rank(key);
  if (i < n && compare(key, keys[i]) != 0) return;
  for (; i < n - 1; i++) {
    keys[i] = keys[i+1];
    vals[i] = vals[i+1];
  }
  n--;
  if (n > 0 && n == s/4) stResize(s/2);
}

int stRank(Key key) {
  int i; 
  for (i = 0; i < n; i++)
    if (compare(keys[i], key) >= 0)
      return i;
  return n;
}

bool stContains(Key key) {
  int i; 
  for (i = 0; i < n; i++)
    if (compare(keys[i], key) == 0)
      return 1; 
  return 0;
}

bool stIsEmpty() {
  return n == 0;
}

void stFree() {
  free(keys);
  free(vals);
  n = 0;
}
    
/* Implementação das rotinas do iterador */

static int current;
    
void stStartIterator() {
  current = 0;
}
    
bool stHasNext() {
  return current < n;
}
    
Key stNext() {
  current++;
  return keys[current-1];
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

static void stResize(int capacity) {
  int i;
  Key   *tmpa, *a = mallocSafe(capacity*sizeof(Key));
  Value *tmpb, *b = mallocSafe(capacity*sizeof(Value));

  if (capacity < n) {
    printf("Error: invalid capacity choice.\n");
    exit(0);
  }

  for (i = 0; i < n; i++) {
    a[i] = keys[i]; 
    b[i] = vals[i];
  }
  s = capacity;
  tmpa = keys;
  tmpb = vals;
  keys = a;
  vals = b;
  free(tmpa);
  free(tmpb);
}

static int rank(Key key) {
  int lo = 0, hi = n-1, mid, cmp;
  while (lo <= hi) {
    mid = (lo + hi)/2;
    cmp = compare(key, keys[mid]);
    if (cmp < 0) hi = mid - 1;
    else if (cmp > 0) lo = mid + 1;
    else return mid;
  }
  return lo;
}
