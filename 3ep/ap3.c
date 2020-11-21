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
#include "ABB.h"
#include <string.h>

int main(int argc, char *argv[]) {
  FILE * pFile;
  long lSize, i = 0, k = 0, j = 0;
  char * buffer, *filename, **word;
  size_t result;
  int tamanho = 0, n = 0, z = 0;
  char c;

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
      while (i < lSize && ((c >= 65 && c <= 90) || (c >= 97 && c <= 122) || c == '-') ){
        if (c == '-') {
          if (i < lSize-1 && ((buffer[i+1] >= 65 && buffer[i+1] <= 90) || (buffer[i+1] >= 97 && buffer[i+1] <= 122))) {
            tamanho++;
          } else {
            tamanho++;
            i++;
            c = buffer[i];
            break;
          }
        } else {
          if (c >= 65 && c <= 90) {
            buffer[i] = (char) ((int)buffer[i] + 32);
          }
          tamanho++;
        }
        if (c >= 65 && c <= 90) {
          buffer[i] = (char) ((int)buffer[i] + 32);
        }
        tamanho++;
        i++;
        c = buffer[i];
      }
      if (tamanho > 0) {
        // if (i > 0 && buffer[i-1] == '-' && tamanho > 0) {
        //   z = 1;
        // }
        word[n] = malloc(tamanho*sizeof(char));
        for (j = i-tamanho, k = 0; j < i-z && k < tamanho; j++, k++) {
          word[n][k] = buffer[j];
        }
        // if (buffer[i-1] == '-') {
        //   printf("%s\n", word[n]);
        // }
        putABB(word[n]);
        // printf("\n");
        z = 0;
        n++;
        tamanho = 0;
      }
    } else {
      i++;
    }

  }
  printABB();
  printf("Número de palavras da ABBA %d\n", sizeABB());
  // terminate
  fclose (pFile);
  free (buffer);
  free(word);
  return 0;
}
