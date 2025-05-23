#include "lista.h"

int main () {
    t_lista lista;
    constroi_lista (&lista);
    for (int i=1; i<=10; i++) {
        insere_inicio(i, &lista);
    }
    mostra_lista (&lista);
    while (!lista_vazia(&lista)) {
        printf ("%d saiu do inicio\n", remove_inicio(&lista));
        mostra_lista(&lista);
    }
    for (int i=1; i<=10; i++) {
        insere_fim(i, &lista);
    }
    mostra_lista (&lista);

    while (!lista_vazia(&lista)) {
        printf ("%d saiu do final\n", remove_fim(&lista));
        mostra_lista(&lista);
    }
    return 0;
}