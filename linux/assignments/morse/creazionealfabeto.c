#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct lettera{
    char *traduzione;
    struct lettera *prossimoPtr;
}lettera;

void readAlfabet(char *alfabet,char *morse[]);

int main(void){
    char alfabet[36];
    char *morse[36];
    int i = 0;
    readAlfabet(alfabet, morse);
}

void readAlfabet(char *alfabet,char *morse[]){
    char line[10];
    char translated[8];
    int i =0, max = 10;
    int len = 10;
    while(strcmp(line,"fine")){
        scanf("%c:%[^\n]%*c", &alfabet[i], translated);
        morse[i]=strcpy(calloc(len-1, sizeof(char)), translated);
        printf("%c %d %p %s\n",alfabet[i], len, morse[i], morse[i]);
        i++;
    }
}
