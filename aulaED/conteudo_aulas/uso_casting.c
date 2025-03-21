// o "a" não consegue receber o valor de "x", pois "x" é float e "a" um int
//já o "x" consegue receber o valor de "a"

#include <stdio.h>

int main(){
    int a = 5;
    float x = 5.75;

    //a recebe x ERRADO
    a = x;
    printf("a = %d\n", a);

    //x recebe a
    x = a;
    printf("x = %.0f\n", x);

    int m = 17, n = 3;
    int p = m / n;
    printf("divisao = %d\n", p);

    float y = m / p;
    printf("outra divisao: %.2f\n", y); //vai dar um numero inteiro pois os operandos "m" e "p" são do tipo int

    //EXEMPLO DE OPERAÇÃO COM OPERANDOS DE TIPOS DIFERENTES
    int z = 5;
    float o = 10;
    float r = o / z; // para a operacao ser valida eh necessario que 1 das variaveis seja a mesma da operacao final
    printf("o valor e: %.0f", r);

    //EXEMPLO PARA EXIBIR SOMENTE A PARTE DECIMAL
    float d = 5.90;
    float decimal = d - (int)d;
    printf("\no valor decimal e: %.2f", decimal);


    return 0;
}