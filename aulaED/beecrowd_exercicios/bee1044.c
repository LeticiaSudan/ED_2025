// Leia 2 valores inteiros (A e B). Após, o programa deve mostrar uma mensagem "Sao Multiplos" ou "Nao sao Multiplos", indicando se os valores lidos são múltiplos entre si.

#include <stdio.h>

int main() {
    int a, b;
    
    scanf("%d", &a);
    
    scanf("%d", &b);
    
    //verificando se a é maior ou igual a b
    if (a >= b) {
        //se sim verifico se a é múltiplo de b
        if (a % b == 0) {
            printf("Sao Multiplos\n");
        } else {
            printf("Nao sao Multiplos\n");
        }
        //senão é porque b é maior ou igual a
    } else {
        //se não verifico se b é múltiplo de a
        if (b % a == 0) {
            printf("Sao Multiplos\n");
        } else {
            printf("Nao sao Multiplos\n");
        }
    }

    return 0;
}