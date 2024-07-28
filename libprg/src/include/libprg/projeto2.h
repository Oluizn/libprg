#ifndef PROJETO2_H
#define PROJETO2_H

typedef struct tarefa {
    char descricao;
    struct tarefa* prox;
}tarefa;

tarefa* criar_no_tarefa();
tarefa *inserir_inicio_tarefa(tarefa* li, char descricao);
void imprimir_lista_tarefa(tarefa *li);

#endif //PROJETO2_H
