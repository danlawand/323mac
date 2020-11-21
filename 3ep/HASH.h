#ifndef _HASH_H
#define _HASH_H

typedef char* Key;
typedef int Value;

typedef struct pair Item;
struct pair {
  Key key;
  Value val;
  Item *next;
};

void SeparateChainingHashSTInit(int);
Value getST(Key);
void putST(Key);
int sizeHASH();
#endif
