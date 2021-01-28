/* ************************* *
 *        stSortedLL.c       *
 * ************************* */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include "st.h"

/* Variáveis privadas da stack */

typedef struct node *Link;

struct node {
  Key key;
  Value val;
  Link next;
};

static struct node first; /* cabeça */
    
static int n;
    
/* Protótipo de rotinas auxiliares */

static Link newNode(Key, Value, Link); 
static void *mallocSafe(size_t);
static int compare (Key, Key);
static Link rank(Key key);

/* Implementação das rotinas principais */

void stInit() {
  first.key = first.val = first.next = NULL;
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
}

Value stGet(Key key) {
  Link p = rank(key);
  if (p->next != NULL && compare(key, p->next->key) == 0)
    return p->next->val;
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
  return p->next != NULL && compare(key, p->next->key) == 0;
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
    
void stStartIterator() {
  current = &first; 
}
    
bool stHasNext() {
  return current->next != NULL;
}
    
Key stNext() {
  current = current->next;
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
  Link p = &first;
  while (p->next != NULL && compare(key, p->next->key) < 0) p = p->next;
  return p;
}

static Link newNode(Key key, Value val, Link next) {
  Link p = mallocSafe(sizeof(*p));
  p->key = key; 
  p->val = val;
  p->next = next;
  return p;
}
