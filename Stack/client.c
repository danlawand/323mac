#include<stdio.h>

#include "stack.h"
#include <string.h>

int main(int argc, char *argv[]) {
  int i;

  stackInit();
  for (i = 1; i < argc; i++) 
    if (strcmp(argv[i], "-") != 0) 
      stackPush(argv[i]);
    else if (!stackIsEmpty())
      printf("%s + ", stackPop());
    
  printf("(%d left on stack)\n", stackSize());
  stackFree();
  return 0;
}
