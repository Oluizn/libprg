#ifndef PROJETO2_H
#define PROJETO2_H

typedef struct tarefa {
    char descricao;
    struct tarefa* prox;
}tarefa;

task* criar_no();
task *inserir_inicio(tarefa* li, char descricao);
#endif //PROJETO2_H
