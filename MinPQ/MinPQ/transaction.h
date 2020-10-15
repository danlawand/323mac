/* ******************* *
 *    transaction.h    *
 * ******************* */

#ifndef HEADER_Transaction

#define HEADER_Transaction

#define bool int

struct transaction {
  char  nome[12];
  int   dia, mes, ano;
  float valor;
};

typedef struct transaction Transaction;

/* Rotinas principais */

bool lessT(Transaction *, Transaction *); 

Transaction *readT(); 

void printT(Transaction *); 

void freeT(Transaction *); 

#endif
