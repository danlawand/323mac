#ifndef _MTF_H
#define _MTF_H

typedef char* Key;
typedef int Value;

typedef struct mtf MTF;
struct mtf {
  Key key;
  Value val;
  MTF *next;
};

void MTFInit(int);
Value getMTF(Key);
void putMTF(Key);
int sizeMTF();

#endif
