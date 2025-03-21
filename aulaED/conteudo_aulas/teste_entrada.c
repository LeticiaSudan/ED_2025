#include <stdio.h>

//stdin = standard input
//stdout = standard output
// ler uma sequencia de numeros, ate encontrar o EOF, soma-los e exibir a soma.

int main() {
    int a, b, n;

    // printf("Digite dois numeros: ");
    // n = scanf("%d%d", &a, &b);
    // printf("\nn = %d\n", n); devolve quantos numeros foram lidos com sucesso
    // teste < entrada.txt (redireciona o arquivo de entrada para o programa) > saida.txt (redireciona o arquivo de saida para o programa)

    while ((scanf("%d", &a)) != EOF) { //EOF = End Of File
        printf("%d\n", a);
    }
    printf("Fim\n");
    return 0;
}