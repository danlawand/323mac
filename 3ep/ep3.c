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

  ep3.c

\__\__\__\__\__\__\__\__\__\__\__\__\__\__\__\__\__\__\__\__\__\__\__*/

#include "time.h"
#include "stdio.h"
#include "stdlib.h"
#include <string.h>
#include "ABB.h"
#include "ARN.h"
#include "HASH.h"
#include "MTF.h"
#include "LP.h"

int main(int argc, char *argv[]) {
  FILE * pFile;
  long lSize, i = 0, k = 0, j = 0;
  char * buffer, *filename, **word;
  size_t result;
  int tamanho = 0, n = 0;
  char c;
  SeparateChainingHashSTInit(1);
  MTFInit(1);
  LinearProbingHashSTInit(1);

  if (argc < 2) {
    printf("Número inválido de argumentos\n");
    exit(1);
  }

  filename = argv[1];
  pFile = fopen ( filename , "r" );
  if (pFile == NULL) {
    fputs ("File error",stderr);
    exit (1);
  }

  // obtain file size:
  fseek (pFile , 0 , SEEK_END);
  lSize = ftell (pFile);
  rewind (pFile);

  // allocate memory to contain the whole file:
  buffer = (char*) malloc (sizeof(char)*lSize);
  word = malloc(lSize*sizeof(char *));
  if (buffer == NULL) {fputs ("Memory error",stderr); exit (2);}

  // copy the file into the buffer:
  result = fread (buffer,1,lSize,pFile);
  if (result != lSize) {fputs ("Reading error",stderr); exit (3);}

  /* the whole file is now loaded in the memory buffer. */
  while (i < lSize) {
    c = buffer[i];
    if (i < lSize && ((c >= 65 && c <= 90) || (c >= 97 && c <= 122))) {
      while (i < lSize && ((c >= 65 && c <= 90) || (c >= 97 && c <= 122)) ){
        if (c >= 'A' && c <= 'Z') {
          buffer[i] = (char) ((int)buffer[i] + 32);
        }
        tamanho++;
        i++;
        c = buffer[i];
      }
      if (tamanho > 0) {
        word[n] = malloc((tamanho)*sizeof(char));
        word[n][tamanho] = '\0';
        for (j = i-tamanho, k = 0; j < i && k < tamanho; j++, k++) {
          word[n][k] = buffer[j];
        }
        // putLP(word[n]);
        // putST(word[n]);
        // putMTF(word[n]);
        // putABB(word[n]);
        // putARN(word[n]);
        n++;
        tamanho = 0;
      }
    } else {
      i++;
    }

  }
  // printARN();
  // printABB();
  printf("Número de palavras na ARN %d\n", sizeARN());
  printf("Número de palavras na ABB %d\n", sizeABB());
  printf("Número de palavras no Hash com Encadeamento %d\n", sizeHASH());
  printf("Número de palavras no Hash com MTF %d\n", sizeMTF());
  printf("Número de palavras no Hash com Linear Probing %d\n", sizeLP());

  // terminate
  fclose (pFile);
  free (buffer);
  free(word);
  return 0;
}
