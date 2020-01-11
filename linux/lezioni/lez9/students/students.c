#include <stdio.h>
#include <stdlib.h>

typedef struct nodo{
	int voto;
	char nome[10];
	char cognome[10];
	struct nodo *prossimoPtr;
}Lista;
typedef Lista *StudPtr; 

void printIfPassed(StudPtr studente);
void creaLista(StudPtr *headPtr);
void readLine(FILE **fPtr, StudPtr *headPtr, StudPtr *lastPtr);

int main(void){
	StudPtr headPtr = NULL;
	creaLista(&headPtr);
	do{
		printIfPassed(headPtr);
		headPtr = headPtr->prossimoPtr;
	}while(headPtr != NULL);
	return 0;
}

void creaLista(StudPtr *headPtr){
	FILE *fPtr = NULL;
	if((fPtr = fopen("input.txt", "r"))==NULL){
		printf("Impossibile aprire il file\n");
		exit(EXIT_FAILURE);
	}
	else{
		StudPtr lastPtr;
		while(readLine(&fPtr, headPtr, &lastPtr), !feof(fPtr));
	}
}

void readLine(FILE **fPtr, StudPtr *headPtr, StudPtr *lastPtr){
	StudPtr tempPtr = calloc(1, sizeof(Lista));
	fscanf(
		*fPtr, "%[^;];%[^;];%d\n", 
		tempPtr->cognome,
		tempPtr->nome,
		&(tempPtr->voto)
	);
	tempPtr->prossimoPtr = NULL;
	if(*headPtr == NULL){
		*headPtr = tempPtr;
		*lastPtr = tempPtr;
	}
	else{
		(*lastPtr)->prossimoPtr = tempPtr;
		(*lastPtr) = tempPtr;
	}
}

void printIfPassed(StudPtr studente){
	if(studente->voto > 17){
		printf(
			"%10s%10s%4d ESAME SUPERATO\n", 
			studente->cognome, 
			studente->nome, 
			studente->voto
		);
	}
}
