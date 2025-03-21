#include <stdio.h>
int main(){

    int v[5], i;

    for(i=0; i<5000; i++){ //problema de acesso à memória, pois a condição de i é muito superior ao tamanho do vetor
        v[i] = i;
        printf("posicao %d tem o valor %d\n", i, v[i]);
    }

    return 0;
}