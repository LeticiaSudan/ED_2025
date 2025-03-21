//Leia 3 valores de ponto flutuante A, B e C e ordene-os em ordem decrescente, de modo que o lado A representa o maior dos 3 lados. A seguir, determine o tipo de triângulo que estes três lados formam

#include <stdio.h>

int main() {
    float A, B, C;
    
    // Garantir que os valores de A, B e C sejam positivos
    do {
        scanf("%f %f %f", &A, &B, &C);
    } while (A <= 0 || B <= 0 || C <= 0);
    
    // Ordenar os valores de A, B e C em ordem decrescente
    if (A < B) {
        float temp = A;
        A = B;
        B = temp;
    }
    if (A < C) {
        float temp = A;
        A = C;
        C = temp;
    }
    if (B < C) {
        float temp = B;
        B = C;
        C = temp;
    }
    
    // Determinar o tipo de triângulo
    if (A >= B + C) {
        printf("NAO FORMA TRIANGULO\n");
    } else {
        if (A * A == B * B + C * C) {
            printf("TRIANGULO RETANGULO\n");
        } else if (A * A > B * B + C * C) {
            printf("TRIANGULO OBTUSANGULO\n");
        } else if (A * A < B * B + C * C) {
            printf("TRIANGULO ACUTANGULO\n");
        }
        
        if (A == B && B == C) {
            printf("TRIANGULO EQUILATERO\n");
        } else if (A == B || B == C || A == C) {
            printf("TRIANGULO ISOSCELES\n");
        }
    }
    
    return 0;
}
