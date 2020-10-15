#ifndef _NODE_H
#define _NODE_H
#include "Processo.h"

typedef struct circularNode *Link;
struct circularNode {
  Processo processo;
  Link next;
  Link previous;
};

Link newNodeCircular (Processo, Link, Link);

void freeNodeCircular (Link);

#endif
