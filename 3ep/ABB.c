#include "ABB.h"
#include "stdio.h"
#include "stdlib.h"
#include "string.h"

static NodeAbb r;
static int n = 0;
FILE *pFile;

static void *mallocSafe(size_t nbytes);

static void inOrdem(NodeAbb, FILE *);
static NodeAbb putTree(NodeAbb, Key);
static NodeAbb getTree(NodeAbb, Key);
static int compare(Key, Key);

NodeAbb newNodeABB (Key key, Value val) {
  n++;
  NodeAbb p = mallocSafe(sizeof(*p));
  p->key = key;
  p->val = val;
  p->left = NULL;
  p->right = NULL;
  return p;
}

Value getABB (Key key) {
  NodeAbb x = getTree(r, key);
  if (x == NULL) return 0;
  return x->val;
}

void putABB (Key key){//, Value val) {
  r = putTree(r, key);//, val);
}

void printABB() {
  pFile = fopen ( "abb.txt" , "w" );
  inOrdem(r, pFile);
  fclose(pFile);
}

int sizeABB() {
  return n;
}
/* Implementação das rotinas auxiliares */
static void inOrdem(NodeAbb r, FILE *file) {
  if (r != NULL) {
    inOrdem(r->left, file);
    fprintf (file,"Palavra: %s <<<<>>>> N. Ocorrencias: %d\n", r->key, r->val);
    // printf("Palavra: %s <<<<>>>> N. Ocorrencias: %d\n", r->key, r->val);
    inOrdem(r->right, file);
  }
}

static NodeAbb putTree(NodeAbb x, Key key) {//, Value val) {
  if (x == NULL)
    return newNodeABB(key, 1);
  int cmp = compare(key, x->key);
  if (cmp < 0)
    x->left = putTree(x->left, key);//, val);
  else if (cmp > 0)
    x->right = putTree(x->right, key);//, val);
  else x->val++;/// = val;
  return x;
}


static NodeAbb getTree(NodeAbb x, Key key) {
  if (x == NULL) return NULL;
  int cmp = compare(key, x->key);
  if (cmp < 0)
    return getTree(x->left, key);
  if (cmp > 0)
    return getTree(x->right, key);
  return x;
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
