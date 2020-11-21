#include <stdio.h>
#include <stdlib.h>
#include "ABB.h"

int main(int argc, char *argv[]) {
  FILE * pFile;
  long lSize, i = 0, k = 0, j = 0;
  char * buffer, *filename, **word;
  size_t result;
  int tamanho = 0, n = 0;
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
      while (i < lSize && ((c >= 65 && c <= 90) || (c >= 97 && c <= 122)) ){
        if (c >= 65 && c <= 90) {
          buffer[i] = (char) ((int)buffer[i] + 32);
        }
        printf("%c", buffer[i]);
        i++;
        tamanho++;
        c = buffer[i];
      }
      if (tamanho > 0) {
        word[n] = malloc(tamanho*sizeof(char));
        for (j = i-tamanho, k = 0; j < i && k < tamanho; j++, k++) {
          word[n][k] = buffer[j];
        }
        putABB(word[n]);
        printf("\n");
        n++;
        tamanho = 0;
      }
    } else {
      i++;
    }

  }

  // terminate
  fclose (pFile);
  free (buffer);
  return 0;
}
