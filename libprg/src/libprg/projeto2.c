#include "libprg/projeto2.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "time.h"

size_t salvar_lista(tarefa_no *li) {
    FILE *file = fopen(FILE_NAME, "wb");
    int cont_elementos = 0;
    if (file) {
        tarefa_no *aux = li;
        tarefa escrevendo_nos;
        while (aux) {
            escrevendo_nos.codigo = aux->pos.codigo;
            strcpy(escrevendo_nos.descricao, aux->pos.descricao);
            escrevendo_nos.prazo.dia = aux->pos.prazo.dia;
            escrevendo_nos.prazo.mes = aux->pos.prazo.mes;
            escrevendo_nos.prazo.ano = aux->pos.prazo.ano;
            escrevendo_nos.conclusao.dia = aux->pos.conclusao.dia;
            escrevendo_nos.conclusao.mes = aux->pos.conclusao.mes;
            escrevendo_nos.conclusao.ano = aux->pos.conclusao.ano;
            strcpy(escrevendo_nos.status, aux->pos.status);
            escrevendo_nos.prioridade = aux->pos.prioridade;
            fwrite(&escrevendo_nos, sizeof(tarefa), 1 , file);
            aux = aux->prox;
        }
        if (ferror(file))
            return -1;
        fclose(file);
        return cont_elementos;
    }
    else {
        exit(0);
    }
}

tarefa_no *carregar_lista (tarefa_no *li) {
    tarefa carregando_tarefas;
    FILE *file = fopen("FILE_NAME", "rb");
    while (!feof(file)) { // TODO verificar o motivo de o arquivo estar abrindo como NULL
        fread(&carregando_tarefas, sizeof(tarefa), 1, file);
        li = inserir_tarefa(li, carregando_tarefas.descricao, carregando_tarefas.prioridade, carregando_tarefas.prazo.dia, carregando_tarefas.prazo.mes, carregando_tarefas.prazo.ano, carregando_tarefas.conclusao.ano, carregando_tarefas.conclusao.mes, carregando_tarefas.conclusao.ano, carregando_tarefas.status);
    }
    fclose(file);
    return li;
}

tarefa_no *criar_no(){
    tarefa_no *novo = (tarefa_no *) malloc(sizeof (tarefa_no));
    if (novo == NULL) {
        exit(0);
    }
    return novo;
}

tarefa_no *inserir_tarefa(tarefa_no *li, char *descricao, int indice_prioridade, int dia_p, int mes_p, int ano_p, int dia_c, int mes_c, int ano_c, char *status){
    tarefa_no *aux = li, * novo_no = criar_no();
    strcpy(novo_no->pos.descricao, descricao);
    novo_no->pos.prazo.dia = dia_p;
    novo_no->pos.prazo.mes = mes_p;
    novo_no->pos.prazo.ano = ano_p;
    strcpy(novo_no->pos.status, status);
    novo_no->pos.conclusao.ano = dia_c;
    novo_no->pos.conclusao.mes = mes_c;
    novo_no->pos.conclusao.ano = ano_c;
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

tarefa_no *busca_descricao (tarefa_no *li, char *descricao) {
    tarefa_no *aux = li;
    while (aux) {
        if (strcmp(descricao, aux->pos.descricao) == 0)
            return aux;
        aux = aux->prox;
    }
    return NULL;
}

// TODO reformular essa busca para comparar com inteiro
// tarefa_no *busca_prazo (tarefa_no *li, int prazo) {
//     tarefa_no *aux = li;
//     while (aux) {
//         if (strcmp(prazo, aux->pos.prazo) == 0)
//             return aux;
//         aux = aux->prox;
//     }
//     return NULL;
// }

void remover_tarefa (tarefa_no **li, int num) {
    tarefa_no *remover = NULL;
    tarefa_no *aux = *li;
    if (*li) {
        if ((*li)->pos.codigo == num) {
            remover = *li;
            *li = remover->prox;
            free(remover);
        }
        else {
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
        }
    }
}

void editar_tarefa_descricao (tarefa_no *li, char *nova_descricao, int codigo) {
    tarefa_no *aux = busca_codigo(li, codigo);
    if (aux)
        strcpy(aux->pos.descricao, nova_descricao);
}

void editar_tarefa_prioridade (tarefa_no *li, int novo_indice_prioridade, int codigo) {
    tarefa_no *aux = busca_codigo(li, codigo);
    if (aux)
        aux->pos.prioridade = novo_indice_prioridade;
}

void editar_tarefa_prazo (tarefa_no *li, int novo_dia, int novo_mes, int novo_ano, int codigo) {
    tarefa_no *aux = busca_codigo(li, codigo);
    if (aux) {
        aux->pos.prazo.dia = novo_dia;
        aux->pos.prazo.mes = novo_mes;
        aux->pos.prazo.ano = novo_ano;
    }
}

void altera_status_tarefa (tarefa_no *li, int codigo) {
    tarefa_no *aux = busca_codigo(li, codigo);
    if (aux) {
        if (strcmp(aux->pos.status, "Nao concluida") == 0 || strcmp(aux->pos.status, "Atrasada") == 0) {
            strcpy(aux->pos.status, "Concluida");
            struct tm *data;
            time_t segundos;
            time(&segundos);
            data = localtime(&segundos);
            aux->pos.conclusao.dia = data->tm_mday;
            aux->pos.conclusao.mes = data->tm_mon+1;
            aux->pos.conclusao.ano = data->tm_year+1900;
        }
        else {
            strcpy(aux->pos.status, "Nao concluida");
            aux->pos.conclusao.dia = 0;
            aux->pos.conclusao.mes = 0;
            aux->pos.conclusao.ano = 0;
        }
    }
}
void tarefa_atrasada (tarefa_no *li) {
    tarefa_no *aux = li;
    struct tm *data;
    time_t segundos;
    time(&segundos);
    data = localtime(&segundos);
    while (aux) {
        if (aux->pos.prazo.dia < data->tm_mday)
            if (aux->pos.prazo.mes <= data->tm_mon+1)
                if (aux->pos.prazo.ano <= data->tm_year+1900)
                    strcpy(aux->pos.status, "Atradasa");
        aux = aux->prox;
    }
}

void ler_string(char *nome, int tamanho) {
    char letra, i = 0;
    do
    {
        letra = getchar ();
        if(letra != '\n' && i < tamanho - 1)
        {
            nome[i] = letra;
            i++;
        }
    }while(letra != '\n');
    nome[i] = '\0';
}
