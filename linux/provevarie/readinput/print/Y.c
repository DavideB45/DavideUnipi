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
    head(base, hig);
    body(base, hig);
}

void head(int b, int h){
    int space = 0;
    for(int i = 0; i < h/2+1; i++){
        for(int j = 0; j < space; j++){
            printf(" ");
        }
        printf("*");
        for(int z = 0; z < b - space; z++){
            printf(" ");
        }
        space++;
        b--;
        printf("*\n");
    }
}

void body(int b, int h){
    for(int i = 0; i<h/2+1; i++){
        for(int j = 0; j<b/2; j++){
            printf(" ");
        }
        printf(" *\n");
    }
}