#include <stdio.h>
int main(){
    
    int a = 23; //variável do tipo int
    //int *p = 6789; //variável do tipo ponteiro de inteiro, não se atribui endereço a uma variável do tipo ponteiro, o SO que faz isso
    int *p = &a; //armazena a posição de "a" na memória
    
    int **x = &p; //ponteiro do ponteiro, armazena o ponteiro p em x
    printf("\na = %d\np = %p\nx = %p\n", a, p, x);

    //*p = 67; errado pois não se pode atribuir valor int pra ponteiro

    /*
    int *j;
    int **k;
    int b = 10;

    k = &j; 
    j = &b;

    *k = &a;*/

    printf("foi");

    return 0;
}