#include "stdio.h"
#include "stdlib.h"
#include "libprg/libprg.h"

numero* criar_no(){
    numero* novo = (numero*) malloc(sizeof (numero));
    return novo;
}


numero *inserir_inicio(numero* li, int valor){
    numero* novo_no = criar_no();
    novo_no->num = valor;
    if (li == NULL) {
        li = novo_no;
        novo_no->prox=NULL;
    }
}

void imprimir_lista(numero *li){
    numero *aux = li;
    while (li!=NULL) {
        printf("%d", aux->num);
        aux=aux->prox;
    }
}