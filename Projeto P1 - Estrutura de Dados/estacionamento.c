#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAMANHO_ESTACIONAMENTO 10

typedef struct {
    char placa[8];
    int manobras;
} carro;

typedef struct {
    carro carros[10];
    int topo;
    
} estacionamento;

void criar_pilha_estacionamento(estacionamento *e);
int pilha_vazia(estacionamento *e);
int pilha_cheia(estacionamento *e);
int estacionar(estacionamento *e, char placa[7]);
int retirar_carro(estacionamento *e, char placa[7]);
void exibir_pilha(estacionamento *e);
void exibir_manobras(estacionamento *e);
void processar_arquivo(const char *nome_arquivo, estacionamento *e);

int main() {
    estacionamento e;
    criar_pilha_estacionamento(&e);

    processar_arquivo("entradas.txt", &e);

    return 0;
}

void criar_pilha_estacionamento(estacionamento *e) {
    e->topo = -1;
}

int pilha_vazia(estacionamento *e) {
    return e->topo == -1;
}

int pilha_cheia(estacionamento *e) {
    return e->topo == TAMANHO_ESTACIONAMENTO - 1;
}

int estacionar(estacionamento *e, char placa[7]) {
    if (pilha_cheia(e)) {
        return 1;
    }

    for(int i = 0; i <= e->topo; i++){
        if(strcmp(e->carros[i].placa, placa) == 0){
            return 2;
        }
    }

    e->topo++;
    strcpy(e->carros[e->topo].placa, placa);
    e->carros[e->topo].manobras = 0;

    return 0;
}

int retirar_carro(estacionamento *e, char placa[7]) {
    if (pilha_vazia(e)) {
        return 1;
    }

    int encontrado = -1;
    for (int i = e->topo; i >= 0; i--) {
        if (strcmp(e->carros[i].placa, placa) == 0) {
            encontrado = i;
            break;
        }
    }

    if (encontrado == -1) {
        return 2;
    }

    carro temp_carros[TAMANHO_ESTACIONAMENTO];
    int temp_topo = -1;

   
    while (e->topo > encontrado) {
        temp_carros[++temp_topo] = e->carros[e->topo];
        temp_carros[temp_topo].manobras++; 
        e->topo--;
    }

    e->topo--;

   for (; temp_topo >= 0; temp_topo--) {
        e->topo++;
        e->carros[e->topo] = temp_carros[temp_topo];
   }

    return 0;
}

void exibir_pilha(estacionamento *e) {
    if (pilha_vazia(e)) {
        printf("A pilha esta vazia.\n");
        printf("\n");
        return;
    }

    printf("Estado atual da pilha (do topo para a base):\n");
    for (int i = e->topo; i >= 0; i--) {
        printf("Placa: %s   Manobras: %i\n", e->carros[i].placa, e->carros[i].manobras);
    }
    printf("\n");
}

void processar_arquivo(const char *nome_arquivo, estacionamento *e) {
    FILE *arquivo = fopen(nome_arquivo, "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo de entradas.\n");
        exit(1);
    }

    char operacao;
    char placa[8];

    while (fscanf(arquivo, " %c %s", &operacao, placa) != EOF) {
        if (operacao == '0') {
            switch (estacionar(e, placa)) {
                case 0: printf("Carro com placa %s estacionado.\n", placa);break;
                case 1: printf("A pilha esta cheia\n");break;
                case 2: printf("Carro com a placa %s ja esta estacionado\n", placa);break;
                default: printf("Erro desconhecido\n");
            }
        } else if (operacao == '1') {
            switch (retirar_carro(e, placa)){
                case 0: printf("Carro com a placa %s foi retirado com sucesso!\n", placa);break;
                case 1: printf("Estacionamento esta vazio\n");break;
                case 2: printf("Carro com a placa %s nao foi encontrado\n", placa);break;
                default: printf("Erro desconhecido\n");
            }
        } else {
            printf("Operacao invalida: %c\n", operacao);
        }

        exibir_pilha(e);
    }

    fclose(arquivo);
}
