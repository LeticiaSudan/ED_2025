#include <stdio.h>
#include "C:\Users\aluno\Desktop\ED_2025\aulaED\conteudo_aulas\lista_ligada\no.h"

typedef struct {
    t_no * primeiro;
    t_no * ultimo;
} t_fila;

t_fila * constroi_fila (int);
int fila_vazia (t_fila *);

int enfileira (int, t_fila *);
int desenfileira (int *, t_fila *);
void mostra_fila (t_fila *);
