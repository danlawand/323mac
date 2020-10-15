/* ******************** *
 *        node.h        *
 * ******************** */

#include "item.h"

typedef struct stackNode *Link;

struct stackNode {
  Item item;
  Link next;
};

Link newNode(Item, Link);

void freeNode(Link);
