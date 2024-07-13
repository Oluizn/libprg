#include "libprg/libprg.h"

int busca_binario (int vet[], int tam, int x) {
    int inicio = 1;
    int fim = tam;

    while (inicio <= fim) {
        int meio = inicio + ((fim - inicio)/2);
        if (vet[meio] == x)
            return meio;
        else if(vet[meio] < x)
            inicio = meio + 1;
        else
            fim = meio - 1;
    }
    return -1;
}

int busca_binaria_recursiva (int vet[], int inicio, int fim, int x) {
    if (inicio <= fim) {
        int meio = inicio + ((fim - inicio)/2);
        if (vet[meio] == x)
            return meio;
        if (vet[meio] > x)
            return busca_binaria_recursiva(vet, inicio, meio-1, x);
        return busca_binaria_recursiva(vet, meio+1, fim, x);
    }
    return -1;
}