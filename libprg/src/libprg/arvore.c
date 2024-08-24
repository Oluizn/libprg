#include "libprg/arvore.h"
#include "stdlib.h"
#include <stdio.h>
int contador = 0;

no_t *criar_no(int x) {
    no_t *novo = (no_t*) malloc(sizeof(no_t));
    if (novo) {
        novo->z = x;
        novo->esquerdo = NULL;
        novo->direito = NULL;
        novo->altura = 0;
    }
    return novo;
}

int maior(int a, int b) {
    return (a > b)? a: b;
}

int altura_no (no_t *node) {
    if (node)
        return node->altura;
    else
        return -1;
}

int fator_balanceamento (no_t *node) {
    if (node)
        return (altura_no(node->esquerdo)-altura_no(node->direito));
    else
        return 0;
}

no_t *rotacao_esquerda (no_t *raiz) {
    no_t *filho, *folha;
    filho = raiz->direito;
    folha = filho->esquerdo;
    filho->esquerdo = raiz;
    raiz->direito = folha;
    raiz->altura = maior(altura_no(raiz->esquerdo), altura_no(raiz->direito)) + 1;
    filho->altura = maior(altura_no(filho->esquerdo), altura_no(filho->direito)) + 1;
    contador++;
    return filho;
}

no_t* rotacao_direita (no_t* raiz) {
    no_t *filho, *folha;
    filho = raiz->esquerdo;
    folha = filho->direito;
    filho->direito = raiz;
    raiz->esquerdo = folha;
    raiz->altura = maior(altura_no(raiz->esquerdo), altura_no(raiz->direito)) + 1;
    filho->altura = maior(altura_no(filho->esquerdo), altura_no(filho->direito)) + 1;
    contador++;
    return filho;
}

no_t* rotacao_direita_esquerda (no_t *raiz) {
    raiz->direito = rotacao_direita(raiz->direito);
    return rotacao_esquerda(raiz);
}

no_t *rotacao_esquerda_direita (no_t *raiz) {
    raiz->esquerdo = rotacao_esquerda(raiz->esquerdo);
    return rotacao_direita(raiz);
}

no_t *inserir_valor_arvore (no_t *raiz, int x) {
    if (raiz == NULL)
       raiz = criar_no(x);
    else {
        if (x < raiz->z)
            raiz->esquerdo = inserir_valor_arvore(raiz->esquerdo, x);
        else if (x > raiz->z)
            raiz->direito = inserir_valor_arvore(raiz->direito, x);
    }
    raiz->altura = maior(altura_no(raiz->esquerdo), altura_no(raiz->direito)) + 1;
    raiz = balancear(raiz);
    return raiz;
}

no_t *balancear(no_t *raiz) {
    int fator = fator_balanceamento(raiz);
    if (fator < -1 && fator_balanceamento(raiz->direito) <= 0)
        raiz = rotacao_esquerda(raiz);
    else if (fator > 1 && fator_balanceamento(raiz->esquerdo) >= 0)
        raiz = rotacao_direita(raiz);
    else if(fator > 1 && fator_balanceamento(raiz->esquerdo) < 0)
        raiz = rotacao_esquerda_direita(raiz);
    else if (fator < -1 && fator_balanceamento(raiz->direito) > 0)
        raiz = rotacao_direita_esquerda(raiz);
    return raiz;
}

no_t *remover(no_t *raiz, int chave) {
    if(raiz == NULL)
        return NULL;
    else
        if (raiz->z == chave) {
            if (raiz->esquerdo == NULL && raiz->direito == NULL) {
                free(raiz);
                return NULL;
            }
            else {
                if (raiz->esquerdo != NULL && raiz->direito != NULL) {
                    no_t *aux = raiz->esquerdo;
                    while (aux->direito != NULL)
                        aux = aux->direito;
                    raiz->z = aux->z;
                    aux->z = chave;
                    raiz->esquerdo = remover(raiz->esquerdo, chave);
                    return raiz;
                }
                else {
                    no_t *aux = raiz;
                    if (raiz->esquerdo != NULL)
                        aux = aux->esquerdo;
                    else
                        aux = aux->direito;
                    free(raiz);
                    return aux;
                }
            }
        } else{
            if(chave < raiz->z)
                raiz->esquerdo = remover(raiz->esquerdo, chave);
            else
                raiz->direito = remover(raiz->direito, chave);
    }
    raiz->altura = maior(altura_no(raiz->esquerdo), altura_no(raiz->direito)) + 1;
    raiz = balancear(raiz);
    return raiz;
}

int contar_no (no_t *raiz) {
    if (raiz == NULL)
        return 0;
    else
        return 1 + contar_no(raiz->esquerdo) + contar_no(raiz->direito);
}

int guardar_no (no_t *raiz) {
    if (raiz->esquerdo && raiz->direito == NULL)
        return raiz->z;
    else
        return guardar_no(raiz->esquerdo);
}

int contador_rotacoes() {
    return contador;
}
