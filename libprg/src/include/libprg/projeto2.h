#ifndef PROJETO2_H
#define PROJETO2_H

typedef struct tarefa {
    int codigo;
    char descricao[100];
    int prioridade;
    char prazo[13];
    int conclusao[13];
}tarefa;

typedef struct estrutura_tarefa {
    tarefa pos;
    struct estrutura_tarefa *prox;
    struct estrutura_tarefa *anterior;
}estrutura;

estrutura *criar_no_tarefa();
estrutura *inserir_inicio_tarefa(estrutura* li, char* descricao, int indice_prioridade, char* prazo);
void imprimir_lista_tarefa(estrutura *li);
void menu_tarefas ();
estrutura *busca (estrutura *li, int codigo);
void remover_tarefa (estrutura **li, int num);

#endif //PROJETO2_H
