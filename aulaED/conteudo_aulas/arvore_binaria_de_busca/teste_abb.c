#include "abb.h"
#include <time.h>

int main(){
    t_abb abb;
    inicia_abb(&abb);
    srand(time(0));
    if (abb_vazia(&abb)){
        printf("Arvore inicializada esta vazia!\n");
    }
    else{
        printf("Arvore inicializada, nao esta vazia!\n");
    }

    for(int i = 1; i <= 12; i++){
        int n = rand() % 20;
        printf("%d ", n);
        insere(n, &abb);
    }
    printf("\n");
    imprime(&abb);
    if(busca(10, &abb)){
        printf("\n10 esta na arvore");
    }
    else{
        printf("\n10 nao esta na arvore");
    }
    
    return 0;
}