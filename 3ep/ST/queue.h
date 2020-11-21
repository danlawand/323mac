/*
 * queue.h 
 * INTERFACE: funcoes para manipular a fila 
 * ATENCAO: Esta interface permite que varias filas 
 *          sejam utilizadas simultaneamente.
 */

#ifndef HEADER_Queue

#define HEADER_Queue

#include "item.h"

typedef void *Queue;

Queue queueInit();
int  queueEmpty(Queue);
int  queueSize(Queue);
void queuePut(Queue,Item);
Item queueGet(Queue);
void queueFree(Queue);
void queueDump(Queue);

#endif
