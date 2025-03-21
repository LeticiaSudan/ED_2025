//Leia 3 valores inteiros e ordene-os em ordem crescente. No final, mostre os valores em ordem crescente, uma linha em branco e em seguida, os valores na sequência como foram lidos.

#include <stdio.h>

int main(){
    //vetor onde serão armazenados os valores originais
    int arrOriginal[3];

    //lendo os valores
    scanf("%d", &arrOriginal[0]);
    scanf("%d", &arrOriginal[1]);
    scanf("%d", &arrOriginal[2]);

    //vetor onde serão armazenados os valores ordenados
    int arrNovo[3];

    //copiando os valores originais para o vetor de ordenação
    for (int i = 0; i < 3; i++) {
        arrNovo[i] = arrOriginal[i];
    }

    //ordenando os valores
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3 - i - 1; j++){
            if(arrNovo[j] > arrNovo[j + 1]){
                int temp = arrNovo[j];
                arrNovo[j] = arrNovo[j + 1];
                arrNovo[j+1] = temp;
            }
        }
    }

    //imprimindo os valores ordenados
    for (int i = 0; i < 3; i++){
        printf("%d\n", arrNovo[i]);
    }
    printf("\n");

    //imprimindo os valores originais
    for (int i = 0; i < 3; i++){
        printf("%d\n", arrOriginal[i]);
    }
    return 0;
}