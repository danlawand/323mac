typedef struct stackP *Processo;

struct stackP {
  int UT;
  int UTiterativo;
  int linhas;
  int tempoInicial;
  int tempoFinal;
};
/*UT, linhas, tempoInicial*/
Processo newProcesso (int, int, int);

void diminuiLinhas(int, Processo);
int getLinhas(Processo);

void diminuiUTiterativo (int, Processo);
int getUTiterativo(Processo);
int getUT(Processo);
//
// void setTempoFinal(int);
//
// int getTempoFinal();
int getTempoInicial(Processo);
void freeProcesso(Processo);
