#include "stdlib.h"
#include "libprg/libprg.h"
#define N 3

void iniciar_fila(T_FILA* fila, int dado) {
    for (int i = 0; i < N; i++) {
        fila->dados[i] = 0;
    }
    fila->fim = 0;
}
void inserir_elementos(int dado, T_FILA *fila) {
    if (fila->fim == N) {
        printf("Fila está cheia \n");
        return;
    }
    else {
        fila->dados[fila->fim] = dado;
        fila->fim++;
    }
}

int remover_elemento(int dado, T_FILA *fila) {
    int aux = fila->dados[0];
    if (fila->fim == 0) {
        printf("A fila está vazia\n");
        return 0;
    }
    else {
        for (int i = 0; i < fila->fim - 1; i++)
            fila->dados[i] = fila->dados[i+1];
        fila->fim--;
        fila->fim == 0;
        return aux;
    }
}