/* ******************** *
 *        stack.h       *
 * ******************** */

#define bool int

#include "item.h"

/* Rotinas principais */

void stackInit();
    
void stackPush(Item);
    
Item stackPop();
    
bool stackEmpty();
    
int stackSize();
    
void stackFree();

/* Rotinas do iterador */

void stackStartIterator();
    
bool stackHasNext();

Item stackNext();
