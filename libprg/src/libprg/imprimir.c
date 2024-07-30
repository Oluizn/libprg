#include "libprg/sort.h"
#include "stdio.h"

void imprimir_sort(int *vet, int tam){
    int i = 0;
    while (i < tam) {
        printf("%d\t", vet[i]);
        i++;
    }
}