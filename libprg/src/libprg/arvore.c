#include <stdlib.h>
#include "libprg/libprg.h"
#include "stdio.h"

typedef struct no {
    int valor;
    struct no *esquerda;
    struct no *direita;
}no_t;

no_t *criar_no (int valor) {
    no_t *no = (no_t* ) malloc(sizeof(no_t));
    no->valor = valor;
    no->direita = no->direita = NULL;
    return no;
}

void destruir_no(no_t *no) {
    if (no) {
        destruir_no(no->esquerda);
        destruir_no(no->direita);
        free(no);
    }
}

no_t *inserir_valor (no_t *raiz, int valor) {
    if (raiz == NULL) {
        return criar_no(valor);
    }
    else if(valor < raiz->valor) {
        raiz->esquerda = inserir_valor(raiz->esquerda, valor);
    }else if(valor > raiz->valor) {
        raiz->direita = inserir_valor(raiz->direita, valor);
    }
    return raiz;
}
int busca(no_t *raiz, int valor) {
    if (raiz == NULL ) return -1;
    if (valor == raiz->valor) return 1;
    if (valor < raiz->valor) return busca(raiz->esquerda, valor);
    return busca(raiz->direita, valor);
}

no_t *remover_valor (no_t *raiz, int valor) {
    if (raiz == NULL) return raiz;
    if (valor < raiz->valor)
        raiz->esquerda = remover_valor(raiz, valor);
    else if (valor > raiz->valor)
        raiz->direita = remover_valor(raiz, valor);
    else {

    }
}