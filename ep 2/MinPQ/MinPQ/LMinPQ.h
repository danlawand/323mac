/* ******************** *
 *       LMinPQ.h       *
 * ******************** */

#include "transaction.h"

#define bool int

/* Rotinas principais */

void MinPQInit(int);
    
void MinPQInsert(Transaction *);
    
Transaction *MinPQMin();
    
Transaction *MinPQDelMin();

int  MinPQSize();

bool MinPQEmpty();
    
void MinPQFree();

