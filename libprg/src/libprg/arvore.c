#include "../include/libprg/arvore.h"

#include <stdio.h>
// int contador = 0;

no *criar_no(int x) {
    no *novo = (no*) malloc(sizeof(no));
    if (novo) {
        novo->valor = x;
        novo->esquerdo = NULL;
        novo->direito = NULL;
        novo->altura = 0;
    }
    return novo;
}

short maior(short a, short b) {
    return (a > b)? a: b;
}

short altura_no (no *no) {
    if (no)
        return no->altura;
    else
        return -1;
}

short fator_balanceamento (no *no) {
    if (no)
        return (altura_no(no->esquerdo)-altura_no(no->direito));
    else
        return 0;
}

no *rotacao_esquerda (no *raiz) {
    no *filho, *folha;
    filho = raiz->direito;
    folha = filho->esquerdo;
    filho->esquerdo = raiz;
    raiz->direito = folha;
    raiz->altura = maior(altura_no(raiz->esquerdo), altura_no(raiz->direito)) + 1;
    filho->altura = maior(altura_no(filho->esquerdo), altura_no(filho->direito)) + 1;
    // contador++;
    return filho;
}

no* rotacao_direita (no* raiz) {
    no *filho, *folha;
    filho = raiz->esquerdo;
    folha = filho->direito;
    filho->direito = raiz;
    raiz->esquerdo = folha;
    raiz->altura = maior(altura_no(raiz->esquerdo), altura_no(raiz->direito)) + 1;
    filho->altura = maior(altura_no(filho->esquerdo), altura_no(filho->direito)) + 1;
    // contador++;
    return filho;
}

no* rotacao_direita_esquerda (no *raiz) {
    raiz->direito = rotacao_direita(raiz->direito);
    return rotacao_esquerda(raiz);
}

no *rotacao_esquerda_direita (no *raiz) {
    raiz->esquerdo = rotacao_esquerda(raiz->esquerdo);
    return rotacao_direita(raiz);
}

no *inserir_valor_arvore (no *raiz, int valor) {
    if (raiz == NULL)
        return criar_no(valor);
    else {
        if (valor < raiz->valor)
            raiz->esquerdo = inserir_valor_arvore(raiz->esquerdo, valor);
        else if (valor > raiz->valor)
            raiz->direito = inserir_valor_arvore(raiz->direito, valor);
    }
    raiz->altura = maior(altura_no(raiz->esquerdo), altura_no(raiz->direito)) + 1;
    raiz = balancear(raiz);

    return raiz;
}

no *balancear(no *raiz) {
    short fator = fator_balanceamento(raiz);
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

no *remover(no *raiz, int chave) {
    if(raiz == NULL)
        return NULL;
    else
        if (raiz->valor == chave) {
            if (raiz->esquerdo == NULL && raiz->direito == NULL) {
                free(raiz);
                return NULL;
            }
            else {
                if (raiz->esquerdo != NULL && raiz->direito != NULL) {
                    no *aux = raiz->esquerdo;
                    while (aux->direito != NULL)
                        aux = aux->direito;
                    raiz->valor = aux->valor;
                    aux->valor = chave;
                    raiz->esquerdo = remover(raiz->esquerdo, chave);
                    return raiz;
                }
                else {
                    no *aux;
                    if (raiz->esquerdo != NULL)
                        aux = aux->esquerdo;
                    else
                        aux = aux->direito;
                    free(raiz);
                    return aux;
                }
            }
        } else{
            if(chave < raiz->valor)
                raiz->esquerdo = remover(raiz->esquerdo, chave);
            else
                raiz->direito = remover(raiz->direito, chave);
    }
    raiz->altura = maior(altura_no(raiz->esquerdo), altura_no(raiz->direito)) + 1;
    raiz = balancear(raiz);
    return raiz;
}

// int contador_rotacoes() {
//     return contador;
// }
