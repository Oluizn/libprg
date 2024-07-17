 #include "stdio.h"
 #include "stdlib.h"
 #include "libprg/libprg.h"

 void bubble_sort(int* vet, int tamanho){
    int aux;
    for (int i = 0; i < tamanho; ++i) {
         for (int j = 0; j < tamanho - 1; ++j) {
             if (vet[j] < vet[j+1]) {
                 aux = vet[j];
                 vet[j] = vet[j+1];
                 vet[j+1] = aux;
             }
         }
    }
 }
 void imprimir_bubble (int *vet){
    int i = 0;
     while (&vet[i]) {
         printf("%d\t", vet[i]);
         i++;
     }
}