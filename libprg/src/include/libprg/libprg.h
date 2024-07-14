#ifndef LIBPRG_LIBPRG_H
#define LIBPRG_LIBPRG_H
#define FILE_NAME "contatos.dat"
#define SIZE 100
#include "stdio.h"

typedef struct {
    double value;
    int error;
} result_t;

typedef enum { SUM, SUB } operation_t;

result_t sub(double a, double b);
result_t sum(double a, double b);
result_t compute(double a, double b, operation_t op);

// struct lista dinamica com nó
struct numero {
    int num;
    struct numero *prox;
};

// struct lista estática
typedef struct T_FILA {
    int dados[3];
    int fim;
}T_FILA;

// declaração das struct para lista ordenada
typedef struct numero numero;
numero* criar_no();
numero *inserir_inicio(numero* li, int valor);
void imprimir_lista(numero *li);

// struct contato para o projeto
struct contact_t {
    char name[61];
    char phone [20];
    char email[251];
};

typedef struct contact_t contact;

// declaração das funções para o projeto lista contatos
void salvar_contato(contact ctt, FILE *file);
int inserir_contato(contact ctt);
int buscar_nome(char *nome_fornecido, char *nome_na_lista, int indexador_inicio, int indexador_limitante);
void deletar_contato(int s);
void editar_contato();
void menu_edicao_exclusao();
void carregar_arquivo();
void mostrar_contatos(int i);
void menu();
void criar_contato();
void contatos_disponiveis();
void buscar_contato();

// declaração das funções de insertion
int* insertion_sort(int* vet, int tamanho);

// declaração das funções de busca em uma lista
int busca_linear (int vet[], int x, int tam);
int busca_binario (int vet[], int tam, int x);
int busca_binaria_recursiva (int vet[], int inicio, int fim, int x);

// declaração das funções de fila
void iniciar_fila(T_FILA* fila);
void inserir_elementos(int dado, T_FILA *fila);
int remover_elemento(int dado, T_FILA *fila);
void imprimir_fila(T_FILA *fila);
#endif
