#include "stdlib.h"
#include "stdio.h"
#include "libprg/hexadecimal.h"
// teste
int hexadecimal_para_decimal (char *hexadecimal) {
    long int decimal = strtol(hexadecimal, NULL, 16);
    return decimal;
}

char *decimal_hexadecimal (int decimal) {
    // Buffer para armazenar o resultado em hexadecimal
    char hex[100];
    int i = 0;

    // Caso o número seja zero, o hexadecimal é simplesmente "0"
    if (num == 0) {
        printf("0");
        return;
    }

    // Converte o número decimal para hexadecimal
    while (num != 0) {
        int temp = 0;

        // Calcula o resto da divisão por 16
        temp = num % 16;

        // Converte o resto para o caractere hexadecimal apropriado
        if (temp < 10) {
            hex[i] = temp + 48; // 48 é o código ASCII para '0'
        } else {
            hex[i] = temp + 55; // 55 é o código ASCII para 'A' - 10
        }
        i++;
        num = num / 16;
    }

    // Imprime o hexadecimal em ordem inversa
    printf("Hexadecimal: ");
    for (int j = i - 1; j >= 0; j--) {
        printf("%c", hex[j]);
    }
    printf("\n");
}

void incrementador (char* inicial, char* final) {
    int inicial_1 = hexadecimal_para_decimal(inicial);
    int final_1 = hexadecimal_para_decimal(final);
    for (int i = inicial_1; i <= final_1; i++) {
        inicial_1++;
        printf("%d\n", inicial_1);
    }
}