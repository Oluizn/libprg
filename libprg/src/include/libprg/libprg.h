#ifndef LIBPRG_LIBPRG_H
#define LIBPRG_LIBPRG_H

typedef struct {
    double value;
    int error;
} result_t;

typedef enum { SUM, SUB } operation_t;

result_t sub(double a, double b);
result_t sum(double a, double b);
result_t compute(double a, double b, operation_t op);

struct numero {
    int num;
    struct numero *prox;
};

typedef struct numero numero;
numero* criar_no();
numero *inserir_inicio(numero* li, int valor);
void imprimir_lista(numero *li);

#endif
