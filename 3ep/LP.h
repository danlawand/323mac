#ifndef _LP_H
#define _LP_H

typedef char* Key;
typedef int Value;

void LinearProbingHashSTInit(int);
Value getLP(Key);
void putLP(Key);
int sizeLP();


#endif
