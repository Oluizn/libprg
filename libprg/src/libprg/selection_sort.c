#include "libprg/sort.h"

int* selection_sort(int *vet, int tam) {
    int i, min;
    for (i = 0; i < tam; i++) {
        min = i;
        for (int j = i + 1; j < tam; j++) {
            if (vet[j] < vet[min])
                min = j;
        }
    }
    if (i != min) {
        int aux = vet[i];
        vet[i] = vet[min];
        vet[min] = aux;
    }
    return vet;
}