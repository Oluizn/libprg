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

typedef struct tarefa_t {
    tarefa pos;
    struct tarefa_t *prox;
    struct tarefa_t *anterior;
}tarefa_no;

tarefa_no *criar_no();
tarefa_no *inserir_tarefa(tarefa_no* li, char* descricao, int indice_prioridade, char* prazo);
void imprimir_lista_tarefa(tarefa_no *li);
void menu_tarefas ();
tarefa_no *busca (tarefa_no *li, int codigo);
void remover_tarefa (tarefa_no **li, int num);
void editar_tarefa_descricao (tarefa_no *li, char *nova_descricao, int codigo);
void editar_tarefa_prioridade (tarefa_no *li, int novo_indice_prioridade, int codigo);
void editar_tarefa_prazo (tarefa_no *li, char *novo_prazo, int codigo);

#endif //PROJETO2_H
