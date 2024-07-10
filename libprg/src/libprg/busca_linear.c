#include "libprg/libprg.h"


int busca_linear (int vet[], int x) {
    for (int i = 0; i < counter; ++i) {
        if (x == vet[i]) {
            return vet[i];
        }
    }
    return 0;
}