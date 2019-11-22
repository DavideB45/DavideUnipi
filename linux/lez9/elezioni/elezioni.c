#include <stdio.h>
#include <string.h>

typedef struct alunno{
    int voti;
    char *nome;
    struct alunno *nextPtr; 
}alunno;
typedef alunno *alunnoPtr;

alunnoPtr insertnewname(alunnoPtr ultimo);
void addvote(alunnoPtr *startPtr, FILE *fPtr);
void cercavincitore(alunno *primo, alunno *secondo);
char* calcdim(char array[])

int main(void){
	FILE *fPtr = NULL;
    if((fPtr = fopen("input.txt", "r"))==NULL){
        printf("file non trovato\n");
        exit(EXIT_FAILURE);
    }
    else{
        alunno *startPtr;
        while(!feof(fPtr)){
            addvote(&startPtr, &fPtr);
        }
    }
    alunno primo;
    alunno secondo;
    cercavincitore(&primo, &secondo);
    printf("%s con %d voti\n", primo.nome, primo.voti);
    printf("%s con %d voti\n", secondo.nome, secondo.voti);
    return 0;
}

void addvote(alunnoPtr *startPtr, FILE *fPtr){
    char nome1[9],nome2[9]; 
    fscanf(fPtr, "%[^,],%[^,]", nome1, nome2);
    if(*startPtr==NULL){
        *startPtr = malloc(sizeof(alunno));
        if(*startPtr == NULL){
            printf("memoria esaurita\n");
        }
        else{
            *startPtr = insertnewname; 
        }
    }
    //do{

    }
}