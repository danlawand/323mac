#include "SkipListST.h"
#include "stdlib.h"
#include <stdio.h>

int main(int argc, char const *argv[]) {
  stInit(10);
  int ia;
  char a, b;
  scanf(" %c", &a);
  while (a != '0') {
    if (a == 'c') {
      printf("ESCOLHE INT\n");
      scanf(" %c", &b);
      ia = b - '0';
      stPut(ia, ia);
      stPrint();
      printf("PAAE\n");
    }// } else {
    //   if (!queueEmpty())
    //     printf("%c + ", queueRemove());
    // }
    printf("(C)ontinua ou (R)emove?\n");
    scanf(" %c", &a);
  }

  return 0;
}
