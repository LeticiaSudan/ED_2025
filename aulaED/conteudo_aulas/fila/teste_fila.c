#include "fila.h"

int main(){
    t_fila * fila;
    int *pi = (int *) malloc (sizeof(int));
    fila = constroi_fila(5);
    mostra_fila(fila);
    if(enfileirar(10, fila)){
        printf("insercao realizada com sucesso\n");
    }
    else{
        printf("falha na insercao, fila cheia\n");
    } 
    enfileirar(20, fila);
    mostra_fila(fila);

    if(desenfileirar(pi, fila)){
        printf("%d saiu da fila\n", *pi);
    } 
    else{
        printf("falha no desinfileiramento\n");
    }    
    
    mostra_fila(fila);
    enfileirar(30, fila); 
    enfileirar(40, fila);
    mostra_fila(fila);
    return 0;
}