#ifndef SORT_H
#define SORT_H

void imprimir_sort(int *vet, int tam);
void bubble_sort(int* vet, int tamanho);
int* insertion_sort(int* vet, int tamanho);
int* selection_sort(int *vet, int tam);
int particiona (int *vet, int inicio, int fim);
void quick_sort(int *vet, int inicio, int fim);
void imprimir_quick (int *vet, int tam);
#endif //SORT_H
