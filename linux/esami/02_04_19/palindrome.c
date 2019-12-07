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
    for(int i = 0; i<size/2; i++){
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
}

void push(LetPtr *headPtr){
    LetPtr newletter = calloc(1, sizeof(Lettera));
    if(newletter==NULL){
        printf("Mem Full\n");
        exit(EXIT_FAILURE);
    } else {
        newletter->ch = getchar();
        *headPtr = newletter;
    }
}

char pop(LetPtr *headPtr){
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
        if(toverify = pop(headPtr)){
            ceck(headPtr);
        } else {
            return 0;
        }
    }
}