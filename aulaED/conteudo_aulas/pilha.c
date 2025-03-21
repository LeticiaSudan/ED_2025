#include "pilha.h"

void controi_pilhar(int capacidade, t_pilha *p){
    p->dados = (int*) malloc(capacidade * sizeof(int));
    p->topo = 0;
    p->capacidade = capacidade;
}
int pilha_vazia(t_pilha *p) {
    if (p->topo == 0){
        return 1;
    } else {
        return 0;
    }
}
int pilha_cheia(t_pilha *p) {
    if (p->topo == p->capacidade){
        return 1;
    } else {
        return 0;
    }
}
int push (int i, t_pilha *p){
    if (pilha_cheia(p)) return 0;
    p->dados[p->topo++] = i;
    return 1;  
    } 
    
int pop (t_pilha *p, int *removido) {
    if (pilha_vazia(p)) return 0;
    *removido = p->dados[--p->topo];
    return 1;
}

void exibe_pilha(t_pilha *p);
