// Para comentar tudo selecionado -> ctrl + ;

#include <stdio.h>
#include <stdlib.h>

// argc = argument counter (conta a posição do array)
// argv = argument vector/values (exibe a string que está na respectiva posição argc do array)
int main(int argc, char * argv[]) {   // * pertence a variável e não ao seu tipo, define o vetor como string

    int i, soma;
    // for(i= 0; i<argc; i++){
    //     printf("argumento %d: %s\n", i, argv[i]);
    // } 

    for(i=1, soma= 0; i<argc; i++){
        soma = soma + atoi(argv[i]);
    }
    i = printf("%d\n", soma);

    return 0;
}