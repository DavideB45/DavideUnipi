#include <stdio.h>

int main(void){
    int num ;
    printf("Metti un numero intero :\t");
    while(scanf("%d", &num)!=1){
        printf("Che caxxo fai!\nMetti un numero :\t");
        while(getchar()!='\n');
    }
    printf("hai messo %d\n", num);
    return 0;
}