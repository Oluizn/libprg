#include <ctype.h>

#include "math.h"
#include "string.h"
#include "stdio.h"
#include "stdlib.h"

int hexadecimal_para_decimal (char *num) {
    long int num_decimal = strtol(num, NULL, 16);
    return num_decimal;
}
