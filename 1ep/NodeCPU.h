#include "Processo.h"

typedef struct stackNode *Link;

struct stackNode {
  Processo processo;
  Link *next;
  Link *previous;
};

/*Processo, next, previous*/
void newNode (Processo, Link, Link);
void freeNode (Link);
