#include <stdio.h>
#include <stdlib.h>
#include "queue.h"
#include <string.h>



int main(int argc, char *argv[]) {
  int i;
  char a, b, c, d;
  queueInit();
/*  for (i = 1; i < argc; i++)
    if (strcmp(argv[i], "-") != 0)
      queueInsert(argv[i]);
   for (i = 1; i < argc; i++)
    if (!queueEmpty())
      printf("%s + ", queueRemove());*/
  scanf("%c%c", &a, &b);
  while (a != 'f') {
    if (a == 'a') {
      printf("ESCOLHE CHAR\n");
      scanf("%c%c", &c, &d);
      queueInsert(c);
      printqueue();
    } else {
      if (!queueEmpty())
        printf("%c + ", queueRemove());
    }
    printf("F ou não\n");
    scanf("%c%c", &a, &b);
  }

  printf("(%d left on queue)\n", queueSize());
  queueFree();
  return 0;
}
