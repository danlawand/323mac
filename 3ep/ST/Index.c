#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include "queue.h"
#include "st.h"

#define MaxWordLength 50

void *mallocSafe(size_t);
char **resize(char **, int, int *);
void freeWords(char **, int);

int main(int argc, char *argv[]) {
  int minLength, minOccurrence, n = 0, cap;
  char **words, s[MaxWordLength], *r, *filename;
  Queue q;
  FILE * pFile;

  if (argc <= 1) {
    printf("Digite Index <filename> <minLength> <minOccurrence>.\n");
    exit(0);
  }

  filename = argv[1];
  pFile = fopen ( filename , "r" );
  if (pFile == NULL) {
    fputs ("File error",stderr);
    exit (1);
  }

  minLength     = atoi(argv[2]);
  minOccurrence = atoi(argv[3]);

  words = mallocSafe(sizeof(char *));
  cap = 1;

  stInit();
  while (fscanf(pFile,"%s",s) != EOF) {
    /*  while (scanf("%s", s) == 1) {
      if (s[0] == "0") break;
    */
    if (n == cap) words = resize(words, n, &cap);
    words[n] = mallocSafe((strlen(s)+1)*sizeof(char));
    strcpy(words[n], s);
    if (strlen(s) < minLength) continue;
    if (!stContains(s)) {
      stPut(words[n], queueInit());
    }
    q = stGet(words[n]);
    queuePut(q, n);
    n++;
  }

  stStartIterator();
  while (stHasNext()) {
    r = stNext();
    q = stGet(r);
    if (queueSize(q) >= minOccurrence) {
      printf("%s : ", r);
      queueDump(q);
    }
  }
  fclose (pFile);
  stFree();
  freeWords(words, n);
  return 0;
}

void *mallocSafe(size_t nbytes) {
  void *p = malloc(nbytes);

  if (p == NULL) {
    printf("Erro: alocação de memória falhou no módulo stack.");
    exit(0);
  }
  return p;
}

char **resize(char **words, int n, int *cap) {
  int i;
  char **new;

  *cap = 2*(*cap);
  new = mallocSafe((*cap)*sizeof(char *));

  for (i = 0; i < n; i++)
    new[i] = words[i];
  free(words);
  return new;
}

void freeWords(char **words, int n) {
  int i;
  for (i = 0; i < n; i++)
    free(words[i]);
  free(words);
}
