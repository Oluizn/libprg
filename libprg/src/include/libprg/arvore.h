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

typedef struct no_pilha {
    int num;
    struct no_pilha *proximo;
}pilha_no;

typedef struct {
    pilha_no *topo;
    int tam;
}Pilha;

no_t *criar_no(int x);
pilha_no *no_pilha();
pilha_no *desempilhar(Pilha *p);
no_t *rotacao_esquerda (no_t *raiz);
no_t* rotacao_direita (no_t* raiz);
no_t* rotacao_direita_esquerda (no_t *raiz);
no_t *rotacao_esquerda_direita (no_t *raiz);
no_t *inserir_valor_arvore (no_t *raiz, int x);
no_t *balancear(no_t *raiz);
no_t *remover(no_t *raiz, int chave);
int contador_rotacoes();
int maior(int a, int b);
int altura_no (no_t *node);
int fator_balanceamento (no_t *node);
int contar_no (no_t *raiz);
int *guardar_arvore();
void liberar_arvore (no_t *raiz);
void in_order (no_t *raiz, Pilha *p);
void empilhar (Pilha *p, int valor);


#endif
#endif //ARVORE_H
