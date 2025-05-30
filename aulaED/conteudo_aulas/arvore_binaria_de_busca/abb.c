#include "abb.h"

void inicia_abb(t_abb * abb){
    abb->raiz = NULL;
}

int abb_vazia(t_abb * abb){
    return abb->raiz == NULL;
}

void insere(int i, t_abb * abb){
    t_no * novo = constroi_no(i);
    if(abb_vazia(abb)){
        abb->raiz = novo;
    }
    else{
        //busca recursiva para descobrir onde encaixar esse novo nó
        insere_rec (novo, abb->raiz);
    }
}

void insere_rec (t_no * novo, t_no * atual){
    if(novo->info > atual->info){ //vai para direita
        if(atual->dir == NULL){
            atual->dir = novo;
        }
        else{
            insere_rec(novo, atual->dir);
        }
    }
    else{ //vai para esquerda
        if(atual->esq == NULL){
            atual->esq = novo;
        }
        else{
            insere_rec(novo, atual->esq);
        }
    }
}

void imprime_rec(t_no * atual){
    if(atual != NULL){
        imprime_rec(atual->esq); //faz até que atual == NULL, quando isso acontece ele desempilha e começa a exibir as info de cada nó da arvore 
        printf("%d ", atual->info);
        imprime_rec(atual->dir); 
    }
}

void imprime(t_abb * abb){
    if(abb_vazia(abb)){
        printf("Arvore vazia!\n");
    }
    else{
        imprime_rec(abb->raiz);   
    }
}

int busca_rec(int x, t_no * atual){
    if (atual == NULL){
        return 0;
    }
    if(atual->info == x){
        return 1;
    }
    if(x > atual->info){
        return busca_rec(x, atual->dir);
    }
    else{
        return busca_rec(x, atual->esq);
    }
}

int busca(int x, t_abb * abb){
    //devolver 1 (verdadeiro), se x estiver na árvore, ou 0, caso contrário
    if (abb_vazia(abb)){
        return 0;
    }
    else{
        busca_rec(x, abb->raiz);
    }
}