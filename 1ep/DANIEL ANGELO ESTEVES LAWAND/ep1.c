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

  ep1.c

  \__\__\__\__\__\__\__\__\__\__\__\__\__\__\__\__\__\__\__\__\__\__\__*/

#include <stdio.h>
#include <stdlib.h>
#include "Fila.h"

/*Análise e escolha da impressora mais vazia para a inserção do processo*/
Fila escolheImpressora(Fila impressora1, Fila impressora2, Fila impressora3) {
  int tam1, tam2, tam3;
  tam1 = getMediaLinhas(impressora1);
  tam2 = getMediaLinhas(impressora2);
  tam3 = getMediaLinhas(impressora3);

  if (tam1 <= tam2 && tam1 <= tam3) {
    return impressora1;
  } else if (tam2 <= tam1 && tam2 <= tam3) {
    return impressora2;
  } else {
    return impressora3;
  }
}

int main(int argc, char *argv[]) {
  Fila cpu = filaInit(0);
  Fila espera = filaInit(0);
  Fila acabados = filaInit(0);
  Fila impressora1 = filaInit(1);
  Fila impressora2 = filaInit(2);
  Fila impressora3 = filaInit(3);
  int seed = 7;
  int tempoSimulacao;
  int novoProcesso, procID = 1;
  int tempoDeProcessamento, lines, tempoInicial;
  double mediaImpressora, mediaCPU, mediaEspera,razaoFinal;
  char tipoSaida;
  Processo p;
  Link no;
  int i = 0;
  srand(seed);

  printf("Digite o tempo de Simulação: ");
  /*%c e &tipoSaida são para não dar erro ao toque do "Enter" */
  scanf("%d%c", &tempoSimulacao, &tipoSaida);

  printf("Saída (c)ompleta ou (s)implificada? ");
  scanf("%c", &tipoSaida);

  while (tempoSimulacao > i) {

/*********Lidando com a impressora***************************/
    /***** IMPRESSORA 1**************************************/
    if (filaIsEmpty(impressora1) == 0) {
      /*****FIM DAS LINHAS*************************************/
      if(getLinhas(impressora1) <= 0) {
        /*Remove processo da impressora*/
        no = retiraNodeFilaLinear(impressora1);
        /*Determina o tempo final de execução no sistema e na fila de impressao*/
        setTempoFinalImpressao(no, i);
        setTempoFinal(no, i);
        /*Imprime os dados do processo terminado*/
        imprimeProcessoTermino(no->processo);
        /*Envia processo para a lista de acabados*/
        addNodeFila(no, acabados);
        /*Contador de Processos Terminados na Fila em questão*/
        incrementaProcessosTerminados(impressora1); 
      }
      decresceLinhas(impressora1);
    }
    /***** IMPRESSORA 2**************************************/
    if (filaIsEmpty(impressora2) == 0) {

      /*****FIM DAS LINHAS*************************************/
      if(getLinhas(impressora2) <= 0) {
        /*Remove processo da impressora*/
        no = retiraNodeFilaLinear(impressora2);
        /*Determina o tempo final de execução no sistema e na fila de impressao*/
        setTempoFinalImpressao(no, i);
        setTempoFinal(no, i);
        /*Imprime os dados do processo terminado*/
        imprimeProcessoTermino(no->processo);
        /*Envia processo para a lista de acabados*/
        addNodeFila(no, acabados);
        /*Contador de Processos Terminados na Fila em questão*/
        incrementaProcessosTerminados(impressora2);
      }
      decresceLinhas(impressora2);
    }
    /***** IMPRESSORA 3**************************************/
    if (filaIsEmpty(impressora3) == 0) {

      /*****FIM DAS LINHAS*************************************/
      if(getLinhas(impressora3) <= 0) {
        /*Remove processo da impressora*/
        no = retiraNodeFilaLinear(impressora3);
        /*Determina o tempo final de execução no sistema e na fila de impressao*/
        setTempoFinalImpressao(no, i);
        setTempoFinal(no, i);
        /*Imprime os dados do processo terminado*/
        imprimeProcessoTermino(no->processo);
        /*Envia processo para a lista de acabados*/
        addNodeFila(no, acabados);
        /*Contador de Processos Terminados na Fila em questão*/
        incrementaProcessosTerminados(impressora3);
      }
      decresceLinhas(impressora3);
    }

/*********Lidando com a CPU*********************************/
    if (filaIsEmpty(cpu) == 0) {

    /************* FIM DO tempoDeProcessamento *********************************/
      if (getTempoDeProcessamento(cpu) == 0){

        /*Verifica se há linhas para imprimir*/
        if (getLinhas(cpu) > 0) {
          /*Remove processo da cpu*/
          no = retiraNodeFilaCircular(cpu);
          /*Determina o tempo final de execução na fila da cpu*/
          setTempoFinalCPU(no, i);
          /*Determina tempo inicial de execução na fila de impressao*/
          setInicioImpressao(no, i);
          /*Envia processo para a lista de Impressão*/
          /*Decisão de qual impressora*/
          addNodeFila(no, escolheImpressora(impressora1, impressora2, impressora3));
        } else {
          /*Remove processo da cpu*/
          no = retiraNodeFilaCircular(cpu);
          /*Determina o tempo final de execução no sistema e na fila da cpu*/
          setTempoFinalCPU(no, i);
          setTempoFinal(no, i);
          /*Imprime os dados do processo terminado*/
          imprimeProcessoTermino(no->processo);
          /*Envia processo para a lista de acabados*/
          addNodeFila(no, acabados);
        }
        /*Contador de Processos Terminados na Fila em questão*/
        incrementaProcessosTerminados(cpu);
      }
      /************* FIM DOS 20 *********************************/
      else if (getUTcpu(cpu) == 20) {
        /*Próximo da fila*/
        resetUTcpu(cpu);
        proximoNode(cpu);
      }
      /*Tempo de execução do processo na cpu*/
      incrementaUTcpu(cpu);
      /*Tempo de processamento*/
      decresceTempoDeProcessamento(cpu);
    }

/**************** Lidando com Fila de Espera******************/
    if (filaSize(cpu) < 10 && filaSize(espera) > 0) {
      /*Contador de Processos Terminados na Fila em questão*/
      incrementaProcessosTerminados(espera);
      /*Retira processo da fila de espera*/
      p = retiraProcessoEspera(espera, i);
      /*Envia para CPU*/
      addProcessoFilaCircular(p, cpu, i);

    }
/******Novo Processo***********************************/
    novoProcesso = (rand() % 100);
    if (novoProcesso <= 6) {
      tempoDeProcessamento = (rand() % 59) + 1;
      lines = (rand() % 500);
      tempoInicial = i;
      p = newProcesso(tempoDeProcessamento, lines, tempoInicial, procID);
      procID++;
      if (filaSize(cpu) < 10) {
        addProcessoFilaCircular(p, cpu, i);
        imprimeNovoProcesso(p);
      } else {
        addProcessoFilaEspera(p, espera, i);
        imprimeNovoProcesso(p);
      }
    }

    /*Impressão das Filas*/
    if (tipoSaida == 'c') {
      /*Imprime filas*/
      printf("\n\nFila De Espera\n");
      printf("Tamanho da Fila de Espera: %d\n\n", filaSize(espera));
      imprimeFila(espera, i);
      printf("\n\nFila da CPU\n");
      printf("Tamanho da Fila da CPU: %d\n\n", filaSize(cpu));
      imprimeFila(cpu, i);
      printf("\n\nFila da Impressora 1\n");
      printf("Tamanho da Fila da Impressora 1: %d\n\n", filaSize(impressora1));
      imprimeFila(impressora1, i);
      printf("\n\nFila da Impressora 2\n");
      printf("Tamanho da Fila da Impressora 2: %d\n\n", filaSize(impressora2));
      imprimeFila(impressora2, i);
      printf("\n\nFila da Impressora 3\n");
      printf("Tamanho da Fila da Impressora 3: %d\n\n", filaSize(impressora3));
      imprimeFila(impressora3, i);
    }
    i++;
  }
  printf("Total de Processos Executados: %d\n", filaSize(acabados));
  printf("Tempo Médio de Permanência no Sistema por Processo: %.2f\n", (double)(acabados->sumPermanencia/(double)filaSize(acabados)));
  /*Funcao que calcula a razao media e os tempos medios de Permanência em cada fila*/
  mediasFinais(acabados, &mediaEspera, &mediaCPU, &mediaImpressora, &razaoFinal);
  printf("Tempo Médio de Permanência na Fila de Espera: %.2f\n", mediaEspera);
  printf("Tempo Médio de Permanência na Fila da CPU: %.2f\n", mediaCPU);
  printf("Tempo Médio de Permanência nas Filas de Impressão: %.2f\n",mediaImpressora);
  printf("Média da Razão do Tempo de Processamento pelo Tempo de Permanência dos Processos Executados: %f\n", razaoFinal);

  filaFree(cpu);
  filaFree(espera);
  filaFree(impressora1);
  filaFree(impressora2);
  filaFree(impressora3);
  filaFree(acabados);
  return 0;
}
