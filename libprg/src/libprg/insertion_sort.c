#include "libprg/libprg.h"

int* insertion_sort(int* vet, int tamanho){
    int chave, j;
    for (int i = 0; i < tamanho; ++i) {
        chave = vet[i];
        j = i - 1;
        while (j>= 0 && vet[j] > chave) {
            vet[j+1] = vet[j];
            j=j-1;
            }
        vet[j+1] = chave;
        }
    return vet;
}