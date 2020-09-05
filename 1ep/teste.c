#include <stdio.h>
#include <stdlib.h>
#include "Processo.h"

int main(int argc, char *argv[]) {
    int ut = 100, line = 15, ti = 2;
    Processo p = newProcesso(ut, line, ti);
    printf("%d\n", p->linhas);
    diminuiLinhas(5, p);
    printf("%d\n", getLinhas(p));

    printf("\n%d\n", getUTiterativo(p));
    diminuiUTiterativo(10, p);
    printf("%d\n", getUTiterativo(p));

    return 0;
}
