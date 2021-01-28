#ifndef _ST_H
#define _ST_H
#include <stdlib.h>
#include <stdio.h>

typedef struct node *Link;
struct node{
  int key;
  int val;
  Link *next;
};


Link newNode(int, int, int);

#endif
