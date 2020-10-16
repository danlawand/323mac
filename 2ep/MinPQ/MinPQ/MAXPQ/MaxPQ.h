/* ******************** *
 *        MinPQ.h       *
 * ******************** */

#include "item.h"

#define bool int

/* Rotinas principais */

void MaxPQInit();

void MaxPQInsert(Item);

Item MaxPQMax();

Item MaxPQDelMax();

int  MaxPQSize();

bool MaxPQEmpty();

void MaxPQFree();

void printMaxPQ();
