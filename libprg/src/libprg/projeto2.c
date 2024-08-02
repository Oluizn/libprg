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
        novo_no->pos.codigo = li->pos.codigo + 1;
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

estrutura *remover_tarefa (estrutura **li, int num) {
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
    // else {
    //     printf("A lista esta vazia\n");
    // }
    return remover;
}
void imprimir_lista_tarefa(estrutura *li){
    estrutura *aux = li;
    while (aux) {
        printf("%d\n", aux->pos.codigo);
        printf("O que fazer: %s\n", aux->pos.descricao);
        printf("Prazo de conclusao: %s\n", aux->pos.prazo);
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

void menu_tarefas () {
    int operador = 0;
    estrutura *lista_tarefa = NULL;
    while (operador != 9) {
        fflush(stdin);
        printf("Escolha uma acao:\n");
        printf("1 - Nova tarefa:\n");
        printf("2 - Lista de tarefas:\n");
        printf("3 - Remover tarefa:\n");
        printf("9 - Sair.\n");

        scanf("%d", &operador);

        if(operador != 9){
            switch (operador) {
                case 1: {
                    fflush(stdin);
                    int descricao, prazo;
                    int prioridade;
                    printf("Por favor informe a descricao da tarefa: ");
                    scanf("%d", &descricao);
                    fflush(stdin);
                    printf("Por favor informe o prazo da tarefa: ");
                    scanf("%d", &prazo);
                    fflush(stdin);
                    printf("Por favor informe o nivel de prioridade da tarefa.\n1 - Baixo\n2 - Medio\n3 - Alto\n");
                    scanf("%d", &prioridade);
                    fflush(stdin);
                    lista_tarefa = inserir_inicio_tarefa(lista_tarefa, "descricao", prioridade, "prazo");
                    break;
                }
                case 2: {
                    fflush(stdin);
                    imprimir_lista_tarefa(lista_tarefa);
                    break;
                }
                case 3: {
                    fflush(stdin);
                    imprimir_lista_tarefa(lista_tarefa);
                    printf("\n");
                    int operador_removedor;
                    fflush(stdin);
                    printf("Por favor, insira o codigo da tarefa que deseja remover: ");
                    scanf("%d", &operador_removedor);
                    fflush(stdin);
                    remover_tarefa(&lista_tarefa, operador_removedor);
                    break;
                }
                default:
                    printf("Opcao invalida, escolha entre 1 e 3, ou pressione 9 para sair");
                fflush(stdin);
            }
        }
        else
            printf("Adeus!.\n");
    }
}