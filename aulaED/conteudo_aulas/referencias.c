#include <stdio.h>

int main(){
    int a = 100;
    printf("valor de a (decimal) = %d\n", a);
    printf("valor de a (hexadecimal) = %x\n", a);
    printf("endereco de a = %p\n", &a); // aqui por conta do & será exibido o endereço de memória de a
    printf("caracter equivalente de a: %c\n", a);
    //printf("string de a: %s\n", a); erro de acesso à memória
    printf("string da referencia de a: %s\n", &a);

    return 0;
}