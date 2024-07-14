#include "libprg/libprg.h"
#define N 4

void iniciar_pilha (T_PILHA *pilha) {
    for (int i = 0; i < pilha->inicio; i++) {
        pilha->dados[i] = 0;
    }
    pilha->inicio = 0;
}
void inserir_pilha(int dado, T_PILHA *pilha) {
    if (pilha->inicio == N)
        printf("A pilha está cheia\n");
    else {
        pilha->dados[pilha->inicio] = dado;
        pilha->inicio++;
    }
}
int remover_pilha (T_PILHA *pilha) {
    int aux = pilha->dados[pilha->inicio-1];
    if (pilha->inicio == 0) {
        printf("A pilha está vazia\n");
        return 0;
    }
    else {
        pilha->inicio--;
    }
    return aux;
}
void imprimir_pilha(T_PILHA *pilha) {
    for (int i = pilha->inicio - 1; i >= 0; i--)
        printf("%d\n", pilha->dados[i]);
}