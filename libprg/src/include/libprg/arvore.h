#ifndef ARVORE_H
#ifndef _LIB_A
#define _LIB_A
#define ARVORE_H

#include <stdlib.h>

typedef struct no {
    int valor;
    struct no *esquerdo, *direito;
    int altura;
}no;

// int contador_rotacoes();
no *criar_no(int x);
short maior(short a, short b);
short altura_no (no *no);
short fator_balanceamento (no *no);
no *rotacao_esquerda (no *raiz);
no* rotacao_direita (no* raiz);
no* rotacao_direita_esquerda (no *raiz);
no *rotacao_esquerda_direita (no *raiz);
no *inserir_valor_arvore (no *raiz, int x);
no *balancear(no *raiz);
no *remover(no *raiz, int chave);

#endif
#endif //ARVORE_H
