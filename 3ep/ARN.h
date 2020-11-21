#ifndef _ARN_H
#define _ARN_H

#define bool int
typedef char* Key;
typedef int Value;

typedef struct nodearn *NodeARN;
struct nodearn {
  Key key;
  Value val;
  int n;
  bool color;
  NodeARN left, right;
};

NodeARN newNodeARN (Key, Value, int, bool);
Value getARN(Key);
void putARN(Key);
void printARN();
int sizeARN();
#endif
