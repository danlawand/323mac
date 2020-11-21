#include "ARN.h"
#include "stdio.h"
#include "stdlib.h"
#include "string.h"

#define RED 1
#define BLACK 0

static NodeARN r;
static int quantidade = 0;
FILE *pFile;

static void *mallocSafe(size_t nbytes);
static bool isRed(NodeARN);
static NodeARN getTree(NodeARN, Key);
static NodeARN rotateLeft(NodeARN);
static NodeARN rotateRight(NodeARN);
static void flipColors(NodeARN);
static NodeARN putTree(NodeARN, Key);
static NodeARN balance(NodeARN);
static void inOrdem(NodeARN, FILE*);
static int sizeRamo(NodeARN);
static int compare(Key, Key);

NodeARN newNodeARN (Key key, Value val, int n, bool color) {
  NodeARN p = mallocSafe(sizeof(*p));
  quantidade++;
  p->key = key;
  p->n = n;
  p->left = NULL;
  p->val = val;
  p->color = color;
  p->right = NULL;
  return p;
}

Value getARN(Key key) {
  NodeARN x = getTree(r, key);
  if (x == NULL) return 0;
  return x->val;
}

void putARN(Key key) {//, Value val) {
  r = putTree(r, key);//, val);
  r->color = BLACK;
}

void printARN() {
  pFile = fopen ( "arn.txt" , "w" );
  inOrdem(r, pFile);
  fclose(pFile);
}

int sizeARN() {
  return quantidade;
}
/* Implementação das rotinas auxiliares */
static void inOrdem(NodeARN r, FILE *file) {
  if (r != NULL) {
    inOrdem(r->left, file);
    fprintf (file,"Palavra: %s <<<<>>>> N. Ocorrencias: %d\n", r->key, r->val);
    // printf("Palavra: %s <<<<>>>> N. Ocorrencias: %d\n", r->key, r->val);
    inOrdem(r->right, file);
  }
}

static NodeARN balance(NodeARN h) {
  if (isRed(h->right) && !isRed(h->left)) {
    h = rotateLeft(h);
  }
  if (isRed(h->left) && isRed(h->left->left)) {
    h = rotateRight(h);
  }
  if (isRed(h->left) && isRed(h->right)){
    flipColors(h);
  }
  return h;
}


static NodeARN putTree(NodeARN h, Key key) {//, Value val) {
  if (h == NULL) {
    return newNodeARN(key, 1, 1, RED);
  }
  int cmp = compare(key, h->key);
  if (cmp < 0) {
    h->left = putTree(h->left, key);//, val);
  } else if (cmp > 0) {
    h->right = putTree(h->right, key);//, val);
  } else h->val = h->val + 1;
  h = balance(h);
  return h;
}

static void flipColors(NodeARN h) {
  h->color = RED;
  h->left->color  = BLACK;
  h->right->color = BLACK;
}

static int sizeRamo(NodeARN h) {
  if (h == NULL) return 0;
  return h->n;
}

static NodeARN rotateRight(NodeARN h) {
  NodeARN x = h->left;
  h->left = x->right;
  x->right = h;
  x->color = h->color;
  h->color = RED;
  x->n = h->n;
  h->n = 1 + sizeRamo(h->left) + sizeRamo(h->right);
  return x;
}


static NodeARN rotateLeft (NodeARN h) {
  NodeARN x = h->right;
  h->right = x->left;
  x->left = h;
  x->color = h->color;
  h->color = RED;
  x->n = h->n;
  h->n = 1 + sizeRamo(h->left) + sizeRamo(h->right);
  return x;
}

static NodeARN getTree(NodeARN x, Key key) {
  if (x == NULL) return NULL;
  int cmp = compare(key, x->key);
  if (cmp < 0) return getTree(x->left, key);
  else if (cmp > 0) return getTree(x->right, key);
  else return x;
}

static bool isRed(NodeARN x) {
  if (x == NULL) return 0;
  return x->color == RED;
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
