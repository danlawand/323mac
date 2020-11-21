#include <stdio.h>
#include "stdlib.h"

int main (int argc, char *argv[])
{
  char *filename;
  char str [80], c = 65;
  float f;
  FILE * pFile;

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
  while (fscanf (pFile, "%s", str) != -1) {
    printf ("I have read: %s \n",str);
  }
  fclose (pFile);
  for (int i = 0; i < 80; i++) {
    printf("%c", str[i]);
  }

  return 0;
}
