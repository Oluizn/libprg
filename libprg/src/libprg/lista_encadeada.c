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
    else{
        novo_no->prox=li;
        li=novo_no;
    }
    return li;
}

void imprimir_lista(numero *li){
    numero *aux = li;
    while (li!=NULL) {
        printf("%d\n", aux->num);
        aux=aux->prox;
    }
}