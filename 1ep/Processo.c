#include "Processo.h"
#include <stdlib.h>

Processo newProcesso (int UT, int linhas, int tempoInicial) {
  Processo p = malloc(sizeof(*p));
  p->UT = UT;
  p->UTiterativo = UT;
  p->linhas = linhas;
  p->tempoInicial = tempoInicial;
  return p;
}

void diminuiUTiterativo (int t, Processo p) {
  if (p->UTiterativo < t) {
    p->UTiterativo = 0;
  } else {
    p->UTiterativo = p->UTiterativo - t;
  }
}

int getUTiterativo (Processo p) {
  return p->UTiterativo;
}

int getUT (Processo p) {
  return p->UT;
}

void diminuiLinhas (int l, Processo p) {
  if (p->linhas < l) {
    p->linhas = 0;
  } else {
    p->linhas = p->linhas - l;
  }
}

int getLinhas (Processo p) {
  return p->linhas;
}

int getTempoInicial(Processo p) {
  return p->tempoInicial;
}

void freeProcesso(Processo p) {
  free(p);
}
