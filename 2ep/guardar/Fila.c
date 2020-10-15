/*\__\__\__\__\__\__\__\__\__\__\__\__\__\__\__\__\__\__\__\__\__\__\__

  AO PREENCHER ESSE CABEÇALHO COM O MEU NOME E O MEU NÚMERO USP,
  DECLARO QUE SOU O ÚNICO AUTOR E RESPONSÁVEL POR ESSE PROGRAMA.
  TODAS AS PARTES ORIGINAIS DESSE EXERCÍCIO PROGRAMA (EP) FORAM
  DESENVOLVIDAS E IMPLEMENTADAS POR MIM SEGUINDO AS INSTRUÇÕES DESSE EP
  E QUE PORTANTO NÃO CONSTITUEM PLÁGIO. DECLARO TAMBÉM QUE SOU RESPONSÁVEL
  POR TODAS AS CÓPIAS DESSE PROGRAMA E QUE EU NÃO DISTRIBUI OU FACILITEI A
  SUA DISTRIBUIÇÃO. ESTOU CIENTE QUE OS CASOS DE PLÁGIO SÃO PUNIDOS COM
  REPROVAÇÃO DIRETA NA DISCIPLINA.

  Nome: DANIEL ANGELO ESTEVES LAWAND
  NUSP: 10297693

  Fila.c

  \__\__\__\__\__\__\__\__\__\__\__\__\__\__\__\__\__\__\__\__\__\__\__*/

#include "Fila.h"
#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>
#define bool int

/* Protótipo de rotinas auxiliares */
static void *mallocSafe(size_t nbytes);

Fila filaInit(int impressoraID) {
  Fila fila = mallocSafe(sizeof(*fila));
  Processo p = newProcesso(0, 0, 0, 0);
  Link cabeca = newNode(p, NULL, NULL);
  fila->cabeca = cabeca;
  fila->cabeca->next = cabeca;
  fila->cabeca->previous = cabeca;
  fila->current = cabeca;
  fila->last = cabeca;
  fila->n = 0;
  fila->impressoraID = impressoraID;
  fila->totalLinhas = 0;
  fila->tempoDeProcesso = 0;
  fila->n_processosTerminados = 0;
  fila->sumPermanencia = 0;
  return fila;
}

void addProcessoFilaCircular(Processo p, Fila fila, int i) {
                                /*Next     previous*/
  Link novo = newNode(p, fila->cabeca, fila->cabeca->previous);
  novo->processo.inicioCPU = i;
  fila->cabeca->previous->next = novo;
  fila->cabeca->previous = novo;
  fila->n++;
  if (fila->current == fila->cabeca) {
    fila->current = fila->cabeca->next;
  }
}

void addProcessoFilaEspera(Processo p, Fila fila, int i) {
  Link no = newNode(p, NULL, fila->last);
  no->processo.inicioEspera = i;
  fila->last->next = no;
  fila->last = no;
  fila->n++;
  fila->totalLinhas += no->processo.linhas;

  /*Garantia de olhar o primeiro processos na fila */
  fila->current = fila->cabeca->next;
}

void addNodeFila(Link no, Fila fila) {

  /*Se o nó for adicionado à fila de acabados, conte o tempo de Permanência do processo*/
  if (no->processo.linhas <= 0) {
    fila->sumPermanencia += (no->processo.tempoFinal - no->processo.tempoInicial);
  }

  /*Se for impressora, identifique o processo em qual ele está*/
  if (fila->impressoraID != 0) {
    no->processo.impressoraID = fila->impressoraID;
  }

  fila->totalLinhas += no->processo.linhas;
  fila->last->next = no;
  no->next = NULL;
  no->previous = fila->last;
  fila->last = no;
  fila->n++;
  /*Garantia de olhar o primeiro processos na fila */
  fila->current = fila->cabeca->next;

}

void imprimeProcessoTermino(Processo processo) {
  double razao;
  printf("Processo Terminado Nº: %d\n", processo.numero);
  printf("Tempo de Processamento Inicial: %d\n",  processo.tempoDeProcessamentoInicial);
  printf("Linhas Iniciais: %d\n", processo.linhasIniciais);
  printf("Tempo de Chegada: %d\n", processo.tempoInicial);
  printf("Tempo Final: %d\n", processo.tempoFinal);
  printf("Tempo Total de Permanência no Sistema: %d\n", processo.tempoFinal - processo.tempoInicial);
  printf("Tempo de Permanência na Fila de Espera: %d\n", processo.fimEspera - processo.inicioEspera);
  printf("Tempo de Permanência na Fila da CPU: %d\n", processo.fimCPU - processo.inicioCPU);
  printf("Tempo de Permanência na Fila de Impressão: %d\n", processo.fimImpressao - processo.inicioImpressao);
  razao = ((double) processo.tempoDeProcessamentoInicial)/((double)(processo.tempoFinal - processo.tempoInicial));
  printf("Razão Tempo de Processamento por Tempo Total de Permanência: %f\n\n", razao);
}

void imprimeNovoProcesso(Processo processo) {
  printf("Novo Processo Nº: %d\n", processo.numero);
  printf("Tempo de Chegada: %d\n", processo.tempoInicial);
  printf("Tempo de Processamento Inicial: %d\n",  processo.tempoDeProcessamentoInicial);
  printf("Linhas Iniciais: %d\n", processo.linhasIniciais);
  printf("Tempo de Chegada no Sistema: %d\n\n", processo.tempoInicial);
}

void imprimeProcesso(Processo processo, int i) {
  int tEspera;
  int tCPU;
  int tImpressao;
  int dt = i - processo.tempoInicial;
  double razao;
  printf("Processo Nº: %d\n", processo.numero);
  printf("Tempo de Processamento Inicial: %d\n",  processo.tempoDeProcessamentoInicial);
  printf("Linhas Iniciais: %d\n", processo.linhasIniciais);
  printf("Linhas Restantes: %d\n", processo.linhas);
  printf("Tempo de Chegada: %d\n", processo.tempoInicial);
  printf("Tempo Atual: %d\n", i);
  printf("Tempo de Permanência no Sistema: %d\n", dt);

  if (processo.fimEspera > 0) {
    tEspera = processo.fimEspera - processo.inicioEspera;
  } else if (processo.inicioEspera > 0) {
    tEspera = i - processo.inicioEspera;
  } else {
    tEspera = 0;
  }
  printf("Tempo de Permanência na Fila de Espera: %d\n", tEspera);

  if (processo.fimCPU > 0) {
    tCPU = processo.fimCPU - processo.inicioCPU;
  } else if (processo.inicioCPU > 0) {
    tCPU = i - processo.inicioCPU;
  } else {
    tCPU = 0;
  }
  printf("Tempo de Permanência na Fila da CPU: %d\n", tCPU);

  if (processo.fimImpressao > 0) {
    tImpressao = processo.fimImpressao - processo.inicioImpressao;
  } else if (processo.inicioImpressao > 0) {
    tImpressao = i - processo.inicioImpressao;
  } else {
    tImpressao = 0;
  }
  printf("Tempo de Permanência na Fila de Impressão: %d\n", tImpressao);

  if (dt != 0) {
    razao = ((double) processo.tempoDeProcessamentoInicial)/((double)(dt));
  } else {
    razao = 0.00;
  }
  printf("Razão Tempo de Processamento por Tempo Total de Permanência: %f\n\n", razao);

}

void imprimeFila (Fila fila, int i) {
  Link no;
  no = fila->cabeca->next;
  while(no != fila->cabeca && no != NULL) {
    imprimeProcesso(no->processo, i);
    no = no->next;
  }
}

int filaSize(Fila fila) {
  return fila->n;
}

bool filaIsEmpty(Fila fila) {
  return fila->n == 0;
}

Link retiraNodeFilaCircular(Fila fila) {
  Link no;
  if (fila->n == 0) {
    return NULL;
  }
  no = fila->current;
  fila->current->previous->next = fila->current->next;
  fila->current->next->previous = fila->current->previous;

  /*Se o próximo for a cabeca*/
  if (fila->current->next == fila->cabeca) {
    fila->current = fila->cabeca->next;
  } else {
    fila->current = fila->current->next;
  }
  fila->n--;
  fila->n_processosTerminados++;
  return no;
}

Link retiraNodeFilaLinear(Fila fila) {
  Link no;
  if (fila->n == 0) {
    return NULL;
  }

  /*Se só tiver um nó*/
  if (fila->n == 1) {
    no = fila->current;
    fila->cabeca->next = NULL;
    fila->last = fila->cabeca;
    fila->current = fila->cabeca;
    fila->n--;
    return no;
  }
  /*Caso contrário*/
  no = fila->cabeca->next;
  fila->cabeca->next = no->next;
  fila->current->next->previous = fila->current->previous;
  fila->current = fila->cabeca->next;
  fila->n--;
  fila->n_processosTerminados++;
  return no;
}

Processo retiraProcessoEspera(Fila fila, int i) {
  Link no;
  Processo p;
  no = retiraNodeFilaLinear(fila);
  no->processo.fimEspera = i;
  p = no->processo;
  freeNode(no);
  fila->n_processosTerminados++;
  return p;
}

void proximoNode(Fila fila) {
  fila->current = fila->current->next;
}

/*Contador de Processos Terminados na Fila em questão*/
void incrementaProcessosTerminados(Fila fila) {
  fila->n_processosTerminados++;
}
int getTempoDeProcessamento(Fila fila) {
  return fila->current->processo.tempoDeProcessamento;
}

void decresceTempoDeProcessamento(Fila fila){
    fila->current->processo.tempoDeProcessamento--;
}

int getUTcpu(Fila fila) {
  return fila->current->processo.UTcpu;
}

void resetUTcpu(Fila fila) {
  fila->current->processo.UTcpu = 0;
}

void incrementaUTcpu(Fila fila) {
    fila->current->processo.UTcpu++;
}

int getLinhas(Fila fila) {
  return fila->current->processo.linhas;
}

void decresceLinhas(Fila fila) {
  if (fila->current == NULL) {return;}

  /*Altera o contador do total de linhas que a fila possui*/
  if (fila->totalLinhas < 10) {
    fila->totalLinhas = 0;
  } else {
    fila->totalLinhas -= 10;
  }

  /*Altera a quantidade de linhas do processo atual*/
  if (fila->current->processo.linhas < 10) {
    fila->current->processo.linhas = 0;
  } else {
    fila->current->processo.linhas-=10;
  }
}

int getMediaLinhas(Fila fila) {
  if (fila->n == 0) {
    return 0;
  }
  return fila->totalLinhas/fila->n;
}

void setTempoFinalEspera(Link no, int i) {
  no->processo.fimEspera = i;
}

void setTempoFinalCPU(Link no, int i) {
  no->processo.fimCPU = i;
}

void setInicioImpressao(Link no, int i) {
  no->processo.inicioImpressao = i;
}

void setTempoFinalImpressao(Link no, int i) {
  no->processo.fimImpressao = i;
}

void setTempoFinal(Link no, int i) {
  no->processo.tempoFinal = i;
}

void mediasFinais(Fila fila, double* mediaEspera, double* mediaCPU, double* mediaImpressora, double* razao) {
  Link no;
  /*Numero de processos contados*/
  int nproc = 0;
  /*Variaveis para as fila de Espera e Cpu*/
  int e = 0, c = 0;
  /*Variaveis para a impressora*/
  int i1 = 0, q1 = 0, i2 = 0, q2 = 0, i3 = 0, q3 = 0, q = 0;
  /*Variaveis para a razão*/
  int sumUT = 0, perm = 0;
  double razaoParcial = 0, mediai1, mediai2, mediai3;

  if (fila->n == 0) {
    *mediaEspera = 0;
    *mediaCPU = 0;
    *mediaImpressora = 0;
    *razao = 0;
    return;
  }
  no = fila->cabeca->next;
  while(no != NULL) {
    e += no->processo.fimEspera - no->processo.inicioEspera;
    c += no->processo.fimCPU - no->processo.inicioCPU;

    if (no->processo.impressoraID == 1) {
      i1 += no->processo.fimImpressao - no->processo.inicioImpressao;
      q1++;
    } else if (no->processo.impressoraID == 2) {
      i2 += no->processo.fimImpressao - no->processo.inicioImpressao;
      q2++;
    } else if( no->processo.impressoraID == 3) {
      i3 += no->processo.fimImpressao - no->processo.inicioImpressao;
      q3++;
    }
    nproc++;
    sumUT = no->processo.tempoDeProcessamentoInicial;
    perm = no->processo.tempoFinal - no->processo.tempoInicial;

    /*Garantia que não dará -nan*/
    if (perm != 0) {
      razaoParcial += ((double)sumUT)/((double)perm);
    }
    no = no->next;
  }
  *mediaEspera = (double)e/(double)nproc;
  *mediaCPU = (double)c/(double)nproc;

  mediai1 = 0;
  if (q1 != 0) {
    q++;
    mediai1 = (double)i1/(double)q1;
  }
  mediai2 = 0;
  if (q2 != 0) {
    q++;
    mediai2 = (double)i2/(double)q2;
  }
  mediai3 = 0;
  if (q3 != 0) {
    q++;
    mediai3 = (double)i3/(double)q3;
  }
  *mediaImpressora = (mediai1+mediai2+mediai3)/(double)q;
  *razao = razaoParcial/(double)nproc;
}

void filaFree(Fila fila) {
  Link no, q;
  if (fila->n != 0) {
    no = fila->cabeca->next;
    while(no != fila->cabeca && no != NULL) {
      q = no->next;
      freeNode(no);
      no = q;
    }
  }
  no = fila->cabeca;
  free(no);
  free(fila);
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
