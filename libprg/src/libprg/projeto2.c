#include "libprg/projeto2.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

tarefa* criar_no_tarefa(){
    tarefa* novo = (tarefa*) malloc(sizeof (tarefa));
    if (novo == NULL) {
        printf("Erro na alocacao de memoria");
        exit(0);
    }
    return novo;
}

tarefa *inserir_descricao_tarefa(tarefa* li, char* descricao){
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

tarefa *inserir_prioridade_tarefa(tarefa *li, int indice_prioridade) {

}
void imprimir_lista_tarefa(tarefa *li){
    tarefa *aux = li;
    while (aux) {
        printf("%s\n", aux->descricao);
        aux=aux->prox;
    }
}