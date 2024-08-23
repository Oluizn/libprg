#ifndef PROJETO2_H
#define PROJETO2_H
#define FILE_NAME "Tarefas.dat"
#include "stdio.h"

typedef struct data {
    int dia, mes, ano;
}data;

typedef struct tarefa {
    int codigo;
    char descricao[100];
    int prioridade;
    data prazo;
    data conclusao;
    char status[25];
}tarefa;

typedef struct tarefa_t {
    tarefa pos;
    struct tarefa_t *prox;
    struct tarefa_t *anterior;
}tarefa_no;

int salvar_lista(tarefa_no *li);
tarefa_no *carregar_lista (tarefa_no *li);
tarefa_no *criar_no();
tarefa_no *inserir_tarefa(tarefa_no *li, char *descricao, int indice_prioridade, int dia_p, int mes_p, int ano_p, int dia_c, int mes_c, int ano_c, char *status);
tarefa_no *busca_codigo (tarefa_no *li, int codigo);
tarefa_no *busca_prioridade (tarefa_no *li, int prioridade);
tarefa_no *busca_prazo_dia (tarefa_no *li, int prazo);
tarefa_no *busca_prazo_mes (tarefa_no *li, int prazo);
tarefa_no *busca_prazo_ano (tarefa_no *li, int prazo);
tarefa_no *busca_descricao (tarefa_no *li, char *descricao);
tarefa_no *busca_conclusao_dia (tarefa_no *li, int prazo);
tarefa_no *busca_conclusao_mes (tarefa_no *li, int prazo);
tarefa_no *busca_conclusao_ano (tarefa_no *li, int prazo);
void remover_tarefa (tarefa_no **li, int num);
void editar_tarefa_descricao (tarefa_no *li, char *nova_descricao, int codigo);
void editar_tarefa_prioridade (tarefa_no *li, int novo_indice_prioridade, int codigo);
void editar_tarefa_prazo (tarefa_no *li, int novo_dia, int novo_mes, int novo_ano, int codigo);
void altera_status_tarefa (tarefa_no *li, int codigo);
void tarefa_atrasada (tarefa_no *li);
void ordenar_prazo_decrescente (tarefa_no *li);
void ordenar_prazo_crescente (tarefa_no *li);
void ordenar_prioridade_maior (tarefa_no *li);
void ordenar_prioridade_menor (tarefa_no *li);
void ordenar_codigo (tarefa_no *li);
void libera_lista (tarefa_no *li);

#endif //PROJETO2_H
