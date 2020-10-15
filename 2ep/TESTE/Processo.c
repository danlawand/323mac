#include "Processo.h"
#include <stdio.h>
#include <stdlib.h>

/* Protótipo de rotinas auxiliares */
static void *mallocSafe(size_t nbytes);

Processo newProcesso (int tempoDeProcessamento, int linhas, int tempoInicial, int procID, int prioridade) {
  Processo p = mallocSafe(sizeof(*p));
  p->prioridade = prioridade;
  p->tempoDeProcessamento = tempoDeProcessamento;
  p->tempoDeProcessamentoInicial = tempoDeProcessamento;
  p->linhas = linhas;
  p->linhasIniciais = linhas;
  p->tempoInicial = tempoInicial;
  p->UTcpu = 0;
  p->numero = procID;
  p->inicioCPU = 0;
  p->fimCPU = 0;
  p->inicioImpressao = 0;
  p->fimImpressao = 0;
  p->inicioEspera = 0;
  p->fimEspera = 0;
  return p;
}

void imprimeProcessoTermino(Processo processo) {
  double razao;
  printf("Processo Terminado Nº: %d\n", processo->numero);
  printf("Prioridade: %d\n", processo->prioridade);
  printf("Tempo de Processamento Inicial: %d\n", processo->tempoDeProcessamentoInicial);
  printf("Linhas Iniciais: %d\n", processo->linhasIniciais);
  printf("Tempo de Chegada: %d\n", processo->tempoInicial);
  printf("Tempo Final: %d\n", processo->tempoFinal);
  printf("Tempo Total de Permanência no Sistema: %d\n", processo->tempoFinal - processo->tempoInicial);
  printf("Tempo de Permanência na Fila de Espera: %d\n", processo->fimEspera - processo->inicioEspera);
  printf("Tempo de Permanência na Fila da CPU: %d\n", processo->fimCPU - processo->inicioCPU);
  printf("Tempo de Permanência na Fila de Impressão: %d\n", processo->fimImpressao - processo->inicioImpressao);
  razao = ((double) processo->tempoDeProcessamentoInicial)/((double)(processo->tempoFinal - processo->tempoInicial));
  printf("Razão Tempo de Processamento por Tempo Total de Permanência: %f\n\n", razao);
}

void imprimeNovoProcesso(Processo processo) {
  printf("Processo Nº: %d --- ", processo->numero);
  printf("Prioridade: %d --- ", processo->prioridade);
  // printf("Tempo de Processamento Inicial: %d\n", processo->tempoDeProcessamentoInicial);
  // printf("Linhas Iniciais: %d\n", processo->linhasIniciais);
  printf("Tempo de Chegada: %d --- ", processo->tempoInicial);
  printf("Posicao: %d\n", processo->posicao);
}

void imprimeProcesso(Processo processo, int i) {
  int tEspera;
  int tCPU;
  int tImpressao;
  int dt = i - processo->tempoInicial;
  double razao;
  printf("Processo Nº: %d\n", processo->numero);
  printf("Prioridade: %d\n", processo->prioridade);
  printf("Tempo de Processamento Inicial: %d\n",  processo->tempoDeProcessamentoInicial);
  printf("Linhas Iniciais: %d\n", processo->linhasIniciais);
  printf("Linhas Restantes: %d\n", processo->linhas);
  printf("Tempo de Chegada: %d\n", processo->tempoInicial);
  printf("Tempo Atual: %d\n", i);
  printf("Tempo de Permanência no Sistema: %d\n", dt);

  if (processo->fimEspera > 0) {
    tEspera = processo->fimEspera - processo->inicioEspera;
  } else if (processo->inicioEspera > 0) {
    tEspera = i - processo->inicioEspera;
  } else {
    tEspera = 0;
  }
  printf("Tempo de Permanência na Fila de Espera: %d\n", tEspera);

  if (processo->fimCPU > 0) {
    tCPU = processo->fimCPU - processo->inicioCPU;
  } else if (processo->inicioCPU > 0) {
    tCPU = i - processo->inicioCPU;
  } else {
    tCPU = 0;
  }
  printf("Tempo de Permanência na Fila da CPU: %d\n", tCPU);

  if (processo->fimImpressao > 0) {
    tImpressao = processo->fimImpressao - processo->inicioImpressao;
  } else if (processo->inicioImpressao > 0) {
    tImpressao = i - processo->inicioImpressao;
  } else {
    tImpressao = 0;
  }
  printf("Tempo de Permanência na Fila de Impressão: %d\n", tImpressao);

  if (dt != 0) {
    razao = ((double) processo->tempoDeProcessamentoInicial)/((double)(dt));
  } else {
    razao = 0.00;
  }
  printf("Razão Tempo de Processamento por Tempo Total de Permanência: %f\n\n", razao);

}

int getPrioridade(Processo p) {
  return p->prioridade;
}


int getLinhas(Processo p) {
  return p->linhas;
}

void decresceLinhas(Processo processo) {
  /*Altera a quantidade de linhas do processo atual*/
  if (processo->linhas < 10) {
    processo->linhas = 0;
  } else {
    processo->linhas-=10;
  }
}

int getTempoDeProcessamento(Processo processo) {
  return processo->tempoDeProcessamento;
}

void decresceTempoDeProcessamento(Processo processo){
  processo->tempoDeProcessamento--;
}

int getUTcpu(Processo processo) {
  return processo->UTcpu;
}

void resetUTcpu(Processo processo) {
  processo->UTcpu = 0;
}

void incrementaUTcpu(Processo processo) {
  processo->UTcpu++;
}

void setTempoInicioEspera(Processo p, int i) {
  p->inicioEspera = i;
}

void setTempoFinalEspera(Processo p, int i) {
  p->fimEspera = i;
}

void setTempoInicioCPU(Processo p, int i) {
  p->inicioCPU = i;
}

void setTempoFinalCPU(Processo p, int i) {
    p->fimCPU = i;
}

void setInicioImpressao(Processo p, int i) {
  p->inicioImpressao = i;
}

void setTempoFinalImpressao(Processo p, int i) {
  p->fimImpressao = i;
}

void setTempoInicio(Processo p, int i) {
  p->tempoInicial = i;
}

void setTempoFinal(Processo p, int i) {
  p->tempoFinal = i;
}

void freeProcesso (Processo p) {
  free(p);
}

/* Implementação das rotinas auxiliares */

static void *mallocSafe(size_t nbytes) {
  void *p = malloc(nbytes);

  if (p == NULL) {
    printf("Erro: alocação de memória falhou no módulo Node.");
    exit(0);
  }
  return p;
}
