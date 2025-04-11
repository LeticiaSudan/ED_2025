#include <stdio.h>

double fat_it (int n){
    double f = 1;
    for(int i = 2; i <= n; i++){
        f = f * i;
    }
    return f;
}

long fat_rec (int n) {
    if(n<=1) return 1;
    return n * fat_rec(n-1);
}

long fibonacci (int n) {
    if(n <= 1) return 1;
    return fibonacci(n-1) + fibonacci(n-2);
}

int main (){
    for(int i = 0; i <= 20; i++){
        printf("fatorial de %d: %.0ld\n", i, fat_it(i));
    }

    for(int i = 0; i <= 20; i++){
        printf("fatorial de %d: %.0ld\n", i, fat_rec(i));
    }

    for(int i = 0; i <=46; i++){
        printf("fibonacci em %d = %.0ld\n", i, fibonacci(i));
    }
}