#ifndef HEXADECIMAL_H
#define HEXADECIMAL_H

typedef struct hexa_t {
    char hexa[20];
    struct hexa_t *prox;
}hexa;

int hexadecimal_para_decimal (char *hexadecimal);
void incrementador (char* inicial, char* final);

#endif //HEXADECIMAL_H
