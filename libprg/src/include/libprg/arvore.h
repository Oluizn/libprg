#ifndef ARVORE_H
#ifndef _LIB_A
#define _LIB_A
#define ARVORE_H

#include <stdlib.h>

typedef struct no {
    int valor;
    struct no *esquerdo, *direito;
    int altura;
}no_t;

int contador_rotacoes();
no_t *criar_no(int x);
short maior(short a, short b);
short altura_no (no_t *node);
short fator_balanceamento (no_t *node);
no_t *rotacao_esquerda (no_t *raiz);
no_t* rotacao_direita (no_t* raiz);
no_t* rotacao_direita_esquerda (no_t *raiz);
no_t *rotacao_esquerda_direita (no_t *raiz);
no_t *inserir_valor_arvore (no_t *raiz, int x);
no_t *balancear(no_t *raiz);
no_t *remover(no_t *raiz, int chave);

#endif
#endif //ARVORE_H
