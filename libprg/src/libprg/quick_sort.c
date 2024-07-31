#include "libprg/sort.h"
#include "stdio.h"

int particiona (int *vet, int inicio, int fim) {
    int pivo = vet[fim];
    int i = inicio - 1;
    for (int j = inicio; j < fim -1; j++) {
        if (vet[j] <= pivo) {
            i = i+1;
        }
    }
    i = i + 1;
    return i;
}
int* quick_sort (int *vet, int inicio, int fim) {
    if (inicio < fim) {
        int p
    }
}