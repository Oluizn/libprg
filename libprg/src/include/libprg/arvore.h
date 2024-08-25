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

no_t *criar_no(int x);
no_t *rotacao_esquerda (no_t *raiz);
no_t *rotacao_direita (no_t* raiz);
no_t *rotacao_direita_esquerda (no_t *raiz);
no_t *rotacao_esquerda_direita (no_t *raiz);
no_t *inserir_valor_arvore (no_t *raiz, int x);
no_t *balancear(no_t *raiz);
no_t *remover(no_t *raiz, int chave);
int contador_rotacoes();
int maior(int a, int b);
int altura_no (no_t *node);
int fator_balanceamento (no_t *node);
void liberar_arvore (no_t *raiz);



#endif
#endif //ARVORE_H
