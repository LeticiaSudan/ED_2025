#include "fila.h"
#include <time.h>

int main(){
    t_fila *fila = constroi_fila();
    int a;
    srand(time(0));
    do{
        if(rand() % 2 == 0){
            enfileira(rand() % 10, fila);
        }
        else{
            desenfileira(&a, fila);
        }
        mostra_fila(fila);
        printf("\n\\\\\\\\\\\\\\\\\n");
    
    } while(!fila_vazia(fila));
    return 0;
}