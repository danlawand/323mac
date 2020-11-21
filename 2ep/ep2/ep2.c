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

  ep2.c

  \__\__\__\__\__\__\__\__\__\__\__\__\__\__\__\__\__\__\__\__\__\__\__*/

#include <stdio.h>
#include <stdlib.h>
#include "MaxPQ.h"
#include "Cpu.h"
#include "Espera.h"
#include "Impressora.h"
#include "Acabados.h"

CPU cpu;
Espera espera;
Acabados acabados;
Impressora impressora;

void lidandoImpressora(int i) {
  Processo p;
  /***PRIMEIRO PONTEIRO***/
  if (!primeiroVazio(impressora)) {
    /*****FIM DAS LINHAS*************************************/
    if(getLinhas(primeiroImpressora(impressora)) <= 0) {
      setTempoFinalImpressao(primeiroImpressora(impressora), i);
      setTempoFinal(primeiroImpressora(impressora), i);
      imprimeProcessoTermino(primeiroImpressora(impressora));
      p = retiraPrimeiroProcessoImpressora(impressora);
      addProcessoAcabados(p, acabados);
      /*Contador de Processos Terminados na Fila em questão*/
      incrementaProcessosTerminadosImpressora(impressora);
      somatorioTempoPermanenciaImpressora(impressora, p);
    }
    if (!primeiroVazio(impressora)) {
      decresceLinhas(primeiroImpressora(impressora));
    }
  }

  /***SEGUNDO PONTEIRO***/
  if (!segundoVazio(impressora)) {
    /*****FIM DAS LINHAS*************************************/
    if(getLinhas(segundoImpressora(impressora)) <= 0) {
      setTempoFinalImpressao(segundoImpressora(impressora), i);
      setTempoFinal(segundoImpressora(impressora), i);
      imprimeProcessoTermino(segundoImpressora(impressora));
      p = retiraSegundoProcessoImpressora(impressora);
      addProcessoAcabados(p, acabados);
      /*Contador de Processos Terminados na Fila em questão*/
      incrementaProcessosTerminadosImpressora(impressora);
      somatorioTempoPermanenciaImpressora(impressora, p);
    }
    if (!segundoVazio(impressora)) {
      decresceLinhas(segundoImpressora(impressora));
    }
  }

  /***TERCEIRO PONTEIRO***/
  if (!terceiroVazio(impressora)) {
    /*****FIM DAS LINHAS*************************************/
    if(getLinhas(terceiroImpressora(impressora)) <= 0) {
      setTempoFinalImpressao(terceiroImpressora(impressora), i);
      setTempoFinal(terceiroImpressora(impressora), i);
      imprimeProcessoTermino(terceiroImpressora(impressora));
      p = retiraTerceiroProcessoImpressora(impressora);
      addProcessoAcabados(p, acabados);
      /*Contador de Processos Terminados na Fila em questão*/
      incrementaProcessosTerminadosImpressora(impressora);
      somatorioTempoPermanenciaImpressora(impressora, p);
    }
    if (!terceiroVazio(impressora)) {
      decresceLinhas(terceiroImpressora(impressora));
    }
  }
}

void lidandoCPU(int i) {
  Processo p;
/************* FIM DO tempoDeProcessamento *********************************/
  if (getTempoDeProcessamento(processoAtualCPU(cpu)) == 0){
    /*Verifica se há linhas para imprimir*/
    if (getLinhas(processoAtualCPU(cpu)) > 0) {
      setTempoFinalCPU(processoAtualCPU(cpu), i);
      setInicioImpressao(processoAtualCPU(cpu), i);
      p = retiraProcessoCPU(cpu);
      somatorioTempoPermanenciaCPU(cpu, p);
      addProcessoImpressora(p, impressora);
    } else {
      setTempoFinalCPU(processoAtualCPU(cpu), i);
      setTempoFinal(processoAtualCPU(cpu), i);
      setInicioImpressao(processoAtualCPU(cpu), i);
      p = retiraProcessoCPU(cpu);
      somatorioTempoPermanenciaCPU(cpu, p);
      imprimeProcessoTermino(p);
      addProcessoAcabados(p, acabados);
    }
    /*Contador de Processos Terminados na Fila em questão*/
    incrementaProcessosTerminadosCPU(cpu);
  }
  /************* FIM DOS 20 *********************************/
  else if (getUTcpu(processoAtualCPU(cpu)) == 20) {
    resetUTcpu(processoAtualCPU(cpu));
    fim20UT(cpu);
  }
  if (!CPUIsEmpty(cpu)) {
    /*Tempo de execução do processo na cpu*/
    incrementaUTcpu(processoAtualCPU(cpu));
    /*Tempo de processamento*/
    decresceTempoDeProcessamento(processoAtualCPU(cpu));
  }
}

void lidandoEspera(int i, int* alterna) {
  Processo p;
  if (CPUSize(cpu) < 10 && EsperaSize(espera) > 0) {
    /*Alternar entre maior tempo de espera e maior prioridade*/
    p = retiraProcessoEspera(espera, *alterna);
    *alterna = *alterna + 1;
    incrementaProcessosTerminadosEspera(espera);
    setTempoFinalEspera(p, i);
    somatorioTempoPermanenciaEspera(espera, p);
    /*Envia para CPU*/
    setTempoInicioCPU(p, i);
    addProcessoCPU(p, cpu);
  }
}


int main(int argc, char *argv[]) {
  int seed;
  int tempoSimulacao;
  int novoProcesso, procID;
  int tempoDeProcessamento, lines, tempoInicial, prioridade;
  int alterna;
  char tipoSaida;
  Processo p;
  int k, i;
  cpu = CPUInit();
  espera = EsperaInit();
  acabados = acabadosInit();
  impressora = impressoraInit();

  procID = 1;
  alterna = 0;
  i = 0;
  seed = 7;
  srand(seed);


  printf("Digite o tempo de Simulação: ");
  scanf("%d", &tempoSimulacao);
  printf("Saída (c)ompleta ou (s)implificada? ");
  scanf(" %c", &tipoSaida);

  while (tempoSimulacao > i) {

/*********Lidando com a impressora***************************/
    if (!impressoraIsEmpty(impressora)) {
      lidandoImpressora(i);
    }
/*********Lidando com a CPU*********************************/
    if (CPUIsEmpty(cpu) == 0) {
      lidandoCPU(i);
    }
/**************** Lidando com Fila de Espera******************/
    lidandoEspera(i, &alterna);

/******Novo Processo***********************************/
    novoProcesso = (rand() % 100);
    if (novoProcesso <= 5) {
      tempoDeProcessamento = (rand() % 60 + 1);
      lines = (rand() % 501);
      prioridade = (rand() % 10);
      tempoInicial = i;
      p = newProcesso(tempoDeProcessamento, lines, tempoInicial, procID, prioridade);
      procID++;
      setTempoInicio(p, i);
      if (CPUSize(cpu) < 10) {
        setTempoInicioCPU(p, i);
        addProcessoCPU(p, cpu);
      } else {
        setTempoInicioEspera(p, i);
        addProcessoEspera(p, espera);
      }
      imprimeNovoProcesso(p);
    }

    /*Impressão das Filas*/
    if (tipoSaida == 'c') {
      /*Imprime filas*/
      printf("\n\nFila De Espera\n");
      printf("Tamanho da Fila de Espera: %d\n\n", EsperaSize(espera));
      imprimeEspera(espera, i);
      printf("\n\nFila da CPU\n");
      printf("Tamanho da Fila da CPU: %d\n\n", CPUSize(cpu));
      imprimeCPU(cpu, i);
      printf("\n\nFila da Impressora\n");
      printf("Tamanho da Fila da Impressora 1: %d\n\n", impressoraSize(impressora));
      imprimeImpressora(impressora, i);
    }
    i++;
  }
  printf("Total de Processos Gerados: %d\n", procID-1);
  printf("Total de Processos Concluídos: %d\n", acabadosSize(acabados));
  printf("Número de Processos remanescentes na Fila de Espera: %d\n", EsperaSize(espera));
  printf("Número de Processos remanescentes na CPU: %d\n", CPUSize(cpu));
  printf("Número de Processos remanescentes na Fila de Impressão: %d\n", impressoraSize(impressora));
  printf("Tempo Médio de Permanência na Fila de Espera: %.2f\n", mediaTempoPermanenciaEspera(espera));
  printf("Tempo Médio de Permanência na Fila da CPU: %.2f\n", mediaTempoPermanenciaCPU(cpu));
  printf("Tempo Médio de Permanência nas Filas de Impressão: %.2f\n",mediaTempoPermanenciaImpressora(impressora));
  printf("Tempo Médio de Permanência no Sistema: %f\n", mediaTempoPermanenciaAcabados(acabados));
  printf("Média da Razão do Tempo de Processamento pelo Tempo de Permanência dos Processos Concluídos: %f\n", mediaRazao(acabados));
  for (k = 0; k < 10; k++) {
    printf("Número de Processos que Restaram na Fila de Espera com Prioridade %d: %d\n", k, sizePrioridade(espera, k));
  }
  for (k = 0; k < 10; k++) {
    printf("Tempo Médio de Permanência na Fila de Espera de Processos de Prioridade %d: %f\n", k, mediaPrioridadesEspera(espera, k));
  }
  for (k = 0; k < 10; k++) {
    printf("Tempo Médio de Permanência no Sistema de Processos de Prioridade %d: %f\n", k, mediaPrioridadesAcabados(acabados, k));
  }
  CPUFree(cpu);
  EsperaFree(espera);
  impressaoFree(impressora);
  acabadosFree(acabados);
  return 0;
}
