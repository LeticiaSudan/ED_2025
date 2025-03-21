//Ler um valor N. Calcular e escrever seu respectivo fatorial. 
//A entrada contém um valor inteiro N (0 < N < 13).

#include <stdio.h>

int main()
{
    int N, fatorial;
    fatorial = 1; 
    
    //Ler um valor N.
    while(N < 0 || N > 13){
        scanf("%i", &N);
    }
    
    //Calcular e escrever seu respectivo fatorial.
    for(int i = 1; i <= N; i++){
        fatorial *= i;
    }
    
    printf("%i\n", fatorial);
    
    return 0;
}