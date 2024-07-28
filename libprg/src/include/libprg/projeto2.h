#ifndef PROJETO2_H
#define PROJETO2_H

typedef struct tarefa {
    int codigo;
    char descricao[100];
    int prioridade;
    char prazo[13];
    struct tarefa* prox;
}tarefa;

tarefa* criar_no_tarefa();
tarefa *inserir_descricao_tarefa(tarefa* li, char decricao[100]);
void imprimir_lista_tarefa(tarefa *li);

#endif //PROJETO2_H
