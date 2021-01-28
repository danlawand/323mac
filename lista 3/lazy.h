
#ifndef _LAZY_H
#define _LAZY_H

typedef char* Key;
typedef int Value;

void LinearProbingHashSTInit(int);
Value getLP(Key);
void putLP(Key, Value);
int sizeLP();
void delete(Key);
void lazy_delete(Key);
void printLP();
int sizeDefuntos();
int capa();

#endif
