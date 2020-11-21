#ifndef _ABB_H
#define _ABB_H

typedef char* Key;
typedef int Value;

typedef struct nodeabb *NodeAbb;
struct nodeabb {
  Key key;
  Value val;
  NodeAbb left, right;
};

NodeAbb newNodeABB (Key, Value);
Value getABB (Key);
void putABB (Key);
void printABB();
int sizeABB();
#endif
