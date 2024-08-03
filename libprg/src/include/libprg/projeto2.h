#ifndef PROJETO2_H
#define PROJETO2_H

typedef struct tarefa {
    int codigo;
    char descricao[100];
    int prioridade;
    char prazo[13];
    int conclusao[13];
    char status [20];
}tarefa;

typedef struct estrutura_tarefa_nao_concluida {
    tarefa pos;
    struct estrutura_tarefa_nao_concluida *prox;
    struct estrutura_tarefa_nao_concluida *anterior;
}tarefa_nao_concluida;

typedef struct estrutura_tarefa_concluida {
    tarefa pos;
    struct estrutura_tarefa_concluida *prox;
    struct estrutura_tarefa_concluida *anterior;
}tarefa_concluida;

tarefa_nao_concluida *criar_no_tarefa();
tarefa_nao_concluida *inserir_inicio_tarefa(tarefa_nao_concluida* li, char* descricao, int indice_prioridade, char* prazo);
void imprimir_lista_tarefa(tarefa_nao_concluida *li);
void menu_tarefas ();
tarefa_nao_concluida *busca (tarefa_nao_concluida *li, int codigo);
void remover_tarefa (tarefa_nao_concluida **li, int num);
void editar_tarefa (tarefa_nao_concluida *li, char *descricao, int indice_prioridade, char *prazo, int codigo);

#endif //PROJETO2_H
