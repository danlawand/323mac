#ifndef _PROCESSO_H
#define _PROCESSO_H
typedef struct processo* Processo;
struct processo {
  /*Numero do Processo*/
  int numero;

  /*Prioridade do Processo*/
  int prioridade;

  /*Posicao na Fila de espera*/
  int posicao;

  /*tempo De Processamento que resta ao processo na CPU*/
  int tempoDeProcessamento;
  /*tempo De Processamento que o processo passará na CPU*/
  int tempoDeProcessamentoInicial;

  /*Variavel que contabiliza quanto tempo o processo esta initerruptamente na CPU*/
  int UTcpu;

  /*Quantidade de linhas restantes*/
  int linhas;
  /*Quantidade de linhas iniciais*/
  int linhasIniciais;

  /*Tempo de Saída e chegada no Sistema*/
  int tempoInicial;
  int tempoFinal;

  /*Tempo de Saída e chegada na CPU*/
  int inicioCPU;
  int fimCPU;

  /*Tempo de Saída e chegada na Impressora*/
  int inicioImpressao;
  int fimImpressao;

  /*Tempo de Saída e chegada na Fila de espera*/
  int inicioEspera;
  int fimEspera;
};

/*Cria novos processos*/
Processo newProcesso(int, int, int, int, int);
void imprimeProcessoTermino(Processo);
void imprimeProcesso(Processo, int);
void imprimeNovoProcesso(Processo);

/*Retorna a prioridade do processo*/
int getPrioridade(Processo);

/*Retorna a quantidade de linhas de um processo que ainda falta imprimir*/
int getLinhas(Processo);

/*Diminui a quantidade de linhas a imprimir*/
void decresceLinhas(Processo);

/*Retorna o tempo restante de processamento*/
int getTempoDeProcessamento(Processo);

/*Diminui o Tempo de processamento*/
void decresceTempoDeProcessamento(Processo);

/*Retorna quanto tempo o processo está sendo executado initerruptamente na CPU*/
int getUTcpu(Processo);

/*Reinicia o tempo de execução dos processos que já passaram 20 UT e ainda não foram encerrados */
void resetUTcpu(Processo);

/*Tempo de execução do processo na CPU aumenta*/
void incrementaUTcpu(Processo);

/*Determina o tempo inicial do processo na fila de espera*/
void setTempoInicioEspera(Processo, int);

/*Determina o tempo final do processo na fila de espera*/
void setTempoFinalEspera(Processo, int);

/*Determina o tempo inicial do processo na fila da CPU*/
void setTempoInicioCPU(Processo, int);

/*Determina o tempo final do processo na fila da CPU*/
void setTempoFinalCPU(Processo, int);

/*Determina o tempo inicial do processo na impressora*/
void setInicioImpressao(Processo, int);

/*Determina o tempo final do processo na fila de impressao*/
void setTempoFinalImpressao(Processo, int);

/*Determina o tempo inicial do processo no Sistema*/
void setTempoInicio(Processo, int);

/*Determina o tempo final do processo no Sistema*/
void setTempoFinal(Processo, int);

void freeProcesso (Processo);

#endif
