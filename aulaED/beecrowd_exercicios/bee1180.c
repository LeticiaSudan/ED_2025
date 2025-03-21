#include <stdio.h>
#include <stdlib.h>

// Escreva um programa que leia um número N. Este N é o tamanho de um array X[N]. Em seguida, leia cada um dos números de X, encontre o menor elemento deste array e sua posição dentro do array, imprimindo esta informação.
 //Entrada : A primeira linha de entrada contém um inteiro N (1 < N < 1000), indicando o número de elementos que devem ser lidos para um array X[N] de números inteiros. A segunda linha contém cada um dos N valores, separados por um espaço. Lembre-se de que nenhuma entrada terá números repetidos.
  //Saída : A primeira linha exibe a mensagem "Menor valor:" seguida por um espaço e o menor número lido na entrada. A segunda linha exibe a mensagem "Posicao:" seguida por um espaço e a posição do array em que o menor número está, lembrando que o array começa na posição zero.



int main() {
    int n, *x;
    scanf("%d", &n);
    x = (int *) malloc (n* sizeof(int)); // alocacao dinamica de memoria

    for(int i = 0; i <n; i++) { // Leitura do vetor e de seus numeros
        scanf("%d", &x[i]);
        }
    int menor = x[0];
    int pos = 0;
    for(int i = 1; i<n; i++){ // Comparacao de valores e alocando o menor valor na variavel menor e a posicao deste em pos
        if (x[i] < menor) {
            menor = x[i];
            pos = i;
        }
    }
    printf("Menor valor: %d\n", menor);
    printf("Posicao: %d\n", pos);
    return 0;
}