#include "time.h"
#include "stdio.h"
#include "stdlib.h"
#include <string.h>
#include "lazy.h"
//
// static char* buffer;
//
// void insereNaED(long lSize) {
//   long i = 1, k = 0, j = 0;
//   char **word, c;
//   int tamanho = 0, n = 0;
//   word = malloc(lSize*sizeof(char *));
//   while (i < lSize) {
//     c = buffer[i];
//     if (i < lSize && ((c >= 65 && c <= 90) || (c >= 97 && c <= 122))) {
//       while (i < lSize && ((c >= 65 && c <= 90) || (c >= 97 && c <= 122)) ){
//         if (c >= 'A' && c <= 'Z') {
//           buffer[i] = (char) ((int)buffer[i] + 32);
//         }
//         tamanho++;
//         i++;
//         c = buffer[i];
//       }
//       if (tamanho > 0) {
//         word[n] = malloc((tamanho)*sizeof(char));
//         word[n][tamanho] = '\0';
//         for (j = i-tamanho, k = 0; j < i && k < tamanho; j++, k++) {
//           word[n][k] = buffer[j];
//         }
//         putLP(word[n], 0);
//         n++;
//         tamanho = 0;
//       }
//     } else {
//       i++;
//     }
//   }
//   free(word);
// }


int main(int argc, char *argv[]) {
  // FILE * pFile;
  // long lSize;
  char mensagem[10];
  // size_t result;
  // clock_t ini, fim;
  // double total = 0;
  char continua, io;
  int i =0;
  for (i = 0; i < 10; i++)
    mensagem[i] = '\0';

  // if (argc < 2) {
  //   printf("Número inválido de argumentos\n");
  //   exit(1);
  // }
  //
  // filename = argv[1];
  // pFile = fopen ( filename , "r" );
  // if (pFile == NULL) {
  //   fputs ("File error",stderr);
  //   exit (1);
  // }

  /* obtain file size:*/
  // fseek (pFile , 0 , SEEK_END);
  // lSize = ftell (pFile);
  // rewind (pFile);
  //
  // /* allocate memory to contain the whole file:*/
  // buffer = (char*) malloc (sizeof(char)*lSize);
  // if (buffer == NULL) {fputs ("Memory error",stderr); exit (2);}
  //
  // /* copy the file into the buffer:*/
  // result = fread (buffer,1,lSize,pFile);
  // if (result != lSize) {fputs ("Reading error",stderr); exit (3);}
  // /* the whole file is now loaded in the memory buffer. */

  LinearProbingHashSTInit(1);

  // ini = clock();
  // insereNaED(lSize); /*Linear Probing*/
  // fim = clock();
  // total = (double)(fim - ini) / CLOCKS_PER_SEC;
  // printf("N. de palavras no Hash com Linear Probing %d -- %f segundos\n", sizeLP(), total);
  char *palavra;

  printf("Vamos iniciar?\n");
  scanf(" %c", &io);
  while (io != '0') {
    printf("N palavras antes %d\n", sizeLP());
    printf("(1)nsere ou rem(o)ve?\n");
    scanf(" %c", &io);
    if (io == '1') {
      printf("Qual palavra inserir?\n");
      scanf(" %s", mensagem);
      for (i = 0; mensagem[i] != '\0'; i++);
      palavra = malloc((i+1)*sizeof(char));
      for (i = 0; mensagem[i] != '\0'; i++) palavra[i] = mensagem[i];
      palavra[i] = '\0';
      putLP(palavra, 1);
    } else if (io == 'r'){
      printf("Qual palavra remover?\n");
      scanf(" %s", mensagem);
      lazy_delete(mensagem);
    }
    printf("\n");
    printLP();
    // for (int i = 0; i < 10; i++)
    //   mensagem[i] = '\0';

    printf("N palavras depois %d\n", sizeLP());
    printf("N defuntos %d\n", sizeDefuntos());
    printf("Capacidade %d\n", capa());
  }

  // fclose (pFile);
  // free (buffer);
  return 0;
}
