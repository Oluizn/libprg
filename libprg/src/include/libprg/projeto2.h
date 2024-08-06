#ifndef PROJETO2_H
#define PROJETO2_H

typedef struct tarefa {
    int codigo;
    char descricao[100];
    int prioridade;
    char prazo[14];
    char conclusao[14];
    char status[25];
}tarefa;

typedef struct tarefa_t {
    tarefa pos;
    struct tarefa_t *prox;
    struct tarefa_t *anterior;
}tarefa_no;

tarefa_no *criar_no();
tarefa_no *inserir_tarefa(tarefa_no* li, char* descricao, int indice_prioridade, char* prazo);
tarefa_no *busca_codigo (tarefa_no *li, int codigo);
tarefa_no *busca_prazo (tarefa_no *li, char *prazo);
tarefa_no *busca_descricao (tarefa_no *li, char *descricao);
void remover_tarefa (tarefa_no **li, int num);
void editar_tarefa_descricao (tarefa_no *li, char *nova_descricao, int codigo);
void editar_tarefa_prioridade (tarefa_no *li, int novo_indice_prioridade, int codigo);
void editar_tarefa_prazo (tarefa_no *li, char *novo_prazo, int codigo);
void altera_status_tarefa (tarefa_no *li, int codigo);

#endif //PROJETO2_H
