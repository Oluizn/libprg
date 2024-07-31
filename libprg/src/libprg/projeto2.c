#include "libprg/projeto2.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

estrutura *criar_no_tarefa(){
    estrutura *novo = (estrutura *) malloc(sizeof (estrutura));
    if (novo == NULL) {
        printf("Erro na alocacao de memoria");
        exit(0);
    }
    return novo;
}

estrutura *inserir_inicio_tarefa(estrutura * li, char *descricao, int indice_prioridade, char* prazo){
    estrutura * novo_no = criar_no_tarefa();
    strcpy(novo_no->pos.descricao, descricao);
    strcpy(novo_no->pos.prazo, prazo);
    novo_no->pos.prioridade = indice_prioridade;

    if (li == NULL) {
        novo_no->pos.codigo = 1;
        li = novo_no;
        novo_no->prox=NULL;
    }
    else{
        estrutura *aux = li; // auxiliar para captar valor do código do nó anterior
        novo_no->pos.codigo = aux->pos.codigo + 1;
        novo_no->prox=li;
        li=novo_no;
    }
    return li;
}

void imprimir_lista_tarefa(estrutura *li){
    estrutura *aux = li;
    while (aux) {
        printf("%d\n", aux->pos.codigo);
        printf("%s\n", aux->pos.descricao);
        printf("%s\n", aux->pos.prazo);
        printf("Nivel de prioridade: %d\n", aux->pos.prioridade);
        aux = aux->prox;
    }
}