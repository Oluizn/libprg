#include "libprg/projeto2.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

tarefa* criar_no_tarefa(){
    tarefa* novo = (tarefa*) malloc(sizeof (tarefa));
    if (novo == NULL) {
        printf("Erro na alocacao de memoria");
        return novo;
    }
    else
        return novo;
}

tarefa *inserir_inicio_tarefa(tarefa* li, char* descricao){
    tarefa* novo_no = criar_no_tarefa();
    strcpy(novo_no->descricao, descricao);
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

void imprimir_lista_tarefa(tarefa *li){
    tarefa *aux = li;
    while (aux) {
        printf("%s", aux->descricao);
        aux=aux->prox;
    }
}