#include <stdio.h>
#include <stdlib.h>
#include <time.h> //A função time(0) foi usada para gerar uma seed para a função srand(). Isso faz com que os números gerados por rand() sejam diferentes a cada execução do programa, ou seja, torna os números pseudo-aleatórios mais imprevisíveis.

int main(){
    long int tempo = time(0);
    printf("valor retornado pelo time(0): %ld\n", tempo);
    srand(tempo);
    int m = rand();
    int n = rand();
    printf("m = %d\nn = %d\n", m, n);

    printf("de 0 a 10: %d\n", rand()%11);
    return 0;
}

