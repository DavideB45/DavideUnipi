#include <stdio.h>

void head(int b, int h);
void body(int b, int h);

int main(void){
    int hig;
    printf("Inserire un intero positivo maggiore di 2: ");
    while(scanf("%d", &hig)!=1 || hig<3){
        printf("Errore nell'input\nInserire un intero positivo maggiore di 2: ");
        while(getchar()!='\n');
    }
    int base;
    printf("Inserire un numero positivo dispari maggiore di 2: ");
    while(scanf("%d", &base)!=1 || base<3 || base%2==0){
        printf("Errore nell'input\nInserire un intero positivo dispari maggiore di 2: ");
        while(getchar()!='\n');
    }
    head(base, hig%2);
    body(base, hig%2);
}

void head(int b, int h){
    int space = 0;
    for(int i = 0; i < h; i++){
        for(int j = 0; j < space; j++){
            printf(" ");
        }
        printf("*");
        for(int j = 0; j < b - space; j++){
            printf(" ");
        }
        space++;
        printf("*\n");
    }
}