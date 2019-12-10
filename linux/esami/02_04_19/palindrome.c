#include <stdio.h>
#include <stdlib.h>


typedef struct lettera{
    char ch;
    struct lettera *nextPtr;
} Lettera;
typedef Lettera * LetPtr;


char pop(LetPtr *headPtr);//restituisce l'elemem=nto in testa alla lista
void push(LetPtr *headPtr);//aggiunge un elemento in testa alla lsta
_Bool check(LetPtr *headPtr);//controlla che la parola sia palindroma

int main(void){
    int size;//dimensione della parola
    LetPtr headPtr = NULL;
    if(scanf("%d", &size)!=1 || size<0){
        printf("Errore nell' input\n");
        return 0;
    }
    while(getchar()!='\n');
    int i;
    for(i = 0; i<size/2; i++){
        push(&headPtr);//aggiunta in testa
    }
    //se il numero di lettere e' dispari ne salto una
    if(size%2==1){
        getchar();
    }
    //verifica della stringa
    if(check(&headPtr)){
        printf("Stringa palindroma\n");
    } else {
        printf("Stringa non palindroma\n");
    }
    return 0;
}

void push(LetPtr *headPtr){
    LetPtr newletter = calloc(1, sizeof(Lettera));
    if(newletter==NULL){//controllo che vi sia memoria disponibile
        printf("Mem Full\n");
        exit(EXIT_FAILURE);
    } else {//aggiunge un elemento in testa
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
    LetPtr tofree = *headPtr;//nodo da restituire
    char ch = tofree->ch;
    *headPtr = tofree->nextPtr;
    free(tofree);
    return ch;//valore contenuto nel nodo
}

_Bool check(LetPtr *headPtr){
    char toverify = getchar();
    if(toverify=='\n'){
        return 1;//la parola e' palindroma
    } else {
        if(toverify == pop(headPtr)){
            return check(headPtr);//chiamata ricorsiva
        } else {
            return 0;//la parola non e' palindroma
        }
    }
}