#include "libprg/projeto2.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "time.h"
#include "ctype.h"

int salvar_lista(tarefa_no *li) {
    FILE *file = fopen(FILE_NAME, "wb");
    if (file) {
        tarefa_no *aux = li;
        while (aux) {
            fwrite(&aux->pos, sizeof(tarefa), 1 , file);
            aux = aux->prox;
        }
        if (ferror(file))
            return -1;
        fclose(file);
        return 0;
    }
    else {
        exit(0);
    }
}

tarefa_no *carregar_lista (tarefa_no *li) {
    tarefa carregando_tarefas;
    FILE *file = fopen(FILE_NAME, "rb");
    if (file) {
        while (!feof(file)) {
            fread(&carregando_tarefas, sizeof(tarefa), 1, file);
            li = inserir_tarefa(li, carregando_tarefas.descricao, carregando_tarefas.prioridade, carregando_tarefas.prazo.dia, carregando_tarefas.prazo.mes, carregando_tarefas.prazo.ano, carregando_tarefas.conclusao.ano, carregando_tarefas.conclusao.mes, carregando_tarefas.conclusao.ano, carregando_tarefas.status);
        }
        fclose(file);
        tarefa_no *aux = li;
        while (aux->prox)
            aux = aux->prox;
        remover_tarefa(&li, aux->pos.codigo);
        return li;
    }
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
    for (int i = 0; i < strlen(descricao); i++)
        descricao[i] = toupper(descricao[i]);
    novo_no->pos.descricao[strcspn(novo_no->pos.descricao, "\n")] = '\0';
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

tarefa_no *busca_prioridade (tarefa_no *li, int prioridade) {
    tarefa_no *aux = li;
    while (aux) {
        if (aux->pos.prioridade == prioridade)
            return aux;
        aux = aux->prox;
    }
    return NULL;
}

tarefa_no *busca_descricao (tarefa_no *li, char *descricao) {
    tarefa_no *aux = li;
    if (aux) {
        for (int i = 0; i < strlen(descricao); i++)
            descricao[i]= toupper(descricao[i]);
    }
    while (aux) {
        if (strcmp(descricao, aux->pos.descricao) == 0)
            return aux;
        aux = aux->prox;
    }
    return NULL;
}

tarefa_no *busca_prazo_dia (tarefa_no *li, int prazo) {
    tarefa_no *aux = li;
    while (aux) {
        if (aux->pos.prazo.dia == prazo)
            return aux;
        aux = aux->prox;
    }
    return NULL;
}

tarefa_no *busca_prazo_mes (tarefa_no *li, int prazo) {
    tarefa_no *aux = li;
    while (aux) {
        if (aux->pos.prazo.mes == prazo)
            return aux;
        aux = aux->prox;
    }
    return NULL;
}

tarefa_no *busca_prazo_ano (tarefa_no *li, int prazo) {
    tarefa_no *aux = li;
    while (aux) {
        if (aux->pos.prazo.ano == prazo)
            return aux;
        aux = aux->prox;
    }
    return NULL;
}

tarefa_no *busca_conclusao_dia (tarefa_no *li, int prazo) {
    tarefa_no *aux = li;
    while (aux) {
        if (aux->pos.conclusao.dia == prazo)
            return aux;
        aux = aux->prox;
    }
    return NULL;
}

tarefa_no *busca_conclusao_mes (tarefa_no *li, int prazo) {
    tarefa_no *aux = li;
    while (aux) {
        if (aux->pos.conclusao.mes == prazo)
            return aux;
        aux = aux->prox;
    }
    return NULL;
}

tarefa_no *busca_conclusao_ano (tarefa_no *li, int prazo) {
    tarefa_no *aux = li;
    while (aux) {
        if (aux->pos.conclusao.ano == prazo)
            return aux;
        aux = aux->prox;
    }
    return NULL;
}

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


//  função para trocar o \n no final da string para \0, para corrigir o problema do fgets no linux, porém não está funcionando direito
// void ler_string(char *nome, int tamanho) {
//     char letra, i = 0;
//     do
//     {
//         letra = getchar ();
//         if(letra != '\n' && i < tamanho - 1)
//         {
//             nome[i] = letra;
//             i++;
//         }
//     }while(letra != '\n');
//     nome[i] = '\0';
// }
