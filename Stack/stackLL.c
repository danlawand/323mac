/* ******************** *
 *        stack.c       *
 * ******************** */

#include<stdlib.h>

#include "node.h"
#include "stack.h"

/* Variáveis privadas da stack */

static Link first;
    
static int n;
    
/* Implementação das rotinas principais */

void stackInit() {
  first = NULL;
  n = 0;
}
    
void stackPush(Item i) {
  first = newNode(i, first);
  n++;
}

Item stackPop() {
  Item k = first->item;
  Link p = first;

  first = first->next;
  freeNode(p);
  n--;
  return k;
}

bool stackIsEmpty() {
  return n == 0;
}
    
int stackSize() {
  return n;
}
    
void stackFree() {
  Link p;

  while (first != NULL) {
    p = first;
    first = first->next;
    freeNode(p);
  }
  n = 0;
}
    
/* Implementação das rotinas do iterador */

static Link current;
    
void stackStartIterator() {
  current = first;
}
    
bool stackHasNext() {
  return current != NULL;
}
    
Item stackNext() {
  Item k = current->item;

  current = current->next;
  return k;
}
