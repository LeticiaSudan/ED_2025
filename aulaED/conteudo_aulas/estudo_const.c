#include <stdio.h>

//função que vai somando o valor de a + 1
//quando a função é do tipo void ela não tem return
// const é um valor que não pode ser alterado, é constante
// Não vai funcionar pois const não permite modificação do valor
void f1(const int a){
    // a++;
}

int main(){
    int x =10;

    //função f1 sendo chamada
    f1(x);

    printf("Digite dois inteiro: ");
    int i, j, k;
    j = scanf("%d%d", &i, &k);
    printf("\ni = %d\n j=%d\n k=%d\n", i ,j, k);

    return 0;
}