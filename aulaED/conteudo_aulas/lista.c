#include "lista.h"


void constroi_lista(t_lista *lista){
    lista->primeiro = lista->ultimo = NULL; // coloca null para primeiro e ultimo
}

int lista_vazia (t_lista *lista){
    if(lista->primeiro == NULL) return 1;
    return 0;
}

void insere_inicio (int i, t_lista *lista){
    t_no * novo = constroi_no(i);
    if(lista_vazia(lista))
        lista->ultimo = novo;
    else
        novo->proximo = lista->primeiro;
        lista->primeiro = novo;
}

int remove_inicio (t_lista *lista){
    if(lista_vazia(lista)) return -1;
    int temp = lista->primeiro->info; // recebe uma copia do valor de info
    t_no *aux = lista->primeiro; // aux aponta para o endereço do primeiro
    lista->primeiro = lista->primeiro->proximo; //primeiro aponta para o proximo
    if(lista->primeiro == NULL) //esvaziou a lista
        lista->ultimo = NULL;
    free(aux);
    return temp; 
}

void mostra_lista (t_lista *lista){
    if(lista_vazia(lista)) printf("Lista vazia\n");
    else{
        t_no *runner = lista->primeiro;
        while(runner != NULL){
            printf("[%d] -> ", runner->info);
            runner = runner->proximo;
        }
    }
}

void insere_fim (int i, t_lista *lista){
    t_no *novo = constroi_no(i);
    if(lista_vazia(lista)) lista->primeiro = novo;
    else lista->ultimo->proximo = novo;
    lista->ultimo = novo;
}

int remove_fim (t_lista *lista){
    int temp;
    //cenário 1: lista vazia
    if(lista_vazia(lista)) return -1;
    //cenário 2: lista tem um elemento só
    if(lista->primeiro == lista->ultimo){
        temp = lista->primeiro->info;
        free(lista->primeiro);
        lista->primeiro = lista->ultimo = NULL;
    }
    else{
        //cenário 3: lista tem mais que um elemento
        t_no * runner = lista->primeiro;
        while (runner->proximo != lista->ultimo) //Encontrar o penúltimo
            runner = runner->proximo;
        temp = lista->ultimo->info;
        free(lista->ultimo);
        runner->proximo = NULL;
        lista->ultimo = runner;
    }
    return temp;
}