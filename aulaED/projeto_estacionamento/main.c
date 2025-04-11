#include <stdio.h>
#include <string.h>

typedef struct {
    char placa[7];
    int manobras;
} t_carro;

typedef struct {
    t_carro carros[10];
    int quantidade;
} t_estacionamento;

int estacionar(t_estacionamento* estacionamento, char placa[7]) {
    if (estacionamento->quantidade == 10) return 1;
    
    for (int i = 0; i < estacionamento->quantidade; i++)
        if (strcmp(placa, estacionamento->carros[i].placa) == 0)
            return 2;

    strcpy(estacionamento->carros[estacionamento->quantidade].placa, placa);
    estacionamento->carros[estacionamento->quantidade].manobras = 0;
    estacionamento->quantidade++;

    return 0;
}

int tirar_carro(t_estacionamento* estacionamento, char placa[7]){
    int posicao_carro = -1;
    for (int i = 0; i < estacionamento->quantidade; i++)
        if (strcmp(placa, estacionamento->carros[i].placa) == 0) {
            posicao_carro = i;
            break;
        }
    if (posicao_carro == -1) return 1;

    for (int i = posicao_carro; i < estacionamento->quantidade; i++) {
        estacionamento->carros[i] = estacionamento->carros[i+1];
        estacionamento->carros[i].manobras++;
    }

    estacionamento->quantidade--;

    return 0;
}

int main() {
    t_estacionamento estacionamento = {0};

    while (1) {
        int acao;
        char placa[7];

        printf("Digite a ação e a placa: ");
        scanf("%i %s", &acao, placa);

        if (acao) {
            switch (tirar_carro(&estacionamento, placa)) {
                case 0: printf("Foi tirado do estacionamento!\n"); break;
                case 1: printf("Não está estacionado!\n"); break;
                default: printf("Código desconhecido!\n");
            }
        } else {
            switch (estacionar(&estacionamento, placa)) {
                case 0: printf("Foi estacionado!\n"); break;
                case 1: printf("O estacionamento está cheio!\n"); break;
                case 2: printf("Já está estacionado!\n"); break;
                default: printf("Código desconhecido!\n");
            }
        }

        for (int i = estacionamento.quantidade - 1; i >= 0; i++)
            printf("%s %i\n", estacionamento.carros[i].placa, estacionamento.carros[i].manobras);
    }

    return 0;
}