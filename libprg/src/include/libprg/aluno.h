#ifndef ALUNO_H
#define ALUNO_H

typedef struct aluno {
    int matricula;
    char nome[30];
    float n1, n2, n3;
}aluno;


typedef struct elemento {
    aluno dados;
    struct elemento *prox;
}elemento;

#endif //ALUNO_H
