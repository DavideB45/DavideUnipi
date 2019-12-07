#include <stdio.h>
#include <stdlib.h>

typedef struct lettera{
    char ch;
    struct lettera *nextPtr;
} Lettera;
typedef Lettera * LetPtr;

char pop(LetPtr *headPtr);
void push(LetPtr *headPtr);
_Bool ceck(LetPtr *headPtr);

int main(void){
    int size;
    LetPtr headPtr = NULL;
    if(scanf("%d", &size)!=1 || size<0){
        printf("Errore nell' input\n");
        return 0;
    }
    while(getchar()!='\n');
    int i;
    for(i = 0; i<size/2; i++){
        push(&headPtr);
    }
    if(size%2==1){
        getchar();
    }
    if(ceck(&headPtr)){
        printf("Stringa palindroma\n");
    } else {
        printf("Stringa non palindroma\n");
    }
    return 0;
}

void push(LetPtr *headPtr){
    LetPtr newletter = calloc(1, sizeof(Lettera));
    if(newletter==NULL){
        printf("Mem Full\n");
        exit(EXIT_FAILURE);
    } else {
        newletter->nextPtr = *headPtr;
        newletter->ch = getchar();
        *headPtr = newletter;
    }
}

char pop(LetPtr *headPtr){
    if(*headPtr==NULL){
        printf("stringa piu' lunga di quanto aspettato\n");
        exit(EXIT_FAILURE);
    }
    LetPtr tofree = *headPtr;
    char ch = tofree->ch;
    *headPtr = tofree->nextPtr;
    free(tofree);
    return ch;
}

_Bool ceck(LetPtr *headPtr){
    char toverify = getchar();
    if(toverify=='\n'){
        return 1;
    } else {
        char x = pop(headPtr);
        if(toverify == x){
            printf("%c = %c\n", toverify, x);
            return ceck(headPtr);
        } else {
            printf("%c = %c", toverify, x);
            return 0;
        }
    }
}