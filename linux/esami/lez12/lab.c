#include <stdio.h>
#include <stdlib.h>

typedef struct stud{
    int matricola;
    struct stud *nextPtr;
}stud;
typedef stud *corso;

void getiscritti(corso *corrPtr, int precMatricola);
void remduplicate(corso *corrPtr);
void printlist(corso corrPtr);
void filter(corso *primoAnno, corso secondoAnno);
void dealloc(corso *corrPtr);

int main(void){
    corso primoAnno = NULL;
    corso secondoAnno = NULL;
    
    getiscritti(&primoAnno, 0);
    printf("Primo elenco\n");
    printlist(primoAnno);
    remduplicate(&primoAnno);
    printf("Primo elenco senza duplicati\n");
    printlist(primoAnno);
    
    getiscritti(&secondoAnno, 0);
    printf("Second elenco\n");
    printlist(secondoAnno);
    remduplicate(&secondoAnno);
    printf("Second elenco senza duplicati\n");
    printlist(secondoAnno);
    
    filter(&primoAnno, secondoAnno);
    
    printf("elenco finale\n");
    printlist(primoAnno);
    //dealloc(&secondoAnno);
    /**/
    return EXIT_SUCCESS;
}

void getiscritti(corso *corrPtr, int precMatricola){
    int newMatricola;
    scanf("%d", &newMatricola);
    if(precMatricola <= newMatricola){
        *corrPtr = malloc(sizeof(stud));
        if(*corrPtr==NULL){
           printf("Memory full\n");
            exit(1);
        } else {
            (*corrPtr)->matricola = newMatricola;
            (*corrPtr)->nextPtr = NULL;
            getiscritti(&((*corrPtr))->nextPtr, (*corrPtr)->matricola);
        }
    }
}

void printlist(corso corrPtr){
    printf("(");
    while(corrPtr!=NULL){
        printf("%d ", corrPtr->matricola);
        corrPtr = corrPtr->nextPtr;
    }
    printf(")\n");
}

void remduplicate(corso *headPtr){
    if((*headPtr)==NULL){
        return;
    }
    corso corrPtr = *headPtr;
    corso nextPtr = corrPtr->nextPtr;
    corso precPtr = NULL;
    while(nextPtr!=NULL){
        if(corrPtr->matricola == nextPtr->matricola){
            if(precPtr==NULL){
                *headPtr = nextPtr;
                free(corrPtr);
            } else {
                free(corrPtr); 
                precPtr->nextPtr = nextPtr; 
            }
            corrPtr = nextPtr;
            nextPtr = nextPtr->nextPtr;
        } else {
            precPtr = corrPtr;
            corrPtr = nextPtr;
            nextPtr = nextPtr->nextPtr;
        }
    }
}

void filter(corso *primoAnno, corso secondoAnno){
    if(*primoAnno!=NULL && secondoAnno!=NULL){
        if((*primoAnno)->matricola == secondoAnno->matricola){
            corso delCorso = *primoAnno;
            *primoAnno = (*primoAnno)->nextPtr;
            free(delCorso);
            filter(primoAnno, secondoAnno->nextPtr);
        } else {
            if((*primoAnno)->matricola < secondoAnno->matricola){
                filter(&((*primoAnno)->nextPtr), secondoAnno);
            } else {
                filter(primoAnno, secondoAnno->nextPtr);
            }
        }
    }
}

void dealloc(corso *corrPtr){
    if(*corrPtr!=NULL){
        dealloc(&( (*corrPtr)->nextPtr ));
        free(*corrPtr);
    }
}