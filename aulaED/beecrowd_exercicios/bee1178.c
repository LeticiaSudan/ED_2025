//Leia um valor X. Coloque este valor na primeira posição de um vetor N[100]. Em cada posição subsequente de N (1 até 99), coloque a metade do valor armazenado na posição anterior, conforme o exemplo abaixo. Imprima o vetor N.

#include <stdio.h>

int main()
{
    double x, N[100];
    scanf("%lf", &x);
    N[0] = x;
    
    //preenche o vetor sempre dividindo o valor anterior por 2
    for(int i = 1; i < 100; i++){
        N[i] = N[i - 1]/2;
    }
    
    for(int i = 0; i < 100; i++){
        printf("N[%i] = %.4lf\n", i, N[i]);
    }

    return 0;
}