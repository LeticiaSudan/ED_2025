#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//declaração das funções, isto é, seus protótipos
    void preenche_vetor(int[], int); // aqui foi informado somente o tipo pois não foi necessário nomear
    void exibe_vetor(int[], int, char *); 
    // as duas se referem aos tipos das variáveis v e n, um vetor de inteiros e um inteiro comum, respectivamente
    void bubble_sort (int[], int); 
    int busca_simples(int[], int, int); 
    int conta_ocorrencias(int[], int, int);
    int busca_binaria(int[], int, int);

int main(){

    int *v; // variavel do tipo ponteiro de inteiro que vai receber o endereço de memoria alocada dinamicamente
    int n;
    srand(time(0));
    printf("Escolha o tamanho do vetor, 0 encerra: ");
    scanf("%d", &n);

    //laço para repetir o processo enquanto o tamanho do vetor(n) informado for diferente de 0
    while(n > 0){
        v = (int *) malloc (n* sizeof(int)); //isso é alocação dinâmica de memória, acontece em tempo de execução e não de compilação
        preenche_vetor(v, n); // função para preencher o vetor com valores aleatórios
        bubble_sort (v, n); // função para ordenar os valores
        exibe_vetor(v, n, "Vetor Original: "); // função para exibir esses valores
        int x;
        printf("Digite o valor a ser buscado: ");
        scanf("%d", &x);
        //if (busca_simples(v, n, x) != -1){
        //    printf("O valor %d foi encontrado no endereco %d\n", x, busca_simples(v, n, x));
        //} else {
        //    printf("O valor %d nao foi encontrado\n", x);
        //}
        //printf("O valor %d aparece %d vez(es) no vetor\n", x, conta_ocorrencias(v, n, x));
        //long int ini = time(0); 
        bubble_sort(v, n); //ordena os valores
        if (busca_binaria(v, n, x) == -1){
            printf("O valor %d nao foi encontrado na busca binaria\n", x);
        } else {
            printf("O valor %d foi encontrado no endereco %d, na busca binaria\n", x, busca_binaria(v, n, x));
        } //busca o valor informado
        //long int fim = time(0);
        // exibe_vetor(v, n, "Vetor Ordenado: "); //exibe novamente com os valores ordenados
        // printf ("\ntempo de ordenacao: %ld\n", fim-ini); //exibe o tempo que foi levado para fazer a ordenação
        free(v); //libera a memória que estava sendo ocupada para v, se ela não for liberada vai chegar uma hora que não será mais possível alocar
        printf("\nEscolha o novo tamanho , 0 encerra: ");
        scanf("%d", &n);
    }
    //v = (int *) malloc (n* sizeof(int)); alocação do vetor do tamanho que o usuario escolheu
    // a variavel v é um ponteiro, malloc é uma funcao que aloca memoria, (n*sizeof(int)) - se refere ao tamanho de bloco de memoria que vc quer alocar, n é o que o usuario escolheu, n é quantas caixinhas vc quer alocar na memoria e sizeof(int) seria o tamanho de cada uma dessas caixinhas)
    //(int *) seria a conversão para o tipo inteiro, funcionaria sem esse casting mas as boas práticas recomendam


    return 0;
}

void preenche_vetor(int v[], int n){
    for(int i = 0; i < n; i++){  //laço que percorre cada posição de n(variável que indica o tamanho do vetor)
        //v[i] = rand() % 100;  atribui a cada posição um valor aleatório até 99, pois é % 100 (resto de 100)
        v[i] = rand() % (10 * n); //Parametriza de acordo com o tamanho do vetor (n), diz que vai ser 10x o tamanho n do vetor
        //if(busca_simples(v, i, verificar) == -1){ //verifica se o valor já existe no vetor
            //v[i] = verificar; //se não existir, atribui o valor aleatório
        //} else {
           // i--; //se existir, decrementa o i para que a posição seja preenchida novamente
       // }
    }

}

void exibe_vetor(int v[], int n, char * msg){
    printf("\n%s\n", msg); //parametriza o código, mostra mensagem para exibir o vetor mais organizado
    for(int i = 0; i < n; i++){
        printf("%d " ,v[i]);
        
    }
    printf("\n");
}

void bubble_sort(int v[], int n){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n - i - 1; j ++){
            if(v[j] > v[j + 1]){
                int temp = v[j]; // temp é uma variável temporária para realizar a troca dos valores entre as duas posições
                v[j] = v[j + 1];
                v[j + 1] = temp;
            }
        }
    }
}
//teria como fazer esse bubble sort com for(int i = 1; i < n; i++) e for(int j = 0; j < n - i; j ++), daria no mesmo

int busca_simples(int v[], int n, int x){
    for(int i = 0; i < n; i++){
        if(v[i] == x){
            return i;
        }
    }
    return -1;
}

int conta_ocorrencias(int v[], int n, int x) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (v[i] == x) {
            count++;
        }
    }
    return count;
}

int busca_binaria (int v[], int n, int x){
    int inicio = 0;
    int fim = n - 1;
    while(inicio <= fim){
        int meio = (inicio + fim) / 2;
        if(v[meio] == x){
            return meio;
        } else if (x > v[meio]){
            inicio = meio + 1;
        } else {
            fim = meio - 1;
        }
    }
    return -1;
}