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

  Fila.h

  \__\__\__\__\__\__\__\__\__\__\__\__\__\__\__\__\__\__\__\__\__\__\__*/
#include "Node.h"
#include <stdio.h>
#define bool int

typedef struct sequenciaFila* Fila;
struct sequenciaFila {
  Link cabeca;
  Link last;
  Link current;

  /*Armazena o tamanho*/
  int n;

  /*Identifica se é impressora e qual das 3 é*/
  int impressoraID;

  /*Armazena o tempo de execução na cpu, para depois verficiar se excedeu as 20 UT na execução do processo*/
  int tempoDeProcesso;

  /*Total de Linhas que aquela fila possui (utilizado para a escolha de impressora)*/
  int totalLinhas;

  /*Numero de processos terminados naquela fila*/
  int n_processosTerminados;

  /*Somatório do tempo de Permanência no Sistema*/
  int sumPermanencia;
};

/*Construtor*/
Fila filaInit(int);

/*Adiciona Processo na Fila da CPU*/
void addProcessoFilaCircular(Processo, Fila, int);

/*Adiciona Processo na Fila de Espera*/
void addProcessoFilaEspera(Processo, Fila, int);

/*Adiciona Link na Fila de Impressao ou na fila de processos Acabados*/
void addNodeFila(Link, Fila);

/*Imprime Processos que terminam a execução*/
void imprimeProcessoTermino(Processo);

/*Imprime um novo processo*/
void imprimeNovoProcesso(Processo);

/*Imprime o processo em determinado UT*/
void imprimeProcesso(Processo, int);

/*Imprime a fila em determinado UT*/
void imprimeFila(Fila, int);

/*Retorna o tamanho da Fila*/
int filaSize(Fila);

/*Devolve true se a fila está vazia*/
bool filaIsEmpty(Fila);

/*Retira processo da fila da CPU*/
Link retiraNodeFilaCircular(Fila);

/*Retira Link da fila de Impressao*/
Link retiraNodeFilaLinear(Fila);

/*Retira Processo da fila de espera*/
Processo retiraProcessoEspera(Fila, int);

/*CURRENT aponta para o próximo Node*/
void proximoNode(Fila);

/*Contador de Processos Terminados na Fila em questão*/
void incrementaProcessosTerminados(Fila); 

/*Retorna o tempo restante de processamento*/
int getTempoDeProcessamento(Fila);

/*Diminui o Tempo de processamento*/
void decresceTempoDeProcessamento(Fila);

/*Retorna quanto tempo o processo está sendo executado initerruptamente na CPU*/
int getUTcpu(Fila);

/*Reinicia o tempo de execução dos processos que já passaram 20 UT e ainda não foram encerrados */
void resetUTcpu(Fila);

/*Tempo de execução do processo na CPU aumenta*/
void incrementaUTcpu(Fila);

/*Retorna a quantidade de linhas de um processo que ainda falta imprimir*/
int getLinhas(Fila);

/*Diminui a quantidade de linhas a imprimir*/
void decresceLinhas(Fila);

/*Funcao que retorna a média de linhas a serem executadas por processo*/
int getMediaLinhas(Fila);

/*Determina o tempo inicial do processo na impressora*/
void setInicioImpressao(Link, int);

/*Determina o tempo final do processo na fila de espera*/
void setTempoFinalEspera(Link, int);

/*Determina o tempo final do processo na fila da CPU*/
void setTempoFinalCPU(Link, int);

/*Determina o tempo final do processo na fila de impressao*/
void setTempoFinalImpressao(Link, int);

/*Determina o tempo final do processo no Sistema*/
void setTempoFinal(Link, int);

/*Funcao que calcula a razao media e os tempos medios de Permanência em cada fila*/
void mediasFinais(Fila, double*, double*, double*, double*);

/*Destrutor*/
void filaFree();
