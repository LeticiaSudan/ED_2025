#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int * dados;
    int primeiro, ultimo, ocupacao, capacidade;
} t_fila;

t_fila * constroi_fila (int);
int fila_vazia (t_fila *);
int fila_cheia (t_fila *);
int enfileirar (int, t_fila *);
int desenfileirar (int *, t_fila *);
void mostra_fila (t_fila *);
void mostra_vetor (t_fila *);