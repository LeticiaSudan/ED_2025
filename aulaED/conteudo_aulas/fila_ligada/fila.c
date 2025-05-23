#include "fila.h"

t_fila * constroi_fila (){
    t_fila * pf = (t_fila *) malloc (sizeof(t_fila));
    pf->primeiro = NULL;
    pf->ultimo = NULL;
    return pf;
}

int fila_vazia (t_fila *pf){
    return pf->primeiro == NULL;
}

int enfileira (int i, t_fila *pf){
    t_no * novo = constroi_no(i);
    if(novo ==NULL){ //alocação de memória falhou
        return 0;
    }
    if(fila_vazia(pf)){
        pf->primeiro = novo;
    }
    else{
        pf->ultimo->prox = novo;    
    }
    pf->ultimo = novo;
    return 1;
}

int desenfileira (int *i, t_fila *pf){
    if(fila_vazia(pf)){
        return 0;
    }
    *i = pf->primeiro->info;
    t_no * aux = pf->primeiro;
    pf->primeiro = pf->primeiro->prox;
    if(pf->primeiro == NULL){  //esvaziou a fila
        pf->ultimo = NULL;
    }
    free(aux);
    return 1;
}

void mostra_fila (t_fila *pf){
    if(fila_vazia(pf)){
        printf("Fila vazia!");
    }
    else{
        t_no * aux = pf->primeiro;
        while(aux != NULL){
            printf("%d ", aux->info);
            aux = aux->prox;
        }
    }
}

void exibe_primeiro(t_fila *pf){
    if(fila_vazia(pf)){
        printf("Fila vazia!\n");
    }
    else{
        printf("%d\n", pf->primeiro->info);
    }
}

int devolve_primeiro(t_fila *pf){
    if(fila_vazia(pf)){
        return -1;
    }
    return pf->primeiro->info;
}

void exibe_ultimo(t_fila *pf){
    if(fila_vazia(pf)){
        printf("Fila vazia!\n");
    }
    else{
        printf("%d\n", pf->ultimo->info);
    }
}

int devolve_ultimo(t_fila *pf){
    if(fila_vazia(pf)){
        return -1;
    }
    return pf->ultimo->info;
}