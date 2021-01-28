#include <stdio.h>
#include <stdlib.h>
#include "MaxPQ.h"
#include <string.h>



int main(int argc, char *argv[]) {
  int ia;
  char a, b;
  MaxPQInit();
/*  for (i = 1; i < argc; i++)
    if (strcmp(argv[i], "-") != 0)
      queueInsert(argv[i]);
   for (i = 1; i < argc; i++)
    if (!queueEmpty())
      printf("%s + ", queueRemove());*/
  scanf(" %c", &a);

  while (a != '0') {
    if (a == 'c') {
      printf("ESCOLHE INT\n");
      scanf(" %c", &b);
      ia = b - '0';
      MaxPQInsert(ia);
      printMaxPQ();
    } else {
      if (!MaxPQEmpty()) {
        printf("%d + \n", MaxPQDelMax());
        printMaxPQ();
      }
    }
    printf("(C)ontinua ou (R)emove?\n");
    scanf(" %c", &a);
  }

  printf("(%d left on queue)\n", MaxPQSize());
  MaxPQFree();
  return 0;
}
