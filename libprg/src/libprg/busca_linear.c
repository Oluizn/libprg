#include "libprg/libprg.h"

int busca_linear (int vet[], int x, int tam) {
    for (int i = 0; i < tam; ++i)
        if (x == vet[i])
            return i;
    return 0;
}

int busca_linear_sentinela (int vet[], int x, int tam) {
    vet[tam] = x;
    int i = 1;
    while (vet[i] != x)
        i++;
    if ( i != tam)
        return i;
}