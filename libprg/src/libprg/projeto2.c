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
    novo_no->anterior = NULL;
    if (li == NULL) {
        novo_no->pos.codigo = 1;
        li = novo_no;
        novo_no->prox=NULL;
    }
    else{
        novo_no->pos.codigo = li->pos.codigo + 1;
        li->anterior = novo_no;
        novo_no->prox=li;
        li=novo_no;
    }
    return li;
}

estrutura *busca (estrutura *li, int codigo) {
    estrutura *aux = li;
    while (aux) {
        if (codigo == aux->pos.codigo)
            return aux;
        aux = aux->prox;
    }
    printf("Tarefa não encontrada\n");
    return NULL;
}

void remover_tarefa (estrutura **li, int num) {
    estrutura *remover = NULL;
    estrutura *aux = NULL;
    if (*li) {
        if ((*li)->pos.codigo == num) {
            remover = *li;
            *li = remover->prox;
        }
        else {
            aux = *li;
            if(busca(aux, num)) {
                remover = aux->prox;
                aux->prox = remover->prox;
            }
        }
    }
    else {
        printf("A lista esta vazia\n");
    }
}

estrutura *editar_tarefa (estrutura **li, char *descricao, int indice_de_prioridade, char *prazo, int codigo) {
    estrutura *editar = NULL;
    estrutura *aux = NULL;
    if (*li) {
        aux = *li;
        if(busca(aux, codigo)) {
            editar = aux->prox;
            aux->prox = editar->prox;
        }
    }
    else {
        printf("A lista esta vazia\n");
    }
    return editar;
}
void imprimir_lista_tarefa(estrutura *li){
    estrutura *aux = li;
    while (aux) {
        printf("%d\n", aux->pos.codigo);
        printf("O que fazer: %s", aux->pos.descricao);
        printf("Prazo de conclusao: %s", aux->pos.prazo);
        if (aux->pos.prioridade == 1)
            printf("Nivel de prioridade: Baixo\n");
        else if (aux->pos.prioridade == 2)
            printf("Nivel de prioridade: Medio\n");
        else if (aux->pos.prioridade == 3)
            printf("Nivel de prioridade: Alto\n");
        aux = aux->prox;
    }
    printf("\n\n");
}
