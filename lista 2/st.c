#include "st.h"
#include <stdlib.h>
#include <stdio.h>
static void *mallocSafe(size_t);

Link newNode(int key, int val, int levels) {
  Link p = mallocSafe(sizeof(*p));
  int k;
  p->key = key;
  p->val = val;
  p->next = mallocSafe(levels * sizeof(Link));
  for (k = 0; k < levels; k++) {
    p->next[k] = NULL;
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
