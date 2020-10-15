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

  Processo.h

  \__\__\__\__\__\__\__\__\__\__\__\__\__\__\__\__\__\__\__\__\__\__\__*/
typedef struct processo Processo;

struct processo {
  /*Numero do Processo*/
  int numero;

  /*Identificador da Impressora que passou, ou 0 por não ter passado por impressora*/
  int impressoraID;

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
Processo newProcesso(int, int, int, int);
