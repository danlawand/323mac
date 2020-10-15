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

  Processo.c

  \__\__\__\__\__\__\__\__\__\__\__\__\__\__\__\__\__\__\__\__\__\__\__*/
#include "Processo.h"
#include <stdlib.h>

Processo newProcesso (int tempoDeProcessamento, int linhas, int tempoInicial, int procID) {
  Processo p;
  p.tempoDeProcessamento = tempoDeProcessamento;
  p.tempoDeProcessamentoInicial = tempoDeProcessamento;
  p.linhas = linhas;
  p.linhasIniciais = linhas;
  p.tempoInicial = tempoInicial;
  p.UTcpu = 0;
  p.numero = procID;
  p.inicioCPU = 0;
  p.fimCPU = 0;
  p.inicioImpressao = 0;
  p.fimImpressao = 0;
  p.inicioEspera = 0;
  p.fimEspera = 0;
  p.impressoraID = 0;
  return p;
}
