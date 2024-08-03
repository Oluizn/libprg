#include "libprg/projeto2.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

tarefa_nao_concluida *criar_no_tarefa(){
    tarefa_nao_concluida *novo = (tarefa_nao_concluida *) malloc(sizeof (tarefa_nao_concluida));
    if (novo == NULL) {
        printf("Erro na alocacao de memoria");
        exit(0);
    }
    return novo;
}

tarefa_nao_concluida *inserir_inicio_tarefa(tarefa_nao_concluida *li, char *descricao, int indice_prioridade, char* prazo){
    tarefa_nao_concluida *aux = li, * novo_no = criar_no_tarefa();
    strcpy(novo_no->pos.descricao, descricao);
    strcpy(novo_no->pos.prazo, prazo);
    strcpy(novo_no->pos.status, "Nao concluida");
    novo_no->pos.prioridade = indice_prioridade;
    if (li == NULL) {
        novo_no->pos.codigo = 1;
        li = novo_no;
        novo_no->prox=NULL;
        novo_no->anterior=NULL;
    }
    else{
        while (aux->prox)
            aux = aux->prox;
        aux->prox = novo_no;
        novo_no->prox = NULL;
        novo_no->anterior = aux;
        novo_no->pos.codigo = aux->pos.codigo + 1;
    }
    return li;
}

tarefa_nao_concluida *busca (tarefa_nao_concluida *li, int codigo) {
    tarefa_nao_concluida *aux = li;
    while (aux) {
        if (codigo == aux->prox->pos.codigo)
            return aux;
        aux = aux->prox;
    }
    printf("Tarefa não encontrada\n");
    return NULL;
}

void remover_tarefa (tarefa_nao_concluida **li, int num) {
    tarefa_nao_concluida *remover = NULL;
    tarefa_nao_concluida *aux = *li;
    if (*li) {
        if ((*li)->pos.codigo == num) {
            remover = *li;
            *li = remover->prox;
            free(remover);
        }
        else {
            while (aux->prox && aux->prox->pos.codigo != num)
                aux = aux->prox;
            if (aux->prox) {
                remover = aux->prox;
                aux->prox = remover->prox;
                if (remover->prox) {
                    tarefa_nao_concluida *aux2 = remover->prox;
                    aux2->anterior = aux;
                }
                free(remover);
            }
            else
                printf("Elemento nao encotrado");
        }
    }
    else {
        printf("A lista esta vazia\n");
    }
}

tarefa_nao_concluida *editar_tarefa (tarefa_nao_concluida *li, char *descricao, int indice_prioridade, char *prazo, int codigo) {
    tarefa_nao_concluida *aux = li, * novo_no = criar_no_tarefa();
    strcpy(novo_no->pos.descricao, descricao);
    strcpy(novo_no->pos.prazo, prazo);
    strcpy(novo_no->pos.status, "Nao concluida");
    novo_no->pos.prioridade = indice_prioridade;
    novo_no->pos.codigo;

    return novo_no;
}
void imprimir_lista_tarefa(tarefa_nao_concluida *li){
    tarefa_nao_concluida *aux = li;
    if (aux == NULL)
        printf("A lista esta vazia!");
    while (aux) {
        printf("\n%d\n", aux->pos.codigo);
        printf("O que fazer: %s\n", aux->pos.descricao);
        printf("Prazo de conclusao: %s\n", aux->pos.prazo);
        printf("Status: %s\n", aux->pos.status);
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
