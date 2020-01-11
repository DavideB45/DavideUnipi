#include <stdio.h>

int sum(void);

int main(void){
    int somma;
    for (size_t i = 0; i < 5; i++){
        somma = sum();
        printf("%3d\n", somma);
    }
    return 0;
}

int sum(void){
    static int somma;
    int numero;
    scanf("%d", &numero);
    somma += numero;
}