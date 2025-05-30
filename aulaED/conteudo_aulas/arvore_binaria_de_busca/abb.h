#include "no.h"

typedef struct {
    t_no * raiz;

} t_abb; //bst - binary search tree

void inicia_abb(t_abb *);
int abb_vazia(t_abb *);
void insere(int, t_abb *);
void insere_rec(t_no *, t_no *);
void imprime(t_abb *);
void imprime_rec(t_no *);
int busca(int, t_abb *);
int busca_rec(int, t_no *);