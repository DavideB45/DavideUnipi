#include <stdio.h>

void head(size_t dim);
void body(size_t dim);

int main(void){
    size_t hig;
    printf("Inserire un numero positivo maggiore di 2: ");
    while(scanf("%l", hig)!=1 || hig<2){
        printf("Errore nell'input\nInserire un intero positivo maggiore di 2: ");
        while(getchar()!='\n');
    }
    size_t base;
    printf("Inserire un numero positivo dispari maggiore di 2: ");
    while(scanf("%l", base)!=1 || base<2 || base%2==0){
        printf("Errore nell'input\nInserire un intero positivo dispari maggiore di 2: ");
        while(getchar()!='\n');
    }
}