#include <stdio.h>
#include "no.h"

int main(){
    t_no no1;
    t_no * p_no;
    no1.info = 3;
    no1.proximo = NULL;
    

    p_no = constroi_no(5);
    printf("conteudo do no apontado por p_no: %d\n", p_no->info); //p_no vale 5
    
    no1.proximo = p_no; // no1.proximo aponta para o endereço alocado na função constroi_no
    p_no = &no1; //agora o p_no ta apontando para o no1
    p_no->info = 12;  //muda o valor de 3 para 12
    no1.proximo->info = 20; //agora o 5 vira 20
    return 0;
}