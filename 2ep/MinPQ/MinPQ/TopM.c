#include <stdio.h>
#include <stdlib.h>

#include "transaction.h"
#include "MinPQ.h"
#include "stack.h"

int main(int argc, char *argv[]) {
  int M; Transaction *t;
  if (argc == 0) {
    printf("Digite TopM <valor de M>.\n");
    exit(0);
  }
  M = atoi(argv[1]);
  MinPQInit(M+1);
  while ((t = readT()) != NULL) {
    MinPQInsert(t);
    /* Mantemos as M maiores transacoes na PQ */
    if (MinPQSize() > M) { 
      t = MinPQDelMin();
      freeT(t);
    }
  }
  /* Usamos uma pilha para imprimir da de maior para a de menor valor */
  stackInit();
  while (!MinPQEmpty())
    stackPush(MinPQDelMin());
  while (!stackEmpty()) {
    t = stackPop();
    printT(t);
    freeT(t);
  }
  stackFree();
  MinPQFree();
  return 0;
}
