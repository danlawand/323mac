/* ******************** *
 *        MaxPQ.h       *
 * ******************** */
#ifndef _MAXPQ_H
#define _MAXPQ_H
#include "Node.h"

#define bool int

/* Rotinas principais */

void MaxPQInit();

void MaxPQInsert(Link);

Processo MaxPQMax();

void MaxPQDelMax();

void MaxPQDelMeio(int);

Link getMaxPQMax();

Link getMaxPQMeio(int);

int  MaxPQSize();

bool MaxPQEmpty();

void MaxPQFree();

void printMaxPQ();

#endif
