#include "NodeCPU.h"
#include "Processo.h"
#define bool int

/*Construtor*/
void filaInit();

/*Adiciona Processo na Fila*/
void addNode(Processo);

/*Retorna o tamanho da Fila*/
int filaSize();

/*Devolve true se a fila está vazia*/
bool filaIsEmpty();

/*Destrutor*/
void filaFree();

/*Inicia a iteracao*/
void filaStartIterator();

/*Devolve true se tem próximo na fila*/
bool filaHasNext();

/*Retorna o próximo processo na fila*/
Processo filaNext();
