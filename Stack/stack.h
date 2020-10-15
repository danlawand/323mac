/* ******************** *
 *        stack.h       *
 * ******************** */

#include "item.h"

#define bool int

/* Rotinas principais */

void stackInit();
    
void stackPush(Item);
    
Item stackPop();
    
bool stackIsEmpty();
    
int stackSize();
    
void stackFree();

/* Rotinas do iterador */

void stackStartIterator();
    
bool stackHasNext();

Item stackNext();
