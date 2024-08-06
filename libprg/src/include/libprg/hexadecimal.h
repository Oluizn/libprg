#ifndef HEXADECIMAL_H
#define HEXADECIMAL_H

typedef struct num {
    char hexadecimal[25];
    struct num *prox;
}num_hexacimal;

int hexadecimal_para_decimal (char *num);


#endif //HEXADECIMAL_H
