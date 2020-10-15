#include <stdio.h>
#include <stdlib.h>
#include "MaxPQ.h"
#include "Espera.h"
#include <string.h>



int main(int argc, char *argv[]) {
  Espera espera = EsperaInit();
  int ia;
  char a, b;
  int procID = 1;
  int tempoDeProcessamento, lines, tempoInicial, prioridade;
  int i = 0;
  int alterna = 0;
  Processo p;
  // Link no;
  MaxPQInit();

  scanf(" %c", &a);
  while (a != '0') {
    if (a == 'c') {
      printf("ESCOLHE INT\n");
      scanf(" %c", &b);
      tempoDeProcessamento = i;
      lines = i;
      prioridade = b - '0';
      tempoInicial = i;
      p = newProcesso(tempoDeProcessamento, lines, tempoInicial, procID, prioridade);
      addProcessoEspera(p, espera);
      procID++;
      // MaxPQInsert(p);
      printEspera(espera);
      // printMaxPQ();
    } else {
      if (!EsperaIsEmpty(espera)) {
        printf("REMOVE QUAL POSIÇÃO?\n");
        scanf(" %c", &b);
        ia = b - '0';
        printf("Processo REMOVIDO --\n");
        imprimeNovoProcesso(retiraProcessoEspera(espera, alterna));
        alterna++;
        printf("vvvvvv--- SITUACAO ATUAL --vvvvvv\n");
        printEspera(espera);
      }
    }
    i++;
    printf("(C)ontinua ou (R)emove?\n");
    scanf(" %c", &a);
  }

  // printf("(%d left on queue)\n", MaxPQSize());
  MaxPQFree();
  return 0;
}
