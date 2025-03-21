#include <stdio.h>
#include <stdlib.h>

    typedef struct {
        int *dados;
        int topo;
        int capacidade;      
    } t_pilha; //nome do tipo

    void controi_pilha(int , t_pilha *p);
    int push (int i, t_pilha *p); // empilhar
    int pop (t_pilha *p, int *removido); // desempilhar
    int pilha_vazia(t_pilha *p);
    int pilha_cheia(t_pilha *p);
    void exibe_pilha(t_pilha *p);
