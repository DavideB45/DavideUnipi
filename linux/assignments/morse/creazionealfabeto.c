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
    int len;
    while(strcmp(line,"fine")){
        getline(line, &max, stdin);
        sscanf(line, "%c:%[^\n]%n\n", alfabet, translated, len);
        morse[i]=strcpy(calloc(len-1, sizeof(char)), translated);
        i++;
        printf("%d %p %s\n", len, morse[i], morse[i]);
    }
}
