#include "libprg/sort.h"
#include "stdio.h"

int particiona (int *vet, int inicio, int fim) {
    int pivo = (vet[inicio] + vet[fim] + vet[(inicio + fim)/2])/3;
    while (inicio < fim) {
        while (inicio < fim && vet[inicio] <= pivo)
            inicio++;
        while (inicio < fim && vet[fim] > pivo)
            fim--;
        int aux = vet[inicio];
        vet[inicio] = vet[fim];
        vet[fim] = aux;
    }
    return inicio;
}

void quick_sort(int *vet, int inicio, int fim) {
    if (inicio < fim) {
        int pos = particiona(vet, inicio, fim);
        quick_sort(vet, inicio, pos -1);
        quick_sort(vet, pos, fim);
    }
}

void imprimir_quick (int *vet, int tam) {
    for (int i = 0; i <= tam; i++)
        printf("%d", vet[i]);
    printf("\n");
}
