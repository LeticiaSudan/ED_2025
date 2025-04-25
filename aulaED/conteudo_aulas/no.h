#include <stdlib.h>

typedef struct no {
    int info;
    struct no * proximo;
} t_no;

t_no * constroi_no (int);//devolve um ponteiro do tipo t_no, controi_no é o nome da função