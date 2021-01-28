/* ***************** *
 *        st.h       *
 * ***************** */

#include "stItem.h"

#define bool int
#define TRUE 1
#define FALSE 0

/* Rotinas principais */

void stInit();
    
void stPut(Key, Value);
    
Value stGet(Key);
    
void stDelete(Key);

bool stContains(Key);
    
int  stRank(Key);
    
bool stEmpty();
    
void stFree();

/* Rotinas do iterador */

void stStartIterator();
    
bool stHasNext();

Key stNext();
