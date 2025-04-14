#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAMANHO_ESTACIONAMENTO 10

typedef struct {
    char placa[8];
    int manobras;
} carro;

typedef struct {
    carro *carros;
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

    processar_arquivo("entradas0.txt", &e);

    exibir_manobras(&e);

    free(e.carros);
    return 0;
}

void criar_pilha_estacionamento(estacionamento *e) {
    e->carros = (carro *)malloc(TAMANHO_ESTACIONAMENTO * sizeof(carro));
    if (e->carros == NULL) {
        printf("Erro ao alocar memória\n");
        exit(1);
    }
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
        printf("Estacionamento cheio\n");
        return 0;
    }
    e->topo++;
    strncpy(e->carros[e->topo].placa, placa, 7);
    e->carros[e->topo].placa[7] = '\0'; 
    e->carros[e->topo].manobras = 0;
    return 1;
}

int retirar_carro(estacionamento *e, char placa[7]) {
    if (pilha_vazia(e)) {
        printf("Estacionamento vazio\n");
        return 0;
    }

    int encontrado = -1;
    for (int i = e->topo; i >= 0; i--) {
        if (strncmp(e->carros[i].placa, placa, 7) == 0) {
            encontrado = i;
            break;
        }
    }

    if (encontrado == -1) {
        printf("Carro %s não encontrado\n", placa);
        return 0;
    }

    carro temp_carros[TAMANHO_ESTACIONAMENTO];
    int temp_topo = -1;

   
    while (e->topo > encontrado) {
        temp_carros[++temp_topo] = e->carros[e->topo];
        temp_carros[temp_topo].manobras++; 
        printf("Carro %s foi temporariamente removido. Total de manobras: %d\n",
               temp_carros[temp_topo].placa, temp_carros[temp_topo].manobras);
        e->topo--;
    }

  
    printf("Carro %s retirado. Total de manobras: %d\n", e->carros[e->topo].placa, e->carros[e->topo].manobras);
    e->topo--;

   
    while (temp_topo >= 0) {
        e->topo++;
        e->carros[e->topo] = temp_carros[temp_topo--];
    }

    return 1;
}

void exibir_pilha(estacionamento *e) {
    if (pilha_vazia(e)) {
        printf("A pilha está vazia.\n");
        return;
    }

    printf("Estado atual da pilha (do topo para a base):\n");
    for (int i = e->topo; i >= 0; i--) {
        printf("Placa: %s\n", e->carros[i].placa);
    }
    printf("\n");
}

void exibir_manobras(estacionamento *e) {
    if (pilha_vazia(e)) {
        printf("Nenhum carro no estacionamento.\n");
        return;
    }

    printf("Resumo de manobras:\n");
    for (int i = e->topo; i >= 0; i--) {
        printf("Carro %s fez %d manobras\n", e->carros[i].placa, e->carros[i].manobras);
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
            if (estacionar(e, placa)) {
                printf("Carro com placa %s estacionado.\n", placa);
            } else {
                printf("Estacionamento cheio. Carro com placa %s não entrou.\n", placa);
            }
        } else if (operacao == '1') {
            if (!retirar_carro(e, placa)) {
                printf("Carro com placa %s não está no estacionamento.\n", placa);
            }
        } else {
            printf("Operação inválida: %c\n", operacao);
        }

        exibir_pilha(e);
    }

    fclose(arquivo);
}
