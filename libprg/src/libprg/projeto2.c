#include "libprg/projeto2.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

tarefa_no *criar_no(){
    tarefa_no *novo = (tarefa_no *) malloc(sizeof (tarefa_no));
    if (novo == NULL) {
        printf("Erro na alocacao de memoria");
        exit(0);
    }
    return novo;
}

tarefa_no *inserir_tarefa(tarefa_no *li, char *descricao, int indice_prioridade, char* prazo){
    tarefa_no *aux = li, * novo_no = criar_no();
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

tarefa_no *busca_codigo (tarefa_no *li, int codigo) {
    tarefa_no *aux = li;
    while (aux) {
        if (aux->pos.codigo == codigo)
            return aux;
        aux = aux->prox;
    }
    return NULL;
}

tarefa_no *busca (tarefa_no *li, int codigo) {
    tarefa_no *aux = li;
    while (aux) {
        if (aux->pos.codigo == codigo)
            return aux;
        aux = aux->prox;
    }
    return NULL;
}

tarefa_no *busca_descricao (tarefa_no *li, char *descricao) {
    tarefa_no *aux = li;
    while (aux) {
        if (strcmp(descricao, aux->pos.descricao) == 0)
            return aux;
        aux = aux->prox;
    }
    return NULL;
}

tarefa_no *busca_prazo (tarefa_no *li, char *prazo) {
    tarefa_no *aux = li;
    while (aux) {
        if (strcmp(prazo, aux->pos.prazo) == 0)
            return aux;
        aux = aux->prox;
    }
    return NULL;
}

void remover_tarefa (tarefa_no **li, int num) {
    tarefa_no *remover = NULL;
    tarefa_no *aux = *li;
    if (*li) {
        if ((*li)->pos.codigo == num) {
            remover = *li;
            *li = remover->prox;
            free(remover);
        }
        else {  // TODO -> tentar implementar essa função utilizando a funçao de busca acima
            while (aux->prox && aux->prox->pos.codigo != num)
                aux = aux->prox;
            if (aux->prox) {
                remover = aux->prox;
                aux->prox = remover->prox;
                if (remover->prox) {
                    tarefa_no *aux2 = remover->prox; // ponteiro para carpturar o nó em sequencia para atribuir o ponteiro anterior para o nó anterior corretamente, após a remoção feita
                    aux2->anterior = aux;
                }
                free(remover);
            }
            else
                printf("Elemento nao encotrado\n");
        }
    }
    else {
        printf("A lista esta vazia\n");
    }
}

void editar_tarefa_descricao (tarefa_no *li, char *nova_descricao, int codigo) {
    tarefa_no *aux = busca(li, codigo);
    if (aux)
        strcpy(aux->pos.descricao, nova_descricao);
}

void editar_tarefa_prioridade (tarefa_no *li, int novo_indice_prioridade, int codigo) {
    tarefa_no *aux = busca(li, codigo);
    if (aux)
        aux->pos.prioridade = novo_indice_prioridade;
}

void editar_tarefa_prazo (tarefa_no *li, char *novo_prazo, int codigo) {
    tarefa_no *aux = busca(li, codigo);
    if (aux)
        strcpy(aux->pos.prazo, novo_prazo);
}

void concluir_tarefa (tarefa_no *li, int codigo) {
    tarefa_no *aux = busca(li, codigo);
    if (aux)
        strcpy(aux->pos.status, "concluida");
}

void imprimir_lista_tarefa(tarefa_no *li){
    tarefa_no *aux = li;
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
