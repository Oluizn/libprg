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