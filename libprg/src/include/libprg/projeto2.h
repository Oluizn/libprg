#ifndef PROJETO2_H
#define PROJETO2_H
#include "stdio.h"

typedef struct task {
    int code
    char description;
    char priority_level;
    char deadline;
} task;

typedef struct node {
    struct tast;
    struct node *next;
};
#endif //PROJETO2_H
