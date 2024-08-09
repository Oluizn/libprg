#include "libprg/projeto2.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "time.h"

int salvar_lista(tarefa_no *li) {
    FILE *file = fopen(FILE_NAME, "wb");
    if (file) {
        tarefa_no *aux = li;
        while (aux) {
            fwrite(&aux->pos.codigo, sizeof(int), 1, file);
            fwrite(aux->pos.descricao, sizeof(char), strlen(aux->pos.descricao), file);
            fwrite(&aux->pos.prioridade, sizeof(int), 1, file);
            fwrite(&aux->pos.prazo.dia, sizeof(int), 1, file);
            fwrite(&aux->pos.prazo.mes, sizeof(int), 1, file);
            fwrite(&aux->pos.prazo.ano, sizeof(int), 1, file);
            fwrite(&aux->pos.conclusao.dia, sizeof(int), 1, file);
            fwrite(&aux->pos.conclusao.mes, sizeof(int), 1, file);
            fwrite(&aux->pos.conclusao.ano, sizeof(int), 1, file);
            fwrite(aux->pos.status, sizeof(char), strlen(aux->pos.status), file);
            aux = aux->prox;
        }
        fclose(file);
        return 0;
    }
    else {
        exit(0);
    }
}

int carregar_lista (tarefa_no *li) {
    FILE *file = fopen("FILE_NAME", "rb");
    if (file) {
        while (!feof(file)) {
            li = inserir_tarefa(li, "", 0, 0, 0, 0);
            fread(&li->pos.codigo, sizeof(int), 1, file);
            fread(li->pos.descricao, sizeof(char), strlen(li->pos.descricao), file);
            fread(&li->pos.prioridade, sizeof(int), 1, file);
            fread(&li->pos.prazo.dia, sizeof(int), 1, file);
            fread(&li->pos.prazo.mes, sizeof(int), 1, file);
            fread(&li->pos.prazo.ano, sizeof(int), 1, file);
            fread(&li->pos.conclusao.dia, sizeof(int), 1, file);
            fread(&li->pos.conclusao.mes, sizeof(int), 1, file);
            fread(&li->pos.conclusao.ano, sizeof(int), 1, file);
            fread(li->pos.status, sizeof(char), strlen(li->pos.status), file);
        }
        fclose(file);
        return 0;
    }
    else
        return 1;
}

tarefa_no *criar_no(){
    tarefa_no *novo = (tarefa_no *) malloc(sizeof (tarefa_no));
    if (novo == NULL) {
        exit(0);
    }
    return novo;
}

tarefa_no *inserir_tarefa(tarefa_no *li, char *descricao, int indice_prioridade, int dia, int mes, int ano){
    tarefa_no *aux = li, * novo_no = criar_no();
    strcpy(novo_no->pos.descricao, descricao);
    novo_no->pos.prazo.dia = dia;
    novo_no->pos.prazo.mes = mes;
    novo_no->pos.prazo.ano = ano;
    strcpy(novo_no->pos.status, "Nao concluida");
    novo_no->pos.conclusao.ano = 0;
    novo_no->pos.conclusao.mes = 0;
    novo_no->pos.conclusao.ano = 0;
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
