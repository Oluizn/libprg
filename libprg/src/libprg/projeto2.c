#include "libprg/projeto2.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

tarefa* criar_no(){
    tarefa* novo = (tarefa*) malloc(sizeof (tarefa));
    return novo;
}

tarefa *inserir_inicio(tarefa* li, char descricao){
    tarefa* novo_no = criar_no();
    novo_no->descricao = descricao;
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

void imprimir_lista(tarefa *li){
    tarefa *aux = li;
    while (aux) {
        printf("%d\t", aux->descricao);
        aux=aux->prox;
    }
}