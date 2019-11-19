#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct alunno{
    int voti;
    char *nome;
    struct alunno *nextPtr; 
}alunno;
typedef alunno *alunnoPtr;

alunnoPtr insertnewname(char nome[]);
void addvote(alunnoPtr *startPtr, FILE **fPtr);
char* assignvalue(char array[]);
char* assegnanome(char array[]);
void printlist(alunnoPtr startPtr);
void cercavincitori(alunno *primo, alunno *secondo, alunnoPtr correntePtr);
void assegnastruct(alunnoPtr vecchio, alunnoPtr nuovoPtr);


int main(void){
	FILE *fPtr = NULL;
    if((fPtr = fopen("input.txt", "r"))==NULL){
        printf("file non trovato\n");
        exit(1);
    }
    else{
        alunnoPtr startPtr = NULL;
        while(!feof(fPtr)){ 
            addvote(&startPtr, &fPtr);
        }
        fclose(fPtr);
        printlist(startPtr);
        alunno secondo;
        alunno primo;
        cercavincitori(&primo, &secondo, startPtr);
        printf("%s con %d voti\n", primo.nome, primo.voti);
        printf("%s con %d voti\n", secondo.nome, secondo.voti);
    }
}


alunnoPtr insertnewname(char newname[]){
    alunnoPtr tempPtr = malloc(sizeof(alunno));
    if(tempPtr == NULL){
        printf("memoria esaurita\n");
        return NULL;
    }
    tempPtr->nome = assegnanome(newname);
    tempPtr->voti = 1;
    tempPtr->nextPtr = NULL;
    return tempPtr;
}

char* assegnanome(char array[]){
    int dim = 0;
    do{
        dim++;
    }while(array[dim]!='\0');
    char *temparray = malloc(dim*sizeof(char));
    return strcpy(temparray, array);
}

void addvote(alunnoPtr *startPtr, FILE **fPtr){
    char nome[2][9];
    fscanf(*fPtr, "%[^,],%s\n", nome[0], nome[1]);
    if((*startPtr)==NULL){
        *startPtr = insertnewname(nome[1]);
        (*startPtr)->nextPtr = insertnewname(nome[0]);
    }
    else{
        alunnoPtr correntePtr;
        alunnoPtr precPtr;
        for(int i = 0; i<2; i++){
            correntePtr = *startPtr;
            precPtr = correntePtr;
            while(strcmp(correntePtr->nome, nome[i])<0 && correntePtr!=NULL){
                precPtr = correntePtr;
                correntePtr = correntePtr->nextPtr;
            }
            if(strcmp(correntePtr->nome, nome[i])==0){
                correntePtr->voti++;
            }
            else{
                if(correntePtr == *startPtr){
                    correntePtr = insertnewname(nome[i]);
                    correntePtr->nextPtr = *startPtr;
                    *startPtr = correntePtr;
                }
                else{
                    correntePtr = insertnewname(nome[i]);
                    correntePtr->nextPtr = precPtr->nextPtr;
                    precPtr->nextPtr = correntePtr;
                }
            }
        }
    }
}

void cercavincitori(alunno *primo, alunno *secondo, alunnoPtr correntePtr){
    assegnastruct(secondo, correntePtr);
    assegnastruct(primo, correntePtr->nextPtr);
    do{
        if(correntePtr->voti > secondo->voti){
            if(correntePtr->voti > primo->voti){
                assegnastruct(secondo, primo);
                assegnastruct(primo, correntePtr);
            }
            else{
                assegnastruct(secondo, correntePtr);
            }
        }
        correntePtr = correntePtr->nextPtr;
    } while (correntePtr!=NULL);
}

void printlist(alunnoPtr startPtr){
        //-------------------
        do
        {
            printf("%15p\t", startPtr->nextPtr);
            printf("%10s\t", startPtr->nome);
            printf("%d\n", startPtr->voti);
            startPtr = startPtr->nextPtr;
        } while (startPtr!=NULL);
        //-------------------
}

void assegnastruct(alunnoPtr vecchio, alunnoPtr nuovoPtr){
    vecchio->voti = nuovoPtr->voti;
    vecchio->nome = nuovoPtr->nome;
    vecchio->nextPtr = NULL;
}













