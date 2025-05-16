#include "fila.h"
#include <time.h>

int main(){
    t_fila *fila = constroi_fila(8);
    int a;
    srand(time(0));
    do{
        if(rand() % 2){
            enfileirar(rand() % 10, fila);
        }
        else{
            desenfileirar(&a, fila);
        }
        mostra_fila(fila);
        mostra_vetor(fila);
    }while(!fila_vazia(fila));

    return 0;
}