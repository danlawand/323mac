/* ******************** *
 *        stMTF.c       *
 * ******************** */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include "st.h"

/* Variáveis privadas da stack */

typedef struct cell *Link;

struct cell {
  Key key;
  Value val;
  Link next;
};

static struct cell first; 
    
static int n;
    
/* Protótipo de rotinas auxiliares */

static Link newNode(Key, Value, Link); 
static void *mallocSafe(size_t);
static int  compare (Key, Key);
static Link rank(Key);
static void moveToFront(Link);

/* Implementação das rotinas principais */

void stInit() {
  first.key = first.val = first.next = NULL; /* cabeca */
  n = 0;
}
    
void stPut(Key key, Value val) {
  Link p = rank(key), q;
  if (p->next != NULL && compare(key, p->next->key) == 0) 
    p->next->val = val;
  else {
    q = newNode(key, val, p->next);
    p->next = q;
    n++;
  }
  moveToFront(p);
}

Value stGet(Key key) {
  Link p = rank(key); 
  if (p->next != NULL && compare(key, p->next->key) == 0) {
    moveToFront(p);
    return first.next->val;
  }
  return NULL;
}

void stDelete(Key key) {
  Link p = rank(key), q;
  if (p->next != NULL && compare(key, p->next->key) != 0) return;
  q = p->next;
  p->next = q->next;
  free(q);
  n--;
}

bool stContains(Key key) {
  Link p = rank(key);
  if (p->next != NULL && compare(key, p->next->key) == 0) {
    moveToFront(p);
    return TRUE;
  }
  else
    return FALSE;
}

bool stIsEmpty() {
  return n == 0;
}

void stFree() {
  Link q; 
  while (first.next != NULL) {
    q = first.next;
    first.next = q->next;
    free(q);
  }
  n = 0;
}
    
/* Implementação das rotinas do iterador */

static Link current;
static Link curnext;
    
void stStartIterator() {
  current = &first;
  curnext = current->next;
}
    
bool stHasNext() {
  return curnext != NULL;
}
    
Key stNext() {
  current = curnext;
  curnext = current->next;
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

static Link rank(Key key) {
  Link p = &first, q = first.next;
  while (q != NULL && compare(key, q->key) != 0) {
    p = q; 
    q = q->next;
  }
  return p;
}

static void moveToFront(Link p) {
  Link q;
  if (p == &first || p->next == NULL) return;
  q = p->next;
  p->next = q->next;
  q->next = first.next;
  first.next = q;
}

static Link newNode(Key key, Value val, Link next) {
  Link p = mallocSafe(sizeof(*p));
  p->key = key; 
  p->val = val;
  p->next = next;
  return p;
}
