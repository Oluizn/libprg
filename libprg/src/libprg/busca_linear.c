#include "libprg/libprg.h"

int busca_linear (int vet[], int x, int tam) {
    for (int i = 0; i < tam; ++i)
        if (x == vet[i])
            return vet[i];
    return 0;
}