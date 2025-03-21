//Faça um programa que leia um vetor N[20]. Troque a seguir, o primeiro elemento com o último, o segundo elemento com o penúltimo, etc., até trocar o 10º com o 11º. Mostre o vetor modificado.

#include <stdio.h>

int main()
{
    int N[20], cont;
    cont = 0;
    
    //Lendo os valores do vetor
    for(int i = 0; i < 20; i++){
        scanf("%i", &N[i]);
    }

    //Invertendo os valores do vetor, vai até 10 pois o 11º elemento já foi trocado
    for(int i = 0; i < 10; i++){
        int temp = N[i];
        N[i] = N[19 - cont];
        N[19 - cont] = temp;
        cont = cont + 1;
    }
    
    for(int i = 0; i < 20; i++){
        printf("N[%i] = %i\n", i, N[i]);
    }
    

    return 0;
}
