#ifndef ARVORE_H
#define ARVORE_H
#include <stdlib.h>

typedef struct no {
    int valor;
    struct no *esquerdo, *direito;
    int altura;
}no;

int contador_rotacao_esquerda;
int contador_rotacao_direita;

no *criar_no(int x);
short maior(short a, short b);
short altura_no (no *no);
short fator_balanceamento (no *no);
no *rotacao_esquerda (no *raiz);
no* rotacao_direita (no* raiz);
no* rotacao_direita_esquerda (no *raiz);
no *rotacao_esquerda_direita (no *raiz);
no *inserir (no *raiz, int valor);
no *balancear(no *raiz);
no *remover(no *raiz, int chave);
#endif //ARVORE_H
